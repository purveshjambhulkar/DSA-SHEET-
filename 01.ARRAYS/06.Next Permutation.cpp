//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
        
        //step1 - find the first decreasing number from right to left
        int pivot = -1;
        for(int i = arr.size()-1;i>0;i--){
            if(arr[i] > arr[i-1]){
                pivot = i-1;
                break;
            }
        }
        
        if(pivot == -1){
            return reverse(arr.begin() , arr.end());
        }
        
        
        //step 2 - swap the first greater number from the number next to the pivot and swap them
        for(int i = arr.size() - 1 ; i > pivot;i--){
            if(arr[i] > arr[pivot]){
                // int temp = arr[pivot];
                // arr[pivot] = arr[i];
                // arr[i] = temp;
                swap(arr[pivot] , arr[i]);
                break;
            }
        }
        
        //step 3 - reverse the number in front of the pivot
        int i = pivot + 1;
        int j = arr.size() - 1;
        while(i < j){
            swap(arr[i] , arr[j]);
            i++;
            j--;
        }
        
        
        
        
        
        
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int n = arr.size();
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends