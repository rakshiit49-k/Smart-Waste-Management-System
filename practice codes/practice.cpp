#include<iostream>
using namespace std;

void  reverseArray(int arr[] , int n){
    int start=0;
    int end=n-1;
    while(start<end){
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}
int main(){
    int arr[10];
    int n;
    cout<<"Enter the no of elements : ";
    cin>>n;
    cout<<"Enter the array elements : "<<endl;
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"the original array is : "<<endl;
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    reverseArray(arr,n);
    cout<<"The reverse array is : "<<endl;
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}