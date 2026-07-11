#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums={1,2,3,4,5,6,7};
    int n=3;
    int st=0;
    int end =nums.size()-1;
    while(n<end){
        swap(nums[st],nums[n+1]);
        st++;
        n++;
    }
    for(int i:nums){
        cout<<i<<" ";
    }
    return 0;

}
