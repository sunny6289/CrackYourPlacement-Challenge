class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result ;
        while(columnNumber>0){
            columnNumber--;
            int remainder = columnNumber%26;
            char ch = 'A'+ remainder;
            result.push_back(ch);
            columnNumber/=26;
        }
        reverse(begin(result),end(result));
        return result;
    }
};