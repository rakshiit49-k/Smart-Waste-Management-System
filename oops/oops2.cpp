/*so in oops1.cpp file we have read about how we can make classes which can posses different attributes and then
we have also created objects by accessing the class and the function inside that class also...
but the problem we'r facing is that if we wants to create a bunch of objects (maybe 30 or 100)....then it would
be a difficult task for us to create that amount of objects again and again.....
so to solve this problem ...we can use a CONSTRUCTOR in this file.*/


#include<iostream>
 using namespace std;

class Employee{
public:
    string Name;
    string Company;
    int Age;
    Employee(string n,string c,int a){                  //CONSTRUCTOR
        Name=n;
        Company=c;
        Age=a;
    }
    void Introduce(){
        cout<<"Hello everyone, My name is "<<Name<<"."<<endl;
        cout<<"I am working for "<<Company<<"."<<endl;
        cout<<"I am "<<Age<<" years old."<<endl;
    }
};
int main(){
    Employee employee1("Rakshit","Google",18);                  //accessing the constructor
    employee1.Introduce();
    cout<<endl;
    Employee employee2("Karan","Amazon",30);
    employee2.Introduce();
    return 0;
}