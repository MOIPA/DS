#include <stdio.h>
#include <stdlib.h>
# define NAME "TZQ"

// Ҫ�õķ��� ��Ҫ�ڵ�����֮ǰ����
int addMySelf(int a){
    // �����a���ⲿ��a����һ����ַ��a��������ַֻ�Ƕ���a����������ĸı䲻��Ӱ�������a
    // ��ôΪ�˴���ͬһ����ַ��a����a�ĵ�ַ���ݹ�ȥ�ͺ��ˣ�ȥ��a�ĵ�ַ�Ĳ����ǣ�&a
    // ��ȡ��ַ�����ݵĲ����ǣ�*b
    // �������ȡ��ַ��ȥ��ַ���ݵĲ����������ú�ָ��
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
   // ����һ������  �������ص�ַ
   int * a; // a�ǵ�ַ
//   a = plus(1,2);
    int * b = malloc(sizeof(int));
    *b = 2;
    a = MySqrt(b);
   printf("a�ĵ�ַ��:%p, ��ַ��Ӧ��ֵ��:%d\n",a,*a);

    // һ������
    MyImaginaryNumber *changeAComplicatedWord = malloc(sizeof(MyImaginaryNumber));

    Student stu2;
    Student stu1;

    Computer *computerA=malloc(sizeof(Computer));
    computerA->price=2000;
    strcpy(computerA->color,"black");
    printf("�۸�%d\n ��ɫ��%s\n ��ַ��%p\n",computerA->price,(*computerA).color,computerA);

    Computer computerB;
    computerB.price=3000;
    strcpy(computerB.color,"white");
    printf("�۸�%d\n ��ɫ��%s\n ��ַ��%p\n",computerB.price,computerB.color,&computerB);

    Computer computerC;
    computerC.price=4000;
    strcpy(computerC.color,"grey");
    printf("�۸�%d\n ��ɫ��%s\n ��ַ��%p\n",computerC.price,computerC.color,&computerC);

}
