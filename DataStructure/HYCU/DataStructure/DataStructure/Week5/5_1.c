#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "5_1.h"

// 공백 연결 리스트를 생성하는 연산
linkedList_h* createLinkedList_h(void) {
	linkedList_h* L = (linkedList_h*)malloc(sizeof(linkedList_h));
	if (L == NULL) return NULL;

	L->head = NULL;
	return L;
}

// 연결 리스트의 전체 메모리를 해제하는 연산
void freeLinkedList_h(linkedList_h* L) {
	if (L == NULL) return;

	listNode* p;
	while (L->head != NULL){
		p = L->head;
		L->head = L->head->link;
		free(p);
		p = NULL;
	}
}

// 연결 리스트를 순서대로 출력하는 연산
void printList(linkedList_h* L) {
	if (L == NULL) return;

	listNode* p;
	printf( "L = (" );
	p = L->head;
	while (p != NULL) {
		printf("%s", p->data);
		p = p->link;
		if (p != NULL) printf(", ");
	}
	printf(") \n");
}

// 첫번째 노드를 삽입하는 연산
void insertFirstNode(linkedList_h* L, char* x) {
	if (L == NULL) return;

	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	if (newNode == NULL) return;

	strcpy(newNode->data, x);
	newNode->link = L->head;
	L->head = newNode;
}

// 노드를 pre 뒤에 삽입하는 연산
void insertMiddleNode(linkedList_h* L, listNode* pre, char* x) {
	if (L == NULL) return;

	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	if (newNode == NULL) return;
	strcpy(newNode->data, x);

	if (L->head == NULL) {				// 공백리스트의 경우
		newNode->link = NULL;
		L->head = newNode;
	}
	else if (pre == NULL) {
		newNode->link = L->head;
		L->head = newNode;
	}
	else {
		newNode->link = pre->link;	// pre 노드 뒤에 새 노드 연결
		pre->link = newNode;
	}
}

// 마지막 노드로 삽입하는 연산
void insertLastNode(linkedList_h* L, char* x) {
	if (L == NULL) return;

	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	if (newNode == NULL) return;

	strcpy(newNode->data, x);
	newNode->link = NULL;
	if (L->head == NULL) {		// 현재 리스트가 공백인 경우
		L->head = newNode;
		return;
	}
	// 현재 리스트가 공백이 아닌 경우
	listNode* temp = L->head;
	while (temp->link != NULL){
		temp = temp->link;
	}
	temp->link = newNode;
}



void testCode_5_1() {
	linkedList_h* L;
	L = createLinkedList_h();
	printf("(1) 공백리스트 생성하기 \n");
	printList(L);

	printf("\n(2) 리스트에 [수] 노드 삽입하기 \n");
	insertFirstNode(L, "수");
	printList(L);
	
	printf("\n(3) 리스트 마지막에 [금] 노드 삽입하기\n");
	insertLastNode(L, "금");
	printList(L);

	printf("\n(4) 리스트 첫 번째에 [월] 노드 삽입하기\n");
	insertFirstNode(L, "월");
	printList(L);

	printf("\n(5) 리스트 공간을 해제하여 공백 리스트로 만들기\n");
	freeLinkedList_h(L);
	printList(L);
}