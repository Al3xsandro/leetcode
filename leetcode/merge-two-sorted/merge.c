#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    struct ListNode *head = NULL;
    struct ListNode *current = NULL;

    if (list1 == NULL) {
        return list2;
    }

    if (list2 == NULL) {
        return list1;
    }

    if (list1->val <= list2->val) {
        head = list1;
        list1 = list1->next;
    } else {
        head = list2;
        list2 = list2->next;
    }

    current = head;

    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }

        current = current->next;
    }
    
    if (list1 != NULL) current->next = list1;
    if (list2 != NULL) current->next = list2;
    
    return head;
}

void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

int main() {
    struct ListNode* l1 = createNode(1);
    l1->next = createNode(2);
    l1->next->next = createNode(4);

    struct ListNode* l2 = createNode(1);
    l2->next = createNode(3);
    l2->next->next = createNode(4);

    printf("List 1: ");
    printList(l1);

    printf("List 2: ");
    printList(l2);

    struct ListNode* merged = mergeTwoLists(l1, l2);

    printf("Merged: ");
    printList(merged);

    return 0;
}