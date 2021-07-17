#pragma once
#include <Windows.h>
#include <d3d9.h>
#ifndef _DEBUG
	#define OutputDebugString ;
#endif

#define EXE_BASE_ADDRESS 0x400000
void perform_sr2_patches();