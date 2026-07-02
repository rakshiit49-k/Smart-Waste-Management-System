#include<iostream>
using namespace std;
int sumOfDigits(int n){
	int sum=0,rem;
	while(n>0){
		rem=n%10;
		sum+=rem;
		n=n/10;
	}
	return sum;
}
int main(){
	int n;
	cout<<"enter the number : ";
	cin>>n;
	cout<<"The sum of digits are : "<<sumOfDigits(n);
	return 0;
}