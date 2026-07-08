//kadanne's algo
#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};
    int currSum=0;
    int maxSum=INT_MIN;
    for(int i:nums){
        currSum+=i;
        maxSum=max(currSum,maxSum);
        if(currSum<0){
            currSum=0;
        }
    }
    cout<<"the maximum subarray sum is : "<<maxSum<<endl;
    return 0;
}