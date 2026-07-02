
#include<iostream>
using namespace std;

int main(){
    int arr[10];
    int n;
    cout<<"Enter the no. of elements : ";
    cin>>n;
    cout<<"Enter the array elements : ";
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    cout<<endl;
    cout<<"Before sorting : "<<endl;
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //Bubble sort;
    for(int i=0;i<n-1;i++){
        for(int j =0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    cout<<"After sorting"<<endl;
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}