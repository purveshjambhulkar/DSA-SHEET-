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
    ListNode* sort(ListNode* list1, ListNode* list2) {
        ListNode* head = nullptr;
        if (list1->val <= list2->val) {
            head = list1;
            list1 = list1->next;
        } else {
            head = list2;
            list2 = list2->next;
        }

        ListNode* prev = head;

        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                ListNode* curr = nullptr;
                curr = list1;
                prev->next = curr;
                prev = prev->next;
                list1 = list1->next;
            } else {
                ListNode* curr = nullptr;
                curr = list2;
                prev->next = curr;
                prev = prev->next;
                 list2 = list2->next;
            }
        }

        if (list1 == NULL) {
            prev->next = list2;
        }
        if (list2 == NULL) {
            prev->next = list1;
        }

        return head;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // condition 1
        if (list1 == NULL) {
            return list2;
        }
        if (list2 == NULL) {
            return list1;
        }

        // condition 2
        if (list1 == NULL && list2 == NULL) {
            return list1;
        }

        // condition 3 both not null
        return sort(list1 , list2);
    }
};  