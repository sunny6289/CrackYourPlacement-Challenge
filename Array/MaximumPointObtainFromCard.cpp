/*
    There are several cards arranged in a row, 
    and each card has an associated number of points. 
    The points are given in the integer array cardPoints.

    In one step, you can take one card from the beginning or from the end of the row. 
    You have to take exactly k cards.

    Your score is the sum of the points of the cards you have taken.

    Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

    Input: cardPoints = [1,2,3,4,5,6,1], k = 3
    Output: 12
*/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        if(n<k) return 0;
        int leftSum=0, rightSum=0, maxSum=0;
        for(int i=0;i<k;i++){
            leftSum+=cardPoints[i];
        }
        maxSum=leftSum;
        int left = k-1;
        int right = n;
        while(k){
            leftSum-=cardPoints[left--];
            rightSum+=cardPoints[--right];
            maxSum=max({maxSum,leftSum+rightSum});
            k--;
        }
        return maxSum;
    }
};