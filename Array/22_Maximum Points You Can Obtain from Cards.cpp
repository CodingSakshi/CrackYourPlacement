// Problem Link: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

// Solution1: 
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int currSum = 0;
        for(int i = 0; i < k; i++) {
            currSum += cardPoints[i];
        }

        int maxSum = currSum;
        for(int i = k-1; i >= 0; i--) {
            currSum -= cardPoints[i];
            currSum += cardPoints[cardPoints.size()-k+i];
            maxSum = max(currSum, maxSum);
        }

        return maxSum;
    }
};

// Solution2
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(); 
        // Defining the range to slide over, including cyclic elements
        int begin = n - k, end = begin + (2 * k); 
        int sum = 0, maxSum = 0; 

        // Slide a window over the array with a range of 2*k elements
        for (int i = begin, j = begin; j < end; j++) {
            sum += cardPoints[j % n]; 
            if (j - i + 1 == k) { 
                maxSum = max(maxSum, sum); 
                sum -= cardPoints[i % n]; 
                i++; 
            }
        }
        return maxSum; 
    }
};


