#pragma once

//这个头文件里定义的类型适用于所有类型的图

//定义无穷大值，即∞
#define INFINITY 65536
#define INFINITY_S "∞" 

//定义最大顶点数量
#define MAX_VERTEX_NUM 20

//定义图的种类
//图的种类：DG表示有向图, DN表示有向网, UDG表示无向图, UDN表示无向网
typedef enum {
    UNDEFINED = 0,
    DG,
    DN,
    UDG,
    UDN
} GraphKind;

//顶点数据，一般是字母标签
typedef char VertexData; 

//对于无权图，用1或0表示是否相邻；对带权图，则为权值
typedef int AdjType;

//定义与弧相关的信息。目前仅有权重
typedef struct OtherInfo {
    int weight;
} OtherInfo;

//定义弧类型
typedef struct {
    int adj; //顶点位序
    struct ArcNode *arc; //顶点为弧尾的弧
} Arc;