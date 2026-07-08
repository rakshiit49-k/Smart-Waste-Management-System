//PALINDROME CHECK

#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(string s){
    int st=0,end=s.size()-1;
    while(st<end){
        if(s[st]!=s[end]){
            return false;
        }
        st++;
        end--;
    }
    return true;
}

int main(){
    string s;
    cout<<"enter the string : "<<endl;
    cin>>s;
    if(isPalindrome(s)){
        cout<<"The string is palindrome";
    }
    else{
        cout<<"the string is not palindrome";
    }
    return 0;
}