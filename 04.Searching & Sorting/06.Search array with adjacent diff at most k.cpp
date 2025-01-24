//{ Driver Code Starts
// C++ program to search an element in an array
// where difference between all elements is 1
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// x is the element to be searched in arr[0..n-1]
// such that all elements differ by at-most k.

class Solution {
  public:
    int findStepKeyIndex(vector<int>& arr, int k, int x) {
        // code here
         int i = 0; 
    while (i < arr.size()) 
    { 
        // If x is found at index i 
        if (arr[i] == x) 
            return i; 
  
        // Jump the difference between current 
        // array element and x divided by k 
        // We use max here to make sure that i 
        // moves at-least one step ahead. 
        i = i + max(1, abs(arr[i]-x)/k); 
    } 
    return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        int k, x;
        cin >> k >> x;
        Solution sol;
        int ans = sol.findStepKeyIndex(arr, k, x);
        cout << ans << endl;
        cout << '~' << endl;
    }
    return 0;
}

// } Driver Code Ends