#include <iostream>
#include <stddef.h>
using namespace std;

#define Posi(T) ListNode<T>*

typedef int Rank;

/****************************************
**ListNode
****************************************/
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

/********************member*****************/
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



/**************************************** 
**class List
****************************************/
template <typename T>
class List{
private:
    int _size;
    Posi(T) header; // 头哨兵
    Posi(T) trailer; // 尾哨兵
protected:

public:
    ~List();
    void init();
    Posi(T) first();
    T operator[](Rank r) const;
    Posi(T) find(T const & e, Rank n, Posi(T) p);
    Posi(T) insertBefore(Posi(T) p, T const& e);
    Posi(T) insertAfter(Posi(T) p, T const& e);
    Posi(T) insertAsFirst(T const& e);
    Posi(T) insertAsLast(T const& e);
    void copyNodes(Posi(T) p, Rank n);
    T remove(Posi(T) p);
    int clean();
    int deduplicate(); // 无序向量，去重复
    int uniquify(); // 有序向量，成批剔除重复元素
    Posi(T) search(T const & e, Rank n, Posi(T) p) const; // 有序列表，p的前n个(真)前驱中，找到不大于e的最后者

};

/********************member*****************/
template <typename T>
List<T>::~List(){ // 列表析构
    clean(); delete header; delete trailer; // 清空列表，释放头、尾哨兵节点
}

template <typename T>
void List<T>::init(){
    header = new ListNode<T>; // 创建头哨兵节点
    trailer = new ListNode<T>; // 创建尾哨兵节点
    header ->succ = trailer; header-> pred = NULL; // 互联
    trailer->pred = header;  trailer->succ = NULL; // 互联
    _size = 0; // 记录规模
}

template <typename T>
Posi(T) List<T>::first(){
    if(header->succ == trailer) return NULL;
    else return header->succ;
}

template <typename T> // assert: 0 <= r < size
T List<T>::operator[](Rank r) const{ // O(r), 效率低下，可偶尔为之
    Posi(T) p = first(); // 从首节点出发
    while(0 < r--) p = p->succ;
    return p->data; // *对空列表，会有问题*
}

template <typename T>
Posi(T) List<T>::find(T const & e, Rank n, Posi(T) p){ //顺序查找，O(n)
    while(n--){ // 从右向左，逐个p的前驱与e比对
        p = p->pred;
        if(e == p->data) return p;
    }
    return NULL;
}

template <typename T>
Posi(T) List<T>::insertBefore(Posi(T) p, T const& e){
    _size++; return p->insertAsPred(e); // 以p的前驱插入
}

template <typename T>
Posi(T) List<T>::insertAfter(Posi(T) p, T const& e){
    _size++; return p->insertAsSucc(e); // 以p的后驱插入
}

template <typename T>
Posi(T) List<T>::insertAsFirst(T const& e){
    _size++; return header->insertAsSucc(e);
}

template <typename T>
Posi(T) List<T>::insertAsLast(T const& e){
    _size++; return trailer->insertAsPred(e);
}

template <typename T>
void List<T>::copyNodes(Posi(T) p, Rank n){ // O(n) 从p开始，连续复制n个节点
    init();
    while(n--)
        { insertAsLast(p->data); p = p->succ; }
}

template <typename T>
T List<T>::remove(Posi(T) p){
    T e = p->data;
    p->pred->succ = p->succ;
    p->succ->pred = p->pred;
    delete p; _size--; return e;
}

template <typename T>
int List<T>::clean(){
    int oldSize = _size;
    while(0 < _size)
        remove(header->succ); // 反复删除首节点，直至列表变空(_size = 0)
    return oldSize;
} // O(n), 线性正比于列表规模

template <typename T>
int List<T>::deduplicate(){ // 无序向量
    if(_size < 2) return 0; // 平凡列表自然无重复 //至少存在2个节点
    int oldSize = _size; // 记录原有规模
    Posi(T) p = first(); Rank r = 1;
    while(trailer != (p->succ)){ // 从第二个节点开始 //依次直到末节点
        Posi(T) q = find(p->data, r, p);
        q? remove(q) : r++; // 若存在，则删除；否则可递增
    } // assert: 循环过程中的任意时刻，p的所有前驱互不相同
    return oldSize-_size; // 列表规模的变化，也就是被删除的元素的总数
}

template <typename T>
int List<T>::uniquify(){
    if(_size < 2) return 0; // 平凡列表自然无重复 //至少存在2个节点
    int oldSize = _size; // 记录原有规模
    Posi(T) p = first(); Posi(T) q; // p为各区段起点，q为p的后继
    while(trailer != (q = p->succ)){ // 反复考察紧邻的节点对(p, q)
        if(p->data != q->data) p = q; // 如果互异，指向下一个区域
        else remove(q); //如果相同，删除后者
    }
    return oldSize-_size; // 列表规模的变化，也就是被删除的元素的总数
}

template <typename T>
Posi(T) List<T>::search(T const & e, Rank n, Posi(T) p) const{ //有序列表，p的前n个(真)前驱中，找到不大于e的最后者
    while(0<n--)
        if( ((p = p->pred)->data) <= e ) break; // 逐个比较
    return p;
}


// 测试
int main(){

   List<int> listTest1;
   listTest1.init(); //初始化，创建header和trailer

   const int NUM = 10;
   int elem;
   for(int i=0; i<NUM; i++){
      elem = rand()%100;
      cout << "*" << elem << "*";
      listTest1.insertAsLast(elem);
   }    
   cout << endl;

}





