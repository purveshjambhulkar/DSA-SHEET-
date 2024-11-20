//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
 
class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        // add code here.
        stack<int> St;
        
        //add the first k element in the stack
        for(int i = 0 ; i < k ; i++){
            int temp = q.front();
            q.pop();
            St.push(temp);
        }
        
        //remove the element from the stack and add in the queue
        for(int i = 0 ; i < k ; i++){
            int temp = St.top();
            St.pop();
            q.push(temp);
        }
        
        int m = q.size() - k;
        //remove the "size - k" elements and them at the back of the queue
        for(int i = 0 ; i < m ; i++){
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        
        return q;
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends