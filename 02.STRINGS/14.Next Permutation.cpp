//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        int br = -1;

        // Step 1: Find the breakpoint
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] < arr[i + 1]) {
                br = i;
                break;
            }
        }

        // Step 2: If no breakpoint, reverse the entire array
        if (br == -1) {
            reverse(arr.begin(), arr.end());
            return;
        }

        // Step 3: Find the smallest element larger than arr[br]
        for (int i = n - 1; i > br; i--) {
            if (arr[i] > arr[br]) {
                swap(arr[br], arr[i]);
                break;
            }
        }

        // Step 4: Reverse the elements after the breakpoint
        reverse(arr.begin() + br + 1, arr.end());
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int n = arr.size();
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends