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
// brute force solution baby

class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        if(count == n){
            ListNode* newHead = head->next;
            return newHead;
        }

        ListNode* tempButDiff = head;

        for (int i = 0; i < count - n - 1; i++) {
            tempButDiff = tempButDiff->next;
        }

        tempButDiff->next = tempButDiff->next->next;

        

        return head;
    }
};
