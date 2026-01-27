from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=None, next=None):
        self.val = val
        self.next = next


class Solution:
    def sort(self, list: Optional[ListNode]) -> Optional[ListNode]:
        head = list
        curr = list.next

        while curr is not None:
            key = curr.val
            prev = head

            while curr != prev and prev.val > key:
                # ------ valor anterior maior que atual, troca -------
                # salva uma copia do anterior
                tmp = prev.val
                # valor anterior agora é o atual
                prev.val = key
                # o novo valor agora é a copia salva
                key = tmp
                # o proximo agora recebe o ponteiro do anterior
                curr = prev.next

            # se prev <= key, a validacao continua e pula para o proximo
            curr.val = key
            curr = curr.next

        return head

    def bubbleSort(self, list: Optional[ListNode]) -> Optional[ListNode]:
        # coming soon
        return list

    def mergeTwoLists(
        self, list1: Optional[ListNode], list2: Optional[ListNode]
    ) -> Optional[ListNode]:
        # verificar se as listas existem
        if not list1:
            return list2
        if not list2:
            return list1

        # definir um head para nova lista (valor inicial da lista ligada)
        if list1.val <= list2.val:
            head = list1
            list1 = list1.next

        if list2.val <= list2.val:
            head = list2
            list2 = list2.next

        current = head

        while list1 and list2:
            # elemento 1 é menor que o 2?
            if list1.val <= list2.val:
                # se sim, ele é o novo atual (uma vez que a lista deve estar ordenada)
                current.next = list1
                # pula para o proximo da lista 1
                list1 = list1.next
            else:
                # caso contrario, o proixmo item é o elemento da lista 2
                current.next = list2
                # pula para verificar o proximo elemento da lista 2
                list2 = list2.next

            # pular para o próximo
            current = current.next

        # retorna o penulitimo valor da lista, dado que trabalhamos com prev/curr
        current.next = list1 if list1 else list2

        return head


a = ListNode(1)
a.next = ListNode(3)
a.next.next = ListNode(5)

b = ListNode(0)
b.next = ListNode(2)
b.next.next = ListNode(4)
b.next.next.next = ListNode(6)

s = Solution()
items = s.mergeTwoLists(a, b)
# items = s.sort(b)

while items is not None:
    if items.val is not None:
        print(items.val)
    items = items.next
