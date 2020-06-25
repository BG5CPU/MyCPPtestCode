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
    // new操作要花费100倍的时间
    Posi(T) x = new ListNode(e, pred, this); // 新建一个节点，新节点的pred是this的pred，新节点的succ是this
    pred->succ = x; // this的pred的succ变为新建节点x
    pred = x; // this的pred变为新建节点x
    return x;
}

template <typename T>
Posi(T) ListNode<T>::insertAsSucc(T const& e){
    // new操作要花费100倍的时间
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
    Posi(T) last();
    T operator[](Rank r) const;
    Posi(T) find(T const & e, Rank n, Posi(T) p);
    Posi(T) insertBefore(Posi(T) p, T const& e);
    Posi(T) insertAfter(Posi(T) p, T const& e);
    Posi(T) insertAsFirst(T const& e);
    Posi(T) insertAsLast(T const& e);
    void copyNodes(Posi(T) p, Rank n);
    T remove(Posi(T) p);
    Posi(T) selectMax(Posi(T) p, int n); // 从起始于位置p的n个元素中选出最大者
    int clean();
    int deduplicate(); // 无序向量，去重复
    int uniquify(); // 有序向量，成批剔除重复元素
    Posi(T) search(T const & e, Rank n, Posi(T) p) const; // 有序列表，p的前n个(真)前驱中，找到不大于e的最后者
    void selectionSort(Posi(T) p, int n); // 对列表中起始于位置p的连续n个元素做选择排序
    void insertionSort(Posi(T) p, int n); // 对列表中起始于位置p的连续n个元素做选择排序
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

template <typename T>
Posi(T) List<T>::last(){
    if(trailer->pred == header) return NULL;
    else return trailer->pred;
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
    delete p; _size--;  // delete 100倍的时间复杂度
    return e;
}

template <typename T> // painter's algorithm
Posi(T) List<T>::selectMax(Posi(T) p, int n){ // 从起始于位置p 后 n个元素中选出最大者(包括p)
    Posi(T) max = p; //最大者暂定为首节点p
    for(Posi(T) curr = p; 1<n; n--){
        if(max->data <= (curr=curr->succ)->data)
            max = curr; //更新最大元素位置记录
    }
    return max;
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
    while(trailer != (p = p->succ)){ // 从第二个节点开始 //依次直到末节点
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

template <typename T>
void List<T>::selectionSort(Posi(T) p, int n){ // 对列表中起始于位置p的连续n个元素做选择排序
    Posi(T) head = p->pred; Posi(T) trail = p; // 待排区间(head, tail)
    for(int i=0; i<n; i++) trail = trail->succ;
    while(1 < n){
        insertBefore(trail, remove(selectMax(head->succ, n)));
        trail = trail->pred; n--;
    }
}

template <typename T>
void List<T>::insertionSort(Posi(T) p, int n){ // 对列表中起始于位置p的连续n个元素做选择排序
    for(int r=0; r<n; r++){
        insertAfter(search(p->data, r, p), p->data);
        p = p->succ; remove(p->pred); // 转向下一个节点
    }
} // in-place




/*******************************************************
* 测试
*******************************************************/ 
int main(){

    List<int> listTest1;
    listTest1.init(); //初始化，创建header和trailer

    const int NUM = 15;
    int elem;
    for(int i=0; i<NUM; i++){
        elem = rand()%10;
        cout << "*" << elem << "*";
        listTest1.insertAsLast(elem);
    }    
    cout << endl;

    Posi(int) listNodeFirst = listTest1.first();
    Posi(int) listNodeLast = listTest1.last();
    cout << "First Node's data is " << listNodeFirst->data;
    cout << "; Second Node's data is " << (listNodeFirst->succ)->data;
    cout << "; Last Node's data is " << listNodeLast->data << endl;

    int dupNum = listTest1.deduplicate();
    Posi(int) p = listTest1.first();
    int leftNum = NUM-dupNum;
    for(int i=0; i<leftNum; i++){
        cout << "*" << p->data << "*";
        p = p->succ;
    }
    cout << " dupNum is " << dupNum << endl;

    p = listTest1.first();
    listTest1.selectionSort(p, leftNum);
    for(int i=0; i<leftNum; i++){
        cout << "*" << p->data << "*";
        p = p->succ;
    }
    cout << " Sorted List " << endl;

    int target = 7;
    Posi(int) tarPos = listTest1.search(target, leftNum, listTest1.last());
    cout << "Target " << target << " is at " << tarPos << " where data is " << tarPos->data << endl;


}





