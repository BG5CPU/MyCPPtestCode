/****************************************
**ListNode
****************************************/
/*
#include "ListNode.h"

template <typename T>
Posi(T) ListNode<T>::insertAsPred(T const& e){
    Posi(T) x = new ListNode(e, pred, this); // 新建一个节点，新节点的pred是this的pred，新节点的succ是this
    pred->succ = x; // this的pred的succ变为新建节点x
    pred = x; // this的pred变为新建节点x
    return x;
}

template <typename T>
Posi(T) ListNode<T>::insertAsSucc(T const& e){
    Posi(T) x = new ListNode(e, this, succ); // 创建节点的耗时较大
    succ->pred = x;
    succ = x;
    return x;
}
*/