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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pointer_A = headA;
        ListNode* pointer_B = headB;

        while(pointer_A != pointer_B){
            if(pointer_A == nullptr) {
                pointer_A = headB;
                continue;
            }
            if(pointer_B == nullptr) {
                pointer_B = headA;
                continue;
            }

            pointer_A = pointer_A->next;
            pointer_B = pointer_B->next;
        }

        return pointer_A;
    }
};