class Solution {
public:
    bool checkPalindrome(string s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        if(s.size()<=2) return true;
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }else{
                if(checkPalindrome(s, i, j-1) || checkPalindrome(s, i+1, j)){
                   return true;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};