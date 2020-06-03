#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class SHAPE
{
public:
    void setLength(float len)
    {
        length = len;
    }
    void setBreadth(float bre)
    {
        breadth = bre;
    }
    void setHeight(float hei)
    {
        height = hei;
    }
protected:
    float length;
    float breadth;
    float height;
};

class COST
{
public:
    void setUnitPrice(float u_p)
    {
        unit_price = u_p;
    }
    float getCost(float area)
    {
        return unit_price*area;
    }
protected:
    float unit_price;
};

class RECTANGLE: public SHAPE, public COST
{
public:
    float getArea()
    {
        return (length*breadth);
    }
};



int main()
{
    RECTANGLE Rect1;
    Rect1.setLength(12.2); Rect1.setBreadth(2.3);
    // 输出对象的面积
    float area = Rect1.getArea();
    cout << "Area of Rect1 is " << area << endl;
    Rect1.setUnitPrice(10.4);
    cout << "Paint cost of Rect1 is " << Rect1.getCost(area) << endl;
    
}





