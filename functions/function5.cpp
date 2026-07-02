#include<iostream>
using namespace std;
void fibonacci(int n){
	int a=0,b=1,c,i;
	for(i=1;i<n;i++){
		cout<<a<<" ";
		c=a+b;
		a=b;
		b=c;
	}
}
int main(){
	int n;
	cout<<"enter the number : ";
	cin>>n;
	fibonacci(n);
	return 0;
}