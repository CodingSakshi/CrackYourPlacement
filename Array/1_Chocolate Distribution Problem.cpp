// Problem Link: https://www.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(), a.end());
        
        long long mini = LLONG_MAX;

        for(int i = 0; i+m-1 < n && i < n; i++) {
            mini = min(mini, a[i+m-1] - a[i]);
        }
        return mini;
    }   
};