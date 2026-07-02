#include<iostream>
using namespace std;
int factorial(int n){
	int fact=1;
	for(int i=1;i<=n;i++){
		fact*=i;
	}
	return fact;
}
int main(){
	int n;
	cout<<"enter the number : ";
	cin>>n;
	int result=factorial(n);
	cout<<"The factorial of "<<n<<" is "<<result;
	return 0;
}