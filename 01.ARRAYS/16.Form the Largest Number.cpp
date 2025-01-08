//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
 public:
    // Custom comparator for largest number
    static bool customComparator(int a, int b) {
        string strA = to_string(a);
        string strB = to_string(b);

        // Compare concatenated strings
        return strA + strB > strB + strA;
    }

    string findLargest(vector<int> &arr) {
        // Sort the array using the custom comparator
        sort(arr.begin(), arr.end(), customComparator);

        // Edge case: If the largest number is 0, return "0"
        if (arr[0] == 0) return "0";

        // Build the result string
        string ans = "";
        for (int num : arr) {
            ans += to_string(num);
        }
        return ans;
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
        string ans = ob.findLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends