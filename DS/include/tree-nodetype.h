#pragma once

typedef struct { 
    char tag;   //节点的字母标签域。
    char s[16]; //节点的字符串值。这个值从对照表中来
    int i;      //节点的整型值，由s转换而来。一般情况下，s和i只用其一
    int bf;     //为今后的应用保留的
} DataType;