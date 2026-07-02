
//--------------------------------------------ABSTRACTION------------------------------------------------------

/* Abstraction in Object-Oriented Programming (OOP) is a core principle that hides complex internal implementation
 details and exposes only the essential features of an object to the user. It focuses on what an object does
  rather than how it does it, simplifying system design and reducing complexit */

#include<iostream>
using namespace std;

class Shape {
public:
    virtual double area() = 0;  // pure virtual function → abstract class
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) { radius = r; }
    double area() override {
        return 3.14 * radius * radius;
    }
};

class Rectangle : public Shape {
    double length, width;
public:
    Rectangle(double l, double w) { length = l; width = w; }
    double area() override {
        return length * width;
    }
};

int main() {
    Shape* s1 = new Circle(5);
    Shape* s2 = new Rectangle(4, 6);
    cout << s1->area() << " , " << s2->area();
}