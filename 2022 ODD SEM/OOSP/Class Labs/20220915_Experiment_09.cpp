#include<iostream>
using namespace std;

float miles, kms;

class distance1
{
    public:
        float dist_miles;
        float equi_kms;

        void convert1()
        {
            equi_kms = 1.60934 * dist_miles;
        }
};

class distance2 : public distance1   //Imnherits public data members and member functions from distance1
{
    public:
        float dist_kms;
        float equi_miles;

        void convert2()
        {
            equi_miles = 0.621371 * dist_kms;
        }

        void sum(distance2 obj)
        {
            miles = obj.dist_miles + obj.equi_miles;
            kms = obj.equi_kms + obj.dist_kms;
        }
};

int main()
{
    float a, b;
    int choice;

    cout<<"Enter the distance in miles : "<<endl;
    cin>>a;
    cout<<"Enter the distance in kms : "<<endl;
    cin>>b;

    distance2 ob;
    ob.dist_miles = a;
    ob.convert1();
    ob.dist_kms = b;
    ob.convert2();
    ob.sum(ob);

    cout<<"What format do you want the output in? \nEnter 1 for Miles \nEnter 2 for Kilometers"<<endl;
    cin>>choice;
    if(choice == 1)
        cout<<"The total distance is "<<miles<<" miles.";
    if(choice == 2)
        cout<<"The total distance is "<<kms<<" kilometers.";
}