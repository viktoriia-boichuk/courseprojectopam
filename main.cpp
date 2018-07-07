#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include "functions.h"

int main ()
{
    //Налаштування коректного відображення кирилиці
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//Виклик головного меню програми
	main_menu();
	return 0;
}
