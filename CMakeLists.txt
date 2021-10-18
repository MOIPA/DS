cmake_minimum_required(VERSION 3.17)
project(DS C)

set(CMAKE_C_STANDARD 99)

#add_executable(cbasic cbasic/main.c)
#add_executable(pointer cbasic/pointerPractice.c)
#add_executable(DS Basic.c cmake-build-debug/Basi.c)
#add_executable(tr BasicTwo.c)
#add_executable(practice practice/List.c)
#add_executable(practice2 practice2/List.c)
#
# 主题 空格 目标执行的文件位置 比如 主题：TzqSort 位置 sort/Sort.c
#add_executable(TzqSort sort/Sort.c) # 排序

add_executable(Node List/basicList/Node.c) # 链表头节点的多种使用
add_executable(ListWithOutHead List/basicList/List.c) # 无头节点链表
add_executable(HeadList List/basicListWithHead/ListWithHead.c) # 带头节点链表
add_executable(DoubleDirectionListWithHead List/DoubleDirectionListWithHead/DoubleDirectionListWithHead.c) # 带头节点的双向链表

