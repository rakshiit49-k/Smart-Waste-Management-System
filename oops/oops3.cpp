
//--------------------------------------------ENCAPSULATION------------------------------------------------------
/*Encapsulation is the bundling of data (variables) and the methods (functions) that manipulate that data into a 
single unit (like a class). It restricts direct access to internal components and protects the data from 
unauthorized modification.*/
/*Setter :- by using setter function we can set the value by our choice,
Getter :- by using getter function we can access the private members of the class*/


#include<iostream>
 using namespace std;

class Employee{
private:                                                //encapsulate
    string Name;
    string Company;
    int Age;
public:
    void setName(string  name){                         //Setter
        Name=name;
    }
    string getName(){                                   //Getter
        return Name;
    }
    void SetCompany(string company){                    //Setter
        Company=company;
    }
    string getCompany(){                                //Getter
        return Company;
    }
    void setAge(int age){  
        if(age>22){                             //Setter(by using some condition for user input)
        Age=age;
        }
    }
    int getAge(){                                       //Getter
        return Age;
    }
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
    employee1.setAge(35);                                       //accessing setter
    employee1.SetCompany("Netflix");                            //accessing setter
    cout<<"Hello guys i am "<<employee1.getName()<<endl<<"i am "<<employee1.getAge()<<endl<<"I am currenlty working at "<<employee1.getCompany()<<endl;
    cout<<endl;
    Employee employee2("Karan","Amazon",30);                    //accessing the constructor
    employee2.setAge(19);                                       //accessing setter
    employee2.setName("Aman");                                 //accessing setter
    cout<<"Hello guys i am "<<employee2.getName()<<endl<<"i am "<<employee2.getAge()<<endl<<"I am currenlty working at "<<employee2.getCompany()<<endl;
    cout<<endl;
    return 0;
}