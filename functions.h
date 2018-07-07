//Визначення різних констант, як-от кодів клавіш, режимів,
//допомоги та інших константних значень проекту
#define ENTER 13
#define UP_ARROW 72
#define DOWN_ARROW 80
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define BACKSPACE 8
#define DOMAIN_LENGHT 40
#define CATEGORY_LENGHT 20
#define PAGE_ENTRIES 10
#define MODE_COMMON 1
#define MODE_SORT 2
#define MODE_EDIT 3
#define MODE_DELETE 4
#define HELP_REQUEST_DELETE 141
#define HELP_REQUEST_ADD 142
#define HELP_REQUEST_EDIT 143
#define F1 59
#define data "data.txt"
#define help_doc "help.txt"

//Опис структури
typedef struct WEBSITE{
		char DOMAIN[DOMAIN_LENGHT];
		char CATEGORY[CATEGORY_LENGHT];
		int AMOUNT;
		float PAGERANK;
} WEBSITE;

//Даний розділ проекту містить перелік прототипів функцій
void cleaning();
void help(int request);
void print_row ();
void print_head ();
int go_to_menu();
void print_main_menu(int point_number);
void print_selection_menu(int point_number);
void print_color_menu(int point_number);
int choise(int mode, int points_amount);
void turn (char* str, char symbol_1, char symbol_2);
int reading(WEBSITE* p, int number);
void input_in_file(FILE* file, WEBSITE* p, int number);
void error_messages (int code);
int empty_file ();
void check_length (char* field, unsigned int max_length);
void last_domain (char* str, char* word1);
void check_domain(char* field);
void check_category(char* field);
int check_amount();
float check_pagerank();
void input(int mode);
void output_row (WEBSITE* p, int number, int arrow = 0);
void edit (WEBSITE* p, int length, int number);
void deleting(WEBSITE* p, int length, int number);
void output_table (int mode);
void sorting();
void rating (WEBSITE* p, int length);
void max_rating (WEBSITE* p, int length);
void amount (WEBSITE* p, int length);
void ua_and_com (WEBSITE* p, int length);
void ua_and_rating (WEBSITE* p, int length);
void average (WEBSITE* p, int length);
void blogs (WEBSITE* p, int length);
void color_menu();
void selection_menu();
void main_menu();
