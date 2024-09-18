//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
     int solve(char opt, int num2, int num1) {
        switch(opt) {
            case '*': return num1 * num2;
            case '+': return num1 + num2;
            case '-': return num1 - num2;
            case '/': return num1 / num2;
            default: return 0; // Return 0 for unknown operators
        }
    }
    
    int evaluatePostfix(string S) {
        stack<int> s;
        
        for(char c : S) {
            if(isdigit(c)) {
                s.push(c - '0');
            } else if(c == '+' || c == '-' || c == '*' || c == '/') {
                int num2 = s.top(); s.pop();
                int num1 = s.top(); s.pop();
                s.push(solve(c, num2, num1));
            }
        }
        
        return s.top();
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends