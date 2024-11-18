//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    bool findPair(vector<int> &arr, int x) {
        // code here
        
        
        sort(arr.begin() , arr.end());
        int i = 0 ;
        int j = 1; 
        
        
        while(i < arr.size() && j < arr.size()){
            if(i != j && (arr[j] - arr[i] == x || arr[i] - arr[j] == x)){
                return true;
                
            }else if(arr[j] - arr[i] < x){
                j++;
            }else{
                i++;
            }
        }
        
        return false;
        
        
    }
};

//APPROACH 1 - TLE

// class Solution {
//   public:
//     bool findPair(vector<int> &arr, int x) {
//         // code here
//         // sort(arr.begin() , arr.end());
        
//         for(int i = 0 ; i < arr.size() ; i++){
//             for(int j = 0 ; j < arr.size() ; j++){
//                 if(i == j){
//                     continue;
//                 }
                
//                 if(arr[j] - arr[i] == x){
//                     return true;
//                 }
//             } 
//         }
//         return false;
//     }
// };


//{ Driver Code Starts.

int main() {

    int t;
    scanf("%d ", &t);

    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int k;
        scanf("%d ", &k);
        Solution obj;

        cout << (obj.findPair(arr, k) ? "true" : "false") << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends