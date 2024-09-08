// Problem Link: https://leetcode.com/problems/reverse-pairs/


class Solution {
public:

    int merge(vector<int> & nums, int left, int mid, int right) {

        int i = left, j = mid;
        int cnt = 0;
        vector<int> temp(right-left+1);
        int k = 0;
        
        int y;
        for(int x = left; x < mid; x++) {
            for(y = mid; y <= right && nums[x] > 2*(long long)nums[y]; y++) { } // there is possibility that the product is greater than the range of int
            cnt += (y - mid);
        }

        while(i < mid && j <= right) {
            
            if(nums[i] <= nums[j]) {
                temp[k] = nums[i];
                i++;
                k++;
            }
            else {   
                temp[k] = nums[j];
                j++;
                k++;
            }
        }

        while(i < mid) {
            temp[k] = nums[i];
            i++;
            k++;
        }

        while(j <= right) {
            temp[k] = nums[j];
            j++;
            k++;
        }

        for(i = left, k = 0; i <= right; i++, k++) {
            nums[i] = temp[k];
        }

        return cnt;
    }

    int mergeSort(vector<int> & nums, int left, int right) {

        int cnt = 0;

        if(right > left) {
            int mid = (left + right) >> 1;
            cnt += mergeSort(nums, left, mid);
            cnt += mergeSort(nums, mid+1, right);
            cnt += merge(nums, left, mid+1, right);
        }

        return cnt;
    }


    int reversePairs(vector<int>& nums) {

        return mergeSort(nums, 0, nums.size()-1);
    }
};









