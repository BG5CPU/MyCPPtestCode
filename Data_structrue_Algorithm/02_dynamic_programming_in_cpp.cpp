#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int Fibonacci(int n); // common 
int Fibonacci_Memoization(int n); // memoization

int main(){
    const int NUM = 42;

    cout << "Fibonacci(n) (common) is " << Fibonacci(NUM)  << endl;

    return 0;
}


int Fibonacci(int n){
    return
     (n < 2)?
     n : Fibonacci(n-1)+Fibonacci(n-2);
}

int Fibonacci_Memoization(int n){
    
}
