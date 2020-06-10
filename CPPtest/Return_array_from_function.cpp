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

void sortArray(int array[], int n){
   int temp;
   for (bool sorted = false; sorted = !sorted; n--){
      for(int i = 1; i < n; i++){
         if(array[i-1] > array[i]){
            temp = array[i-1];
            array[i-1] = array[i];
            array[i] = temp;     
            sorted = false;       
         }
      }
   }
}

int main()
{
   int *p;
   p = getRandom();
   int array[10];
   for(int i=0; i<10; i++)
   {
      cout << "*(p + "<< i << "): ";
      cout << *(p+i) <<endl;
      array[i] = *(p+i);
   }
   
   sortArray(array, 10);
   for(int i=0; i<10; i++)
   {
      cout << array[i] <<"--";
   }
   cout << endl;

}