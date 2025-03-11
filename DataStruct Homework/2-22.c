#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
    int data;
    struct LNode* next;
} LNode;

// 插入操作（position从0开始计数）
LNode* ListInsert(LNode* head, int position, int elem) {
    LNode* newNode = (LNode*)malloc(sizeof(LNode));
    newNode->data = elem;
    
    // 插入到第一个位置或空链表
    if (position == 0 || head == NULL) {
        newNode->next = head;
        return newNode; // 返回新的头指针
    }

    // 普通位置插入
    LNode* p = head;
    for (int i = 0; p->next && i < position-1; i++) {
        p = p->next;
    }
    newNode->next = p->next;
    p->next = newNode;
    return head;
}

// 删除操作（position从0开始计数）
LNode* ListDelete(LNode* head, int position) {
    if (!head) return NULL;

    // 删除第一个节点
    if (position == 0) {
        LNode* newHead = head->next;
        free(head);
        return newHead;
    }

    // 普通位置删除
    LNode* p = head;
    for (int i = 0; p->next && i < position-1; i++) {
        p = p->next;
    }
    if (p->next) {
        LNode* delNode = p->next;
        p->next = delNode->next;
        free(delNode);
    }
    return head;
}

int main() {
    LNode* head = NULL;
    
    // 测试插入
    head = ListInsert(head, 0, 10);   // 插入第一个节点
    head = ListInsert(head, 0, 20);   // 头部插入
    head = ListInsert(head, 1, 30);   // 中间插入
    head = ListInsert(head, 3, 40);   // 尾部插入
    
    // 测试删除
    head = ListDelete(head, 0);       // 删除头部
    head = ListDelete(head, 2);       // 删除尾部
    head = ListDelete(head, 1);       // 删除中间节点
    
    return 0;
}