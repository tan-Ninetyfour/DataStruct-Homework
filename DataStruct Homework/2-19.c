#include <stdio.h>

typedef struct LNode {   // 修正结构体定义
    int data;
    struct LNode *next;  // 将int*改为struct LNode*
} LNode, *LinkList;

int ListDeleteMore(LinkList* L, int x) {
    int count = 0;
    LNode *current = *L;
    LNode *prev = NULL;
    
    // 处理头结点连续为x的情况   
    while (current != NULL && current->data == x) {
        *L = current->next;
        free(current);
        current = *L;
        count++;
    }
    
    // 处理中间结点
    while (current != NULL) {
        if (current->data == x) {
            prev->next = current->next;
            free(current);
            current = prev->next;
            count++;
        } else {
            prev = current;
            current = current->next;
        }
    }
    return count;
}