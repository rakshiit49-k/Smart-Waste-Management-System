//Binary Search

#include<iostream>
using namespace std;

int main(){
    int arr[]={1,3,4,5,6,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target;
    cout<<"Enter the target value : ";
    cin>>target;
    int st=0;
    int end=n-1;
    for(int i=0;i<n;i++){
        int mid=(st+end)/2;
        if(arr[mid]==target){
            cout<<"the targeted value is at "<<mid<<" index"<<endl;
            return 0;
        }
        else if(arr[mid]>target){
            end=mid-1;
        }
        else{
            st=mid+1;
        }
    }
    cout<<"not found";
    return 0;
}