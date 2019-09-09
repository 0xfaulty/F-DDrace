/* (c) Shereef Marzouk. See "licence DDRace.txt" and the readme.txt in the root of the distribution for more information. */

// This file can be included several times.

#ifndef CONSOLE_COMMAND
#define CONSOLE_COMMAND(name, params, flags, callback, userdata, help)
#endif

CONSOLE_COMMAND("kill_pl", "v[id]", CFGFLAG_SERVER, ConKillPlayer, this, "Kills player v and announces the kill")
CONSOLE_COMMAND("totele", "i[number]", CFGFLAG_SERVER|CMDFLAG_CHEAT, ConToTeleporter, this, "Teleports you to teleporter v")
CONSOLE_COMMAND("totelecp", "i[number]", CFGFLAG_SERVER|CMDFLAG_CHEAT, ConToCheckTeleporter, this, "Teleports you to checkpoint teleporter v")
CONSOLE_COMMAND("tele", "?v[id] ?i[id]", CFGFLAG_SERVER|CMDFLAG_CHEAT, ConTeleport, this, "Teleports player v to player i")
CONSOLE_COMMAND("addweapon", "i[weapon-id] ?v[id] ?i[spread]", CFGFLAG_SERVER|CMDFLAG_CHEAT, ConAddWeapon, this, "Gives weapon i to player v, or spread weapon")
CONSOLE_COMMAND("removeweapon", "i[weapon-id] ?v[id]", CFGFLAG_SERVER|CMDFLAG_CHEAT, ConRemoveWeapon, this, "Removes weapon i from player v")
CONSOLE_COMMAND("shotgun", "?v[id] ?i[spread]", CFGFLAG_SERVER|CMDFLAG_CHEAT, ConShotgun, this, "Gives a shotgun to player v, or spread shotgun")
CONSOLE_COMMAND("grenade", "?v[id] ?i[spread]", CFGFLAG_SERVER|CMDFLAG_CHEAT, ConGrenade, this, "Gives a grenade launcher to player v, or spread grenade")
CONSOLE_COMMAND("rifle", "?v[id] ?i[spread]", CFGFLAG_SERVER|CMDFLAG_CHEAT, ConRifle, this, "Gives a rifle to player v, or spread rifle")
CONSOLE_COMMAND("weapons", "?v[id] ?i[spread]", CFGFLAG_SERVER|CMDFLAG_CHEAT, ConWeapons, this, "Gives all weapons to player v, or spread weapons")
CONSOLE_COMMAND("unshotgun", "?v[id]", CFGFLAG_SERVER|CMDFLAG_CHEAT, ConUnShotgun, this, "Takes the shotgun from player v")
CONSOLE_COMMAND("ungrenade", "?v[id]", CFGFLAG_SERVER|CMDFLAG_CHEAT, ConUnGrenade, this, "Takes the grenade launcher player v")
CONSOLE_COMMAND("unrifle", "?v[id]", CFGFLAG_SERVER|CMDFLAG_CHEAT, ConUnRifle, this, "Takes the rifle from player v")
CONSOLE_COMMAND("unweapons", "?v[id]", CFGFLAG_SERVER|CMDFLAG_CHEAT, ConUnWeapons, this, "Takes all weapons from player v")
CONSOLE_COMMAND("ninja", "?v[id]", CFGFLAG_SERVER|CMDFLAG_CHEAT, ConNinja, this, "Makes player v a ninja")
CONSOLE_COMMAND("super", "?v[id]", CFGFLAG_SERVER|CMDFLAG_CHEAT, ConSuper, this, "Makes player v super")
CONSOLE_COMMAND("unsuper", "?v[id]", CFGFLAG_SERVER|CMDFLAG_CHEAT, ConUnSuper, this, "Removes super from player v")
CONSOLE_COMMAND("unsolo", "?v[id]", CFGFLAG_SERVER|CMDFLAG_CHEAT, ConUnSolo, this, "Puts player v out of solo part")
CONSOLE_COMMAND("undeep", "?v[id]", CFGFLAG_SERVER|CMDFLAG_CHEAT, ConUnDeep, this, "Puts player v out of deep freeze")
CONSOLE_COMMAND("left", "", CFGFLAG_SERVER|CMDFLAG_CHEAT, ConGoLeft, this, "Makes you move 1 tile left")
CONSOLE_COMMAND("right", "", CFGFLAG_SERVER|CMDFLAG_CHEAT, ConGoRight, this, "Makes you move 1 tile right")
CONSOLE_COMMAND("up", "", CFGFLAG_SERVER|CMDFLAG_CHEAT, ConGoUp, this, "Makes you move 1 tile up")
CONSOLE_COMMAND("down", "", CFGFLAG_SERVER|CMDFLAG_CHEAT, ConGoDown, this, "Makes you move 1 tile down")

CONSOLE_COMMAND("move", "i[x] i[y]", CFGFLAG_SERVER|CMDFLAG_CHEAT, ConMove, this, "Moves to the tile with x/y-number ii")
CONSOLE_COMMAND("move_raw", "i[x] i[y]", CFGFLAG_SERVER|CMDFLAG_CHEAT, ConMoveRaw, this, "Moves to the point with x/y-coordinates ii")
CONSOLE_COMMAND("force_pause", "v[id] i[seconds]", CFGFLAG_SERVER, ConForcePause, this, "Force i to pause for i seconds")
CONSOLE_COMMAND("force_unpause", "v[id]", CFGFLAG_SERVER, ConForcePause, this, "Set force-pause timer of i to 0.")

CONSOLE_COMMAND("list", "?s[filter]", CFGFLAG_CHAT, ConList, this, "List connected players with optional case-insensitive substring matching filter")
CONSOLE_COMMAND("set_team_ddr", "v[id] ?i[team]", CFGFLAG_SERVER, ConSetDDRTeam, this, "Set ddrace team of a player")
CONSOLE_COMMAND("uninvite", "v[id] ?i[team]", CFGFLAG_SERVER, ConUninvite, this, "Uninvite player from team")

CONSOLE_COMMAND("mute", "", CFGFLAG_SERVER, ConMute, this, "")
CONSOLE_COMMAND("muteid", "v[id] i[seconds]", CFGFLAG_SERVER, ConMuteID, this, "")
CONSOLE_COMMAND("muteip", "s[ip] i[seconds]", CFGFLAG_SERVER, ConMuteIP, this, "")
CONSOLE_COMMAND("unmute", "v[id]", CFGFLAG_SERVER, ConUnmute, this, "")
CONSOLE_COMMAND("mutes", "", CFGFLAG_SERVER, ConMutes, this, "")

// F-DDrace
//weapons
CONSOLE_COMMAND("extraweapons", "?v[id] ?i[spread]", CFGFLAG_SERVER|CMDFLAG_CHEAT, ConExtraWeapons, this, "Gives all extra weapons to player v, or spread extra weapons")
CONSOLE_COMMAND("unextraweapons", "?v[id]", CFGFLAG_SERVER|CMDFLAG_CHEAT, ConUnExtraWeapons, this, "Takes all extra weapons from player v")

CONSOLE_COMMAND("plasmarifle", "?v[id] ?i[spread]", CFGFLAG_SERVER|CMDFLAG_CHEAT, ConPlasmaRifle, this, "Gives a plasma rifle to player v, or spread plasma rifle")
CONSOLE_COMMAND("unplasmarifle", "?v[id]", CFGFLAG_SERVER|CMDFLAG_CHEAT, ConUnPlasmaRifle, this, "Takes the plasma rifle from player v")
CONSOLE_COMMAND("heartgun", "?v[id] ?i[spread]", CFGFLAG_SERVER, ConHeartGun, this, "Gives a heart gun to player v, or spread heart gun")
CONSOLE_COMMAND("unheartgun", "?v[id]", CFGFLAG_SERVER, ConUnHeartGun, this, "Takes the heart gun from player v")
CONSOLE_COMMAND("straightgrenade", "?v[id] ?i[spread]", CFGFLAG_SERVER, ConStraightGrenade, this, "Gives a straight grenade to player v, or spread straight grenade")
CONSOLE_COMMAND("unstraightgrenade", "?v[id]", CFGFLAG_SERVER, ConUnStraightGrenade, this, "Takes the straight grenade from player v")
CONSOLE_COMMAND("telekinesis", "?v[id]", CFGFLAG_SERVER|CMDFLAG_CHEAT, ConTelekinesis, this, "Gives telekinses power to player v")
CONSOLE_COMMAND("untelekinesis", "?v[id]", CFGFLAG_SERVER|CMDFLAG_CHEAT, ConUnTelekinesis, this, "Takes telekinses power from player v")
CONSOLE_COMMAND("lightsaber", "?v[id]", CFGFLAG_SERVER|CMDFLAG_CHEAT, ConLightsaber, this, "Gives a lightsaber to player v")
CONSOLE_COMMAND("unlightsaber", "?v[id]", CFGFLAG_SERVER|CMDFLAG_CHEAT, ConUnLightsaber, this, "Takes the lightsaber from player v")

CONSOLE_COMMAND("hammer", "?v[id]", CFGFLAG_SERVER|CMDFLAG_CHEAT, ConHammer, this, "Gives a hammer to player v")
CONSOLE_COMMAND("gun", "?v[id] ?i[spread]", CFGFLAG_SERVER|CMDFLAG_CHEAT, ConGun, this, "Gives a gun to player v, or spread gun")
CONSOLE_COMMAND("unhammer", "?v[id]", CFGFLAG_SERVER|CMDFLAG_CHEAT, ConUnHammer, this, "Takes the hammer from player v")
CONSOLE_COMMAND("ungun", "?v[id]", CFGFLAG_SERVER|CMDFLAG_CHEAT, ConUnGun, this, "Takes the gun from player v")

CONSOLE_COMMAND("scrollninja", "?v[id]", CFGFLAG_SERVER|CMDFLAG_CHEAT, ConScrollNinja, this, "Gives a ninja to player v")

//dummy
CONSOLE_COMMAND("connectdummy", "?i[amount] ?i[dummymode]", CFGFLAG_SERVER, ConConnectDummy, this, "Connects i dummies")
CONSOLE_COMMAND("disconnectdummy", "v[id]", CFGFLAG_SERVER, ConDisconnectDummy, this, "Disconnects dummy v")
CONSOLE_COMMAND("dummymode", "?v[id] ?i[dummymode]", CFGFLAG_SERVER, ConDummymode, this, "Sets or shows the dummymode of dummy v")
CONSOLE_COMMAND("connectdefaultdummies", "", CFGFLAG_SERVER, ConConnectDefaultDummies, this, "Connects default dummies")

//power
CONSOLE_COMMAND("forceflagowner", "i[flag] ?i[id]", CFGFLAG_SERVER|CMDFLAG_CHEAT, ConForceFlagOwner, this, "Gives flag i to player i (0 = red, 1 = blue) (to return flag, set id = -1)")

//fun
CONSOLE_COMMAND("sound", "i[sound]", CFGFLAG_SERVER, ConSound, this, "Plays the sound with id i")

//client information
CONSOLE_COMMAND("player_name", "v[id] r[name]", CFGFLAG_SERVER, ConPlayerName, this, "Sets name of player v")
CONSOLE_COMMAND("player_clan", "v[id] r[clan]", CFGFLAG_SERVER, ConPlayerClan, this, "Sets clan of player v")

//info
CONSOLE_COMMAND("accountinfo", "r[username]", CFGFLAG_SERVER|CFGFLAG_CHAT, ConAccountInfo, this, "Shows information about account s")
CONSOLE_COMMAND("playerinfo", "r[name]", CFGFLAG_SERVER|CFGFLAG_CHAT, ConPlayerInfo, this, "Shows information about the player r")
CONSOLE_COMMAND("lasertext", "v[id] r[text]", CFGFLAG_SERVER, ConLaserText, this, "Sends a laser text")

//extras
CONSOLE_COMMAND("item", "v[id] i[item]", CFGFLAG_SERVER, ConItem, this, "Gives player v item i (-3=none, -2=heart, -1=armor, 0 and up=weapon id)")
CONSOLE_COMMAND("invisible", "?v[id]", CFGFLAG_SERVER|CMDFLAG_CHEAT, ConInvisible, this, "Toggles invisibility for player v")

CONSOLE_COMMAND("hookpower", "?s[power] ?v[id]", CFGFLAG_SERVER, ConHookPower, this, "Sets hook power for player v")
CONSOLE_COMMAND("freezehammer", "?v[id]", CFGFLAG_SERVER|CMDFLAG_CHEAT, ConFreezeHammer, this, "Toggles freeze hammer for player v")

CONSOLE_COMMAND("infinitejumps", "?v[id]", CFGFLAG_SERVER|CMDFLAG_CHEAT, ConInfiniteJumps, this, "Toggles infinite jumps for player v")
CONSOLE_COMMAND("endlesshook", "?v[id]", CFGFLAG_SERVER|CMDFLAG_CHEAT, ConEndlessHook, this, "Toggles endlesshook for player v")
CONSOLE_COMMAND("jetpack", "?v[id]", CFGFLAG_SERVER|CMDFLAG_CHEAT, ConJetpack, this, "Toggles jetpack for player v")
CONSOLE_COMMAND("rainbowspeed", "?v[id] ?i[speed]", CFGFLAG_SERVER, ConRainbowSpeed, this, "Sets the rainbow speed i for player v")
CONSOLE_COMMAND("rainbow", "?v[id]", CFGFLAG_SERVER, ConRainbow, this, "Toggles rainbow for player v")
CONSOLE_COMMAND("infrainbow", "?v[id]", CFGFLAG_SERVER, ConInfRainbow, this, "Toggles infinite rainbow for player v")
CONSOLE_COMMAND("atom", "?v[id]", CFGFLAG_SERVER, ConAtom, this, "Toggles atom for player v")
CONSOLE_COMMAND("trail", "?v[id]", CFGFLAG_SERVER, ConTrail, this, "Toggles trail for player v")
CONSOLE_COMMAND("spookyghost", "?v[id]", CFGFLAG_SERVER, ConSpookyGhost, this, "Toggles spooky ghost for player v")
CONSOLE_COMMAND("spooky", "?v[id]", CFGFLAG_SERVER, ConSpooky, this, "Toggles spooky mode for player v")
CONSOLE_COMMAND("addmeteor", "?v[id]", CFGFLAG_SERVER, ConAddMeteor, this, "Adds a meteors to player v")
CONSOLE_COMMAND("addinfmeteor", "?v[id]", CFGFLAG_SERVER, ConAddInfMeteor, this, "Adds an infinite meteors to player v")
CONSOLE_COMMAND("removemeteors", "?v[id]", CFGFLAG_SERVER, ConRemoveMeteors, this, "Removes all meteors from player v")
CONSOLE_COMMAND("passive", "?v[id]", CFGFLAG_SERVER, ConPassive, this, "Toggles passive mode for player v")
CONSOLE_COMMAND("vanillamode", "?v[id]", CFGFLAG_SERVER, ConVanillaMode, this, "Activates vanilla mode for player v")
CONSOLE_COMMAND("ddracemode", "?v[id]", CFGFLAG_SERVER, ConDDraceMode, this, "Deactivates vanilla mode for player v")
CONSOLE_COMMAND("bloody", "?v[id]", CFGFLAG_SERVER, ConBloody, this, "Toggles bloody for player v")
CONSOLE_COMMAND("strongbloody", "?v[id]", CFGFLAG_SERVER, ConStrongBloody, this, "Toggles strong bloody for player v")
CONSOLE_COMMAND("policehelper", "?v[id]", CFGFLAG_SERVER, ConPoliceHelper, this, "Toggles police helper for player v")

//account
CONSOLE_COMMAND("acc_logout", "v[id]", CFGFLAG_SERVER, ConAccLogout, this, "Account logout for player v")
CONSOLE_COMMAND("acc_disable", "v[id] i[on/off]", CFGFLAG_SERVER, ConAccDisable, this, "Enables or disables account of player v")
CONSOLE_COMMAND("acc_vip", "v[id] i[on/off]", CFGFLAG_SERVER, ConAccVIP, this, "Enables or disables vip for account of player v")
#undef CONSOLE_COMMAND
