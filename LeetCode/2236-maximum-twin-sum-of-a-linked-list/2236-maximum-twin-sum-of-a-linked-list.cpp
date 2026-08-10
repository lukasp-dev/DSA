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
    ListNode* reverseLinkedList(ListNode* node) {
        if(node == nullptr || node->next == nullptr) {
            return node;
        }

        ListNode* lastNode = reverseLinkedList(node->next);
        
        node->next->next = node;
        node->next = nullptr;

        return lastNode;
    }

    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* reversedHead = reverseLinkedList(slow);

        int maxPair = 0;
        
        while(reversedHead != nullptr) {
            maxPair = max(maxPair, head->val + reversedHead->val);
            head = head->next;
            reversedHead = reversedHead->next;
        }

        return maxPair;
    }
};