#include <windows.h>

class ciInfo {
  public:
    void SETUPCLASS(void);
};

typedef struct {
  void(*OnCreate)(HWND, HINSTANCE, UINT);
} EXTENDED_WINDOW_INFO;

static bool *bwWindowShould = new bool(true); 

class Window {
  private:
    HWND Hwnd;
  public:
    void Init(LPSTR title, int x, int y, int w, int h) {
      ciInfo ci1;
      ci1.SETUPCLASS();
      HWND pHwnd;
      pHwnd = CreateWindowExA(0, "Window1", title, WS_OVERLAPPEDWINDOW | WS_VISIBLE, x, y, w, h, nullptr, nullptr, GetModuleHandle(0), nullptr);
      this->Hwnd = pHwnd;
      if(Hwnd == INVALID_HANDLE_VALUE) {
        MessageBoxA(nullptr, "Cannot Create Window\n\nERROR 0x2", "Window", MB_OK);
        *bwWindowShould = false;
      }
      ShowWindow(pHwnd, SW_SHOW);
    };

    HWND GetHandle() const {
      return this->Hwnd;
    }
    bool ShouldClose() const {
      return *bwWindowShould;
    }
    EXTENDED_WINDOW_INFO EXTENDEDWINDOWINFOONCREATE;
};

Window *ppWinInf = new Window;

void BindControls(const Window* wiInf) {
  ppWinInf->EXTENDEDWINDOWINFOONCREATE.OnCreate = wiInf->EXTENDEDWINDOWINFOONCREATE.OnCreate;
}
