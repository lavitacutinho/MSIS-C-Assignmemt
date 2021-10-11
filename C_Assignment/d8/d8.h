struct _student_
{
    int reg;
    char name[20];
    int age;
    int marks;
};

typedef struct _student_ Student;

Student *store_stud_dynamically(int record);

int search_by_roll(Student *stud_detail, int record, int search);

int search_by_name(Student *stud_detail, int record, char *searchn);

int highest_mark(Student *stud_detail, int record);

int search_a(Student *stud_detail, int record, char letter);


struct _coord_
{
    int x[100], weight;
};

typedef struct _coord_ Coord;

Coord *read_coord_dynamically(int row);

int find_lines(Coord **c);
