# Projeto SSeMU 99B CMZ2K26 - Base SSeMU 0.99B (2.1.7)
## Créditos Source: SSeMU SetecSoft Development
## Créditos MuServer e Cliente: SSeMU SetecSoft Development
## CMZone: Organização, Correções e Atualizações

---

### Correções e Atualizações CMZone (2026)

#### UPDATE CMZ 01 (27-09-2026) - Correção de Static Runtime Linking (/MT) e Build Visual Studio 2022
* **Linkagem Estática do CRT (/MT) em Todos os Módulos:**
  - Alterada a configuração de compilação de `/MD` (Runtime Library dinâmica) para `/MT` (Multi-Threaded estático) em todos os projetos `.vcxproj` (`ConnectServer`, `DataServer`, `Main`, `GetMainInfo` e `GameServer`).
  - Binários gerados agora são 100% autossuficientes e eliminam a necessidade de DLLs externas do Visual C++ Redistributable como `msvcp100.dll` e `msvcr100.dll`.
* **Compatibilidade com Toolsets Modernos (v143 / v145 - VS 2022):**
  - Atualizados os toolsets do MSBuild para suportar compilação limpa no Visual Studio 2022.
  - No GameServer, configurado `$(VC_ATLMFC_IncludePath)` para resolução nativa de dependências MFC/ATL (`atltime.h`).
* **Correção de Compatibilidade LUA 5.2 / CRT Moderno:**
  - Implementada compatibilidade de `__iob_func` e linkagem com `legacy_stdio_definitions.lib` para eliminar conflitos de símbolos não resolvidos do LUA.
  - Corrigida a inicialização de gerador de números aleatórios (`std::mt19937`) em `GameServer/Util.cpp`.
* **Correção de Recursos de Janela e RC:**
  - Substituída a inclusão depreciada de `afxres.h` por `winres.h` em `Main.rc` e `GetMainInfo.rc`.
* **Padronização de Conexão e Handshake do Cliente:**
  - Corrigido o handshake entre `Client99B` e `ConnectServer`, alinhando a porta de conexão em `ServerInfo.sse` e `ConnectServer.ini` e eliminando o erro "You are disconnected from the server".
  - Criado script facilitador `Gerar_ServerInfo.bat` em `GetMainInfo99B` para compilação e sincronização automática das configurações diretamente com o cliente.

---
### Histórico Oficial de Atualizações SSeMU (Base Original 99B)

# -- SSEMU MUONLINE SERVER EMULATOR
# -- www.ssemu.com
# -- www.facebook.com/setecsoft
# -- © 2021 SetecSoft Development
# ----------------------------------------------------------
# -- File is a part of SSeMU MuOnline Server files.

===
UPDATE 52 (2.1.7):
* Se arreglo crash por sobrelectura. [ALL VERSIONS]
* Se arreglo el problema del listado del CustomPick. [ALL VERSIONS]
* Se arreglo una caida inesperada por uso al autenticar licencia. [ALL VERSIONS]
* Se arreglo el ScriptCore.lua. [ALL VERSIONS]

* Eliminadas opciones en "GameServer\DATA\GameServerInfo - Common.dat". [ALL VERSIONS] (CheckSkillSpeedAction,CheckSkillSpeedPenalty,Serv erDebugger,ServerDebuggerName)
* Eliminadas opciones en "GameServerCS\DATA\GameServerInfo - Common.dat". [ALL VERSIONS] (CheckSkillSpeedAction,CheckSkillSpeedPenalty,Serv erDebugger,ServerDebuggerName)

* Modificado el archivo "Data\Hack\HackSkillSpeedCheck.txt" se agregaron nuevos metodos de filtro. [ALL VERSIONS]

* Mejorado el sistema de ItemBag Avanzado. GradeCount aplica, durabilidad o grado de items. [ALL VERSIONS]

UPDATE 51 (2.1.6):
* Nuevos mensaje en el archivo "Data\Message.txt" [ALL VERSIONS] (724) [ALL VERSIONS]
* Nuevas opciones agregadas en "GameServer\DATA\GameServerInfo - Event.dat". [99B][S0][S2][S2PHI][S3][S3TAI][S6] (ChaosCastleMoneyRate)
* Nuevas opciones agregadas en "GameServerCS\DATA\GameServerInfo - Event.dat". [S0][S2][S2PHI][S3][S3TAI][S6] (ChaosCastleMoneyRate)

* Arreglado Dark Knight skills en Chaos Castle. [99B]
* Arreglado el error de nombre de mapa en party. [99B]
* Arregladas las frutas. [99B]
* Arreglado la perdida de buffs al moverse de mapa. [99B][S0][S2][S2PHI][S3][S3TAI]
* Arreglado el problema de tener que moverse para volver a comprar en shops. [99B]
* Arreglado el problema de moverse con la maquina chaos abierta. [99B]

* Agregado soporte de Bridge LUA. [ALL VERSIONS]
* Agregada la recompensa al azar en Chaos Castle. [ALL VERSIONS]
* Agregado mover items al baul, chaosmix y trade con clic derecho. [99B]
* Modificado archivos LUA. [ALL VERSIONS] (ScriptMain.lua, ScriptCore.lua y ScriptDefine.lua) (DEBE REMPLAZAR LA CARPETA SCRIPT O GENERARA CRASH)

* Eliminadas opciones en "GameServer\DATA\GameServerInfo - Common.dat". [99B] (FruitSubPointMin,FruitSubPointMax,FruitSubPointSu ccessRate_ALX)
* Eliminadas opciones en "GameServerCS\DATA\GameServerInfo - Common.dat". [99B] (FruitSubPointMin,FruitSubPointMax,FruitSubPointSu ccessRate_ALX)

Cliente:
* Arreglado los viewport al usar skill Twisth Slash, Inferno, Decay. [99B][S0][S2K][S2P]
* Arreglado el problema que trababa los skills en PvP. [ALL VERSIONS]

* Mejorada la lectura de LUA. [ALL VERSIONS]

UPDATE 50 (2.1.5):
* Arreglado el crash al ir a Atlans. [S2][S2P]
* Arreglado el crash al jugar Battle Soccer. [ALL VERSIONS]
* Arreglado el crash al jugar War. [ALL VERSIONS]

* Agregado al sistema de noticias el slide. [ALL VERSIONS]

* Eliminado el sistema de bridges LUA que causaba crash. [ALL VERSIONS]

UPDATE 49 (2.1.4):
* Arreglado el sistema de encriptacion de MHPServer. [ALL VERSIONS]

* Modificados sistemas de licenciamientos. [ALL VERSIONS]

UPDATE 48 (2.1.3):
* Arreglados problemas de CustomAttack en MAINS. [ALL VERSIONS]

CLIENT:
* Implementacion de LUA para desarrollo de estructuras. [ALL VERSIONS]

UPDATE 47 (2.1.2):
* Arreglado el crash al finalizar el GuildWar. [ALL VERSIONS]
* Arreglado el problema que no finalizaba el attack a usar skills. [ALL VERSIONS]

* Mejorado el sistema de attack. [ALL VERSIONS]

* Modificado el archivo "Data\Custom\CustomAttack.txt" se agrego rate de velocidad. [ALL VERSIONS]

CLIENT:
* Agregado Fog para mapas. [ALL VERSIONS]

* Arreglado un problema de la camara 3D. [S3][S3TAI]
* Arreglado un bug de ataque a larga distancia [99B]
* Arreglado el problema de % en Chaos Mix. [ALL VERSIONS]

UPDATE 46 (2.1.1):
* Arreglado el problema de las noticias en guilds. [ALL VERSIONS]
* Arreglado el modulo de LUA que causaba crashs. [ALL VERSIONS]
* Arreglado el bug de viewport al usar determinados skills. [ALL VERSIONS]
* Arreglado el problema de viewport de items al moverse. [ALL VERSIONS]
* Arreglado el mensaje erroneo en party al recoger items. [99B]

* Nuevas funciones LUA (CommandSend,SetObjectWindowTitle) [ALL VERSIONS]

CLIENT:
* Arreglado el problema de viewport de habilidad + ataque normal. [99B][S0][S2][S2PHI][S3][S3TAI]
* Arreglada la camara 3D en Valle of Loren. [S3][S3TAI]
* Arreglado el problema del ChaosMix. [ALL VERSIONS]
* Arreglado crash en ChaosMix. [S2PHI]
* Arreglada la resolucion 640x480. [ALL VERSIONS]

* Agregadas funciones de LUA de cambio de titulo de ventana. [ALL VERSIONS]
* Agregado el separador de chat. [S4][S6]

UPDATE 45 (2.1.0):
* Arreglado el error del Guild con usuarios conectados. [ALL VERSIONS]
* Arreglado el problema de los rates invalidos en creacion de pets. [ALL VERSIONS]
* Arreglado el crash por lectura de lua masivos. [ALL VERSIONS]
* Arreglado Viewport el cerrar el Guild. [ALL VERSIONS]
* Arreglado Viewport al abrir el baul. [ALL VERSIONS]
* Arreglado problema de quest diarias invalidas. [S6][S8]

* Agregado a consola debug el ingreso de opciones ancient. [ALL VERSIONS]

* Reestructurado el sistema ancient en shops y comandos. [ALL VERSIONS]

* Mejorada la lectura de scripts bridges LUA mediante clases estaticas. [ALL VERSIONS]


CLIENT:
* Arreglado el error de camara con cuadros negros. [99B]
* Arreglado el mensaje de rate y money en creacion de mascotas DL. [ALL VERSIONS]

UPDATE 44 (2.0.9):
* Arreglado el problema de viewport con items ancient. [ALL VERSIONS]
* Arreglado el problema de viewport al equipar items. [ALL VERSIONS]
* Arregladas auras de items ancient sets completos. [ALL VERSIONS]
* Arreglados atributos de items ancients. [S3][S3TAI]
* Arreglados los rates en tiempo real de Pet Trainer. [99B]
* Arreglado el viewport de los anillos de transformacion. [99B][S0]
* Arreglado el Double Damage en Ancient. [ALL VERSIONS]
* Arreglado el teleport en Stadium a Lorencia. [ALL VERSIONS]
* Arreglado el problema de las noticias de clanes que no se guardaban. [ALL VERSIONS]

* Rediseñado el sistema de guilds. [99B]
* Rediseñado el sistema de guild war. [ALL VERSIONS]
* Rediseñado el sistema de conexiones. [ALL VERSIONS]

* Mejoras al cambiar de mapa entre servidores. [ALL VERSIONS]
* Mejoras en ViewCharSet. [ALL VERSIONS]
* Mejoras al map viewer. [ALL VERSIONS]

UPDATE 43 (2.0.8):
* Arreglado el problema de Viewport al utilizar la ventana Move. [ALL VERSIONS]
* Arreglado el Battle Soccer que no se movia la pelota. [99B]
* Arreglado Skill Splash y otros que no pegaban en ciertas posiciones. [ALL VERSIONS]
* Arreglado el Skill Heal en Party de Helper Offline. [S6][S8]
* Arreglado el crash con skill Twisth Slash. [99B]

* Rediseñado el sistema de Battle Soccer. [ALL VERSIONS]
* Rediseñado todo el sistema de protocolos de versiones antiguas. [99B][S0][S2][S3]

* Mejorado el rendimiento de los ejecutables.[ALL VERSIONS]
* Mejorado el sistema de seguridad anti flood. [ALL VERSIONS]

UPDATE 42 (2.0.7):
* Arreglado el problema de las puertas del castle siege. [ALL VERSIONS]
* Arreglado el problema del skill teleport que dejaba traspasar las puertas del CS. [ALL VERSIONS]
* Arreglado el problema del skill Party Summon que dejaba traspasar las puertas del CS. [ALL VERSIONS]
* Arreglado el problema de Viewport luego de usar el skill summon party. [ALL VERSIONS]
* Arreglado la probicion de usar skills en LUA. [ALL VERSIONS]
* Arreglado un problema de custom attack que lo detenia a las 24 horas de uso. [ALL VERSIONS]

* Agregadas las bundles nuevas al comando pack y unpack. [S0][S2][S2PHI][S3][S3TAI][S4]

* Modificado el archivo "Data\Item\Item.txt" se agregaron las bundles [S0][S2][S2PHI][S3][S3TAI][S4] (seccion 12, desde el item 136 al item 143)

* Nueva opcion agregada en "GameServer\DATA\GameServerInfo - Custom.dat". [ALL VERSIONS] (Custom Store Settings and Custom Jewel Pack Settings)
* Nueva opcion agregada en "GameServerCS\DATA\GameServerInfo - Custom.dat". [ALL VERSIONS] (Custom Store Settings and Custom Jewel Pack Settings)

* Mejoras en el sistema lua. [ALL VERSIONS]

CLIENTE:
* Agregadas lineas en el Text_xxx.bmd [1792~1799] [S0][S2][S2PHI][S3][S3TAI][S4]
* Modificadas lineas en el Text_xxx.bmd [1806,1807,1819] [S0][S2][S2PHI][S3][S3TAI][S4]
* Agregados las bundles en Item_xxx.bmd [S0][S2][S2PHI][S3][S3TAI][S4] (seccion 12, desde el item 136 al item 143)

UPDATE 41 (2.0.6):
* Arreglado el problema de CustomAttack que no se podia habilitar en los eventos. [ALL VERSIONS]
* Arreglado el MonsterMove que a veces no movia automaticamente los NPC. [ALL VERSIONS]
* Arreglado un Protocolo invalido que generaba problemas de conexiones. [ALL VERSIONS]
* Arreglado un problema con la funcion ItemGive Lua. [ALL VERSIONS]
* Arreglado los excesos de PCPoints y WCoin al vender en store. [S2][S2PHI][S3][S3TAI][S4]
* Arreglado efectos visuales +13 en MAINS. [S0][S2][S2PHI][S3][S3TAI][S4]

* Agregadas 3 nuevas box "Green Box,Red Box,Purple Box" en ItemBagManager. [S6][S8]
* Agregado sistema de mision de todos los NPC. [Elf Buffer, Zebina, Tercia, Gens, Zyro, Derubish] [S6][S8]

* Modificado el archivo "Data\Item\ItemStack.txt" Se agregaron 3 items quest. [S6][S8]
* Modificado el archivo "Data\Monster\MonsterMove.txt" Se restructuro el sistema de monstruos que se warpean. [ALL VERSIONS]
* Modificado el archivo "Data\Quest\Quest.txt" Se restructuro el sistema de quest. [ALL VERSIONS]
* Modificado el archivo "Data\Quest\QuestObjective.txt" Se restructuro el sistema de quest. [ALL VERSIONS]
* Modificado el archivo "Data\Quest\QuestReward.txt" Se restructuro el sistema de quest. [ALL VERSIONS]
* Modificado el archivo "Data\QuestWorld\QuestWorld.txt" Se restructuro el sistema de quest. [S6][S8]
* Modificado el archivo "Data\QuestWorld\QuestWorldObjective.txt" Se restructuro el sistema de quest. [S6][S8]
* Modificado el archivo "Data\QuestWorld\QuestWorldReward.txt" Se restructuro el sistema de quest. [S6][S8]
* Modificado el archivo "Data\EventItemBagManager.txt" se reestructuro el archivo y se agregaron 3 nuevas box. [ALL VERSIONS]

* Mejorado sistema de lectura de varios archivos. [ALL VERSIONS]
* Mejorada la carga de monstruos. [ALL VERSIONS]

*** IMPORTANTE: SE RECOMIENDA EJECUTAR LA SENTENCIA "DELETE QuestWorld" EN SQL PARA BORRAR TODAS LAS QUESTWORLD ANTERIORES, EN CASO DE NO HACERLO PUEDE GENERAR PROBLEMAS. ***

UPDATE 40 (2.0.5):
* Arreglado el problema que el comando offattack no mantenia conectados a los personajes. [ALL VERSIONS]

* Agregado al comando ClearInventory que no se borren items de eventos (BC e IT). [ALL VERSIONS]
* Agregado el filtro para usar comandos Attack, Pick, Store con la funcion MapZone. (-1: ALL Maps, 0,10: Ejemplo Lorencia e Icarus) [ALL VERSIONS]

* Modificado el mensaje en el archivo "Data\Message.txt" [ALL VERSIONS] (454) [ALL VERSIONS]
* Nuevos mensaje en el archivo "Data\Message.txt" [ALL VERSIONS] (459,460) [ALL VERSIONS]

* Nueva opcion agregada en "GameServer\DATA\GameServerInfo - Custom.dat". [ALL VERSIONS] (CustomAttackMapZone,CustomPickMapZone)
* Nueva opcion agregada en "GameServerCS\DATA\GameServerInfo - Custom.dat". [ALL VERSIONS] (CustomAttackMapZone,CustomPickMapZone)

* Modificado el archivo "Data\Custom\CustomPick.txt" [ALL VERSIONS]

* Eliminadas opciones en "GameServer\DATA\GameServerInfo - Custom.dat". [ALL VERSIONS] (CustomAttackPickEnable_ALX,CustomAttackOfflinePic kEnable_ALX,CustomPickMaxItemList)
* Eliminadas opciones en "GameServerCS\DATA\GameServerInfo - Custom.dat". [ALL VERSIONS] (CustomAttackPickEnable_ALX,CustomAttackOfflinePic kEnable_ALX,CustomPickMaxItemList)

UPDATE 39 (2.0.4-1):
* Arreglado el problema de crash en noticias del guild. [ALL VERSIONS]
* Arreglado el problema stuck al portar marcotas. [ALL VERSIONS]
* Arreglado el problema de lua de algunas funciones. [ALL VERSIONS]

* Arreglado el plugin 3 de los mains. [ALL VERSIONS]

UPDATE 38 (2.0.4):
* Arreglado el problema de desconexion en Windows XP, Windows 7. [ALL VERSIONS]
* Arreglado el problema de compatibilidad de DLL's externas. [ALL VERSIONS]
* Arreglado el crash al matar el Kundum en mapas que no sean kalima. [ALL VERSIONS]

* Modificado el archivo "Data\Util\Notice.txt" Se restructuro el sistema de noticias. [ALL VERSIONS]

* Mejorado el sistema de creacion de ventanas de versiones bajas. [S0]

* Actualizado el sistema de lua a 5.3.1. [ALL VERSIONS]
* Actualizado el sistema de conexiones de Socket TCP y UDP. [ALL VERSIONS]

CLIENTE:

* Mejorado el sistema de carga de textuas. [ALL VERSIONS]
* Implementado sistema de efectos estaticos, dinamicos y especiales. [ALL VERSIONS]

* Removido el sistema de CustomEffectWing. [S6][S8]

UPDATE 37 (2.0.3):
* Nuevo archivo para configurar uso de skills en "Data\Skill\SkillEnabler.txt". [ALL VERSIONS]

* Modificado el archivo "Data\Event\EventEntryLevel.dat". [ALL VERSIONS] (Modificada la estructura)

* Arreglado el Custom Luke Helper. [ALL VERSIONS]
* Arreglado el Golden Archer, ahora resta de a 1 item. [ALL VERSIONS]

* Mejorado el sistema de filtrado de palabras. [ALL VERSIONS]
* Mejorado el sistema de hilos en multiprocesadores. [ALL VERSIONS]

* Nuevos mensaje en el archivo "Data\Message.txt" [ALL VERSIONS] (723) [ALL VERSIONS]

CLIENTE:

* Mejorado el rendimiento del cliente. [ALL VERSIONS]
* Implementado el sistema de EventEntryLevel. [ALL VERSIONS]

UPDATE 36 (2.0.2):
* Arreglada la herramienta para generar el Item.bmd. [S0][S2][S2PHI][S3][S3TAI][S4][S4E][S6]
* Arreglada la funcion lua CreateMonster. [ALL VERSIONS]
* Arreglado el problema de perdida de ManaShield al cambiar de mapa. [S0][S2][S2PHI][S3][S3TAI]
* Arreglado el golden archer que no consumia las renas correctamente.[S0][S2][S2PHI][S3][S3TAI][S4][S4E][S6]
* Arreglado el problema que no se podia desconectar cuentas en offattack. [S0][S2][S2PHI][S3][S3TAI][S4][S4E]
* Arreglado el problema que no se podia desconectar gente desde el menu. [ALL VERSIONS]
* Arreglado el crash del chaos castle 6. [S0]
* Arreglado problema de experiencia en master level. [S6][S8]
* Arreglado Viewport al cambiar de servidor. [ALL VERSIONS]
* Arreglado el sistema de creacion de personajes por nivel ocultando innecesarios o innabilitados. [ALL VERSIONS]
* Arregladas las cartas de creacion de personajes. [S6][S8]
* Arreglados problemas de desconexiones. [ALL VERSIONS]
* Arreglado el problema del drop ancient desde ItemOptionRate. [ALL VERSIONS]

* Agregado sistema de bridges a Scripting LUA en "Script\Bridge" [ALL VERSIONS]
* Agregado activacion rapida del comando "/attack". [ALL VERSIONS]
* Agregado MonsterSkin para personalizar CustomMonsters con armaduras. [ALL VERSIONS]

* Mejorado el sistema de fuentes de los mains. [ALL VERSIONS]

* Modificado el archivo "GameServer\DATA\GameServerInfo - Common.dat" se agrego opcion "CheckLiveSecurity" para desactivar la seguridad en tiempo real. [ALL VERSIONS]
* Modificados el archivo "Data\Item\ItemOptionRate.txt" se incorporaron nuevas opciones para drop ancient(Section 5). [ALL VERSIONS]
* Modificados el archivo "Data\Item\SetItemOption.txt" se agrego a OptionIndex2. [S0][S2][S2PHI][S3][S3TAI]
* Modificados el archivo "Data\Item\SetItemOption.txt" se agrego a OptionIndex2. [S0][S2][S2PHI][S3][S3TAI]

* Nuevas funciones LUA. (MessageSend,MessageSendToAll) Ver(Script Lua Interface Functions)[ALL VERSIONS]

Cliente:
* Agregado sistema de multilenguage a los clientes [S0][S2][S2PHI][S3][S3TAI][S4]
* Fusionado el CustomMessage.txt con Text_XXX.bmd. [ALL VERSIONS]

UPDATE 35 (2.0.1):
* Nuevos comandos agregados en "Data\CommandManager.txt" (Offline) [S6][S8](21)

* Nueva opcion agregada en "GameServer\DATA\GameServerInfo - Common.dat". [S6][S8] (WriteScriptLog,Helper Offline Settings)
* Nueva opcion agregada en "GameServerCS\DATA\GameServerInfo - Common.dat". [S6][S8] (WriteScriptLog,Helper Offline Settings)

* Nueva opcion agregada en "GameServer\DATA\GameServerInfo - Custom.dat". [ALL VERSIONS] (CustomArenaMapNumber,CustomAttack,CustomAttackOff line Settings)
* Nueva opcion agregada en "GameServerCS\DATA\GameServerInfo - Custom.dat". [ALL VERSIONS] (CustomArenaMapNumber,CustomAttack,CustomAttackOff line Settings)

* Nuevo archivo para configurar propiedades de skills de OffHelper en "Data\Skill\HelperSkill.txt". [S6][S8]

* Modificado el archivo "Data\Custom\CustomAttack.txt" se restructuro el archivo. [ALL VERSIONS]
* Modificado el archivo "Data\Custom\CustomLukeHelper.txt" Se agrego Class de mob. [ALL VERSIONS]
* Modificado el archivo "Data\MapServerInfo.txt" Agregados los mapas de Acheron Guardian. [S8]
* Modificado el archivo "Data\Util\Notice.txt" Se restructuro el sistema de noticias. [ALL VERSIONS]

* Mejorado el sistema de lectura de scripts. [ALL VERSIONS]
* Mejorado el sistema de scripts LUA. [ALL VERSIONS]

* Reconstruida la IA de los mobs que no tienen inteligencia programada. [ALL VERSIONS]
* Reconstruida la IA de los summon monsters. [ALL VERSIONS]

* Arreglada la opcion de Auto Aceptar miembros del Guild en Helper/Offhelper. [S8]
* Arreglado el MonsterSchedule. [ALL VERSIONS]
* Arreglado el sistema de creacion de personajes por cartas. [S4][S6][S8]
* Arreglado el sistema de respawn en mismos mapas donde murio. [ALL VERSIONS]
* Arreglado el problema del SD Ratio. [S2][S2PHI][S3][S3TAI][S4][S4E][S6][S8]

* Agregado Sistema de OffHelper en modo BETA 1. [S6][S8]
* Agregada tool para generar Item.bmd. [S0][S2][S2PHI][S3][S3TAI][S4][S4E][S6]

* Eliminadas opciones en "GameServer\DATA\GameServerInfo - Common.dat". [S6][S8] (HelperActiveMaxTime_AL3)
* Eliminadas opciones en "GameServerCS\DATA\GameServerInfo - Common.dat". [S6][S8] (HelperActiveMaxTime_AL3)

UPDATE 34 (2.0.0):
* Arreglado el problema de exceso de SD ratio increase que sobrepasaba el 100%. [ALL VERSIONS]
* Arreglado el problema de usar varios skills en CustomAttack. [ALL VERSIONS]
* Arreglado el problema de los randoms en ItemBag e ItemBagEx. [ALL VERSIONS]
* Arreglados los shops por coins. [ALL VERSIONS]

* Nuevos mensaje en el archivo "Data\Message.txt" [ALL VERSIONS] (588,719~722) [ALL VERSIONS]

* Nuevas funciones LUA. (MapGetItemTable,ObjectGetCoin,PermissionCheck,Per missionInsert,PermissionRemove,QuestStateCheck) [ALL VERSIONS]
* Nuevas Bridges LUA. (OnCommandDone,OnUserItemPick,OnUserItemDrop,OnUse rItemMove) [ALL VERSIONS]

* Opciones agregadas en "GameServer\DATA\GameServerInfo - Common.dat". [ALL VERSIONS] (CustomerLicenseId,ServerType,ServerVersion,Server Serial,ServerEncDecKey1,ServerEncDecKey2,TeleportA ttackCheck,CheckSkillSpeedAction,CheckSkillSpeedPe nalty,CharacterDeleteSwitch,CharacterDeleteMaxLeve l,PKLimitFree,PKLimitShop,PKLimitMove,PKLimitMoveS ummon,PKLimitEventEntry,PKDeathAnnounce,PKDownPlus TimePoint,PKDownPlusKillPoint,PKDownRequirePoint1, PKDownRequirePoint2,PKDownRequirePoint3,PKDownRequ irePoint4,PKItemDropRatePvP1,PKItemDropRatePvP2,PK ItemDropRatePvP3,PKItemDropRatePvM1,PKItemDropRate PvM2,PKItemDropRatePvM3,PKItemDropMaxLevel,PKItemD ropPetPKItemDropWing,PKItemDropExc,PKItemDropSet,P KItemDropJoH,PKItemDrop380,DuelAnnounceSwitch)
* Opciones agregadas en "GameServerCS\DATA\GameServerInfo - Common.dat". [ALL VERSIONS](CustomerLicenseId,ServerType,ServerVersion,Server Serial,ServerEncDecKey1,ServerEncDecKey2,TeleportA ttackCheck,CheckSkillSpeedAction,CheckSkillSpeedPe nalty,CharacterDeleteSwitch,CharacterDeleteMaxLeve l,PKLimitFree,PKLimitShop,PKLimitMove,PKLimitMoveS ummon,PKLimitEventEntry,PKDeathAnnounce,PKDownPlus TimePoint,PKDownPlusKillPoint,PKDownRequirePoint1, PKDownRequirePoint2,PKDownRequirePoint3,PKDownRequ irePoint4,PKItemDropRatePvP1,PKItemDropRatePvP2,PK ItemDropRatePvP3,PKItemDropRatePvM1,PKItemDropRate PvM2,PKItemDropRatePvM3,PKItemDropMaxLevel,PKItemD ropPetPKItemDropWing,PKItemDropExc,PKItemDropSet,P KItemDropJoH,PKItemDrop380,DuelAnnounceSwitch)

* Modificado el archivo "ConnectServer.ini" [ALL VERSIONS] Cambiado(CustomerName -> CustomerLicenseId)
* Modificado el archivo "DataServer.ini" [ALL VERSIONS] Cambiado(CustomerName -> CustomerLicenseId)
* Modificado el archivo "JoinServer.ini" [ALL VERSIONS] Cambiado(CustomerName -> CustomerLicenseId)
* Modificado el archivo "MHPServer.ini" [ALL VERSIONS] Cambiado(CustomerName -> CustomerLicenseId)
* Modificado el archivo "Data\MapServerInfo.txt". [ALL VERSIONS] Removido (MHPEncDecKey,ServerVersion,ServerSerial)

* Eliminado el archivo "Data\Custom\CustomMasterResetReward.txt" [ALL VERSIONS]
* Eliminado el archivo "Data\Custom\CustomMonsterKillMove.txt" [ALL VERSIONS]
* Eliminado el archivo "Data\Custom\CustomMove.txt" [ALL VERSIONS]
* Eliminado el archivo "Data\Custom\CustomNPCCollector.txt" [ALL VERSIONS]
* Eliminado el archivo "Data\Custom\CustomNPCMove.txt" [ALL VERSIONS]
* Eliminado el archivo "Data\Custom\CustomPKSafeZone.txt" [ALL VERSIONS]
* Eliminado el archivo "Data\Custom\CustomPVPZone.txt" [ALL VERSIONS]
* Eliminado el archivo "Data\Custom\CustomResetReward.txt" [ALL VERSIONS]
* Eliminado el archivo "Data\PKItemDrop.txt" [ALL VERSIONS]
* Eliminado el archivo "Data\PKManager.txt" [ALL VERSIONS]

* Eliminadas opciones en "GameServer\DATA\GameServerInfo - Common.dat". [ALL VERSIONS] (CustomerName,CheckHackSkillAction,LuaScriptSwitch ,PKDownTime1,PKDownTime2,ShieldGaugeDisable)
* Eliminadas opciones en "GameServerCS\DATA\GameServerInfo - Common.dat". [ALL VERSIONS] (CustomerName,CheckHackSkillAction,LuaScriptSwitch ,PKDownTime1,PKDownTime2,ShieldGaugeDisable)

* Eliminadas opciones en "GameServer\DATA\GameServerInfo - Skill.dat". [ALL VERSIONS] (CastleSiegeSkillForAllMaps)
* Eliminadas opciones en "GameServerCS\DATA\GameServerInfo - Skill.dat". [ALL VERSIONS] (CastleSiegeSkillForAllMaps)

UPDATE 33:
* Nueva opcion agregada en "GameServer\DATA\GameServerInfo - ChaosMix.dat". [S8] (TrophiesMixRate1_ALX,TrophiesMixRate2_ALX,Trophie sMixRate3_ALX,TrophiesMixRate4_ALX,TrophiesMixRate 5_ALX,TrophiesMixRate6_ALX,TrophiesMixRate7_ALX,Tr ophiesMixRate8_ALX,TrophiesMixRate9_ALX,TrophiesMi xRate10_ALX)
* Nueva opcion agregada en "GameServerCS\DATA\GameServerInfo - ChaosMix.dat". [S8] (TrophiesMixRate1_ALX,TrophiesMixRate2_ALX,Trophie sMixRate3_ALX,TrophiesMixRate4_ALX,TrophiesMixRate 5_ALX,TrophiesMixRate6_ALX,TrophiesMixRate7_ALX,Tr ophiesMixRate8_ALX,TrophiesMixRate9_ALX,TrophiesMi xRate10_ALX)

* Nueva opcion agregada en "GameServer\DATA\GameServerInfo - Command.dat". [ALL VERSIONS] (CommandPKClearType,CommandPKClearMoney_ALX)
* Nueva opcion agregada en "GameServerCS\DATA\GameServerInfo - Command.dat". [ALL VERSIONS] (CommandPKClearType,CommandPKClearMoney_ALX)

* Nueva opcion agregada en "GameServer\DATA\GameServerInfo - Common.dat". [ALL VERSIONS] (LuaScriptSwitch,EffectOverwriteMode,PetExperience MultiplierConstA,PetExperienceRateDivisor,MaxPetLe vel)
* Nueva opcion agregada en "GameServerCS\DATA\GameServerInfo - Common.dat". [ALL VERSIONS] (LuaScriptSwitch,EffectOverwriteMode,PetExperience MultiplierConstA,PetExperienceRateDivisor,MaxPetLe vel)

* Nuevos mensajes en el archivo "Data\Message.txt" [ALL VERSIONS] (713~718) (1.0.3.3-1)

* Nuevas funciones LUA. (GetObjectGuildStatus,GetObjectGuildRelationship,G etObjectGuildUnionNumber,GetObjectGuildUnionName,G etObjectOfflineFlag,InventoryGetItemTable,MonsterS ummonCreate,MonsterSummonDelete) [ALL VERSIONS] (1.0.3.3-1)

* Agregados ChaosMix Rates en tiempo real. [ALL VERSIONS]
* Agregado el comando PKClear por cantidad de muertes. [ALL VERSIONS]

* Agregado script SQL necesario en "Databases\UP 1.0.3.3 (1 - Create Table EventEntryCount).sql". [ALL VERSIONS] (1.0.3.3-1)
* Agregado script SQL necesario en "Databases\UP 1.0.3.3 (2 - Create Procedure WZ_GetEventEntryInfo).sql". [ALL VERSIONS] (1.0.3.3-1)
* Agregado script SQL necesario en "Databases\UP 1.0.3.3 (3 - Create Procedure WZ_SetEventEntryInfo).sql". [ALL VERSIONS] (1.0.3.3-1)

* Movido Acheron Guardian de "GameServer" a "GameServerCS". [S8]

* Corregido el ScheduleManager. [ALL VERSIONS]
* Corregidos los efectos de Arka War (179~184,187). [S8]
* Corregido el drop por efecto en Acheron. [S8]
* Corregido el drop ancient con efecto en Acheron. [S8]
* Corregidas las opciones JewelOfHarmonyItemRestoreMixRate_ALX. [S2][S2PHI][S3][S3TAI][S4][S4E][S6][S8]

Cliente:
* Arreglado desborde de la barra reconnect.[ALL VERSIONS]

[Text.bmd] Linea 484-1156-1167 [S2PHI]
[GetMainInfo.txt] Eliminado DisableMonsterHealthBarKeys
[GetMainInfo.txt] Eliminado DisableCamera3DKeys
[GetMainInfo.txt] Eliminado DisableMinimizeTrayKeys
[GetMainInfo.txt] Agregado KeyCodeHealthBarSwitch [S0][S2][S2PHI][S3][S3TAI][S4][S4E][S6]
[GetMainInfo.txt] Agregado KeyCodeCamera3DSwitch [ALL VERSIONS]
[GetMainInfo.txt] Agregado KeyCodeCamera3DRestore [ALL VERSIONS]
[GetMainInfo.txt] Agregado KeyCodeTrayModeSwitch [ALL VERSIONS]

UPDATE 32:
* Se reparo reconnexiones automaticas al ingresar varias personas a eventos. [ALL VERSIONS]
* Se reparo bug de caminada fantasma en Castle Siege. [ALL VERSIONS]
* Se reparo un error en el Helper que ocasionaba su parada critita. [S6]

* Modificado el archivo "Data\Hack\HackSkillSpeedCheck.txt" se agregaron nuevos metodos de filtro. [ALL VERSIONS]

* Eliminado el archivo "Data\Hack\HackChecksumCheck.txt". [ALL VERSIONS]
* Eliminadas opciones en "GameServer\DATA\GameServerInfo - Common.dat". [S0][S2][S2PHI][S3][S3TAI] (PartyMaxMember,PartyGeneralExperience6,PartyGener alExperience7,PartyGeneralExperience8,PartyGeneral Experience9,PartyGeneralExperience10,PartySpecialE xperience6,PartySpecialExperience7,PartySpecialExp erience8,PartySpecialExperience9,PartySpecialExper ience10)
* Eliminadas opciones en "GameServerCS\DATA\GameServerInfo - Common.dat". [S0][S2][S2PHI][S3][S3TAI] (PartyMaxMember,PartyGeneralExperience6,PartyGener alExperience7,PartyGeneralExperience8,PartyGeneral Experience9,PartyGeneralExperience10,PartySpecialE xperience6,PartySpecialExperience7,PartySpecialExp erience8,PartySpecialExperience9,PartySpecialExper ience10)

Cliente:
* Limpiado el cliente de falsos positivos.
* Limpiado el MHPClient.dll de falsos positivos.
* Se reparo falso crash. [S6][S8]
* Se elimino sistema checksum en tiempo real por falsos positivos.
* Se arreglo problema de la jaulas de stadium que desconectaban.

UPDATE 31:
* Se reestructuraron varias cosas en los ejecutables. [ALL VERSIONS]
* Se mejoro el rendimiento. [ALL VERSIONS]
* Se volvio a agregar la version BETA con LUA. [ALL VERSIONS]
* Se mejoro la ventana de conexiones de usuarios. [ALL VERSIONS]
* Se agrego soporte para la temporada 4 episodio 6. [S4E]

Cliente:
* Se reestructuro todo el sistema del main.
* Se agrego soporte para inyeccion al main.
* Se implementaron mejoras en el OpenGL.
* Se corrigio el problema de velocidad en main.
* Se agrego correctamente el sistema CRC.

UPDATE 30:
* Arreglado el PartyExperience. [ALL VERSIONS]
* Arreglados los problemas de CustomMonster en CustomNPCCollector,CustomNPCMove y MonsterSchedule. [ALL VERSIONS]
* Arreglados efectos buffs auras ELF. [S0][S2][S2PHI][S3][S3TAI]
* Arreglado mensaje invalido post. [S8]

* Agregado UI de MapViewer en GameServers. [ALL VERSIONS]
* Agregada auto deteccion a la opcion MaxPacketPerSecond de los gameserver. [ALL VERSIONS]
* Agregada verificacion de checksum al cliente en "Data\Hack\HackChecksumCheck.txt". [ALL VERSIONS]

* Nueva opcion agregada en "GameServer\DATA\GameServerInfo - Common.dat". [S0][S2][S2PHI][S3][S3TAI] (PartyMaxMember,PartyGeneralExperience6,PartyGener alExperience7,PartyGeneralExperience8,PartyGeneral Experience9,PartyGeneralExperience10,PartySpecialE xperience6,PartySpecialExperience7,PartySpecialExp erience8,PartySpecialExperience9,PartySpecialExper ience10)
* Nueva opcion agregada en "GameServerCS\DATA\GameServerInfo - Common.dat". [S0][S2][S2PHI][S3][S3TAI] (PartyMaxMember,PartyGeneralExperience6,PartyGener alExperience7,PartyGeneralExperience8,PartyGeneral Experience9,PartyGeneralExperience10,PartySpecialE xperience6,PartySpecialExperience7,PartySpecialExp erience8,PartySpecialExperience9,PartySpecialExper ience10)

Cliente:
* Arregladas las camaras 3D y extendidos sus rangos. [ALL VERSIONS]
* Arreglado crash CustomMaps. [S0]
* Extendido el party hasta 10 personas. [S0][S2][S2PHI][S3][S3TAI]

* CustomMonster y CustomNPC pueden elegirse las carpetas a usar. [ALL VERSIONS]

* Mejorado el soporte de CustomMap y agregado effectos por mapas. [ALL VERSIONS]
* Mejoradas las interface de Reconnect. [ALL VERSIONS]

UPDATE 29:
* Arreglado el reloj de Double Goer. [S6][S8]
* Arreglado el reloj de Imperial Guardian. [S6][S8]
* Arreglado el problema que no se podian crear clanes con 8 letras. [ALL VERSIONS]
* Arreglado el crash de GS en duelo al estar ShieldGaugeDisable en 1. [S6][S8]

* Mejorado el sistema de anti flood. [ALL VERSIONS]

* Agregadas nuevas UI de ConnectionList en GameServers. [ALL VERSIONS]
* Agregadas nuevas UI de DetectionList en MHPServer.

* Removido de la version oficial el soporte LUA (Solo en BETA). [ALL VERSIONS]

* Opciones eliminadas en "ConnectServer\ConnectServer.ini". [ALL VERSIONS] (MaxIpConnection,MaxPacketCount,MaxPacketDelay,Tim eoutDisconnect,VerifyTimeoutDisconnect,AutomaticLo ckSwitch,AutomaticLockTime)
* Opciones eliminadas en "GameServer\DATA\GameServerInfo - Common.dat". [ALL VERSIONS] (DebugCharName,MaxPacketTime,MaxPacketCount,DSJSMa xPacketTime,DSJSMaxPacketCount,TimeoutDisconnect,V erifyTimeoutDisconnect,MaxIpConnection,MaxHidConne ction)
* Opciones eliminadas en "GameServerCS\DATA\GameServerInfo - Common.dat". [ALL VERSIONS] (DebugCharName,MaxPacketTime,MaxPacketCount,DSJSMa xPacketTime,DSJSMaxPacketCount,TimeoutDisconnect,V erifyTimeoutDisconnect,MaxIpConnection,MaxHidConne ction)
* Opciones eliminadas en "MHPServer\MHPServer.ini". [ALL VERSIONS] (MHPServerPort,MaxIpConnection,MaxHidConnection,Ma xPacketCount,MaxPacketDelay,TimeoutDisconnect,Veri fyTimeoutDisconnect)

* Nueva opcion agregada en "ConnectServer\ConnectServer.ini". [ALL VERSIONS] (MaxConnectionIdle,MaxConnectionPerIP,MaxPacketPer Second)
* Nueva opcion agregada en "GameServer\DATA\GameServerInfo - Character.dat". [ALL VERSIONS] (DamageStuckOnPetUniria,DamageStuckOnPetDinorant,D amageStuckOnPetDarkHorse,DamageStuckOnPetFenrir)
* Nueva opcion agregada en "GameServerCS\DATA\GameServerInfo - Character.dat". [ALL VERSIONS] (DamageStuckOnPetUniria,DamageStuckOnPetDinorant,D amageStuckOnPetDarkHorse,DamageStuckOnPetFenrir)
* Nueva opcion agregada en "GameServer\DATA\GameServerInfo - Common.dat". [ALL VERSIONS] (ServerDebuggerName,MaxConnectionIdle,MaxConnectio nPerIP,MaxConnectionPerHID,MaxPacketPerSecond,MaxT imeConnectionVerify)
* Nueva opcion agregada en "GameServerCS\DATA\GameServerInfo - Common.dat". [ALL VERSIONS] (ServerDebuggerName,MaxConnectionIdle,MaxConnectio nPerIP,MaxConnectionPerHID,MaxPacketPerSecond,MaxT imeConnectionVerify)
* Nueva opcion agregada en "MHPServer\MHPServer.ini". [ALL VERSIONS] (MHPServerPortTCP,MaxConnectionIdle,MaxConnectionP erIP,MaxConnectionPerHID,MaxPacketPerSecond)

UPDATE 28:
* Arreglados los problemas de consumo excesivo de memoria en main. [S0][S2][S2PHI][S3][S3TAI]
* Arreglado el problema de HackSkillSpeedCheck que no se podian poner varios valores por rangos. [ALL VERSIONS]
* Agregados Escudos faltantes y corregido el set aura. [S4]
* Arreglados los problemas de clics en mains. [S0][S2][S2PHI][S3][S3TAI][S4][S8]
* Arreglado el problema de OZT en CustomMaps. [S0]

* Nueva opcion agregada en "GameServer\DATA\GameServerInfo - Common.dat". [ALL VERSIONS] (DebugCharName)
* Nueva opcion agregada en "GameServerCS\DATA\GameServerInfo - Common.dat". [ALL VERSIONS] (DebugCharName)

* Modificado el archivo "Data\Item\Item.txt" se agrego el Cross Shield [S4]
* Modificado el archivo "Data\Script\ScriptMain.lua". [ALL VERSIONS]

* Finalizado el sistema de Scripts LUA. [ALL VERSIONS]
* Reducidos los consumos de CPU en todos los mains.

UPDATE 27-3:
* Arreglado el problema que no se podian hacer shops con monster custom. [ALL VERSIONS]
* Arreglado el problema que no se podian usar monster custom como CustomNPCMove,CustomNPCCollector. [ALL VERSIONS]
* Arreglado el life stone que dropeaba items y daba experiencia al destruirlo. [ALL VERSIONS]
* Arreglado el problema de los mercenarios invencibles. [ALL VERSIONS]
* Arreglado el OnlineReward que no funcionaba. [S2PHI]
* Arreglado el problema de velocidad de la summoner. [S4]

* Agregado sistema de scripts en "Data\Script\ScriptMain.lua". [ALL VERSIONS]
* Agregados los logs de Scripts en "GameServer\LOG\SCRIPT_LOG". [ALL VERSIONS]
* Agregadas referencias de Scripts en "Tools\Reference Scripts Lua.txt". [ALL VERSIONS]

* Modificado el archivo "Data\Event\BloodCastle.dat" se agrego cordenadas de las estatuas. [ALL VERSIONS]
* Modificado el archivo "Data\Monster\MonsterList.txt" Se agrego type para distinguir MOB/NPC y resistencias 5,6,7. [ALL VERSIONS]

UPDATE 27 (1-2):
* Arreglado viewport de los fireworks. [ALL VERSIONS]
* Arreglado viewport de los Heart,Silver Medal,Golden Medal. [ALL VERSIONS]
* Arreglado el problema de crash al finalizar un GuildWar. [ALL VERSIONS]
* Arreglado problema de bloqueos en el GameServer. [ALL VERSIONS]
* Arreglado problema de desconeccion de MHP Server.
* Arreglada la desaparicion de los clanes en actualizacion v 1.0.2.4 a 1.0.2.5 [ALL VERSIONS]
* Arreglado el viewport de items y mobs que aparecien en lugares "safe". [ALL VERSIONS]
* Arreglado el problema de reset. [ALL VERSIONS]
* Arreglado el problema que no se mostraba el nombre correcto en CustomPick. [ALL VERSIONS]
* Arreglado el problema de clanes al cambiar de nombre por comando. [ALL VERSIONS]
* Arreglado el error visual de ManaShield que se eliminaba al cambiar de mapa. [S0][S2][S2PHI][S3][S3TAI]
* Arreglado el problema de noticias en GameServerCS. [ALL VERSIONS]
* Arreglado el bucle de buffs interminable en comando attack. [ALL VERSIONS]
* Arreglado customattack que necesitaba todos los skiles detallados para master level. [S6][S8]
* Arreglado el battle soccer. [ALL VERSIONS]
* Arreglado el Invasion Manager. [ALL VERSIONS]
* Arreglado el problema de recarga de monstruos. [ALL VERSIONS]
* Arreglado el bloqueo de HardWareId en MHPServer.

* Mejorado el sistema DDoS en GameServer,HackServer y ConnectServer. [ALL VERSIONS]

* Nuevos mensajes en el archivo "Data\Message.txt" [ALL VERSIONS] (712)

* Agregado el LauncherMutex para escoger un nombre de mutex compatible con su launcher. [ALL VERSIONS]

* Nuevas opciones agregadas en "GameServer\DATA\GameServerInfo - Common.dat". [S6][S8] (LuckyMinDurabilityRepair)
* Nuevas opciones agregadas en "GameServerCS\DATA\GameServerInfo - Common.dat". [S6][S8] (LuckyMinDurabilityRepair)

* Opciones eliminadas en "GameServer\DATA\GameServerInfo - Common.dat". [ALL VERSIONS] (AutomaticLockSwitch,AutomaticLockTime)
* Opciones eliminadas en "GameServerCS\DATA\GameServerInfo - Common.dat". [ALL VERSIONS] (AutomaticLockSwitch,AutomaticLockTime)

UPDATE 26:
* Arreglado el problema de falsos chat en Guild. [ALL VERSIONS]
* Arreglado el problema que mostraba chats de otros guilds. [ALL VERSIONS]
* Arreglado el problema que mostraba a diferentes uniones chats. [ALL VERSIONS]
* Arreglado el master skill. [S4]

* Agregado los logs de items en "GameServer\LOG\ITEM_LOG". [ALL VERSIONS]
* Agregado los logs de items en "GameServerCS\LOG\ITEM_LOG". [ALL VERSIONS]

* Mejoradas Funciones nativas en gameserver. [S4]

* Reconstruido el sistema de Viewports de Guilds en Union y Rivalidad. [ALL VERSIONS]
* Reconstruidas las funciones de CannonTower. [ALL VERSIONS]
* Reconstruidas funciones del Castle Siege. [ALL VERSIONS]

* Nueva opcion agregada en "GameServer\DATA\GameServerInfo - Command.dat". [ALL VERSIONS] (CommandResetClearParty_ALX,CommandMasterResetClea rParty_ALX)
* Nueva opcion agregada en "GameServerCS\DATA\GameServerInfo - Command.dat". [ALL VERSIONS] (CommandResetClearParty_ALX,CommandMasterResetClea rParty_ALX)

Cliente:
* Mejoras de seguridad en MHPServer, MHPClient y MHPVerify.
* Mejoras en el rendimiento de los Main.dll

UPDATE 25:
* Nuevo archivo para configurar caida de zen en "Data\Item\ItemMoneyDrop.txt". [ALL VERSIONS]

* Reconstruido el sistema Friends. [ALL VERSIONS]
* Reconstruido el sistema Guild, GuildClass, GuildManager, GuildAlliance y GuildRival. [ALL VERSIONS]

* Arreglado el RewardMessage de CustomMonster. [ALL VERSIONS]
* Arreglado el Viewport de S8 en alianza de clanes. [ALL VERSIONS]

* Agregadas mejoras de seguridad en la conexión. [ALL VERSIONS]

UPDATE 24:
* Agregados protocolos de conexiones de Illusion Temple Renewals y Arca War. [ALL VERSIONS]

* Arreglado el problema de la recompensa del Devil Square. [ALL VERSIONS]

* Reestructurado el sistema de seguridad anti DDOS. [ALL VERSIONS]
* Reestructurado el sistema de seguridad anti DDOS entre el GameServer -> JoinServer. [ALL VERSIONS]
* Reestructurado el sistema de seguridad anti DDOS entre el GameServer -> DataServer. [ALL VERSIONS]

* Nuevas opciones agregadas en "GameServer\DATA\GameServerInfo - Common.dat". [ALL VERSIONS] (MaxPacketTime,MaxPacketCount)
* Nuevas opciones agregadas en "GameServerCS\DATA\GameServerInfo - Common.dat". [ALL VERSIONS] (MaxPacketTime,MaxPacketCount)

* Mejoras de seguridad MHPServer Client.
* Mejoras de seguridad MHPServer Servidor.
* Mejorado el sistema de EventItemBag. [ALL VERSIONS]

UPDATE 23:
* Arreglado el problema de crash al tirar jewels custom. [S3][S3TAI]
* Arreglado el problema que no mostraba ItemToolTip. [S0][S2][S2PHI][S3][S3TAI]
* Arreglado EventEntryLevel de Kalima. [ALL VERSIONS]
* Arreglada la recompensa del Devil Square. [ALL VERSIONS]
* Arreglados seals sin tiempo y cosas erroneas respecto a seals. [S6][S8]
* Arreglado el Viewport al recibir daño del Evil Spirit. [S0]
* Arreglado los comandos por segundos. [ALL VERSIONS]

* Modificado el archivo "Data\Event\EventEntryLevel.dat" se modifico los niveles de kalima. [ALL VERSIONS]
* Modificado el archivo "Data\Skill\EffectList.txt" se modificaron algunos items. [S6][S8]

CLIENTE:
* Arreglados los problemas de CustomToolTip.
* Mejorado el MHP Server y Cliente.
* Mejorado el flujo de datos en los mains.
* Arreglado problemas de Custom Jewels.
* Arreglado problema de seals con duracion.

UPDATE 22-1:
* Arreglado el problema de bug con el warehouse. [ALL VERSIONS]
* Arreglado el problema de zen en trade. [ALL VERSIONS]
* Arreglado el problema de Guild Alianza. [S0]
* Arreglado el bug de dup en warehouse. [ALL VERSIONS]
* Arreglado el problema del Archer y Spearman. [ALL VERSIONS]

* Agregado ItemLevel.txt para diferencias los items por nivel en "Data\Item\ItemLevel.txt" [ALL VERSIONS]
* Agregado soporte de reconocimiento de items por nivel al comando pick. [ALL VERSIONS]
* Agregado soporte de reconocimiento de items por nivel al comando pickset. [ALL VERSIONS]

* Mejorado el frujo de datos entre el DataServer y el GameServer. [ALL VERSIONS]

* Modificados mensajes en el archivo "Data\Message.txt" [ALL VERSIONS] (656,664)

UPDATE 22:
* Arreglado los problemas de Viewport en Blood Castle. [ALL VERSIONS]
* Arreglado el duplicado de items al morir con la maquina chaos. [ALL VERSIONS]
* Arreglado el trade hack al morir. [ALL VERSIONS]
* Arreglado el problema de los Shops con items Ancient. [ALL VERSIONS]
* Arreglado el empuje de mobs. [S6][S8]
* Arreglado el respawn de mobs en evento Acheron Guardian. [S8]

* Agregado Evento Acheron Guardian. [S8]
* Agregado todo el soporte de Acheron y Arca War. [S8]
* Agregados los mensajes de Arca War al Message.txt. [S8]
* Agregado soporte de NPC Lesnar para Arca War. [S8]
* Agregados los buffs de Arca War. [S8]

* Nuevos mensajes en el archivo "Data\Message.txt" [ALL VERSIONS] (23~29,596,597,702~711)

* Modificado el GameMaster.txt. [ALL VERSIONS]

* Reestructuradas a nivel codigo las funciones del protocolo de Guild Alianzas y Hostilidades. [ALL VERSIONS]
* Mejorada la carga de archivos por MemScript. [ALL VERSIONS]
* Mejorado el sistema de Sign GM desde CtrlCode en SQL Server. [ALL VERSIONS]

UPDATE 21:
* Nuevo archivo para configurar comando pick en "Data\Custom\CustomPick.txt". [S0][S2][S2PHI][S3][S3TAI][S6]

* Agregado script SQL para el comando pick en "Databases\4 - (1.0.2.1) CustomPick.sql". [S0][S2][S2PHI][S3][S3TAI][S6]

* Nuevos comandos agregados en "Data\CommandManager.txt" (Pick,PickSet,PickClear,SetBuff) [S0][S2][S2PHI][S3][S3TAI][S6] (63,64,65,129)
* Nuevos mensajes en el archivo "Data\Message.txt" [S0][S2][S2PHI][S3][S3TAI][S6] (50,395,450~458)

* Nuevas opciones agregadas en "GameServer\DATA\GameServerInfo - Common.dat". [S0][S2][S2PHI][S3][S3TAI][S6] (MonsterGetTopHitDamageUserMaxTime)
* Nuevas opciones agregadas en "GameServerCS\DATA\GameServerInfo - Common.dat". [S0][S2][S2PHI][S3][S3TAI][S6] (MonsterGetTopHitDamageUserMaxTime)
* Nuevas opciones agregadas en "GameServer\DATA\GameServerInfo - Custom.dat". [S0][S2][S2PHI][S3][S3TAI][S6] (CustomPickSwitch,CustomPickMaxItemList,CustomPick MaxTime_ALX)
* Nuevas opciones agregadas en "GameServerCS\DATA\GameServerInfo - Custom.dat". [S0][S2][S2PHI][S3][S3TAI][S6] (CustomPickSwitch,CustomPickMaxItemList,CustomPick MaxTime_ALX)
* Nuevas opciones agregadas en "GameServer\DATA\GameServerInfo - Event.dat". [S0][S2][S2PHI][S3][S3TAI][S6] (BloodCastleNPCWithoutEntrance,DevilSquareNPCWitho utEntrance,IllusionTempleNPCWithoutEntrance)
* Nuevas opciones agregadas en "GameServerCS\DATA\GameServerInfo - Event.dat". [S0][S2][S2PHI][S3][S3TAI][S6] (BloodCastleNPCWithoutEntrance,DevilSquareNPCWitho utEntrance,IllusionTempleNPCWithoutEntrance)

* Modificado el archivo "ConnectServer\ServerList.dat". [S0][S2][S2PHI][S3][S3TAI][S6]

* Arreglado el problema que mostraba horarios incorrectos en entradas BC,CC,DS e IT. [S0][S2][S2PHI][S3][S3TAI][S6]
* Arreglado el problema del Dark Horse invisible en Blood Castle. [S2PHI]

* Agregado SSeMU Editor. [S0][S2][S2PHI][S3][S3TAI]
* Agregada opcion para mostrar en NPC los niveles necesarios para ingresar al BC,DS e IT. [S0][S2][S2PHI][S3][S3TAI][S6]
* Agregado al GetMainInfo eliminar barraSD, teclas de camara,traymode y monsterbar. [S0][S2][S2PHI][S3][S3TAI][S6]
* Agregado a GetMainInfo nivel minimo necesario para borrar a un personaje. [S0][S2][S2PHI][S3][S3TAI][S6]
* Agregado sistema de dialogo para mostrar advertencias en el juego. [S0][S2][S2PHI][S3][S3TAI][S6]

UPDATE 20-1:
* Actualizada la interface de los ejecutables. [S0][S2][S2PHI][S3][S3TAI][S6].
* Arreglado la opcion RandomOpt en Bags en Formato1. [S0][S2][S2PHI][S3][S3TAI][S6].
* Arreglado el skill invisible luego del trade. [S0][S2][S2PHI][S3][S3TAI]
* Arreglado el problema de hack de paquete 0x0D.[S0][S2][S2PHI][S3][S3TAI][S6]
* Arreglada la estructura de los efectos. [S0][S2][S2PHI][S3][S3TAI][S6]

* Agregado MapManager. S0][S2][S2PHI][S3][S3TAI][S6]
* Agregado CustomItemBow, CustomItemGlove. [S6]

* Modificado el archivo "Data\Skill\EffectList.txt" se modificaron la estructura del archivo. [S0][S2][S2PHI][S3][S3TAI][S6]

UPDATE 20:
* Nuevo archivo para configurar la barra de vide de los mobs en "Data\Custom\CustomHealthBar.txt" [S0][S2][S2PHI][S3][S3TAI][S6].
* Nuevo archivo para configurar los daños PvM y MvP en "Data\Util\DamageTable.txt" [S0][S2][S2PHI][S3][S3TAI][S6].
* Nuevo archivo para configurar los ItemOptionRate por mapas en "Data\MapRateInfo.txt" [S0][S2][S2PHI][S3][S3TAI][S6].

* Nueva opcion agregada en "GameServer\DATA\GameServerInfo - Character.dat". [S0][S2][S2PHI][S3][S3TAI][S6] (XXReflectDamageRateToXX)
* Nueva opcion agregada en "GameServerCS\DATA\GameServerInfo - Character.dat". [S0][S2][S2PHI][S3][S3TAI][S6] (XXReflectDamageRateToXX)

* Nueva opcion agregada en "GameServer\DATA\GameServerInfo - Common.dat". [S2][S2PHI][S3][S3TAI][S6] (ShieldGaugeDisable,ExperienceRandomAditional)
* Nueva opcion agregada en "GameServerCS\DATA\GameServerInfo - Common.dat". [S2][S2PHI][S3][S3TAI][S6] (ShieldGaugeDisable,ExperienceRandomAditional)

* Nueva opcion agregada en "GameServer\DATA\GameServerInfo - Command.dat". [S0][S2][S2PHI][S3][S3TAI][S6] (CommandResetPointRateXX,CommandMasterResetPointRa teXX)
* Nueva opcion agregada en "GameServerCS\DATA\GameServerInfo - Command.dat". [S0][S2][S2PHI][S3][S3TAI][S6] (CommandResetPointRateXX,CommandMasterResetPointRa teXX)

* Nuevas opciones agregadas en "GameServer\DATA\GameServerInfo - Item.dat" para configurar rates de drinks. [S0][S2][S2PHI][S3][S3TAI][S6] (AleIncSpeed,AleIncSpeedTime,OliveOfLoveIncSpeed,O liveOfLoveIncSpeedTime,RemedyOfLoveIncDamage,Remed yOfLoveIncDamageTime,PotionOfBlessConstA,PotionOfB lessConstB,PotionOfBlessTimeConstA,PotionOfSoulCon stA,PotionOfSoulConstB,PotionOfSoulTimeConstA)
* Nuevas opciones agregadas en "GameServerCS\DATA\GameServerInfo - Item.dat" para configurar rates de drinks. [S0][S2][S2PHI][S3][S3TAI][S6] (AleIncSpeed,AleIncSpeedTime,OliveOfLoveIncSpeed,O liveOfLoveIncSpeedTime,RemedyOfLoveIncDamage,Remed yOfLoveIncDamageTime,PotionOfBlessConstA,PotionOfB lessConstB,PotionOfBlessTimeConstA,PotionOfSoulCon stA,PotionOfSoulConstB,PotionOfSoulTimeConstA)

* Nuevas opciones agregada en "GameServer\DATA\GameServerInfo - Skill.dat". [S2][S2PHI][S3][S3TAI][S6] (InfinityArrowSwitch_ALX)
* Nuevas opciones agregada en "GameServerCS\DATA\GameServerInfo - Skill.dat". [S2][S2PHI][S3][S3TAI][S6] (InfinityArrowSwitch_ALX)

* Arreglado el problema del Dark Horse que no daba rango adicional para atacar. [S0][S2][S2PHI][S3][S3TAI][S6]
* Arreglado el problema del PK Assasing en personas que no poseen la actualizacion 1.0.1.9.
* Arreglado el problema de la puerta irrompible del Blood Castle 1. [S0].
* Arreglado el problema del boss indestructible con CustomMonsters en InvasionManager.[S0][S2][S2PHI][S3][S3TAI][S6]
* Arreglado el problema de experiencia 0 en versiones con pocas experiencia. [S0][S2][S2PHI][S3][S3TAI]
* Arreglado el problema de que no andaban los rangos de niveles en itembagsex. [S0][S2][S2PHI][S3][S3TAI][S6]
* Arreglado el error de lectura de InfinityArrowTimeConstA. [S2][S2PHI][S3][S3TAI][S6]
* Arreglado el sign en el select char de los personajes desde "Data\Util\GameMaster.txt". S0][S2][S2PHI][S3][S3TAI][S6]

* Modificada la opcion Invisibility de "Data\Util\GameMaster.txt" [S0][S2][S2PHI][S3][S3TAI][S6] (Invisibility ~ 0: Normal | 1: Invisible for all mobs | 2: Invisible for all players and mobs)

* Modificado el archivo "Data\Item\SetItemOption.txt" se modificaron la estructura del archivo. [S0][S2][S2PHI][S3][S3TAI]
* Modificado el archivo "Data\Item\SetItemType.txt" se modificaron la estructura del archivo. [S0][S2][S2PHI][S3][S3TAI]
* Modificado el archivo "Data\Quest\QuestObjective.txt" se modificaron la estructura del archivo. [S0][S2][S2PHI][S3][S3TAI][S6]
* Modificado el archivo "Data\QuestWorld\QuestWorldObjective.txt" se modificaron la estructura del archivo. [S6]
* Modificado el archivo "Data\QuestWorld\QuestWorldReward.txt" se modificaron la estructura del archivo. [S6]

* Mejorado el rendimiento de los archivos en ejecucion. [S0][S2][S2PHI][S3][S3TAI][S6]
* Se mejoro el Invasion Manager detectando el efecto en cada mapa dependiendo la cantidad de bosses. [S0][S2][S2PHI][S3][S3TAI][S6]
* Se agrego el mapa donde se mato a cada boss en Invasion Manager agregando "%s" al mensaje de BossKilledMessage. [S0][S2][S2PHI][S3][S3TAI][S6]

UPDATE 19:
* Nuevo archivo "Data\PKManager.txt" para configurar opciones de PK. [S0][S2][S2PHI][S3][S3TAI][S6]
* Nuevo archivo "Data\Item\WingOption.txt" para configurar opciones de alas. [S0][S2][S2PHI][S3][S3TAI][S6]
* Nuevas mensajes en el archivo "Data\Message.txt" [S0][S2][S2PHI][S3][S3TAI] (269, and 687 ~ 701)

* Nuevas opciones agregadas en "GameServer\DATA\GameServerInfo - Custom.dat". [S0][S2][S2PHI][S3][S3TAI][S6] (CustomAttackAutoPotionDelay)
* Nuevas opciones agregadas en "GameServerCS\DATA\GameServerInfo - Custom.dat". [S0][S2][S2PHI][S3][S3TAI][S6] (CustomAttackAutoPotionDelay)
* Nuevas opciones agregadas en "GameServer\DATA\GameServerInfo - Character.dat". [S0][S2][S2PHI][S3][S3TAI][S6] (ComboDamageConstC) para calcular el % de daño del combo
* Nuevas opciones agregadas en "GameServerCS\DATA\GameServerInfo - Character.dat". [S0][S2][S2PHI][S3][S3TAI][S6] (ComboDamageConstC) para calcular el % de daño del combo

* Opciones eliminadas en "GameServer\DATA\GameServerInfo - Common.dat". [S0][S2][S2PHI][S3][S3TAI][S6] (PKDeathAnnounce,PKLimitBuyInShops,PKLimitEventEnt ry,PKLimitFree,PKLimitMove,PKLimitMoveSummon)
* Opciones eliminadas en "GameServerCS\DATA\GameServerInfo - Common.dat". [S0][S2][S2PHI][S3][S3TAI][S6] (PKDeathAnnounce,PKLimitBuyInShops,PKLimitEventEnt ry,PKLimitFree,PKLimitMove,PKLimitMoveSummon)

* Modificado el archivo "Data\CommandManager.txt" se modificaron la estructura del archivo. [S0][S2][S2PHI][S3][S3TAI][S6]
* Nuevos comandos agregados en "Data\CommandManager.txt" (Rename,DCFriend,BanChat,UnBanAcc,UnBanChar,UnBanC hat,BCStart,DSStart,CCStart,ITStart) [S0][S2][S2PHI][S3][S3TAI][S6]

* Arreglado el problema del anillo Wizards Ring. [S0][S2][S2PHI][S3][S3TAI][S6]
* Arreglado el problema de multiples renas registradas. [S0][S2][S2PHI][S3][S3TAI][S6]
* Arreglado el problema de stackear items y quedaban en el inventario. [S0][S2][S2PHI][S3][S3TAI][S6]
* Arreglado el problema del Horse de DL. [S3][S3TAI]
* Arreglados los problemas con las entradas CC. [S0]
* Arreglados mensajes extraños en el ejecutable GameServer de CastleSiege. [S0][S2][S2PHI][S3][S3TAI][S6]

* Agregado el tiempo entre posiones en CustomAttack. [S0][S2][S2PHI][S3][S3TAI][S6]
* Agregado script SQL para el comando rename en "Databases\1 - (1.0.1.9) WZ_RenameCharacter.sql". [S0][S2][S2PHI][S3][S3TAI][S6]
* Agregado script SQL para el comando banacc en "Databases\2 - (1.0.1.9) WZ_BanAccount.sql". [S0][S2][S2PHI][S3][S3TAI][S6]
* Agregado script SQL para el comando banchar en "Databases\3 - (1.0.1.9) WZ_BanCharacter.sql". [S0][S2][S2PHI][S3][S3TAI][S6]

UPDATE 18:

* Arreglado el problema de las Jewels en CustomStore. [S0][S2][S2PHI][S3][S3TAI]

* Agregado el comando Pack(61) Unpack(62). "Data\CommandManager.txt" [S0][S2][S3][S3TAI][S6]

* Nuevas opciones en el archivo "Data\Message.txt" [S0][S2][S2PHI][S3][S3TAI] (387 a 392)
* Nuevas opción agregada en "Data\Util\GameMaster.txt" [S0][S2][S2PHI][S3][S3TAI][S6] (Invisibility ~ 0: Normal | 1: Invisible for all players | 2: Invisible for all players and mobs)
* Nuevas opciones agregadas en "GameServer\DATA\GameServerInfo - Custom.dat". [S0][S2][S2PHI][S3][S3TAI][S6] (CustomJewelPackSwitch,CustomJewelPackCommandJoBSy ntax,CustomJewelPackCommandJoSSyntax,CustomJewelPa ckCommandJoLSyntax,CustomJewelPackCommandJoCSyntax ,CustomJewelPackCommandJCRSyntax,CustomJewelPackCo mmandJoGSyntax,CustomJewelPackCommandJoHSyntax)
* Nuevas opciones agregadas en "GameServerCS\DATA\GameServerInfo - Custom.dat". [S0][S2][S2PHI][S3][S3TAI][S6] (CustomJewelPackSwitch,CustomJewelPackCommandJoBSy ntax,CustomJewelPackCommandJoSSyntax,CustomJewelPa ckCommandJoLSyntax,CustomJewelPackCommandJoCSyntax ,CustomJewelPackCommandJCRSyntax,CustomJewelPackCo mmandJoGSyntax,CustomJewelPackCommandJoHSyntax)
* Nuevas opción agregada en "GameServer\DATA\GameServerInfo - Skill.dat". [S0][S2][S2PHI][S3][S3TAI][S6] (CastleSiegeSkillForAllMaps)
* Nuevas opción agregada en "GameServerCS\DATA\GameServerInfo - Skill.dat". [S0][S2][S2PHI][S3][S3TAI][S6] (CastleSiegeSkillForAllMaps)

* Soporte de usar skills castle siege en todos los mapas. [S0][S2][S2PHI][S3][S3TAI][S6]

UPDATE 17-1:
* Nuevas opciones agregada en "GameServer\DATA\GameServerInfo - Common.dat". [S0][S2][S2PHI][S3][S3TAI][S6] (DSJSMaxPacketTime,DSJSMaxPacketCount)
* Nuevas opciones agregada en "GameServerCS\DATA\GameServerInfo - Common.dat". [S0][S2][S2PHI][S3][S3TAI][S6] (DSJSMaxPacketTime,DSJSMaxPacketCount)

* Arreglado el problema de comercio de dinero. [S0][S2]
* Arreglado el problema en CustomNPCCollector y CustomNPCMove que no funcionaba con CustomsNpcs. [S0][S2][S2PHI][S3][S3TAI][S6]
* Arreglado el problema de los nombres incompletos en los requisitos de las quest. [S0][S2][S2PHI][S3][S3TAI][S6]
* Arreglado el problema del tiempo en las entradas del blood castle 7. [S0][S2][S2PHI][S3]
* Arreglado el problema de la High Refinery. [S3]

* Removida la healthbar de los personajes. [S0][S2][S2PHI][S3][S3TAI][S6]

MHPServer:
* Arreglado el problema de desconexiones.

UPDATE 17:
* Nuevo archivo "Data\PKItemDrop.txt" para configurar mas a fondo el PKItemDrop. [S0][S2][S2PHI][S3][S3TAI][S6]

* Nuevas opciones agregada en "GameServer\DATA\GameServerInfo - Common.dat". [S6] (HelperActiveMaxTime_ALX)
* Nuevas opciones agregada en "GameServerCS\DATA\GameServerInfo - Common.dat". [S6] (HelperActiveMaxTime_ALX)
* Nuevas opciones agregada en "GameServer\DATA\GameServerInfo - Common.dat". [S0][S2][S2PHI][S3][S3TAI][S6] (VerifyTimeOutDisconnect,CheckHackSkillAction,Chec kSpeedHackAction,CheckLatencyHackAction,CheckAutoP otionHackAction,CheckAutoComboHackAction,CheckMove HackAction)
* Nuevas opciones agregada en "GameServerCS\DATA\GameServerInfo - Common.dat". [S0][S2][S2PHI][S3][S3TAI][S6] (VerifyTimeOutDisconnect,CheckHackSkillAction,Chec kSpeedHackAction,CheckLatencyHackAction,CheckAutoP otionHackAction,CheckAutoComboHackAction,CheckMove HackAction)
-- 0: No hacer nada | 1: Desconectar | 2: Bloquear IP, HardWareId y Cerrar Cliente.

* Modificado el archivo "Data\Item\Item.txt" se modificaron Todos los sets lucky con sus variables originales (Set 62 a Set 72). [S6]
* Modificado el formato ItemIndex de CustomWing.txt a "00,000". [S0][S2][S2PHI][S3][S3TAI][S6]

* Mejorado el rango MoneyDropRate de MapManager.txt. [S0][S2][S2PHI][S3][S3TAI][S6]

* Arreglado el problema de la masterlevel experience no mostrada. [S6]

* Agregado mensaje al alcanzar el limite máximo del SeniorMix. [S0][S2][S2PHI][S3][S3TAI][S6]
* Agregados nuevos sistemas de seguridad en ConnectServer, MHPServer y GameServer. [S0][S2][S2PHI][S3][S3TAI][S6]

* Opciones removidas de [GameServer\DATA\GameServerInfo - Common.dat] [S0][S2][S2PHI][S3][S3TAI][S6] (MainChecksum,PKItemDropMinPKLevel,PKItemDropRateO nMonsterKill_ALX,PKItemDropRateOnPlayerKill_ALX,PK ItemDropItemMinLevel,PKItemDropItemMaxLevel,PKItem DropCanDropExc,PKItemDropCanDropSet,PKItemDropCanD ropHarmony,PKItemDropCanDrop380,PKItemDropCanDropS ocket)
* Opciones removidas de [GameServerCS\DATA\GameServerInfo - Common.dat] [S0][S2][S2PHI][S3][S3TAI][S6] (MainChecksum,PKItemDropMinPKLevel,PKItemDropRateO nMonsterKill_ALX,PKItemDropRateOnPlayerKill_ALX,PK ItemDropItemMinLevel,PKItemDropItemMaxLevel,PKItem DropCanDropExc,PKItemDropCanDropSet,PKItemDropCanD ropHarmony,PKItemDropCanDrop380,PKItemDropCanDropS ocket)

ConnectServer:
* Nuevas opciones agregada en "ConnectServer\ConnectServer.ini". [S0][S2][S2PHI][S3][S3TAI][S6] (TimeoutDisconnect,VerifyTimeoutDisconnect)

MHPServer:
* Nuevas opciones agregada en "MHPServer\MHPServer.ini". [S0][S2][S2PHI][S3][S3TAI][S6] (TimeoutDisconnect,VerifyTimeoutDisconnect)

Clientes:
* Arreglado el problema crasheo en el cliente al mover un ítem a la maquina chaos. [S0][S2][S2PHI][S3][S3TAI]
* Agregado el TrayMode Tecla F12. [S2][S2PHI][S3][S3TAI][S6]
* Agregada la opciones de cambio de fuente en el cliente. [S0][S2][S2PHI][S3][S3TAI][S6]

UPDATE 16-1:
* Nuevas opciones agregada en "GameServer\DATA\GameServerInfo - Common.dat". [S0][S2][S2PHI][S3][S3TAI][S6] (ServerDebugger)
* Nuevas opciones agregada en "GameServerCS\DATA\GameServerInfo - Common.dat". [S0][S2][S2PHI][S3][S3TAI][S6] (ServerDebugger)

* Agregado soporte para Season 2 Episode 1 Philipine. [S2PHI]
* Agregada consola debug para SkillHack, MoveHack, Ítems inválidos y Monsters inválidos. [BETA] [S0][S2][S2PHI][S3][S3TAI][S6]
* Agregado se muestra la experiencia siempre aunque se suba de nivel. [S0][S2][S2PHI][S3][S3TAI][S6]

* Arreglado el problema de los ítems 380 que no aplicaba el daño. [S2][S3][S3TAI][S6]
* Arreglado el problema del viewport en s2 al recibir veneno. [S2]

Cliente:
* Agregado Right Clic Ítem Move en Main. [S0][S2][S3][S3TAI]

* Arreglado el problema de las jewels Lower Refining Stone y Higher Refining Stone. [S2][S3][S3TAI]
* Arreglado el problema de la Jewel of Creation que tildaba el cliente. [S0]
* Arreglado el problema de la puerta del Castle Siegue. [S6]
* Arreglado el problema del Death Stab que no mostraba el efecto. [S0]

UPDATE 16:
* Arreglado el problema de PKItemDrop que en ciertas ocasiones dropeba ítem con 0 probabilidad. [S0][S2][S3][S3TAI][S6]
* Arreglado el crash del GMPost al usar %s
* Arreglado el CashShop no restaba puntos al comprar.[S3TAI]
* Arreglado el problema que no se borraban las entradas a eventos con durabilidad (BC, CC, DS y IT)
* Arreglado el problema del castle siege de procedimientos erróneos.
* Arreglado el problema de fechas incorrectas en MUCASTLE_DATA. [S0][S2][S3][S3TAI][S6]
* Arreglado el problema de CustomMonster en NPC con barra de vida. [S0][S2][S3][S3TAI][S6]

* Agregado soporte para CustomJewel en "Data\Custom\CustomJewel.txt" [S0][S2][S3][S3TAI]
* Agregada la opción gate en "Data\Custom\CustomMove.txt" [S0][S2][S3][S3TAI][S6]
* Agregada la opción gate en "Data\Custom\CustomNPCMove.txt" [S0][S2][S3][S3TAI][S6]
* Agregada la recompensa de custom arena en "Data\EventItemBag\Custom Arena.txt". [S0][S2]
* Agregado el comando MakeSet(120). "Data\CommandManager.txt" [S0][S2][S3][S3TAI][S6]
* Agregado soporte para recarga automática de flechas durante el attack y offattack. [S0][S2][S2PHI][S3][S3TAI][S6]
* Agregada nueva opción para no descontar flechas. [S0]

* Nuevas opciones agregada en "GameServer\DATA\GameServerInfo - Skill.dat". [S0] (InfinityArrowSwitch_ALX)
* Nuevas opciones agregada en "GameServerCS\DATA\GameServerInfo - Skill.dat". [S0](InfinityArrowSwitch_ALX)

* Modificado el archivo "Data\Custom\CustomJewel.txt" se modificaron opciones para cada version. [S0][S2][S3][S3TAI][S6]
* Modificado el archivo "Data\Event\InvasionManager.dat" se borro la invasión 5 correspondiente a un mob invalido. [S3TAI]
* Modificado el archivo "Data\Monster\MonsterList.txt" se borro el mobs 413 no correspondiente a esta versión. [S3TAI]
* Modificado el archivo "Data\EventItemBagManager.txt" para soportar recompensa CustomArena. [S0][S2]
* Modificado el archivo "GameServer\DATA\GameServerInfo - Character.dat" agregada la linea "CustomArenaDamageRate". [S0][S2]

Cliente:
* Agregado soporte para Custom Jewel en Main. [S0][S2][S3][S3TAI]
* Agregado soporte para Custom Tool Tip en Main. [S0][S2][S3][S3TAI]
* Agregado soporte para ItemStack e ItemValue en Main. [S0][S2][S3][S3TAI][S6]
* Agregado AttackAnimationValue en GetMainInfo. [S0][S2][S3][S3TAI][S6]
* Agregado soporte multilenguage en CustomMessage de GetMainInfo. [S0][S2][S3][S3TAI]

UPDATE 15:
* Arreglado el crash o interface invisible en resoluciones HD en Kanturu. [S2][S3][S3TAI]
* Arreglado el CustomMap en main.dll. [S6]
* Arreglado el contador de gameserver en ConnectServer al recargar. [S0][S2][S3][S3TAI][S6]

UPDATE 14-1:
* Agregados los logs al comprar en CashShop. [S3TAI]
* Agregado el comando "!" para gamemasters. [S0][S2][S3][S3TAI][S6]

* Arreglada la creación de Mobs de InvasionManager en SafeZone. [S0][S2][S3][S3TAI][S6]
* Arreglado el Skill Invisible. [S0][S2][S3][S3TAI][S6]
* Arreglado el error de dupeo por maquina chaos. [S0][S2][S3][S3TAI][S6]
* Arreglados los daños erróneos en main. [S0][S2][S3][S3TAI]

* Mejorado el Skill invisible en GameMasters. [S0][S2][S3][S3TAI][S6]

* Agregada la reducción de consumo de CPU en main. [S0][S2][S3][S3TAI]
* Agregado sistema de Minimap en main. [S0][S2][S3][S3TAI]

UPDATE 14:
* Nuevas opciones agregada en "GameServer\DATA\GameServerInfo - Common.dat". [S0][S2][S3][S3TAI][S6] (ExperienceMultiplierConstA,ExperienceMultiplierCo nstB,MaxLevel,DuelMaxTime)
* Nuevas opciones agregada en "GameServerCS\DATA\GameServerInfo - Common.dat". [S0][S2][S3][S3TAI][S6] (ExperienceMultiplierConstA,ExperienceMultiplierCo nstB,MaxLevel,DuelMaxTime)

* Nuevo archivo "Data\Custom\CustomArena.txt". [S0]
* Nuevo archivo "Data\Terrain\Terrain41.att" [S0][S2]

* Modificado el archivo "Data\MapManager.txt". [S0][S2] (Agregados el mapa index 40)

* Modificado el archivo "Data\Event\EventEntryLevel.dat". [S0][S2][S3][S3TAI][S6] (Cambiado los MaxLevel 400 por *)
* Modificado el archivo "Data\Move\Gate.txt". [S0][S2][S3][S3TAI][S6] (Cambiado los MaxLevel 400 por *)
* Modificado el archivo "Data\Move\Move.txt". [S0][S2][S3][S3TAI][S6] (Cambiado los MaxLevel 400 por *)
* Modificado el archivo "Data\Move\MoveSummon.txt". [S0][S2][S3][S3TAI][S6] (Cambiado los MaxLevel 400 por *)
* Modificado el archivo "Data\Quest\Quest.txt". [S0][S2][S3][S3TAI][S6] (Cambiado los MaxLevel 400 por *)
* Modificado el archivo "Data\QuestWorld\QuestWorld.txt". [S6] (Cambiado los MaxLevel 400 por *)

* Agregado el mapa 40 a main. [S0][S2]
* Agregado sistema de reconnexion en main. [S0][S2]

* Arreglado el Ctrl Fix en Main. [S0]
* Arreglada la Jewel of Elevation. [S6]
* Arreglado el Party Bug al morir. [S0][S2][S3][S3TAI][S6]
* Arreglado el problema de reparar items con trade. [S0][S2][S3][S3TAI][S6]
* Arreglado el problema de zen en trade. [S0][S2][S3][S3TAI][S6]
* Arreglado el CustomMove, CustomNPCMove y otros moves en safezone. [S0][S2][S3][S3TAI][S6]

UPDATE 13:
* Arreglado el problema al coronar Castle Siege. [S0][S2]
* Arreglado el error WZ_CW_InfoLoad y WZ_CW_SaveLoad. [S2]
* Arreglado el sistema de terrenos. [S0][S2][S3][S3TAI][S6]
* Arreglado el disconnect del MG con Evil Spirit. [S3 TAI]
* Arreglado el problema del dragón derecho usando interface downgrade en Kanturu Event,Crywolf y Castle Siege. [S6]
* Arreglado el problema que no se mostraba precio en tiendas coins. [S3][S3TAI]

* Agregado el menú de desconexión y baneo de cuentas y personajes en gameserver. [S0][S2][S3][S3TAI][S6]

* Eliminados todos los terrain, sincronizados los nuevos. [SE DEBE ELIMINAR TERRAINS ANTERIORES] [S0][S2][S3][S3TAI][S6]
* Eliminado el sistema de launcher del connectserver. [S0][S2][S3][S3TAI][S6]

* Modificado el archivo "Data\Hack\HackPacketCheck.txt". [S3TAI]
* Modificado el archivo "Data\Item\Item.txt". [S3TAI]
* Modificado el archivo "Data\Event\CastleSiege.dat" con sus valores reales. [S0][S2][S3][S3TAI]

UPDATE 12:
* Implementado el sistema de reconnect.[S3][S3TAI]
* Implementada las opciones de forzar el inicio de las invasión. [S0][S2][S3][S3TAI][S6]

* Nuevo archivo "Data\EventItemBag\Chaos Card Mix 1.txt" [S3TAI]
* Nuevo archivo "Data\CashShop.txt" [S3TAI]

* Nueva opción agregada en "GameServer\DATA\GameServerInfo - Common.dat". [S2][S3][S3TAI] (SetItemAcceptHarmonySwitch,AutomaticLockSwitch)
* Nueva opción agregada en "GameServerCS\DATA\GameServerInfo - Common.dat". [S2][S3][S3TAI] (SetItemAcceptHarmonySwitch,AutomaticLockSwitch)
* Modificado el archivo con ítems nuevos "Data\Item\Item.txt" [S3TAI]
* Nuevas opciones en el archivo "ConnectServer\ConnectServer.ini" [S0][S2][S3][S3TAI][S6]

* Arreglado la posibilidad de sacar el Harmony en ítems ancient desde el NPC. [S2][S3][S3TAI]
* Arreglado el problema del Seal of Movement que no dejaba warpear gratis. [S3TAI][S6]
* Arreglado el problema de los MISS en PVP. [S0]
* Arreglado el problema de la healthbar que mostraba las traps invisibles. [S0][S2][S3][S3TAI][S6]
* Arreglado el problema del GateKeeper.[S6]
* Arreglado el problema de la alianza desconectaba. [S2]
* Arreglado los mensajes erróneos en Guild Alianza y Hostilidad. [S0][S2][S3][S3TAI][S6]
* Arreglado el error del menú escape con trade. [S2][S3][S3TAI]

* Mejorado el autobloqueo en ConnectServer, MHPServer y GameServers. [S0][S2][S3][S3TAI][S6]
* Mejorado el sistema de WindowMode incluido minimizador (Tecla F12). [S0]
* Mejorado el sistema de efectos. [S0][S2][S3][S3TAI]
* Mejorado el activador/desactivador de MonsterBar (Tecla F8). [S0][S2][S3][S3TAI][S6]

UPDATE 11:
* Nuevas opciones en el archivo "Data\CommandManager.txt" [S0][S2][S3][S6]
* Nuevas opciones en el archivo "Data\Message.txt" [S0][S2][S3][S6]
* Nuevas opciones en el archivo "GameServer\DATA\GameServerInfo - Common.dat" [S0][S2][S3][S6]
* Nuevas opciones en el archivo "GameServerCS\DATA\GameServerInfo - Common.dat" [S0][S2][S3][S6]

* Nuevos comandos agregados /banacc y /banchar. [S0][S2][S3][S6]
* Nuevos comandos agregados /buyvip configuracion en "Data\Custom\CustomBuyVip.txt". [S0][S2][S3][S6]

* Agregado sistema para deshabilitar caída de ítems quest en party y conteo de monstruos. [S0][S2][S3][S6]
* Agregado sistema ItemLoot para evitar que otros personajes tomen ítems de otros personajes. Config en "Data\Item\ItemLoot.txt" [S0][S2][S3][S6]

* Arreglado el sistema de bonusmanager al OnlineReward.txt. [S0][S2][S3][S6]
* Arreglado el problema del party con un solo miembro en PartyReconnect 0. [S0][S2][S3][S6]
* Arreglado el problema de los ítems quest que podían ser agarrado por cualquier personaje. [S0][S2][S3][S6]

UPDATE 10:
* Nuevo archivo agregado en "Data\Util\OnlineReward.txt" [S3][S6]
* Agregada la posibilidad de respawnear donde se muere o al reloguear desde MapManager.
* Agregadas opciones el comando /make 380 y JoH
* Arreglado el problema de la invasionmanager que no respawnean.
* Arreglado el problema de los ítems SET en los shops.
* Arreglado el problema de Kanturu Hands.
* Arreglado el problema de la vida de los mobs, puertas y estatuas en castle siege.

UPDATE 9:
* Arreglado el problema de la opción de matarse entre miembros de la misma party.
* Arreglado el problema al apagar el cashshop no funcionaban las tiendas por coins.

* Nuevas opciones en el archivo "Data\MapManager.txt" [S0][S2][S3][S6]

* Agregado el healthbar al main s0.
* Agregados los puntos en tiempo real en s2.

UPDATE 8:
* Nuevo formato en el archivo "Data\Item\ExcellentOptionRate.txt" [S0][S3][S6]
* Nuevo formato en el archivo "Data\Item\ItemOption.txt" [S0][S3][S6]

* Arreglo en problemas varios en MAIN [S3][S6]

UPDATE 7:
* Nuevas opciones en el archivo "GameServer\DATA\GameServerInfo - Common.dat" [S3][S6]
* Nuevas opciones en el archivo "GameServerCS\DATA\GameServerInfo - Common.dat" [S3][S6]

* Agregado el Golden Archer en "Data\Monster\Spawn\002 - Devias.txt" [S3]
* Agregado el Golden Archer en "Data\Monster\Spawn\003 - Noria.txt" [S3]
* Agregado el empuje en el combo al morir el oponente. [S3][S6]
* Agregado el empuje en el combo al morir los mobs. [S3][S6]
* Agregada la opción a PKItemDrop de ítems 380. [S3][S6]

* Arreglada las opciones CommandMasterResetKeepX [S3][S6]
* Arreglado el problema de CustomGift en DataServer y GameServer. [S3][S6]
* Arreglado el problema de mensajes confusos al dropear cajas. [S3]
* Arreglado el mensaje erróneo en el castle siege. [S3][S6]
* Arreglado el master level del dark horse que no aplicaba defensa. [S6]
* Arreglado el drop de ítems en duelo. [S3]

* Arreglos en "Data\Character\DefaultClassFreebies.txt" [S3]
* Arreglos en "Data\Custom\CustomJewel.txt" [S3]
* Arreglos en "Data\EventItemBag\Game Master Box.txt" [S3]
* Arreglos en "Data\EventItemBag\Silver Medal.txt" [S3]
* Arreglos en "Data\EventItemBag\Gold Medal.txt" [S3]
* Arreglos en "Data\EventItemBag\Leo the Helper.txt" [S3]

* Agregada nueva tabla en base de datos (EventGoldenArcher,GiftData). [S3][S6]
* Procedimientos modificados en base de datos (WZ_DeleteCharacter,WZ_RenameCharacter). [S3][S6]
* Eliminada la tabla (GiftSystem). [S3][S6]

* Cambio de color en la UI de las aplicaciones.

UPDATE 6:
* Agregado el NPC Mirage en "Data\Monster\Spawn\000 - Lorencia.txt" [S3]
* Arreglados el sistema de skill de Illusion Temple. [S3][S6]
* Arreglado Skill Nova [S3]
* Arreglado problemas de texturas. [S3]
* Arreglado ítems brillantes raros. [S3]

* Removido CustomJewel. [S3]

UPDATE 5:
* Agregado sistema de ConnectMember en "Data\ConnectMember.txt" [S3][S6]
* Agregado sistema de ComboSkill en "Data\Skill\ComboSkill.txt" [S3][S6]
* Agregado soporte al ConnectServer para hacer auto update. [S3][S6]

* Nuevas opciones en el archivo "GameServer\DATA\GameServerInfo - Character.dat" [S3][S6]
* Nuevas opciones en el archivo "GameServerCS\DATA\GameServerInfo - Character.dat" [S3][S6]
* Nuevas opciones en el archivo "GameServer\DATA\GameServerInfo - Common.dat" [S3][S6]
* Nuevas opciones en el archivo "GameServerCS\DATA\GameServerInfo - Common.dat" [S3][S6]

* Arreglado el problema de conteo de ítem en QuestWorld. [S6]

UPDATE 4:
* Agregado sistema de uso de skills en zona safe "Data\Skill\SkillUseArea.txt"
* Agregado sistema Monster Move en "Data\Monster\MonsterMove.txt"
* Agregados los nuevos sistemas de recompensa a QuestWorld.

* Sincronizados los terrenos con los terrenos del cliente.

* Arreglado el problema del comando /edit
* Arreglado el drop de la estatua en blood castle.
* Arregladas las misiones de Wandering Merchant Zyro.
* Arreglado el sistema de Quest filtrado por mapnumber.
* Arreglado el sistema de QuestWorld filtrado por mapnumber.

* Removidos los bots (buffer y trader)
* Removido el sistema de "Data\Monster\MarlonSpawn.txt"

UPDATE 3:
* Agregado el sistema de bloqueo automático.

* Arreglado el problema de desconexión al hacer Reload Common.
* Arreglado el problema de mobs creados en zonas safe.
* Arreglado el problema de los PCPoints/Coins por tiempo.

* Nuevas opciones en el archivo "GameServer\DATA\GameServerInfo - Event.dat"
* Nuevas opciones en el archivo "GameServer\DATA\GameServerInfo - Common.dat"

* Modificado el comando makemob Modo1: /makemob <mob> Modo2: /makemob <-mob> <map> <y> <x>

* Mejorado el comando /setcoin
* Mejorado el comando /edit

UPDATE 2:
* Agregada la opción de recuperación de vida del Kundum al fallar Crywolf.
* Agregado el sistema de venta en shops por coins.

* Agregado el archivo "Data\Custom\CustomMasterResetReward.txt"

* Arreglado el problema del SeniorMix en Season3.
* Arreglado el problema de carga de terrenos inválidos.
* Arreglado el problema de carga de mobs en mapas inválidos.
* Arreglado el problema de múltiples shops con diferente archivo.
* Arreglado el problema del offhelper de reparación automática.
* Arreglado el problema del offhelper del heal constante.

* Eliminado el archivo "Data\Custom\CustomRespawn.txt"
* Eliminado el archivo "Data\Custom\CustomSpawn.txt"

* Nuevas opciones en el archivo "Data\MapManager.txt"
* Nuevas mensajes en el archivo "Data\Message.txt"
* Nuevas opciones en el archivo "Data\ShopManager.txt"
* Nuevas opciones en el archivo "GameServer\DATA\GameServerInfo - Event.dat"
* Nuevas opciones en el archivo "GameServer\DATA\GameServerInfo - Common.dat"

* Removido el GameServerCS.
* Removidas cosas innecesarias de "ConnectServer\ServerList.dat"
* Removidas cosas innecesarias de "Data\MapServerInfo.txt"
