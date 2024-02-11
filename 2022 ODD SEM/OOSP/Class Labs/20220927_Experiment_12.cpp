#include <iostream>
using namespace std;

class Building
{
private:
int height; int width;
public:
Building(
}
~Building(X)
virtual void getdata()
{
cout << "Enter a height: ' cin >> height;
cout << "Enter width: "; cin >> width;
}
virtual void putdata()

{
cout << "Building height is: " << height << "n";
cout << "Building width is: " << width<<"In";
}
};
class height: public Building
{
private:
int high;
public:
height()ft
-height()f}
virtual void getdata({
Building :getdata();
cout << "Enter height: ";
cin >> high;
}
virtual void putdata()
{
cout << "Height is : " << high << "In";
}
};
class width : public Building
{
private:
int wide;
public:
width(<?
~width(k)
virtual void getdata(
Building getdata();
cout << "Enter width: ".
cin >> wide;
}
virtual void putdata()
{
cout << "width is:"<< wide << in"
}
};

class Feet: public height, public with {
private:
int feeh; int feew;

public:
Feet()}
-Feet())
virtual void getdata(§{
cout << "Enter the hight in Feet: ". cin >> feeh;
cout << "Enter the width in Feet:". cIn >> feew;
}
virtual void putdata()
{
cout << "Height in feet is : " << feeh << "In".
cout <<"Width in feet is:"<< feew <<mn"
};
class Inches : public height, public width
{ private:
int inchh; int inchw;
public:
Inches()f
~Inches)n
virtual void getdata(§{
cout << "Enter the Height in Inches. !. cin >> inchh;
cout << "Enter the width in Inches: ". cin >> inchw;
}
virtual void putdata()
{
cout << "Height in inches is: " << inchh

cout s< Width in inches is " «s inchw
}
};

int main(void){
Feet* new_fee = new Feet);
new _fee-> getdata(); cout<<"In";
Inches* new inch = new inches()

new_inch-> getdata();
cout<<"In" new fee->putdata();
new inch->putdata();
return 0;
}
