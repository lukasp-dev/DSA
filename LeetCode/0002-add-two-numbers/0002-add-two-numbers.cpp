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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode();
        ListNode* tmp = res;
        int carry  = 0;

        while(l1 != nullptr && l2 != nullptr){
            int sum = (carry + l1->val + l2->val)%10;
            carry = (carry + l1->val + l2->val)/10;

            tmp->next = new ListNode(sum);
            tmp = tmp->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        if(!l1){
            while(l2){
                int sum = (carry + l2->val)%10;
                carry = (carry + l2->val)/10;
                
                tmp->next = new ListNode(sum);
                tmp = tmp->next;
                l2 = l2->next;
            }
        }else if(!l2){
            while(l1){
                int sum = (carry + l1->val)%10;
                carry = (carry + l1->val)/10;

                tmp->next = new ListNode(sum);
                tmp = tmp->next;
                l1 = l1->next;
            }
        }

        if(carry){
            tmp->next = new ListNode(carry);
        }

        return res->next;
    }
};

