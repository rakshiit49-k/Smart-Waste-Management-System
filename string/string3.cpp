//Reverse a string in such a manner that the words inside the string get reversed not the characters inside the words.

#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

int main(){
    string s;
    cout<<"enter the string : "<<endl;
    getline(cin,s);

    stringstream ss(s);
    vector<string> words;
    string word;

    while(ss>>word){
        words.push_back(word);
    }

    for(int i=words.size()-1;i>=0;i--){
        cout<<words[i];
        if(i!=0){
            cout<<" ";
        }
    }
    return 0;
}