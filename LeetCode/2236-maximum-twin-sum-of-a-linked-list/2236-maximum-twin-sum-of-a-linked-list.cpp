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
    ListNode* reverseCopy(ListNode* head) {
        ListNode* reversed = nullptr;

        while (head) {
            ListNode* newNode = new ListNode(head->val);
            newNode->next = reversed;
            reversed = newNode;
            head = head->next;
        }

        return reversed;
    }

    int pairSum(ListNode* head) {
        ListNode* reversedHead = reverseCopy(head);
        int maxTwinSum = 0;
        
        while(head != nullptr){
            maxTwinSum = max(maxTwinSum, head->val + reversedHead->val);
            
            head = head->next; 
            reversedHead = reversedHead->next;
        }
        
        return maxTwinSum;
    }
};