// 在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
// 数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。
// 请找出数组中任意一个重复的数字。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include <iostream>
#include<vector>
#include<string.h>
using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        bool flag[nums.size()];
        memset(flag, false, sizeof(flag));
        // cout << "size of nums is "<< sizeof(flag) << endl;
        for(int i=0; i<nums.size(); i++){
            if(flag[nums[i]]){
                return nums[i];
            }else{
                flag[nums[i]] = true;
            }
        }
        return -1;
    }
};

int main(void){
    Solution sol;
    static int MAX = 7;
    int testNum[MAX] = {2, 3, 1, 0, 2, 5, 3};
    vector<int> nums(testNum, testNum+MAX);
    int repNum;
    repNum = sol.findRepeatNumber(nums);
    cout << "repeat number is "<< repNum << endl;
}




/*
int main(void)
{
    int a[5] = {1,2,3,4,5};
    vector<int> b;
    vector<int> c(a,a+3);
    for(int i=0; i<c.size(); i++)
    {
        cout << "c is " << c[i] << endl;
    }
  
    for(vector<int>::iterator it = c.begin(); it<c.end(); it++)
    {
        b.push_back(*it);
        cout << "iterator of c is xx and *iterator of c is " << *it << endl;
    }
   
    return 0;
}
*/