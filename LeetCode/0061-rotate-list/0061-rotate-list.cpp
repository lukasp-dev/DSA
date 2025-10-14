class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        int n = 0;
        ListNode* tmp = head;
        while (tmp) {
            n++;
            tmp = tmp->next;
        }

        int move = n - (k % n);
        if (move == n || move == 0) return head;

        ListNode* parent = nullptr;
        ListNode* curr = head;

        for (int i = 0; i < move; i++) {
            parent = curr;
            curr = curr->next;
        }

        parent->next = nullptr;
        ListNode* newHead = curr;
\
        while (curr->next) curr = curr->next;
        curr->next = head;

        return newHead;
    }
};
