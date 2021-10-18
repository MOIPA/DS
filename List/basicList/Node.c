#include <stdlib.h>
#include "stdio.h"

// 这个代码很拉跨，根本不存在可用，以后其他文件想用你定义好的Node咋办，看好了 原来的我给你注释了
// 定义在了main里面的stu怎么能被其他方法用到呢，一般都是定义在外面的，不然你定义了给谁用，要知道数据结构是用来用的，写在main里面就是纯粹的演示的

typedef struct Node{
    int value;
    // 结构体的成员可以包含其他结构体，也可以包含指向自己结构体类型的指针，而通常这种指针的应用是为了实现一些更高级的数据结构如链表和树等。
    // 一个节点应该有子节点 我们定义子节点
    struct Node *next; // 只能使用指针 且不能使用小名
} MyNode;
// 这个MyNode就是小名

// 对结构体的使用的示例
int test(void){


    // 示例1：直接使用系统给的地址不手动分配的  无所谓规范了
    struct Node *node2;
    node2->value = 12;
    printf("node2 的value是：%d\n", node2->value);

    // 示例2： 手动分配空间的 要引用stdlib
    struct Node *node3 = malloc(sizeof(struct Node));
    node3->value = 100;
    printf("node3 的value是：%d\n", node3->value);

    // 示例3：不用指针的
    struct Node node4;
    node4.value = 100;
    printf("node4 的value是：%d\n", node4.value);

    // 示例4；不定义名字的结构体 就是短暂拿来用 不打算给其他方法用的，这种不怎么用 了解就行，因为你炒的代码这样的 所以演示下
//    struct{
//        int value
//    } s1,s2;
//    // 这里呢 就直接给你吧变量定义好了 s1和s2，因为不给结构体名字所以肯定不能用名字去定义变量，那么你就直接提供变量。
//    s1.value = 1;s2.value = 2;
//    printf("定义好的结构体变量：%d", s1.value);

    // 示例5：你不觉得struct Node nodex; 每次都要打个struct tmd 烦死了
    // 这里提供 Node nodex的方式 让代码看起来更美观
    // 这个typedef就是取小名的意思 这里把int取了个小名 tzqInt，作用和int一样
    typedef int tzqInt;
    tzqInt tzqDeInt = 12;
    // 然后呢 我刚刚在我们的struct Node{... 前面呢 加了个typedef 最后这个结构体的小名也得写上，之后呢 你可以继续struct Node nodex 也可以Node nodex;
    MyNode nodex;
    nodex.value=111;

    // 现在演示为啥要那么费力定义一个node
    // 定义两个Node 一个叫。。。然后各自赋值
    MyNode startNode;
    MyNode secondNode;
    startNode.value=1;
    secondNode.value=2;
    startNode.next = &secondNode;  // 这里的& 是取地址符号哦 别忘了 Node里面定义的next是指针
    secondNode.next = NULL;

    // 那我们咋遍历呢 思路：这个节点的next是否为NULL，如果为NULL说明结束了 不然就取出来然后读下一个节点
    // currentNode 当前节点  指针访问只能用->
    MyNode *currentNode = &startNode;

    while (currentNode!=NULL){
        printf("node value:%d",currentNode->value);
        currentNode = currentNode->next;
    }


}


