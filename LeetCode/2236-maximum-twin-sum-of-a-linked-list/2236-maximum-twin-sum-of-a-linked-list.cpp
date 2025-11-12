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
        if(node==nullptr || node->next == nullptr){
            return node;
        }

        ListNode* res = reverse(node->next);
        node->next->next = node;
        node->next = nullptr;
        
        return res;
    }

    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* start = head;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* end = reverse(slow);
        int res = 0;

        while(end){
            res = max(res, start->val + end->val);
            start = start->next;
            end = end->next;
        }

        return res;
    }
};