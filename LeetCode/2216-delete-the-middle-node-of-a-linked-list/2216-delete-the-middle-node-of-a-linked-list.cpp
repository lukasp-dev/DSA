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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr) return head;

        int size=0;
        
        ListNode* tmp = head;
        
        while(tmp != nullptr){
            size++;
            tmp = tmp->next;
        }

        if(size == 1){
            return nullptr;
        }

        tmp = head;
        int deleteIdx = size/2;

        while(deleteIdx != 1){
            tmp = tmp->next;
            deleteIdx--;
        }
        
        tmp->next = tmp->next->next;

        return head;
    }
};