 #define NAME_LEN 40

typedef struct _student_ Student;

struct _student_ {
      int     reg_number;
    char    name[NAME_LEN];
     int    age;
    float   grade;
};

Student store_data( int reg, char name[], int age, float grade);
void display_data(Student s2);

typedef struct _complexnum_ Complexop;

struct _complexnum_{
       float real,img;
};

Complexop arithmetic_operation(Complexop a, Complexop b, int choice);

/*Defining a new structure that holds price and quantity of an item as entities*/
typedef struct _purch_detail_ Purchase;

struct _purch_detail_{
char item[20];
float price;
int quantity;
};

Purchase Enter_details();
float sum_of_prices(Purchase p3);
float calculate_discount(float total_amount);
void display_bill(Purchase p4);
int bill_generator(int input);

int rd();
void displaychart(int curp,char player[4]);
int snake_ladder();
