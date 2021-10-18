#include <stdlib.h>
#include "stdio.h"
// 带头结点的链表

// 实现节点
typedef struct Node{
    int elem;
    struct Node *next;
}Node;
void insertNode(Node *firstNode,int index,int targetElem);
// 创建链表 带头节点
Node *createList(int value){
    Node *head=malloc(sizeof(Node));
    Node * firstNode = malloc(sizeof(Node));
    head->next = firstNode;
    firstNode->elem = value;
    firstNode->next = NULL;
    return head;
}
// 打印链表
void printList(Node *firstNode){
    Node *tmp;
    tmp=firstNode->next;
    while (tmp!=NULL){
        printf("链表：%d\n",tmp->elem);
        tmp=tmp->next;
    }
}

int getLength(Node *firstNode){
    int count=0;
    Node *tmp;
    tmp=firstNode->next;
    while (tmp!=NULL){
        count++;
        tmp=tmp->next;
    }
    return count;
}

//找节点
Node *findNode(int posi,Node *firstNode){
    if (posi>getLength(firstNode))return NULL;
    Node *tmp;
    tmp=firstNode;
    int count=0;
    while (count<=posi-1){
        count++;
        tmp=tmp->next;
    }
    return tmp;
}


//追加
void append(Node *firstNode,int value){
    insertNode(firstNode,getLength(firstNode)+1,value);
}

// 插入节点  这次就不给append方法了
void insertNode(Node *firstNode,int index,int targetElem){
    Node *targetNode=malloc(sizeof(Node));
    targetNode->elem=targetElem;
    targetNode->next = NULL;
    Node *tmp;
    if (index>getLength(firstNode)+1){
        index = getLength(firstNode)+1; // 这样 index永远都是合法的 一旦超过长度 就是默认放到最后一个
    }
    // 插入到 index位置 得先遍历到index-1的位置 只有tmp为index-1的位置的节点才好操作
    tmp=findNode(index-1,firstNode);
    targetNode->next=tmp->next;
    tmp->next=targetNode;
}

//删除
int delete(int index, Node *firstNode) {
    // 超过边界值判定
    if (index<0||index>getLength(firstNode)) return -1;
    Node *tmp;
    int deletedValue;
    tmp = findNode(index - 1, firstNode);
    deletedValue = tmp->next->elem;
    tmp->next = tmp->next->next;
    return deletedValue;
}

// main使用方法

void main(){
    Node * firstNode = createList(1);
    insertNode(firstNode,2,2);
    append(firstNode,3);
    append(firstNode,4);
    append(firstNode,5);
    insertNode(firstNode,1,0);
    insertNode(firstNode,3,100);
    printf("被删除的数是：%d\n",delete(3,firstNode));
    printf("链表长度: %d\n",getLength(firstNode));
    printList(firstNode);
    printf("第三个节点是:%d\n",findNode(3,firstNode)->elem);
}