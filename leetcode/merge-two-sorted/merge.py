from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=None, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        # choose a valid head
        if list1.val <= list2.val:
            head = list1
            list1 = list1.next
        else:
            head = list2
            list2 = list2.next

        # set a copy for head
        current = head

        while list1 and list2:
            if list1.val <= list2.val:
                current.next = list1
                list1 = list1.next
            else:
                current.next = list2
                list2 = list2.next
            current = current.next

        current.next = list1 if list1 else list2

        return head


a = ListNode(1)
a.next = ListNode(3)
a.next.next = ListNode(5)

b = ListNode(0)
b.next = ListNode(4)
b.next.next = ListNode(6)

s = Solution()
items = s.mergeTwoLists(a, b)

while items is not None:
    if items.val is not None:
        print(items.val)
    items = items.next