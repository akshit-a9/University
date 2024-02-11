// //Define two classes distance1 and distance2 in c++. distance1 stores the distance in miles and distance2 stores the distance in kilometers and meters.
// //WAP that reads values of class objects and adds one object of distance1 with an object of distance2. Display units as asked for by the user.
// ///Make use of friend function

// #include<iostream>
// using namespace std;

// float miles, kilometers;

// class distance2;

// class distance1
// {
//     private:
//         float distance_in_miles;
//         float equivalant_kilometers;
//     public:

//         void convert()
//         {
//             equivalant_kilometers = 1.61* distance_in_miles;
//         }
//         distance1(float inp)
//         {
//             distance_in_miles = inp;
//             convert();
//         }

//         friend void result_sum(distance1, distance2);
// };

// class distance2
// {
//     private:
//         float distance_in_kilometers;
//         float equivalant_miles;
//     public:

//         void convert()
//         {
//             equivalant_miles = 0.62 * distance_in_kilometers;
//         }

//         distance2(float inp)
//         {
//             distance_in_kilometers = inp;
//             convert();
//         }

//         friend void result_sum(distance1, distance2);
// };

// void result_sum(distance1 a, distance2 b)
// {
//     miles = a.distance_in_miles + b.equivalant_miles;
//     kilometers = a.equivalant_kilometers + b.distance_in_kilometers;
// }

// int main()
// {
//     int choose;
//     float input_1, input_2;

//     cout<<"Enter the distance in miles : "<<endl;
//     cin>>input_1;
//     cout<<"Enter the distance in kms : "<<endl;
//     cin>>input_2;

//     distance1 object_1(input_1);
//     distance2 object_2(input_2);

//     result_sum(object_1, object_2);

//     cout<<"What format do you want the output in? \nEnter 1 for Miles \nEnter 2 for Kilometers"<<endl;
//     cin>>choose;
//     if(choose == 1)
//         cout<<"The total distance is "<<miles<<" miles.";
//     else
//         cout<<"The total distance is "<<kilometers<<" kilometers.";
// }

//Define two classes distance1 and distance2 in c++. distance1 stores the distance in miles and distance2 stores the distance in kilometers and meters.
//WAP that reads values of class objects and adds one object of distance1 with an object of distance2. Display units as asked for by the user.
///Make use of friend function

#include<iostream>
using namespace std;

float miles, kms;

class distance2;

class distance1
{
    private:
        float dist_miles;
        float equi_kms;
    public:
        distance1(float x)
        {
            dist_miles = x;
            convert();
        }

        void convert()
        {
            equi_kms = 1.60934 * dist_miles;
        }

        friend void sum(distance1, distance2);
};

class distance2
{
    private:
        float dist_kms;
        float equi_miles;
    public:
        distance2(float y)
        {
            dist_kms = y;
            convert();
        }

        void convert()
        {
            equi_miles = 0.621371 * dist_kms;
        }

        friend void sum(distance1, distance2);
};

void sum(distance1 obj1, distance2 obj2)
{
    miles = obj1.dist_miles + obj2.equi_miles;
    kms = obj1.equi_kms + obj2.dist_kms;
}

int main()
{
    float a, b;
    int choice;

    cout<<"Enter the distance in miles : "<<endl;
    cin>>a;
    cout<<"Enter the distance in kms : "<<endl;
    cin>>b;

    distance1 d1(a);
    distance2 d2(b);

    sum(d1, d2);

    cout<<"What format do you want the output in? \nEnter 1 for Miles \nEnter 2 for Kilometers"<<endl;
    cin>>choice;
    if(choice == 1)
        cout<<"The total distance is "<<miles<<" miles.";
    if(choice == 2)
        cout<<"The total distance is "<<kms<<" kilometers.";
}