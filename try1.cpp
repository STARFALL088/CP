#include <bits/stdc++.h>
#include <fstream>
using namespace std;
void signup()
{
    string name, pass;
    cin >> name >> pass;
    ofstream file;
    file.open("one.txt",::ios::out|::ios::app);
    
    // file << "name : " << name << "," << endl;
    // file << "pass : " << pass << endl;
    file<<name<<","<<pass<<endl;;
    
    file.close();
    cout << "Good job" << endl;
}
bool login()
{
    string name, pass;
    cin >> name >> pass;
    ifstream file("one.txt");
    string line;
    string a, b;

    while (getline(file, line))
    {
        stringstream ss(line);
        getline(ss, a, ',');
        getline(ss, b, ',');
        if (a == name && b == pass){
            file.close();
            return 1;}
    }
    file.close();
    return 0;
}
void print(){
    string line;
    ifstream file("entry.txt");
    while(getline(file,line)){
        cout<<line<<endl;
    }
    file.close();
}
void take(){
    string a,b;
    cin.ignore();
    cout<<"title";
    getline(cin,a);
    cout<<"go";
    getline(cin,b);
    ofstream file;
    file.open("entry.txt",::ios::out|::ios::app);
    file<<"-------------";
    file<<a<<endl;
    file<<b<<endl;
    file.close();
}

int main()
{
    while (1)
    {
        cout << "1.sign up  2.log in " << endl;
        int n;
        cin >> n;
        if (n == 1)
        {
            signup();
        }
        else if (n == 2)
        {
            if (login()){
                cout << "yes";
                cout<<"1.entry 2.print"<<endl;
                int _;
                cin>>_;

                if(_==1) take();
                else if(_==2)print();
            }
        }
    }
}