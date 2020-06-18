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

}






