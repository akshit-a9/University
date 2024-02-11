#include<iostream>
//#include<bits/stdc++.h>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;

class student
{
protected:
    string fname, lname, roll, fatherfname, fatherlname, course, phno, newph, mailid, newmailid, parentphno, newfatherph, newfathermailid, parentmailid;
    string newfname1, newlname1,newfname2, newlname2, newfname3, newlname3, newfname4, newlname4, newfname5, newlname5;
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
        // DEMONSTRATION OF HOW EXCEPTION HANDLING WORKS
        try
        {
            if (semester<1)
            {
               throw semester;
            }

        }
        catch(int x)
        {
            cout<<"Enter a positive number !!!"<<endl;
            cout<<"Enter correct semester :"<<endl;
            cin>>semester;
        }
        cout<<"ENTER THE BATCH\n";
        cin>>batch;
        
        cout<<"ENTER THE STUDENT'S PHONE NUMBER\n";
        cin>>newph;
        phno = newph;
        cout<<"ENTER THE FATHER'S PHONE NUMBER\n";
        cin>>newfatherph;
        parentphno = newfatherph;
        cout<<"ENTER THE STUDENT'S MAIL ID\n";
        cin>>newmailid;
        mailid = newmailid;
        cout<<"ENTER THE FATHER'S MAIL ID\n";
        cin>>newfathermailid;
        parentmailid = newfathermailid;

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

class exam_info : virtual public student
{
protected:
    string subject1, subject2, subject3, subject4, subject5;
    string fname1, fname2, fname3, fname4, fname5;
    string lname1, lname2, lname3, lname4, lname5;
    int row, column;

public:
    void get_exam_info()
    {
        cout << "ENTER THE NAME OF SUBJECT 1" <<"\n";
        cin >> subject1;
        cout << "ENTER THE FIRST NAME OF THE FACULTY ASSOCIATED WITH " << subject1<<"\n";
        cin>>fname1;
        cout<<"ENTER THE LAST NAME OF THE FACULTY ASSOCIATED WITH "<<subject1<<"\n";
        cin>>lname1;
        cout << "ENTER THE NAME OF SUBJECT 2" <<"\n";
        cin >> subject2;
        cout << "ENTER THE FIRST NAME OF THE FACULTY ASSOCIATED WITH " << subject2<<"\n";
        cin>>fname2;
        cout<<"ENTER THE LAST NAME OF THE FACULTY ASSOCIATED WITH "<<subject2<<"\n";
        cin>>lname2;
        cout << "ENTER THE NAME OF SUBJECT 3" <<"\n";
        cin >> subject3;
        cout << "ENTER THE FIRST NAME OF THE FACULTY ASSOCIATED WITH " << subject3<<"\n";
        cin>>fname3;
        cout<<"ENTER THE LAST NAME OF THE FACULTY ASSOCIATED WITH "<<subject3<<"\n";
        cin>>lname3;
        cout << "ENTER THE NAME OF SUBJECT 4" <<"\n";
        cin >> subject4;
        cout << "ENTER THE FIRST NAME OF THE FACULTY ASSOCIATED WITH " << subject4<<"\n";
        cin>>fname4;
        cout<<"ENTER THE LAST NAME OF THE FACULTY ASSOCIATED WITH "<<subject4<<"\n";
        cin>>lname4;
        cout << "ENTER THE NAME OF SUBJECT 5" <<"\n";
        cin >> subject5;
        cout << "ENTER THE FIRST NAME OF THE FACULTY ASSOCIATED WITH " << subject5<<"\n";
        cin>>fname5;
        cout<<"ENTER THE LAST NAME OF THE FACULTY ASSOCIATED WITH "<<subject5<<"\n";
        cin>>lname5;
    }

    void disp_exam_info()
    {
        for(row = 1; row <= 11; row++) {
            for (column = 1; column <= 20; column++) {
                if (row % 2 == 1) {
                    cout << "-";
                } else if (row == 2) {
                    cout << "| " << subject1;
                    int x = subject1.length();
                    for (int i = 1; i < 19 - x; i++) {
                        cout << " ";
                    }
                    column = column + 19;
                } else if (row == 4) {
                    cout << "| " << subject2;
                    int x = subject2.length();
                    for (int i = 1; i < 19 - x; i++) {
                        cout << " ";
                    }
                    column = column + 19;
                } else if (row == 6) {
                    cout << "| " << subject3;
                    int x = subject3.length();
                    for (int i = 1; i < 19 - x; i++) {
                        cout << " ";
                    }
                    column = column + 19;
                } else if (row == 8) {
                    cout << "| " << subject4;
                    int x = subject4.length();
                    for (int i = 1; i < 19 - x; i++) {
                        cout << " ";
                    }
                    column = column + 19;
                } else if (row == 10) {
                    cout << "| " << subject5;
                    int x = subject5.length();
                    for (int i = 1; i < 19 - x; i++)
                    {
                        cout << " ";
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
                    string q = fname1 + " " + lname1;
                    cout<<" " + q;
                    int lq = q.length();
                    for(int i = 1; i <= 32 - lq; i++)
                    {
                        cout<<" ";
                    }
                    cout<<"|";
                    column = column + 50;
                }

                else if(row == 4)
                {
                    string q = fname2 +" "+  lname2;
                    cout<<" " + q;
                    int lq = q.length();
                    for(int i = 1; i <= 32 - lq; i++)
                    {
                        cout<<" ";
                    }
                    cout<<"|";
                    column = column + 50;
                }
                else if(row == 6)
                {
                    string q = fname3 +" "+  lname3;
                    cout<<" " + q;
                    int lq = q.length();
                    for(int i = 1; i <= 32 - lq; i++)
                    {
                        cout<<" ";
                    }
                    cout<<"|";
                    column = column + 50;
                }
                else if(row == 8)
                {
                    string q = fname4 +" "+  lname4;
                    cout<<" " + q;
                    int lq = q.length();
                    for(int i = 1; i <= 32 - lq; i++)
                    {
                        cout<<" ";
                    }
                    cout<<"|";
                    column = column + 50;
                }
                else if(row == 10)
                {
                    string q = fname5 +" "+  lname5;
                    cout<<" " + q;
                    int lq = q.length();
                    for(int i = 1; i <= 32 - lq; i++)
                    {
                        cout<<" ";
                    }
                    cout<<"|";
                    column = column + 50;
                }

            }
            cout<<"\n";
        }

    }
};

class final :  public exam_info, public personal_info {
private:
    string a, b, c;
public:
    void updatedata() {
        cout<< "WHAT TYPE OF INFORMATION WOULD YOU LIKE TO UPDATE\nPRESS P FOR PERSONAL INFORMATION\nPRESS A FOR ACADEMIC INFORMATION\n";
        cin >> a;

        if (a == "P") {
            cout << "WHOSE INFORMATION WOULD YOU LIKE TO UPDATE\nPRESS S FOR STUDENT\nPRESS F FOR FATHER\n";
            cin >> b;

            if (b == "S") {
                cout << "WHAT WOULD YOU LIKE TO UPDATE\nPRESS PH FOR PHONE NUMBER\nPRESS M FOR MAIL ID\n";
                cin >> c;

                if (c == "PH") {
                    cout << "ENTER THE NEW PHONE NUMBER\n";
                    cin >> newph;
                    phno = newph;
                } else if (c == "M") {
                    cout << "ENTER THE NEW MAIL ID\n";
                    cin >> newmailid;
                    mailid = newmailid;
                }

            }

            if (b == "F") {
                cout << "WHAT WOULD YOU LIKE TO UPDATE\nPRESS PH FOR PHONE NUMBER\nPRESS M FOR MAIL ID";
                cin >> c;

                if (c == "PH") {
                    cout << "ENTER THE NEW PHONE NUMBER\n";
                    cin >> newfatherph;
                    parentphno = newfatherph;
                } else if (c == "M") {
                    cout << "ENTER THE NEW MAIL ID\n";
                    cin >> newfathermailid;
                    parentmailid = newfathermailid;
                }

            }
            
            disp_personal_info();
        }

        if (a == "A")
        {
            cout << "ENTER THE SUBJECT NUMBER OF THE SUBJECT WHOSE INFORMATION YOU WOULD LIKE TO UPDATE\n";
            cin >> b;

            cout << "WHAT WOULD YOU LIKE TO UPDATE\nPRESS F FOR FIRST NAME\nPRESS L FOR LAST NAME\nPRESS B FOR BOTH\n";
            cin >> c;

            if (b == "1" || b == subject1) {
                if (c == "F") {
                    cout << "ENTER THE NEW FIRST NAME\n";
                    cin >> newfname1;
                    fname1 = newfname1;
                } else if (c == "L") {
                    cout << "ENTER THE NEW LAST NAME\n";
                    cin >> newlname1;
                    lname1 = newlname1;
                } else if (c == "B") {
                    cout << "ENTER THE NEW FIRST NAME\n";
                    cin >> newfname1;
                    cout << "ENTER THE NEW LAST NAME\n";
                    cin >> newlname1;
                    fname1 = newfname1;
                    lname1 = newlname1;
                }
            } else if (b == "2" || b == subject2) {
                if (c == "F") {
                    cout << "ENTER THE NEW FIRST NAME\n";
                    cin >> newfname2;
                    fname2 = newfname2;
                } else if (c == "L") {
                    cout << "ENTER THE NEW LAST NAME\n";
                    cin >> newlname2;
                    lname2 = newfname2;
                } else if (c == "B") {
                    cout << "ENTER THE NEW FIRST NAME\n";
                    cin >> newfname2;
                    cout << "ENTER THE NEW LAST NAME\n";
                    cin >> newlname2;
                    fname2 = newfname2;
                    lname2 = newlname2;
                }

            } else if (b == "3" || b == subject3) {
                if (c == "F") {
                    cout << "ENTER THE NEW FIRST NAME\n";
                    cin >> newfname3;
                    fname3 = newfname3;
                } else if (c == "L") {
                    cout << "ENTER THE NEW LAST NAME\n";
                    cin >> newlname3;
                    lname3 = newlname3;
                } else if (c == "B") {
                    cout << "ENTER THE NEW FIRST NAME\n";
                    cin >> newfname3;
                    cout << "ENTER THE NEW LAST NAME\n";
                    cin >> newlname3;
                    fname3 = newfname3;
                    lname3 = newlname3;
                }

            } else if (b == "4" || b == subject4) {
                if (c == "F") {
                    cout << "ENTER THE NEW FIRST NAME\n";
                    cin >> newfname4;
                    fname4 = newfname4;
                } else if (c == "L") {
                    cout << "ENTER THE NEW LAST NAME\n";
                    cin >> newlname4;
                    lname4 = newlname4;
                } else if (c == "B") {
                    cout << "ENTER THE NEW FIRST NAME\n";
                    cin >> newfname4;
                    cout << "ENTER THE NEW LAST NAME\n";
                    cin >> newlname4;
                    fname4 = newfname4;
                    lname4 = newlname4;
                }

            } else if (b == "5" || b == subject5) {
                if (c == "F") {
                    cout << "ENTER THE NEW FIRST NAME\n";
                    cin >> newfname5;
                    fname5 = newfname5;
                } else if (c == "L") {
                    cout << "ENTER THE NEW LAST NAME\n";
                    cin >> newlname5;
                    lname5 = newlname5;
                } else if (c == "B") {
                    cout << "ENTER THE NEW FIRST NAME\n";
                    cin >> newfname5;
                    cout << "ENTER THE NEW LAST NAME\n";
                    cin >> newlname5;
                    fname5 =newfname5;
                    lname5 = newlname5;
                }

            }
            disp_exam_info();
        }
    }

    void classtofile()
{
    ofstream datafile;
    datafile.open("P_data.txt",ios::app);
    datafile.write((char*)this,sizeof(*this));
    datafile.close();
}

    void showfiledata()
    {
    // cout<<"All Data Entered: ";
    ifstream datafile;
    datafile.open("P_data.txt");
    datafile.read((char*)this,sizeof(*this));
    while(!datafile.eof())
    {
        disp_personal_info();
        disp_exam_info();
    }
    datafile.close();
    }
};

int main()
{
    int a;
    string b;
    cout<<"ENTER THE NUMBER OF STUDENTS IN THE CLASS\n";
    cin>>a;
    final arr[a];
    for(int i = 0; i < a; i++)
    {
        final arr[i];
    }

    for(int i = 0; i < a; i++)
    {
        arr[i].enterdata();
        arr[i].get_exam_info();
        arr[i].classtofile();
        // arr[i].showfiledata();
    }
    int j;
    string s1;
    for(int i = 0; i <= 200; i++)
    {
        cout<<"ENTER THE ROLL NUMBER OF THE STUDENT IN THE CLASS WHOSE DATA YOU WOULD LIKE TO SEE\nPRESS ANY ALPHABET TO EXIT\n";
        cin>>j;

        if(j > a)
        {
            cout<<"INVALID INPUT\nTOTAL NUMBER OF STUDENTS = "<<a<<endl;
            cout<<"ENTER A NUMBER BETWEEN 1 AND "<<a<<endl;

            continue;
        }

        cout<<"WHAT INFORMATION WOULD YOU LIKE TO SEE\nPRESS PI FOR PERSONAL INFORMATION\nPRESS EI FOR EXAM INFORMATION\n";
        cin>>b;

        if(b == "PI")
        {
            arr[j-1].disp_personal_info();
        }

        else if(b == "EI")
        {
            arr[j-1].disp_exam_info();
        }


        cout<<"SELECT ONE FROM THE FOLLOWING\nPRESS U FOR UPDATE SOMETHING\nPRESS E TO EXIT\nPRESS N TO SEE SOMEONE ELSE'S DATA\n";
        cin>>s1;

        if( s1 == "E")
        {
            break;
        }
        else if( s1 == "N")
        {
            continue;
        }

        if (s1 == "U")
        {
            arr[j-1].updatedata();
            continue;
        }
    }

    // cout<<"All Data Entered : ";
    // for(int i = 0; i<a; i++)
    // {
    //     arr[i].showfiledata();
    // }

}