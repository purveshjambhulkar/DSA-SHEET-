/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // FFLOYDS ALGORITHM

    bool hasCycle(ListNode* head) {

        if (head == nullptr || head->next == nullptr) {
        return false; // No cycle if no nodes or only one node
    }

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next; // Move slow pointer by one step
        fast = fast->next->next; // Move fast pointer by two steps

        if (slow == fast) {
            return true; // Cycle detected
        }
    }

    return false; // No cycle found
    }
};/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // FFLOYDS ALGORITHM

    bool hasCycle(ListNode* head) {

        if (head == nullptr || head->next == nullptr) {
        return false; // No cycle if no nodes or only one node
    }

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next; // Move slow pointer by one step
        fast = fast->next->next; // Move fast pointer by two steps

        if (slow == fast) {
            return true; // Cycle detected
        }
    }

    return false; // No cycle found
    }
};