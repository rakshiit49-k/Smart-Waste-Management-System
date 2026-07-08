//week 3

#include<iostream>
using namespace std;

/*int gcd(int n1,int n2){
    int rem;
    while(n2!=0){
        rem=n1%n2;
        n1=n2;
        n2=rem;
    }
    return n1;
}

int main(){
    int n1,n2;
    cout<<"enter the first and second number : ";
    cin>>n1>>n2;
    cout<<"The gcd of two numbers is : "<<gcd(n1,n2);
    return 0;
}*/

/*int sumDigits(int num){
    int sum=0;
    while(num>0){
        sum+=num%10;
        num/=10;
    }
    return sum;
}
int main(){
    int num;
    cout<<"enter the number : ";
    cin>>num;
    cout<<"the individual digit sum is : "<<sumDigits(num)<<endl;
    if(sumDigits(num)%2==0)
        cout<<"The sum is even";
    else
        cout<<"The sum is odd";
    return 0;
}*/

/*int primeSum(int n){
    int sum=0;
    int flag;
    for(int i=2;i<=n;i++){
        flag=1;
        for(int j=2;j<=i/2;j++){
            if(i%j==0)
                flag=0;
                break;
        }
        if(flag==1){
            sum=sum+i;
        }
    }
    return sum;
}
int main(){
    int num;
    cout<<"enter the number : ";
    cin>>num;
    cout<<"The prime sum is  : "<<primeSum(num);
    return 0;
}*/