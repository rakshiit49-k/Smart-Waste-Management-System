#include<iostream>
using namespace std;
int factorial(int n){
	int fact=1;
	for(int i=1;i<=n;i++){
		fact*=i;
	}
	return fact;
}
int ncr(int n, int r){
	int result;
	result=factorial(n)/((factorial(r))*factorial(n-r));
	return result;
}
int main(){
	int n,r;
	cout<<"enter n : ";
	cin>>n;
	cout<<"enter r : ";
	cin>>r;
	int result=ncr(n,r);
	cout<<"The ncr is "<<result;
	return 0;
}
