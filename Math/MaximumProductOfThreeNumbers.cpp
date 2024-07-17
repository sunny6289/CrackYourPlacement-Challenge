class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if(nums.size()==3) return nums[0]*nums[1]*nums[2];
        int n = nums.size();
        sort(nums.begin(),nums.end());
        return max(nums[0]*nums[1]*nums[n-1],nums[n-1]*nums[n-2]*nums[n-3]);
    }
};
/*
    case 1: nums=[-2,-3,4]
    case 2: nums=[1,2,3,4,5];
    case 3: nums=[-1,-2,3,4,5];
    case 4: nums=[1,-2,-3,4,5];
    
    Dry run on all these cases you will understand
*/