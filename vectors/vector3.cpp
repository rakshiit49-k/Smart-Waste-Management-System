//return the index of two elements whose sum is equal to the given target 

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cout<<"enter the no. of elements : ";
    cin>>n;
    vector<int> nums(n);
    cout<<"enter the elements : ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int target;
    vector<int> ans;
    cout<<"Enter the target : ";
    cin>>target;
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(nums[i]+nums[j]==target){
                ans.push_back(i);
                ans.push_back(j);
            }
        }
    }
    cout<<"the index of two numbers is : "<<ans[0]<<" , "<<ans[1];
    return 0;
}