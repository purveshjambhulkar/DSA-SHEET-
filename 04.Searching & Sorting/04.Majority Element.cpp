//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  int majorityElement(const vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, int> countMap;

    // Traverse the array and count occurrences using the hash map
    for (int num : arr) {
        countMap[num]++;
      
        // Check if current element count exceeds n / 2
        if (countMap[num] > n / 2) {
            return num;
        }
    }

    // If no majority element is found, return -1
    return -1;}

};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends