/********************************************************************************
* describe
* Let S be a set of n integral points on the x-axis. 
* For each given interval [a, b], you are asked to count the points lying inside.
* Input:
* 5 2
* 1 3 7 9 11
* 4 6
* 7 12
* Output:
* 0
* 3
*********************************************************************************/ 

#include <iostream>
using namespace std;
#include <stdlib.h>     /* qsort */
#include <stdio.h>      /* printf */

/*******************************************************
* 测试
*******************************************************/

// 有序向量的元素查找，返回不大于这个元素的最后的位置
static int binSearch(int* A, int const & e, int lo, int hi){
    while(lo < hi){ //不变性: A[0, lo) <= e < A[hi, n)
        int mi = (lo + hi) >> 1; // 以中点为轴点，经比较后确定深入
        (e < A[mi])? hi = mi : lo = mi+1; //[lo, mi) 或 (mi, hi)
    } // 出口时，A[lo = hi]为不大于e的最小元素
    return --lo;
}

int compare (const void * a, const void * b){
  return ( *(int*)a - *(int*)b );
}

int main(){

    int NUM, mLines;
    scanf("%d %d", &NUM, &mLines); // 输入数组长度和查询次数 
    
    // 输入数组
    int array[NUM];
    for(int i=0; i<NUM; i++)
        scanf("%d", &array[i]); // cin >> array[i];
    
    qsort(array, NUM, sizeof(int), compare);
    
    // 输入边界
    int leftI, rightI, Pleft, Pright, cnt;
    while(mLines--){
        scanf("%d %d", &leftI, &rightI);
        Pleft = binSearch(array, leftI, 0, NUM);
        Pright = binSearch(array, rightI, 0, NUM);
        if(array[Pleft] == leftI){
            cnt = Pright-Pleft+1;
        }else{
            cnt = Pright-Pleft;
        }
        if(Pleft == -1) cnt = Pright+1;
        printf("%d\n", cnt);       
    }

/*  
    // 存放结果的向量
    int ans = 0;
    for(int i=0; i<mLines; i++){
        for(int m=0; m<NUM; m++){
            if((Boun[i][0]<=array[m]) && (array[m]<=Boun[i][1])) ++ans;
        }
        printf("%d\n", ans);
    }
*/
    return 0;
}





