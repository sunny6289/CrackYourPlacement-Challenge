class Solution {
public:
    string addBinary(string a, string b) {
        int alen = a.size();
        int blen = b.size();
        string s;
        int carry = 0;
        if(alen>blen){
            b = s.append(alen-blen,'0')+b;
        }else{
            a = s.append(blen-alen,'0')+a;
        }
        s = "";
        for(int i=a.size()-1;i>=0;i--){
            int sum = carry+(a[i]-'0') + (b[i]-'0');
            s = to_string(sum%2) + s;
            carry = sum/2;
        }
        if(carry!=0) s = "1"+s;
        return s;
    }
};