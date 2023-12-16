#include <windows.h>
#include <Window.hpp>
#include <winuser.h>

int WINAPI WinMain(HINSTANCE hThis, HINSTANCE hPrev, LPSTR Args, int Ncmd) {
  Window win1;
  win1.Init("Hello World", 0, 0, 800, 600);
  while (win1.ShouldClose()) {
    MSG message; //HANDLE TO MESSAGE
    while(PeekMessage(&message, win1.GetHandle(), 0, 0, PM_REMOVE) > 0) {
      TranslateMessage(&message);
      DispatchMessage(&message);
    }
  }
  DestroyWindow(win1.GetHandle());
  return 0;
}
