/********************************************************************************
* describe
* Let's play the game Zuma! 
* There are a sequence of beads on a track at the right beginning. 
* All the beads are colored but no three adjacent ones are allowed to be with a same color. 
* You can then insert beads one by one into the sequence. 
* Once three (or more) beads with a same color become adjacent due to an insertion, 
* they will vanish immediately.
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

int *Continue3or4(string str, int pos, int space){
    cout << "Continue3or4--" << str << "--" << pos << "--" << space;
    cout << endl;
    // space从2开始
    int p1, p2, l1, l2;
    p1 = pos-1; p2 = pos-2;
    l1 = pos+space; l2 = pos+space+1;
    int strS = str.size();

    int ppos = -1, sspace = 0;
    static int returnA[2];
    returnA[0] = ppos; returnA[1] = sspace;
    
    if(p1 == -1) return returnA;
    if(l1 == strS) return returnA;
    if(p2 == -1 && l2 == strS) return returnA;

    if(p2 == -1 && l2 < strS){
        if( (str.at(p1) == str.at(l1)) && (str.at(p1) == str.at(l2)) ){
            ppos = p1; sspace = 3;
        }else ppos = -1;
    }else if(p2 > -1 && l2 == strS){
        if( (str.at(p1) == str.at(l1)) && (str.at(p2) == str.at(l1)) ){
            ppos = p2; sspace = 3;
        }else ppos = -1;
    }else{
        if( (str.at(p2) == str.at(p1)) && (str.at(p2) == str.at(l1)) && (str.at(p2) == str.at(l2)) ){
            ppos = p2; sspace = 4;
        }else if( (str.at(p2) == str.at(p1)) && (str.at(p2) == str.at(l1)) ){
            ppos = p2; sspace = 3;
        }else if( (str.at(p1) == str.at(l1)) && (str.at(p1) == str.at(l2)) ){
            ppos = p1; sspace = 3;
        }else ppos = -1;
    }

    returnA[0] = ppos; returnA[1] = sspace;
    cout << "Continue3or4RETURN--" << ppos << "--" << sspace;
    cout << endl;
    return returnA;
}

int main(){

    string str;
    cin >> str;

//    int posti, space;
//    scanf("%d %d",&posti, &space);
    
    int posti; char color;
    scanf("%d %c",&posti, &color);

    int pos2, space = 2;
    pos2 = isContinueTwo(str, posti, color);
    
    int *ret;
    while(pos2 != -1){
        ret = Continue3or4(str, pos2, space);
        pos2 = ret[0];
        space = space+ret[1];   
        cout << "pos is " << pos2 << " and spa is " << space;
        cout << endl;    
    }

//    cout << "pos is " << ret[0] << " and spa is " << ret[1] << endl;
 

/*
    int nLines;
    scanf("%d", &nLines);

    int posti;
    char color;
    while(nLines--){
        scanf("%d %c",&posti, &color);
        cout << isContinueTwo(str, posti, color) << endl;
        
    }
*/
    
    return 0;
}





