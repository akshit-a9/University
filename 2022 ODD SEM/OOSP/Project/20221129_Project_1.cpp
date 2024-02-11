#include<iostream>
//#include<bits/stdc++.h>
#include<string>
#include<sstream>
using namespace std;

class student
{
protected:
    string fname, lname, roll, fatherfname, fatherlname, course, phno, mailid, parentphno, parentmailid;
    int semester, batch;
    static int st;

public:
    void enterdata()
    {
        st++;
        cout<<"\n";
        cout<<"ENTER THE DATA FOR STUDENT NUMBER "<<st<<endl;
        cout<<"ENTER THE FIRST NAME OF THE STUDENT\n";
        cin>>fname;
        cout<<"ENTER THE LAST NAME OF THE STUDENT\n";
        cin>>lname;
        cout<<"ENTER THE ENROLLMENT NUMBER OF THE STUDENT\n";
        cin>>roll;
        cout<<"ENTER THE FATHER'S FIRST NAME OF THE STUDENT\n";
        cin>>fatherfname;
        cout<<"ENTER THE FATHER'S LAST NAME OF THE STUDENT\n";
        cin>>fatherlname;
        cout<<"ENTER THE COURSE OPTED FOR\n";
        cin>>course;
        cout<<"ENTER THE CURRENT SEMESTER\n";
        cin>>semester;
        cout<<"ENTER THE BATCH\n";
        cin>>batch;
        cout<<"ENTER THE STUDENT'S PHONE NUMBER\n";
        cin>>phno;
        cout<<"ENTER THE FATHER'S PHONE NUMBER\n";
        cin>>parentphno;
        cout<<"ENTER THE STUDENT'S MAIL ID\n";
        cin>>mailid;
        cout<<"ENTER THE FATHER'S MAIL ID\n";
        cin>>parentmailid;
    }
};
int student :: st = 0;
class personal_info : virtual public student
{
private:
    int row, column, spaces;
public:
    void disp_personal_info()
    {
       for(row = 1; row <= 11; row++)
       {
           for(column = 1; column <= 20; column++)
           {
               if(row % 2 == 1)
               {
                   cout<<"-";
               }

               else if(row == 2)
               {
                   cout<<"| ENROLLMENT NUMBER";
                   for(int i = 1; i < 2; i++)
                   {
                       cout<<" ";
                   }
                   column = column + 19;
               }

               else if(row == 4)
               {
                   cout<<"| NAME";
                   for(int i = 1; i < 15; i++)
                   {
                       cout<<" ";
                   }
                   column = column + 19;
               }

               else if(row == 6)
               {
                   cout<<"| PHONE NUMBER";
                   for(int i = 1; i < 7; i++)
                   {
                       cout<<" ";
                   }
                   column = column + 19;
               }

               else if(row == 8)
               {
                   cout<<"| E-MAIL ID";
                   for(int i = 1; i < 10; i++)
                   {
                       cout<<" ";
                   }
                   column = column + 19;
               }
               else if(row == 10)
               {
                   cout<<"| SEMESTER";
                   for(int i = 1; i < 11; i++)
                   {
                       cout<<" ";
                   }
                   column = column + 19;
               }
           }
           for(column = 21; column < 22; column++)
           {
               cout<<"|";
           }
           for(column = 27; column <= 60; column++)
           {
               if(row % 2 == 1)
               {
                   cout<<"-";
               }

               else if(row == 2)
               {
                   string q = roll;
                   cout<<" " + q;
                   int lq = q.length();
                   for(int i = 1; i <= 34 - lq; i++)
                   {
                       cout<<" ";
                   }
                   //cout<<"|";
                   column = column + 50;
               }

               else if(row == 4)
               {
                   string q = fname +" "+  lname;
                   cout<<" " + q;
                   int lq = q.length();
                   for(int i = 1; i <= 33 - lq; i++)
                   {
                       cout<<" ";
                   }
                   cout<<"|";
                   column = column + 50;
               }
               else if(row == 6)
               {
                   string q = phno;
                   cout<<" " + q;
                   int lq = q.length();
                   for(int i = 1; i <= 33 - lq; i++)
                   {
                       cout<<" ";
                   }
                   cout<<"|";
                   column = column + 50;
               }
               else if(row == 8)
               {
                   string q = mailid;
                   cout<<" " + q;
                   int lq = q.length();
                   for(int i = 1; i <= 33 - lq; i++)
                   {
                       cout<<" ";
                   }
                   cout<<"|";
                   column = column + 50;
               }
               else if(row == 10)
               {
                   string q = to_string(semester);
                   cout<<" " + q;
                   int lq = q.length();
                   for(int i = 1; i <= 33 - lq; i++)
                   {
                       cout<<" ";
                   }
                   cout<<"|";
                   column = column + 50;
               }

           }
           for(column = 61; column <= 83; column++)
           {
               if(row % 2 == 1)
               {
                   cout<<"-";
               }

               else if(row == 2)
               {
                   for(int i = 1; i <= 22; i++)
                   {
                       cout<<" ";
                   }
                   //cout<<"|";
                   column = column + 115;
               }

               else if(row == 4)
               {
                   cout<<" FATHER'S NAME";
                   for(int i = 1; i < 10; i++)
                   {
                       cout<<" ";
                   }
                   cout<<"|";
                   column = column + 83;
               }

               else if(row == 6)
               {
                   cout<<" FATHER'S PHONE NUMBER";
                   for(int i = 1; i < 2; i++)
                   {
                       cout<<" ";
                   }
                   cout<<"|";
                   column = column + 83;
               }

              else if(row == 8)
              {
                  cout<<" FATHER'S MAIL ID";
                  for(int i = 1; i < 7; i++)
                  {
                      cout<<" ";
                  }
                  cout<<"|";
                  column = column + 83;
              }

               else if(row == 10)
               {
                   cout<<" BATCH";
                   for(int i = 1; i < 18; i++)
                   {
                       cout<<" ";
                   }
                   cout<<"|";
                   column = column + 83;
               }

           }

           for(column = 84; column <= 117; column++)
           {
               if(row % 2 == 1)
               {
                   cout<<"-";
               }

               else if(row == 2)
               {
                   for(int i = 1; i <= 33; i++)
                   {
                       cout<<" ";
                   }
                   cout<<"|";
                   column = column + 116;
               }

               else if(row == 4)
               {
                   string q = fatherfname +" "+  fatherlname;
                   cout<<" " + q;
                   int lq = q.length();
                   for(int i = 1; i <= 30 - lq; i++)
                   {
                       cout<<" ";
                   }
                   cout<<"|";
                   column = column + 115;
               }
               else if(row == 6)
               {
                   string q = parentphno;
                   cout<<" " + q;
                   int lq = q.length();
                   for(int i = 1; i <= 30 - lq; i++)
                   {
                       cout<<" ";
                   }
                   cout<<"|";
                   column = column + 115;
               }
               else if(row == 8)
               {
                   string q = parentmailid;
                   cout<<" " +q;
                   int lq = q.length();
                   for(int i = 1; i <= 30 - lq; i++)
                   {
                       cout<<" ";
                   }
                   cout<<"|";
                   column = column + 115;
               }
               else if(row == 10)
               {
                   string q = to_string(batch);
                   cout<<" " + q;
                   int lq = q.length();
                   for(int i = 1; i <= 30 - lq; i++)
                   {
                       cout<<" ";
                   }
                   cout<<"|";
                   column = column + 115;
               }

           }
           cout<<"\n";

       }
    }
};

int main()
{
    int a;
    cout<<"ENTER THE NUMBER OF STUDENTS IN THE CLASS\n";
    cin>>a;
    personal_info arr[a];
    for(int i = 0; i < a; i++)
    {
        personal_info arr[i];
    }

    for(int i = 0; i < a; i++)
    {
        arr[i].enterdata();
//        arr[i].disp_personal_info();
    }
    int j;
    string s1;
    for(int i = 0; i <= 200; i++)
    {
        cout<<"ENTER THE ROLL NUMBER OF THE STUDENT IN THE CLASS WHOSE DATA YOU WOULD LIKE TO SEE\n";
        cin>>j;

        if(j > a)
        {
            cout<<"INVALID INPUT\nTOTAL NUMBER OF STUDENTS = "<<a<<endl;
            cout<<"ENTER A NUMBER BETWEEN 1 AND "<<a<<endl;

            continue;
        }
        arr[j-1].disp_personal_info();

        cout<<"DO YOU WISH TO CONTINUE\nPRESS Y FOR YES\nPRESS N FOR NO\n";
        cin>>s1;

        if( s1 == "N")
        {
            break;
        }
        else if( s1 == "Y")
        {
            continue;
        }

    }

}