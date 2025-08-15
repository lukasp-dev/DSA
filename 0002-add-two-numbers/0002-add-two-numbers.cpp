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
        vector<int> first;
        vector<int> second;

        while(l1 != nullptr){
            first.push_back(l1->val);
            l1 = l1->next;
        }

        while(l2 != nullptr){
            second.push_back(l2->val);
            l2 = l2->next;
        }

        if(first.size() > second.size()){
            second.resize(first.size());
        }else if(first.size() < second.size()){
            first.resize(second.size());
        }

        int val=0; int carry=0;
        ListNode* ret = new ListNode();
        ListNode* ptr = ret;

        for(int i = 0; i<second.size(); i++){
            val = (first[i] + second[i])%10;
            ptr -> next = new ListNode((val + carry)%10);
            ptr = ptr->next;
            carry = (first[i] + second[i] + carry)/10;
        }

        if(carry){
            ptr -> next = new ListNode(carry);
        }

        return ret->next;
    }
};