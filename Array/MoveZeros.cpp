class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size()==0 || nums.size()==1){
            return;
        }
        int s = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                s=i;
                break;
            }
        }
        if(s==-1){
            return ;
        }
        for(int i=s+1;i<nums.size();i++){
            if(nums[i]!=0){
                swap(nums[i],nums[s]);
                s++;
            }
        }
        return;
        
    }
};