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

int main(){

    string str;
    cin >> str;

    int nLines;
    scanf("%d", &nLines);

    int po;
    char color;
    while(nLines--){
        scanf("%d %c",&po, &color);
        

    }

    return 0;
}





