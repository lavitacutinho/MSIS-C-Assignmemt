#define READ_TEXT_MODE "r"
#define WRITE_TEXT_MODE "w"
#define APPEND_TEXT_MODE "a"

#define READ_BIN_MODE "rb"
#define WRITE_BIN_MODE "wb"
#define APPEND_BIN_MODE "ab"

FILE * open_file(char *file_name, char *mode);

int read_file_by_char(char *file_name);
int write_file_by_char(char *file_name,char *content);
int read_file_by_char_reverse(char *file_name);

int copy_file(char *src, char *dst);

int write_file_line(FILE *, char *file_name);
int read_file_line(FILE *, char *file_name);
void display(FILE *);

int count_file_content(char *file_name);

void write_a_file(char *file_name, int input);
void check_for_even_odd(char *file_name);
void display_int_file(FILE *fp);
int sort_even_odd_files(char *file_name, int input);

struct _person_
{
   unsigned int telno;
    char name[20];
   const char address[100];

};

typedef struct _person_ Person;

void Add_data();
void Delete_data();
void findData();
void Edit_data();

