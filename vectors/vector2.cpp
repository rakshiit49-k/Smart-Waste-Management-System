//KADANE'S ALGORITHM(time complexity=0(n))

#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};   //maximum sum is 6;
    int CurrSum=0;
    int MaxSum=INT_MIN;
    
    for(int i:nums){
        CurrSum+=i;
        MaxSum=max(CurrSum,MaxSum);
        if(CurrSum<0){
            CurrSum=0;
        }
    }
    cout<<"the maximum sum of subarray is : "<<MaxSum;
    return 0;
}