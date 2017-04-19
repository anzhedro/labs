#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <ctime>
#include <math.h>

#include "resource.h"
//#define IDR_MENU1                       101
//#define ID_NEWGAME                      40003
//#define ID_EXIT2                        40005
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

	/*HWND hWnd = CreateWindow(szClassName, "Пятнашки!!", WS_SYSMENU|WS_VISIBLE, screenX / 2 - 318, screenY / 2 - 318, 
	506, 523, NULL, NULL, hInstance, NULL);*/
	HWND hWnd = CreateWindowEx(
		WS_EX_LAYERED, //прозрачность
		szClassName, 
		"Пятнашки!!",
		WS_VISIBLE|WS_POPUP, // стиль - окно без рамки
		screenX / 2 - 318,
		/*screenY / 2 - 318*/20,
		636,
		679, 
		NULL,
		NULL,
		hInstance,
		NULL);

	SetLayeredWindowAttributes(hWnd, RGB(255, 255, 1), 0, LWA_COLORKEY);



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
	wc.style         = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc   = (WNDPROC)WndProc;
	wc.cbClsExtra    = 0;
	wc.cbWndExtra    = 0;
	wc.hInstance     = hInstance;
	wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor       = LoadCursor(NULL, IDC_CROSS);
	wc.hbrBackground = (HBRUSH) CreateSolidBrush(RGB(255, 255,1));
	wc.lpszMenuName  = NULL;
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
		X[2]  == 159  &&  Y[2]  == 0   &&
		X[3]  == 318  &&  Y[3]  == 0   &&
		X[4]  == 477  &&  Y[4]  == 0   &&
		X[5]  == 0    &&  Y[5]  == 159 &&
		X[6]  == 159  &&  Y[6]  == 159 &&
		X[7]  == 318  &&  Y[7]  == 159 &&
		X[8]  == 477  &&  Y[8]  == 159 &&
		X[9]  == 0    &&  Y[9]  == 318 &&
		X[10] == 159  &&  Y[10] == 318 &&
		X[11] == 318  &&  Y[11] == 318 &&
		X[12] == 477  &&  Y[12] == 318 &&
		X[13] == 0    &&  Y[13] == 477 &&
		X[14] == 159  &&  Y[14] == 477 &&
		X[15] == 318  &&  Y[15] == 477 &&
		X[16] == 477  &&  Y[16] == 477)
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
		X[array[1]]  = 159;  Y[array[1]]  = 0;
		X[array[2]]  = 318;  Y[array[2]]  = 0;
		X[array[3]]  = 477;  Y[array[3]]  = 0;
		X[array[4]]  = 0;    Y[array[4]]  = 159;
		X[array[5]]  = 159;  Y[array[5]]  = 159;
		X[array[6]]  = 318;  Y[array[6]]  = 159;
		X[array[7]]  = 477;  Y[array[7]]  = 159;
		X[array[8]]  = 0;    Y[array[8]]  = 318;
		X[array[9]]  = 159;  Y[array[9]]  = 318;
		X[array[10]] = 318;  Y[array[10]] = 318;
		X[array[11]] = 477;  Y[array[11]] = 318;
		X[array[12]] = 0;    Y[array[12]] = 477;
		X[array[13]] = 159;  Y[array[13]] = 477;
		X[array[14]] = 318;  Y[array[14]] = 477;
		X[array[15]] = 477;  Y[array[15]] = 477;
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
	HFONT          hFont;
	int            key;
	char           szText[5];
	static HMENU   hmenu;
	static HINSTANCE hInstance;
	static int click_x, click_y;

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
		hBitmap[16]   =  (HBITMAP)LoadImage(NULL, "0.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hBitmap[17]   =  (HBITMAP)LoadImage(NULL, "WIN.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hBitmap[18]   =  (HBITMAP)LoadImage(NULL, "BAR.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		key = 0;
		hmenu = LoadMenu(hInstance, MAKEINTRESOURCE(IDR_MENU1));
		hmenu = GetSubMenu(hmenu, 0);            


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
			hFont = CreateFontIndirect(&lf); 


		//CreateWindow("button", "Новая игра", WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,
		//	0, 636,
		//	100, 40, hwnd, (HMENU)ID_COUNT, hInstance, NULL);
		//CreateWindow("button", "Выход", WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,
		//	536, 636,
		//	100, 40, hwnd, (HMENU)ID_EXIT, hInstance, NULL);




		srand(time(0));



		break;
	case WM_COMMAND:
		switch(LOWORD(wParam)) 
		{
			//case ID_COUNT:
		case ID_NEWGAME:
			SCORE = 0;
			KEY++;
			RANDOM();
			InvalidateRect(hwnd, NULL, TRUE);
			break;
			//case ID_EXIT:
		case ID_EXIT2:
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


		

			SelectObject(hdc, hFont); 
			SetBkMode(hdc, 20);
			SetTextColor(hdc, RGB(0, 0, 128));
			itoa(SCORE, szText, 10);
			TextOut(hdc, 400, 434, szText, strlen(szText));
			KEY = 0;
			CHEAT = 0;
			//DeleteObject(hFont);
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

		GetObject(hBitmap[18], sizeof(BITMAP), &Bitmap);
		hCompatibleDC = CreateCompatibleDC(hdc);
		hOldBitmap = SelectObject(hCompatibleDC, hBitmap[18]);
		GetClientRect(hwnd, &Rect);
		StretchBlt(hdc, 0, 639, Bitmap.bmWidth , Bitmap.bmHeight, 
			hCompatibleDC, 0, 0, Bitmap.bmWidth, Bitmap.bmHeight, SRCCOPY);
		SelectObject(hCompatibleDC, hOldBitmap);
		DeleteDC(hCompatibleDC);
		//DeleteObject(hFont);
		EndPaint(hwnd, &ps);
		break;

	case WM_KEYDOWN :
		key = wParam;
		if (key == 27) 
		{
			DeleteObject(hFont);
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
			SCORE = -200;
			InvalidateRect(hwnd, NULL, TRUE);
		}
		if (KEY)
		{
			if (key == 37)      // <-
			{
				if (X[16] != 477)
				{
					for (i = 1; i < 16; i++)
					{
						if (X[i] == X[16] + 159 && Y[i] == Y[16]) break;
					}
					X[i] -= 159;
					X[16] += 159;
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
						if (X[i] == X[16] - 159 && Y[i] == Y[16]) break;
					}
					X[i] += 159;
					X[16] -= 159;
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
				if (Y[16] != 477)
				{
					for (i = 1; i < 16; i++)
					{
						if (Y[i] == Y[16] + 159 && X[i] == X[16]) break;
					}
					Y[i] -= 159;
					Y[16] += 159;
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
						if (Y[i] == Y[16] - 159 && X[i] == X[16]) break;
					}
					Y[i] += 159;
					Y[16] -= 159;
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



	case WM_LBUTTONUP :
		click_x = LOWORD(lParam);
		click_y = HIWORD(lParam);
		if ((X[16] - 159 < click_x ) && (click_x < X[16]) && (click_y > Y[16]) &&(click_y < Y[16] + 159))
		{
			for (i = 1; i < 16; i++)
					{
						if (X[i] == X[16] - 159 && Y[i] == Y[16]) break;
					}
					X[i] += 159;
					X[16] -= 159;
					InvalidateRect(hwnd, NULL, TRUE);
					SCORE++;
					MessageBeep(MB_ICONASTERISK);
			break;
		}
		if ((X[16] < click_x ) && (click_x < X[16] + 159) && (click_y > Y[16] - 159) &&(click_y < Y[16]))
		{
			for (i = 1; i < 16; i++)
			{
				if (Y[i] == Y[16] - 159 && X[i] == X[16]) break;
			}
			Y[i] += 159;
			Y[16] -= 159;
			InvalidateRect(hwnd, NULL, TRUE);
			SCORE++;
			MessageBeep(MB_ICONASTERISK);
		}
		if ((X[16] + 159 < click_x ) && (click_x < X[16] + 318) && (click_y > Y[16]) &&(click_y < Y[16] + 159))
		{
			for (i = 1; i < 16; i++)
			{
				if (X[i] == X[16] + 159 && Y[i] == Y[16]) break;
			}
			X[i] -= 159;
			X[16] += 159;
			InvalidateRect(hwnd, NULL, TRUE);
			SCORE++;
			MessageBeep(MB_ICONASTERISK);
		}
		if ((X[16] < click_x ) && (click_x < X[16] + 159) && (click_y > Y[16] + 159) &&(click_y < Y[16] + 318 ))
		{
			for (i = 1; i < 16; i++)
			{
				if (Y[i] == Y[16] + 159 && X[i] == X[16]) break;
			}
			Y[i] -= 159;
			Y[16] += 159;
			InvalidateRect(hwnd, NULL, TRUE);
			SCORE++;
			MessageBeep(MB_ICONASTERISK);
		}

		break;

	/*case WM_LBUTTONDOWN:
     SendMessage(hwnd,WM_NCLBUTTONDOWN,HTCAPTION,0);
          break;*/
	case WM_NCRBUTTONDOWN:
		{	
			POINT point = {LOWORD(lParam), HIWORD(lParam)}; //координата нажатия мышью
			ClientToScreen(hwnd, &point);
			WINDOWPLACEMENT wp;
			GetWindowPlacement(hwnd, &wp);
			point.x -= wp.rcNormalPosition.left;
			point.y -= wp.rcNormalPosition.top;
			TrackPopupMenu(hmenu, 0, point.x, point.y, 0, hwnd, NULL);//отображение контекстного меню в данной точке
		}
		break;


	case WM_DESTROY :
		DeleteObject(hFont);
		PostQuitMessage (0) ;
		break; 
	}

	return DefWindowProc (hwnd, iMsg, wParam, lParam) ;
}