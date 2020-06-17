#include <iostream>
#include<vector>
using namespace std;

typedef int Rank; // 秩

//通常有两种形式：函数模板和类模板；
//使用模板的目的就是能够让程序员编写与类型无关的代码。

template<typename T>  //函数模板 针对仅参数类型不同的函数；
inline T Max(T &a, T &b){
    return a>b ? a:b;
}

template <typename T> static Rank binSearch_B(T* A, T const & e, Rank lo, Rank hi){
    while(1 < hi -lo){
        Rank mi = (lo + hi) >> 1;
        (e < A[mi])? hi = mi : lo = mi; //[lo, mi) 或 [mi, hi)
    }
    return (e == A[lo])? lo : -1;
}

template <typename T> static Rank binSearch_C(T* A, T const & e, Rank lo, Rank hi){
    while(lo < hi){ //不变性: A[0, lo) <= e < A[hi, n)
        Rank mi = (lo + hi) >> 1; // 以中点为轴点，经比较后确定深入
        (e < A[mi])? hi = mi : lo = mi+1; //[lo, mi) 或 (mi, hi)
    } // 出口时，A[lo = hi]为不大于e的最小元素
    return --lo; 
}

template <typename T> void bubbleSort_A(T* A, Rank lo, Rank hi){ // [lo, hi)   
    bool sorted = false; // 整体有序标准
    T temp; Rank tempI = lo;
    while(!sorted){
        sorted = true; 
        while(++tempI < hi){
            if(A[tempI-1] > A[tempI]){
                sorted = false;
                temp = A[tempI-1];
                A[tempI-1] = A[tempI];
                A[tempI] = temp;
            }
        }
        --hi; tempI = lo;
    }
}

template <typename T> void bubbleSort_B(T* A, Rank lo, Rank hi){ // [lo, hi)   
    Rank last = hi;
    T temp; Rank tempI = lo;
    while(lo < last){ // 逐行扫描交换，直至全序
        last = lo; 
        while(++tempI < hi){
            if(A[tempI-1] > A[tempI]){
                last = tempI; // 最右侧逆序对的位置
                temp = A[tempI-1];
                A[tempI-1] = A[tempI];
                A[tempI] = temp;
            }
        }
        --hi; tempI = lo;
    }
}


int main(){
    static int MAX = 7;
    int testNum[MAX] = {2, 3, 1, 0, 2, 5, 3};
    vector<int> nums(testNum, testNum+MAX);
    cout << nums[1] << endl;

    int a = 10, b = 6;
    cout << "Max(a, b): " << Max(a, b) << endl;

    float aa = 2.3, bb = 5.4;
    cout << "Max(aa, bb): " << Max(aa, bb) << endl;

    int testArray[MAX] = {2, 2, 4, 6, 8, 8, 9};
    cout << "4 is at rank" << binSearch_B(testArray, 4, 0, 7) << " (version B)" << endl;
    cout << "5 is at rank" << binSearch_B(testArray, 5, 0, 7) << " (version B)" << endl;
    cout << "4 is at rank" << binSearch_C(testArray, 4, 0, 7) << " (version C)" << endl;
    cout << "5 is at rank" << binSearch_C(testArray, 5, 0, 7) << " (version C)" << endl;

    
    int testArray1[MAX] = {2, 3, 1, 0, 2, 5, 3};
    bubbleSort_A(testArray1, 0, MAX);
    for(int i = 0; i < MAX; i++){
        cout << testArray1[i] << " ";
    }
    cout << " is sorted array (version A)" << endl;

    int testArray2[MAX] = {2, 3, 1, 0, 2, 5, 3};
    bubbleSort_B(testArray2, 0, MAX);
    for(int i = 0; i < MAX; i++){
        cout << testArray2[i] << " ";
    }
    cout << " is sorted array (version B)" << endl;


}






