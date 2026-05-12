#pragma once
// 원형 연결 리스트의 노드 구조를 구초체로 정의

typedef struct ListNode {
	char data[4];
	struct ListNode* link;
} listNode;

typedef struct {
	listNode* head;
}linkedList_h;


linkedList_h* createLinkedList_h3(void);
void printList3(linkedList_h* CL);
void insertFirstNode3(linkedList_h* CL, char* x);
void insertMiddleNode3(linkedList_h* CL, listNode* pre, char* x);
void deleteNode3(linkedList_h* CL, listNode* old);
listNode* searchNode3(linkedList_h* CL, char* x);
