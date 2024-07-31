/*
    Given an integer array nums, 
    return all the triplets 
    [nums[i], nums[j], nums[k]] 
    such that i != j, i != k, and j != k, 
    and nums[i] + nums[j] + nums[k] == 0.

    Notice that the solution set must not contain duplicate triplets.
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int start = 0;

        for(int start=0;start<nums.size()-2;start++){
            if(start!=0 && nums[start]==nums[start-1]){
                continue;
            }
            int mid = start+1;
            int end = nums.size()-1;
            while(mid<end){
                int val = nums[start]+nums[mid]+nums[end];
                if(val==0){
                    ans.push_back({nums[start],nums[mid],nums[end]});
                    mid++;
                    end--;
                    while(nums[mid]==nums[mid-1] && mid<end){
                        mid++;
                    }
                    while(nums[end]==nums[end+1] && mid<end){
                        end--;
                    }
                }else if(val>0){
                    end--;
                }else{
                    mid++;
                }
            }
        }
        return ans;
    }
};