/****************************************
**ListNode
****************************************/

#define Posi(T) ListNode<T>*

template <typename T>
struct ListNode{ //列表节点模板类(以双向链表形式实现)
    T data; // 数值
    Posi(T) pred; //前驱
    Posi(T) succ; //后继
    ListNode() {} //针对header和trailer的构造
    ListNode(T e, Posi(T) p, Posi(T) s)
        : data(e), pred(p), succ(s) {} //默认构造器
    Posi(T) insertAsPred(T const& e);
    Posi(T) insertAsSucc(T const& e);
};

