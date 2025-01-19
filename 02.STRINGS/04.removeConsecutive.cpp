//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removeConsecutiveCharacter(string& s) {
        // code here.
        //APPROACH 2 - W/O USING ADDITIONAL SPACE
        
        for(int i = 1 ; i<= s.length();i++){
            if(s[i] == s[i-1]){
                s.erase(i-1 , 1);
                i--;
            }
        }
        return s;
        
        
        
        //APPRAOCH 1 - USING ADDITIONAL SPACE - STRING
        // string ans = "";
        // for(int i = 0 ; i < s.length() ;i++){
        //     char c = s[i];
        //     ans.push_back(c);
        //     while(s[i] == s[i+1]){
        //         i++;
        //     }
        // }
        // return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.removeConsecutiveCharacter(s) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends