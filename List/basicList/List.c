#include "Node.c"

/**
 * 1. 创建链表
 * 为了方便使用 写了很多辅助方法 比如判断一个元素是否在链表内，删除第N个元素
 */
MyNode *createList(int value) {
    MyNode *node = malloc(sizeof(MyNode));
    node->next = NULL;
    node->value = value;
    return node;
}

/**
 * 2. 给末尾添加元素
 */
void appendValue(int targetEle, MyNode *startNode) {
    // 找到startNode的最后一个节点 给这个节点添加
    MyNode *tmp = startNode;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    // tmp = 最后一个节点  需要手动分配空间，不然默认使用一个地址，会导致自己指向自己
    MyNode *targetNode = malloc(sizeof(MyNode));
    targetNode->value = targetEle;
    targetNode->next = NULL;
    tmp->next = targetNode;
}

/**
 * 读取所有节点
 * 需求驱动开发，你是没需求 不知道有什么需求 才蒙蔽
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
* 5. 看多少个节点总共
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
 * 3. 删除某个节点
 */
int delete(int index, MyNode *start) {
    int len = getLength(start);
    if (index > len) return -1;
    int counter = 1;
    int deletedValue;
    MyNode *tmp;
    tmp = start;
    // 如果删除第四个 那么目标停止节点就是3 即 到第三个节点停止循环
    int targetStopNode = index - 1;
    // 如果targetStopNode 是3， 当counter = 3 的时候 不满足 counter<targetStopNode，循环结束这时候counter是3，tmp指向第三个节点
    while (counter < targetStopNode) {
        counter++;
        tmp = tmp->next;
    }
    // 这时候tmp指向的是被删除节点的前一个 counter 是 index -1!
    deletedValue = tmp->next->value;
    // 这下面已经执行了删除了 这个节点都丢失了啊
    tmp->next = tmp->next->next;
    return deletedValue;
}

/**
* 4. 修改某个节点  来完成这个吧
*/
void changeNode(int posi, int targetValue, MyNode *firstNode) {
    MyNode *tmp;
    tmp = firstNode;
    int counter = 0;
    while (counter <= posi - 2) {
        counter++;
        tmp = tmp->next;
    }
    // tmp这时候是要被修改的节点了
    tmp->value = targetValue;
}

/**
* 6. 再第几个位置插入节点
*/
MyNode *insertNode(int posi, int targetElem, MyNode *firstNodeAddr) {
    // 1. 生成节点
    MyNode *targetNode = malloc(sizeof(MyNode));
    targetNode->value = targetElem;
    // 2. 如果posi是1
    if (posi == 1) {
        targetNode->next = firstNodeAddr;
        return targetNode;
    }
    // 3. 如果posi大于等于链表总长度 就变成了append
    if (posi > getLength(firstNodeAddr)) {
        appendValue(targetElem, firstNodeAddr);
        return firstNodeAddr;
    }
    // 4. 如果插入中间的情况
    // 4.1 首先找到posi位置的前一个节点  循环找到这个节点 p
    MyNode *tmp;
    tmp = firstNodeAddr;
    int counter = 1;
    while (counter < posi - 1) {
        counter++;
        tmp = tmp->next;
    }
    // 4.2 将新生成的节点指向 p的下一个节点
    targetNode->next = tmp->next;
    // 4.3 将p的下一个节点指向为我们新生成的节点  targetNode
    tmp->next = targetNode;
    // 4.4 返回原来的头节点
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
    MyNode *targetNode = findNode(posi, firstNode); // 先找到最后倒数第二个节点
    MyNode *newFirstNode = targetNode->next;  // 倒数第二个节点的下一个才是最后一个节点 保存好最后一个节点 逆置后会变为头节点 需要返回

    while (posi >= 1) {
        targetNode = findNode(posi, firstNode);
        targetNode->next->next = targetNode;
        posi--;
    }
    targetNode->next = NULL;
    return newFirstNode;
}
// 逆置算法  第二个算法 时间复杂度o(n)  思路：新建一个链表 每次插入到第一个
MyNode *reverseTwo(MyNode *firstNode) {
    MyNode * newFirstNode = createList(firstNode->value);
    MyNode *tmp = firstNode->next;
    while (tmp!=NULL){
        newFirstNode = insertNode(1, tmp->value, newFirstNode);
        tmp = tmp->next;
    }
    return newFirstNode;
}

// 栈的push操作 就是在最后加一个数据
void push(int value, MyNode *list) {
    appendValue(value, list);
}

// 栈的pop操作就是删除最后一个节点返回
int pop(MyNode *list) {
    delete(getLength(list), list);
}

/**
 * 链表使用  为什么要有链表，因为有些数据是动态增长的，在一开始谁也不知道应该多大，如果给太多，会浪费空间，小了又不够
 * @return
 */
int main(void) {
    // 1.获取一个链表
    MyNode *firstNode = createList(1);
//    firstNode->value=1;
    // 2.添加一个元素怎么操作
    MyNode tmp;
    tmp.value = 2;
    firstNode->next = &tmp;
    // 3.再添加一个元素
    MyNode tmp2;
    tmp2.value = 3;
    tmp2.next = NULL;
    firstNode->next->next = &tmp2;
    // 4.如果不知道里面几个元素 咋办
    appendValue(4, firstNode);
    appendValue(5, firstNode);
    // 4.1 删除元素
    delete(2, firstNode);
    // 4.2 全部元素个数
    printf("basicList size: %d\n", getLength(firstNode));
    // 4.3 修改第二个元素的内容
    changeNode(2, 10, firstNode);
    // 4.4 给链表插入节点
    firstNode = insertNode(1, 20, firstNode);
    firstNode = insertNode(2, -1, firstNode);
    firstNode = insertNode(1, -5, firstNode);
    firstNode = insertNode(1, -6, firstNode);

//    firstNode = *newFirstNode;
    printf("找到第6个节点:%d\n",findNode(6,firstNode)->value);
    // 5. 查看链表里面的所有元素
    printf("============原链表内容===========\n");
    readList(firstNode);
    printf("============逆置的结果===========\n");
    MyNode *newFirstNode = reverseTwo(firstNode);
    readList(newFirstNode);


//    // 模拟栈操作 定义栈
//    MyNode *stack = createList(-1);
//    // 1. push
//    push(1,stack);
//    push(2,stack);
//    push(3,stack);
//    push(4,stack);
//    // 2. pop
//    printf("pop了一个数：%d\n",pop(stack));
//    printf("pop了一个数：%d\n",pop(stack));
//    printf("pop了一个数：%d\n",pop(stack));
//    push(5,stack);
//    push(6,stack);
//    printf("pop了一个数：%d\n",pop(stack));
//    printf("pop了一个数：%d\n",pop(stack));

}


