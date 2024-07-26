/*
    Given an array of integers nums containing n + 1 integers 
    where each integer is in the range [1, n] inclusive.

    There is only one repeated number in nums, return this repeated number.
    You must solve the problem without modifying the array nums and uses only constant extra space.

                    ***Using Hare and Tortoise Algo***
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size()==2) return nums[0];
        int slow = nums[0];
        int fast = nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
        fast=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};