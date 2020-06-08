/*
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
输入：s = "We are happy."
输出："We%20are%20happy."
*/

#include <iostream>
#include<vector>
#include<string.h>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int i = 0;
        while(i<s.size()){
            if(s[i] == ' '){
                s.insert(i, "%20");
                s.erase(i+3,1);
            }
            i+=1;
        }
        return s;
    }
};


int main(void){

    string testStr = "We are happy.";
    string::iterator pTestStr = testStr.begin();
    while(pTestStr != testStr.end()){
        cout << *pTestStr;
        pTestStr++;
    }
    cout << endl;

    testStr.insert(2, "%20");
    testStr.erase(5,1);
    for(int i=0; i<testStr.size(); i++){
        cout << testStr[i];
    }
    cout << endl;

    cout << "Size of testStr is " << testStr.size() << endl;

    testStr = " We are happy. ";
    Solution sol;
    cout << sol.replaceSpace(testStr) << endl;
    return 0;
}