//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int x)
        : data(x)
        , next(nullptr) {}
};

void printList(Node *head) {
    Node *temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


// } Driver Code Ends
/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution {
  public:

   Node *removeDuplicates(Node *head) {
    unordered_set<int> hashSet;
    Node *curr = head;
    Node *prev = nullptr;

    while (curr != nullptr) {

        // Check if the element is already in the hash table
        if (hashSet.find(curr->data) != hashSet.end()) {

            // Element is present, remove it
            prev->next = curr->next;

            // Delete the curr node
            Node *temp = curr;
            curr = curr->next;
            delete temp;
        }
        else {

            // Element is not present, add it to hash table
            hashSet.insert(curr->data);
            prev = curr;
            curr = curr->next;
        }
    }
    return head;


}


//APPROACH 1 - TLE

// class Solution {
//   public:
//   Node* removeDuplicates(Node* head) {
//     Node* curr1 = head; 

//     // Traverse each node in the list
//     while (curr1 != nullptr) {
//         Node* curr2 = curr1; 

//         // Traverse the remaining nodes to find and 
//         // remove duplicates
//         while (curr2->next != nullptr) {
            
//             // Check if the next node has the same 
//             // data as the current node
//             if (curr2->next->data == curr1->data) {
                
//                 // Duplicate found, remove it
//                 Node* duplicate = curr2->next;  
//                 curr2->next = curr2->next->next;  

//                 // Free the memory of the duplicate node
//                 delete duplicate;
//             } else {
              
//                 // If the next node has different data from 
//                 // the current node, move to the next node
//                 curr2 = curr2->next;
//             }
//         }
        
//         // Move to the next node in the list
//         curr1 = curr1->next;
//     }
//     return head;
// }

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

        if (arr.empty()) {
            cout << "empty" << endl;
            continue;
        }

        Node *head = new Node(arr[0]);
        Node *tail = head;

        for (size_t i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        Node *result = ob.removeDuplicates(head);
        printList(result);
    }

    return 0;
}

// } Driver Code Ends