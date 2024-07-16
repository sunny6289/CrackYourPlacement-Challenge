class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        if(nums.size()==2){
            ans.push_back(0);
            ans.push_back(1);
            return ans;
        }
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(target-nums[i])!=mp.end()){
                ans.push_back(i);
                ans.push_back(mp[target-nums[i]]);
                break;
            }
            mp.insert({nums[i],i});
        }
        return ans;
    }
};