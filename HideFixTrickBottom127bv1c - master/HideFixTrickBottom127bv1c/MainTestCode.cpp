//Thanks to "karaulov (Warcraft III bypass map file size limit)" for the main base of this code.
//Angelcraft: (this code is still being tested.)
#include <windows.h>
#include "verinfo.h"

HMODULE gamedll;
DWORD gamedllsize;

int gameversion = 0;
int gamesubversion = 0;
UINT_PTR addr = 0;

//Thanks to "247CTF" for his tutorial "Hacking a game with DLL injection [Game Hacking 101] 
//youtube" where this code is based.
const int total_memory_ChangeValue = 10;//number of bytes to hack, representing the size of an array, in this case 10 bytes.
const int patch_size = 1;//size of the number of bytes to replace, it is only 1 byte in this case.

struct memory_ChangeValue {
	void* patch_address;
	byte patch_bytes[patch_size];
	byte original_bytes[patch_size];
};

struct memory_ChangeValue memory_ChangeValue[total_memory_ChangeValue];
HANDLE aoe_handle = GetCurrentProcess();

void init_ChangeValue() {
	//assigns the value gamedll transforming it into an address
	addr = ((UINT_PTR)gamedll);
	
	//Section: 1 //section only for the main buttons hide.
	memory_ChangeValue[0] = { (void*)(addr + 0x3CA29D), { 0xFF }, { 0x3 } };
	memory_ChangeValue[1] = { (void*)(addr + 0x3CA2AB), { 0xFF }, { 0x2 } };
	//Section: 2 //section only for the spell buttons hide.
	memory_ChangeValue[2] = { (void*)(addr + 0x36B492), { 0xFF }, { 0x3 } };
	memory_ChangeValue[3] = { (void*)(addr + 0x36B4A6), { 0xFF }, { 0x2 } };
	memory_ChangeValue[4] = { (void*)(addr + 0x36B4D6), { 0xFF }, { 0x3 } };
	memory_ChangeValue[5] = { (void*)(addr + 0x36B4E4), { 0xFF }, { 0x2 } };
	//Section: 3 //I still don't know what this does, but it's not present in the 1.27a or 1.28a patches...
	memory_ChangeValue[6] = { (void*)(addr + 0x373A98), { 0xFF }, { 0x3 } };
	memory_ChangeValue[7] = { (void*)(addr + 0x373AB8), { 0xFF }, { 0x3 } };
	memory_ChangeValue[8] = { (void*)(addr + 0x373AD8), { 0xFF }, { 0x2 } };
	memory_ChangeValue[9] = { (void*)(addr + 0x373AF8), { 0xFF }, { 0x2 } };
}

BOOL WINAPI DllMain( HINSTANCE hi , DWORD reason , LPVOID )
{

	if ( reason == DLL_PROCESS_ATTACH )
	{
		// Get Kernel32.dll address
		HMODULE krn32 = GetModuleHandle( "Kernel32.dll" );
		if ( !krn32 )
		{
			MessageBox( NULL , "No Kernel32.dll found!" , "ERROR" , MB_OK );
			return FALSE;
		}

		// Get GetFileSize func address
		DWORD filesizeaddr = ( DWORD ) GetProcAddress( krn32 , "GetFileSize" );
		if ( !filesizeaddr )
		{
			MessageBox( NULL , "No Kernel32.dll GetFileSize found!" , "ERROR" , MB_OK );
			return FALSE;
		}

		// Get Game.dll address
		gamedll = GetModuleHandle( "Game.dll" );
		if ( !gamedll )
		{
			return FALSE;
		}

		// file / module version info
		CFileVersionInfo gdllver;
		gdllver.Open( gamedll );

		// Game.dll version (1.XX)
		gameversion = gdllver.GetFileVersionMinor( );
		gamesubversion = gdllver.GetFileVersionBuild( );
		
		//Check if it is version 1"27.1" which is itself 1"27.b"
		if (gameversion == 27 && gamesubversion == 1)
		{
			//assigns the value gamedll transforming it into an address
			addr = ((UINT_PTR)gamedll);

			//check if in given address the value containing 0x3
			char* pointer = (char*)((DWORD)gamedll + 0x36B492);
			char value = *pointer;
			char first_byte = pointer[0];

			//check if in given address the value containing 0x2
			pointer = (char*)((DWORD)gamedll + 0x36B4A6);
			value = *pointer;
			char second_byte = pointer[0];

			if( (int)first_byte == 3 && (int)second_byte == 2)
			{
				////Changing the values of the ifs, 0x3, 0x2, to 0xFF, which this value makes if no longer work.
				init_ChangeValue();
				void* to_patch;
				addr = ((UINT_PTR)gamedll);
				for (int i = 0; i < total_memory_ChangeValue; i++) {
					to_patch = &memory_ChangeValue[i].patch_bytes; //to_patch = &memory_hacks[i].original_bytes;
					WriteProcessMemory(aoe_handle, (void*)memory_ChangeValue[i].patch_address, to_patch, patch_size, 0);
				}
			}
		}
		gdllver.Close( );
	}
	else if ( reason == DLL_PROCESS_DETACH )
	{

	}
	return TRUE;
}