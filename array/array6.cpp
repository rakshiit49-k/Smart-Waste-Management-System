#include<iostream>
using namespace std;

int main(){
    int arr[10],n;
    int count;
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
    cout<<"The unique array is "<<endl;
    for(int i=0;i<n;i++){
        count=0;
        for(int j=0;j<n;j++){
            if(arr[i]==arr[j])
            count++;
        }
        if(count==1){
            cout<<arr[i]<<" ";
        }
    }
    return 0;
}