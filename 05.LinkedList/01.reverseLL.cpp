/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //condtition to check if linked list is empty
        if(!head){
            return head;
        }

        ListNode* curr = head;
        ListNode* prev = head;
        ListNode* nxt = head->next;
        prev->next = NULL;
        while (nxt != NULL) {
            curr = nxt;
            nxt = nxt->next;
            curr->next = prev;
            prev = curr ;
        }
        return curr;
    }
};