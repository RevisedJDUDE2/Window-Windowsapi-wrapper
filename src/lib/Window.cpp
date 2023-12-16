#include <windows.h>
#include <Window.hpp>
#include <wingdi.h>
#include <winuser.h>

LRESULT winCallBackProc(HWND, UINT, WPARAM, LPARAM);

void ciInfo::SETUPCLASS(void) {
  WNDCLASSEXA priWndClass = {sizeof(WNDCLASSEXA)};
  priWndClass.hInstance = GetModuleHandle(0);
  priWndClass.lpszClassName = "Window1";
  priWndClass.lpfnWndProc = winCallBackProc;
  priWndClass.hbrBackground = CreateSolidBrush(RGB(255, 0, 0));

  if(!RegisterClassExA(&priWndClass))
    MessageBoxA(nullptr, "Cannot Register\n\nERROR 0x1", "WIN PROC", MB_OK);
}

LRESULT winCallBackProc(HWND handle, UINT msg, WPARAM wp, LPARAM lp) {
  LRESULT res = 0;
  switch (msg) {
    case WM_QUIT:
      *bwWindowShould = false;
      break;
    case WM_KEYDOWN:
      if(wp == VkKeyScanA('P')) {
        MessageBoxA(handle, "Hello World!", "", MB_OK);
      }
    default:
      res =  DefWindowProcA(handle, msg, wp, lp);   
      break;
  };
  return res;
}
