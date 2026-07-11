#include<iostream>
using namespace std;

int addBinary(string a, string b) {
    int A=a.size()-1;
    int B=b.size()-1;
    int sum=0;
    while(A>=0|| B>-0){
        sum+=a[A]+b[B];
        A--;
        B--;
    }
    return sum;
}

int main(){
    string a,b;
    cout<<"Enter two strings : "<<endl;
    cin>>a>>b;
    cout<<addBinary(a,b);
    return 0;
}