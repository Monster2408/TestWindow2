#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>

#define WINDOW_WIDTH    800
#define WINDOW_HEIGHT   600

void DoGetActiveWindow();

int main()
{
	DoGetActiveWindow();
    return 0;
}

/* アクティブウィンドウのタイトルを表示する */
void DoGetActiveWindow(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow) {
	HWND hwnd;
	WNDCLASS winc;
	MSG msg;

	winc.style = CS_HREDRAW | CS_VREDRAW;
	winc.lpfnWndProc = DefWindowProc;
	winc.cbClsExtra = winc.cbWndExtra = 0;
	winc.hInstance = hInstance;
	winc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winc.hCursor = LoadCursor(NULL, IDC_ARROW);
	winc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	winc.lpszMenuName = NULL;
	winc.lpszClassName = _T("MainClass");

	if (!RegisterClass(&winc)) return 0;

	hwnd = CreateWindow(
		_T("MainClass"), _T("検定対策ソフト"),
		WS_OVERLAPPEDWINDOW,
		100, 100, WINDOW_WIDTH, WINDOW_HEIGHT, NULL, NULL,
		hInstance, NULL
	);

	TextOut(hwnd, 0, 0, _T("TEXT"), 0);

	if (hwnd == NULL) return 0;

	ShowWindow(hwnd, SW_SHOW);
	while (GetMessage(&msg, NULL, 0, 0)) {
		DispatchMessage(&msg);
	}

	return 0;
}
