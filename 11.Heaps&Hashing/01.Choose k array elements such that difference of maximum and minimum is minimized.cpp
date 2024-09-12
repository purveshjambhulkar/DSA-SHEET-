//{ Driver Code Starts
#include <bits/stdc++.h>
#include <math.h>
#include <stdio.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minDiff(vector<int>& arr, int k) {
        // write code here
        //sort the array in ascending order
        sort(arr.begin() , arr.end());
        int n = arr.size();
        int result = INT_MAX;
        . 
    for (int i=0; i<=n-k; i++) 
        result = min(result, arr[i+k-1] - arr[i]); 
        
        
        return result;
     
 
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        cout << obj.minDiff(arr, k) << endl;
    }
    return 0;
}
// } Driver Code Ends