class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return nullptr;

        ListNode* ret = head;
        ListNode* ptr = head;
        int totalIdx = 0;

        // 1) 전체 길이 구하기
        while (ptr) {
            ptr = ptr->next;
            totalIdx++;
        }

        // 2) 머리 노드 제거 케이스
        if (totalIdx == n) {
            ListNode* del = head;
            ret = head->next;     // 새 head
            del->next = nullptr;  // (선택) 깔끔하게 끊기
            return ret;
        }

        // 3) 목표 앞 노드까지 이동
        int steps = totalIdx - n - 1; // 0-based로 앞까지
        ListNode* ptr2 = head;
        while (steps-- > 0) {
            ptr2 = ptr2->next;
        }

        // 4) 삭제
        ListNode* nxt = ptr2->next;       // 삭제할 노드
        ptr2->next = nxt->next;           // 건너뛰기
        nxt->next = nullptr;              // (선택) 깔끔하게 끊기
        return ret;
    }
};
