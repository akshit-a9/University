//Implement a class 'circle', compute its area. Also, it must have atleast one overloaded operator.

#include<iostream>
#include<math.h>
using namespace std;

class circle
{
    private:
        int x, y;
        float area;
    public:
        circle(int p1, int p2)
        {
            x = p1;
            y = p2;
        }

        circle operator + (circle &obj)
        {
            circle c;
            c.x = x- obj.x;
            c.y = y- obj.y;
            return c;
        }

        void compute()
        {
            area = (3.14)*(pow(sqrt((y*y) + (x*x))), 2);
        }

        int print()
        {
            return area;
        }
};

int main()
{
    int x1, y1, x2, y2;

    cout<<"Enter the coordinates of the center : ";
    cin>>x1>>y1;
    cout<<"Enter the coordinates of teh circle : ";
    cin>>x2>>y2;

    circle c1(x1,y1) , c2(x2,y2);
    circle c3 = c1 + c2;

    cout<<"The area of the circle is : "<<c3.print();

    return 0;
}