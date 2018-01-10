#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2
#define MAXVEX 100 //一个图的最大顶点数
typedef int status;
typedef char VElemType; //顶点数据元素类型定义

typedef struct EdgeNode//边表结点
{
	int adjvex;//顶点对应下标
	int weight;//权值
	EdgeNode *next;
} EdgeNode,*Edg;

typedef struct VextexNode//顶点表结点
{
	VElemType data;//顶点信息
	EdgeNode *firstedge;//边表头指针
} VextexNode,AdjList[MAXVEX];

typedef struct GraphNode {
	AdjList adjlist;
	int num_v;//图的顶点数
	int num_e;//图的边数
}GraphNode,*Gra;

status CreateCraph(Gra &Gp);
status DestroyCraph(Gra &Gp);
int LocateVex(Gra Gp, VElemType u);
VElemType GetVex(Gra Gp, int i);
status PutVex(Gra &Gp, int v, char ch);
Edg FirstAdjVex(Gra Gp, VElemType u);
Edg NextAdjVex(Gra Gp, VElemType v, VElemType w);
status InsertVex(Gra &Gp, VElemType v);
status DeleteVex(Gra &Gp, VElemType v);
status InsertArc(Gra &Gp, VElemType v, VElemType w, int weight);
status DeleteArc(Gra &Gp, VElemType v, VElemType w);
void DFS(Gra gp, int v, bool* visited);
void DFSTraverse(Gra gp);
void BFSTraverse(Gra gp);
status SaveData(Gra gp, char *filename);
status LoadData(Gra &gp, char *filename);
