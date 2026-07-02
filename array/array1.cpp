#include<iostream>
using namespace std;
int main(){
	int arr[10],n;
	cout<<"enter the no. of elements : ";
	cin>>n;
	cout<<"enter "<<n<<" elements : ";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int max=arr[0];
	int min=arr[0];
	for(int i=0;i<n;i++){
		if(arr[i]>max){
			max=arr[i];
		}
		if(arr[i]<min){
			min=arr[i];
		}
	}
	cout<<"the largest number is : "<<max<<endl;
	cout<<"the smallest number is : "<<min;
	return 0;
}