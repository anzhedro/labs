#include <windows.h>

#define ID_WorkWithBooks      1 
#define ID_WorkWithStudents   2
#define ID_OutBooks           3
#define ID_WorkWithBlack      4
#define ID_EXIT               5
#define ID_OKd                6


LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL InitApplication(HINSTANCE  hInstance);
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);

LPCSTR szClassName = "WinAPI";
LPCSTR szTitle =	 "«Библиотека кафедры»";

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
	wc.hbrBackground = (HBRUSH) (COLOR_3DFACE-4);
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
		150,
		50,
		900,
		600,
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

HWND         Hwnd[30];

void BACK()
{
	ShowWindow(Hwnd[1], SW_SHOW);
	ShowWindow(Hwnd[2], SW_SHOW);
	ShowWindow(Hwnd[3], SW_SHOW);
	ShowWindow(Hwnd[4], SW_SHOW);
	ShowWindow(Hwnd[6], SW_HIDE);
	ShowWindow(Hwnd[7], SW_HIDE);
	ShowWindow(Hwnd[8], SW_HIDE);
	ShowWindow(Hwnd[9], SW_HIDE);
	ShowWindow(Hwnd[10], SW_HIDE);
	ShowWindow(Hwnd[11], SW_HIDE);
	ShowWindow(Hwnd[12], SW_HIDE);
	ShowWindow(Hwnd[13], SW_HIDE);
	ShowWindow(Hwnd[14], SW_HIDE);
	ShowWindow(Hwnd[15], SW_HIDE);
	ShowWindow(Hwnd[16], SW_HIDE);
	ShowWindow(Hwnd[17], SW_HIDE);
	ShowWindow(Hwnd[18], SW_HIDE);
	ShowWindow(Hwnd[19], SW_HIDE);
	ShowWindow(Hwnd[20], SW_HIDE);
	ShowWindow(Hwnd[21], SW_HIDE);
	ShowWindow(Hwnd[22], SW_HIDE);
	ShowWindow(Hwnd[23], SW_HIDE);
	ShowWindow(Hwnd[24], SW_HIDE);
	ShowWindow(Hwnd[0] , SW_HIDE);
	ShowWindow(Hwnd[25], SW_HIDE);
	ShowWindow(Hwnd[26], SW_HIDE);
	ShowWindow(Hwnd[27], SW_HIDE);
	ShowWindow(Hwnd[28], SW_HIDE);
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC          hdc;
	PAINTSTRUCT  ps;
	RECT         rect;
	static int   me, ok, X, Y, KEY, VAL, number;
	static char  Str[10], Auto[10], Name[10], Cost[10], NumberOfBooks[10], CostOfBooks[10];

	switch(message)
	{
	case WM_CREATE:
		//////////////////////////////Главное меню
		Hwnd[0] = CreateWindow("button", "<< Назад >>", WS_CHILD|BS_DEFPUSHBUTTON,
			20, 460, 150, 40, hwnd, (HMENU)0, NULL, NULL);
		Hwnd[1] = CreateWindow("button", "Книги >>", WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,
			20, 80,	150, 40, hwnd, (HMENU)ID_WorkWithBooks, NULL, NULL);
		Hwnd[2] = CreateWindow("button", "Студенты >>", WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,
			20, 120,	150, 40, hwnd, (HMENU)ID_WorkWithStudents, NULL, NULL);
		Hwnd[3] = CreateWindow("button", "Выдача книг >>", WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,
			20, 160, 150, 40, hwnd, (HMENU)ID_OutBooks, NULL, NULL);
		Hwnd[4] = CreateWindow("button", "Черный список >>", WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,
			20, 200, 150, 40, hwnd, (HMENU)ID_WorkWithBlack, NULL, NULL);
		Hwnd[5] = CreateWindow("button", "<< Выход >>", WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,
			20, 500, 150, 40, hwnd, (HMENU)ID_EXIT, NULL, NULL);
		//////////////////////////////Работа с книгами
		Hwnd[6] = CreateWindow("button",  "1.1 Счит. книги из файла",WS_CHILD|BS_DEFPUSHBUTTON,
			20, 80, 200, 40, hwnd, (HMENU)11, 0, NULL);
		Hwnd[7] = CreateWindow("button",  "1.2 Вывод  книг в файл",WS_CHILD|BS_DEFPUSHBUTTON,
			20, 120, 200, 40, hwnd, (HMENU)12, 0, NULL);
		Hwnd[8] = CreateWindow("button",  "1.3 Вывод книг на экран",WS_CHILD|BS_DEFPUSHBUTTON,
			20, 160, 200, 40, hwnd, (HMENU)13, 0, NULL);
		Hwnd[9] = CreateWindow("button",  "1.4 Удалить книгу",WS_CHILD|BS_DEFPUSHBUTTON,
			20, 200, 200, 40, hwnd, (HMENU)14, 0, NULL);
		Hwnd[10] = CreateWindow("button", "1.5 Удалить все книги",WS_CHILD|BS_DEFPUSHBUTTON,
			20, 240, 200, 40, hwnd, (HMENU)15, 0, NULL);
		Hwnd[11] = CreateWindow("button", "1.6 Добавить книгу",WS_CHILD|BS_DEFPUSHBUTTON,
			20, 280, 200, 40, hwnd, (HMENU)16, 0, NULL);
		Hwnd[12] = CreateWindow("button", "1.7 Вывод кол-ва книг",WS_CHILD|BS_DEFPUSHBUTTON,
			20, 320, 200, 40, hwnd, (HMENU)17, 0, NULL);
		Hwnd[13] = CreateWindow("button", "1.8 Вывод стоимости",WS_CHILD|BS_DEFPUSHBUTTON,
			20, 360, 200, 40, hwnd, (HMENU)18, 0, NULL);
		Hwnd[14] = CreateWindow("button", "1.9 Сортиковка по автору",WS_CHILD|BS_DEFPUSHBUTTON,
			20, 400, 200, 40, hwnd, (HMENU)19, 0, NULL);
		//////////////////////////////Работа со студентами
		Hwnd[15] = CreateWindow("button", "2.1 Счит. студ. из файла",WS_CHILD|BS_DEFPUSHBUTTON,
			20, 80, 200, 40, hwnd, (HMENU)21, 0, NULL);
		Hwnd[16] = CreateWindow("button", "2.2 Вывод студ. в файл",WS_CHILD|BS_DEFPUSHBUTTON,
			20, 120, 200, 40, hwnd, (HMENU)22, 0, NULL);
		Hwnd[17] = CreateWindow("button", "2.3 Вывод студ. на экран",WS_CHILD|BS_DEFPUSHBUTTON,
			20, 160, 200, 40, hwnd, (HMENU)23, 0, NULL);
		Hwnd[18] = CreateWindow("button", "2.4 Удаление студента",WS_CHILD|BS_DEFPUSHBUTTON,
			20, 200, 200, 40, hwnd, (HMENU)24, 0, NULL);
		Hwnd[19] = CreateWindow("button", "2.5 Удалить всех студентов",WS_CHILD|BS_DEFPUSHBUTTON,
			20, 240, 200, 40, hwnd, (HMENU)25, 0, NULL);
		Hwnd[20] = CreateWindow("button", "2.6 Добавить студента",WS_CHILD|BS_DEFPUSHBUTTON,
			20, 280, 200, 40, hwnd, (HMENU)26, 0, NULL);
		//////////////////////////////Выдача книг
		Hwnd[21] = CreateWindow("button", "3.1 Выдача книги", WS_CHILD|BS_DEFPUSHBUTTON,
			20, 80, 200, 40, hwnd, (HMENU)31, 0, NULL);
		Hwnd[22] = CreateWindow("button", "3.2 Возврат книги", WS_CHILD|BS_DEFPUSHBUTTON,
			20, 120, 200, 40, hwnd, (HMENU)32, 0, NULL);
		//////////////////////////////Чёрный список
		Hwnd[23] = CreateWindow("button", "4.1 Добавить в ч.с", WS_CHILD|BS_DEFPUSHBUTTON,
			20, 80, 200, 40, hwnd, (HMENU)41, 0, NULL);
		Hwnd[24] = CreateWindow("button", "4.2 Удалить из ч.с", WS_CHILD|BS_DEFPUSHBUTTON,
			20, 120, 200, 40, hwnd, (HMENU)42, 0, NULL);


		Hwnd[25] = CreateWindow("edit", "", WS_CHILD|BS_PUSHBOX,
			240, 120, 200, 20, hwnd, (HMENU)9000, 0, NULL);

		Hwnd[26] = CreateWindow("button", "OK", WS_CHILD|BS_DEFPUSHBUTTON,
			460, 120, 40, 20, hwnd, (HMENU)ID_OKd, 0, NULL);

		Hwnd[27] = CreateWindow("edit", "", WS_CHILD|BS_PUSHBOX,
			240, 160, 200, 20, hwnd, (HMENU)9001, 0, NULL);

		Hwnd[28] = CreateWindow("edit", "", WS_CHILD|BS_PUSHBOX,
			240, 200, 200, 20, hwnd, (HMENU)9002, 0, NULL);





		me = 0;
		ok = 0;
		X = 0;
		Y = 0;
		KEY = VAL = 0;
		number = 0;


		break;

	case WM_COMMAND:
		switch(LOWORD(wParam)) 
		{
			////////////////////////////////////////Главное меню
		case ID_WorkWithBooks:
			me = 1;
			ShowWindow(Hwnd[1], SW_HIDE);
			ShowWindow(Hwnd[2], SW_HIDE);
			ShowWindow(Hwnd[3], SW_HIDE);
			ShowWindow(Hwnd[4], SW_HIDE);
			ShowWindow(Hwnd[6], SW_SHOW);
			ShowWindow(Hwnd[7], SW_SHOW);
			ShowWindow(Hwnd[8], SW_SHOW);
			ShowWindow(Hwnd[9], SW_SHOW);
			ShowWindow(Hwnd[10], SW_SHOW);
			ShowWindow(Hwnd[11], SW_SHOW);
			ShowWindow(Hwnd[12], SW_SHOW);
			ShowWindow(Hwnd[13], SW_SHOW);
			ShowWindow(Hwnd[14], SW_SHOW);
			ShowWindow(Hwnd[0], SW_SHOW);
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		case ID_WorkWithStudents:
			me = 2;
			ShowWindow(Hwnd[1], SW_HIDE);
			ShowWindow(Hwnd[2], SW_HIDE);
			ShowWindow(Hwnd[3], SW_HIDE);
			ShowWindow(Hwnd[4], SW_HIDE);
			ShowWindow(Hwnd[15], SW_SHOW);
			ShowWindow(Hwnd[16], SW_SHOW);
			ShowWindow(Hwnd[17], SW_SHOW);
			ShowWindow(Hwnd[18], SW_SHOW);
			ShowWindow(Hwnd[19], SW_SHOW);
			ShowWindow(Hwnd[20], SW_SHOW);
			ShowWindow(Hwnd[0], SW_SHOW);
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		case ID_OutBooks:
			me = 3;
			ShowWindow(Hwnd[1], SW_HIDE);
			ShowWindow(Hwnd[2], SW_HIDE);
			ShowWindow(Hwnd[3], SW_HIDE);
			ShowWindow(Hwnd[4], SW_HIDE);
			ShowWindow(Hwnd[21], SW_SHOW);
			ShowWindow(Hwnd[22], SW_SHOW);
			ShowWindow(Hwnd[0], SW_SHOW);
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		case ID_WorkWithBlack: 
			me = 4;
			ShowWindow(Hwnd[1], SW_HIDE);
			ShowWindow(Hwnd[2], SW_HIDE);
			ShowWindow(Hwnd[3], SW_HIDE);
			ShowWindow(Hwnd[4], SW_HIDE);
			ShowWindow(Hwnd[23], SW_SHOW);
			ShowWindow(Hwnd[24], SW_SHOW);
			ShowWindow(Hwnd[0], SW_SHOW);
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		case 0:      // Кнопка Назад
			me = 0;
			BACK();
			InvalidateRect(hwnd, NULL, TRUE);
			break;
			/////////////////////////////////////////Обработка кнопок в 1 пункте
		case 11:
			ShowWindow(Hwnd[25], SW_HIDE);
			ShowWindow(Hwnd[26], SW_HIDE);
			ShowWindow(Hwnd[27], SW_HIDE);
			ShowWindow(Hwnd[28], SW_HIDE);
			                 // Тут чтение книг из файла
			InvalidateRect(hwnd, NULL, TRUE);
			MessageBox(hwnd, "Успех", "Успех", MB_OK|MB_ICONQUESTION);
			break;
		case 12:
			ShowWindow(Hwnd[25], SW_HIDE);
			ShowWindow(Hwnd[26], SW_HIDE);
			ShowWindow(Hwnd[27], SW_HIDE);
			ShowWindow(Hwnd[28], SW_HIDE);
			                    // Тут вывод книг в файл
			InvalidateRect(hwnd, NULL, TRUE);
			MessageBox(hwnd, "Успех", "Успех", MB_OK|MB_ICONQUESTION);			
			break;
		case 13:
			ShowWindow(Hwnd[25], SW_HIDE);
			ShowWindow(Hwnd[26], SW_HIDE);
			ShowWindow(Hwnd[27], SW_HIDE);
			ShowWindow(Hwnd[28], SW_HIDE);
			     //Тут вывод всеъ книг на экран
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		case 14:
			KEY = VAL = 14; // Выведет текст на удаление и если нажмут ОК перейдет к обработке OK
			ShowWindow(Hwnd[25], SW_SHOW);
			ShowWindow(Hwnd[26], SW_SHOW);
			ShowWindow(Hwnd[27], SW_HIDE);
			ShowWindow(Hwnd[28], SW_HIDE);
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		case 15:
			ShowWindow(Hwnd[25], SW_HIDE);
			ShowWindow(Hwnd[26], SW_HIDE);
			ShowWindow(Hwnd[27], SW_HIDE);
			ShowWindow(Hwnd[28], SW_HIDE);
			InvalidateRect(hwnd, NULL, TRUE);
			if (IDYES == MessageBox(hwnd, "Вы уверены, что хотите удалить все книги?", "Удалить все!", MB_YESNO|MB_ICONQUESTION))
			{
				// тут функция удаления всех книг
			}
			break;
		case 16: // Добавление книги
			ShowWindow(Hwnd[25], SW_SHOW);
			ShowWindow(Hwnd[26], SW_SHOW);
			ShowWindow(Hwnd[27], SW_SHOW);
			ShowWindow(Hwnd[28], SW_SHOW);
			InvalidateRect(hwnd, NULL, TRUE);
			KEY = VAL = 16;
			break;
		case 17: // Количество книг
			ShowWindow(Hwnd[25], SW_HIDE);
			ShowWindow(Hwnd[26], SW_HIDE);
			ShowWindow(Hwnd[27], SW_HIDE);
			ShowWindow(Hwnd[28], SW_HIDE);
			KEY = 17;
			itoa(0, NumberOfBooks, 10); // Вместо 0 количество книг
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		case 18: // Стоимость всех книг
			ShowWindow(Hwnd[25], SW_HIDE);
			ShowWindow(Hwnd[26], SW_HIDE);
			ShowWindow(Hwnd[27], SW_HIDE);
			ShowWindow(Hwnd[28], SW_HIDE);
			KEY = 18;
			itoa(0, CostOfBooks, 10);  //Вместо 0 общая цена книг
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		case 19:  // Сортировка по автору
			ShowWindow(Hwnd[25], SW_HIDE);
			ShowWindow(Hwnd[26], SW_HIDE);
			ShowWindow(Hwnd[27], SW_HIDE);
			ShowWindow(Hwnd[28], SW_HIDE);
			InvalidateRect(hwnd, NULL, TRUE);
			//здесь функция сортировки по атору
			MessageBox(hwnd, "Отсортировано!", "Успех", MB_OK|MB_ICONQUESTION);
			break;
			/////////////////////////////////////////////Обработка кнопок в 2 пункте
		case 21:
			ShowWindow(Hwnd[25], SW_HIDE);
			ShowWindow(Hwnd[26], SW_HIDE);
			ShowWindow(Hwnd[27], SW_HIDE);
			// Чтение студентов из файла
			InvalidateRect(hwnd, NULL, TRUE);
			MessageBox(hwnd, "Успех", "Успех", MB_OK|MB_ICONQUESTION);
			break;
		case 22:
			ShowWindow(Hwnd[25], SW_HIDE);
			ShowWindow(Hwnd[26], SW_HIDE);
			ShowWindow(Hwnd[27], SW_HIDE);
			// Вывод студентов в файл
			InvalidateRect(hwnd, NULL, TRUE);
			MessageBox(hwnd, "Успех", "Успех", MB_OK|MB_ICONQUESTION);
			break;
		case 23:
			ShowWindow(Hwnd[25], SW_HIDE);
			ShowWindow(Hwnd[26], SW_HIDE);
			ShowWindow(Hwnd[27], SW_HIDE);
			// Вывод студентов на экран
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		case 24:
			KEY = VAL = 24; // Выведет текст на удаление и если нажмут ОК перейдет к обработке OK
			ShowWindow(Hwnd[25], SW_SHOW);
			ShowWindow(Hwnd[26], SW_SHOW);
			ShowWindow(Hwnd[27], SW_HIDE);
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		case 25:
			ShowWindow(Hwnd[25], SW_HIDE);
			ShowWindow(Hwnd[26], SW_HIDE);
			ShowWindow(Hwnd[27], SW_HIDE);
			InvalidateRect(hwnd, NULL, TRUE);
			if (IDYES == MessageBox(hwnd, "Вы уверены, что хотите удалить всех студентов?", "Удалить всеч!", MB_YESNO|MB_ICONQUESTION))
			{
				// Тут функция удаления всех студентов
			}
			break;
		case 26:                   // Добавление студента
			ShowWindow(Hwnd[25], SW_SHOW);
			ShowWindow(Hwnd[26], SW_SHOW);
			ShowWindow(Hwnd[27], SW_SHOW);
			InvalidateRect(hwnd, NULL, TRUE);
			KEY = VAL = 26;
			break;
			/////////////////////////////////////////////Выдача книг
		case 31:                   // Выдача книги
			ShowWindow(Hwnd[25], SW_SHOW);
			ShowWindow(Hwnd[26], SW_SHOW);
			ShowWindow(Hwnd[27], SW_SHOW);
			InvalidateRect(hwnd, NULL, TRUE);
			KEY = VAL = 31;
			break;
		case 32:                   // Возврат книги
			ShowWindow(Hwnd[25], SW_SHOW);
			ShowWindow(Hwnd[26], SW_SHOW);
			ShowWindow(Hwnd[27], SW_SHOW);
			InvalidateRect(hwnd, NULL, TRUE);
			KEY = VAL = 32;
			break;
			////////////////////////////////////////////Чёрный список
		case 41:                   // Удаление студента
			ShowWindow(Hwnd[25], SW_SHOW);
			ShowWindow(Hwnd[26], SW_SHOW);
			ShowWindow(Hwnd[27], SW_SHOW);
			InvalidateRect(hwnd, NULL, TRUE);
			KEY = VAL = 41;
			break;
		case 42:                   // Удаление студента
			ShowWindow(Hwnd[25], SW_SHOW);
			ShowWindow(Hwnd[26], SW_SHOW);
			ShowWindow(Hwnd[27], SW_SHOW);
			InvalidateRect(hwnd, NULL, TRUE);
			KEY = VAL = 42;
			break;


			////////////////////////////////////Обработка кнопки OK

		case ID_OKd:
			switch (VAL)
			{
			case 14:
				{
					GetDlgItemText(hwnd, 9000, Str, 4);                 // в Str находится введенное значение
					itoa(number, Str, 10);
					 // Удаление книги c номером number
					MessageBox(hwnd, "Книга удалена!", "Успех!", MB_OK|MB_ICONQUESTION);
					break;
				}
			case 16:
				{
					GetDlgItemText(hwnd, 9000, Auto, 9);
					GetDlgItemText(hwnd, 9001, Name, 9);
					GetDlgItemText(hwnd, 9002, Cost, 9);
					// 3 параметра в функции - добавление книги
					MessageBox(hwnd, "Книга успешно добавлена!", "Успех!", MB_OK|MB_ICONQUESTION);
					break;
				}
			case 24:
				{
					GetDlgItemText(hwnd, 9000, Str, 9);                 // в Str находится введенное значение
					itoa(number, Str, 10);
					// Удаление студента number
					MessageBox(hwnd, "Студент удален!", "Успех!", MB_OK|MB_ICONQUESTION);
					break;
				}
			case 26:
				{
					GetDlgItemText(hwnd, 9000, Auto, 9);
					GetDlgItemText(hwnd, 9002, Cost, 9);
					// 2 параметра в функции - добавление студента, Auto = фамилия, Cost = номер зачетки
					MessageBox(hwnd, "Студент успешно добавлен!", "Успех!", MB_OK|MB_ICONQUESTION);
					break;
				}
			case 31:
				{
					GetDlgItemText(hwnd, 9000, Auto, 9);
					GetDlgItemText(hwnd, 9002, Cost, 9);
					 //  параметра в функции - выдача книги, Auto = фамилия, Cost = Книга
					// Тут я хз сколько параметров так что я сделал 2
					MessageBox(hwnd, "Книга выдана!", "Успех!", MB_OK|MB_ICONQUESTION);
					break;
				}
			case 41:
				{
					GetDlgItemText(hwnd, 9000, Auto, 9);
					GetDlgItemText(hwnd, 9002, Cost, 9);
					//  2 параметра в функции - ч.с добавить, Auto = фамилия, Cost = номер зачетки
					MessageBox(hwnd, "Студент добавлен в ч.с.!", "Успех!", MB_OK|MB_ICONQUESTION);
					break;
				}
			case 42:
				{
					GetDlgItemText(hwnd, 9000, Auto, 9);
					GetDlgItemText(hwnd, 9002, Cost, 9);
					// 2 параметра в функции - ч.с. удалить, Auto = фамилия, Cost = номер зачетки
					MessageBox(hwnd, "Студент удален из ч.с.!", "Успех!", MB_OK|MB_ICONQUESTION);
					break;
				}
			}
			VAL = 0;
			break;

		case ID_EXIT:
			if (IDYES == MessageBox(hwnd, "Вы уверены?", "Exit", MB_YESNO|MB_ICONQUESTION))
			{
				SendMessage(hwnd,WM_DESTROY,NULL,NULL);
			}
			break;
		}
	case WM_PAINT:
		hdc = BeginPaint(hwnd,&ps);

		GetClientRect(hwnd, &rect);
		SetBkMode(hdc, TRANSPARENT);
		DrawText(hdc, szTitle, -1, &rect, DT_CENTER);

		switch (me) 
		{
		case 0:
			TextOut(hdc, 20, 60, "Главное меню:", 13);
			break;
		case 1:
			TextOut(hdc, 20, 60, "Работа с книгами:", 17);
			break;
		case 2:
			TextOut(hdc, 20, 60, "Работа со студентами:", 21);
			break;
		case 3:
			TextOut(hdc, 20, 60, "Выдача книг:", 12);
			break;
		case 4:
			TextOut(hdc, 20, 60, "Работа с чёрным списком:", 24);
			break;
		}

		switch (KEY) 
		{
		case 14:
			TextOut(hdc, 240, 90, "Введите номер книги которую вы хотите удалить:", 46);
			KEY = 0;
			break;
		case 16:
			TextOut(hdc, 240, 100, "Автор:", 6);
			TextOut(hdc, 240, 140, "Название:", 9);
			TextOut(hdc, 240, 180, "Цена:", 5);
			KEY = 0;
			break;
		case 17:
			TextOut(hdc, 240, 90, "Общее количество книг:", 22);
			TextOut(hdc, 420, 90, NumberOfBooks, strlen(NumberOfBooks));
			KEY = 0;
			break;
		case 18:
			TextOut(hdc, 240, 90, "Общая стоимость книг:", 21);
			TextOut(hdc, 410, 90, CostOfBooks, strlen(CostOfBooks));
			KEY = 0;
			break;
		case 24:
			TextOut(hdc, 240, 90, "Введите номер студента которого вы хотите удалить:", 50);
			KEY = 0;
			break;
		case 26:
			TextOut(hdc, 240, 100, "Фамилия:", 8);
			TextOut(hdc, 240, 140, "Номер зачетки:", 14);
			KEY = 0;
			break;
		case 31:
			TextOut(hdc, 240, 100, "Фамилия:", 8);
			TextOut(hdc, 240, 140, "Название книги:", 15);
			KEY = 0;
			break;
		case 32:
			TextOut(hdc, 240, 100, "Фамилия:", 8);
			TextOut(hdc, 240, 140, "Название книги:", 15);
			KEY = 0;
			break;
		case 41:
			TextOut(hdc, 240, 100, "Фамилия:", 8);
			TextOut(hdc, 240, 140, "Номер зачетки:", 14);
			KEY = 0;
			break;
		case 42:
			TextOut(hdc, 240, 100, "Фамилия:", 8);
			TextOut(hdc, 240, 140, "Номер зачетки:", 14);
			KEY = 0;
			break;

		}


		EndPaint(hwnd, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}