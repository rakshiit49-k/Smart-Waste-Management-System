//ANAGRAM TEST

#include<iostream>
using namespace std;

bool isAnagram(string s1, string s2){
    int count[26]={0};
    if(s1.size()!=s2.size()){
        return false;
    }

    for(char i:s1) count[i-'a']++;
    for(char j:s2) count[j-'a']--;

    for(int k:count){
        if(k!=0){
            return false;
        }
    }
    return true;
}

int main(){
    string s1,s2;
    cout<<"enter the two words : "<<endl;
    cin>>s1>>s2;
    
    if(isAnagram(s1,s2)){
        cout<<"the anagram test is passed";
    }
    else{
        cout<<"the anagram test is not passed";
    }
    return 0;
}