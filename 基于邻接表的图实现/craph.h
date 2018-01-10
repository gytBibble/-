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
#define MAXVEX 100 //һ��ͼ����󶥵���
typedef int status;
typedef char VElemType; //��������Ԫ�����Ͷ���

typedef struct EdgeNode//�߱���
{
	int adjvex;//�����Ӧ�±�
	int weight;//Ȩֵ
	EdgeNode *next;
} EdgeNode,*Edg;

typedef struct VextexNode//�������
{
	VElemType data;//������Ϣ
	EdgeNode *firstedge;//�߱�ͷָ��
} VextexNode,AdjList[MAXVEX];

typedef struct GraphNode {
	AdjList adjlist;
	int num_v;//ͼ�Ķ�����
	int num_e;//ͼ�ı���
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
