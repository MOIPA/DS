#include <stdio.h>
#include <stdlib.h>
# define NAME "TZQ"

// 要用的方法 需要在调用者之前定义
int addMySelf(int a){
    // 这里的a和外部的a不是一个地址的a，两个地址只是都叫a，所以这里的改变不会影响外面的a
    // 那么为了传递同一个地址的a，吧a的地址传递过去就好了，去除a的地址的操作是：&a
    // 获取地址的数据的操作是：*b
    // 以上这个取地址，去地址数据的操作就是引用和指针
    a++;
    return 0;
}
int * plus(int a,int b){
    int c = a+b;
    int *addressOfC;
    addressOfC = &c;
    return addressOfC;
}
int minus(int *a,int *b){
    return *a - *b;
}
int multi(int *a, int b){
    return *a * b;
}
int * MySqrt(int *a){
    int *res = malloc(sizeof(int));
    *res = ((*a)*(*a));
    return res;
}
typedef struct ImaginaryNumber{
    int real;
    int imaging;
}MyImaginaryNumber;

typedef struct Student{
    char name[100];
    int age;
} Student;

typedef struct Computer{
    int price;
    char color[10];
}Computer;

int main() {
   // 调用一个方法  方法返回地址
   int * a; // a是地址
//   a = plus(1,2);
    int * b = malloc(sizeof(int));
    *b = 2;
    a = MySqrt(b);
   printf("a的地址是:%p, 地址对应的值是:%d\n",a,*a);

    // 一个虚数
    MyImaginaryNumber *changeAComplicatedWord = malloc(sizeof(MyImaginaryNumber));

    Student stu2;
    Student stu1;

    Computer *computerA=malloc(sizeof(Computer));
    computerA->price=2000;
    strcpy(computerA->color,"black");
    printf("价格：%d\n 颜色：%s\n 地址：%p\n",computerA->price,(*computerA).color,computerA);

    Computer computerB;
    computerB.price=3000;
    strcpy(computerB.color,"white");
    printf("价格：%d\n 颜色：%s\n 地址：%p\n",computerB.price,computerB.color,&computerB);

    Computer computerC;
    computerC.price=4000;
    strcpy(computerC.color,"grey");
    printf("价格：%d\n 颜色：%s\n 地址：%p\n",computerC.price,computerC.color,&computerC);

}
