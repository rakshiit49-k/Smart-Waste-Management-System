#include<iostream>
using namespace std;

int main(){
    int arr[10],n;
    int prd=1,add=0;
    cout<<"enter the no of elements : ";
    cin>>n;
    cout<<"enter the elements : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"The original array is : "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        prd*=arr[i];
        add+=arr[i];
    }
    cout<<"the addition of elements is : "<<add<<endl;
    cout<<"the product of elements is : "<<prd;
    return 0;
}