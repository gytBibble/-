#include"craph.h"
int main(void)
{
	int op = 1;
	Gra gp=NULL;
	while (op)
	{
		system("cls");
		printf("\n\n");
		printf("      Menu for Linear Table On Cragh Structure \n");
		printf("-------------------------------------------------\n");
		printf("    	  1. CreateCraph       8. InsertVex\n"); 
		printf("    	  2. DestroyCraph      9. DeleteVex\n");
		printf("    	  3. LocateVex        10. InsertArc\n"); 
		printf("    	  4. GetVex           11. DeleteArc\n");
		printf("    	  5. PutVex           12. DFSTraverse\n");
		printf("    	  6. FirstAdjVex      13. BFSTraverse\n");
		printf("    	  7. NextAdjVex       14. SaveData\n");
		printf("    	  0. Exit             15. LoadData\n");
		printf("-------------------------------------------------\n");
		if (gp != NULL)
		{
			int i = 0;
			printf("该图已有%d个顶点,分别为：\n", gp->num_v);
			for (i = 0; i < gp->num_v; i++)
			{
				printf("\tv%d:%c", i, gp->adjlist[i].data);
				for (Edg r = gp->adjlist[i].firstedge; r != NULL; r = r->next)
				{
					printf("-->%d|%d", r->adjvex, r->weight);
				}
				printf("\n");
			}
			printf("-------------------------------------------------\n");
		}
		printf("    请选择你的操作[0~15]:");
		scanf("%d", &op);
		switch (op) {
		case 1://创建图（无向图）
			if (CreateCraph(gp) == OK) printf("图创建成功！\n");
			else printf("创建失败！\n");
			getchar(); getchar();
			break;
		case 2://销毁图
			if (gp != NULL) {//图存在
				if (DestroyCraph(gp) == OK) printf("图销毁成功！\n");
				else printf("销毁失败！\n");
			}
			else printf("图不存在！\n");
			getchar(); getchar();
			break;
		case 3://查找顶点
			if (gp != NULL) {//图存在
				char ch;
				printf("请输入你想查找的顶点的特征信息：\n");
				getchar();
				scanf("%c", &ch);
				if (LocateVex(gp, ch) == -1) printf("不存在具有相同特征的顶点！\n");
				else printf("存在具有相同特征的顶点，且顶点为v%d\n", LocateVex(gp, ch));
			}
			else printf("图不存在！\n");
			getchar(); getchar();
			break;
		case 4://获得顶点值
			if (gp != NULL) {//图存在
				int ordernum;
				printf("请输入你要获得值的顶点的序号：\n");
				scanf("%d", &ordernum);
				if (ordernum < 0 || ordernum >= gp->num_v) printf("图中没有该顶点！\n");
				else printf("该顶点的值为%c", GetVex(gp, ordernum));
			}
			else printf("图不存在！\n");
			getchar(); getchar();
			break;
		case 5://顶点赋值
			if (gp != NULL) {//图存在
				int ordernum;
				char ch;
				printf("请输入你要进行赋值的顶点的序号：\n");
				scanf("%d", &ordernum);
				if (ordernum < 0 || ordernum >= gp->num_v) printf("图中没有该顶点！\n");
				else {
					printf("请输入你想对该顶点赋的值：\n");
					getchar();
					scanf("%c", &ch);
					if (PutVex(gp,LocateVex(gp, GetVex(gp, ordernum)) , ch) == OK) printf("赋值成功！\n");
					else printf("赋值失败！\n");
				}
			}
			else printf("图不存在！\n");
			getchar(); getchar();
			break;
		case 6://获得第一邻接点
			if (gp != NULL) {//图存在
				char ch;
				printf("请输入需要获得邻接点的顶点的特征信息：\n");
				getchar();
				scanf("%c", &ch);
				if (LocateVex(gp, ch) == -1) printf("图中不存在该顶点！\n");
				else {
					if (FirstAdjVex(gp, ch) == NULL) printf("该顶点没有邻接顶点！\n");
					else {
						int i = FirstAdjVex(gp, ch)->adjvex;
						printf("该顶点有邻接顶点！且第一邻接点为%c\n", gp->adjlist[i].data);
					}
				}
			}
			else printf("图不存在！\n");
			getchar(); getchar();
			break;
		case 7://获得下一邻接点
			if (gp != NULL) {//图存在
				char ch;
				char sh;
				printf("请输入需要获得下一邻接点的顶点的相关信息");
				printf("(v是图的一个顶点,w是v的邻接顶点)：\n");
				printf("请输入顶点v：\n");
				getchar();
				scanf("%c", &ch);
				if (LocateVex(gp, ch) == -1) {
					printf("图中不存在顶点v！\n");
					break;
				}
				if (FirstAdjVex(gp, ch) == NULL) {
					printf("顶点v没有邻接顶点！\n");
					break;
				}
				printf("请输入顶点w：\n");
				getchar();
				scanf("%c", &sh);
				if (NextAdjVex(gp, ch, sh) == NULL) printf("w为最后一个结点!\n");
				else {
					int i = NextAdjVex(gp, ch, sh)->adjvex;
					printf("顶点w的在v中邻接表下一邻接点值为：%c", gp->adjlist[i].data);
					}
			}
			else printf("图不存在！\n");
			getchar(); getchar();
			break;
		case 8://插入顶点
			if (gp != NULL) {//图存在
				char ch;
				printf("请输入你想插入的顶点的信息：\n");
				getchar();
				scanf("%c", &ch);
				if (InsertVex(gp,ch)==OK) printf("插入成功！\n");
				else printf("插入失败！\n");
			}
			else printf("图不存在！\n");
			getchar(); getchar();
			break;
		case 9://删除顶点
			if (gp != NULL) {//图存在
				char ch;
				printf("请输入你想删除的顶点的信息：\n");
				getchar();
				scanf("%c", &ch);
				if (LocateVex(gp,ch)==-1) printf("该顶点不存在！\n");
				else {
					if (DeleteVex(gp, ch) == OK) printf("删除顶点成功！\n");
					else printf("删除失败！\n");
				}
			}
			else printf("图不存在！\n");
			getchar(); getchar();
			break;
		case 10://插入弧
			if (gp != NULL) {//图存在
				char ch;
				char sh;
				int weight;
				printf("输入插入边(v,w)的相关信息（无向图）！\n");
				printf("请输入顶点v：\n");
				getchar();
				scanf("%c", &ch);
				if (LocateVex(gp, ch) == -1) {
					printf("图中不存在顶点v！\n");
					break;
				}
				printf("请输入顶点w：\n");
				getchar();
				scanf("%c", &sh);
				if (LocateVex(gp, sh) == -1) {
					printf("图中不存在顶点w！\n");
					break;
				}
				printf("请输入边(v,w)的权值：\n");
				scanf("%d", &weight);
				if (InsertArc(gp, ch, sh, weight) == OK) printf("插入成功！\n");
				else printf("插入失败！\n");
			}
			else printf("图不存在！\n");
			getchar(); getchar();
			break;
		case 11://删除弧
			if (gp != NULL) {//图存在
				char ch;
				char sh;
				int weight;
				printf("输入删除边(v,w)的相关信息（无向图）！\n");
				printf("请输入顶点v：\n");
				getchar();
				scanf("%c", &ch);
				if (LocateVex(gp, ch) == -1) {
					printf("图中不存在顶点v！\n");
					break;
				}
				printf("请输入顶点w：\n");
				getchar();
				scanf("%c", &sh);
				if (LocateVex(gp, sh) == -1) {
					printf("图中不存在顶点w！\n");
					break;
				}
				if (DeleteArc(gp, ch, sh) == OK) printf("删除成功！\n");
				else printf("删除失败！\n");
			}
			else printf("图不存在！\n");
			getchar(); getchar();
			break;
		case 12://深度优先搜索
			if (gp != NULL) {//图存在
				printf("深度优先搜索结果为：\n");
				DFSTraverse(gp);
			}
			else printf("图不存在！\n");
			getchar(); getchar();
			break;
		case 13://广度优先搜索
			if (gp != NULL) {//图存在
				printf("广度优先搜索结果为：\n");
				BFSTraverse(gp);
			}
			else printf("图不存在！\n");
			getchar(); getchar();
			break;
		case 14://数据保存
			if (gp != NULL) {//图存在
				char filename[30];
				printf("输入文件名：\n");
				scanf("%s", filename);
				if(SaveData(gp, filename)==OK) printf("数据保存成功！\n");
				else printf("数据保存失败！\n");
			}
			else printf("图不存在！\n");
			getchar(); getchar();
			break;
		case 15://数据加载
			if (gp == NULL) {//图为空
				char filename[30];
				printf("输入文件名：\n");
				scanf("%s", filename);
				if (LoadData(gp, filename) == OK) printf("数据加载成功！\n");
				else printf("数据加载失败！\n");
			}
			else printf("图不为空，请销毁当前图再进行操作！\n");
			getchar(); getchar();
			break;
		}
	}
}
status CreateCraph(Gra &Gp)
{//创建图
	if (!(Gp = (Gra)malloc(sizeof(GraphNode)))) return OVERFLOW;
	int i,j,k,w;
	Edg p;
	printf("\n请输入图的顶点数： ");
	scanf("%d", &Gp->num_v);
	printf("请输入图的边数： ");
	scanf("%d", &Gp->num_e);
	printf("-------------------------------------------------\n");
	printf("\n输入顶点信息：\n");
	for (i = 0; i < Gp->num_v; i++)
	{
		printf("输入顶点 v%d 的信息：", i);
		getchar();
		scanf("%c",&Gp->adjlist[i].data);
		Gp->adjlist[i].firstedge = NULL;//将边表置为空
	}
	for (k = 0; k < Gp->num_e; k++)//建立边表
	{
		printf("\n输入边(vi,vj)的顶点序号i和j:");
		scanf("%d %d", &i, &j);
		printf("请输入该边的权值:");
		scanf("%d", &w);
		/*创建无向图的邻接表，一个循环创建两个边表结点*/
		if(!(p = (Edg)malloc(sizeof(EdgeNode)))) return OVERFLOW;		
		p->adjvex = j;
		p->weight = w;
		p->next = NULL;
		/*将结点插入链尾*/
		if (Gp->adjlist[i].firstedge == NULL) Gp->adjlist[i].firstedge = p;
		else {
			Edg r = Gp->adjlist[i].firstedge;
			while (r->next != NULL)
			{
				r = r->next;
			}
			r ->next = p;
		}
		if (!(p = (Edg)malloc(sizeof(EdgeNode)))) return OVERFLOW;
		p->adjvex = i;
		p->weight = w;
		p->next = NULL;
		if (Gp->adjlist[j].firstedge == NULL) Gp->adjlist[j].firstedge = p;
		else {
			Edg r = Gp->adjlist[j].firstedge;
			while (r->next != NULL)
			{
				r = r->next;
			}
			r->next = p;
		}
	}
	return OK;
}
status DestroyCraph(Gra &Gp)
{
	int i;
	EdgeNode *p, *q;
	VextexNode v;
	for (i = 0; i < Gp->num_v; i++)
	{//逐个销毁每个边表的结点
		p = Gp->adjlist[i].firstedge;
		while (p)
		{
			q = p->next;
			free(p);
			p = q;
		}
	}
	free(Gp);
	Gp = NULL;
	return OK;
}
int LocateVex(Gra Gp, VElemType u)
{
	int i;
	for (i = 0; i < Gp->num_v; i++)
	{
		if (u == Gp->adjlist[i].data)
			return i;//存在是返回顶点序号
	}
	return -1;//不存在时返回-1
}
VElemType GetVex(Gra Gp, int i)
{
	return Gp->adjlist[i].data;
}
status PutVex(Gra &Gp, int v, char ch)
{
	if (v > -1) {
		Gp->adjlist[v].data = ch;
		return OK;
	}
	return ERROR;
}
Edg FirstAdjVex(Gra Gp, VElemType u)
{
	int i;
	Edg p;
	i = LocateVex(Gp, u);
	p = Gp->adjlist[i].firstedge;
	if (p != NULL) {
		 return p;
	}
	else return NULL;
}
Edg NextAdjVex(Gra Gp, VElemType v, VElemType w)
{//v是图Gp的一个顶点,w是v的邻接顶点
	Edg p = FirstAdjVex(Gp, v);//p为v边表第一邻接点
	while (p&&p->adjvex != LocateVex(Gp, w))
		p = p->next;//找到w
	if (p->next == NULL)//w为最后一个结点
		return NULL;
	else return p->next;
}
status InsertVex(Gra &Gp, VElemType v)
{
	Gp->adjlist[Gp->num_v].data = v;
	Gp->adjlist[Gp->num_v].firstedge = NULL;
	Gp->num_v = Gp->num_v + 1;
	printf("新插入的顶点序号为v%d", Gp->num_v-1);
	return OK;
}
status DeleteVex(Gra &Gp, VElemType v)
{
	int i, j;
	Edg p=NULL, q=NULL, r=NULL;
	i = LocateVex(Gp, v);//需要删除的顶点序号
	if (i<0 || i>Gp->num_v-1) return FALSE;
	p = Gp->adjlist[i].firstedge;
	for (j = i + 1; j < Gp->num_v; j++)//顶点v后面的顶点前移
	{
		Gp->adjlist[j - 1] = Gp->adjlist[j];
		Gp->adjlist[j - 1].firstedge = Gp->adjlist[j].firstedge;
	}
	Gp->num_v--;//顶点数减一
	while (p != NULL)
	{//删除邻接表上以v为表头结点的边表
		q = p->next;
		free(p);
		p = q;
		Gp->num_e = Gp->num_e - 1;//边数减一
	}
	for (j = 0; j < Gp->num_v; j++)
	{//删除邻接表上v作为的边表结点
		p = Gp->adjlist[j].firstedge;
		while (p)
		{
			if (p->adjvex == i)
			{
				if (p == Gp->adjlist[j].firstedge)
				{
					Gp->adjlist[j].firstedge = p->next;
				}
				else {
					r->next = p->next;
				}
				q = p;
				p = p->next;
				free(q);
			}
			else{
				if (p->adjvex > i)
					p->adjvex--;
				r = p;
				p = p->next;
				}
		}
	}
	return OK;
}
status InsertArc(Gra &Gp, VElemType v, VElemType w,int weight)
{
	int i, j;
	Edg p;
	i = LocateVex(Gp, v);
	j = LocateVex(Gp, w);
	if (!(p = (Edg)malloc(sizeof(EdgeNode)))) return OVERFLOW;
	p->weight = weight;
	p->adjvex = j;
	p->next = Gp->adjlist[i].firstedge;
	Gp->adjlist[i].firstedge = p;
	if (!(p = (Edg)malloc(sizeof(EdgeNode)))) return OVERFLOW;
	p->weight = weight;
	p->adjvex = i;
	p->next = Gp->adjlist[j].firstedge;
	Gp->adjlist[j].firstedge = p;
	return OK;
}
status DeleteArc(Gra &Gp, VElemType v, VElemType w)
{
	int i, j;
	Edg p,q=NULL;
	i = LocateVex(Gp, v);
	j = LocateVex(Gp, w);
	p = Gp->adjlist[i].firstedge;
	while (p&&p->adjvex != j)
	{
		q = p;
		p = p->next;
	}
	if (p&&p->adjvex == j)//找到边(v,w)
	{
		if (p == Gp->adjlist[i].firstedge)//w是第一个结点
		{
			Gp->adjlist[i].firstedge = p->next;
			free(p);
		}
		else {
			q->next = p->next;
			free(p);
		}
	}
	/*无向图，再来一次*/
	p = Gp->adjlist[j].firstedge;
	while (p&&p->adjvex != i)
	{
		q = p;
		p = p->next;
	}
	if (p&&p->adjvex == i)//找到边(v,w)
	{
		if (p == Gp->adjlist[j].firstedge)//w是第一个结点
		{
			Gp->adjlist[j].firstedge = p->next;
			free(p);
		}
		else {
			q->next = p->next;
			free(p);
		}
	}
	return TRUE;
}
void DFSTraverse(Gra gp)
{
	int i;
	bool visited[MAXVEX];
	for (i = 0; i < gp->num_v; i++) visited[i] = FALSE;
	for (i = 0; i < gp->num_v; i++)
	{
		if (!visited[i])
			DFS(gp, i, visited);
	}
}
void DFS(Gra gp, int v, bool* visited)
{
	int w;
	Edg p;
	visited[v] = TRUE;
	printf(" %c", gp->adjlist[v].data);
	p = gp->adjlist[v].firstedge;
	while (p != NULL)
	{
		if (!visited[p->adjvex])
			DFS(gp, p->adjvex, visited);
		p = p->next;
	}
}
void BFSTraverse(Gra gp)
{
	bool visited[MAXVEX];
	int v,w,i;
	int head = 0;
	int rear = 0;
	int Q[MAXVEX];//辅助队列
	Edg p;
	for (v = 0; v < gp->num_v; v++) visited[v] = FALSE;
	for (v = 0; v < gp->num_v; v++)
	{
		if (!visited[v])
		{
			visited[v] = TRUE;
			printf(" %c", gp->adjlist[v].data);
			Q[rear++] = v;//入队列
		}
		while (head != rear)
		{
			w = Q[head++];//出队列
			p = gp->adjlist[w].firstedge;
			while (p != NULL)
			{
				i = p->adjvex;
				if (!visited[i])
				{
					visited[i] = TRUE;
					printf(" %c", gp->adjlist[i].data);
					Q[rear++] = i;
				}
				p = p->next;
			}
		}//while
	}//end of for
}
status SaveData(Gra gp,char *filename)
{
	FILE *fp;
	Edg p;
	if ((fp = fopen(filename, "w")) == NULL)
	{
		printf("File open error!\n ");
		return ERROR;
	}
	fprintf(fp, "\t%d", gp->num_v);
	fprintf(fp, "\t%d", gp->num_e);
	for (int i = 0; i < gp->num_v; i++)
		fprintf(fp, "%c", gp->adjlist[i].data);
	for (int i = 0; i < gp->num_v; i++)
	{
		p = gp->adjlist[i].firstedge;
		while (p != NULL)
		{
			fprintf(fp, "\t%d\t%d\t%d", i, p->adjvex,p->weight);
			p = p->next;
		}
	}
	fclose(fp);
	return OK;
}
status LoadData(Gra &gp, char *filename)
{
	FILE *fp;
	Edg p;
	int  i, j, w;
	if (!(gp = (Gra)malloc(sizeof(GraphNode)))) return OVERFLOW;
	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("File open error!\n ");
		return ERROR;
	}
	fscanf(fp, "%d", &gp->num_v);
	fscanf(fp, "%d", &gp->num_e);
	for ( i = 0; i < gp->num_v; i++)
	{
		fscanf(fp, "%c", &gp->adjlist[i].data);
		gp->adjlist[i].firstedge = NULL;//将边表置为空
	}
	for (int k = 0; k < 2*gp->num_e; k++)
	{
		fscanf(fp,"%d%d%d", &i, &j, &w);
		if (!(p = (Edg)malloc(sizeof(EdgeNode)))) return OVERFLOW;
		p->adjvex = j;
		p->weight = w;
		p->next = NULL;
		/*将结点插入链尾*/
		if (gp->adjlist[i].firstedge == NULL) gp->adjlist[i].firstedge = p;
		else {
			Edg r = gp->adjlist[i].firstedge;
			while (r->next != NULL)
			{
				r = r->next;
			}
			r->next = p;
		}
	}
	fclose(fp);
	return OK;
}
