#include <windows.h>
#include <stdio.h>
#include <string.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL InitApplication(HINSTANCE  hInstance);

HBITMAP numbers[9];
HWND hComboBox;
LPCSTR szClassName = "WinAPI", szTitle = "";
int screenX, screenY;


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG msg;
	if (!hPrevInstance)
	{
		if (!InitApplication(hInstance))
			return (FALSE);
	}

	HDC hDCScreen = GetDC(NULL);
	screenX = GetDeviceCaps(hDCScreen, HORZRES);
	screenY = GetDeviceCaps(hDCScreen, VERTRES);

	HWND hWnd = CreateWindow(szClassName, "Nine!", WS_SYSMENU|WS_VISIBLE, 1366 / 2 - 198, 768 / 2 - 189, 
		381, 403, NULL, NULL, hInstance, NULL);
	UpdateWindow(hWnd);

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
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH) CreateSolidBrush(RGB(115,112,112));
	wc.lpszMenuName	 = NULL;
	wc.lpszClassName = szClassName;
	return RegisterClass(&wc);
}



int ff, dd, KEY = 0, SCORE = 0, i, first = 0;
HANDLE hBitmap[11];
int X[10], Y[10];

bool WIN()
{
	if     (X[1] == 0    &&  Y[1] == 0   &&
		X[2] == 125  &&  Y[2] == 0   &&
		X[3] == 250  &&  Y[3] == 0   &&
		X[4] == 0    &&  Y[4] == 125 &&
		X[5] == 125  &&  Y[5] == 125 &&
		X[6] == 250  &&  Y[6] == 125 &&
		X[7] == 0    &&  Y[7] == 250 &&
		X[8] == 125  &&  Y[8] == 250 &&
		X[9] == 250  &&  Y[9] == 250)
		return true;
	else
		return false;
}

LRESULT CALLBACK WndProc (HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT    ps;
	HDC            hdc, hCompatibleDC;
	HANDLE         hOldBitmap;
	BITMAP         Bitmap;
	RECT           Rect;
	int            key;
	char           szText[4];

	switch (iMsg)
	{
	case WM_CREATE:
		hBitmap[0]   =  (HBITMAP)LoadImage(NULL, "START.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hBitmap[1]   =  (HBITMAP)LoadImage(NULL, "1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hBitmap[2]   =  (HBITMAP)LoadImage(NULL, "2.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hBitmap[3]   =  (HBITMAP)LoadImage(NULL, "3.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hBitmap[4]   =  (HBITMAP)LoadImage(NULL, "4.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hBitmap[5]   =  (HBITMAP)LoadImage(NULL, "5.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hBitmap[6]   =  (HBITMAP)LoadImage(NULL, "6.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hBitmap[7]   =  (HBITMAP)LoadImage(NULL, "7.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hBitmap[8]   =  (HBITMAP)LoadImage(NULL, "8.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hBitmap[9]   =  (HBITMAP)LoadImage(NULL, "0.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hBitmap[10]  =  (HBITMAP)LoadImage(NULL, "WIN.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		key = 0;

		break;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		if (WIN())
		{
			GetObject(hBitmap[10], sizeof(BITMAP), &Bitmap);
			hCompatibleDC = CreateCompatibleDC(hdc);
			hOldBitmap = SelectObject(hCompatibleDC, hBitmap[10]);
			GetClientRect(hwnd, &Rect);
			StretchBlt(hdc, 0, 0, Bitmap.bmWidth , Bitmap.bmHeight, 
				hCompatibleDC, 0, 0, Bitmap.bmWidth, Bitmap.bmHeight, SRCCOPY);
			SelectObject(hCompatibleDC, hOldBitmap);
			DeleteDC(hCompatibleDC);
			SetBkMode(hdc, 20);
			SetTextColor(hdc, RGB(255, 140, 0));
			itoa(SCORE, szText, 10);
			TextOut(hdc, 180, 300, szText, strlen(szText)); 
		}
		else
		{
			if (first)
			{
				for (int i = 1; i < 10; i++)
				{
					GetObject(hBitmap[i], sizeof(BITMAP), &Bitmap);
					hCompatibleDC = CreateCompatibleDC(hdc);
					hOldBitmap = SelectObject(hCompatibleDC, hBitmap[i]);
					GetClientRect(hwnd, &Rect);
					StretchBlt(hdc, X[i], Y[i], Bitmap.bmWidth , Bitmap.bmHeight, 
						hCompatibleDC, 0, 0, Bitmap.bmWidth, Bitmap.bmHeight, SRCCOPY);
					SelectObject(hCompatibleDC, hOldBitmap);
					DeleteDC(hCompatibleDC);
				}
			}
			else
			{
				GetObject(hBitmap[0], sizeof(BITMAP), &Bitmap);
				hCompatibleDC = CreateCompatibleDC(hdc);
				hOldBitmap = SelectObject(hCompatibleDC, hBitmap[0]);
				GetClientRect(hwnd, &Rect);
				StretchBlt(hdc, 0, 0, Bitmap.bmWidth , Bitmap.bmHeight, 
					hCompatibleDC, 0, 0, Bitmap.bmWidth, Bitmap.bmHeight, SRCCOPY);
				SelectObject(hCompatibleDC, hOldBitmap);
				DeleteDC(hCompatibleDC);
				first++;
			}
		}
		EndPaint(hwnd, &ps);
		break;

	case WM_KEYDOWN :
		key = wParam;
		if (key == 27) PostQuitMessage (0);
		if (key == 32)
		{
			X[9] = 0;    Y[9] = 0;
			X[8] = 125;  Y[8] = 0;
			X[7] = 250;  Y[7] = 0;
			X[6] = 0;    Y[6] = 125;
			X[5] = 125;  Y[5] = 125;
			X[4] = 250;  Y[4] = 125;
			X[3] = 0;    Y[3] = 250;
			X[2] = 125;  Y[2] = 250;
			X[1] = 250;  Y[1] = 250;
			SetWindowText(hwnd, "----New Game----");
			SCORE = 0;
			KEY++;
			InvalidateRect(hwnd, NULL, TRUE);
		}
		if (KEY)
		{
			if (key == 37)      // <-
			{
				SCORE++;
				char s[5];
				itoa(SCORE, s, 10);
				SetWindowText(hwnd, s);
				if (X[9] != 250)
				{
					for (i = 1; i < 9; i++)
					{
						if (X[i] == X[9] + 125 && Y[i] == Y[9]) break;
					}
					X[i] -= 125;
					X[9] += 125;
					InvalidateRect(hwnd, NULL, TRUE);
				}
			}
			if (key == 39)      // ->
			{
				SCORE++;
				char s[5];
				itoa(SCORE, s, 10);
				SetWindowText(hwnd, s);
				if (X[9] != 0)
				{
					for (i = 1; i < 9; i++)
					{
						if (X[i] == X[9] - 125 && Y[i] == Y[9]) break;
					}
					X[i] += 125;
					X[9] -= 125;
					InvalidateRect(hwnd, NULL, TRUE);
				}
			}
			if (key == 38)      //  /\         //
			{
				SCORE++;
				char s[5];
				itoa(SCORE, s, 10);
				SetWindowText(hwnd, s);
				if (Y[9] != 250)
				{
					for (i = 1; i < 9; i++)
					{
						if (Y[i] == Y[9] + 125 && X[i] == X[9]) break;
					}
					Y[i] -= 125;
					Y[9] += 125;
					InvalidateRect(hwnd, NULL, TRUE);
				}
			}
			if (key == 40)      //  \/
			{
				SCORE++;
				char s[5];
				itoa(SCORE, s, 10);
				SetWindowText(hwnd, s);
				if (Y[9] != 0)
				{
					for (i = 1; i < 9; i++)
					{
						if (Y[i] == Y[9] - 125 && X[i] == X[9]) break;
					}
					Y[i] += 125;
					Y[9] -= 125;
					InvalidateRect(hwnd, NULL, TRUE);
				}
			}
		}
		break;



	case WM_DESTROY :
		PostQuitMessage (0) ;
		break; 
	}

	return DefWindowProc (hwnd, iMsg, wParam, lParam) ;
}