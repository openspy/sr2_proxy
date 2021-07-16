#include <stdio.h>
#include <stdio.h>
#include <Windows.h>
#include <assert.h>

void write_string_offset(void *address, int string_len, const char* string) {
	void* exe_mem_offset = (void*)0x400000;

	void* write_address = (void*)((ptrdiff_t)exe_mem_offset + (ptrdiff_t)address);
	DWORD oldProtect;

	BOOL success = VirtualProtect(write_address, string_len, PAGE_READWRITE, &oldProtect);

	
	assert(success);
	SIZE_T numWritten = 0;
	success = WriteProcessMemory(GetCurrentProcess(), write_address, string, string_len, &numWritten);
	assert(success);

	DWORD protect;
	success = VirtualProtect(write_address, string_len, oldProtect, &protect);

	assert(success);

}
void perform_sr2_patches() {

	write_string_offset((void*)0xA88CD0, 17, "gpsp.openspy.net");
	
	write_string_offset((void*)0xA88E18, 17, "gpcm.openspy.net");
	write_string_offset((void*)0xA33568, 25, "%s.available.openspy.net");
	write_string_offset((void*)0xA355B0, 20, "%s.ms%d.openspy.net");
	
	
	write_string_offset((void*)0xA37E44, 20, "natneg1.openspy.net");
	write_string_offset((void*)0xA37E58, 20, "natneg2.openspy.net");
	write_string_offset((void*)0xA37E6C, 20, "natneg3.openspy.net");
	

	

	write_string_offset((void*)0xA33E60, 12, "openspy.net");
	write_string_offset((void*)0xA34088, 64, "http://%s.sake.openspy.net/SakeStorageServer/StorageServer.asmx");
	write_string_offset((void*)0xA346F8, 77, "http://%s.comp.pubsvs.openspy.net/CompetitionService/CompetitionService.asmx");
	write_string_offset((void*)0xA34A54, 22, "%s.master.openspy.net");
	write_string_offset((void*)0xA38080, 22, "http://motd.openspy.net/motd/motd.asp");
	write_string_offset((void*)0xA38018, 42, "http://motd.openspy.net/motd/vercheck.asp");

	write_string_offset((void*)0xA35600, 64, "http://%s.auth.pubsvs.openspy.net/AuthService/AuthService.asmx\x00");
	
	write_string_offset((void*)0x9D0C78, 257, "afb5818995b3708d0656a5bdd20760aee76537907625f6d23f40bf17029e56808d36966c0804e1d797e310fedd8c06e6c4121d963863d765811fc9baeb2315c9a6eaeb125fad694d9ea4d4a928f223d9f4514533f18a5432dd0435c5c6ac8e276cf29489cb5ac880f16b0d7832ee927d4e27d622d6a450cd1560d7fa882c6c13");
}