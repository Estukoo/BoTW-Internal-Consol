#pragma once

enum RenderingBackend_t {
	NONE = 0,

	OPENGL,
	VULKAN,
};

namespace Utils {
	void SetRenderingBackend(RenderingBackend_t eRenderingBackend);
	RenderingBackend_t GetRenderingBackend( );
	const char* RenderingBackendToStr( );

	HWND GetProcessWindow( );
	void UnloadDLL( );
	
	HMODULE GetCurrentImageBase( );

	int GetCorrectDXGIFormat(int eCurrentFormat);
}

namespace U = Utils;
