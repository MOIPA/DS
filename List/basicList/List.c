#include "Node.c"

/**
 * 1. ��������
 * Ϊ�˷���ʹ�� д�˺ܶศ������ �����ж�һ��Ԫ���Ƿ��������ڣ�ɾ����N��Ԫ��
 */
MyNode *createList(int value) {
    MyNode *node = malloc(sizeof(MyNode));
    node->next = NULL;
    node->value = value;
    return node;
}

/**
 * 2. ��ĩβ���Ԫ��
 */
void appendValue(int targetEle, MyNode *startNode) {
    // �ҵ�startNode�����һ���ڵ� ������ڵ����
    MyNode *tmp = startNode;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    // tmp = ���һ���ڵ�  ��Ҫ�ֶ�����ռ䣬��ȻĬ��ʹ��һ����ַ���ᵼ���Լ�ָ���Լ�
    MyNode *targetNode = malloc(sizeof(MyNode));
    targetNode->value = targetEle;
    targetNode->next = NULL;
    tmp->next = targetNode;
}

/**
 * ��ȡ���нڵ�
 * ������������������û���� ��֪����ʲô���� ���ɱ�
 * @param node
 */
void readList(MyNode *firstNode) {
    MyNode *tmp = firstNode;
    while (tmp != NULL) {
        printf("%d\n", tmp->value);
        tmp = tmp->next;
    }
}

/**
* 5. �����ٸ��ڵ��ܹ�
*/
int getLength(MyNode *start) {
    int counter = 0;
    MyNode *tmp;
    tmp = start;
    while (tmp != NULL) {
        counter++;
        tmp = tmp->next;
    }
    return counter;
}

/**
 * 3. ɾ��ĳ���ڵ�
 */
int delete(int index, MyNode *start) {
    int len = getLength(start);
    if (index > len) return -1;
    int counter = 1;
    int deletedValue;
    MyNode *tmp;
    tmp = start;
    // ���ɾ�����ĸ� ��ôĿ��ֹͣ�ڵ����3 �� ���������ڵ�ֹͣѭ��
    int targetStopNode = index - 1;
    // ���targetStopNode ��3�� ��counter = 3 ��ʱ�� ������ counter<targetStopNode��ѭ��������ʱ��counter��3��tmpָ��������ڵ�
    while (counter < targetStopNode) {
        counter++;
        tmp = tmp->next;
    }
    // ��ʱ��tmpָ����Ǳ�ɾ���ڵ��ǰһ�� counter �� index -1!
    deletedValue = tmp->next->value;
    // �������Ѿ�ִ����ɾ���� ����ڵ㶼��ʧ�˰�
    tmp->next = tmp->next->next;
    return deletedValue;
}

/**
* 4. �޸�ĳ���ڵ�  ����������
*/
void changeNode(int posi, int targetValue, MyNode *firstNode) {
    MyNode *tmp;
    tmp = firstNode;
    int counter = 0;
    while (counter <= posi - 2) {
        counter++;
        tmp = tmp->next;
    }
    // tmp��ʱ����Ҫ���޸ĵĽڵ���
    tmp->value = targetValue;
}

/**
* 6. �ٵڼ���λ�ò���ڵ�
*/
MyNode *insertNode(int posi, int targetElem, MyNode *firstNodeAddr) {
    // 1. ���ɽڵ�
    MyNode *targetNode = malloc(sizeof(MyNode));
    targetNode->value = targetElem;
    // 2. ���posi��1
    if (posi == 1) {
        targetNode->next = firstNodeAddr;
        return targetNode;
    }
    // 3. ���posi���ڵ��������ܳ��� �ͱ����append
    if (posi > getLength(firstNodeAddr)) {
        appendValue(targetElem, firstNodeAddr);
        return firstNodeAddr;
    }
    // 4. ��������м�����
    // 4.1 �����ҵ�posiλ�õ�ǰһ���ڵ�  ѭ���ҵ�����ڵ� p
    MyNode *tmp;
    tmp = firstNodeAddr;
    int counter = 1;
    while (counter < posi - 1) {
        counter++;
        tmp = tmp->next;
    }
    // 4.2 �������ɵĽڵ�ָ�� p����һ���ڵ�
    targetNode->next = tmp->next;
    // 4.3 ��p����һ���ڵ�ָ��Ϊ���������ɵĽڵ�  targetNode
    tmp->next = targetNode;
    // 4.4 ����ԭ����ͷ�ڵ�
    return firstNodeAddr;
}

MyNode *findNode(int posi, MyNode *firstNode) {
    MyNode *tmp;
    tmp = firstNode;
    int counter = 1;
    while (counter <= posi - 1) {
        counter++;
        tmp = tmp->next;
    }
    return tmp;
}

MyNode *reverse(MyNode *firstNode) {
    int posi = getLength(firstNode)-1;
    MyNode *targetNode = findNode(posi, firstNode); // ���ҵ�������ڶ����ڵ�
    MyNode *newFirstNode = targetNode->next;  // �����ڶ����ڵ����һ���������һ���ڵ� ��������һ���ڵ� ���ú���Ϊͷ�ڵ� ��Ҫ����

    while (posi >= 1) {
        targetNode = findNode(posi, firstNode);
        targetNode->next->next = targetNode;
        posi--;
    }
    targetNode->next = NULL;
    return newFirstNode;
}
// �����㷨  �ڶ����㷨 ʱ�临�Ӷ�o(n)  ˼·���½�һ������ ÿ�β��뵽��һ��
MyNode *reverseTwo(MyNode *firstNode) {
    MyNode * newFirstNode = createList(firstNode->value);
    MyNode *tmp = firstNode->next;
    while (tmp!=NULL){
        newFirstNode = insertNode(1, tmp->value, newFirstNode);
        tmp = tmp->next;
    }
    return newFirstNode;
}

// ջ��push���� ����������һ������
void push(int value, MyNode *list) {
    appendValue(value, list);
}

// ջ��pop��������ɾ�����һ���ڵ㷵��
int pop(MyNode *list) {
    delete(getLength(list), list);
}

/**
 * ����ʹ��  ΪʲôҪ��������Ϊ��Щ�����Ƕ�̬�����ģ���һ��ʼ˭Ҳ��֪��Ӧ�ö�������̫�࣬���˷ѿռ䣬С���ֲ���
 * @return
 */
int main(void) {
    // 1.��ȡһ������
    MyNode *firstNode = createList(1);
//    firstNode->value=1;
    // 2.���һ��Ԫ����ô����
    MyNode tmp;
    tmp.value = 2;
    firstNode->next = &tmp;
    // 3.�����һ��Ԫ��
    MyNode tmp2;
    tmp2.value = 3;
    tmp2.next = NULL;
    firstNode->next->next = &tmp2;
    // 4.�����֪�����漸��Ԫ�� զ��
    appendValue(4, firstNode);
    appendValue(5, firstNode);
    // 4.1 ɾ��Ԫ��
    delete(2, firstNode);
    // 4.2 ȫ��Ԫ�ظ���
    printf("basicList size: %d\n", getLength(firstNode));
    // 4.3 �޸ĵڶ���Ԫ�ص�����
    changeNode(2, 10, firstNode);
    // 4.4 ���������ڵ�
    firstNode = insertNode(1, 20, firstNode);
    firstNode = insertNode(2, -1, firstNode);
    firstNode = insertNode(1, -5, firstNode);
    firstNode = insertNode(1, -6, firstNode);

//    firstNode = *newFirstNode;
    printf("�ҵ���6���ڵ�:%d\n",findNode(6,firstNode)->value);
    // 5. �鿴�������������Ԫ��
    printf("============ԭ��������===========\n");
    readList(firstNode);
    printf("============���õĽ��===========\n");
    MyNode *newFirstNode = reverseTwo(firstNode);
    readList(newFirstNode);


//    // ģ��ջ���� ����ջ
//    MyNode *stack = createList(-1);
//    // 1. push
//    push(1,stack);
//    push(2,stack);
//    push(3,stack);
//    push(4,stack);
//    // 2. pop
//    printf("pop��һ������%d\n",pop(stack));
//    printf("pop��һ������%d\n",pop(stack));
//    printf("pop��һ������%d\n",pop(stack));
//    push(5,stack);
//    push(6,stack);
//    printf("pop��һ������%d\n",pop(stack));
//    printf("pop��һ������%d\n",pop(stack));

}


