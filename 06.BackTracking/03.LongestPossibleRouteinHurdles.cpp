//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

        //down
class Solution {
public:
    
    int findlongestPath(vector<vector<int>> &matrix, int row, int col, int xd, int yd,int n,int m,int len){
        if(row<0||col<0||row>=n||col>=m||matrix[row][col]==0){
            return -1;
        }
        if(row==xd&&col==yd){
            return len;
        }
        matrix[row][col]=0;
        int up=findlongestPath(matrix,row-1,col,xd,yd,n,m,len+1);
        int dow=findlongestPath(matrix,row+1,col,xd,yd,n,m,len+1);
        int lef=findlongestPath(matrix,row,col-1,xd,yd,n,m,len+1);
        int rig=findlongestPath(matrix,row,col+1,xd,yd,n,m,len+1);
        matrix[row][col]=1;
        return max(rig,max(up,max(dow,lef)));
    }


    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
      int n=matrix.size();
      int m=matrix[0].size();
      return findlongestPath(matrix,xs,ys,xd,yd,n,m,0);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends