// Without Extra Space //

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(nums1.size()==0){
            for(int i=0;i<nums2.size();i++){
                nums1.push_back(nums2[i]);
            }
            return;
        }
        int temp1 = m-1; 
        int temp2 = 0;
        while(temp1>=0 && temp2<n){
            if(nums1[temp1]>nums2[temp2]){
                swap(nums1[temp1],nums2[temp2]);
                temp1--;
                temp2++;
            }else{
                break;
            }
        }
        temp2 = 0;
        for(int i=m;i<nums1.size();i++){
            nums1[i]=nums2[temp2++];
        }
        sort(nums1.begin(),nums1.end());
    }
};





// Using Extra Space //

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int temp1=0;
        int temp2=0;
        vector<int>ans;
        while(temp1<m && temp2<n){
            if(nums1[temp1]<=nums2[temp2]){
                ans.push_back(nums1[temp1]);
                temp1++;
            }else{
                ans.push_back(nums2[temp2]);
                temp2++;
            }
        }
        while(temp1<m){
            ans.push_back(nums1[temp1]);
            temp1++;
        }
        while(temp2<n){
            ans.push_back(nums2[temp2]);
            temp2++;
        }
        temp1=0;
        while(temp1<ans.size()){
            nums1[temp1]=ans[temp1];
            temp1++;
        }
    }
};
