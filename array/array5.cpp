//swap minimum and maximum element
#include<iostream>
using namespace std;
int temp;
int main(){
	int arr[10],n;
	cout<<"enter the no. of elements : ";
	cin>>n;
	cout<<"enter "<<n<<" elements : ";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
    cout<<"The original array is : "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
	int max=arr[0];
	int min=arr[0];
    int maxindex=0;
    int minindex=0;
	for(int i=0;i<n;i++){
		if(arr[i]>max){
			max=arr[i];
            maxindex=i;
		}
		if(arr[i]<min){
			min=arr[i];
            minindex=i;
		}
	}
    temp=arr[minindex];
    arr[minindex]=arr[maxindex];
    arr[maxindex]=temp;
    cout<<"The updated array is "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}