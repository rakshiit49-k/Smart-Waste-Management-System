/*Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 1:
Input: nums = [3,2,3]
Output: 3*/


//METHOD 1(time complexity of o(n2))
/*
#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int n=nums.size();
    for(int i:nums){
        int freq=0;
        for(int j:nums){
            if(i==j){
                freq++;
            }
        }
        if(freq>=n/2){
            return i;
        }
    }
    return -1;
}

int main(){
    vector<int> nums={3,2,3,4,4,4,5,5,5,5,5,};
    cout<<"the majority element in a array is : "<<majorityElement(nums);
    return 0;
}
*/

//METHOD 2(time complexity of O(nlogn))
/*
#include<iostream>
#include<vector>
#include<algorithm>   //for sort function

using namespace std;

int majorityElement(vector<int>& nums) {
    int n=nums.size();

    //sort
    sort(nums.begin(),nums.end());

    int freq=1,ans=nums[0];
    for(int i=1;i<n;i++){
        if(nums[i]==nums[i-1]){
            freq++;
        }
        else{
            freq=1;
            ans=nums[i];
        }
        if(freq>=n/2){
            return ans;
        }
    }
    return -1;
}

int main(){
    vector<int> nums={3,2,3};
    cout<<"the majority element is : "<<majorityElement(nums)<<endl;
    return 0;
}
*/

//METHOD 3(MOORE'S VOTING ALGORITHM(most efficient))

#include<iostream>
#include<vector>

using namespace std;

int majorityElement(vector<int>& nums) {
    int freq=0,ans=0;
    for(int i=0;i<nums.size();i++){
        if(freq==0){
            ans=nums[i];
        }
        if(ans==nums[i]){
            freq++;
        }
        else{
            freq--;
        }
    }
    return ans;
}

int main(){
    vector<int> nums={3,2,3};
    cout<<"the majority element is : "<<majorityElement(nums)<<endl;
    return 0;
}