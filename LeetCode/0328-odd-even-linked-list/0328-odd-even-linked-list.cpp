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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* oddHead = new ListNode();
        ListNode* oddPtr = oddHead;

        ListNode* evenHead = new ListNode();
        ListNode* evenPtr = evenHead;

        int counter = 1;
        
        while(head != nullptr){
            if(counter%2 == 1){
                oddPtr->next = head;
                oddPtr = oddPtr->next;
            }else{
                evenPtr->next = head;
                evenPtr = evenPtr->next;
            }

            counter++;
            head = head->next;
        }

        evenPtr->next = nullptr;
        oddPtr->next = evenHead->next; 
        return oddHead->next;
    }
};