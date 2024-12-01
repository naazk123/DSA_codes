#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void store(int roll, string name, string kbt, string dob, string add)
{
    ofstream f;
    f.open("dsal.txt", ios::app);
    f << roll << "|" << name << "|" << kbt << "|" << dob << "|" << add << endl;
    f.close();
}
int search(int roll)
{
    int line = 1, flag = 0;
    string data;
    ifstream infile;
    infile.open("dsal.txt");
    while (getline(infile, data))
    {
        string r = "";
        for (int i = 0; i < data.length(); i++)
        {
            if (data[i] != '|')
                r += data[i];
            else
                break;
        }
        if (r == to_string(roll))
        {
            cout << "The student record is PRESENT at line "<<line<<" : "<<endl; cout<< data<< endl;
            flag = 1;
            break;
        }
        line++;
    }
    if (flag == 0)
    {
        cout << "Record ABSENT from file." << endl;
        return 0;
    }
    else
        return 1;
    infile.close();
}
void deletion(int roll)
{
    int line = 1, flag = 0;
    string data, alldata = "";
    ifstream infile;
    infile.open("dsal.txt");
    while (getline(infile, data))
    {
        string r = "";
        for (int i = 0; i < data.length(); i++)
        {
            if (data[i] != '|')
                r += data[i];
            else
                break;
        }
        if (r == to_string(roll))
        {
            cout << "Record Deleted." << endl;
            flag = 1;
        }
        else
            alldata += data + "\n";
        if (flag == 0)
            line++;
    }
    infile.close();
    if (flag == 0)
        cout << "Record ABSENT from file." << endl;
    else
    {
        ofstream outfile;
        outfile.open("dsal.txt", ios::out);
        outfile << alldata;
    }
}
int main()
{
    while (1)
    {
        int ch;
        cout << "Enter 1-Insert in Sequential Access File | 2 -Search |3 - Delete | 0 - EXIT : "<<endl; 
                                    cin >>
                             ch;
        int roll;
        string kbt, name, dob, add;
        if (ch == 1 || ch == 2 || ch == 3)
        {
            string arr[] = {"Inserted", "Searched", "Deleted"};
            cout << "Enter Student Record Data to be "<<arr[ch-1]<<" : "<<endl; cout<< "Enter Roll No. " << endl;
            cin >> roll;
            if (ch == 1)
            {
                cout << "Enter Name : " << endl;
                cin >> name;
                cout << "Enter KBTUGID : " << endl;
                cin >> kbt;
                cout << "Enter DOB : " << endl;
                cin >> dob;
                cout << "Enter Address : " << endl;
                cin.get();
                getline(cin, add);
                store(roll, name, kbt, dob, add);
            }
            else if (ch == 2)
                int y = search(roll);
            else if (ch == 3)
            {
                int y = search(roll);
                if (y == 1)
                    deletion(roll);
            }
        }
        else if (ch == 0)
        {
            cout << "EXITING." << endl;
            break;
        }
    }
    return 0;
}