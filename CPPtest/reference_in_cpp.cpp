#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

float vals[] = {10.1, 12.6, 33.1, 24.1, 50.0};

void swapAB(int &a, int &b);
float &setValues(int i); // 把引用作为返回值

int main()
{
    int a = 10;
    int *pa = NULL;
    pa = &a; // 取地址符，不是引用
    cout <<"*pa="<<*pa<<" and "<<"pa="<<pa<<endl;

    // 声明简单的变量
   int i;
   double d;
 
    // 声明引用变量
    int &r = i; //r和i的地址相同
    double &s = d;

    // 局部变量声明
    int aa = 100;
    int bb = 200;
    cout << "before exchange aa=" << aa;
    cout << " ,bb=" << bb << endl;
    /* 调用函数来交换值 */
    swapAB(aa, bb); // 注意，函数没有返回值
    cout << "after exchange aa=" << aa;
    cout << " ,bb=" << bb << endl; 

    cout << "改变前的值" << endl;
    for ( int i = 0; i < 5; i++ )
    {
        cout << "vals[" << i << "] = ";
        cout << vals[i] << endl;
    }

    
    setValues(1) = 20.23; // 改变第 2 个元素
    setValues(3) = 70.8;  // 改变第 4 个元素
    cout << "改变后的值" << endl;
    for ( int i = 0; i < 5; i++ )
    {
        cout << "vals[" << i << "] = ";
        cout << vals[i] << endl;
    }   

    return 0;
}

/* 
1. 在被调函数中对形参变量的操作就是对其相应的目标对象的操作。 
2. 使用引用传递函数的参数，在内存中并没有产生实参的副本，它是直接对实参操作；
  而使用一般变量传递函数的参数，当发生函数调用时，需要给 形参分配存储单元，形参变量是实参变量的副本；
  如果传递的是对象，还将调用拷贝构造函数。
  因此，当参数传递的数据较大时，用引用比用一般变量传递参数的效 率和所占空间都好。
3. 使用指针作为函数的参数虽然也能达到与使用引用的效果。
  但是，在被调函数中同样要给形参分配存储单元，且需要重复使用"*指针变量名"的 形式进行运算，
  这很容易产生错误且程序的阅读性较差；另一方面，在主调函数的调用点处，必须用变量的地址作为实参。
  而引用更容易使用，更清晰。
*/
void swapAB(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;   
    return;
}


float &setValues(int i)
{
    return vals[i];   // 返回第 i 个元素的引用
}