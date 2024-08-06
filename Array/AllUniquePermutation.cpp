/*
    Given a collection of numbers, 
    nums, that might contain duplicates, 
    return all possible unique permutations in any order.

    Input: nums = [1,1,2]
    Output: [[1,1,2], [1,2,1], [2,1,1]]
*/

class Solution {
public:
    vector<vector<int>>ans;
    int n;
    void solve(vector<int>& temp, unordered_map<int, int>& mp){
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }
        for(auto& [num, count] : mp){
            if(count==0){
                continue;
            }
            temp.push_back(num);
            count--;
            solve(temp, mp);
            temp.pop_back();
            count++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        if(n==1){
            ans.push_back(nums);
            return ans;
        }
        unordered_map<int, int>mp;
        for(int& num: nums){
            mp[num]++;
        }
        vector<int>temp;
        solve(temp, mp);
        return ans;
    }
};