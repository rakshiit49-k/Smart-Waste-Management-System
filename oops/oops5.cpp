
//--------------------------------------------INHERITENCE--------------------------------------------------------
/*One class (child) acquires properties and behavior of another class (parent).*/

#include<iostream>
using namespace std;


class Animal {
public:
    string name;
    void eat() {
        cout << name << " is eating." << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << name << " is barking." << endl;
    }
};

int main() {
    Dog d;
    d.name = "Tommy";
    d.eat();   // inherited from Animal
    d.bark();  // Dog's own function
}



/* 
 Types of inheritance:

Type                                      Meaning

Single                              One base, one derived
Multiple                           One derived class, multiple base classes
Multilevel                             A → B → C chain
Hierarchical                        One base, multiple derived
Hybrid                                 Combination of above
*/

// Multilevel example
class Animal { public: void eat() { cout << "eating\n"; } };
class Mammal : public Animal { public: void walk() { cout << "walking\n"; } };
class Dog : public Mammal { public: void bark() { cout << "barking\n"; } };