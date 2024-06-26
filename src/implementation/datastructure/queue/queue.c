//
// Created by Yoon BeongWook on 4/21/24.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct NODE {
    char szData[64];
    struct NODE* next;
} NODE;

NODE* p_queue_head = NULL;
NODE* g_pTail = 0;

int IsQueueEmpty() {
    return (p_queue_head == NULL || p_queue_head->next == NULL);
}

void PrintQueueList(void) {
    printf("\nPrintQueueList()\n");
    NODE* pHead = p_queue_head->next;
    while (pHead != NULL) {
        printf("[%p] %s, next[%p]\n", pHead, pHead->szData, pHead->next);
        pHead = pHead->next;
    }
}

void ReleaseQueueList(void)
{
    printf("\nReleaseList()\n");
    NODE* pTmp = p_queue_head->next;
    while (pTmp != NULL) {
        NODE* pDelete = pTmp;
        pTmp = pTmp->next;

        printf("Delete: [%p] %s\n", pDelete, pDelete->szData);
        free(pDelete);
    }
    p_queue_head = 0;
    g_pTail = 0;
}


int Enqueue(char* pszData)
{
    NODE* pNode = (NODE*)malloc(sizeof(NODE));
    memset(pNode, 0, sizeof(NODE));
    strncpy(pNode->szData, pszData, sizeof(pNode->szData));

    if (p_queue_head == NULL)
    {
        p_queue_head = (NODE*)malloc(sizeof(NODE));
        memset(p_queue_head, 0, sizeof(NODE));

        // 리스트에 추가된 첫번째 데이터 처리
        p_queue_head->next = pNode;
    } else {
        g_pTail->next = pNode;
    }
    g_pTail = pNode;
    return 1;
}

int Dequeue(NODE* pGetNode) {
    if (IsQueueEmpty())
        return 0;

    NODE* stack_pointer = p_queue_head->next;
    memcpy(pGetNode, stack_pointer, sizeof(NODE));
    p_queue_head->next = stack_pointer->next;
    free(stack_pointer);
    printf("Dequeue: %s\n", pGetNode->szData);
    return 1;
}

int Queue() {
    // Queue 테스트를 위한 코드

    Enqueue("TEST01");
    Enqueue("TEST02");
    Enqueue("TEST03");

    PrintQueueList();

    NODE node = {0};
    printf("\nDequeue()\n");
    Dequeue(&node);
    Dequeue(&node);
    Dequeue(&node);


    PrintQueueList();
    ReleaseQueueList();
    return 0;
}