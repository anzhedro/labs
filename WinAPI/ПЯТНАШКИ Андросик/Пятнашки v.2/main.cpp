#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <ctime>
#include <math.h>



#define ID_COUNT 1 
#define ID_EXIT 2

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

BOOL InitApplication(HINSTANCE  hInstance);

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

	/*HWND hWnd = CreateWindow(szClassName, "Пятнашки!!", WS_SYSMENU|WS_VISIBLE, screenX / 2 - 250, screenY / 2 - 250, 
	506, 523, NULL, NULL, hInstance, NULL);*/
	HWND hWnd = CreateWindowEx(
		WS_EX_LAYERED, //прозрачность
		szClassName, 
		"Пятнашки!!",
		WS_VISIBLE|WS_POPUP, // стиль - окно без рамки
		screenX / 2 - 250,
		screenY / 2 - 250,
		500,
		540, 
		NULL,
		NULL,
		hInstance,
		NULL);

	SetLayeredWindowAttributes(hWnd, RGB(225, 25, 0), 0, LWA_COLORKEY);

	CreateWindow("button", "Новая игра", WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,
		0, 500,
		100, 40, hWnd, (HMENU)ID_COUNT, hInstance, NULL);
	CreateWindow("button", "Выход", WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,
		400, 500,
		100, 40, hWnd, (HMENU)ID_EXIT, hInstance, NULL);

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
	wc.hCursor		 = LoadCursor(NULL, IDC_CROSS);
	wc.hbrBackground = (HBRUSH) CreateSolidBrush(RGB(123, 104, 238));
	wc.lpszMenuName	 = NULL;
	wc.lpszClassName = szClassName;
	return RegisterClass(&wc);
}

int ff, dd, KEY = 0, SCORE = 0, i, first = 0;
HANDLE hBitmap[18];
int X[17], Y[17];
int genElem  = 0;
int CHEAT = 0;

bool WIN()
{
	if (X[1]  == 0    &&  Y[1]  == 0   &&
		X[2]  == 125  &&  Y[2]  == 0   &&
		X[3]  == 250  &&  Y[3]  == 0   &&
		X[4]  == 375  &&  Y[4]  == 0   &&
		X[5]  == 0    &&  Y[5]  == 125 &&
		X[6]  == 125  &&  Y[6]  == 125 &&
		X[7]  == 250  &&  Y[7]  == 125 &&
		X[8]  == 375  &&  Y[8]  == 125 &&
		X[9]  == 0    &&  Y[9]  == 250 &&
		X[10] == 125  &&  Y[10] == 250 &&
		X[11] == 250  &&  Y[11] == 250 &&
		X[12] == 375  &&  Y[12] == 250 &&
		X[13] == 0    &&  Y[13] == 375 &&
		X[14] == 125  &&  Y[14] == 375 &&
		X[15] == 250  &&  Y[15] == 375 &&
		X[16] == 375  &&  Y[16] == 375)
		return true;
	else
		return false;
}

void RANDOM()
{
	int *array = new int[16];
	for (int i = 0; i < 16; i++) 
	{
		genElem = (rand() % 16) + 1;
		if (!std::count(array, array + 15, genElem))
			array[i] = genElem;
		else
			i--;
	}

	int summ = 0;
	int e = 0;
	for (int i = 0; i < 15; i++)
	{
		if (array[i] == 16) 
		{
			if (i % 4 == 0) 
				e = 4;
			else
				e = i % 4 + 1;
			continue;
		}
		for (int j = i + 1; j < 16; j++)
			if (array[i] > array[j])
				summ++;
	}
	summ += e;

	if (summ % 2 == 1) 
	{
		delete [] array;
		RANDOM();
	}
	else
	{
		X[array[0]]  = 0;    Y[array[0]]  = 0;
		X[array[1]]  = 125;  Y[array[1]]  = 0;
		X[array[2]]  = 250;  Y[array[2]]  = 0;
		X[array[3]]  = 375;  Y[array[3]]  = 0;
		X[array[4]]  = 0;    Y[array[4]]  = 125;
		X[array[5]]  = 125;  Y[array[5]]  = 125;
		X[array[6]]  = 250;  Y[array[6]]  = 125;
		X[array[7]]  = 375;  Y[array[7]]  = 125;
		X[array[8]]  = 0;    Y[array[8]]  = 250;
		X[array[9]]  = 125;  Y[array[9]]  = 250;
		X[array[10]] = 250;  Y[array[10]] = 250;
		X[array[11]] = 375;  Y[array[11]] = 250;
		X[array[12]] = 0;    Y[array[12]] = 375;
		X[array[13]] = 125;  Y[array[13]] = 375;
		X[array[14]] = 250;  Y[array[14]] = 375;
		X[array[15]] = 375;  Y[array[15]] = 375;
		delete [] array;
		return;
	}
}

LRESULT CALLBACK WndProc (HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT    ps;
	HDC            hdc, hCompatibleDC;
	HANDLE         hOldBitmap;
	BITMAP         Bitmap;
	RECT           Rect;
	LOGFONT        lf;
	int            key;
	char           szText[5];


	switch (iMsg)
	{
	case WM_CREATE:
		hBitmap[0]    =  (HBITMAP)LoadImage(NULL, "START.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hBitmap[1]    =  (HBITMAP)LoadImage(NULL, "1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hBitmap[2]    =  (HBITMAP)LoadImage(NULL, "2.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hBitmap[3]    =  (HBITMAP)LoadImage(NULL, "3.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hBitmap[4]    =  (HBITMAP)LoadImage(NULL, "4.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hBitmap[5]    =  (HBITMAP)LoadImage(NULL, "5.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hBitmap[6]    =  (HBITMAP)LoadImage(NULL, "6.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hBitmap[7]    =  (HBITMAP)LoadImage(NULL, "7.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hBitmap[8]    =  (HBITMAP)LoadImage(NULL, "8.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hBitmap[9]    =  (HBITMAP)LoadImage(NULL, "9.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hBitmap[10]   =  (HBITMAP)LoadImage(NULL, "10.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hBitmap[11]   =  (HBITMAP)LoadImage(NULL, "11.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hBitmap[12]   =  (HBITMAP)LoadImage(NULL, "12.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hBitmap[13]   =  (HBITMAP)LoadImage(NULL, "13.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hBitmap[14]   =  (HBITMAP)LoadImage(NULL, "14.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hBitmap[15]   =  (HBITMAP)LoadImage(NULL, "15.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		//hBitmap[16]   =  (HBITMAP)LoadImage(NULL, "0.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hBitmap[17]   =  (HBITMAP)LoadImage(NULL, "WIN.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		key = 0;
		srand(time(0));



		break;
	case WM_COMMAND:
		switch(LOWORD(wParam)) 
		{
		case ID_COUNT:
			SCORE = 0;
			KEY++;
			RANDOM();
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		case ID_EXIT:
			DestroyWindow(hwnd);
			break;
		}
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		if (WIN() || CHEAT == 1)
		{
			GetObject(hBitmap[17], sizeof(BITMAP), &Bitmap);
			hCompatibleDC = CreateCompatibleDC(hdc);
			hOldBitmap = SelectObject(hCompatibleDC, hBitmap[17]);
			GetClientRect(hwnd, &Rect);
			StretchBlt(hdc, 0, 0, Bitmap.bmWidth , Bitmap.bmHeight, 
				hCompatibleDC, 0, 0, Bitmap.bmWidth, Bitmap.bmHeight, SRCCOPY);
			SelectObject(hCompatibleDC, hOldBitmap);
			DeleteDC(hCompatibleDC);


			strcpy(lf.lfFaceName, "Impact"); 
			lf.lfUnderline = 0; 
			lf.lfUnderline = 0;  
			lf.lfStrikeOut = 0;
			lf.lfItalic = 0;
			lf.lfHeight = 40; 
			lf.lfWidth = 15; 
			lf.lfWeight = 75; 
			lf.lfEscapement = 0; 
			lf.lfQuality = 0;
			lf.lfUnderline = 5;
			HFONT hFont = CreateFontIndirect(&lf); 

			SelectObject(hdc, hFont); 
			SetBkMode(hdc, 20);
			SetTextColor(hdc, RGB(128, 0, 0));
			itoa(SCORE, szText, 10);
			TextOut(hdc, 321, 328, szText, strlen(szText));
			KEY = 0;
			CHEAT = 0;
			DeleteObject(hFont);
		}
		else
		{
			if (first)
			{
				for (int i = 1; i < 17; i++)
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
		if (key == 27) 
		{
			PostQuitMessage (0);
		}
		if (key == 32)
		{
			SetWindowText(hwnd, "----Новая игра----");
			SCORE = 0;
			KEY++;
			RANDOM();
			InvalidateRect(hwnd, NULL, TRUE);
		}
		if (key == 16)
		{
			CHEAT = 1;
			//SCORE = 15;
			InvalidateRect(hwnd, NULL, TRUE);
		}
		if (KEY)
		{
			if (key == 37)      // <-
			{
				if (X[16] != 375)
				{
					for (i = 1; i < 16; i++)
					{
						if (X[i] == X[16] + 125 && Y[i] == Y[16]) break;
					}
					X[i] -= 125;
					X[16] += 125;
					InvalidateRect(hwnd, NULL, TRUE);
					SCORE++;
					char s[50];
					itoa(SCORE, s, 10);
					SetWindowText(hwnd, s);
					MessageBeep(MB_ICONASTERISK);
				}
			}
			if (key == 39)      // ->
			{
				if (X[16] != 0)
				{
					for (i = 1; i < 16; i++)
					{
						if (X[i] == X[16] - 125 && Y[i] == Y[16]) break;
					}
					X[i] += 125;
					X[16] -= 125;
					InvalidateRect(hwnd, NULL, TRUE);
					SCORE++;
					char s[50];
					itoa(SCORE, s, 10);
					SetWindowText(hwnd, s);
					MessageBeep(MB_ICONASTERISK);
				}
			}
			if (key == 38)      //  /\         //
			{
				if (Y[16] != 375)
				{
					for (i = 1; i < 16; i++)
					{
						if (Y[i] == Y[16] + 125 && X[i] == X[16]) break;
					}
					Y[i] -= 125;
					Y[16] += 125;
					InvalidateRect(hwnd, NULL, TRUE);
					SCORE++;
					char s[50];
					itoa(SCORE, s, 10);
					SetWindowText(hwnd, s);
					MessageBeep(MB_ICONASTERISK);
				}
			}
			if (key == 40)      //  \/
			{
				if (Y[16] != 0)
				{
					for (i = 1; i < 16; i++)
					{
						if (Y[i] == Y[16] - 125 && X[i] == X[16]) break;
					}
					Y[i] += 125;
					Y[16] -= 125;
					InvalidateRect(hwnd, NULL, TRUE);
					SCORE++;
					char s[50];
					itoa(SCORE, s, 10);
					SetWindowText(hwnd, s);
					MessageBeep(MB_ICONASTERISK);
				}
			}
		}
		break;
	case WM_NCHITTEST:
		{
			/*
			После того как рамка окна была убрана, стало невозможно двигать окно с помощью мыши.
			Здесь предложен способ обмануть систему, сказав ей что теперь наша рамка - все окно.
			*/
			LRESULT currentArea = DefWindowProc(hwnd, iMsg, wParam, lParam);
			if (HTCLIENT == currentArea)
				return HTCAPTION;
			return currentArea;
		}

	case WM_DESTROY :
		PostQuitMessage (0) ;
		break; 
	}

	return DefWindowProc (hwnd, iMsg, wParam, lParam) ;
}