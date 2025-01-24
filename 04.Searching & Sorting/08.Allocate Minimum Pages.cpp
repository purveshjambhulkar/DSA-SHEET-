//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countStudents(vector<int> &arr, int pages) {
        int students = 1; // Start with one student
        int pagesStudent = 0; // Pages allocated to the current student

        for (int i = 0; i < arr.size(); i++) {
            if (pagesStudent + arr[i] <= pages) {
                // Add the current book's pages to the current student
                pagesStudent += arr[i];
            } else {
                // Assign the current book to the next student
                students++;
                pagesStudent = arr[i];
            }
        }
        return students;
    }

    int findPages(vector<int> &arr, int k) {
        int n = arr.size();

        // If there are more students than books, allocation is impossible
        if (k > n) return -1;

        // Define the search range
        int low = *max_element(arr.begin(), arr.end()); // Minimum possible pages
        int high = accumulate(arr.begin(), arr.end(), 0); // Maximum possible pages
        int result = -1;

        // Binary search
        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Check if `mid` pages can be allocated to `k` students
            if (countStudents(arr, mid) <= k) {
                result = mid;   // Update result
                high = mid - 1; // Try for a smaller maximum page allocation
            } else {
                low = mid + 1;  // Try for a larger maximum page allocation
            }
        }

        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends