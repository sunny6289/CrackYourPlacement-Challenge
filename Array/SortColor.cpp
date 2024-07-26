/*
    Given an array nums with n objects colored red, 
    white, or blue, sort them in-place so that objects of the same color are adjacent, 
    with the colors in the order red, white, and blue.

    We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
    You must solve this problem without using the library's sort function.

                            ***Dutch National Flag Algo***
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start = 0;
        int mid = 0;
        int end = nums.size()-1;

        while(mid<=end){
            switch(nums[mid]){
                case 0:
                    swap(nums[start],nums[mid]);
                    start++;
                    mid++;
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(nums[mid],nums[end]);
                    end--;
                    break;
            }
        }
        return;
    }
};