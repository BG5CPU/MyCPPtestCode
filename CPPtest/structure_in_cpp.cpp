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


