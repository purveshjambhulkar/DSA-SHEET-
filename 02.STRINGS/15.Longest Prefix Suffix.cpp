//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int longestPrefixSuffix(string &s) {
        // Your code goes here
        int count = 0;
        int pre = 0;
        int suff = 1;
        int pos =1;
        int n = s.length();
        while(pre < n && suff < n){
            if(s[pre] == s[suff]){
                suff++;
                count++;
                pre++;
            }else{
                count = 0; 
                pos++;
                pre = 0;
                suff = pos;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.longestPrefixSuffix(str) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends

