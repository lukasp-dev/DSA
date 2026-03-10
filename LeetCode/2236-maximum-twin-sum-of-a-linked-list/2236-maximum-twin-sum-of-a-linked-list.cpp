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
    ListNode* reverseNode(ListNode* node){
        if(!node || !node->next) return node;
        
        ListNode* tmp = reverseNode(node->next);
        node->next->next = node;
        node->next = nullptr;

        return tmp;
    }

    int pairSum(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* tmp = head;

        while(fast && fast->next){
            fast = fast->next->next;
            tmp = slow;
            slow = slow->next;
        }

        ListNode* secondHalf = reverseNode(slow);
        ListNode* firstHalf = head;
        int ret = 0;
        
        while (secondHalf) {
            ret = max(ret, firstHalf->val + secondHalf->val);
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return ret;
    }
};