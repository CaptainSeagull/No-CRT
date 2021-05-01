#include <windows.h>
#include <stdint.h>

extern "C" {
	int _fltused = 0;

#pragma function(memset)
	void *memset(void *dst, int v, size_t cnt) {
		uint8_t *dst8 = (uint8_t *)dst;
		while(cnt--) {
			*dst8++ = (uint8_t)v;
		}

		return(dst);
	}

#pragma function(memcpy)
	void *memcpy(void *dst, const void *src, size_t cnt) {
		uint8_t *dst8 = (uint8_t *)dst;
		uint8_t *src8 = (uint8_t *)src;
		while(cnt--) {
			*dst8++ = *src8++;
		}

		return(dst);
	}
}

int CALLBACK WinMain(HINSTANCE Instance, HINSTANCE PrevInstance, LPSTR CommandLine, int ShowCode) {
	MessageBoxA(0, "", "", MB_OK);

	return(0);
}

void __stdcall WinMainCRTStartup() {
	int Result = WinMain(GetModuleHandle(0), 0, GetCommandLineA(), 0);
	ExitProcess(Result); // Is it OK to just return from WinMainCRTStartup?
}