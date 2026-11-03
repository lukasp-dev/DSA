# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: ListNode | None, val: int) -> ListNode | None:
        if head is None:
            return None

        while head is not None and head.val == val:
            head = head.next

        ptr = head

        while ptr is not None and ptr.next is not None:
            if ptr.next.val == val:
                ptr.next = ptr.next.next
            
            else:
                ptr = ptr.next
        

        return head