// made by fokkonaut

#include <engine/server.h>
#include <game/server/gamecontext.h>
#include "button.h"

CButton::CButton(CGameWorld *pGameWorld, vec2 Pos, int Number, bool Collision)
: CEntity(pGameWorld, CGameWorld::ENTTYPE_BUTTON, Pos, 16)
{
	m_Number = Number;
	m_Collision = Collision;

	vec2 aOffsets[NUM_SIDES] = {
		vec2(0, -16),
		vec2(16, 0),
		vec2(0, 16),
		vec2(-16, 0)
	};

	for (int i = 0; i < NUM_SIDES; i++)
	{
		m_aSides[i].m_Pos = aOffsets[i];
		m_aSides[i].m_ID = Server()->SnapNewID();
	}

	ResetCollision();
	GameWorld()->InsertEntity(this);
}

CButton::~CButton()
{
	ResetCollision(true);
	for (int i = 0; i < NUM_SIDES; i++)
		Server()->SnapFreeID(m_aSides[i].m_ID);
}

void CButton::ResetCollision(bool Remove)
{
	// For preview, we cant use m_BrushCID here yet because when the entity is created its not set yet
	if (!m_Collision)
		return;

	int Number = Remove ? 0 : m_Number;
	GameServer()->Collision()->SetButtonNumber(m_Pos, Number);
}

void CButton::Snap(int SnappingClient)
{
	if (NetworkClipped(SnappingClient, false, true))
		return;

	if (m_BrushCID != -1)
	{
		CCharacter *pBrushChr = GameServer()->GetPlayerChar(m_BrushCID);
		if (pBrushChr && pBrushChr->m_DrawEditor.OnSnapPreview(SnappingClient))
			return;
	}

	CCharacter *pChr = GameServer()->GetPlayerChar(SnappingClient);
	if (SnappingClient > -1 && (GameServer()->m_apPlayers[SnappingClient]->GetTeam() == -1 || GameServer()->m_apPlayers[SnappingClient]->IsPaused()) && GameServer()->m_apPlayers[SnappingClient]->GetSpectatorID() != -1)
		pChr = GameServer()->GetPlayerChar(GameServer()->m_apPlayers[SnappingClient]->GetSpectatorID());
	bool Status = GameServer()->Collision()->m_pSwitchers && GameServer()->Collision()->m_pSwitchers[m_Number].m_Status[pChr->Team()];

	if (!Status && (Server()->Tick() % Server()->TickSpeed()) % 11 == 0)
		return;

	CNetObj_Laser *pButton = static_cast<CNetObj_Laser *>(Server()->SnapNewItem(NETOBJTYPE_LASER, GetID(), sizeof(CNetObj_Laser)));
	if (!pButton)
		return;

	pButton->m_X = round_to_int(m_Pos.x);
	pButton->m_Y = round_to_int(m_Pos.y);
	pButton->m_FromX = round_to_int(m_Pos.x);
	pButton->m_FromY = round_to_int(m_Pos.y);
	pButton->m_StartTick = 0;

	if (!Status)
		return;

	for (int i = 0; i < NUM_SIDES; i++)
	{
		CNetObj_Laser *pSide = static_cast<CNetObj_Laser *>(Server()->SnapNewItem(NETOBJTYPE_LASER, m_aSides[i].m_ID, sizeof(CNetObj_Laser)));
		if (!pSide)
			return;

		int To = i == POINT_LEFT ? POINT_TOP : i+1;
		pSide->m_X = round_to_int(m_Pos.x + m_aSides[i].m_Pos.x);
		pSide->m_Y = round_to_int(m_Pos.y + m_aSides[i].m_Pos.y);
		pSide->m_FromX = round_to_int(m_Pos.x + m_aSides[To].m_Pos.x);
		pSide->m_FromY = round_to_int(m_Pos.y + m_aSides[To].m_Pos.y);
		pSide->m_StartTick = Server()->Tick();
	}
}
