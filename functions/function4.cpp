#include<iostream>
using namespace std;
int prime(int n){
	int i,flag=1;
	for(i=2;i<n;i++){
		if(n%i==0){
			flag=0;
			break;
		}
	}
	if(flag){
		return 1;
	}
}
int main(){
	int n;
	cout<<"enter the number : ";
	cin>>n;
	for(int i=2;i<n;i++){
		if(prime(i)){
			cout<<i<<"\n";
		}
	}
	return 0;
}