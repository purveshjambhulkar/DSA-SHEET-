//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        // code here
        int arr[] = {2000 , 500 , 200, 100,50,20,10,5,2,1};
        vector<int> result;
        int ans  = 0;
        int n = N;
        int i = 0 ;
        while(ans != N){
            if(n >= arr[i]){
                result.push_back(arr[i]);
                ans = ans + arr[i];
                n = n- arr[i];
            }else{
                i++;            }
        }
        return result;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends