#include <windows.h>
#include <ctime>
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL InitApplication(HINSTANCE  hInstance);
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);

LPCSTR szClassName = "WinAPI";
LPCSTR szTitle =	 "Тетрис";

void NewGame(HWND hwnd);

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
	HBRUSH brush = CreateSolidBrush(RGB(122,2,2));
	WNDCLASS wc;
	wc.style		 = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc	 = (WNDPROC)WndProc;
	wc.cbClsExtra	 = 0;
	wc.cbWndExtra	 = 0;
	wc.hInstance	 = hInstance;
	wc.hIcon		 = LoadIcon(NULL, IDI_ASTERISK);
	wc.hCursor		 = LoadCursor(NULL, IDC_CROSS);
	wc.hbrBackground = /*brush;/*/(HBRUSH) (COLOR_APPWORKSPACE-1);
	wc.lpszMenuName	 = NULL;
	wc.lpszClassName = szClassName;
	return RegisterClass(&wc);
}
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;
	hWnd = CreateWindow( szClassName,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		200,
		0,
		250 + 17 + 150,
		500 + 39 + 25,
		NULL,
		NULL,
		hInstance,
		NULL);

	if(!hWnd)
		return (FALSE);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	return (TRUE);
}



char SCORE[5] = "0", LINES[5] = "0";
int TETR[21][11], MOVE = 0, KEY = 0, X = -1, Y = -1, Score = 0, OBJECT = 0, OBJNEXT = 0, count = 0, count2 = 0, Start = 0, Lines = 0;

void LineReduce(HWND hwnd)
{
	int sz = 0;
	for (int i = 19; i >= 0; i--)
	{
		for (int j = 9; j >= 0; j--)
		{
			if (TETR[i][j] > 0) sz++;
		}
		if (sz == 10)
		{
			for (int z = i; z > 0; z--)
				for (int q = 0; q < 10; q++)
				{
					TETR[z][q] = TETR[z - 1][q]; 
				};
			count2++;
			if (count < 150)
				count += 5;
			LineReduce(hwnd);
		}
		switch (count2)
		{
		case 1:
			Score += 100;
			break;
		case 2:
			Score += 250;
			break;
		case 3:
			Score += 500;
			break;
		case 4:
			Score += 1500;
			break;
		}
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 10; j++)
				if (TETR[i][j] > 0) 
					NewGame(hwnd);
		Lines += count2;
		_itoa(Lines, LINES, 10);
		count2 = 0;
		_itoa(Score, SCORE, 10);
		SetTimer(hwnd, 1, 350 - count, NULL);
		sz = 0;
	}
}

void Next(HDC hdc, HBRUSH *hBrush)
{
	SetBkMode(hdc, 20);
	TextOut(hdc, 25*12, 10, "Androsik©", 9);
	TextOut(hdc, 25*11, 30, "Next:", 5);
	//Rectangle(hdc, 275, 50, 375, 150);
	MoveToEx(hdc, 25 * 11, 50, NULL);    // 275, 50
	LineTo(hdc, 25 * 11, 150);
	MoveToEx(hdc, 25 * 15, 50, NULL);
	LineTo(hdc, 25 * 15, 150);
	MoveToEx(hdc, 25 * 11, 50, NULL);
	LineTo(hdc, 25 * 15, 50);
	MoveToEx(hdc, 25 * 11, 150, NULL); 
	LineTo(hdc, 25 * 15, 150);           // 375, 150

	TextOut(hdc, 25*11, 160, "Score:", 6);
	TextOut(hdc, 25*13, 160, SCORE, strlen(SCORE));

	TextOut(hdc, 25*11, 180, "Lines:", 6);
	TextOut(hdc, 25*13, 180, LINES, strlen(LINES));

	Rectangle(hdc, 275, 450, 375, 475);
	TextOut(hdc, 288, 454, "    START", 9);
	if (Start && OBJECT)
	{
		switch (OBJNEXT)
		{
		case 1:
			SelectObject(hdc, hBrush[8]);
			Rectangle(hdc, 300, 75, 325, 100);
			break;
		case 2:
			SelectObject(hdc, hBrush[1]);
			Rectangle(hdc, 300, 75, 300 + 25, 75 + 25);
			Rectangle(hdc, 300 + 25, 75, 300 + 50, 75 + 25);
			Rectangle(hdc, 300 + 25, 75 + 25, 300 + 50, 75 + 50);
			Rectangle(hdc, 300 , 75 + 25, 300 + 25, 75 + 50);
			break;
		case 3:
			SelectObject(hdc, hBrush[5]);
			Rectangle(hdc, 300, 50, 325, 75);
			Rectangle(hdc, 325, 50, 350, 75);
			Rectangle(hdc, 300, 75, 325, 100);
			Rectangle(hdc, 300, 100, 325, 125);
			break;
		case 4:
			SelectObject(hdc, hBrush[2]);
			Rectangle(hdc, 300, 50     , 300 + 25, 50 + 25);
			Rectangle(hdc, 300, 50 + 25, 300 + 25, 50 + 50);
			Rectangle(hdc, 300, 50 + 50, 300 + 25, 50 + 75);
			Rectangle(hdc, 300, 50 + 75, 300 + 25, 50 + 100);
			break;
		case 5:
			SelectObject(hdc, hBrush[6]);
			Rectangle(hdc, 300, 50, 300 + 25, 50 + 25);
			Rectangle(hdc, 300 + 25, 50, 300 + 50, 50 + 25);
			Rectangle(hdc, 300 + 25, 50 + 25, 300 + 50, 50 + 50);
			Rectangle(hdc, 300 + 25, 50 + 50, 300 + 50, 50 + 75);
			break;
		case 6:
			SelectObject(hdc, hBrush[3]);
			Rectangle(hdc, 300, 50, 300 + 25, 50 + 25);
			Rectangle(hdc, 300, 50 + 25, 300 + 25, 50 + 50);
			Rectangle(hdc, 300 + 25, 50 + 25, 300 + 50, 50 + 50);
			Rectangle(hdc, 300 + 25, 50 + 50, 300 + 50, 50 + 75);
			break;
		case 7:
			SelectObject(hdc, hBrush[4]);
			Rectangle(hdc, 300 + 25, 50, 300 + 50, 50 + 25);
			Rectangle(hdc, 300 + 25, 50 + 25, 300 + 50, 50 + 50);
			Rectangle(hdc, 300, 50 + 25, 300 + 25, 50 + 50);
			Rectangle(hdc, 300, 50 + 50, 300 + 25, 50 + 75);
			break;
		case 8:
			SelectObject(hdc, hBrush[2]);
			Rectangle(hdc, 275, 75, 275 + 25, 75 + 25);
			Rectangle(hdc, 275 + 25, 75, 275 + 50, 75 + 25);
			Rectangle(hdc, 275 + 50, 75, 275 + 75, 75 + 25);
			Rectangle(hdc, 275 + 75, 75, 275 + 100, 75 + 25);
			break;
		case 9:
			SelectObject(hdc, hBrush[3]);
			Rectangle(hdc, 275, 75 + 25, 275 + 25, 75 + 50);
			Rectangle(hdc, 275 + 25, 75, 275 + 50, 75 + 25);
			Rectangle(hdc, 275 + 25, 75 + 25, 275 + 50, 75 + 50);
			Rectangle(hdc, 275 + 50, 75, 275 + 75, 75 + 25);
			break;
		case 10:
			SelectObject(hdc, hBrush[4]);
			Rectangle(hdc, 275, 75, 275 + 25, 75 + 25);
			Rectangle(hdc, 275 + 25, 75, 275 + 50, 75 + 25);
			Rectangle(hdc, 275 + 25, 75 + 25, 275 + 50, 75 + 50);
			Rectangle(hdc, 275 + 50, 75 + 25, 275 + 75, 75 + 50);
			break;
		case 11:
			SelectObject(hdc, hBrush[5]);
			Rectangle(hdc, 275, 75, 275 + 25, 75 + 25);
			Rectangle(hdc, 275, 75 + 25, 275 + 25, 75 + 50);
			Rectangle(hdc, 275 + 25, 75 + 25, 275 + 50, 75 + 50);
			Rectangle(hdc, 275 + 50, 75 + 25, 275 + 75, 75 + 50);
			break;
		case 12:
			SelectObject(hdc, hBrush[5]);
			Rectangle(hdc, 275 + 25, 75, 275 + 50, 75 + 25);
			Rectangle(hdc, 275 + 25, 75 + 25, 275 + 50, 75 + 50);
			Rectangle(hdc, 275 + 25, 75 + 50, 275 + 50, 75 + 75);
			Rectangle(hdc, 275, 75 + 50, 275 + 25, 75 + 75);
			break;
		case 13:
			SelectObject(hdc, hBrush[5]);
			Rectangle(hdc, 275, 75, 275 + 25, 75 + 25);
			Rectangle(hdc, 275 + 25, 75, 275 + 50, 75 + 25);
			Rectangle(hdc, 275 + 50, 75, 275 + 75, 75 + 25);
			Rectangle(hdc, 275 + 50, 75 + 25, 275 + 75, 75 + 50);
			break;		
		case 14:
			SelectObject(hdc, hBrush[6]);
			Rectangle(hdc, 275, 75, 275 + 25, 75 + 25);                        // ###
			Rectangle(hdc, 275, 75 + 25, 275 + 25, 75 + 50);                   // #
			Rectangle(hdc, 275 + 25, 75, 275 + 50, 75 + 25);
			Rectangle(hdc, 275 + 50, 75, 275 + 75, 75 + 25);
			break;
		case 15:
			SelectObject(hdc, hBrush[6]);
			Rectangle(hdc, 275, 75, 275 + 25, 75 + 25);                        // #
			Rectangle(hdc, 275, 75 + 25, 275 + 25, 75 + 50);                   // #
			Rectangle(hdc, 275 + 25, 75 + 50, 275 + 50, 75 + 75);              // ##
			Rectangle(hdc, 275, 75 + 50, 275 + 25, 75 + 75);
			break;
		case 16:
			SelectObject(hdc, hBrush[6]);
			Rectangle(hdc, 275, 75 + 25, 275 + 25, 75 + 50);                   //   #
			Rectangle(hdc, 275 + 25, 75 + 25, 275 + 50, 75 + 50);              // ###
			Rectangle(hdc, 275 + 50, 75 + 25, 275 + 75, 75 + 50);
			Rectangle(hdc, 275 + 50, 75, 275 + 75, 75 + 25);
			break;
		case 17:
			SelectObject(hdc, hBrush[7]);
			Rectangle(hdc, 275, 75, 275 + 25, 75 + 25);                        // #
			Rectangle(hdc, 275, 75 + 25, 275 + 25, 75 + 50);                   // ##
			Rectangle(hdc, 275, 75 + 50, 275 + 25, 75 + 75);                   // #
			Rectangle(hdc, 275 + 25, 75 + 25, 275 + 50, 75 + 50);
			break;
		case 18:
			SelectObject(hdc, hBrush[7]);
			Rectangle(hdc, 275 + 13 + 25, 75, 275 + 13 + 50, 75 + 25);                   //  #
			Rectangle(hdc, 275 + 13, 75 + 25, 275 + 13 + 25, 75 + 50);                   // ###
			Rectangle(hdc, 275 + 13 + 25, 75 + 25, 275 + 13 + 50, 75 + 50);
			Rectangle(hdc, 275 + 13 + 50, 75 + 25, 275 + 13 + 75, 75 + 50);
			break;
		case 19:
			SelectObject(hdc, hBrush[7]);
			Rectangle(hdc, 300 + 25, 50 + 13, 300 + 50, 50 + 13 + 25);                   //  #
			Rectangle(hdc, 300, 50 + 13 + 25, 300 + 25, 50 + 13 + 50);                   // ##
			Rectangle(hdc, 300 + 25, 50 + 13 + 25, 300 + 50, 50 + 13 + 50);              //  #
			Rectangle(hdc, 300 + 25, 50 + 13 + 50, 300 + 50, 50 + 13 + 75);
			break;
		case 20:
			SelectObject(hdc, hBrush[7]);
			Rectangle(hdc, 275 + 13, 75, 275 + 13 + 25, 75 + 25);                        // ###
			Rectangle(hdc, 275 + 13 + 25, 75, 275 + 13 + 50, 75 + 25);                   //  #
			Rectangle(hdc, 275 + 13 + 50, 75, 275 + 13 + 75, 75 + 25);
			Rectangle(hdc, 275 + 13 + 25, 75 + 25, 275 + 13 + 50, 75 + 50);
			break;
		}
	}
}

void Pole(HDC hdc)
{
	for (int i = 0; i < 11; i++)
	{
		MoveToEx(hdc, 25 * i, 0, NULL);
		LineTo(hdc, 25 * i , 500);
	}
	for (int i = 0; i < 21; i++)
	{
		MoveToEx(hdc, 0, 25 * i, NULL);
		LineTo(hdc, 250, 25 * i);
	}
}


void DrawPole(HDC hdc, HBRUSH *hBrush)
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (TETR[i][j] > 0)
			{
				SelectObject(hdc, hBrush[TETR[i][j]]);
				Rectangle(hdc, j * 25+1, i * 25+1, j * 25 + 25-1 , i * 25 +25-1);
			}

		}
	}
}
void DrawObject(HDC hdc, HBRUSH *hBrush)
{
	switch (OBJECT)
	{
	case 1:
		SelectObject(hdc, hBrush[8]);
		Rectangle(hdc, X, Y, X + 25, Y + 25);
		break;
	case 2:
		SelectObject(hdc, hBrush[1]);
		Rectangle(hdc, X, Y, X + 25, Y + 25);
		Rectangle(hdc, X + 25, Y, X + 50, Y + 25);
		Rectangle(hdc, X + 25, Y+ 25, X + 50, Y + 50);
		Rectangle(hdc, X , Y + 25, X + 25, Y + 50);
		break;
	case 3:
		SelectObject(hdc, hBrush[5]);
		Rectangle(hdc, X, Y, X + 25, Y + 25);
		Rectangle(hdc, X + 25, Y, X + 50, Y + 25);
		Rectangle(hdc, X, Y + 25, X + 25, Y + 50);
		Rectangle(hdc, X, Y + 50, X + 25, Y + 75);
		break;
	case 4:
		SelectObject(hdc, hBrush[2]);
		Rectangle(hdc, X, Y     , X + 25, Y + 25);
		Rectangle(hdc, X, Y + 25, X + 25, Y + 50);
		Rectangle(hdc, X, Y + 50, X + 25, Y + 75);
		Rectangle(hdc, X, Y + 75, X + 25, Y + 100);
		break;
	case 5:
		SelectObject(hdc, hBrush[6]);
		Rectangle(hdc, X, Y, X + 25, Y + 25);
		Rectangle(hdc, X + 25, Y, X + 50, Y + 25);
		Rectangle(hdc, X + 25, Y + 25, X + 50, Y + 50);
		Rectangle(hdc, X + 25, Y + 50, X + 50, Y + 75);
		break;
	case 6:
		SelectObject(hdc, hBrush[3]);
		Rectangle(hdc, X, Y, X + 25, Y + 25);
		Rectangle(hdc, X, Y + 25, X + 25, Y + 50);
		Rectangle(hdc, X + 25, Y + 25, X + 50, Y + 50);
		Rectangle(hdc, X + 25, Y + 50, X + 50, Y + 75);
		break;
	case 7:
		SelectObject(hdc, hBrush[4]);
		Rectangle(hdc, X + 25, Y, X + 50, Y + 25);
		Rectangle(hdc, X + 25, Y + 25, X + 50, Y + 50);
		Rectangle(hdc, X, Y + 25, X + 25, Y + 50);
		Rectangle(hdc, X, Y + 50, X + 25, Y + 75);
		break;
	case 8:
		SelectObject(hdc, hBrush[2]);
		Rectangle(hdc, X, Y, X + 25, Y + 25);
		Rectangle(hdc, X + 25, Y, X + 50, Y + 25);
		Rectangle(hdc, X + 50, Y, X + 75, Y + 25);
		Rectangle(hdc, X + 75, Y, X + 100, Y + 25);
		break;
	case 9:
		SelectObject(hdc, hBrush[3]);
		Rectangle(hdc, X, Y + 25, X + 25, Y + 50);
		Rectangle(hdc, X + 25, Y, X + 50, Y + 25);
		Rectangle(hdc, X + 25, Y + 25, X + 50, Y + 50);
		Rectangle(hdc, X + 50, Y, X + 75, Y + 25);
		break;
	case 10:
		SelectObject(hdc, hBrush[4]);
		Rectangle(hdc, X, Y, X + 25, Y + 25);
		Rectangle(hdc, X + 25, Y, X + 50, Y + 25);
		Rectangle(hdc, X + 25, Y + 25, X + 50, Y + 50);
		Rectangle(hdc, X + 50, Y + 25, X + 75, Y + 50);
		break;
	case 11:
		SelectObject(hdc, hBrush[5]);
		Rectangle(hdc, X, Y, X + 25, Y + 25);
		Rectangle(hdc, X, Y + 25, X + 25, Y + 50);
		Rectangle(hdc, X + 25, Y + 25, X + 50, Y + 50);
		Rectangle(hdc, X + 50, Y + 25, X + 75, Y + 50);
		break;
	case 12:
		SelectObject(hdc, hBrush[5]);
		Rectangle(hdc, X + 25, Y, X + 50, Y + 25);
		Rectangle(hdc, X + 25, Y + 25, X + 50, Y + 50);
		Rectangle(hdc, X + 25, Y + 50, X + 50, Y + 75);
		Rectangle(hdc, X, Y + 50, X + 25, Y + 75);
		break;
	case 13:
		SelectObject(hdc, hBrush[5]);
		Rectangle(hdc, X, Y, X + 25, Y + 25);
		Rectangle(hdc, X + 25, Y, X + 50, Y + 25);
		Rectangle(hdc, X + 50, Y, X + 75, Y + 25);
		Rectangle(hdc, X + 50, Y + 25, X + 75, Y + 50);
		break;
	case 14:
		SelectObject(hdc, hBrush[6]);
		Rectangle(hdc, X, Y, X + 25, Y + 25);                        // ###
		Rectangle(hdc, X, Y + 25, X + 25, Y + 50);                   // #
		Rectangle(hdc, X + 25, Y, X + 50, Y + 25);
		Rectangle(hdc, X + 50, Y, X + 75, Y + 25);
		break;
	case 15:
		SelectObject(hdc, hBrush[6]);
		Rectangle(hdc, X, Y, X + 25, Y + 25);                        // #
		Rectangle(hdc, X, Y + 25, X + 25, Y + 50);                   // #
		Rectangle(hdc, X + 25, Y + 50, X + 50, Y + 75);              // ##
		Rectangle(hdc, X, Y + 50, X + 25, Y + 75);
		break;
	case 16:
		SelectObject(hdc, hBrush[6]);
		Rectangle(hdc, X, Y + 25, X + 25, Y + 50);                   //   #
		Rectangle(hdc, X + 25, Y + 25, X + 50, Y + 50);              // ###
		Rectangle(hdc, X + 50, Y + 25, X + 75, Y + 50);
		Rectangle(hdc, X + 50, Y, X + 75, Y + 25);
		break;
	case 17:
		SelectObject(hdc, hBrush[7]);
		Rectangle(hdc, X, Y, X + 25, Y + 25);                        // #
		Rectangle(hdc, X, Y + 25, X + 25, Y + 50);                   // ##
		Rectangle(hdc, X, Y + 50, X + 25, Y + 75);                   // #
		Rectangle(hdc, X + 25, Y + 25, X + 50, Y + 50);
		break;
	case 18:
		SelectObject(hdc, hBrush[7]);
		Rectangle(hdc, X + 25, Y, X + 50, Y + 25);                   //  #
		Rectangle(hdc, X, Y + 25, X + 25, Y + 50);                   // ###
		Rectangle(hdc, X + 25, Y + 25, X + 50, Y + 50);
		Rectangle(hdc, X + 50, Y + 25, X + 75, Y + 50);
		break;
	case 19:
		SelectObject(hdc, hBrush[7]);
		Rectangle(hdc, X + 25, Y, X + 50, Y + 25);                   //  #
		Rectangle(hdc, X, Y + 25, X + 25, Y + 50);                   // ##
		Rectangle(hdc, X + 25, Y + 25, X + 50, Y + 50);              //  #
		Rectangle(hdc, X + 25, Y + 50, X + 50, Y + 75);
		break;
	case 20:
		SelectObject(hdc, hBrush[7]);
		Rectangle(hdc, X, Y, X + 25, Y + 25);                        // ###
		Rectangle(hdc, X + 25, Y, X + 50, Y + 25);                   //  #
		Rectangle(hdc, X + 50, Y, X + 75, Y + 25);
		Rectangle(hdc, X + 25, Y + 25, X + 50, Y + 50);
		break;
	}
}
void NewGame(HWND hwnd)
{
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 10; j++)
			TETR[i][j] = 0;
	Score = 0;
	OBJECT = 0;
	OBJNEXT = 0;
	Lines = 0;
	Start = 1;
	SetTimer(hwnd, 1, 350, NULL);
	SetWindowText(hwnd, "NEW GAME");
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT    ps;
	HDC            hdc;
	static HBRUSH  hBrush[10];
	switch(message)
	{
	case WM_CREATE:
		hBrush[8] = CreateSolidBrush(RGB(255, 215, 0));    // Точка                     +
		hBrush[1] = CreateSolidBrush(RGB(255, 255, 0));    // Квадрат                   +
		hBrush[2] = CreateSolidBrush(RGB(255, 140, 0));    // Палка                     +-
		hBrush[3] = CreateSolidBrush(RGB(0, 128, 0));      // Z                         +-
		hBrush[4] = CreateSolidBrush(RGB(139, 0, 0));      // Z наоборот                +-
		hBrush[5] = CreateSolidBrush(RGB(0, 0, 128));      // Г                         +-
		hBrush[6] = CreateSolidBrush(RGB(0, 255, 255));    // Г наоборот                +-
		hBrush[7] = CreateSolidBrush(RGB(148, 0, 211));    // Т                         +-
		SetTimer(hwnd, 1, 250, NULL);
		srand((unsigned int)time(0));
		OBJNEXT = ((rand() % 8)) + 1;

		for (int i = 0; i < 20; i++)
			for (int j = 0; j < 10; j++)
				TETR[i][j] = 0;
		for (int j = 0; j < 10; j++)
			TETR[20][j] = 1;
		for (int j = 0; j < 20; j++)
			TETR[j][10] = 1;

		break;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		Pole(hdc);
		Next(hdc, hBrush);
		DrawPole(hdc, hBrush);
		DrawObject(hdc, hBrush);
		EndPaint(hwnd, &ps);
		break;

	case WM_TIMER:
		if (Start)
		{
			switch (OBJECT)
			{
			case 0:
				OBJECT = OBJNEXT;
				OBJNEXT = (rand() % 20) + 1;
				Y = 0;
				if (OBJECT == 1 || OBJECT == 4)
					X = (rand() % 10) * 25;
				if (OBJECT == 2 || OBJECT == 3 || OBJECT == 5 || OBJECT == 6 || OBJECT == 7 || OBJECT == 12 || OBJECT == 15|| OBJECT == 17 || OBJECT == 19)
					X = (rand() % 9) * 25;
				if (OBJECT == 9 || OBJECT == 10 || OBJECT == 11 || OBJECT == 13 || OBJECT == 14 || OBJECT == 18 || OBJECT == 20)
					X = (rand() % 8) * 25;
				if (OBJECT == 8)
					X = (rand() % 7) * 25;
				InvalidateRect(hwnd, NULL, TRUE);
				break;
			case 1:                                              
				MOVE = 1;
				if (TETR[Y / 25 + 1][X / 25] > 0)
				{
					TETR[Y / 25][X / 25] = 8;                 // #
					LineReduce(hwnd);
					if (Score)
						SetWindowText(hwnd, SCORE);
					OBJECT = 0;
				}
				Y += 25;
				InvalidateRect(hwnd, NULL, TRUE);
				break;
			case 2:                                                                          
				MOVE = 2;
				if ((TETR[Y / 25 + 2][X / 25] > 0) || (TETR[Y / 25 + 2][X / 25 + 1] > 0))
				{
					TETR[Y / 25][X / 25] = 1;                               // ##
					TETR[Y / 25][X / 25 + 1] = 1;                           // ##
					TETR[Y / 25 + 1][X / 25] = 1;
					TETR[Y / 25 + 1][X / 25 + 1] = 1;
					LineReduce(hwnd);
					if (Score)
						SetWindowText(hwnd, SCORE);
					Y = -1;
					OBJECT = 0;
				}
				Y += 25;
				InvalidateRect(hwnd, NULL, TRUE);
				break;
			case 3:                                                                    
				MOVE = 3;
				if ((TETR[Y / 25 + 3][X / 25] > 0) || (TETR[Y / 25 + 1][X / 25 + 1] > 0))
				{
					TETR[Y / 25][X / 25]     = 5;                   // ##
					TETR[Y / 25][X / 25 + 1] = 5;                   // #
					TETR[Y / 25 + 1][X / 25] = 5;                   // #
					TETR[Y / 25 + 2][X / 25] = 5;
					LineReduce(hwnd);
					if (Score)
						SetWindowText(hwnd, SCORE);
					OBJECT = 0;
				}
				Y += 25;
				InvalidateRect(hwnd, NULL, TRUE);
				break;
			case 11:
				MOVE = 11;
				if ((TETR[Y / 25 + 2][X / 25] > 0) || (TETR[Y / 25 + 2][X / 25 + 1] > 0) || (TETR[Y / 25 + 2][X / 25 + 2] > 0))
				{
					TETR[Y / 25][X / 25]     = 5;                   // #
					TETR[Y / 25 + 1][X / 25] = 5;                   // ###
					TETR[Y / 25 + 1][X / 25 + 1] = 5;
					TETR[Y / 25 + 1][X / 25 + 2] = 5;
					LineReduce(hwnd);
					if (Score)
						SetWindowText(hwnd, SCORE);
					OBJECT = 0;
				}
				Y += 25;
				InvalidateRect(hwnd, NULL, TRUE);
				break;
			case 12:
				MOVE = 12;
				if ((TETR[Y / 25 + 3][X / 25] > 0) || (TETR[Y / 25 + 3][X / 25 + 1] > 0))
				{
					TETR[Y / 25    ][X / 25 + 1] = 5;             //  #
					TETR[Y / 25 + 1][X / 25 + 1] = 5;             //  #
					TETR[Y / 25 + 2][X / 25 + 1] = 5;             // ##
					TETR[Y / 25 + 2][X / 25    ] = 5;
					LineReduce(hwnd);
					if (Score)
						SetWindowText(hwnd, SCORE);
					OBJECT = 0;
				}
				Y += 25;
				InvalidateRect(hwnd, NULL, TRUE);
				break;
			case 13:
				MOVE = 13;
				if ((TETR[Y / 25 + 1][X / 25] > 0) || (TETR[Y / 25 + 1][X / 25 + 1] > 0) || (TETR[Y / 25 + 2][X / 25 + 2] > 0))
				{
					TETR[Y / 25    ][X / 25    ] = 5;             // ###
					TETR[Y / 25    ][X / 25 + 1] = 5;             //   #
					TETR[Y / 25    ][X / 25 + 2] = 5;
					TETR[Y / 25 + 1][X / 25 + 2] = 5;
					LineReduce(hwnd);
					if (Score)
						SetWindowText(hwnd, SCORE);
					OBJECT = 0;
				}
				Y += 25;
				InvalidateRect(hwnd, NULL, TRUE);
				break;
			case 4:       
				MOVE = 4;                          
				if ((TETR[Y / 25 + 4][X / 25] > 0)) 
				{
					TETR[Y / 25    ][X / 25] = 2;              // #
					TETR[Y / 25 + 1][X / 25] = 2;              // #
					TETR[Y / 25 + 2][X / 25] = 2;              // #
					TETR[Y / 25 + 3][X / 25] = 2;              // #
					LineReduce(hwnd);
					if (Score)
						SetWindowText(hwnd, SCORE);
					OBJECT = 0;
				}
				Y += 25;
				InvalidateRect(hwnd, NULL, TRUE);
				break;
			case 8:                                 
				MOVE = 8;                                         
				if ((TETR[Y / 25 + 1][X / 25] > 0) ||
					(TETR[Y / 25 + 1][X / 25 + 1] > 0) ||
					(TETR[Y / 25 + 1][X / 25 + 2] > 0) ||
					(TETR[Y / 25 + 1][X / 25 + 3] > 0))
				{
					TETR[Y / 25][X / 25] = 2;               // ####
					TETR[Y / 25][X / 25 + 1] = 2;
					TETR[Y / 25][X / 25 + 2] = 2;
					TETR[Y / 25][X / 25 + 3] = 2;
					LineReduce(hwnd);
					if (Score)
						SetWindowText(hwnd, SCORE);
					OBJECT = 0;
				}
				Y += 25;
				InvalidateRect(hwnd, NULL, TRUE);
				break;
			case 5:
				MOVE = 5;
				if ((TETR[Y / 25 + 3][X / 25 + 1] > 0) || (TETR[Y / 25 + 1][X / 25] > 0))
				{
					TETR[Y / 25][X / 25]     = 6;                       // ##
					TETR[Y / 25][X / 25 + 1] = 6;                       //  #
					TETR[Y / 25 + 1][X / 25 + 1] = 6;                   //  #
					TETR[Y / 25 + 2][X / 25 + 1] = 6;
					LineReduce(hwnd);
					if (Score)
						SetWindowText(hwnd, SCORE);
					OBJECT = 0;
				}
				Y += 25;
				InvalidateRect(hwnd, NULL, TRUE);
				break;
			case 14:
				MOVE = 14;
				if ((TETR[Y / 25 + 2][X / 25] > 0) || (TETR[Y / 25 + 1][X / 25 + 1] > 0) || (TETR[Y / 25 + 1][X / 25 + 2] > 0))
				{
					TETR[Y / 25][X / 25]     = 6;                       // ###
					TETR[Y / 25 + 1][X / 25] = 6;                       // #
					TETR[Y / 25][X / 25 + 1] = 6;
					TETR[Y / 25][X / 25 + 2] = 6;
					LineReduce(hwnd);
					if (Score)
						SetWindowText(hwnd, SCORE);
					OBJECT = 0;
				}
				Y += 25;
				InvalidateRect(hwnd, NULL, TRUE);
				break;
			case 15:
				MOVE = 15;
				if ((TETR[Y / 25 + 3][X / 25] > 0) || (TETR[Y / 25 + 3][X / 25 + 1] > 0))
				{
					TETR[Y / 25    ][X / 25] = 6;                 // #
					TETR[Y / 25 + 1][X / 25] = 6;                 // # 
					TETR[Y / 25 + 2][X / 25] = 6;                 // ## 
					TETR[Y / 25 + 2][X / 25 + 1] = 6;
					LineReduce(hwnd);
					if (Score)
						SetWindowText(hwnd, SCORE);
					OBJECT = 0;
				}
				Y += 25;
				InvalidateRect(hwnd, NULL, TRUE);
				break;
			case 16:
				MOVE = 16;
				if ((TETR[Y / 25 + 2][X / 25] > 0) || (TETR[Y / 25 + 2][X / 25 + 1] > 0) || (TETR[Y / 25 + 2][X / 25 + 2] > 0))
				{
					TETR[Y / 25 + 1][X / 25    ] = 6;            //   #
					TETR[Y / 25 + 1][X / 25 + 1] = 6;            // ###
					TETR[Y / 25 + 1][X / 25 + 2] = 6;
					TETR[Y / 25][X / 25 + 2] = 6;
					LineReduce(hwnd);
					if (Score)
						SetWindowText(hwnd, SCORE);
					OBJECT = 0;
				}
				Y += 25;
				InvalidateRect(hwnd, NULL, TRUE);
				break;
			case 6:
				MOVE = 6;
				if ((TETR[Y / 25 + 3][X / 25 + 1] > 0) || (TETR[Y / 25 + 2][X / 25] > 0))
				{
					TETR[Y / 25][X / 25]     = 3;                         // #
					TETR[Y / 25 + 1][X / 25] = 3;                         // ##
					TETR[Y / 25 + 1][X / 25 + 1] = 3;                     //  #
					TETR[Y / 25 + 2][X / 25 + 1] = 3;
					LineReduce(hwnd);
					if (Score)
						SetWindowText(hwnd, SCORE);
					OBJECT = 0;
				}
				Y += 25;
				InvalidateRect(hwnd, NULL, TRUE);
				break;
			case 9:
				MOVE = 9;
				if ((TETR[Y / 25 + 2][X / 25] > 0) || (TETR[Y / 25 + 2][X / 25 + 1] > 0) || (TETR[Y / 25 + 1][X / 25 + 2] > 0))
				{
					TETR[Y / 25 + 1][X / 25]     = 3;                    //  ##
					TETR[Y / 25][X / 25 + 1] = 3;                        // ##
					TETR[Y / 25 + 1][X / 25 + 1] = 3;
					TETR[Y / 25][X / 25 + 2] = 3;
					LineReduce(hwnd);
					if (Score)
						SetWindowText(hwnd, SCORE);
					OBJECT = 0;
				}
				Y += 25;
				InvalidateRect(hwnd, NULL, TRUE);
				break;
			case 7:
				MOVE = 7;
				if ((TETR[Y / 25 + 3][X / 25] > 0) || (TETR[Y / 25 + 2][X / 25 + 1] > 0))
				{
					TETR[Y / 25][X / 25 + 1]     = 4;                    //  #
					TETR[Y / 25 + 1][X / 25 + 1] = 4;                    // ##
					TETR[Y / 25 + 1][X / 25] = 4;                        // #
					TETR[Y / 25 + 2][X / 25] = 4;
					LineReduce(hwnd);
					if (Score)
						SetWindowText(hwnd, SCORE);
					OBJECT = 0;
				}
				Y += 25;
				InvalidateRect(hwnd, NULL, TRUE);
				break;
			case 10:                  
				MOVE = 10;
				if ((TETR[Y / 25 + 1][X / 25] > 0) || (TETR[Y / 25 + 2][X / 25 + 1] > 0) || (TETR[Y / 25 + 2][X / 25 + 2] > 0))
				{
					TETR[Y / 25][X / 25]     = 4;                        // ##
					TETR[Y / 25][X / 25 + 1] = 4;                        //  ##
					TETR[Y / 25 + 1][X / 25 + 1] = 4;
					TETR[Y / 25 + 1][X / 25 + 2] = 4;
					LineReduce(hwnd);
					if (Score)
						SetWindowText(hwnd, SCORE);
					OBJECT = 0;
				}
				Y += 25;
				InvalidateRect(hwnd, NULL, TRUE);
				break;
			case 17:
				MOVE = 17;
				if ((TETR[Y / 25 + 3][X / 25] > 0) || (TETR[Y / 25 + 2][X / 25 + 1] > 0))
				{
					TETR[Y / 25][X / 25]     = 7;                        // # 
					TETR[Y / 25 + 1][X / 25 + 1] = 7;                    // ##
					TETR[Y / 25 + 1][X / 25] = 7;                        // #
					TETR[Y / 25 + 2][X / 25] = 7;
					LineReduce(hwnd);
					if (Score)
						SetWindowText(hwnd, SCORE);
					OBJECT = 0;
				}
				Y += 25;
				InvalidateRect(hwnd, NULL, TRUE);
				break;
			case 18:                  
				MOVE = 18;
				if ((TETR[Y / 25 + 2][X / 25] > 0) || (TETR[Y / 25 + 2][X / 25 + 1] > 0) || (TETR[Y / 25 + 2][X / 25 + 2] > 0))
				{
					TETR[Y / 25 + 1][X / 25]     = 7;                    //  #
					TETR[Y / 25][X / 25 + 1] = 7;                        // ###
					TETR[Y / 25 + 1][X / 25 + 1] = 7;
					TETR[Y / 25 + 1][X / 25 + 2] = 7;
					LineReduce(hwnd);
					if (Score)
						SetWindowText(hwnd, SCORE);
					OBJECT = 0;
				}
				Y += 25;
				InvalidateRect(hwnd, NULL, TRUE);
				break;
			case 19:
				MOVE = 19;
				if ((TETR[Y / 25 + 2][X / 25] > 0) || (TETR[Y / 25 + 3][X / 25 + 1] > 0))
				{
					TETR[Y / 25][X / 25 + 1]     = 7;                    //  #
					TETR[Y / 25 + 1][X / 25 + 1] = 7;                    // ##
					TETR[Y / 25 + 1][X / 25] = 7;                        //  #
					TETR[Y / 25 + 2][X / 25 + 1] = 7;
					LineReduce(hwnd);
					if (Score)
						SetWindowText(hwnd, SCORE);
					OBJECT = 0;
				}
				Y += 25;
				InvalidateRect(hwnd, NULL, TRUE);
				break;
			case 20:                  
				MOVE = 20;
				if ((TETR[Y / 25 + 1][X / 25] > 0) || (TETR[Y / 25 + 2][X / 25 + 1] > 0) || (TETR[Y / 25 + 1][X / 25 + 2] > 0))
				{
					TETR[Y / 25][X / 25]     = 7;                        // ###
					TETR[Y / 25][X / 25 + 1] = 7;                        //  #
					TETR[Y / 25 + 1][X / 25 + 1] = 7;
					TETR[Y / 25][X / 25 + 2] = 7;
					LineReduce(hwnd);
					if (Score)
						SetWindowText(hwnd, SCORE);
					OBJECT = 0;
				}
				Y += 25;
				InvalidateRect(hwnd, NULL, TRUE);
				break;
			}
		}
		break;

	case WM_KEYDOWN :
		KEY = wParam;
		if (KEY == VK_SPACE)
		{
			NewGame(hwnd);
		}
		if (KEY == VK_DOWN)
		{
			SetTimer(hwnd, 1, 10, NULL);
		}
		switch (MOVE)
		{
		case 1:
			if (KEY == 37)      // <-
				if ((X != 0) && (TETR[Y / 25][X / 25 - 1]) == 0)
				{
					X -= 25;
					InvalidateRect(hwnd, NULL, TRUE);
				};
			if (KEY == 39) // ->
				if ((TETR[Y / 25][X / 25 + 1]) == 0)
				{
					X += 25;
					InvalidateRect(hwnd, NULL, TRUE);
				}
				break;
		case 2:
			if (KEY == 37)      // <-
				if ((X != 0) && (TETR[Y / 25][X / 25 - 1]) == 0 && (TETR[Y / 25][X / 25 - 1]) == 0 && (TETR[Y / 25 + 1][X / 25 - 1]) == 0)
				{
					X -= 25;
					InvalidateRect(hwnd, NULL, TRUE);
				};
			if (KEY == 39) // ->
				if ((TETR[Y / 25][X / 25 + 2]) == 0 && (TETR[Y / 25][X / 25 + 2]) == 0 && (TETR[Y / 25 + 1][X / 25 + 2]) == 0)
				{
					X += 25;
					InvalidateRect(hwnd, NULL, TRUE);
				}
				break;
		case 3:
			if (KEY == VK_UP)         // ^
			{
				OBJECT = 11;
			}
			if (KEY == 37)      // <-
				if ((X != 0) && (TETR[Y / 25][X / 25 - 1]) == 0 && 
					(TETR[Y / 25 + 1][X / 25 - 1]) == 0 && (TETR[Y / 25 + 2][X / 25 - 1]) == 0)
				{
					X -= 25;
					InvalidateRect(hwnd, NULL, TRUE);
				};
			if (KEY == 39) // ->
				if ((TETR[Y / 25][X / 25 + 2]) == 0 && 
					(TETR[Y / 25 + 1][X / 25 + 1]) == 0 && (TETR[Y / 25 + 2][X / 25 + 1]) == 0)
				{
					X += 25;
					InvalidateRect(hwnd, NULL, TRUE);
				}
				break;
		case 4:
			if (KEY == VK_UP)         // ^
			{
				if (TETR[Y / 25][X / 25 + 1] == 0 && TETR[Y / 25][X / 25 + 2] == 0 && TETR[Y / 25][X / 25 + 3] == 0)
				{
					if ((X == 175 || X == 200 || X == 225) && 
						TETR[Y / 25][8] == 0 && TETR[Y / 25][7] == 0) 
					{
						X = 150;
					}
					//if (TETR[Y / 25][X / 25 + 1] == 0 && TETR[Y / 25][X / 25 + 2] == 0 && TETR[Y / 25][X / 25 + 3] == 0
					OBJECT = 8;
				}
				else
				{
				}
			}
			if (KEY == 37)      // <-
				if ((X != 0) && (TETR[Y / 25][X / 25 - 1]) == 0 && (TETR[Y / 25 + 1][X / 25 - 1]) == 0  && 
					(TETR[Y / 25 + 2][X / 25 - 1]) == 0 && (TETR[Y / 25 + 3][X / 25 - 1]) == 0)
				{
					X -= 25;
					InvalidateRect(hwnd, NULL, TRUE);
				};
			if (KEY == 39) // ->
				if ((TETR[Y / 25][X / 25 + 1]) == 0 && (TETR[Y / 25 + 1][X / 25 + 1]) == 0  && 
					(TETR[Y / 25 + 2][X / 25 + 1]) == 0 && (TETR[Y / 25 + 3][X / 25 + 1]) == 0)
				{
					X += 25;
					InvalidateRect(hwnd, NULL, TRUE);
				}
				break;
		case 5:
			if (KEY == VK_UP)         // ^
			{
				OBJECT = 14;
			}
			if (KEY == 37)      // <-
				if ((X != 0) && (TETR[Y / 25][X / 25 - 1]) == 0 && 
					(TETR[Y / 25 + 1][X / 25]) == 0 && (TETR[Y / 25 + 2][X / 25]) == 0)
				{
					X -= 25;
					InvalidateRect(hwnd, NULL, TRUE);
				};
			if (KEY == 39) // ->
				if ((TETR[Y / 25][X / 25 + 2]) == 0 && 
					(TETR[Y / 25 + 1][X / 25 + 2]) == 0 && (TETR[Y / 25 + 2][X / 25 + 2]) == 0)
				{
					X += 25;
					InvalidateRect(hwnd, NULL, TRUE);
				}
				break;
		case 6:
			if (KEY == VK_UP)         // ^
			{
				if ((X == 200) && TETR[Y / 25 - 1][7] == 0) 
				{
					X = 175;
				}
				OBJECT = 9;
			}
			if (KEY == 37)      // <-
				if ((X != 0) && (TETR[Y / 25][X / 25 - 1]) == 0 && 
					(TETR[Y / 25 + 1][X / 25 - 1]) == 0 && (TETR[Y / 25 + 2][X / 25]) == 0)
				{
					X -= 25;
					InvalidateRect(hwnd, NULL, TRUE);
				};
			if (KEY == 39) // ->
				if ((TETR[Y / 25][X / 25 + 1]) == 0 && 
					(TETR[Y / 25 + 1][X / 25 + 2]) == 0 && (TETR[Y / 25 + 2][X / 25 + 2]) == 0)
				{
					X += 25;
					InvalidateRect(hwnd, NULL, TRUE);
				}
				break;
		case 7:
			if (KEY == VK_UP)         // ^
			{
				OBJECT = 10;
			}
			if (KEY == 37)      // <-
				if ((X != 0) && (TETR[Y / 25][X / 25]) == 0 && 
					(TETR[Y / 25 + 1][X / 25 - 1]) == 0 && (TETR[Y / 25 + 2][X / 25 - 1]) == 0)
				{
					X -= 25;
					InvalidateRect(hwnd, NULL, TRUE);
				};
			if (KEY == 39) // ->
				if ((TETR[Y / 25][X / 25 + 2]) == 0 && 
					(TETR[Y / 25 + 1][X / 25 + 2]) == 0 && (TETR[Y / 25 + 2][X / 25 + 1]) == 0)
				{
					X += 25;
					InvalidateRect(hwnd, NULL, TRUE);
				}
				break;
		case 8:
			if (KEY == VK_UP)
				if (TETR[Y / 25 + 1][X / 25] == 0 && TETR[Y / 25 + 2][X / 25] == 0 && TETR[Y / 25 + 3][X / 25] == 0)
					OBJECT = 4;
			if (KEY == 37)      // <-
				if ((X != 0) && (TETR[Y / 25][X / 25 - 1]) == 0)
				{
					X -= 25;
					InvalidateRect(hwnd, NULL, TRUE);
				};
			if (KEY == 39) // ->
				if ((TETR[Y / 25][X / 25 + 4]) == 0)
				{
					X += 25;
					InvalidateRect(hwnd, NULL, TRUE);
				}
				break;
		case 9:
			if (KEY == VK_UP)         // ^
			{
				OBJECT = 6;
			}
			if (KEY == 37)      // <-
				if ((X != 0) && (TETR[Y / 25][X / 25]) == 0 && 
					(TETR[Y / 25 + 1][X / 25 - 1]) == 0)
				{
					X -= 25;
					InvalidateRect(hwnd, NULL, TRUE);
				};
			if (KEY == 39) // ->
				if ((TETR[Y / 25][X / 25 + 3]) == 0 && 
					(TETR[Y / 25 + 1][X / 25 + 2]) == 0)
				{
					X += 25;
					InvalidateRect(hwnd, NULL, TRUE);
				}
				break;
		case 10:
			if (KEY == VK_UP)         // ^
			{
				OBJECT = 7;
			}
			if (KEY == 37)      // <-
				if ((X != 0) && (TETR[Y / 25][X / 25 - 1]) == 0 && 
					(TETR[Y / 25 + 1][X / 25]) == 0)
				{
					X -= 25;
					InvalidateRect(hwnd, NULL, TRUE);
				};
			if (KEY == 39) // ->
				if ((TETR[Y / 25][X / 25 + 2]) == 0 && 
					(TETR[Y / 25 + 1][X / 25 + 3]) == 0)
				{
					X += 25;
					InvalidateRect(hwnd, NULL, TRUE);
				}
				break;
		case 11:
			if (KEY == VK_UP)         // ^
			{
				OBJECT = 12;
			}
			if (KEY == 37)      // <-
				if ((X != 0) && (TETR[Y / 25][X / 25 - 1]) == 0 && 
					(TETR[Y / 25 + 1][X / 25 - 1]) == 0)
				{
					X -= 25;
					InvalidateRect(hwnd, NULL, TRUE);
				};
			if (KEY == 39) // ->
				if ((TETR[Y / 25][X / 25 + 1]) == 0 && 
					(TETR[Y / 25 + 1][X / 25 + 3]) == 0)
				{
					X += 25;
					InvalidateRect(hwnd, NULL, TRUE);
				}
				break;
		case 12:
			if (KEY == VK_UP)         // ^
			{
				OBJECT = 13;
			}
			if (KEY == 37)      // <-
				if ((X != 0) && (TETR[Y / 25][X / 25]) == 0 && 
					(TETR[Y / 25 + 1][X / 25]) == 0 && (TETR[Y / 25 + 2][X / 25 - 1]) == 0)
				{
					X -= 25;
					InvalidateRect(hwnd, NULL, TRUE);
				};
			if (KEY == 39) // ->
				if ((TETR[Y / 25][X / 25 + 2]) == 0 && 
					(TETR[Y / 25 + 1][X / 25 + 2]) == 0 && (TETR[Y / 25 + 2][X / 25 + 2]) == 0)
				{
					X += 25;
					InvalidateRect(hwnd, NULL, TRUE);
				}
				break;
		case 13:
			if (KEY == VK_UP)         // ^
			{
				OBJECT = 3;
			}
			if (KEY == 37)      // <-
				if ((X != 0) && (TETR[Y / 25][X / 25 - 1]) == 0 && 
					(TETR[Y / 25 + 1][X / 25 + 1]) == 0)
				{
					X -= 25;
					InvalidateRect(hwnd, NULL, TRUE);
				};
			if (KEY == 39) // ->
				if ((TETR[Y / 25][X / 25 + 3]) == 0 && 
					(TETR[Y / 25 + 1][X / 25 + 3]) == 0)
				{
					X += 25;
					InvalidateRect(hwnd, NULL, TRUE);
				}
				break;
		case 14:
			// ###
			// #
			if (KEY == VK_UP)         // ^
			{
				OBJECT = 15;
			}
			if (KEY == 37)      // <-
				if ((X != 0) && (TETR[Y / 25][X / 25 - 1]) == 0 && 
					(TETR[Y / 25 + 1][X / 25 - 1]) == 0)
				{
					X -= 25;
					InvalidateRect(hwnd, NULL, TRUE);
				};
			if (KEY == 39) // ->
				if ((TETR[Y / 25 + 1][X / 25 + 1]) == 0 && 
					(TETR[Y / 25][X / 25 + 3]) == 0)
				{
					X += 25;
					InvalidateRect(hwnd, NULL, TRUE);
				}
				break;
		case 15:
			// #
			// #
			// ##
			if (KEY == VK_UP)         // ^
			{
				OBJECT = 16;
			}
			if (KEY == 37)      // <-
				if ((X != 0) && (TETR[Y / 25][X / 25 - 1]) == 0 && 
					(TETR[Y / 25 + 1][X / 25 - 1]) == 0 && (TETR[Y / 25 + 2][X / 25 - 1]) == 0)
				{
					X -= 25;
					InvalidateRect(hwnd, NULL, TRUE);
				};
			if (KEY == 39) // ->
				if ((TETR[Y / 25][X / 25 + 1]) == 0 && 
					(TETR[Y / 25 + 1][X / 25 + 1]) == 0 && (TETR[Y / 25 + 2][X / 25 + 2]) == 0)
				{
					X += 25;
					InvalidateRect(hwnd, NULL, TRUE);
				}
				break;
		case 16:
			//   #
			// ###
			if (KEY == VK_UP)         // ^
			{
				OBJECT = 5;
			}
			if (KEY == 37)      // <-
				if ((X != 0) && (TETR[Y / 25][X / 25 + 1]) == 0 && 
					(TETR[Y / 25 + 1][X / 25 - 1]) == 0)
				{
					X -= 25;
					InvalidateRect(hwnd, NULL, TRUE);
				};
			if (KEY == 39) // ->
				if ((TETR[Y / 25][X / 25 + 3]) == 0 && 
					(TETR[Y / 25 + 1][X / 25 + 3]) == 0)
				{
					X += 25;
					InvalidateRect(hwnd, NULL, TRUE);
				}
				break;
		case 17:
			// #
			// ##
			// #
			if (KEY == VK_UP)         // ^
			{
				OBJECT = 18;
			}
			if (KEY == 37)      // <-
				if ((X != 0) && (TETR[Y / 25][X / 25 - 1]) == 0 && 
					(TETR[Y / 25 + 1][X / 25 - 1]) == 0 && (TETR[Y / 25 + 2][X / 25 - 1]) == 0)
				{
					X -= 25;
					InvalidateRect(hwnd, NULL, TRUE);
				};
			if (KEY == 39) // ->
				if ((TETR[Y / 25][X / 25 + 1]) == 0 && 
					(TETR[Y / 25 + 1][X / 25 + 2]) == 0 && (TETR[Y / 25 + 2][X / 25 + 1]) == 0)
				{
					X += 25;
					InvalidateRect(hwnd, NULL, TRUE);
				}
				break;
		case 18:
			//  #
			// ###
			if (KEY == VK_UP)         // ^
			{
				OBJECT = 19;
			}
			if (KEY == 37)      // <-
				if ((X != 0) && (TETR[Y / 25][X / 25]) == 0 && 
					(TETR[Y / 25 + 1][X / 25 - 1]) == 0)
				{
					X -= 25;
					InvalidateRect(hwnd, NULL, TRUE);
				};
			if (KEY == 39) // ->
				if ((TETR[Y / 25][X / 25 + 2]) == 0 && 
					(TETR[Y / 25 + 1][X / 25 + 3]) == 0)
				{
					X += 25;
					InvalidateRect(hwnd, NULL, TRUE);
				}
				break;
		case 19:
			//  #
			// ##
			//  #
			if (KEY == VK_UP)         // ^
			{
				OBJECT = 20;
			}
			if (KEY == 37)      // <-
				if ((X != 0) && (TETR[Y / 25][X / 25]) == 0 && 
					(TETR[Y / 25 + 1][X / 25 - 1]) == 0 && (TETR[Y / 25 + 2][X / 25]) == 0)
				{
					X -= 25;
					InvalidateRect(hwnd, NULL, TRUE);
				};
			if (KEY == 39) // ->
				if ((TETR[Y / 25][X / 25 + 2]) == 0 && 
					(TETR[Y / 25 + 1][X / 25 + 2]) == 0 && (TETR[Y / 25 + 2][X / 25 + 2]) == 0)
				{
					X += 25;
					InvalidateRect(hwnd, NULL, TRUE);
				}
				break;
		case 20:
			// ###
			//  #
			if (KEY == VK_UP)         // ^
			{
				OBJECT = 17;
			}
			if (KEY == 37)      // <-
				if ((X != 0) && (TETR[Y / 25][X / 25 - 1]) == 0 && 
					(TETR[Y / 25 + 1][X / 25]) == 0)
				{
					X -= 25;
					InvalidateRect(hwnd, NULL, TRUE);
				};
			if (KEY == 39) // ->
				if ((TETR[Y / 25][X / 25 + 3]) == 0 && 
					(TETR[Y / 25 + 1][X / 25 + 2]) == 0)
				{
					X += 25;
					InvalidateRect(hwnd, NULL, TRUE);
				}
				break;
		}
		break;
	case WM_LBUTTONUP:
		if (HIWORD(lParam) < 475 && 450 < HIWORD(lParam) &&
			LOWORD(lParam) < 375 && 275 < LOWORD(lParam))
			NewGame(hwnd);
		break;
	case WM_DESTROY:
		DeleteObject(hBrush);
		KillTimer(hwnd, 1);
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}