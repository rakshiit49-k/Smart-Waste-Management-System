#include<iostream>
using namespace std;

int bintodec(int n){
	int rem,ans=0,pow=1;
	while(n>0){
		rem=n%10;
		ans+=rem*pow;
		n=n/10;
		pow*=2;
	}
	return ans;
}
int main(){
	int n;
	cout<<"enter the number : ";
	cin>>n;
	cout<<bintodec(n);
	return 0;
}