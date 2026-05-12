#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "5_3.h"

linkedList_h* createLinkedList_h3(void) {
	linkedList_h* CL = (linkedList_h*)malloc(sizeof(linkedList_h));
	if (CL == NULL) return NULL;
	CL->head = NULL;
	return CL;
}


void printList3(linkedList_h* CL) {
    if (CL == NULL) return;
    listNode* p;
    printf(" CL =(" );
    p = CL->head;

    if (p == NULL) {
        printf(") \n"); return;
    }

    do {
        printf("%s", p->data);
        p = p->link;
        if (p != CL->head) printf(", ");
    } while (p != CL->head);
    printf("\n");
}


void insertFirstNode3(linkedList_h* CL, char* x) {
    if (CL == NULL) return;
    listNode* newNode = malloc(sizeof(listNode));
    if (newNode == NULL) return;

    listNode* temp = NULL;

    strcpy(newNode->data, x);
    if (CL->head == NULL) {
        CL->head = newNode;
        newNode->link = newNode;
    }
    else {
        temp = CL->head;
        while (temp->link != CL->head)
        {
            temp = temp->link;
        }
        newNode->link = temp->link;
        temp->link = newNode;
        CL->head = newNode;
    }
}

void insertMiddleNode3(linkedList_h* CL, listNode* pre, char* x) {
    if (CL == NULL || pre == NULL)  return;

    listNode* newNode = (listNode*)malloc(sizeof(listNode));
    if (newNode == NULL) return;

    strcpy(newNode->data, x);
    if (CL->head == NULL) {
        CL->head = newNode;
        newNode->link = newNode;
    }
    else{
        newNode->link = pre->link;
        pre->link = newNode;
    }
}

void deleteNode3(linkedList_h* CL, listNode* old) {
    listNode* pre;
    if (CL->head == NULL) return;
    if (CL->head->link == CL->head) {
        free(CL->head);
        CL->head = NULL;
        return;
    }
    else if (old == NULL) return;
    else{
        pre = CL->head;
        while (pre->link != old) {
            pre = pre->link;
        }
        pre->link = old->link;
        if (old == CL->head)
            CL->head = old->link;
        free(old);
    }
}

// 
listNode* searchNode3(linkedList_h* CL, char* x) {
    listNode* temp = CL->head;
    if (temp == NULL) return NULL;
    do {
        if (strcmp(temp->data, x) == 0) return temp;
        else temp = temp->link;

    } while (temp != CL->head);
   

    return NULL;
}

void testCode_5_3(){
    linkedList_h* CL;
    listNode* p;

    CL = createLinkedList_h3();
    insertFirstNode3(CL, "Mon");    // UTF-8 일 때 한글 사용X
    printList3(CL);

    p = searchNode3(CL, "Mon"); insertMiddleNode3(CL, p, "Web");
    printList3(CL);

    p = searchNode3(CL, "Web"); insertMiddleNode3(CL, p, "Fri");
    printList3(CL);

    deleteNode3(CL, p);
    printList3(CL);
}
