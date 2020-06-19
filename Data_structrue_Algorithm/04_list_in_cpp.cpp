#include <iostream>
#include<vector>
#include "ListNode.h"
#include "List.h"
using namespace std;



/******************************************************************************************
 * 随机生成长度为n的列表（其中可能包含重复节点）
 ******************************************************************************************/
/*
template <typename T> //元素类型
void randomList ( List<T> & list, int n ) { //在[0, 2n)中选择n个偶数，随机插入列表
   ListNodePosi(T) p =
      ( rand() % 2 ) ?
      list.insertAsLast ( rand() % ( T ) n * 2 ) :
      list.insertAsFirst ( rand() % ( T ) n * 2 );
   for ( int i = 1; i < n; i++ )
      p = rand() % 2 ?
          list.insertB ( p, rand() % ( T ) n * 2 ) :
          list.insertA ( p, rand() % ( T ) n * 2 );
}
*/



// 测试
int main(){

   List<int> testList1;
    

}





