//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    
    void bfs(int V , vector<int> adj[] , vector<int>&ans  , vector<int> &visited , int node ){
        queue<int> q;
        q.push(node);
        visited[node] = 1;
        
        while(!q.empty()){
            int temp = q.front();
            ans.push_back(temp);
            q.pop();
            
            //add all the node attached to this node
            for(auto i : adj[temp]){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = 1;
                }
            }
            
        }
    }
    
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        vector<int> visited(V , 0);
        
        bfs(V , adj , ans ,  visited , 0);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends