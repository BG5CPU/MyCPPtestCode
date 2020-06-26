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

/*******************************************************
* 测试
*******************************************************/ 
int main(){

    int NUM, mLines;
    scanf("%d %d", &NUM, &mLines); // 输入数组长度和查询次数 
    
    // 输入数组
    int array[NUM];
    for(int i=0; i<NUM; i++)
        cin >> array[i]; // scanf("%d", &array[i]);
    
    // 输入边界
    int Boun[mLines][2];
    for(int i=0; i<mLines; i++)
        scanf("%d %d", &Boun[i][0], &Boun[i][1]);
    
    // 存放结果的向量
    int ans = 0;
    for(int i=0; i<mLines; i++){
        for(int m=0; m<NUM; m++){
            if((Boun[i][0]<=array[m]) && (array[m]<=Boun[i][1])) ++ans;
        }
        cout << ans << endl;
    }

    return 0;
}





