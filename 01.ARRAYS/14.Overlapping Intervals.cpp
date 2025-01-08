//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        
        //sort
        sort(arr.begin() , arr.end());
        
        //initialization
        vector<vector<int>> merged;
        
        //solve
        for(vector<int> curr : arr){
            //if the merged is empty or no overlap then add 
            //the curr in the merged arr
            if(merged.empty() || curr[0] > merged.back()[1] ){
                merged.pus h_back(curr);
            }else{
                //overlap exists!
                merged.back()[1] = max(merged.back()[1] ,curr[1]);
            }
        }
        
        return merged;
    }
} ;

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        Solution obj;
        vector<vector<int>> ans = obj.mergeOverlap(arr);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends