//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to delete middle element of a stack.
    
    void deleteMidUtil(stack<int>& s , int N){
        int popped_ele = N - s.size();
        if(popped_ele == (N/2)){
            s.pop();
            return;
        }
        
        int x = s.top();
        s.pop();
        deleteMidUtil(s , N);
        s.push(x);
    }
    
    void deleteMid(stack<int>& s) {
        // code here..
        int N = s.size();
        deleteMidUtil(s , N);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        stack<int> s;
        int num;
        while (ss >> num) {
            s.push(num);
        }

        Solution ob;
        ob.deleteMid(s);
        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends