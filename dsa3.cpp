#include <iostream> 
using namespace std; 
 
struct node 
{ 
    string name; 
    node *B[5]; 
}; 
 
class book 
{ 
    int c, s, sub; 
 
public: 
    node *temp = new node; 
 
    void Getnewnode() 
    { 
        for (int i = 0; i < 5; i++) 
        { 
            temp->B[i] = new node; 
            temp->B[i]->name = "empty"; 
            for (int j = 0; j < 5; j++) 
            { 
                temp->B[i]->B[j] = new node; 
                temp->B[i]->B[j]->name = "empty"; 
                for (int k = 0; k < 5; k++) 
                { 
                    temp->B[i]->B[j]->B[k] = new node; 
                    temp->B[i]->B[j]->B[k]->name = "empty"; 
                } 
            } 
        } 
    } 
    void add_title() 
    { 
        cout << "ENTER THE TITLE OF THE BOOK:"; 
        cin >> temp->name; 
        Getnewnode(); 
    } 
 
    void add_chapter() 
    { 
        string cname; 
        int cnum; 
        cout << "ENTER NUMBER OF CHAPTERS IN THE BOOK:"; 
        cin >> cnum; 
        c = cnum; 
        for (int i = 0; i < cnum; i++) 
        { 
            cout<< "Chapter " << i + 1 << ":"; 
            cin >> cname; 
            temp->B[i]->name = cname; 
        } 
    } 
 
    void add_section() 
    { 
        string sname; 
        int snum; 
        int chnum; 
        cout << "CHAPTER NUMBER WHERE YOU NEED TO ADD SECTIONS:"; 
        cin >> chnum; 
        cout << "ENTER NUMBER OF SECTIONS:"; 
        cin >> snum; 
        s = snum; 
        for (int i = 0; i < snum; i++) 
        { 
            cout << "Section " << chnum << "." << i + 1 << ":"; 
            cin >> sname; 
            temp->B[chnum - 1]->B[i]->name = sname; 
        } 
    } 
 
    void add_sub_section() 
    { 
        string subname; 
        int subnum; 
        int snum; 
        int chnum; 
        cout << "CHAPTER NUMBER WHERE YOU NEED TO ADD SECTIONS:"; 
        cin >> chnum; 
        cout << "SECTION NUMBER WHERE YOU NEED TO ADD SUB-SECTIONS:"; 
        cin >> snum; 
        cout << "ENTER NUMBER OF SUB-SECTIONS:"; 
        cin >> subnum; 
        sub = subnum; 
        for (int i = 0; i < subnum; i++) 
        { 
            cout << endl 
                 << "Sub-Section " << chnum << "." << snum << "." << i + 1 << " = "; 
            cin >> subname; 
            temp->B[chnum - 1]->B[snum - 1]->B[i]->name = subname; 
        } 
    } 
 
    void display() 
    { 
        cout << endl 
             << "======= INDEX =======" << endl; 
        cout << endl 
             << ":  TITLE   : " << temp->name; 
        cout << endl 
             << ": CHAPTERS : " << endl; 
        for (int i = 0; i < c; i++) 
        { 
            if (temp->B[i]->name != "empty") 
                cout << endl 
                     << ": " << i + 1 << ". " << temp->B[i]->name; 
            for (int j = i; j < s; j++) 
            { 
                if (temp->B[i]->B[j]->name != "empty") 
                    cout << endl 
                         << " : " << i + 1 << "." << j + 1 << " " << temp->B[i]->B[j]->name; 
                for (int k = 0; k < sub; k++) 
                { 
                    if (temp->B[i]->B[j]->B[k]->name != "empty") 
                        cout << endl 
                             << "  : " << i + 1 << "." << j + 1 << " " << temp->B[i]->B[j]->B[k]->name; 
                } 
            } 
        } 
        cout << endl; 
    } 
}; 
 
int main() 
{ 
    book b1; 
    b1.add_title(); 
    int c; 
    while (1) 
    { 
        
cout<<"**************************************************************************"<<endl; 
        cout << "1-Add chapter.\n2-Add scetion.\n3-Add subsection.\n4-Display book.\n5-Exit." << endl; 
        cout << "Enter your choice:"; 
        cin >> c; 
        if (c == 1) 
        { 
            b1.add_chapter(); 
        } 
        else if (c == 2) 
            b1.add_section(); 
        else if (c == 3) 
            b1.add_sub_section(); 
        else if (c == 4) 
            b1.display(); 
        else if (c == 5) 
        { 
            cout << "End of the program." << endl; 
            break; 
        } 
        else 
            cout << "Wrong Choice!!!" << endl; 
} 
}