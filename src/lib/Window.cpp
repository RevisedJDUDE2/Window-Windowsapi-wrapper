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

  if(!RegisterClassExA(&priWndClass))
    MessageBoxA(nullptr, "Cannot Register\n\nERROR 0x1", "WIN PROC", MB_OK);
}

LRESULT winCallBackProc(HWND handle, UINT msg, WPARAM wp, LPARAM lp) {
  LRESULT res = 0;
  switch (msg) {
    case WM_CREATE:
      ppWinInf->EXTENDEDWINDOWINFOONCREATE.OnCreate(handle, GetModuleHandle(0), msg); //CALLS THE CREATE FUNCTION?
      //TODO: break;
    case WM_QUIT:
      *bwWindowShould = false;
      break;
    case WM_KEYDOWN:
      if(wp == VK_SHIFT && wp == VkKeyScanA('p')) {
        MessageBoxA(handle, "Hello World!", "", MB_OK);
      }
    default:
      res =  DefWindowProcA(handle, msg, wp, lp);   
      break;
  };
  return res;
}
