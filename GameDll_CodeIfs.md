The internal code of the game dll, and the so-called ifs that do this. In gHidra and Cheat Engine.
1.27b - gHydra Code - game.dll So far there are no other ifs involved in this.

//Section: 1 //section only for the main buttons hide.

                             LAB_6f3ca277                                    XREF[1]:     6f3ca24e(j)  
        6f3ca277 8b 45 08        MOV        EAX,dword ptr [EBP + param_1]
        6f3ca27a 8d 4f 1c        LEA        ECX,[EDI + 0x1c]
        6f3ca27d 89 41 04        MOV        dword ptr [ECX + 0x4],EAX
        6f3ca280 8b 45 0c        MOV        EAX,dword ptr [EBP + param_2]
        6f3ca283 89 41 08        MOV        dword ptr [ECX + 0x8],EAX
        6f3ca286 8b 45 10        MOV        EAX,dword ptr [EBP + param_3]
        6f3ca289 89 41 10        MOV        dword ptr [ECX + 0x10],EAX
        6f3ca28c 8b 45 14        MOV        EAX,dword ptr [EBP + param_4]
        6f3ca28f 89 41 0c        MOV        dword ptr [ECX + 0xc],EAX
        6f3ca292 8b 45 18        MOV        EAX,dword ptr [EBP + param_5]
        6f3ca295 89 41 14        MOV        dword ptr [ECX + 0x14],EAX
        6f3ca298 8b 45 1c        MOV        EAX,dword ptr [EBP + param_6]
        6f3ca29b 83 f8 03        CMP        EAX,0x3 <- "the if"
        6f3ca29e 77 06           JA         LAB_6f3ca2a6
        6f3ca2a0 89 81 9c        MOV        dword ptr [ECX + 0x59c],EAX
                 05 00 00
                             LAB_6f3ca2a6                                    XREF[1]:     6f3ca29e(j)  
        6f3ca2a6 8b 45 20        MOV        EAX,dword ptr [EBP + param_7]
        6f3ca2a9 83 f8 02        CMP        EAX,0x2 <- "the if"
        6f3ca2ac 77 06           JA         LAB_6f3ca2b4
        6f3ca2ae 89 81 a0        MOV        dword ptr [ECX + 0x5a0],EAX
                 05 00 00

Write - Cheat Engine Detect - game.dll 1.27b

Game.dll+3CA2A0:
65DCA29B - 83 F8 03 - cmp eax,03
65DCA29E - 77 06 - ja Game.dll+3CA2A6
65DCA2A0 - 89 81 9C050000  - mov [ecx+0000059C],eax <<
65DCA2A6 - 8B 45 20  - mov eax,[ebp+20]
65DCA2A9 - 83 F8 02 - cmp eax,02

EAX=00000003
EBX=162300BC
ECX=16211CA4
EDX=162A013C
ESI=E446D7B5
EDI=16211C88
ESP=012FEBE8
EBP=012FEC0C
EIP=65DCA2A6

1.27b - gHydra Code - game.dll
Section: 2 //section only for the spell buttons hide.

        6f36b482 e8 99 aa        CALL       FUN_6f3b5f20                                     undefined FUN_6f3b5f20(undefined
                 04 00
        6f36b487 85 c0           TEST       EAX,EAX
        6f36b489 74 2f           JZ         LAB_6f36b4ba
        6f36b48b 8b 55 10        MOV        EDX,dword ptr [EBP + param_3]
        6f36b48e 8b 32           MOV        ESI,dword ptr [EDX]
        6f36b490 83 fe 03        CMP        ESI,0x3 <- "the if"
        6f36b493 77 0c           JA         LAB_6f36b4a1
        6f36b495 8b 88 90        MOV        ECX,dword ptr [EAX + 0x190]
                 01 00 00
        6f36b49b 89 b1 9c        MOV        dword ptr [ECX + 0x59c],ESI
                 05 00 00
        6f36b493 77 0c           JA         LAB_6f36b4a1
        6f36b495 8b 88 90        MOV        ECX,dword ptr [EAX + 0x190]
                 01 00 00
        6f36b49b 89 b1 9c        MOV        dword ptr [ECX + 0x59c],ESI
                 05 00 00
                             LAB_6f36b4a1                                    XREF[1]:     6f36b493(j)  
        6f36b4a1 8b 4a 04        MOV        ECX,dword ptr [EDX + 0x4]
        6f36b4a4 83 f9 02        CMP        ECX,0x2 <- "the if"
        6f36b4a7 77 44           JA         LAB_6f36b4ed
        6f36b4a9 8b 80 90        MOV        EAX,dword ptr [EAX + 0x190]
                 01 00 00
   
Section: 2 //Part 2 the spell buttons hide.

        6f36b4cb 85 c0           TEST       EAX,EAX
        6f36b4cd 74 1e           JZ         LAB_6f36b4ed
        6f36b4cf 8b 55 10        MOV        EDX,dword ptr [EBP + param_3]
        6f36b4d2 8b 0a           MOV        ECX,dword ptr [EDX]
        6f36b4d4 83 f9 03        CMP        ECX,0x3 <- "the if"
        6f36b4d7 77 06           JA         LAB_6f36b4df
        6f36b4d9 89 88 9c        MOV        dword ptr [EAX + 0x59c],ECX
                 05 00 00
                             LAB_6f36b4df                                    XREF[1]:     6f36b4d7(j)  
        6f36b4df 8b 4a 04        MOV        ECX,dword ptr [EDX + 0x4]
        6f36b4e2 83 f9 02        CMP        ECX,0x2 <- "the if"
        6f36b4e5 77 06           JA         LAB_6f36b4ed
        6f36b4e7 89 88 a0        MOV        dword ptr [EAX + 0x5a0],ECX
                 05 00 00

Write - Cheat Engine Detect - game.dll 1.27b

6E06B4D4 - 83 F9 03 - cmp ecx,03
6E06B4D7 - 77 06 - ja Game.dll+36B4DF
6E06B4D9 - 89 88 9C050000  - mov [eax+0000059C],ecx <<
6E06B4DF - 8B 4A 04  - mov ecx,[edx+04]
6E06B4E2 - 83 F9 02 - cmp ecx,02

EAX=198F7EA4
EBX=0CC2B6D4
ECX=00000001
EDX=0115F934
ESI=15B40088
EDI=41303035
ESP=0115F8FC
EBP=0115F900
EIP=6E06B4DF

//Section: 3 //I still don't know what this does, but it's not present in the 1.27a or 1.28a patches...
1.27b - gHydra Code - game.dll  
                        
                             FUN_6f373a90
        6f373a90 55              PUSH       EBP
        6f373a91 8b ec           MOV        EBP,ESP
        6f373a93 8b 55 08        MOV        EDX,dword ptr [EBP + param_1]
        6f373a96 83 fa 03        CMP        EDX,0x3 <- "the if"
        6f373a99 77 0c           JA         LAB_6f373aa7
        6f373a9b 8b 81 90        MOV        EAX,dword ptr [ECX + 0x190]
                 01 00 00
        6f373aa1 89 90 9c        MOV        dword ptr [EAX + 0x59c],EDX
                 05 00 00
                             LAB_6f373aa7                                    XREF[1]:     6f373a99(j)  

                             undefined FUN_6f373ab0(undefined4 param_1)
                               assume FS_OFFSET = 0xffdff000
             undefined         AL:1           <RETURN>
             undefined4        Stack[0x4]:4   param_1                                 XREF[1]:     6f373ab3(R)  
                             FUN_6f373ab0
        6f373ab0 55              PUSH       EBP
        6f373ab1 8b ec           MOV        EBP,ESP
        6f373ab3 8b 45 08        MOV        EAX,dword ptr [EBP + param_1]
        6f373ab6 83 f8 03        CMP        EAX,0x3 <- "the if"
        6f373ab9 77 06           JA         LAB_6f373ac1
        6f373abb 89 81 9c        MOV        dword ptr [ECX + 0x59c],EAX
                 05 00 00
                             LAB_6f373ac1                                    XREF[1]:     6f373ab9(j)  

                             undefined FUN_6f373ad0(undefined4 param_1)
                               assume FS_OFFSET = 0xffdff000
             undefined         AL:1           <RETURN>
             undefined4        Stack[0x4]:4   param_1                                 XREF[1]:     6f373ad3(R)  
                             FUN_6f373ad0
        6f373ad0 55              PUSH       EBP
        6f373ad1 8b ec           MOV        EBP,ESP
        6f373ad3 8b 55 08        MOV        EDX,dword ptr [EBP + param_1]
        6f373ad6 83 fa 02        CMP        EDX,0x2 <- "the if"
        6f373ad9 77 0c           JA         LAB_6f373ae7
        6f373adb 8b 81 90        MOV        EAX,dword ptr [ECX + 0x190]
                 01 00 00
        6f373ae1 89 90 a0        MOV        dword ptr [EAX + 0x5a0],EDX
                 05 00 00
                             LAB_6f373ae7                                    XREF[1]:     6f373ad9(j)  

                             undefined FUN_6f373af0(undefined4 param_1)
                               assume FS_OFFSET = 0xffdff000
             undefined         AL:1           <RETURN>
             undefined4        Stack[0x4]:4   param_1                                 XREF[1]:     6f373af3(R)  
                             FUN_6f373af0
        6f373af0 55              PUSH       EBP
        6f373af1 8b ec           MOV        EBP,ESP
        6f373af3 8b 45 08        MOV        EAX,dword ptr [EBP + param_1]
        6f373af6 83 f8 02        CMP        EAX,0x2 <- "the if"
        6f373af9 77 06           JA         LAB_6f373b01
        6f373afb 89 81 a0        MOV        dword ptr [ECX + 0x5a0],EAX
                 05 00 00
                             LAB_6f373b01                                    XREF[1]:     6f373af9(j)  
        6f373b01 5d              POP        EBP
