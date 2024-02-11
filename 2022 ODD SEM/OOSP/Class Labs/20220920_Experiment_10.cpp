// Imagine a publishing company that markets both books and audio- cassette version 
// of its works. Create a class Publication in C++ that stores the title (a string) and price 
// (type float) of a publication. From this class derive two classes: Book, which adds a 
// page count and Tape, which adds playing time in minutes. These classes should have 
// getdata() function to get its data from the user and the putdata() function to display 
// its data. Write a main() program to test the book and tape classes by creating 
// instances of them, asking the user to fill in their data with getdata() and displaying 
// the data with putdata(). 

#include<iostream>
#include<string>
using namespace std;

class Publication
{
    public:
        string title;
        float price;
};

class Book : public Publication
{
    public:
        int page_count;
        
        void getdata()
        {
            cout<<"Enter the title of the Book : "<<endl;
            cin>>title;
            cout<<"Enter the price of the book (in USD) : "<<endl;
            cin>>price;
            cout<<"Enter the number of pages : "<<endl;
            cin>>page_count;
        }

        void putdata()
        {
            cout<<"Title : "<<title<<endl<<"Price: "<<price<<endl<<"Page Count : "<<page_count<<endl<<endl;
        }
};

class Tape : public Publication
{
    public: 
        float play_time;

        void getdata()
        {
            cout<<"Enter the title of the Tape : "<<endl;
            cin>>title;
            cout<<"Enter the price of the tape (in USD) : "<<endl;
            cin>>price;
            cout<<"Enter the runtime (in minutes) : "<<endl;
            cin>>play_time;
        }

        void putdata()
        {
            cout<<"Title : "<<title<<endl<<"Price: "<<price<<endl<<"Run Time : "<<play_time<<endl<<endl;
        }
};

int main()
{
    // Book b1;
    // b1.getdata();

    // Tape t1;
    // t1.getdata();

    // b1.putdata();
    // t1.putdata();

    int numb, numt;
    cout<<"Enter the number of books to be entered : (Max 50)"<<endl;
    cin>>numb;
    cout<<"Enter the number of tapes to be entered : (Max 50)"<<endl;
    cin>>numt;

    Book dat[50];
    Tape tap[50];

    for (int i = 0; i<numb; i++)
    {
        cout<<endl<<"Book "<<i+1<<" : "<<endl;
        dat[i].getdata();
    }

    for (int i = 0; i<numt; i++)
    {
        cout<<endl<<"Tape "<<i+1<<" : "<<endl;
        tap[i].getdata();
    }

    cout<<endl<<endl<<"Entered Data : "<<endl;

    for (int i = 0; i<numb; i++)
    {
        cout<<endl<<"Book "<<i+1<<" : "<<endl;
        dat[i].putdata();
    }

    for (int i = 0; i<numt; i++)
    {
        cout<<endl<<"Tape "<<i+1<<" : "<<endl;
        tap[i].putdata();

    }
}