class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
        if(a.size()<=1 || n<m){
            return -1;
        }
        sort(a.begin(), a.end()); 
        int start=0;
        long long minDiff = LLONG_MAX;
        for(int b=m-1;b<a.size();b++){
            long long curr_Diff = a[b]-a[start];
            minDiff = min(curr_Diff, minDiff);
            start++;
        }
        return minDiff;
    }   
};