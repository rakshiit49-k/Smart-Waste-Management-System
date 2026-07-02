//week 4

#include<iostream>
using namespace std;

int fl(int num){
    int end=num%10;
    while(num>=10){
        num/=10;
    }
    int st=num;
    int prd=st*end;
    return prd;
}
int main(){
    int num;
    cout<<"enter the number : ";
    cin>>num;
    cout<<"The product of first and last digit is  : "<<fl(num);
    return 0;
}