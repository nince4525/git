#pragma once

//定义键值类型
//因为数据很多，所以定义成unsigned char可以节省内存
// typedef unsigned short KeyType;
typedef int KeyType;

//设置数据集最大数限制：数据集中每一个数均小于LIMIT
#define LIMIT   32767

typedef struct {
    KeyType key;
} RecordType;

//定义万能指针类型
typedef void *POINTER;

//定义查找结果类型
//基于树的查找会返回指针结果，其他返回整型结果（一般是数组的下标）
typedef enum {INT_R, POINTER_R, BOTH_R} type_r; //2025/05/25，BZJ。添加了BOTH_R
typedef struct {
    type_r kind;
    struct { //2025/05/25，BZJ。从union修改为struct
        int i;
        POINTER p;
    };
} SearchResult;