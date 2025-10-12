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
    ListNode* reverse(ListNode* node){
        if(node->next == nullptr){
            return node;
        }

        ListNode* reversedHead = reverse(node->next);

        node->next->next = node;
        node->next = nullptr;

        return reversedHead;
    }

    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode* reversedHead = reverse(slow);

        int maxTwinSum = 0;
        
        while(head && reversedHead){
            maxTwinSum = max(maxTwinSum, head->val + reversedHead->val);
            head = head->next;
            reversedHead = reversedHead->next;
        }

        return maxTwinSum;
    }
};