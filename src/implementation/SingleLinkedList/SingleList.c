//
// Created by Yoon BeongWook on 4/19/24.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct NODE
{
    char szData[64];
    struct NODE* next;
} NODE;

NODE* g_pHead = NULL;

// 연결 리스트 전체 데이터 출력
void printList(void){
    NODE* pHead = g_pHead;
    while(pHead != NULL){
        printf("[%p] %s, next[%p]\n", pHead, pHead->szData, pHead->next);
        pHead = pHead->next;
    }
}

int InsertNewNode(char* pszData)
{
    NODE* pNode = (NODE*)malloc(sizeof(NODE));
    memset(pNode, 0, sizeof(NODE));
    strncpy(pNode-> szData, pszData, sizeof(pNode -> szData));


    if(g_pHead == NULL) // 헤드 노드가 NULL인 경우 = 연결 리스트가 존재하지 않을 경우
        g_pHead = pNode;
    else { // 연결리스트가 존재하는 경우
        // 새로 생성한 노드의 next(가리키는 주소)를 기존의 노드로 설정
        pNode -> next = g_pHead;
        // 새로 생성한 노드를 헤드 노드로 설정
        g_pHead = pNode;
    }

    return 1;
}

int SingleList(){
    // List 테스트를 위한 코드
    InsertNewNode("TEST01");
    InsertNewNode("TEST02");
    InsertNewNode("TEST03");
    printList();
    return 0;
}