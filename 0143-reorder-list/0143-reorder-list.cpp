class Solution {
public:
    ListNode* reverse(ListNode* node) {
        if (!node || !node->next) return node;
        ListNode* newHead = reverse(node->next);
        node->next->next = node;
        node->next = nullptr;
        return newHead;
    }

    ListNode* merge(ListNode* l1, ListNode* l2, int flag = 0) {
        if (!l1) return l2;
        if (!l2) return l1;

        if (flag % 2 == 0) {
            l2->next = merge(l1, l2->next, flag + 1);
            return l2;
        } else {
            l1->next = merge(l1->next, l2, flag + 1);
            return l1;
        }
    }

    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // 1. Find the middle
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Reverse second half
        ListNode* second = reverse(slow->next);
        slow->next = nullptr;

        // 3. Merge: pass second first to make l2 start
        head = merge(second, head);
    }
};
