// Optimized solution //
class Solution{
    public:
    string longestCommonPrefix(vector<string>& strs){
        if(strs.size()==1) return strs[0];
        string ans = "";
        sort(strs.begin(),strs.end());
        string first = strs[0], last = strs[strs.size()-1];
        for(int i=0;i<min(first.size(),last.size());i++){
            if(first[i]!=last[i]) return ans;
            ans+=first[i];
        }
        return ans;
    }
};

// Better solution //
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1) return strs[0];
        string small = strs[0];
        for(int i=0;i<strs.size();i++){
            if(strs[i].size()<small.size()){
                small = strs[i];
            }
        }
        int k = 0;
        while(k<small.size()){
            for(int i=0;i<strs.size();i++){
                if(strs[i][k]!=small[k]){
                    if(k==0) return "";
                    return small.substr(0,k);
                }
            }
            k++;
        }
        return small;
    }
};

/*
    // Brute Force //
    
    Check each character with each string
    if longest common prefix is of 'm' size
    and strs contains 'n' strings. 
    Then Time Complexity will be O(M*N)
*/