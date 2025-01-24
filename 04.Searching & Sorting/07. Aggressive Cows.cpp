bool isPossible(vector<int> &arr, int k, int mid) {
    int cowCount = 1; // Start with one cow placed
    int prevPos = 0;  // Place the first cow at the first stall

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] - arr[prevPos] >= mid) {
            cowCount++;   // Place another cow
            prevPos = i;  // Update the position of the last placed cow
        }

        if (cowCount == k) {
            return true;  // Successfully placed all cows
        }
    }
    return false;  // Not possible to place all cows with at least 'mid' distance
}

int aggressiveCows(vector<int> &stalls, int k) {
    // Sort the stalls to arrange them in increasing order
    sort(stalls.begin(), stalls.end());

    // Initialize binary search variables
    int n = stalls.size();
    int start = 1;  // Minimum possible distance
    int end = stalls[n - 1] - stalls[0];  // Maximum possible distance
    int ans = -1;

    // Binary search
    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (isPossible(stalls, k, mid)) {
            ans = mid;     // Update answer if possible
            start = mid + 1;  // Try for a larger minimum distance
        } else {
            end = mid - 1;  // Try for a smaller minimum distance
        }
    }

    return ans;  // Return the largest minimum distance
}
