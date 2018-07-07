#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <malloc.h>
#include <ctype.h>
#include "functions.h"

// �������� ������
void cleaning()
{
    if (_getch())
        system("cls");
}

// ��������� ���������� ����� ��������
void help(int request)
{
    FILE* file = fopen(help_doc, "r");
    char help [35][85];
    for (int number = 0; number < 35; number++)
        fgets(help[number], 85, file);
    // � ��������� �� ���������� ��������� ������� �������� ������
    switch(request) {
        //���� �������� ��� �������� ��� ���������, ���������� ����� � 0 �� 19-��
        case HELP_REQUEST_ADD:
             for (int number = 0; number < 19; number++)
                 printf ("%s", help[number]);
             cleaning();
             break;
        //���� �������� ��� �������� ��� �����������, ���������� ����� � 20 �� 28-�
        case HELP_REQUEST_EDIT:
             for (int number = 20; number < 28; number++)
                 printf ("%s", help[number]);
             cleaning();
             break;
        //���� �������� ��� �������� ��� ���������, ���������� ����� � 29 �� 35-�
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
    printf("|  �  |                  �����                 |      ��������     | ʳ������ | PAGERANK |\n");
    printf("| �/� |                                        |                    |���������|          |\n");
    print_row();
}

int go_to_menu()
{
    printf("���� ���� �������� ������ ���������, �������� ������ BackSpace\n");
    printf("��� ��������� ������ �������� F1\n");
    printf("��� ����������� �������� ����-��� ���� ������\n");
    int button = _getch();
    if (button == 0)
        button = _getch();
    system("cls");
    //��������� BACKSPACE - ���������� �� ����
    switch (button) {
        case BACKSPACE:
            return 1;
            break;
    //��������� F1 - ������ ��������
        case F1:
            help(HELP_REQUEST_ADD);
            return 0;
            break;
        default: return 0; break;
    }
}

//������� �������������� ��������� ����
void print_main_menu(int point_number)
{
    printf("������ ��������� ��:\n");
    if (point_number == 1) printf("-> "); else printf ("   ");
    printf("������� �������\n");
    if (point_number == 2) printf("-> "); else printf ("   ");
    printf("������ ��� �� ������� �����\n");
    if (point_number == 3) printf("-> "); else printf ("   ");
    printf("������ ��� � ����� �����\n");
    if (point_number == 4) printf("-> "); else printf ("   ");
    printf("����������� ��� �� ������ �� �������\n");
    if (point_number == 5) printf("-> "); else printf ("   ");
    printf("���������� ��� ��� ����\n");
    if (point_number == 6) printf("-> "); else printf ("   ");
    printf("�������� ��� ��� ����\n");
    if (point_number == 7) printf("-> "); else printf ("   ");
    printf("������\n");
    if (point_number == 8) printf("-> "); else printf ("   ");
    printf("������ ���� ������/����\n");
    if (point_number == 9) printf("-> "); else printf ("   ");
    printf("�����\n\n");
}

//������� �������������� ���� ������
void print_selection_menu(int point_number)
{
    printf("������ ��������� ������:\n");
    if (point_number == 1) printf("-> "); else printf ("   ");
    printf("����� � ��������� ����� 0.5\n");
    if (point_number == 2) printf("-> "); else printf ("   ");
    printf("����� �� ������� �ua� �� �com�\n");
    if (point_number == 3) printf("-> "); else printf ("   ");
    printf("������� ������� �� ������� ������� ��������� �� ����\n");
    if (point_number == 4) printf("-> "); else printf ("   ");
    printf("����� �� ����� �ua� � ��������� PR ����� 0.7\n");
    if (point_number == 5) printf("-> "); else printf ("   ");
    printf("����� ������� �blog�\n");
    if (point_number == 6) printf("-> "); else printf ("   ");
    printf("����� � ������� ��������� ����� 50\n");
    if (point_number == 7) printf("-> "); else printf ("   ");
    printf("���� � ��������� ���������\n");
    if (point_number == 8) printf("-> "); else printf ("   ");
    printf("������� ����\n\n");
}

//������� �������������� ���� �������
void print_color_menu(int point_number)
{
    printf("������ �������� ���� � �������:\n");
    if (point_number == 1) printf("-> "); else printf ("   ");
    printf("�����-���� (����������)\n");
    if (point_number == 2) printf("-> "); else printf ("   ");
    printf("�����-����\n");
    if (point_number == 3) printf("-> "); else printf ("   ");
    printf("�����-����\n");
    if (point_number == 4) printf("-> "); else printf ("   ");
    printf("������-����\n");
    if (point_number == 5) printf("-> "); else printf ("   ");
    printf("���������-����\n");
    if (point_number == 6) printf("-> "); else printf ("   ");
    printf("�������-����\n");
    if (point_number == 7) printf("-> "); else printf ("   ");
    printf("���-����\n");
    if (point_number == 8) printf("-> "); else printf ("   ");
    printf("���-������\n");
    if (point_number == 9) printf("-> "); else printf ("   ");
    printf("������� ����\n\n");
}

//������� ��� ������������ � ������ ������ ����
int choise(int mode, int points_amount)
{
    int button, point_number = 1;
    do {
        printf("������������ �� ��������� ������ ����� � ����\n");
        printf("���� �� ��������� ������ Enter\n\n");
        switch (mode){
            case 0: print_main_menu(point_number); break;
            case 1: print_selection_menu(point_number); break;
            case 2: print_color_menu(point_number); break;
        }
        button = getch();
        system("cls");
        // �������� ��������� ������ �� ��������� �������� 䳿
        switch(button) {
            case UP_ARROW: point_number--; break;
            case DOWN_ARROW: point_number++; break;
            case ENTER: system("cls"); return point_number; break;
        }
        //���������� �� ������� �� � ����� ������,
        //���� ����� ������ �������� �� �������� ���
        if(point_number > points_amount)
            point_number = 1;
        else if (point_number < 1)
            point_number = points_amount;
    }
    while(1);//���������� ����
    return 0;
}

//������������ ������� � ����� (������ �������� - �� ����� �������, ����� - �� ��)
void turn (char* str, char symbol_1, char symbol_2)
{
    int number = 0;
    while (str[number] != '\0'){
        if (str[number] == symbol_1)
            str[number] = symbol_2;
            number++;
        }
}

//���������� � �����
int reading(WEBSITE* p, int number)
{
    FILE* file = fopen(data, "r");
    while (!feof(file)){
        fscanf(file, "%s", p[number].DOMAIN);
        fscanf(file, "%s", p[number].CATEGORY);
        //����� "��������" �� "�����"
        turn(p[number].CATEGORY, '_', ' ');
        fscanf(file,"%d", &p[number].AMOUNT);
        fscanf(file,"%f", &p[number].PAGERANK);
        number++;
        //�������� �������� ���'�� �� ��������� �������
        p = (WEBSITE*)realloc(p, (number + 1) * sizeof(WEBSITE));
    }
    fclose(file);
    return number;
}

//��������� � ���� ������ ������
void input_in_file(FILE* file, WEBSITE* p, int number)
{
	fprintf(file, "%s\n", p[number].DOMAIN);
    //����� "������" �� "�������"
	turn(p[number].CATEGORY, ' ', '_');
	fprintf(file, "%s\n", p[number].CATEGORY);
	fprintf(file,"%d\n", p[number].AMOUNT);
	fprintf(file,"%f\n", p[number].PAGERANK);
}

//�������������� �������. � ����� ��������� ������� ��� �������
void error_messages (int code)
{
    switch(code){
        case 1: printf("\a������� ���������� ��� ������ ���� ���!");
                Sleep(2200);
                printf("\r%50c \r��������� ������ �� ���: ", ' ');
                break;
        case 2: printf("\a����� �� ������� � ����� ���!");
                Sleep(2200);
                printf("\r%50c \r��������� ������ �� ���: ", ' ');
                break;
        case 3: printf("\a�� ������� ������ �����!");
                Sleep(2200);
                printf("\r%50c \r��������� ������ �� ���: ", ' ');
                break;
        case 4: printf("\a������ ���-����� �������!");
                cleaning();
                break;
        case 5: printf("������� �������� �������!");
                Sleep(2200);
                printf("\r%30c \r��������� ������ �� ���: ", ' ');
                break;
    }
}

//��������, �� ���� �� �������
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

//�������� ������� ���������� �� ���������� ������ ����
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

//³����������� ������ ��������� ����
void last_domain (char* str, char* word1)
{
    //� ����� ��������� �������� ����
    char  buffer[DOMAIN_LENGHT], * part, * word = NULL;
    int elements_amount = 0, number = 0;
    //���� �� ���� �����
    while (str[number] != '\0'){
        if (str[number] == '.')
            elements_amount++;
        number++;
    }
    //���� � ��� ���� ������, ���������� �����
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

//�������� ������ �� ����������� ��������
void check_domain(char* field)
{
    char str[DOMAIN_LENGHT], word[DOMAIN_LENGHT];
    int number, elements_amount;
    do{
        elements_amount = 0, number = 0;
        check_length (str, DOMAIN_LENGHT);
        //�������� �� �������� ������ � ��������� ������ �������
        do{
            if (!isalnum(str[number]) && (str[number] != '.')){
                elements_amount++;
                break;
            }
            number++;
        }
        while (str[number] != '\0');
        //���� ���� ������������ ������� ��� ����������
        //����� ��������� ���� � ������������ �� �� ����������
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

//�������� ���� ������в�  �� ����������� ��������
void check_category(char* field)
{
    char str[CATEGORY_LENGHT];
    int number, elements_amount;
    do{
        elements_amount = 0, number = 0;
        check_length (str, CATEGORY_LENGHT);
        //��������, �� � ��� � ����� �������� �������
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

//�������� ���� ʲ��ʲ��� ²�²������ �� ����������� ��������
int check_amount()
{
    char str[10];
    int field, number, elements_amount;
    do{
        elements_amount = 0, number = 0;
        check_length (str, 10);
        //��������, �� ������� �������� �����
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

//�������� ���� ��������� �� ����������� ��������
float check_pagerank()
{
    char str[10];
    float field;
    int number, elements_amount;
    do{
        do{
            elements_amount = 0, number = 0;
            check_length (str, 10);
            //� ����� ��� ������ ���� ����� ����� � ������
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
        //���� ���� ������ ����� �� 0 �� 1
        if (field > 1)
            error_messages (2);
    }
    while (field > 1);
    return field;
}

//������� �������� �����
void input(int mode)
{
    //��������� �����������, �� ����������� ����������
    if (mode)
        printf ("�������� ����� �� ������� �����\n\n");
    else printf ("�������� ����� � ����� �����\n\n");
    //� �������, ���� �������� go_to_menu ������� �������, �� �������� �� ������������ ��������
    if (!go_to_menu()){
        WEBSITE *p = NULL;
        int length = 0;
        char answer;
        //�������� �������� ���'��
        p = (WEBSITE*)realloc(p, (length + 1) * sizeof(WEBSITE));
        printf("������ ���������� ��� ���-����\n");
        do{
            //�������� ������
            _flushall();
            //����� ���� ��� ������� ������ ������������ �� �����������
            printf("\n����� ������� ��'�: ");
            check_domain(p[length].DOMAIN);
            printf("��������: ");
            check_category(p[length].CATEGORY);
            printf("ʳ������ ��������� � ����: ");
            p[length].AMOUNT = check_amount();
            printf("PageRank: ");
            p[length].PAGERANK = check_pagerank();
            length++;
            //������� �� ����������� �� ���� �� ���������� ��������.
            //���� ��� - ���� ������������, � ���� � - �����������
            printf("\n������ ���������� �������� ��� ����� ���-����?(y/n)\n");
            scanf("%c", &answer);
            if(answer != 'y')
                system("cls");
            else
                p = (WEBSITE*)realloc(p, (length + 1) * sizeof(WEBSITE));
        }
        while (answer == 'y');
        //���� ������ ����� "�������� �� �������" -
        //���������� � ���� ���� ����, ��������� �� ������� ��� ���...
        if (mode){
            p = (WEBSITE*)realloc(p, (length + 1) * sizeof(WEBSITE));
            length = reading(p, length);
            FILE* file = fopen(data, "w");
            for (int number = 0; number < length - 1; number++)
                input_in_file(file, p, number);
            fclose(file);
        }
        //...���� � ������ "�������� � �����" -
        //������ � ����� �����
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

//��������� ����� ����� � ����� � �������, �� ���
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

//������� �����������
void edit (WEBSITE* p, int length, int number)
{
    int done, cancel, point_number = 0, button;
    //������� ����, �� �������� ���������� �������� �����������
    do{
        done = 0, cancel = 0;
        do{
            system("cls");
            //��������� ���� �� �������� ��� ��������� ����
            printf("������ ���� ��� �����������\n");
            if(point_number == 0) printf("-> "); else printf("   ");
            printf("%s\n", p[number].DOMAIN);
            if(point_number == 1) printf("-> "); else printf("   ");
            printf("%s\n", p[number].CATEGORY);
            if(point_number == 2) printf("-> "); else printf("   ");
            printf("%d\n", p[number].AMOUNT);
            if(point_number == 3) printf("-> "); else printf("   ");
            printf("%f\n", p[number].PAGERANK);
            button = getch();
            //��������� ����� ��������, � ��������� �� ��������� ������
            switch(button) {
                //��������� �������� ����� - ���������� ������ ���� �� ������� �����...
                        case UP_ARROW:
                            point_number--;
                            if(point_number < 0)
                                point_number = 3;
                            break;
                //...��, ��������, ����
                        case DOWN_ARROW:
                            point_number++;
                            if(point_number > 3)
                                point_number = 0;
                            break;
                //���������� ENTER ������� �������� ���� � ��������� ���������� ��
                        case ENTER:
                            done = 1;
                            break;
                //���������� BACKSPACE ������� ���� �� ������� � �������� ����
                        case BACKSPACE:
                            cancel = 1;
                            break;
            }
        }
        while (!done && !cancel);
        //���� ���� ��������� �����...
        if(done)
        {
            system("cls");
            //...���������� �������� ������ �������� �������� ������� ����
            printf("������ ���� ��������: ");
            switch(point_number) {
                case 0: check_domain(p[number].DOMAIN); break;
                case 1: check_category(p[number].CATEGORY); break;
                case 2: p[number].AMOUNT = check_amount(); break;
                case 3: p[number].PAGERANK = check_pagerank(); break;
            }
            //³������� ����� ��� ������
            FILE* file = fopen(data, "w");
            //������������ �����
            for(int i = 0; i < length; i++)
                input_in_file(file, p, i);
            fclose(file);
        }
        system("cls");
    }
    while (!cancel);
}

//������� ��������� ������
void deleting(WEBSITE* p, int length, int number)
{
    //���������� ��������������� ����� ����� ��� ��������� ������
    FILE* file = fopen(data, "w");
    for(int i = 0; i < length; i++)
        if(i != number)
            input_in_file(file, p, i);
    fclose(file);
}

//��������� ������� ����� �� �����
void output_table (int mode)
{
    //��������, �� ���� �� �������.
    //���� �� ������� - ���������� �������
    if (!empty_file()){
        int cancel = 0;
        do {
            //��������� ���������� ������ � ��������� � ����� ����� � �����
            WEBSITE *p = NULL;
            int length = 0, row = 0;
            p = (WEBSITE*)realloc(p, (length + 1) * sizeof(WEBSITE));
            length = reading(p, length) - 1;
            system("cls");
            int pages_amount;
            //���������� ������� �������. ʳ������ ������ ������� �� ������� ������ �� ������� (10)
            //���� ������� �� ������ - ��������� �� ���� �������
            if (length % PAGE_ENTRIES)
                pages_amount = length/PAGE_ENTRIES + 1;
            else pages_amount = length/PAGE_ENTRIES;
            int first = 0, last, page = 1, button;
            do{
                //� ��������� �� ������ ��������� �������
                //����� �������� ���������� ��-������
                //����� ������� ������: ���������, ����������, ����������� �� ���������
                //����������� �� ��������� ���������� � �������
                //��������� �� ���������� ����������� ����� ���������� �� ������������� ��� ������
                switch (mode){
                    case MODE_COMMON: printf("������ ���-�����:\n\n");
                                      printf ("��� ���������� ����� �������� Backspace\n\n");
                                      break;
                    case MODE_SORT: printf("³����������� ������ ���-�����:\n\n");
                                    printf ("��� ���������� ����� �������� Backspace\n\n");
                                    break;
                    case MODE_EDIT: printf("�����������:\n\n");
                         printf("�������� F1 ��� ������� ������\n\n"); break;
                    case MODE_DELETE: printf("���������:\n\n");
                         printf("�������� F1 ��� ������� ������\n\n"); break;
                }
                print_head();
                //���� �������� ������� � ���������
                //�� ����� ���������� ������ ������� �������� ������� ������...
                if (page == pages_amount)
                    last = length;
                //...������ ����� ���������� ������ �� �������
                // ������� ����������� + ������� ������ �� �������
                else last = first + PAGE_ENTRIES;
                // ������� �� ������, ������ ���������� � �������, �� ���
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
                printf("%32c<-%6c������� %d/%d%6c->", ' ', ' ', page, pages_amount, ' ');
                button = _getch();
                system("cls");
                //��������� �� �������� �� ��������� ������
                switch(button) {
                    //���������� ������ ���� �������� ������� �� ���������
                    //������ ��� ����� �������� �� ������� ���� �������
                    //����� ������� ������ �������� ���������
                    case LEFT_ARROW: page--;
                            row -= PAGE_ENTRIES;
                            first -= PAGE_ENTRIES;
                            break;
                    //������ ������ ���������� �������� 䳿 � ����������� ��
                    case RIGHT_ARROW: page++;
                            row += PAGE_ENTRIES;
                            first += PAGE_ENTRIES;
                            break;
                    //������ ����� �� �������� ������� ������ �� ������� �����...
                    case UP_ARROW: row--; break;
                    //...������ ����, ��������, ������� ����
                    case DOWN_ARROW: row++; break;
                    //��� ��������� ������ �����, �������� �� ������, � ����� ����������� �������
                    //����������� ������� ����������� �� ���������
                    case ENTER: if (mode == MODE_EDIT)
                                    edit(p, length, row);
                                else if (mode == MODE_DELETE)
                                    deleting(p, length, row);
                                button = BACKSPACE;
                                break;
                    //���������� BACKSPACE ������� ��������� ����� �� ������� � �������� ����
                    case BACKSPACE: cancel = 1; break;
                    //������ F1 ������� �������� ��������
                    case F1:
                         if (mode == MODE_EDIT)
                            help(HELP_REQUEST_EDIT);
                         else if (mode == MODE_DELETE)
                            help(HELP_REQUEST_DELETE);
                         break;
                }
                //���������� ������ �� ������ ������� ������,
                //���� �� �������� �� ��� ���������� ��������
                if (row > last - 1){
                    row = first;
                }
                //�� ���������� �� �������, ��� ������� �� ��� �������
                else if (row < first){
                    row = last - 1;
                }
                //���� ����� ������� ������� ������, �� �������� ������� �������,
                //��� ������� �� �����...
                if (page > pages_amount){
                    page = 1;
                    first = 0;
                    row = first;
                }
                //��, ��������, ������� �� �������
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

//������� ����������
void sorting()
{
    if (!empty_file()){
        WEBSITE *p = NULL;
        int length = 0;
        p = (WEBSITE*)realloc(p, (length + 1) * sizeof(WEBSITE));
        length = reading(p, length);
        //����������� ���������� �������� ��������� ������� ����������
        qsort (p->DOMAIN, length - 1, sizeof(WEBSITE), (int (*)(const void *, const  void *)) strcmp);
        FILE* file = fopen(data, "w");
        //��������� ������������ ����� � ����
        for (int number = 0; number < length - 1; number++)
            input_in_file (file, p, number);
        fclose(file);
        output_table (MODE_SORT);
        free(p);
    }
}

//������: �����, ������� ���� ����� 0.5
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
    printf("\n\n�������� ������� ����� � ��������� ����� 0.5 = %d", elements_amount);
    if (!elements_amount){
        system("cls");
        printf("\a����� � ��������� ����� 0.5 ����!\n");
    }
    cleaning();
}

//������: ��������� �������
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
        printf("\n\n�������� ������� ����� � ��������� ��������� ��������� = %d", elements_amount);
    cleaning();
}

//������: ������� ���������, ����� 50
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
    printf("\n\n�������� ������� ����� � ������� ��������� ����� 50 = %d", elements_amount);
    if (!elements_amount){
        system("cls");
        printf("\a����� � ������� ��������� ����� 50 ����!\n");
    }
    cleaning();
}

//������: ������ ua i com
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
    printf("\n\n�������� ������� ����� �� ������� �ua� �� �com� = %d", elements_amount);
    if (!elements_amount){
        system("cls");
        printf("\a����� �� ������� �ua� �� �com� ����!\n");
    }
    cleaning();
}

//������: ����� �� ����� ua �� ��������� ����� 0.7
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
    printf("\n\n�������� ������� ����� �� ����� �ua� � ��������� PR ����� 0.7 = %d", elements_amount);
    if (!elements_amount){
        system("cls");
        printf("\a����� �� ����� �ua� � ��������� PR ����� 0.7 ����!\n");
    }
    cleaning();
}

//������: ������� ������� ��������� �� ������� �������
void average (WEBSITE* p, int length)
{
    float average_pagerank = 0, average_amount = 0;
    for (int number = 0; number < length - 1; number++){
        average_amount += p[number].AMOUNT;
        average_pagerank += p[number].PAGERANK;
    }
    average_amount /= length - 1;
    average_pagerank /= length - 1;
    printf("����� ��� ������������� �����:\n\n");
    printf("������� ������� = %f\n",average_pagerank);
    printf("������� ������� ��������� �� ���� = %f",average_amount);
    cleaning();
}

//������: �����, � �������� "blog"
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
    printf("\n\n�������� ������� ����� ������� �blog� = %d", elements_amount);
    if (!elements_amount){
        system("cls");
        printf("\a����� ������� �blog� ����!\n");
    }
    cleaning();
}

//������� ������ �������
void color_menu()
{
    int Menupoint;
    do{
        Menupoint = choise(2, 9);
        switch (Menupoint) {
            case 1: system("color 07"); break;//�����������
            case 2: system("color 0f"); break;//�����-����
            case 3: system("color 1f"); break;//�����-����
            case 4: system("color 2f"); break;//������-����
            case 5: system("color 5f"); break;//���������-����
            case 6: system("color 4f"); break;//�������-����
            case 7: system("color 8f"); break;//���-����
            case 8: system("color f0"); break;//���-������
            case 9: break;
        }
    }
    while (Menupoint != 9);
}

//���� ������
void selection_menu()
{
    if (!empty_file()){
        int MenuPoint, length = 0;
        WEBSITE* p = NULL;
        p = (WEBSITE*)realloc(p, (length + 1) * sizeof(WEBSITE));
        length = reading(p, length);
        //����, �� ��������� ����� ����������� ������������ �� ��������
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

//������� ��������� ��������� ����
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
            case 9: printf("������ ���������!\n"); break;
        }
	}
	while(MenuPoint != 9);
	_getch();
}
