class Solution {
public:
    void printAllDuplicateElement(string s) {
        unordered_map<char,int>count;
        for(int i=0;i<s.size();i++){
            if(count.find(s[i])!=count.end()) count[s[i]]++;
            else count[s[i]]=1;
        }
        for(auto it : count){
            if(it.second>1) cout<<it.first<<endl;
        }
        return;
    }
};
