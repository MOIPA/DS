#include <stdlib.h>
#include "stdio.h"

// �����������磬���������ڿ��ã��Ժ������ļ������㶨��õ�Nodeզ�죬������ ԭ�����Ҹ���ע����
// ��������main�����stu��ô�ܱ����������õ��أ�һ�㶼�Ƕ���������ģ���Ȼ�㶨���˸�˭�ã�Ҫ֪�����ݽṹ�������õģ�д��main������Ǵ������ʾ��

typedef struct Node{
    int value;
    // �ṹ��ĳ�Ա���԰��������ṹ�壬Ҳ���԰���ָ���Լ��ṹ�����͵�ָ�룬��ͨ������ָ���Ӧ����Ϊ��ʵ��һЩ���߼������ݽṹ����������ȡ�
    // һ���ڵ�Ӧ�����ӽڵ� ���Ƕ����ӽڵ�
    struct Node *next; // ֻ��ʹ��ָ�� �Ҳ���ʹ��С��
} MyNode;
// ���MyNode����С��

// �Խṹ���ʹ�õ�ʾ��
int test(void){


    // ʾ��1��ֱ��ʹ��ϵͳ���ĵ�ַ���ֶ������  ����ν�淶��
    struct Node *node2;
    node2->value = 12;
    printf("node2 ��value�ǣ�%d\n", node2->value);

    // ʾ��2�� �ֶ�����ռ�� Ҫ����stdlib
    struct Node *node3 = malloc(sizeof(struct Node));
    node3->value = 100;
    printf("node3 ��value�ǣ�%d\n", node3->value);

    // ʾ��3������ָ���
    struct Node node4;
    node4.value = 100;
    printf("node4 ��value�ǣ�%d\n", node4.value);

    // ʾ��4�����������ֵĽṹ�� ���Ƕ��������� ����������������õģ����ֲ���ô�� �˽���У���Ϊ�㳴�Ĵ��������� ������ʾ��
//    struct{
//        int value
//    } s1,s2;
//    // ������ ��ֱ�Ӹ���ɱ���������� s1��s2����Ϊ�����ṹ���������Կ϶�����������ȥ�����������ô���ֱ���ṩ������
//    s1.value = 1;s2.value = 2;
//    printf("����õĽṹ�������%d", s1.value);

    // ʾ��5���㲻����struct Node nodex; ÿ�ζ�Ҫ���struct tmd ������
    // �����ṩ Node nodex�ķ�ʽ �ô��뿴����������
    // ���typedef����ȡС������˼ �����intȡ�˸�С�� tzqInt�����ú�intһ��
    typedef int tzqInt;
    tzqInt tzqDeInt = 12;
    // Ȼ���� �Ҹո������ǵ�struct Node{... ǰ���� ���˸�typedef �������ṹ���С��Ҳ��д�ϣ�֮���� ����Լ���struct Node nodex Ҳ����Node nodex;
    MyNode nodex;
    nodex.value=111;

    // ������ʾΪɶҪ��ô��������һ��node
    // ��������Node һ���С�����Ȼ����Ը�ֵ
    MyNode startNode;
    MyNode secondNode;
    startNode.value=1;
    secondNode.value=2;
    startNode.next = &secondNode;  // �����& ��ȡ��ַ����Ŷ ������ Node���涨���next��ָ��
    secondNode.next = NULL;

    // ������զ������ ˼·������ڵ��next�Ƿ�ΪNULL�����ΪNULL˵�������� ��Ȼ��ȡ����Ȼ�����һ���ڵ�
    // currentNode ��ǰ�ڵ�  ָ�����ֻ����->
    MyNode *currentNode = &startNode;

    while (currentNode!=NULL){
        printf("node value:%d",currentNode->value);
        currentNode = currentNode->next;
    }


}


