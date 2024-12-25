vector<int> Solution::repeatedNumber(const vector<int> &A) {
    vector<int> B = A;
    sort(B.begin(), B.end()); // Sort the array
    vector<int> ans(2); // To store the repeated and missing numbers
    long long n = A.size();
    long long sum = n * (n + 1) / 2; // Sum of first n natural numbers
    long long sumB = 0; // To compute the sum of elements in B
    long long x = 0; // To store the repeated number

    for (int i = 0; i < B.size(); i++) {
        // Check for repeated element
        if (i > 0 && B[i] == B[i - 1]) {
            x = B[i]; // Repeated number found
        }
        sumB += B[i];
    }

    ans[0] = x;                      // Repeated number
    ans[1] = sum - (sumB - x);       // Missing number
    return ans;
}
