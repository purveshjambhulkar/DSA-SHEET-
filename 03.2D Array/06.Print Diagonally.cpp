//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDiagonal(int N, vector<vector<int>> A)
	{
		// Your code goes here
		vector<int> ans;
		for(int i = 0 ; i < N ; i++){
		    int row = 0;
		    int col = i;
		    ans.push_back(A[row][col]);
		    row++;
		    col--;
		    while(row < N && col >=0 ){
		        ans.push_back(A[row][col]);
		        row++;
		        col--;
		    }
		}
		
		
		for(int j = 1; j < N ; j++){
		    int row = j;
		    int col = N-1;
		    ans.push_back(A[row][col]);
		    row++;
		    col--;
		    while(row < N && col >=0 ){
		        ans.push_back(A[row][col]);
		        row++;
		        col--;
		    }
		}
		
		return ans;
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDiagonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    
cout << "~" << "\n";
}

    return 0;
}

// } Driver Code Ends