/********************************************************************************
* describe
* Let's play the game Zuma! 
* Input:
* ACCBA
* 5
* 1 B
* 0 A
* 2 B
* 4 C
* 0 A
* Output:
* ABCCBA
* AABCCBA
* AABBCCBA
* -
* A
*********************************************************************************/ 

#include <iostream>
using namespace std;
#include <stdlib.h>     /* qsort */
#include <stdio.h>      /* printf */

/*******************************************************
* 测试
*******************************************************/

int isContinueTwo(string str, int pos, char col){
    int strS = str.size();
    if(pos == 0){
        if( (str.at(0)==col) && (str.at(1)==col) ) return 0;
        else return -1;
    }else if(pos == strS){
        if( (str.at(strS-1)==col) && (str.at(strS-2)==col) ) return strS-2;
        else return -1;        
    }else if(pos == 1){
        if( (str.at(pos)==col) && (str.at(pos+1)==col) ) return pos;
        else if( (str.at(pos-1)==col) && (str.at(pos)==col) ) return pos-1; 
        else return -1;
    }else if(pos == strS-1){
        if( (str.at(pos-1)==col) && (str.at(pos)==col) ) return pos-1;
        else if( (str.at(pos-2)==col) && (str.at(pos-1)==col) ) return pos-2;
        else return -1;
    }else{
        if( (str.at(pos)==col) && (str.at(pos+1)==col) ) return pos;
        else if( (str.at(pos-1)==col) && (str.at(pos)==col) ) return pos-1;
        else if( (str.at(pos-2)==col) && (str.at(pos-1)==col) ) return pos-2;
        else return -1;
    }
}

int isContinueThree(string str, int pos, int nLoop){
    if(pos == 0) return 0;
    else if(pos == 1){
        if( (str.at(0) == str.at(1)) )
    }
    
}

int main(){

    string str;
    cin >> str;

    int nLines;
    scanf("%d", &nLines);

    int posti;
    char color;
    while(nLines--){
        scanf("%d %c",&posti, &color);
        cout << isContinueTwo(str, posti, color) << endl;
        
    }

    return 0;
}





