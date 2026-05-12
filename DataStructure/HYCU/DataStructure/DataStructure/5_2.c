#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "5_2.h"


// 공백 연결 리스트를 생성하는 연산
linkedList_h* createLinkedList_h2(void) {
    linkedList_h* L = (linkedList_h*)malloc(sizeof(linkedList_h));
    if (L == NULL) return NULL;

    L->head = NULL;
    return L;
}

// 연결 리스트의 전체 메모리를 해제하는 연산
void freeLinkedList_h2(linkedList_h* L) {
    if (L == NULL) return;

    listNode* p;
    while (L->head != NULL) {
        p = L->head;
        L->head = L->head->link;
        free(p);
        p = NULL;
    }
}

// 연결 리스트를 순서대로 출력하는 연산
void printList2(linkedList_h* L) {
    if (L == NULL) return;

    listNode* p;
    printf("L = (");
    p = L->head;
    while (p != NULL) {
        printf("%s", p->data);
        p = p->link;
        if (p != NULL) printf(", ");
    }
    printf(") \n");
}

// 첫번째 노드를 삽입하는 연산
void insertFirstNode2(linkedList_h* L, char* x) {
    if (L == NULL) return;

    listNode* newNode = (listNode*)malloc(sizeof(listNode));
    if (newNode == NULL) return;

    strcpy(newNode->data, x);
    newNode->link = L->head;
    L->head = newNode;
}

// 노드를 pre 뒤에 삽입하는 연산
void insertMiddleNode2(linkedList_h* L, listNode* pre, char* x) {
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
void insertLastNode2(linkedList_h* L, char* x) {
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
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = newNode;
}


void deleteNode2(linkedList_h* L, listNode* p) {
    if (L == NULL) return;

    listNode* pre;

    if (L->head == NULL) return;
    if (L->head->link == NULL) {
        free(L->head);
        L->head = NULL;
        return;
    }
    else if (p == NULL) return;
    else {
        pre = L->head;
        while (pre->link != p) {
            pre = pre->link;
        }
        pre->link = p->link;
        free(p);
    }

}

listNode* searchNode2(linkedList_h* L, char* x) {
    if (L == NULL) return NULL;
    listNode* temp = L->head;
    while (temp != NULL) {
        if (strcmp(temp->data, x) == 0) return temp;
        else temp = temp->link;
    }
    return temp;
}

void reverse2(linkedList_h* L) {
    if (L == NULL) return;

    listNode* p;
    listNode* q;
    listNode* r;

    p = L->head;
    q = NULL;
    r = NULL;

    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->link;

        q->link = r;
    }
    L->head = q;
}


void testCode_5_2() {
    linkedList_h* L;
    L = createLinkedList_h2();
    listNode* p;

    insertLastNode2(L, "MON");
    insertLastNode2(L, "수");
    insertLastNode2(L, "SUN");

    p = searchNode2(L, "수");
    if (p == NULL) {
        printf("찾는 데이터가 없습니다.\n");
    }
    else {
        printf("[%s]를 찾았습니다.", p->data);
    }

    deleteNode2(L, p);
    reverse2(L);
    freeLinkedList_h2(L);
    printList2(L);

}