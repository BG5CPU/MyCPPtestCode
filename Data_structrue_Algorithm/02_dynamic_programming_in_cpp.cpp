#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int Fibonacci(int n); // common 
int Fibonacci_Memoization(int n); // memoization
int Fibonacci_DP1(int n); // dynamic programming
void LonComSub_Recursion(string str1, string str2, int &n, int &MAX); // longest common subsequence
int LonComSub_DP1(string str1, string str2); // longest common subsequence

int main(){
    const int NUM = 36;

    cout << "Fibonacci(n) (common) is " << Fibonacci(NUM) << endl;
    cout << "Fibonacci(n) (DP1) is " << Fibonacci_DP1(NUM) << endl;

    // string str1 = "aebkcfmde", str2 = "eadbbacdk";
    string str1 = "didaactical", str2 = "advantage";  
    int n = 0, lcsMAX = 0;
    LonComSub_Recursion(str1, str2, n, lcsMAX);
    cout << "Length of LCS is " << lcsMAX << endl;
    cout << "Length of LCS (DP) is " << LonComSub_DP1(str1, str2) << endl;

    return 0;
}


int Fibonacci(int n){
    return
     (n < 2)?
     n : Fibonacci(n-1)+Fibonacci(n-2);
}

int Fibonacci_Memoization(int n){
    return 0;
}

int Fibonacci_DP1(int n){
    int f_1 = 1, f_2 = 0, f = 1; // fib(0) = 0, fib(1) = 1;
    n--;
    while(n > 0){
        f = f_1+f_2;
        f_2 = f_1;
        f_1 = f;
        n--;
    }
    return f;
}

void LonComSub_Recursion(string str1, string str2, int &n, int &MAX){
    if(str1=="" || str2==""){//recursion base
        if(n > MAX) MAX = n;
        return;
    } 
    
    char char1, char2;
    char1 = str1.back();
    char2 = str2.back();

    string temStr1, temStr2;
    if(char1 == char2){
        n++;
        str1.pop_back(); str2.pop_back();
        LonComSub_Recursion(str1, str2, n, MAX);
        n--;  // roll back 
    }else{
        temStr1 = str1; temStr2 = str2;
        str1.pop_back(); str2.pop_back();
        LonComSub_Recursion(str1, temStr2, n, MAX);
        LonComSub_Recursion(temStr1, str2, n, MAX);
    }
}

int LonComSub_DP1(string str1, string str2){
    int LenStr1, LenStr2;
    LenStr1 = str1.length(); LenStr2 = str2.length();
    int PreNLCS[LenStr1+1] = { 0 };
    int NowNLCS[LenStr1+1] = { 0 };
    int NowLSC = 0;
    for(int i=0; i<LenStr2; i++){
        for(int j=1; j<LenStr1+1; j++){
            if(str1.at(j-1) == str2.at(i)){
                NowLSC = PreNLCS[j-1]+1;
                NowNLCS[j] = NowLSC;
            }else{
                NowLSC = (NowNLCS[j-1] > PreNLCS[j])? NowNLCS[j-1] : PreNLCS[j];
                NowNLCS[j] = NowLSC;
            }
        }
        memcpy(PreNLCS, NowNLCS, sizeof(NowNLCS));
    }   
    return NowLSC;
}
