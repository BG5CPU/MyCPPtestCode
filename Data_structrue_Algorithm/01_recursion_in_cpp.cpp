#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int *getRandom(void);
void sortArray(int array[], int n); //起泡
int sumRecursion(int A[], int n);
int sumIteration(int A[], int n);
int sumDivide(int A[], int lo, int hi);
void reverseRecursion(int* A, int lo, int hi);
void max2Iteration(int A[], int lo, int hi, int &x1, int &x2); // interval is [lo, hi)
void max2IterationImprove(int A[], int lo, int hi, int &x1, int &x2); // interval is [lo, hi)
void max2Divide(int A[], int lo, int hi, int &x1, int &x2); // interval is [lo, hi)

int main(){

    int *p;
    p = getRandom();
    int array[10];
    for(int i=0; i<10; i++){
        array[i] = *(p+i);
    }
    cout << endl;
 
    sortArray(array, 10);
    for(int i=0; i<10; i++){
        cout << array[i] <<"--";
    }
    cout << endl;

    cout << "Sum of array (use recursion) is " << sumRecursion(array, 10) << endl;
    cout << "Sum of array (use iteration) is " << sumIteration(array, 10) << endl;  
    cout << "Sum of array (use division) is " << sumDivide(array, 0, 9) << endl; 

    reverseRecursion(array, 0, 9);
    for(int i=0; i<10; i++){
        cout << array[i] <<"--";
    }
    cout << endl; 

    int max1, max2, maxI1, maxI2, maxD1, maxD2;
    max2Iteration(array, 0, 10, max1, max2);
    max2IterationImprove(array, 0, 10, maxI1, maxI2);
    max2Divide(array, 0, 10, maxD1, maxD2);
    cout << "Positions of Max1 and Max2 (ordinary) are " << max1 << " and " << max2 << endl;
    cout << "Positions of Max1 and Max2 (improved) are " << maxI1 << " and " << maxI2 << endl;
    cout << "Positions of Max1 and Max2 (divided) are " << maxD1 << " and " << maxD2 << endl;

    return 0;
}

int *getRandom(){
    static int randd[10];  
    //set seed
    srand( (unsigned)time(NULL) );
    for(int i=0; i<10; i++){
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

int sumRecursion(int A[], int n){
    return
     (n < 1)?
      0 : sumRecursion(A, n-1)+A[n-1];
}

int sumIteration(int A[], int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum = sum+A[i];
    }
    return sum;
}

int sumDivide(int A[], int lo, int hi){
    if(lo == hi) return A[lo];
    int mid = (lo+hi)>>1; // 右移1位，等于除以二
    return sumDivide(A, lo, mid)+sumDivide(A, mid+1, hi);
}

void reverseRecursion(int* A, int lo, int hi){
    int temp;
    if(lo < hi){
        temp = A[hi]; A[hi] = A[lo]; A[lo] = temp;
        reverseRecursion(A, lo+1, hi-1);
    }else 
        return;
}

void max2Iteration(int A[], int lo, int hi, int &x1, int &x2){
    x1 = lo;
    for(int i = lo+1; i < hi; i++){
        if(A[x1] < A[i]) x1 = i;
    }

    if(x1 == lo) x2 = lo+1;
    else x2 = lo;    
    for(int i = lo+1; i < x1; i++){
        if(A[x2] < A[i]) x2 = i;
    }
    for(int i = x1+1; i < hi; i++){
        if(A[x2] < A[i]) x2 = i;
    }
}

void max2IterationImprove(int A[], int lo, int hi, int &x1, int &x2){
    if(A[lo] > A[lo+1]){x1 = lo; x2 = lo+1;}
    else{x1 = lo+1; x2 = lo;}
    for(int i = lo+2; i < hi; i++){
        if(A[i] > A[x2]){
            x2 = i;
            if(A[x2] > A[x1]){
                x2 = x1;
                x1 = i;
            }
        }
    }
}

void max2Divide(int A[], int lo, int hi, int &x1, int &x2){
    
    if(lo+2 == hi){
        if(A[lo]>A[lo+1]){x1 = lo; x2 = lo+1;}
        else{x1 = lo+1; x2 = lo;}
        return;
    }
    if(lo+3 == hi){
        if(A[lo]>A[lo+1]){
            if(A[lo+2]>A[lo+1]){
                if(A[lo+2]>A[lo]){x1 = lo+2; x2 = lo;}
                else{x1 = lo; x2 = lo+2;}
            }else{x1 = lo; x2 = lo+1;}
        }else{
            if(A[lo+2]>A[lo]){
                if(A[lo+2]>A[lo+1]){x1 = lo+2; x2 = lo+1;}
                else{x1 = lo+1; x2 = lo+2;}
            }else{x1 = lo+1; x2 = lo;}
        }
        return;
    }
    
    int mid = (lo+hi)>>1;
    int x1L, x2L;
    max2Divide(A, lo, mid, x1L, x2L);
    int x1R, x2R;
    max2Divide(A, mid, hi, x1R, x2R);
    if(A[x1L] > A[x1R]){
        x1 = x1L;
        x2 = (A[x1R]>A[x2L])? x1R : x2L;
    }else{
        x1 = x1R;
        x2 = (A[x1L]>A[x2R])? x1L : x2R;
    }
}
