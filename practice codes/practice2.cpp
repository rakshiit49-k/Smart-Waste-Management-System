//week 2


#include<iostream>
using namespace std;
/*int main(){
    int a=0,b=1,c,i=0;
    int n;
    cout<<"Enter the limit : ";
    cin>>n;
    cout<<"the fibnacci series is : "<<endl;
    while(i<n){
        cout<<a<<" ";
        c=a+b;
        a=b;
        b=c;
        i++;
    }
}*/

/*int main(){
    int rem,rev=0;
    int num;
    cout<<"enter the number : "<<endl;
    cin>>num;
    int temp=num;
    while(temp!=0){
        rem=temp%10;
        rev=(rev*10)+rem;
        temp=temp/10;
    }
    if(rev==num)
        cout<<"the number is palindrome"<<endl;
    else
        cout<<"the number is not palindrome"<<endl;
    return 0;
}*/

//PATTERNS

/*int main(){
    char ch='A';
    for(int i=0;i<4;i++){
        for(int j=0;j<i+1;j++){
            cout<<ch<<" ";
            ch=ch+2;
        }
        cout<<"\n";
    }
    return 0;
}*/

/*int main(){
    for(int i=0;i<5;i++){
        int num=1;
        for(int j=0;j<i+1;j++){
            cout<<num<<" ";
            num=num+1;
        }
        cout<<"\n";
    }
    return 0;
}*/

/*int main(){
    for(int i=0;i<5;i++){
        for(int j=0;j<i+1;j++){
            if((i+j)%2==0)
                cout<<1<<"  ";
            else
                cout<<0<<" ";
        }
        cout<<"\n";
    }
    return 0;
}*/

/*int main(){
    for(int i=0;i<5;i++){
        char ch='A';
        for(int j=0;j<i+1;j++){
            cout<<ch<<" ";
            ch+=2;
        }
        cout<<"\n";
    }
    return 0;
}*/
