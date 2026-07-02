//Linear Search

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
    cout<<"The array elements are : "<<endl;
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int target;
    cout<<"enter the target : ";
    cin>>target;
    for(int i=0;i<n;i++){
        if(arr[i]==target){
            cout<<"the element is at position "<<i;
            break;
        }
    }
    return 0;
}

