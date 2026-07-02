//reverse an array
#include <iostream>
using namespace std;    

void reverseArray(int arr[],int size){
    int start=0,end=size-1;
    while(start<end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}
int main(){
    int arr[10],size;
    cout<<"Enter the no of elements : ";
    cin>>size;
    cout<<"enter "<<size<<" elements : ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"The original array is "<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"the reverse array is : "<<endl;
    reverseArray(arr,size);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}