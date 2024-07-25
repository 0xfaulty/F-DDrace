// made by fokkonaut

#include <engine/server.h>
#include <game/server/gamecontext.h>
#include <game/server/gamemodes/DDRace.h>
#include "teleporter.h"

static float s_CurrentDist = 0.f;
static bool s_Vertical = false;
static int64 s_LastProcessTick = 0;

CTeleporter::CTeleporter(CGameWorld *pGameWorld, vec2 Pos, int Type, int Number, bool Collision)
: CEntity(pGameWorld, CGameWorld::ENTTYPE_TELEPORTER, Pos, 14, Collision)
{
	m_Type = Type;
	m_Number = Number;

	m_Snap.m_Pos = m_Pos;
	m_Snap.m_Time = 0.f;
	m_Snap.m_LastTime = Server()->Tick();

	for (int i = 0; i < NUM_TELEPORTER_IDS; i++)
		m_aID[i] = Server()->SnapNewID();

	ResetCollision();
	GameWorld()->InsertEntity(this);
}

CTeleporter::~CTeleporter()
{
	ResetCollision(true);
	for (int i = 0; i < NUM_TELEPORTER_IDS; i++)
		Server()->SnapFreeID(m_aID[i]);
}

void CTeleporter::ResetCollision(bool Remove)
{
	// For preview, we cant use m_BrushCID here yet because when the entity is created its not set yet
	if (!m_Collision)
		return;

	CGameControllerDDRace *pController = (CGameControllerDDRace *)GameServer()->m_pController;
	if (!pController)
		return; // when server reloads or shuts down

	if (m_Type == TILE_TELEOUT || m_Type == TILE_TELE_INOUT || m_Type == TILE_TELE_INOUT_EVIL)
	{
		if (Remove)
		{
			for (unsigned int i = 0; i < pController->m_TeleOuts[m_Number - 1].size(); i++)
			{
				if (pController->m_TeleOuts[m_Number - 1][i] == m_Pos)
				{
					pController->m_TeleOuts[m_Number - 1].erase(pController->m_TeleOuts[m_Number - 1].begin() + i);
					break;
				}
			}
		}
		else
		{
			pController->m_TeleOuts[m_Number - 1].push_back(m_Pos);
		}
	}

	int Type = m_Type;
	int Number = m_Number;
	if (Remove)
	{
		Type = 0;
		Number = 0;
		m_Collision = false;
	}
	GameServer()->Collision()->SetTeleporter(m_Pos, Type, Number);
}

void CTeleporter::Tick()
{
	if (!s_LastProcessTick || s_LastProcessTick != Server()->Tick())
	{
		if (Config()->m_SvLightTeleporters && Server()->Tick() % 2 == 0)
		{
			if (s_CurrentDist < 32.f)
			{
				s_CurrentDist = clamp(s_CurrentDist+3.75f, 0.f, 32.f);
			}
			else
			{
				s_CurrentDist = 0.f;
				s_Vertical = !s_Vertical;
			}
		}
		s_LastProcessTick = Server()->Tick();
	}
}

void CTeleporter::Snap(int SnappingClient)
{
	if (NetworkClipped(SnappingClient))
		return;

	CCharacter *pChr = GameServer()->GetPlayerChar(SnappingClient);
	if (pChr && pChr->m_DrawEditor.OnSnapPreview(this))
		return;

	if (Config()->m_SvLightTeleporters && m_BrushCID == -1) // preview should always be the old circular teleporter to see better
	{
		vec2 aCorners[4] = {
			vec2(-12, -12),
			vec2(12, -12),
			vec2(12, 12),
			vec2(-12, 12),
		};

		for (int i = 0; i < 2; i++)
		{
			int From = (i * 2) + (int)s_Vertical;
			int To = From == 3 ? 0 : From+1;
			float Diff = s_CurrentDist / 32.f;
			vec2 Pos;
			Pos.x = mix(aCorners[From].x, aCorners[To].x, Diff);
			Pos.y = mix(aCorners[From].y, aCorners[To].y, Diff);

			CNetObj_Projectile *pObj = static_cast<CNetObj_Projectile *>(Server()->SnapNewItem(NETOBJTYPE_PROJECTILE, m_aID[i], sizeof(CNetObj_Projectile)));
			if(!pObj)
				return;

			pObj->m_X = round_to_int(m_Pos.x + Pos.x);
			pObj->m_Y = round_to_int(m_Pos.y + Pos.y);
			pObj->m_VelX = 0;
			pObj->m_VelY = 0;
			pObj->m_StartTick = 0;
			pObj->m_Type = WEAPON_HAMMER;
		}
	}
	else
	{
		float AngleStep = 2.0f * pi / NUM_CIRCLE;
		m_Snap.m_Time += (Server()->Tick() - m_Snap.m_LastTime) / Server()->TickSpeed();
		m_Snap.m_LastTime = Server()->Tick();

		for (int i = 0; i < NUM_CIRCLE; i++)
		{
			vec2 Pos = m_Pos;
			Pos.x += TELE_RADIUS * cosf(m_Snap.m_Time * 2.5f + AngleStep * i);
			Pos.y += TELE_RADIUS * sinf(m_Snap.m_Time * 2.5f + AngleStep * i);

			CNetObj_Projectile *pObj = static_cast<CNetObj_Projectile *>(Server()->SnapNewItem(NETOBJTYPE_PROJECTILE, m_aID[i], sizeof(CNetObj_Projectile)));
			if(!pObj)
				return;

			pObj->m_X = (int)Pos.x;
			pObj->m_Y = (int)Pos.y;
			pObj->m_VelX = 0;
			pObj->m_VelY = 0;
			pObj->m_StartTick = 0;
			pObj->m_Type = WEAPON_HAMMER;
		}
	}

	if (m_Type == TILE_TELEINWEAPON)
	{
		CNetObj_Projectile *pObj = static_cast<CNetObj_Projectile *>(Server()->SnapNewItem(NETOBJTYPE_PROJECTILE, m_aID[NUM_CIRCLE], sizeof(CNetObj_Projectile)));
		if (!pObj)
			return;

		pObj->m_X = (int)m_Pos.x;
		pObj->m_Y = (int)m_Pos.y;
		pObj->m_VelX = 0;
		pObj->m_VelY = 0;
		pObj->m_StartTick = Server()->Tick()-2;
		pObj->m_Type = WEAPON_GUN;
	}
	else if (m_Type == TILE_TELEINHOOK)
	{
		CNetObj_Projectile *pObj = static_cast<CNetObj_Projectile *>(Server()->SnapNewItem(NETOBJTYPE_PROJECTILE, m_aID[NUM_CIRCLE], sizeof(CNetObj_Projectile)));
		if (!pObj)
			return;

		pObj->m_X = (int)m_Pos.x;
		pObj->m_Y = (int)m_Pos.y;
		pObj->m_VelX = 0;
		pObj->m_VelY = 0;
		pObj->m_StartTick = Server()->Tick()-2;
		pObj->m_Type = WEAPON_SHOTGUN;
	}
	else if (m_Type != TILE_TELEOUT && m_Collision)
	{
		for (int i = 0; i < NUM_PARTICLES; i++)
		{
			float RandomRadius = frandom()*(TELE_RADIUS-4.0f);
			float RandomAngle = 2.0f * pi * frandom();
			vec2 ParticlePos = m_Pos + vec2(RandomRadius * cos(RandomAngle), RandomRadius * sin(RandomAngle));
			
			CNetObj_Projectile *pObj = static_cast<CNetObj_Projectile *>(Server()->SnapNewItem(NETOBJTYPE_PROJECTILE, m_aID[NUM_CIRCLE+i], sizeof(CNetObj_Projectile)));
			if (!pObj)
				return;

			pObj->m_X = (int)ParticlePos.x;
			pObj->m_Y = (int)ParticlePos.y;
			pObj->m_VelX = 0;
			pObj->m_VelY = 0;
			pObj->m_StartTick = Server()->Tick();
			pObj->m_Type = WEAPON_HAMMER;
		}
	}
}
