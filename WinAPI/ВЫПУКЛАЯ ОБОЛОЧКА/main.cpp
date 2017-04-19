#include <windows.h>
#include <ctime>
#define ID_COUNT1  1
#define ID_COUNT2  2
#define ID_COUNT3  3
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL InitApplication(HINSTANCE  hInstance);
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);

LPCSTR szClassName = "WinAPI";
LPCSTR szTitle =	 "Выпуклая оболочка";

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG msg;
	if (!hPrevInstance)
	{
		if (!InitApplication(hInstance))
			return (FALSE);
	}
	if (!InitInstance(hInstance, nCmdShow))
		return (FALSE);

	while(GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (msg.wParam);
}
BOOL InitApplication(HINSTANCE hInstance)
{
	WNDCLASS wc;
	wc.style		 = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc	 = (WNDPROC)WndProc;
	wc.cbClsExtra	 = 0;
	wc.cbWndExtra	 = 0;
	wc.hInstance	 = hInstance;
	wc.hIcon		 = LoadIcon(NULL, IDI_ASTERISK);
	wc.hCursor		 = LoadCursor(NULL, IDC_CROSS);
	wc.hbrBackground = (HBRUSH) (COLOR_APPWORKSPACE-1);
	wc.lpszMenuName	 = NULL;
	wc.lpszClassName = szClassName;
	return RegisterClass(&wc);
}
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;
	hWnd = CreateWindow(
		szClassName,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		0,
		0,
		1366,
		728,
		NULL,
		NULL,
		hInstance,
		NULL);

	if(!hWnd)
		return (FALSE);

	CreateWindow("button", "Рандом!", WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,
		1200, 10, 140, 40, hWnd, (HMENU)ID_COUNT1, hInstance, NULL);
	CreateWindow("button", "Рандом 5!", WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,
		1200, 50, 140, 40, hWnd, (HMENU)ID_COUNT2, hInstance, NULL);
	CreateWindow("button", "Рандом 200!", WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,
		1200, 90, 140, 40, hWnd, (HMENU)ID_COUNT3, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	return (TRUE);
}

int NUMBER = 0;
int X[10000], Y[10000];
int Z[10000], num = 0;

void Jarvis()
{
	// находим самую левую из самых нижних
	int base = 0;
	num = 0;
	for (int i = 1; i < NUMBER; i++)
	{
		if (Y[i] < Y[base])
			base = i;
		else
			if (Y[i] == Y[base] && X[i] < X[base])
				base = i;
	}
	Z[num++] = base;
	int first = base;
	int cur = base;
	//1) p[1] = самая левая нижняя точка множества P;
	//2) i = 1;
	//3) do:
	//p[i+1] = любая точка из P (кроме уже попавших в выпуклую оболочку, но включая p[1]);
	//(a)for (для каждой точки j из P, кроме уже попавших в выпуклую оболочку, но включая p[1])
	//	p[i+1] = min_polar_angle(p[i+1], P[j]); // минимум через векторное произведение, как описано выше
	//(b)i = i + 1;
	//while p[i] != p[1]
	//4) return p;
	do
	{ 
		int next = (cur + 1) % NUMBER;
		for (int i = 0; i < NUMBER; i++)
		{
			int sign = X[cur] * (Y[next] - Y[i]) + X[next] * (Y[i] - Y[cur]) + X[i] * (Y[cur] - Y[next]);
			// точка mas[i] находится левее прямой ( mas[cur], mas[next] )
			if (sign < 0) // обход выпуклой оболочки против часовой стрелки
				next = i;
			// точка лежит на прямой, образованной точками mas[cur], mas[next]
			else if (sign == 0)
			{
				// точка mas[i] находится дальше, чем mas[next] от точки mas[cur]
				if (( X[cur] <= X[next] && X[next] <= X[i] && Y[cur] <= Y[next] && Y[next] <= Y[i]))
					next = i;
			}
		}
		cur = next;
		Z[num++] = next;
	}
	while (cur != first);
}
int rand1;
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC         hdc ;
	PAINTSTRUCT ps;
	RECT        rect ;
	static HPEN        hPen;
	static HBRUSH      hBrush1, hBrush2;
	switch (message)
	{
	case WM_CREATE:
		hPen = CreatePen(PS_SOLID, 10, RGB(245, 222, 179));
		hBrush1 = CreateSolidBrush(RGB(225, 25, 0));
		hBrush2 = CreateSolidBrush(RGB(0, 0, 0));
		srand(time(NULL));
		break;
	case WM_COMMAND:
		switch(LOWORD(wParam)) 
		{
		case ID_COUNT1:
			rand1 = rand();
			X[NUMBER] = (rand1 % 1366);
			Y[NUMBER] = (rand1 % 700);
			NUMBER ++;
			Jarvis();
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		case ID_COUNT2:
			for (int i = 0; i < 5; i++)
			{
				rand1 = rand();
				X[NUMBER] = (rand1 % 1360);
				Y[NUMBER] = (rand1 % 700);
				NUMBER ++;
			}
			Jarvis();
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		case ID_COUNT3:
			for (int i = 0; i < 200; i++)
			{
				rand1 = rand();
				X[NUMBER] = (rand1 % 1366);
				Y[NUMBER] = (rand1 % 700);
				NUMBER ++;
			}
			Jarvis();
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		};
		break;
	case WM_PAINT :
		hdc = BeginPaint (hwnd, &ps);
		for (int i = 0; i < NUMBER; i++)
		{
			SelectObject(hdc, hBrush2);
			Ellipse(hdc, X[i] - 10, Y[i] - 10, X[i] + 10, Y[i] + 10);
			SelectObject(hdc, hBrush1);
			Ellipse(hdc, X[i] - 5, Y[i] - 5, X[i] + 5, Y[i] + 5);
		}
		for (int i = 0; i < num - 1; i++)
		{
			SelectObject(hdc, hPen);
			MoveToEx(hdc, X[Z[i]], Y[Z[i]], NULL);
			LineTo(hdc, X[Z[i + 1]], Y[Z[i + 1]]);
		}
		EndPaint (hwnd, &ps) ;
		break;
	case WM_LBUTTONDOWN :
		X[NUMBER] = LOWORD(lParam);
		Y[NUMBER] = HIWORD(lParam);
		NUMBER++;
		InvalidateRect(hwnd, NULL, TRUE);
		break;
	case WM_LBUTTONUP :
		Jarvis();
		InvalidateRect(hwnd, NULL, TRUE);
		break;
	case WM_DESTROY:
		DeleteObject(hPen);
		DeleteObject(hBrush1);
		DeleteObject(hBrush2);
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}