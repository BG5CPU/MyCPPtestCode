/**************************************** 
**class List
****************************************/

#include "ListNode.h"

typedef int Rank;


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
    Posi(T) insertAsLast(T const& e);
    void copyNodes(Posi(T) p, Rank n);
    T remove(Posi(T) p);
    int clean();
    int deduplicate(); // 无序向量
};





