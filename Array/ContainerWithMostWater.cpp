/*
    You are given an integer array height of length n. 
    There are n vertical lines drawn such that 
    the two endpoints of the ith line are (i, 0) and (i, height[i]).

    Find two lines that together with the x-axis form a container, 
    such that the container contains the most water.

    Return the maximum amount of water a container can store.
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxLeft = 0;
        int maxRight = height.size()-1;
        int maxWater = 0;
        while(maxLeft<maxRight){
            int water_amnt = min(height[maxLeft],height[maxRight]) * (maxRight-maxLeft);
            if(water_amnt>maxWater){
                maxWater = water_amnt;
            }
            if(height[maxLeft]<=height[maxRight]){
                maxLeft++;
            }else{
                maxRight--;
            }
        }
        return maxWater;
    }
};