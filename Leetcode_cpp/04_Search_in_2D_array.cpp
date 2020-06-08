/*
在一个 n * m 的二维数组中，
每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。
请完成一个函数，
输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include<vector>
#include<string.h>
using namespace std;
/*
class Solution {
public:
    bool findNumberIn2DArray(vector< vector<int> >& matrix, int target) { 
        if(matrix.empty()|| matrix[0].empty()) return false;
        int* pboun;
        pboun = findBoundary(matrix, target);
        int a,b,c,d;
        a=*(pboun+2); b=*(pboun+0)+1; c=*(pboun+3); d=*(pboun+1)+1;
        for(int i=a; i<b; i++){
            for(int j=c; j<d; j++){
                if(matrix[j][i] == target){
                    return true;
                }
            }            
        }
        return false;
    }

    int* findBoundary(vector< vector<int> >& matrix, int target){
        int NROW = matrix.size(); int MCOL = matrix[0].size();
        // boundary[0]=(0,a); boundary[1]=(b,0); 
        // boundary[2]=(NROW,c); boundary[3]=(d,MCOL);
        static int boundary[4];
        int i;
        for(i=0; i<MCOL; i++){
            if(matrix[0][i]>target){
                boundary[0] = i-1;
                break;
            }else{
                boundary[0] = i;
            }
        }
        for(i=0; i<NROW; i++){
            if(matrix[i][0]>target){
                boundary[1] = i-1;
                break;
            }else{
                boundary[1] = i;
            }
        }
        for(i=0; i<MCOL; i++){
            boundary[2] = i;
            if(matrix[NROW-1][i]>=target) break;
        }
        for(i=0; i<NROW; i++){
            boundary[3] = i;
            if(matrix[i][MCOL-1]>=target) break;
        }
        return boundary;
    }
};
*/

class Solution {
public:
    bool findNumberIn2DArray(vector< vector<int> >& matrix, int target) { 
        if(matrix.empty()|| matrix[0].empty()) return false;
        int ROW = matrix.size(); int COL = matrix[0].size();
        int compNum = matrix[ROW-1][0];
        int nextNum=0, mRow=ROW-1, nCol=0;
        bool isFind = false;
        while(true){
            if(target < compNum){
                mRow -=1;                             
            }else if(target > compNum){
                nCol +=1;
            }else{
                isFind = true;
                break;
            }            
            if(mRow==-1 || nCol==COL){
                break;
            }else{
                nextNum = matrix[mRow][nCol]; 
                compNum = nextNum; 
            }                    
        }
        return isFind;
    }
};

int main(void){
    const int NROW = 5;
    const int MCOL = 6;
    
    int testData[NROW][MCOL] = {{1,   4,  7, 11, 15, 20},
                                {2,   5,  8, 12, 19, 23},
                                {3,   6,  9, 16, 22, 25},
                                {10, 13, 14, 17, 24, 27},
                                {18, 21, 23, 26, 30, 31}};
    
    /*int testData[NROW][MCOL] = {{-1, 3}};*/
    vector<int> tempArray;
    vector< vector<int> > finaArray;
    for(int i=0; i<NROW; i++){
        for(int j=0; j<MCOL; j++){
            tempArray.push_back(testData[i][j]);
        }
        finaArray.push_back(tempArray);
        tempArray.clear();
    }
    cout << "size of finaArray is " << finaArray.size() << endl;

    int target = 7;
    int* pboun;

    Solution sol;
/*
    pboun = sol.findBoundary(finaArray, target);
    for(int i=0; i<4; i++){
        cout<< "Boundary is " << *(pboun+i) << endl;
    }
*/
    if(sol.findNumberIn2DArray(finaArray, target)){
        cout << "I can find the number." << endl;
    }else{
        cout << "I can't find the number." << endl;
    }

    return 0;
}