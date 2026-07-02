
#include<iostream>
using namespace std;

int dectobin(int n){
	int rem,ans=0,pow=1;
	while(n>0){
		rem=n%2;
		n=n/2;
		ans+=rem*pow;
		pow*=10;
	}
	return ans;
}
int main(){
	int n;
	cout<<"Enter the number : ";
	cin>>n;
	cout<<dectobin(n);
	return 0;
}