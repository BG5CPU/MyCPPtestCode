#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

float getAverage(float *arr, int size);

const int MAX = 3;

int main()
{

    char cch = 'a';
    char *pchar = NULL;
    pchar = &cch;
    cout << "address of cch is " << pchar << endl;
    cout << "~~~" << endl;
    
    /*
    char *pstrin = "Hello"; // length = 6
    for(int i=0; i<6; i++)
    {
        cout << "*pstrin[" << i << "]=" << *pstrin;
        cout <<  "and pstrin=" << pstrin << endl;
        pstrin++;
    }
    */

    int var[MAX] = {22, 223, 456};
    // char var[MAX] = {'s', 'd', 'f'};
    int *pvar;
    // 指向数组的地址
    pvar = var;
    for(int i=0; i<MAX; i++)
    {
        cout << "Addresss of var[" << i << "]=";
        cout << pvar << endl;

        cout << "Value of var[" << i << "]=";
        cout << *pvar << endl;

        // 移到下一个位置
        pvar++;
        
    }

    const char *names[MAX] = {
                   "Zara Ali",
                   "Hina Ali",
                   "Nuha Ali"};
 
   for (int i = 0; i < MAX; i++)
   {
      cout << "Value of names[" << i << "] = ";
      cout << names[i] << "~~~" << *names[i] << endl;
      cout << "~~~" << endl;
   }
   
   float balance[5] = {10.3, 2.4, 3.9, 17.4, 50.1};
   float avg;
   avg = getAverage(balance, 5);
   cout << "Average value is: " << avg << endl; 
     
   return 0;
}

float getAverage(float *arr, int size)
{
    int i;
    float sum = 0.0;       
    float avg;          
 
    for (i = 0; i < size; ++i)
    {
        sum += arr[i];
    }
    avg = sum / size;
    return avg;
}