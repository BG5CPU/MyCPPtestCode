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

// 有序向量的元素查找 
template <typename T> static Rank binSearch_B(T* A, T const & e, Rank lo, Rank hi){
    while(1 < hi -lo){
        Rank mi = (lo + hi) >> 1;
        (e < A[mi])? hi = mi : lo = mi; //[lo, mi) 或 [mi, hi)
    }
    return (e == A[lo])? lo : -1;
}

// 有序向量的元素查找，返回不大于这个元素的最后的位置
template <typename T> static Rank binSearch_C(T* A, T const & e, Rank lo, Rank hi){
    while(lo < hi){ //不变性: A[0, lo) <= e < A[hi, n)
        Rank mi = (lo + hi) >> 1; // 以中点为轴点，经比较后确定深入
        (e < A[mi])? hi = mi : lo = mi+1; //[lo, mi) 或 (mi, hi)
    } // 出口时，A[lo = hi]为不大于e的最小元素
    return --lo; 
}

// 气泡排序
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

// 气泡排序改进
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

/*
template <typename T> void merge(T* E, Rank lo, Rank mi, Rank hi){
    T* A = E + lo;  // A[0, hi-lo) = E[lo, hi)
    Rank lb = mi - lo; T* B = new T[lb]; // 前子向量 B[0, lb) = E[lo, mi)
    for(Rank i = 0; i < lb; B[i++] = A[i]); // 复制前子向量B
    Rank lc = hi - mi; T* C = E + mi; // 后子向量C[0, lc) = E[mi, hi)
    for(Rank i=0, j=0, k=0; (j<lb)||(k<lc);){ //B[j]或C[k]中 小者 转至A的末尾
        if( (j<lb)&&(lc<=k || (B[j]<=C[k])) ) A[i++] = B[j++];
        if( (k<lc)&&(lb<=j || (C[k]< B[j])) ) A[i++] = C[k++];
    }
}
*/
template <typename T> void merge(T* E, Rank lo, Rank mi, Rank hi){
    T* A = E + lo;  // A[0, hi-lo) = E[lo, hi)
    Rank lb = mi - lo; T* B = new T[lb]; // 前子向量 B[0, lb) = E[lo, mi)
    for(Rank i = 0; i < lb; B[i++] = A[i]); // 复制前子向量B
    Rank lc = hi - mi; T* C = E + mi; // 后子向量C[0, lc) = E[mi, hi)
    for(Rank i=0, j=0, k=0; j<lb;){ //B[j]或C[k]中 小者 转至A的末尾
        if( lc<=k || (B[j]<=C[k]) )  A[i++] = B[j++];
        if( (k<lc) && (C[k]< B[j]) ) A[i++] = C[k++];
    }
}

// 二分归并排序
template <typename T> void mergeSort(T* A, Rank lo, Rank hi){ // [lo, hi) 
    if(hi - lo < 2) return;
    Rank mi = (lo+hi)>>1;
    mergeSort(A, lo, mi);
    mergeSort(A, mi, hi);
    merge(A, lo, mi, hi); // 归并
}

// 测试
int main(){
    static int MAX = 7;
    int testNum[MAX] = {2, 3, 1, 0, 2, 5, 3};
    vector<int> nums(testNum, testNum+MAX);
    cout << nums[1] << endl;
    // int i = 0;
    // cout << "test i++" << nums[i++] << endl;

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

    int testArray3[MAX] = {2, 1, 3, 4, 0, 5, 6};
    merge(testArray3, 1, 4, 7);
    for(int i = 0; i < MAX; i++){
        cout << testArray3[i] << " ";
    }
    cout << " is merged array (version A)" << endl;

    int testArray4[MAX] = {5, 1, 4, 4, 0, 3, 6};
    mergeSort(testArray4, 0, MAX);
    for(int i = 0; i < MAX; i++){
        cout << testArray4[i] << " ";
    }
    cout << " is mergeSorted array (version A)" << endl;

}






