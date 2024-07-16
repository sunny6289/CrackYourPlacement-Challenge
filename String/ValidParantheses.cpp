class Solution {
public:
    bool isValid(string s) {
        if(s.size()==1 || s.size()%2!=0){
            return false;
        }
        unordered_map<char,char>paran;
        paran.insert({'(',')'});
        paran.insert({'{','}'});
        paran.insert({'[',']'});
        stack<char>open;
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                open.push(s[i]);
            }else{
                if(open.empty() || paran[open.top()]!=s[i]) return false;
                else open.pop();
            }
        }
        if(open.size()) return false;
        return true;
    }
};