#include<iostream>
 using namespace std;

class Employee{
public:                 //we can also make it PRIVATE and PROTECTED.
    string Name;
    string Company;
    int Age;
    void Introduce(){
        cout<<"Hello everyone, My name is "<<Name<<"."<<endl;
        cout<<"I am working for "<<Company<<"."<<endl;
        cout<<"I am "<<Age<<" years old."<<endl;
    }
};
int main(){
    Employee Employee1;
    Employee1.Name="Rakshit";
    Employee1.Company="Google";
    Employee1.Age=18;
    Employee1.Introduce();
    cout<<endl;
    Employee Employee2;
    Employee1.Name="Karan";
    Employee1.Company="Amazon";
    Employee1.Age=30;
    Employee1.Introduce();
}