//REVERSE THE STRING

#include<iostream>
using namespace std;

string Reverse(string& s){
    int st=0,end=s.size()-1;
    while(st<end){
       /* char temp=s[st];
        s[st]=s[end];
        s[end]=temp;*/
        swap(s[st],s[end]);
        st++;
        end--;
    }
    return s;
}

int main(){
    string s;
    cout<<"enter the string : "<<endl;
    getline(cin,s);
    cout<<Reverse(s);
    return 0;
}