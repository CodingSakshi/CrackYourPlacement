// Problem Link: 

//  Using prefix sum concept and an unordered_map to store the frequency of remainders
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0]++;
        int prefixSum=0;
        int count=0;

        for(int i : nums) {
            prefixSum += i;
            int rem = prefixSum % k;

            // Adjusting the remainder to be positive if it is negative
            if(rem < 0) rem += k;

            // If the current remainder is found in the map, it means there exist previous subarrays
            // which when added to some elements give the same remainder. Hence these subarrays sums 
            // are divisible by k
            if(m.find(rem) != m.end()) {
                count += m[rem];
            }

            m[rem]++;
        }
        return count;
    }
};







