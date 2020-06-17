#include <iostream>
#include<vector>
using namespace std;

//通常有两种形式：函数模板和类模板；
//使用模板的目的就是能够让程序员编写与类型无关的代码。

template<typename T>  //函数模板 针对仅参数类型不同的函数；
inline T Max(T &a, T &b){
    return a>b ? a:b;
}

template<class T>
class STACK{
private:
    vector<T> elems;
public:
    void push(T const&);
    void pop();
    T top() const;
    bool isEmpty(){
        return elems.empty();
    }
};

template<class T>
void STACK<T>::push(T const& elem){
    // 追加传入元素的副本
    elems.push_back(elem);
}

template<class T>
void STACK<T>::pop(){
    if(elems.empty()){
        throw out_of_range("Stack<>::pop(): empty stack");
    }
    // 删除最后一个元素
    elems.pop_back();
}

template<class T>
T STACK<T>::top() const{
    if(elems.empty()){
        throw out_of_range("Stack<>::pop(): empty stack");
    }
    // 返回最后一个元素的副本 
    return elems.back();   
}

int main(){
    static int MAX = 7;
    int testNum[MAX] = {2, 3, 1, 0, 2, 5, 3};
    vector<int> nums(testNum, testNum+MAX);
    cout << nums[1] << endl;

    int a = 10, b = 6;
    cout << "Max(a, b): " << Max(a, b) << endl;

    float aa = 2.3, bb = 5.4;
    cout << "Max(aa, bb): " << Max(aa, bb) << endl;

    

    try{
        STACK<int> intStack;  // int 类型的栈 
        STACK<string> stringStack;  // string 类型的栈 

        intStack.push(1); intStack.push(2);
        cout << "intStack.top() is " << intStack.top() <<endl;
        intStack.push(9); intStack.push(29); intStack.pop();
        cout << "intStack.top() is " << intStack.top() <<endl;

        // 操作 string 类型的栈 
        stringStack.push("Hellow W"); stringStack.push("LLLDDDDP");
        cout << "stringStack.top() is " << stringStack.top() << std::endl; 
        stringStack.pop();
        cout << "stringStack.top() is " << stringStack.top() << std::endl;
        stringStack.pop();
        cout << "stringStack.top() is " << stringStack.top() << std::endl;
    }catch(exception const &ex){
        cerr << "Exception: " << ex.what() <<endl; 
        return -1;
    }

}





