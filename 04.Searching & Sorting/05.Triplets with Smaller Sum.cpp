//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    long long countTriplets(int n, long long sum, long long arr[]) {
        // Your code goes here
        
        //Approach:
        //1 sort the array
        //2 intialize a i+1 AND n-1 var
        //3 set a loop and count
        
        sort(arr,arr+n);
        int ans = 0;
        
        //loop which selects only the first element of the triplet
        //therefore we skip the last 2 elements of the array as they cannot form  the triplet
        for(int i = 0 ; i < n-2; i++){
            int j = i+1;
            int k = n-1;
            
            while(j<k){
                
                //skipp the elements form last that exceeds the sum 
                //move the right corner i.e k to the left to search for smaller elements
                if(arr[i] + arr[j] +arr[k] >= sum){
                    k--;
                }else{
                    //now for the current value of i and j there can be k-j triplets
                    ans += (k-j);
                    j++;
                }
            }
            
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        long long sum;
        cin >> n >> sum;
        long long arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countTriplets(n, sum, arr);

        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends