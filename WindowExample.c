#include <windows.h>

const char ClassNameSIZE[] = "WindowClass";

LRESULT CALLBACK WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {

switch (Msg) {
    case WM_CLOSE:
        DestroyWindow(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, Msg, wParam, lParam);
}
return 0;
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int nCmdShow) {

WNDCLASSEX WinCtr;
HWND hWnd;
MSG Message;

WinCtr.cbSize = sizeof(WNDCLASSEX);
WinCtr.style = CS_DROPSHADOW;
WinCtr.lpfnWndProc = WndProc;
WinCtr.cbClsExtra = 0;
WinCtr.hInstance = hInstance;
WinCtr.hIcon = LoadIcon(NULL, IDI_APPLICATION);
WinCtr.hCursor = LoadCursor(NULL, IDC_ARROW);
WinCtr.hbrBackground = (HBRUSH)(COLOR_WINDOW+2);
WinCtr.lpszMenuName = NULL;
WinCtr.lpszClassName = ClassNameSIZE;
WinCtr.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

if(!RegisterClassEx(&WinCtr)) {
    MessageBox(NULL, "Window Registration has failed.", "An Error has Occured", MB_ICONEXCLAMATION | MB_OK);
    return 0;
}

hWnd = CreateWindowEx(WS_EX_CLIENTEDGE, ClassNameSIZE, "Program01", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, NULL, NULL, hInstance, NULL);

if (hWnd == NULL) {
    MessageBox(NULL, "Window failed to be created.", "An Error has Occurred.", MB_ICONEXCLAMATION | MB_OK);
    return 0;
}

ShowWindow(hWnd, nCmdShow);
FreeConsole();
UpdateWindow(hWnd);

while(GetMessage(&Message, NULL, 0, 0) > 0) {
    TranslateMessage(&Message);
    DispatchMessage(&Message);
}
return Message.wParam;
}