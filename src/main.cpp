#include <windows.h>
#include <Window.hpp>

void OnCreate(HWND, HINSTANCE, UINT);

int WINAPI WinMain(HINSTANCE hThis, HINSTANCE hPrev, LPSTR Args, int Ncmd) {
  Window win1;
  win1.Init("Hello World!", 0, 0, 800, 600);
  win1.EXTENDEDWINDOWINFOONCREATE.OnCreate = OnCreate;
  BindControls(&win1);
  while (win1.ShouldClose()) {
    MSG message; //HANDLE TO MESSAGE
    while(PeekMessage(&message, win1.GetHandle(), 0, 0, PM_REMOVE) > 0) {
      TranslateMessage(&message);
      DispatchMessage(&message);
    }
    //RENDER HERe 
  }
  DestroyWindow(win1.GetHandle());
  return 0;
}

void OnCreate(HWND handle, HINSTANCE hinstance, UINT msg) {
  MessageBoxA(nullptr, "Hello World", "", MB_OK);
}
