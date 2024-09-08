// Problem Link: https://www.geeksforgeeks.org/problems/all-unique-permutations-of-an-array/0

class Solution {
  public:
    int next_permutation(vector<int> &arr, int n) {
        int i = n-2;
        while(i >= 0 && arr[i]>=arr[i+1]) {
            i--;
        }
        
        if(i < 0) return 0;      // when the given permutation is already the largest possible permutation

        int j = n-1;
        while(j > i && arr[j]<=arr[i]) {
            j--;
        }
        
        swap(arr[i], arr[j]);
        reverse(arr.begin()+i+1, arr.end());
        
        return 1;
    }
    
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        vector<vector<int>> ans;
        set<vector<int>> s;
        
        sort(arr.begin(), arr.end());
        s.insert(arr);
        
        while(next_permutation(arr, n)) {
            s.insert(arr);
        }
        
        for(auto i: s) {
            ans.push_back(i);
        }
        return ans;
    }

};