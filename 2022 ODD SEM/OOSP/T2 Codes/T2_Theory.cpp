 #include<iostream>
 #include<string>
 #include<fstream>
 using namespace std;

 int main()
 {
    fstream fio;
    string line = "Always give your best!";
    
    fio.open("MyJournal.txt", ios::out);
    fio<<line<<endl;
    fio.close();
   
    fio.open("MyJournal.txt", ios::in);
    cout<<fio.tellp();
    fio.seekp(-5, ios::cur);
    cout<<fio.tellp();
    fio.seekg(10, ios::beg);
    cout<<fio.tellg();

    return 0;
 }