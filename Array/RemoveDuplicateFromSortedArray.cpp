class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int s = -1;
        int e = -101;

        for(int i=0;i<nums.size();i++){
            if(e!=nums[i]){
                e=nums[i];
                s++;
                nums[s]=e;
            }
        }
        return s+1;
    }
};

