//return two elements whose sum is equal to the given target but of time complexity o(n)

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int arr[]={1,2,11,15};
    int n=sizeof(arr)/sizeof(arr[0]);
    int st=0;
    int end=n-1;
    int target;

    cout<<"Enter the target";
    cin>>target;

    while(st<end){
        int pairSum=arr[st]+arr[end];
        if(pairSum==target){
            cout<<"Pair found "<<arr[st]<<" , "<<arr[end]<<endl;
            return 0;
        }
        else if(pairSum>target){
            end--;
        }
        else{
            st++;
        }
    }
    cout<<"No pair found";
    return 0;
}
