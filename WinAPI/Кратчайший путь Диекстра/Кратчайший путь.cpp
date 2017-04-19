#include <windows.h>
#include <tchar.h>
#include <math.h>
#include <fstream>
#include <iostream>
#include <math.h>
#include <string.h>
#define ID_COUNT 1 
using namespace std;
static int n = 0, first = 0, last = 0;
static int NUMBER, FIRST, LAST;
static int **a;
static int *z, num, v;
void READ()
{
		ifstream inp("input.txt");            
		inp >> n >> first >> last;
		a = new int*[n];
		for (int i = 0; i < n; i++) a[i] = new int[n];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				inp >> a[i][j];
				if (a[i][j] == -1) a[i][j] = 0;
			}
		}
		inp.close();
		NUMBER = n;
		FIRST = first - 1;
		LAST = last - 1;
}
int func()
{
	int INF = 2013;                    
	int p = NUMBER;                          
	int *x = new int[NUMBER];  
	int *t = new int[NUMBER];  
	int *h = new int[NUMBER];  
	z = new int[NUMBER + 1]; 
	num = 1;
	int u;     
	for (u = 0; u < p; u++)
	{
		t[u] = INF; 
		x[u] = 0;        
	}
	h[FIRST] = 0; 
	t[FIRST] = 0; 
	x[FIRST] = 1; 
	v = FIRST;    
	if (FIRST == LAST)
	{
		return 0;
	}
	else
		while (true)
		{
			for(u = 0; u < p; u++)
			{
				if(a[v][u] == 0) continue;
				if(x[u] == 0 && t[u] > t[v] + a[v][u])
				{
					t[u] = t[v] + a[v][u];  
					h[u] = v; 
				}
			}
			int w = INF;  
			v = -1;            
			for(u = 0; u < p; u++) 
			{
				if(x[u] == 0 && t[u] < w)
				{
					v = u; 
					w = t[u];
				}
			}
			if(v == -1)
			{
				return -1;
			}
			if(v == LAST) 
			{        
				u = LAST;
				while(u != FIRST)
				{
					z[num] =  u + 1;
					u = h[u];
					num++;
				}
				z[num] = FIRST + 1;
				break;
			}
			x[v] = 1; 
		}
		return t[LAST];
}


LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	READ();
	static TCHAR szAppName[] = ("HelloWin") ;
	HWND        hwnd ;
	MSG         msg ;
	WNDCLASSEX  wndclass ;
	ZeroMemory( &wndclass, sizeof( wndclass ) );
	wndclass.cbSize        = sizeof (wndclass) ;
	wndclass.style         = 0;
	wndclass.lpfnWndProc   = (WNDPROC)WndProc ;
	wndclass.cbClsExtra    = 0 ;
	wndclass.cbWndExtra    = 0 ;
	wndclass.hInstance     = hInstance ;
	wndclass.hIcon         = LoadIcon(NULL, IDI_QUESTION) ;
	wndclass.hIconSm       = LoadIcon(NULL, IDI_ASTERISK) ;
	wndclass.hCursor       = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH) CreateSolidBrush(RGB(192, 192, 192));
	wndclass.lpszMenuName  = NULL ;
	wndclass.lpszClassName = szAppName ;

	RegisterClassEx (&wndclass) ;
	hwnd = CreateWindow ((szAppName), ("Графы!"), WS_OVERLAPPEDWINDOW, 0, 0, 1366, 768, NULL, NULL, hInstance, NULL);
	//hwnd = CreateWindowEx(
	//	WS_EX_LAYERED, //прозрачность
	//	(szAppName), 
	//	"Графы!!",
	//	WS_VISIBLE|WS_POPUP, // стиль - окно без рамки
	//	0,
	//	15,
	//	1366,
	//	768, 
	//	NULL,
	//	NULL,
	//	hInstance,
	//	NULL);

	//SetLayeredWindowAttributes(hwnd, RGB(255, 255, 1), 0, LWA_COLORKEY);
	CreateWindow("button", "Считать!", WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,
		          1200, 10, 140, 40, hwnd, (HMENU)ID_COUNT, hInstance, NULL);

	//SetLayeredWindowAttributes(hwnd, RGB(255, 255, 1), 0, LWA_COLORKEY);
	
	ShowWindow (hwnd, iCmdShow) ;
	UpdateWindow (hwnd) ;
	while (GetMessage (&msg, NULL, 0, 0))
	{
		TranslateMessage (&msg) ;
		DispatchMessage (&msg) ;
	}
	return msg.wParam ;
}
LRESULT CALLBACK WndProc (HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC         hdc ;
	PAINTSTRUCT ps;
	RECT        rect ;
	HPEN        hPen;
	static HBRUSH      hBrush1, hBrush2, hBrush3;
	static HCURSOR hcHand, hcArrow;
	static char *number, *szText, *txt;
	static int *x, *y, x1, x2, click_x, click_y, k1, q = -1, keyy, PUT, count;
	static double e;
	switch (iMsg)
	{
	case WM_CREATE :
		hcHand = LoadCursor(NULL, IDC_HAND); // удалять не надо, это разделяемые курсоры
		hcArrow = LoadCursor(NULL, IDC_ARROW);
		hBrush1 = CreateSolidBrush(RGB(0, 128, 0));
		hBrush2 = CreateSolidBrush(RGB(255, 250, 250));
		hBrush3 = CreateSolidBrush(RGB(135, 206, 235));
		szText = new char[5];
		txt = new char[5];
		number = new char[5];
		x = new int[n];
		y = new int[n];
		e = 3.1415;
		PUT = 0;
		count = 1;
		for (int j = n; j>= 1; j--)
		{
			x[j] = 1366/2 + 160 * cos((double)e) * 1.6;
			y[j] = 768/2  - 160 * sin((double)e) * 1.6;
			e += (3.1415 * 2) / n;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				if (a[i][j] > 0)
				{
					a[i][j] = (int)sqrt((double)((x[i + 1] - x[j + 1]) * (x[i + 1] - x[j + 1]) + (y[i + 1] - y[j + 1]) * (y[i + 1] - y[j + 1])));
					
				}
		}
		unsigned int key;
		break;
	case WM_SIZE :
		GetClientRect(hwnd, &rect);
		break;
	case WM_COMMAND:
		switch(LOWORD(wParam)) 
		{
		case ID_COUNT:
			hdc = GetDC(hwnd);
			PUT = func();
			for (int i = num; i > 1; i--)
			{
				hPen = CreatePen(0, 2, RGB(225, 25, 0));
				SelectObject(hdc, hPen);
				MoveToEx(hdc, x[z[i]], y[z[i]], NULL);
				LineTo(hdc, x[z[i - 1]], y[z[i - 1]]);
				DeleteObject(hPen);
			}

			break;
		}
		break;
	case WM_PAINT :
		hdc = BeginPaint (hwnd, &ps) ;
		for (int i = n; i >= 1; i--)
		{
			if (i == q) 
			{
				SelectObject(hdc, hBrush1);
			}
			else
				SelectObject(hdc, hBrush2);
			if (i == first || i == last) 
			{
				SelectObject(hdc, hBrush3);
			} 

			Ellipse(hdc, x[i] - 300 / n, y[i] - 300 / n, x[i] + 300 / n, y[i] + 300 / n);
		}
		for (int k = n; k >= 1; k--)
		{
			for (int r = n; r >= 1; r--)
			{
				if (a[k - 1][r - 1] > 0)
				{
					hPen = CreatePen(0, 2, RGB(245, 222, 179));
					SelectObject(hdc, hPen);
					MoveToEx(hdc, x[k], y[k], NULL);
					LineTo(hdc, x[r], y[r]);
					DeleteObject(hPen);
				}
			}
		}
		for (int i = n; i >= 1; i--)
		{
			itoa(i, number, 10);
			SetBkMode(hdc, 20);
			SetTextColor(hdc, RGB(0, 0, 0));
			TextOut(hdc, x[i] - 7, y[i] - 6, number, strlen(number));
		}

		EndPaint (hwnd, &ps) ;
		break;
	case WM_MOUSEMOVE : 
		{
			char s[20];
			int ff = LOWORD(lParam);
			int dd = HIWORD(lParam); 
			itoa(ff, s, 10);
			strcat(s, " - ");
			char ss[5];
			itoa(dd, ss, 10);
			strcat(s, ss);
			SetWindowText(hwnd, s);
			keyy = 0;
			if (k1)
			{
				x[q] = LOWORD(lParam);
				y[q] = HIWORD(lParam);
				keyy = q;
				InvalidateRect(hwnd, NULL, TRUE); 
			} 
		}
		break;					  
	case WM_LBUTTONDOWN :
		for (int i = n; i >= 1; i--) if (x[i] - 300 / n < click_x && click_x <  x[i] + 300 / n && y[i] - 300 / n < click_y && click_y < y[i] + 300 / n) MessageBeep(MB_ICONEXCLAMATION);
		click_x = LOWORD(lParam);
		click_y = HIWORD(lParam);
		for (int i = n; i >= 1; i--)
		{
			if (x[i] - 300 / n < click_x && click_x <  x[i] + 300 / n && y[i] - 300 / n < click_y && click_y < y[i] + 300 / n)
			{
				q = i;
				k1++;
				break;
			}
		}
		break;
	case WM_LBUTTONUP :
		k1 = 0;
		if (keyy > 0)
		{
			hdc = GetDC(hwnd); 
			SetTextColor(hdc, RGB(225, 25, 0));
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
					if (a[i][j] > 0)
					{
						a[i][j] = (int)sqrt((double)((x[i + 1] - x[j + 1]) * (x[i + 1] - x[j + 1]) + (y[i + 1] - y[j + 1]) * (y[i + 1] - y[j + 1])));

					}
			}
		}
		break;
	case WM_KEYDOWN :
		key = wParam;  
		hdc = GetDC(hwnd); 
		if (key == 32)
		{
			PUT = func();
			for (int i = num; i > 1; i--)
			{
				hPen = CreatePen(0, 2, RGB(225, 25, 0));
				SelectObject(hdc, hPen);
				MoveToEx(hdc, x[z[i]], y[z[i]], NULL);
				LineTo(hdc, x[z[i - 1]], y[z[i - 1]]);
				DeleteObject(hPen);
			}
		}
		break;
	case WM_DESTROY :
		DeleteObject(hBrush1);
		DeleteObject(hBrush2);
		DeleteObject(hBrush3);
		PostQuitMessage (0) ;
		break; 
	}
	return DefWindowProc (hwnd, iMsg, wParam, lParam) ;
}
