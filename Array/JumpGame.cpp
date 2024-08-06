/*
    You are given an integer array nums. 
    You are initially positioned at the array's first index, 
    and each element in the array represents your maximum jump length at that position.

    Return true if you can reach the last index, or false otherwise.

    Input: nums = [3,2,1,0,4]
    Output: false
    Explanation: 
    You will always arrive at index 3 no matter what. 
    Its maximum jump length is 0, which makes it impossible to reach the last index.
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        if(nums[0]==0) return false;
        
        int maxIdx = 0;
        for(int i=0;i<nums.size();i++){
            if(i>maxIdx)return false;
            maxIdx = max({maxIdx, nums[i]+i});
            if(maxIdx>=nums.size()-1) return true;
        }

        return true;
    }
};