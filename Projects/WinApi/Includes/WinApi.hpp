#pragma once
#include <WinApi/ArithmeticTypes.hpp>

extern "C" { namespace Aiva::WinApi
{
    constexpr const uint32_t INVALID_HANDLE_VALUE = static_cast<uint32_t>(-1);
    constexpr const uint32_t ERROR_SUCCESS = 0;

    constexpr const uint32_t STD_INPUT_HANDLE = static_cast<uint32_t>(-10);
    constexpr const uint32_t STD_OUTPUT_HANDLE = static_cast<uint32_t>(-11);
    constexpr const uint32_t STD_ERROR_HANDLE = static_cast<uint32_t>(-12);

    constexpr const uint32_t SW_HIDE = 0;
    constexpr const uint32_t SW_SHOWNORMAL = 1;
    constexpr const uint32_t CW_USEDEFAULT = 0x80000000;

    using WNDPROC = int64_t(__stdcall*)(void* /*hWnd*/, uint32_t /*uMsg*/, uint64_t /*wParam*/, int64_t /*lParam*/);

    struct WNDCLASSEXW final
	{
		uint32_t cbSize{};
		uint32_t style{};
		WNDPROC lpfnWndProc{};
		int32_t cbClsExtra{};
		int32_t cbWndExtra{};
		void* hInstance{};
		void* hIcon{};
		void* hCursor{};
		void* hbrBackground{};
		wchar_t const* lpszMenuName{};
		wchar_t const* lpszClassName{};
		void* hIconSm{};
	};

    void* __stdcall CreateWindowExW(uint32_t exStyle, wchar_t const* className, wchar_t const* windowName, uint32_t style, uint32_t x, uint32_t y, uint32_t width, uint32_t height, void* parentWindow, void* menu, void* instance, void* param);

    int64_t __stdcall DefWindowProcW(void* hWnd, uint32_t uMsg, uint64_t wParam, int64_t lParam);

    int32_t __stdcall DestroyWindow(void* hWnd);

    int32_t __stdcall GetClassInfoExW(void* hInstance, wchar_t const* lpszClass, WNDCLASSEXW* lpwcx);

    void* __stdcall GetModuleHandleW(wchar_t const* moduleName);

    void* __stdcall GetStdHandle(uint32_t const nStdHandle);

    int32_t __stdcall IsWindow(void* hWnd);

    int32_t __stdcall IsWindowVisible(void* hWnd);

    uint16_t __stdcall RegisterClassExW(WNDCLASSEXW const* const lpwcx);

    int32_t __stdcall ShowWindow(void* hWnd, int32_t nCmdShow);

    void __stdcall Sleep(uint32_t const dwMilliseconds);

    int32_t __stdcall UnregisterClassW(wchar_t const* lpClassName, void* hInstance);

    int __stdcall WriteFile(void *const hFile, void const*const lpBuffer, uint32_t const nNumberOfBytesToWrite, uint32_t *const lpNumberOfBytesWritten, void *const lpOverlapped);

    void __stdcall ExitProcess(uint32_t const uExitCode);
}}
// extern "C" namespace Aiva::WinApi
