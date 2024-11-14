//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool detectCycle(int i ,vector<vector<int>> &adj ,vector<bool> &visited ,vector<bool> &recStack  ){
        
        if(!visited[i]){
            
            //mark as visited and recStack
            visited[i] = true;
            recStack[i] = true;
            
            for(int x : adj[i]){
                if(!visited[x] && detectCycle(x , adj , visited , recStack)){
                    return true;
                }else if(recStack[x]){
                    return true;
                }
            }
            
        }
        
        recStack[i] = false;
        return false;
        
    }
    
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        
        vector<bool> visited(V,false);
        vector<bool> recStack(V,false);
        
        for(int i = 0 ; i < V ; i++){
            if(!visited[i] && detectCycle(i , adj , visited, recStack)){
                return true;
            }
        }
        
        return false;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends