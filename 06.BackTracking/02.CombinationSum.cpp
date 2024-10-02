//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    void solve(vector<int> &A, int B ,  vector<int> temp , vector<vector<int>> &result,int i){
        
        
        //base case - if we found the result
        
        if(B == 0){
            result.push_back(temp);
            return;
        }
        
        while(i < A.size() && B - A[i] >=0){
            temp.push_back(A[i]);
            
            solve(A  ,B- A[i] , temp , result , i );
            i++;
            
            temp.pop_back();
        }
        
    }
    
    
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        
        //sort the array
        sort(A.begin() , A.end());
        
        
        //remove unique elements from the array
        A.erase(unique(A.begin() , A.end()) , A.end());
        
        vector<int> temp ;
        vector<vector<int>> result;
        
        solve(A , B  , temp  , result , 0);
        
        return result;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends