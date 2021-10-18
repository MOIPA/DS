#include <stdlib.h>
#include "stdio.h"
// ��ͷ��������

// ʵ�ֽڵ�
typedef struct Node{
    int elem;
    struct Node *next;
}Node;
void insertNode(Node *firstNode,int index,int targetElem);
// �������� ��ͷ�ڵ�
Node *createList(int value){
    Node *head=malloc(sizeof(Node));
    Node * firstNode = malloc(sizeof(Node));
    head->next = firstNode;
    firstNode->elem = value;
    firstNode->next = NULL;
    return head;
}
// ��ӡ����
void printList(Node *firstNode){
    Node *tmp;
    tmp=firstNode->next;
    while (tmp!=NULL){
        printf("����%d\n",tmp->elem);
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

//�ҽڵ�
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


//׷��
void append(Node *firstNode,int value){
    insertNode(firstNode,getLength(firstNode)+1,value);
}

// ����ڵ�  ��ξͲ���append������
void insertNode(Node *firstNode,int index,int targetElem){
    Node *targetNode=malloc(sizeof(Node));
    targetNode->elem=targetElem;
    targetNode->next = NULL;
    Node *tmp;
    if (index>getLength(firstNode)+1){
        index = getLength(firstNode)+1; // ���� index��Զ���ǺϷ��� һ���������� ����Ĭ�Ϸŵ����һ��
    }
    // ���뵽 indexλ�� ���ȱ�����index-1��λ�� ֻ��tmpΪindex-1��λ�õĽڵ�źò���
    tmp=findNode(index-1,firstNode);
    targetNode->next=tmp->next;
    tmp->next=targetNode;
}

//ɾ��
int delete(int index, Node *firstNode) {
    // �����߽�ֵ�ж�
    if (index<0||index>getLength(firstNode)) return -1;
    Node *tmp;
    int deletedValue;
    tmp = findNode(index - 1, firstNode);
    deletedValue = tmp->next->elem;
    tmp->next = tmp->next->next;
    return deletedValue;
}

// mainʹ�÷���

void main(){
    Node * firstNode = createList(1);
    insertNode(firstNode,2,2);
    append(firstNode,3);
    append(firstNode,4);
    append(firstNode,5);
    insertNode(firstNode,1,0);
    insertNode(firstNode,3,100);
    printf("��ɾ�������ǣ�%d\n",delete(3,firstNode));
    printf("������: %d\n",getLength(firstNode));
    printList(firstNode);
    printf("�������ڵ���:%d\n",findNode(3,firstNode)->elem);
}