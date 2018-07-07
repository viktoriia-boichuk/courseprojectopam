#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <malloc.h>
#include <ctype.h>
#include "functions.h"

// Очищення екрану
void cleaning()
{
    if (_getch())
        system("cls");
}

// Порядкове зчитування файлу допомоги
void help(int request)
{
    FILE* file = fopen(help_doc, "r");
    char help [35][85];
    for (int number = 0; number < 35; number++)
        fgets(help[number], 85, file);
    // В залежності від отриманого параметру викликає відповідну довідку
    switch(request) {
        //Якщо отримано код допомоги про додавання, виводяться рядки з 0 до 19-го
        case HELP_REQUEST_ADD:
             for (int number = 0; number < 19; number++)
                 printf ("%s", help[number]);
             cleaning();
             break;
        //Якщо отримано код допомоги про редагування, виводяться рядки з 20 до 28-й
        case HELP_REQUEST_EDIT:
             for (int number = 20; number < 28; number++)
                 printf ("%s", help[number]);
             cleaning();
             break;
        //Якщо отримано код допомоги про видалення, виводяться рядки з 29 по 35-й
        case HELP_REQUEST_DELETE:
             for (int number = 29; number < 35; number++)
                 printf ("%s", help[number]);
             cleaning();
             break;
    }
    fclose(file);
}

void print_row ()
{
    printf("+-----+----------------------------------------+--------------------+-----------+----------+\n");
}

void print_head ()
{
    print_row();
    printf("|  №  |                  Домен                 |      Категорія     | Кількість | PAGERANK |\n");
    printf("| п/п |                                        |                    |відвідувань|          |\n");
    print_row();
}

int go_to_menu()
{
    printf("Якщо дану операцію обрано випадково, натисніть клавішу BackSpace\n");
    printf("Для отримання довідки натисніть F1\n");
    printf("Для продовження натисніть будь-яку іншу клавішу\n");
    int button = _getch();
    if (button == 0)
        button = _getch();
    system("cls");
    //Натиснуто BACKSPACE - повернення до меню
    switch (button) {
        case BACKSPACE:
            return 1;
            break;
    //Натиснуто F1 - виклик допомоги
        case F1:
            help(HELP_REQUEST_ADD);
            return 0;
            break;
        default: return 0; break;
    }
}

//Функція видруковування головного меню
void print_main_menu(int point_number)
{
    printf("Оберіть необхідну дію:\n");
    if (point_number == 1) printf("-> "); else printf ("   ");
    printf("вивести таблицю\n");
    if (point_number == 2) printf("-> "); else printf ("   ");
    printf("ввести дані на початок файлу\n");
    if (point_number == 3) printf("-> "); else printf ("   ");
    printf("ввести дані в кінець файлу\n");
    if (point_number == 4) printf("-> "); else printf ("   ");
    printf("відсортувати дані за іменем по алфавіту\n");
    if (point_number == 5) printf("-> "); else printf ("   ");
    printf("редагувати дані про сайт\n");
    if (point_number == 6) printf("-> "); else printf ("   ");
    printf("видалити дані про сайт\n");
    if (point_number == 7) printf("-> "); else printf ("   ");
    printf("вибірка\n");
    if (point_number == 8) printf("-> "); else printf ("   ");
    printf("змінити колір тексту/фону\n");
    if (point_number == 9) printf("-> "); else printf ("   ");
    printf("вихід\n\n");
}

//Функція видруковування меню вибірок
void print_selection_menu(int point_number)
{
    printf("Оберіть необхідну вибірку:\n");
    if (point_number == 1) printf("-> "); else printf ("   ");
    printf("сайти з рейтингом понад 0.5\n");
    if (point_number == 2) printf("-> "); else printf ("   ");
    printf("сайти на доменах “ua” та “com”\n");
    if (point_number == 3) printf("-> "); else printf ("   ");
    printf("середній рейтинг та середня кількість відвідувань за день\n");
    if (point_number == 4) printf("-> "); else printf ("   ");
    printf("сайти на домені “ua” з рейтингом PR понад 0.7\n");
    if (point_number == 5) printf("-> "); else printf ("   ");
    printf("сайти категорії “blog”\n");
    if (point_number == 6) printf("-> "); else printf ("   ");
    printf("сайти з кількістю відвідувань понад 50\n");
    if (point_number == 7) printf("-> "); else printf ("   ");
    printf("сайт з найбільшим рейтингом\n");
    if (point_number == 8) printf("-> "); else printf ("   ");
    printf("головне меню\n\n");
}

//Функція видруковування меню кольорів
void print_color_menu(int point_number)
{
    printf("Оберіть поєднання фону і кольору:\n");
    if (point_number == 1) printf("-> "); else printf ("   ");
    printf("чорно-сірий (стандартно)\n");
    if (point_number == 2) printf("-> "); else printf ("   ");
    printf("чорно-білий\n");
    if (point_number == 3) printf("-> "); else printf ("   ");
    printf("синьо-білий\n");
    if (point_number == 4) printf("-> "); else printf ("   ");
    printf("зелено-білий\n");
    if (point_number == 5) printf("-> "); else printf ("   ");
    printf("фіолетово-білий\n");
    if (point_number == 6) printf("-> "); else printf ("   ");
    printf("бордово-білий\n");
    if (point_number == 7) printf("-> "); else printf ("   ");
    printf("сіро-білий\n");
    if (point_number == 8) printf("-> "); else printf ("   ");
    printf("біло-чорний\n");
    if (point_number == 9) printf("-> "); else printf ("   ");
    printf("головне меню\n\n");
}

//Функція для переключення і вибору пункту меню
int choise(int mode, int points_amount)
{
    int button, point_number = 1;
    do {
        printf("Переключення за допомогою стрілок вверх і вниз\n");
        printf("Вибір за допомогою клавіші Enter\n\n");
        switch (mode){
            case 0: print_main_menu(point_number); break;
            case 1: print_selection_menu(point_number); break;
            case 2: print_color_menu(point_number); break;
        }
        button = getch();
        system("cls");
        // Перевірка натиснутої клавіші та виконання відповідної дії
        switch(button) {
            case UP_ARROW: point_number--; break;
            case DOWN_ARROW: point_number++; break;
            case ENTER: system("cls"); return point_number; break;
        }
        //Повернення на початок чи в кінець списку,
        //якщо номер пункту виходить за допустимі межі
        if(point_number > points_amount)
            point_number = 1;
        else if (point_number < 1)
            point_number = points_amount;
    }
    while(1);//безкінечний цикл
    return 0;
}

//Перетворення символів в рядку (другий параметр - що треба замінити, третій - на що)
void turn (char* str, char symbol_1, char symbol_2)
{
    int number = 0;
    while (str[number] != '\0'){
        if (str[number] == symbol_1)
            str[number] = symbol_2;
            number++;
        }
}

//Зчитування з файлу
int reading(WEBSITE* p, int number)
{
    FILE* file = fopen(data, "r");
    while (!feof(file)){
        fscanf(file, "%s", p[number].DOMAIN);
        fscanf(file, "%s", p[number].CATEGORY);
        //Заміна "прочерку" на "пробіл"
        turn(p[number].CATEGORY, '_', ' ');
        fscanf(file,"%d", &p[number].AMOUNT);
        fscanf(file,"%f", &p[number].PAGERANK);
        number++;
        //Динамічне виділення пам'яті на наступний елемент
        p = (WEBSITE*)realloc(p, (number + 1) * sizeof(WEBSITE));
    }
    fclose(file);
    return number;
}

//Занесення у файл одного запису
void input_in_file(FILE* file, WEBSITE* p, int number)
{
	fprintf(file, "%s\n", p[number].DOMAIN);
    //Заміна "пробілу" на "прочерк"
	turn(p[number].CATEGORY, ' ', '_');
	fprintf(file, "%s\n", p[number].CATEGORY);
	fprintf(file,"%d\n", p[number].AMOUNT);
	fprintf(file,"%f\n", p[number].PAGERANK);
}

//Видруковування помилок. В якості параметру виступає код помилки
void error_messages (int code)
{
    switch(code){
        case 1: printf("\aВведено недопустимі для даного поля дані!");
                Sleep(2200);
                printf("\r%50c \rСпробуйте ввести ще раз: ", ' ');
                break;
        case 2: printf("\aЧисло не входить у задані межі!");
                Sleep(2200);
                printf("\r%50c \rСпробуйте ввести ще раз: ", ' ');
                break;
        case 3: printf("\aНе введено жодних даних!");
                Sleep(2200);
                printf("\r%50c \rСпробуйте ввести ще раз: ", ' ');
                break;
        case 4: printf("\aСписок веб-сайтів порожній!");
                cleaning();
                break;
        case 5: printf("Введено забагато символів!");
                Sleep(2200);
                printf("\r%30c \rСпробуйте ввести ще раз: ", ' ');
                break;
    }
}

//Перевірка, чи файл не порожній
int empty_file ()
{
    FILE* file = fopen(data, "r");
    fseek(file, 0, SEEK_END);
    if (ftell(file)){
        fclose(file);
        return 0;
    }
    else {
        fclose(file);
        error_messages(4);
        return 1;
    }
}

//Перевірка введеної інформації на відповідність розміру поля
void check_length (char* field, unsigned int max_length)
{
    char str[100];
    int correct_length = 0;
    do {
        gets(str);
        if ((str[0] == '\0') || (isspace(str[0])))
            error_messages(3);
        else if(strlen(str) < max_length)
            correct_length = 1;
        else error_messages(5);
    }
    while(!correct_length);
    strcpy(field, str);
}

//Відокремлення домену верхнього рівня
void last_domain (char* str, char* word1)
{
    //В буфер копіюється значення поля
    char  buffer[DOMAIN_LENGHT], * part, * word = NULL;
    int elements_amount = 0, number = 0;
    //Цикл до кінця рядка
    while (str[number] != '\0'){
        if (str[number] == '.')
            elements_amount++;
        number++;
    }
    //Якщо є хоч одна крапка, виконується умова
    if (elements_amount){
        strcpy(buffer, str);
        part = strtok(buffer, "." );
        while (part != NULL){
            part = strtok(NULL, ".");
            if(part != NULL)
                word = part;
        }
        strcpy(word1, word);
    }
    else word1 = NULL;
}

//Перевірка домену на правильність введення
void check_domain(char* field)
{
    char str[DOMAIN_LENGHT], word[DOMAIN_LENGHT];
    int number, elements_amount;
    do{
        elements_amount = 0, number = 0;
        check_length (str, DOMAIN_LENGHT);
        //Перевірка на наявність крапки і відсутність зайвих символів
        do{
            if (!isalnum(str[number]) && (str[number] != '.')){
                elements_amount++;
                break;
            }
            number++;
        }
        while (str[number] != '\0');
        //Якщо немає недозволених символів тоді відділяється
        //домен верхнього рівня і перевіряється чи він символьний
        if (!elements_amount){
            number = 0;
            last_domain(str, word);
            if (word != NULL){
                do{
                    if (!isalpha(word[number])){
                        elements_amount++;
                        break;
                    }
                    number++;
                }
                while (word[number] != '\0');
            }
        }
        if (elements_amount)
            error_messages (1);
    }
    while (elements_amount != 0);
    sscanf(str, "%s", field);
}

//Перевірка поля КАТЕГОРІЯ  на правильність введення
void check_category(char* field)
{
    char str[CATEGORY_LENGHT];
    int number, elements_amount;
    do{
        elements_amount = 0, number = 0;
        check_length (str, CATEGORY_LENGHT);
        //Перевірка, чи в полі є тільки допустимі символи
        do{
            if (!isalpha(str[number]) && (!isspace(str[number]))){
                elements_amount++;
                break;
            }
            number++;
        }
        while (str[number] != '\0');
        turn(str, ' ', '_');
        if (elements_amount)
            error_messages (1);
    }
    while (elements_amount != 0);
    sscanf(str, "%s", field);
}

//Перевірка поля КІЛЬКІСТЬ ВІДВІДУВАНЬ на правильність введення
int check_amount()
{
    char str[10];
    int field, number, elements_amount;
    do{
        elements_amount = 0, number = 0;
        check_length (str, 10);
        //Перевірка, чи введено виключно число
        do{
            if (!isdigit(str[number])){
                elements_amount++;
                break;
            }
            number++;
        }
        while (str[number] != '\0');
        if (elements_amount)
            error_messages (1);
    }
    while (elements_amount != 0);
    sscanf(str, "%d", &field);
    return field;
}

//Перевірка поля ПЕЙДЖРАНК на правильність введення
float check_pagerank()
{
    char str[10];
    float field;
    int number, elements_amount;
    do{
        do{
            elements_amount = 0, number = 0;
            check_length (str, 10);
            //В цьому полі можуть бути тільки числа і крапка
            do{
                if ((!isdigit(str[number])) && (str[number] != '.')){
                    elements_amount++;
                    break;
                }
                number++;
            }
            while (str[number] != '\0');
            if (elements_amount)
                error_messages (1);
        }
        while (elements_amount != 0);
        sscanf(str, "%f", &field);
        //Поле може містити числа від 0 до 1
        if (field > 1)
            error_messages (2);
    }
    while (field > 1);
    return field;
}

//Функція введення даних
void input(int mode)
{
    //Виведення повідомлення, де знаходиться користувач
    if (mode)
        printf ("Введення даних на початок файлу\n\n");
    else printf ("Введення даних в кінець файлу\n\n");
    //У випадку, якщо функкція go_to_menu поверне одиницю, то програма не виконуватиме введення
    if (!go_to_menu()){
        WEBSITE *p = NULL;
        int length = 0;
        char answer;
        //Динамічне виділення пам'яті
        p = (WEBSITE*)realloc(p, (length + 1) * sizeof(WEBSITE));
        printf("Введіть інформацію про веб-сайт\n");
        do{
            //Очишення буферу
            _flushall();
            //Кожне поле при введенні одразу перевіряється на правильність
            printf("\nПовне доменне ім'я: ");
            check_domain(p[length].DOMAIN);
            printf("Категорія: ");
            check_category(p[length].CATEGORY);
            printf("Кількість відвідувань в день: ");
            p[length].AMOUNT = check_amount();
            printf("PageRank: ");
            p[length].PAGERANK = check_pagerank();
            length++;
            //Питання до користувача чи бажає він продовжити введення.
            //Якщо так - цикл повторюється, а якщо ні - завершується
            printf("\nБажаєте продовжити введення про інший веб-сайт?(y/n)\n");
            scanf("%c", &answer);
            if(answer != 'y')
                system("cls");
            else
                p = (WEBSITE*)realloc(p, (length + 1) * sizeof(WEBSITE));
        }
        while (answer == 'y');
        //Якщо обрано пункт "введення на початок" -
        //перезаписує у файл весь вміст, дописуючи на початок нові дані...
        if (mode){
            p = (WEBSITE*)realloc(p, (length + 1) * sizeof(WEBSITE));
            length = reading(p, length);
            FILE* file = fopen(data, "w");
            for (int number = 0; number < length - 1; number++)
                input_in_file(file, p, number);
            fclose(file);
        }
        //...якщо ж обрано "введення в кінець" -
        //дописує в кінець файлу
        else {
            FILE* file = fopen(data, "r+");
            fseek(file, 0, SEEK_END);
            for (int number = 0; number < length; number++)
                input_in_file(file, p, number);
            fclose(file);
        }
        free (p);
    }
}

//Виведення рядку даних з файлу зі стрілкою, чи без
void output_row (WEBSITE* p, int number, int arrow)
{
    if (arrow){
        printf("|%5d|%-40s", number + 1, p[number].DOMAIN);
        printf("|%-20s", p[number].CATEGORY);
        printf("|%11d", p[number].AMOUNT);
        printf("|%10f| <-\n", p[number].PAGERANK);
    }
    else {
        printf("|%5d|%-40s", number + 1, p[number].DOMAIN);
        printf("|%-20s", p[number].CATEGORY);
        printf("|%11d", p[number].AMOUNT);
        printf("|%10f|\n", p[number].PAGERANK);
    }
}

//Функція редагування
void edit (WEBSITE* p, int length, int number)
{
    int done, cancel, point_number = 0, button;
    //Зовнішній цикл, що дозволяє виконувати повторне редагування
    do{
        done = 0, cancel = 0;
        do{
            system("cls");
            //Виведення полів та стрілочки біля потрібного поля
            printf("Оберіть поле для редагування\n");
            if(point_number == 0) printf("-> "); else printf("   ");
            printf("%s\n", p[number].DOMAIN);
            if(point_number == 1) printf("-> "); else printf("   ");
            printf("%s\n", p[number].CATEGORY);
            if(point_number == 2) printf("-> "); else printf("   ");
            printf("%d\n", p[number].AMOUNT);
            if(point_number == 3) printf("-> "); else printf("   ");
            printf("%f\n", p[number].PAGERANK);
            button = getch();
            //Виконання різних операцій, в залежності від натиснутої клавіші
            switch(button) {
                //натиснуто стрілочку вверх - переміщення стрілки меню на позицію вверх...
                        case UP_ARROW:
                            point_number--;
                            if(point_number < 0)
                                point_number = 3;
                            break;
                //...та, відповідно, вниз
                        case DOWN_ARROW:
                            point_number++;
                            if(point_number > 3)
                                point_number = 0;
                            break;
                //натискання ENTER завершує внутрішній цикл з подальшим виконанням дій
                        case ENTER:
                            done = 1;
                            break;
                //натискання BACKSPACE завершує цикл та повертає у попереднє меню
                        case BACKSPACE:
                            cancel = 1;
                            break;
            }
        }
        while (!done && !cancel);
        //Якщо було натиснуто ентер...
        if(done)
        {
            system("cls");
            //...починається введення нового значення обраного стрілкою поля
            printf("Введіть нове значення: ");
            switch(point_number) {
                case 0: check_domain(p[number].DOMAIN); break;
                case 1: check_category(p[number].CATEGORY); break;
                case 2: p[number].AMOUNT = check_amount(); break;
                case 3: p[number].PAGERANK = check_pagerank(); break;
            }
            //Відкриття файлу для запису
            FILE* file = fopen(data, "w");
            //Безпосередній запис
            for(int i = 0; i < length; i++)
                input_in_file(file, p, i);
            fclose(file);
        }
        system("cls");
    }
    while (!cancel);
}

//Функція видалення запису
void deleting(WEBSITE* p, int length, int number)
{
    //Виконується перезаписування вмісту файлу БЕЗ вказаного запису
    FILE* file = fopen(data, "w");
    for(int i = 0; i < length; i++)
        if(i != number)
            input_in_file(file, p, i);
    fclose(file);
}

//Виведення таблиці даних на екран
void output_table (int mode)
{
    //Перевірка, чи файл не порожній.
    //Якщо він порожній - виводиться помилка
    if (!empty_file()){
        int cancel = 0;
        do {
            //Створення динамічного масиву і занесення в нього даних з файлу
            WEBSITE *p = NULL;
            int length = 0, row = 0;
            p = (WEBSITE*)realloc(p, (length + 1) * sizeof(WEBSITE));
            length = reading(p, length) - 1;
            system("cls");
            int pages_amount;
            //Визначення кількості сторінок. Кількість записів ділиться на кількість записів на сторінці (10)
            //Якщо ділиться не націло - друкується ще одна сторінка
            if (length % PAGE_ENTRIES)
                pages_amount = length/PAGE_ENTRIES + 1;
            else pages_amount = length/PAGE_ENTRIES;
            int first = 0, last, page = 1, button;
            do{
                //В залежності від режиму виконання функції
                //даний фрагмент виконується по-різному
                //Наявні наступні режими: звичайний, сортування, редагування та видалення
                //Редагування та видалення виконується зі стрілкою
                //звичайний та сортування відрізняються тільки заголовком та відображаються без стрілки
                switch (mode){
                    case MODE_COMMON: printf("Список веб-сайтів:\n\n");
                                      printf ("Для повернення назад натисніть Backspace\n\n");
                                      break;
                    case MODE_SORT: printf("Відсортований список веб-сайтів:\n\n");
                                    printf ("Для повернення назад натисніть Backspace\n\n");
                                    break;
                    case MODE_EDIT: printf("Редагування:\n\n");
                         printf("Натисніть F1 для виклику довідки\n\n"); break;
                    case MODE_DELETE: printf("Видалення:\n\n");
                         printf("Натисніть F1 для виклику довідки\n\n"); break;
                }
                print_head();
                //Якщо виведена сторінка є останньою
                //то номер останнього запису дорівнює загальній кількості записів...
                if (page == pages_amount)
                    last = length;
                //...інакше номер останнього запису на сторінці
                // дорівнює початковому + кількості записів на сторінці
                else last = first + PAGE_ENTRIES;
                // залежно від режиму, записи виводяться зі стрілкою, чи без
                for (int number = first; number < last; number++){
                    if ((mode == MODE_COMMON)||(mode == MODE_SORT))
                        output_row(p, number);
                    else {
                        if (number == row)
                        output_row(p, number, 1);
                        else output_row(p, number);
                    }
                }
                print_row();
                printf("%32c<-%6cСторінка %d/%d%6c->", ' ', ' ', page, pages_amount, ' ');
                button = _getch();
                system("cls");
                //Виконання дій відповідно до натиснутої клавіші
                switch(button) {
                    //Натискання стрілки вліво перемикає сторінку на попередню
                    //стрілка при цьому зміщується на початок даної сторінки
                    //номер першого запису відповідно змінюється
                    case LEFT_ARROW: page--;
                            row -= PAGE_ENTRIES;
                            first -= PAGE_ENTRIES;
                            break;
                    //Стрілка вправо виконується аналогічні дії в протилежний бік
                    case RIGHT_ARROW: page++;
                            row += PAGE_ENTRIES;
                            first += PAGE_ENTRIES;
                            break;
                    //Клавіша вверх на клавіатурі переміщає стрілку на позицію вверх...
                    case UP_ARROW: row--; break;
                    //...клавіша вниз, відповідно, переміщає вниз
                    case DOWN_ARROW: row++; break;
                    //При натисканні клавіші ентер, відповідно до режиму, в якому викликалася функція
                    //Викликається функція редагування чи видалення
                    case ENTER: if (mode == MODE_EDIT)
                                    edit(p, length, row);
                                else if (mode == MODE_DELETE)
                                    deleting(p, length, row);
                                button = BACKSPACE;
                                break;
                    //Натискання BACKSPACE завершує виконання циклу та повертає у попереднє меню
                    case BACKSPACE: cancel = 1; break;
                    //Клавіша F1 викликає відповідну допомогу
                    case F1:
                         if (mode == MODE_EDIT)
                            help(HELP_REQUEST_EDIT);
                         else if (mode == MODE_DELETE)
                            help(HELP_REQUEST_DELETE);
                         break;
                }
                //Повернення стрілки на перший елемент списку,
                //коли та виходить за межі останнього елементу
                if (row > last - 1){
                    row = first;
                }
                //Та повернення на останній, при переході за межі першого
                else if (row < first){
                    row = last - 1;
                }
                //Якщо номер поточної сторінки більший, ніж загальна кількість сторінок,
                //тоді повертає на першу...
                if (page > pages_amount){
                    page = 1;
                    first = 0;
                    row = first;
                }
                //та, відповідно, перехід на останню
                else if (page < 1){
                    page = pages_amount;
                    first = (page - 1)*PAGE_ENTRIES;
                    row = first;
                }
            }
            while (button != BACKSPACE);
            system("cls");
            free(p);
        }
        while (!cancel);
    }
}

//Функція сортування
void sorting()
{
    if (!empty_file()){
        WEBSITE *p = NULL;
        int length = 0;
        p = (WEBSITE*)realloc(p, (length + 1) * sizeof(WEBSITE));
        length = reading(p, length);
        //Безпосереднє сортування викликом вбудованої функції сортування
        qsort (p->DOMAIN, length - 1, sizeof(WEBSITE), (int (*)(const void *, const  void *)) strcmp);
        FILE* file = fopen(data, "w");
        //Перезапис відсортованих даних у файл
        for (int number = 0; number < length - 1; number++)
            input_in_file (file, p, number);
        fclose(file);
        output_table (MODE_SORT);
        free(p);
    }
}

//Вибірка: Сайти, рейтинг яких більше 0.5
void rating (WEBSITE* p, int length)
{
    float min_rating = 0.5;
    int elements_amount = 0;
    print_head();
    for (int number = 0; number < length - 1; number++)
        if (p[number].PAGERANK > min_rating){
            output_row(p, number);
            elements_amount++;
        }
    print_row();
    printf("\n\nЗагальна кількість сайтів з рейтингом понад 0.5 = %d", elements_amount);
    if (!elements_amount){
        system("cls");
        printf("\aСайтів з рейтингом понад 0.5 немає!\n");
    }
    cleaning();
}

//Вибірка: Найбільший рейтинг
void max_rating (WEBSITE* p, int length)
{
    int elements_amount = 0;
    float maximum;
    print_head();
    for (int number = 0; number < length - 1; number++){
        if (!number)
            maximum = p[number].PAGERANK;
        else if (p[number].PAGERANK > maximum)
            maximum = p[number].PAGERANK;
    }
    for (int number = 0; number < length - 1; number++)
        if (p[number].PAGERANK == maximum){
            output_row(p, number);
            elements_amount++;
        }
    print_row();
    if (elements_amount > 1)
        printf("\n\nЗагальна кількість сайтів з однаковим найбільшим рейтингом = %d", elements_amount);
    cleaning();
}

//Вибірка: кількість відвідувань, більше 50
void amount (WEBSITE* p, int length)
{
    int elements_amount = 0, min_amount = 50;
    print_head();
    for (int number = 0; number < length - 1; number++)
        if (p[number].AMOUNT > min_amount){
            output_row(p, number);
            elements_amount++;
        }
    print_row();
    printf("\n\nЗагальна кількість сайтів з кількістю відвідувань понад 50 = %d", elements_amount);
    if (!elements_amount){
        system("cls");
        printf("\aСайтів з кількістю відвідувань понад 50 немає!\n");
    }
    cleaning();
}

//Вибірка: домени ua i com
void ua_and_com (WEBSITE* p, int length)
{
    int elements_amount = 0;
    char word[50];
    print_head();
    for (int number = 0; number < length - 1; number++){
        last_domain(p[number].DOMAIN, word);
        if ((word[0]!='\0')&&(!(strcmp(word,"ua"))||!(strcmp(word,"com")))){
            output_row(p, number);
            elements_amount++;
        }
    }
    print_row();
    printf("\n\nЗагальна кількість сайтів на доменах “ua” та “com” = %d", elements_amount);
    if (!elements_amount){
        system("cls");
        printf("\aСайтів на доменах “ua” та “com” немає!\n");
    }
    cleaning();
}

//Вибірка: сайти на домені ua та рейтингом більше 0.7
void ua_and_rating (WEBSITE* p, int length)
{
    int elements_amount = 0;
    char word[50];
    float min_rating = 0.7;
    print_head();
    for (int number = 0; number < length - 1; number++){
        last_domain(p[number].DOMAIN, word);
        if ((p[number].PAGERANK > min_rating) && (word != NULL) && (!(strcmp(word,"ua")))){
            output_row(p, number);
            elements_amount++;
        }
    }
    print_row();
    printf("\n\nЗагальна кількість сайтів на домені “ua” з рейтингом PR понад 0.7 = %d", elements_amount);
    if (!elements_amount){
        system("cls");
        printf("\aСайтів на домені “ua” з рейтингом PR понад 0.7 немає!\n");
    }
    cleaning();
}

//Вибірка: середня кількість відвідувань та середній рейтинг
void average (WEBSITE* p, int length)
{
    float average_pagerank = 0, average_amount = 0;
    for (int number = 0; number < length - 1; number++){
        average_amount += p[number].AMOUNT;
        average_pagerank += p[number].PAGERANK;
    }
    average_amount /= length - 1;
    average_pagerank /= length - 1;
    printf("Серед усіх представлених сайтів:\n\n");
    printf("Середній рейтинг = %f\n",average_pagerank);
    printf("Середня кількість відвідувань за день = %f",average_amount);
    cleaning();
}

//Вибірка: сайти, з категорією "blog"
void blogs (WEBSITE* p, int length)
{
    int elements_amount = 0;
    print_head();
    for (int number = 0; number < length - 1; number++){
        if (!strcmp(p[number].CATEGORY,"blog")){
            elements_amount++;
            output_row(p, number);
        }
    }
    print_row();
    printf("\n\nЗагальна кількість сайтів категорії “blog” = %d", elements_amount);
    if (!elements_amount){
        system("cls");
        printf("\aСайтів категорії “blog” немає!\n");
    }
    cleaning();
}

//Функція вибору кольорів
void color_menu()
{
    int Menupoint;
    do{
        Menupoint = choise(2, 9);
        switch (Menupoint) {
            case 1: system("color 07"); break;//стандартний
            case 2: system("color 0f"); break;//чорно-білий
            case 3: system("color 1f"); break;//синьо-білий
            case 4: system("color 2f"); break;//зелено-білий
            case 5: system("color 5f"); break;//фіолетово-білий
            case 6: system("color 4f"); break;//бордово-білий
            case 7: system("color 8f"); break;//сіро-білий
            case 8: system("color f0"); break;//біло-чорний
            case 9: break;
        }
    }
    while (Menupoint != 9);
}

//Меню вибірок
void selection_menu()
{
    if (!empty_file()){
        int MenuPoint, length = 0;
        WEBSITE* p = NULL;
        p = (WEBSITE*)realloc(p, (length + 1) * sizeof(WEBSITE));
        length = reading(p, length);
        //Цикл, за допомогою якого здійснюється переключення між вибірками
        do{
            MenuPoint = choise(1, 8);
            switch(MenuPoint){
                case 1: rating(p, length); break;
                case 2: ua_and_com (p, length); break;
                case 3: average(p, length); break;
                case 4: ua_and_rating(p, length); break;
                case 5: blogs(p, length); break;
                case 6: amount(p, length);break;
                case 7: max_rating(p, length); break;
                case 8: break;
            }
        }
        while(MenuPoint != 8);
        free(p);
    }
}

//Функція виведення головного меню
void main_menu()
{
    int MenuPoint;
    do{
        MenuPoint = choise(0, 9);
        switch(MenuPoint){
            case 1: output_table (MODE_COMMON); break;
            case 2: input(1); break;
            case 3: input(0); break;
            case 4: sorting(); break;
            case 5: output_table (MODE_EDIT); break;
            case 6: output_table(MODE_DELETE); break;
            case 7: selection_menu(); break;
            case 8: color_menu(); break;
            case 9: printf("Роботу завершено!\n"); break;
        }
	}
	while(MenuPoint != 9);
	_getch();
}
