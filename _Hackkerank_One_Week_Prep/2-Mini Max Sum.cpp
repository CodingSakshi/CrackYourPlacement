// Problem Link: https://www.hackerrank.com/challenges/one-week-preparation-kit-mini-max-sum

void miniMaxSum(vector<int> arr) {
    int maxi = INT_MIN;
    int mini = INT_MAX;
    long sum = 0;
    
    for(auto i : arr) {
        sum += i;
        mini = min(mini, i);
        maxi = max(maxi, i);
    }
    
    cout << sum-maxi << ' ' << sum-mini;
}