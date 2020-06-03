#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int *getRandom()
{
   static int randd[10];
   
   //set seed
   srand( (unsigned)time(NULL) );
   for(int i=0; i<10; i++)
   {
      randd[i] = rand();
      cout << i << "--";
      cout << randd[i] <<endl;
   }
   return randd;
}

int main()
{
   int *p;
   p = getRandom();
   for(int i=0; i<10; i++)
   {
      cout << "*(p + "<< i << "): ";
      cout << *(p+i) <<endl;
   }
}