#include<iostream>
using namespace std;
int linearSearch(int arr[],int n,int target){
	for(int i=0;i<n;i++){
		if(arr[i]==target){
			return i;
		}
	}
	return -1;
}
int main(){
	int arr[10],n,target;
	cout<<"enter the no of elements: ";
	cin>>n;
	cout<<"Enter array elements: ";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"Enter the targeted value : ";
	cin>>target;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	cout<<"the index of targeted element is : "<<linearSearch(arr,n,target);
	return 0;
}