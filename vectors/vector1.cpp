//MAXIMUM SUBARRAY SUM
//TIME COMPLEXITY=O(N2)

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int arr[10]={1,2,3,4,5,6};
    int n=6;
    for(int st=0;st<=n;st++){
        for(int end=st;end<=n;end++){
            for(int i=st;i<end;i++){
                cout<< arr[i];
            }
            cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}