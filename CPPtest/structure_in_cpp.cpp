#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

// void printBook(BOOk book);
void printBook(struct BOOks book);
void PrintBookPP(struct BOOks *book);

// void printStudent(struct student stu); // error
void printStudent(struct STUDENT stu);
void printStudentP(struct STUDENT *student);

struct BOOks
{
    string title;
    int id;
};

typedef struct STUDENT{
    string name;
    int number;
}student;

// 测试struct的构造
struct node{
    int data;
    string str;
    char x;
    void init(int a, string b, char c){
        this->data = a;
        this->str = b;
        this->x = c;
    }
//    node() {} // 构造
    node(int a = 0, string b = "default", char c = 'x')
        :data(a), str(b), x(c) {} // 构造
};


struct Knode{
    int data;
    string str;
    char x;
    void init(int a, string b, char c){
        this->data = a;
        this->str = b;
        this->x = c;
    }
    Knode() {} // 构造
    Knode(int a, string b, char c) // 注意，没有默认值
        :data(a), str(b), x(c) {} // 构造
};


int main()
{
    BOOks MathBook;
    BOOks EnglBook;

    MathBook.title = "MATH";
    MathBook.id = 1;
    EnglBook.title = "ENGLISH";
    EnglBook.id = 2;
    printBook(MathBook);
    PrintBookPP(&EnglBook);

    student Mike;
    struct STUDENT Rose;

    Mike.name = "Mike";
    Mike.number = 1;
    Rose.name = "Rose";
    Rose.number = 2;   
    printStudentP(&Rose);
    printStudent(Mike);

    node N[5];
    N[0] =  {1, "hello", 'a'};
    N[1].init(2, "world", 'b');
    for (int i = 0; i < 5; i++){
		cout << N[i].data << " " << N[i].str << " " << N[i].x << endl;
	}

    Knode KN[5];
    KN[0] =  {1, "hello", 'a'};
    KN[1].init(2, "world", 'b');
    for (int i = 0; i < 5; i++){
		cout << KN[i].data << " " << KN[i].str << " " << KN[i].x << endl;
	}

}

// void printBook(BOOks book)
void printBook(struct BOOks book)
{
    cout << "This book is " << book.title;
    cout << ", and its ID is " << book.id << endl;
}

void PrintBookPP(struct BOOks *book)
{
    cout << book->title;
    cout << book->id << endl;
}

void printStudent(struct STUDENT stu)
{
    cout << "This student is " << stu.name;
    cout << ", and Number is " << stu.number << endl;
}

void printStudentP(struct STUDENT *student)
{
     cout << "This student is " << student->name;
     cout << ", and Number is " << student->number << endl;  
}


