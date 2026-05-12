#pragma once

typedef struct ListNode {
	char data[4];
	struct ListNode* link;
} listNode;

typedef struct {
	listNode* head;
} linkedList_h;

linkedList_h* createLinkedList_h2(void);
void freeLinkedList_h2(linkedList_h* L);
void printList2(linkedList_h* L);
void insertFirstNode2(linkedList_h* L, char* x);
void insertMiddleNode2(linkedList_h* L, listNode* pre, char* x);
void insertLastNode2(linkedList_h* L, char* x);
void deleteNode2(linkedList_h* L, listNode* p);
listNode* searchNode2(linkedList_h* L, char* x);
void reverse2(linkedList_h* L);