class Solution {
public:
    // solving by using kadane alogorithm
    // Kadane's algorithm efficiently finds the maximum sum of a contiguous
    // subarray in a given array. It iterates through the array, maintaining two
    // values: `currSum` (the sum of the current subarray) and `maxSum` (the
    // maximum sum encountered so far). If `currSum` becomes negative, it resets
    // to zero, ensuring that only positive sums are considered. This approach
    // runs in O(n) time complexity.
    int maxSubArray(vector<int>& nums) {
        int currSum = 0;
        int maxSum = nums[0];
        for (int i = 0; i <= nums.size() - 1; i++) {
            currSum += nums[i];
            maxSum = max(currSum, maxSum);
            if (currSum < 0) {
                currSum = 0;
            }
        }
        return maxSum;
    }
};