/*
    Given an array nums of n integers, 
    return an array of all the unique quadruplets 
    [nums[a], nums[b], nums[c], nums[d]] 
    such that: 0 <= a, b, c, d < n
    a, b, c, and d are distinct.
    nums[a] + nums[b] + nums[c] + nums[d] == target

    You may return the answer in any order.
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        if(nums.size()<=3) return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-3;i++){
            if(i!=0 && nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1;j<nums.size()-2;j++){
                if(j!=i+1 && nums[j]==nums[j-1]){
                    continue;
                }
                int k = j+1;
                int l = nums.size()-1;
                while(k<l){
                    long long sum = nums[i];
                    sum+=nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    if(sum==target){
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
                        while(nums[k]==nums[k-1] && k<l){
                            k++;
                        }
                        while(nums[l]==nums[l+1] && l>k){
                            l--;
                        }
                    }else if(sum>target){
                        l--;
                    }else{
                        k++;
                    }
                }
            }
        }
        return ans;
    }
};