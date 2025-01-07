class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Iterate through the array
        for (int i = 0; i < nums.size(); i++) {
            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1;               // Left pointer
            int k = nums.size() - 1;     // Right pointer

            // Step 3: Two-pointer approach
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    // Found a triplet
                    ans.push_back({nums[i], nums[j], nums[k]});

                    // Skip duplicates for `j` and `k`
                    while (j < k && nums[j] == nums[j + 1]) j++;
                    while (j < k && nums[k] == nums[k - 1]) k--;

                    j++;
                    k--;
                } else if (sum > 0) {
                    k--;  // Decrease the sum
                } else {
                    j++;  // Increase the sum
                }
            }
        }

        return ans;
    }
};
