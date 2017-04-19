#include <process.h>  
#include <windows.h>
#include <tchar.h>
#include <math.h>
#undef UNICODE
LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;


int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	static TCHAR szAppName[] = ("HelloWin") ;
	HWND        hwnd ;
	MSG         msg ;
	WNDCLASSEX  wndclass ;

	wndclass.cbSize        = sizeof (wndclass) ;
	wndclass.style         = CS_HREDRAW | CS_VREDRAW ;
	wndclass.lpfnWndProc   = WndProc ;
	wndclass.cbClsExtra    = 0 ;
	wndclass.cbWndExtra    = 0 ;
	wndclass.hInstance     = hInstance ;
	wndclass.hIcon         = LoadIcon (NULL, IDI_APPLICATION) ;
	wndclass.hCursor       = LoadCursor (NULL, IDC_ARROW) ;
	wndclass.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH) ;
	wndclass.lpszMenuName  = NULL ;
	wndclass.lpszClassName = szAppName ;
	wndclass.hIconSm       = LoadIcon (NULL, IDI_APPLICATION) ;

	RegisterClassEx (&wndclass) ;

	hwnd = CreateWindow ((szAppName), ("ֳנאפû!"), WS_OVERLAPPEDWINDOW, 0, 0, 1366, 768, NULL, NULL, hInstance, NULL) ;		             // creation parameters

	ShowWindow (hwnd, iCmdShow) ;
	UpdateWindow (hwnd) ;

	while (GetMessage (&msg, NULL, 0, 0))
	{
		TranslateMessage (&msg) ;
		DispatchMessage (&msg) ;
	}
	return msg.wParam ;
}

int n = 12, O = 0;;
double *x = new double[n], *y = new double[n], e = 3.1415;
LRESULT CALLBACK WndProc (HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC         hdc ;
	PAINTSTRUCT ps ;
	RECT        rect ;
	HBRUSH      hBrush;
	HPEN        hPen;
	static double fi = 3.1415;
	static int k1, q = -1;
	static char number[5];

	static double x1, x2, click_x, click_y;
	if (!O)
	{
		for (int j = n; j>= 1; j--)
		{
			x[j] = 1366/2 + 160 * cos(e) *1.6;
			y[j] = 768/2 - 160 * sin(e) *1.6;
			e += (3.1415 * 2) / n;
		}
		O++;
	}




	switch (iMsg)
	{
	case WM_SIZE :
		GetClientRect(hwnd, &rect);
		break;
	case WM_PAINT :
		hdc = BeginPaint (hwnd, &ps) ;
		for (int i = n; i >= 1; i--)
		{
			if (i == q) 
			{
				hBrush = CreateSolidBrush(RGB(255, 140, 0));
				SelectObject(hdc, hBrush);
				Ellipse(hdc, x[i] - 300 / n, y[i] - 300 / n, x[i] + 300 / n, y[i] + 300 / n);
				DeleteObject(hBrush);
			}
			else
				Ellipse(hdc, x[i] - 300 / n, y[i] - 300 / n, x[i] + 300 / n, y[i] + 300 / n);

			itoa(i, number, 10);
			TextOut(hdc, x[i] + 5, y[i] + 5, number, strlen(number));
		}
		for (int k = n; k >= 1; k--)
			for (int r = n; r >= 1; r--)
			{
				hPen=CreatePen(2, 2, RGB(139, 0, 139));
				SelectObject(hdc, hPen);
				MoveToEx(hdc, x[k], y[k], NULL);
				LineTo(hdc, x[r], y[r]);
				DeleteObject(hPen);
			}

			EndPaint (hwnd, &ps) ;
			break;

	case WM_MOUSEMOVE: 
		{
			char s[300];
			int xx = LOWORD(lParam);
			int yy = HIWORD(lParam); 
			itoa(xx, s, 10);
			strcat(s, " - ");
			char ss[100];
			itoa(yy, ss, 10);
			strcat(s, ss);
			SetWindowText(hwnd, s);
			strcat(s, " - ");
			if (k1)
			{
				x[q] = LOWORD(lParam);
				itoa(x[q], ss, 10);
				strcat(s, ss);
				strcat(s, " - ");

				y[q] = HIWORD(lParam);
				itoa(y[q], ss, 10);
				strcat(s, ss);
				SetWindowText(hwnd, s);

				InvalidateRect(hwnd, NULL, TRUE); 
			} 
		}
		break;					  

	case WM_LBUTTONDOWN:
		for (int i = n; i >= 1; i--)
			if (x[i] - 300 / n < click_x && click_x <  x[i] + 300 / n && y[i] - 300 < click_y && click_y < y[i] + 300 / n) MessageBeep(MB_ICONEXCLAMATION);
		click_x = LOWORD(lParam);
		click_y = HIWORD(lParam);
		for (int i = n; i >= 1; i--)
			if (x[i] - 300 / n < click_x && click_x <  x[i] + 300 / n && y[i] - 300 < click_y && click_y < y[i] + 300 / n)
			{
				q = i;
				k1++;
				break;
			}
			break;


	case WM_LBUTTONUP:
		//if (x1-20<click_x && click_x<x1+20 && y1-20<click_y && click_y<y1+20) MessageBeep(MB_ICONASTERISK);
		k1 = 0;

		break;


	case WM_DESTROY :
		PostQuitMessage (0) ;
		break;
	}

	return DefWindowProc (hwnd, iMsg, wParam, lParam) ;
}
