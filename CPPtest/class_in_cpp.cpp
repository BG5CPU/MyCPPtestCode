#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class BOX
{
    public:
        static int BoxCount;
        float length;
        float breadth;
        float height;
        
        // 成员函数定义（可以在里面定义）
        float getVolume(void)
        {
            return length*breadth*height;
        }
        // 成员函数声明
        void setLength(float len);
        void setBreadth(float bre);
        void setHeight(float hei);
        void setWidth(float wid);
        float getWidth(void);
   
    private:
        float width;
};

class LINE
{
    public:
        void setLength(float len);
        float getLength(void);
        /*构造函数可用于为某些成员变量设置初始值*/
        LINE(float len, int id);  // 这是构造函数声明
        /*析构函数有助于在跳出程序
        （比如关闭文件、释放内存等）前释放资源。*/
        ~LINE(void);  // 这是析构函数声明

        float SquareArea()
        {
            return length*length;
        }

        bool IsBigger(LINE line)
        {
            return this->SquareArea() >line.SquareArea();
        }
    
    private:
        float length;
        int line_id;
};

// 初始化类 Box 的静态成员
int BOX::BoxCount = 0;  // 必须先初始化
// 成员函数定义（可以在外面用::定义）
void BOX::setLength(float len)
{
    length = len;
}
void BOX::setBreadth(float bre)
{
    breadth = bre;
}
void BOX::setHeight(float hei)
{
    height = hei;
}
void BOX::setWidth(float wid)
{
    width = wid;
}
float BOX::getWidth(void)
{
    return width;
}

// FOR LINE
void LINE::setLength(float len)
{
    length = len;
}
float LINE::getLength(void)
{
    return length;
}
LINE::LINE(float len, int id)  // 构造函数
{
    length = len;
    line_id = id;
    cout << "Object " << line_id << " is being created, length = " << length << endl;
}
LINE::~LINE(void)
{
    cout << "Object " << line_id << " is being deleted" << endl;
}

int main()
{
    BOX *ptrbox;
    BOX box1;
    float volume;

    box1.length = 1.2; box1.breadth = 2.1; box1.height = 3.0;
    volume = (box1.length)*(box1.breadth)*(box1.height);
    cout << "volume of box1 is " << volume << endl;
    BOX::BoxCount += 1; 
    cout << "Count of box1 is " << BOX::BoxCount << endl;

    BOX box2;
    box2.setLength(0.6); box2.setBreadth(2.1); box2.setHeight(3.0);
    ptrbox = &box2;
    cout << "volume of box2 is " << ptrbox->getVolume() << endl;
    BOX::BoxCount += 1; 
    cout << "Count of box2 is " << BOX::BoxCount << endl;

    // box2.width = 10; // Error: width is private
    // box2.setWidth(10);
    ptrbox->setWidth(10);
    cout << "width of box2 is " << box2.getWidth() << endl;

    LINE line1(6.66, 1);
    cout << "Length of line is: " << line1.getLength() <<endl;
    line1.setLength(3.32); 
    cout << "Length of line is: " << line1.getLength() <<endl;

    LINE line2(3.33, 2);
    cout << "Square area of line2 is " << line2.SquareArea() <<endl;
    if(line1.IsBigger(line2))
    {
        cout << "Square area of line1 is bigger than line2" <<endl;
    }else
    {
        cout << "Square area of line2 is bigger than line1" <<endl;
    }
    
    
}


