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
			printf("��ͼ����%d������,�ֱ�Ϊ��\n", gp->num_v);
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
		printf("    ��ѡ����Ĳ���[0~15]:");
		scanf("%d", &op);
		switch (op) {
		case 1://����ͼ������ͼ��
			if (CreateCraph(gp) == OK) printf("ͼ�����ɹ���\n");
			else printf("����ʧ�ܣ�\n");
			getchar(); getchar();
			break;
		case 2://����ͼ
			if (gp != NULL) {//ͼ����
				if (DestroyCraph(gp) == OK) printf("ͼ���ٳɹ���\n");
				else printf("����ʧ�ܣ�\n");
			}
			else printf("ͼ�����ڣ�\n");
			getchar(); getchar();
			break;
		case 3://���Ҷ���
			if (gp != NULL) {//ͼ����
				char ch;
				printf("������������ҵĶ����������Ϣ��\n");
				getchar();
				scanf("%c", &ch);
				if (LocateVex(gp, ch) == -1) printf("�����ھ�����ͬ�����Ķ��㣡\n");
				else printf("���ھ�����ͬ�����Ķ��㣬�Ҷ���Ϊv%d\n", LocateVex(gp, ch));
			}
			else printf("ͼ�����ڣ�\n");
			getchar(); getchar();
			break;
		case 4://��ö���ֵ
			if (gp != NULL) {//ͼ����
				int ordernum;
				printf("��������Ҫ���ֵ�Ķ������ţ�\n");
				scanf("%d", &ordernum);
				if (ordernum < 0 || ordernum >= gp->num_v) printf("ͼ��û�иö��㣡\n");
				else printf("�ö����ֵΪ%c", GetVex(gp, ordernum));
			}
			else printf("ͼ�����ڣ�\n");
			getchar(); getchar();
			break;
		case 5://���㸳ֵ
			if (gp != NULL) {//ͼ����
				int ordernum;
				char ch;
				printf("��������Ҫ���и�ֵ�Ķ������ţ�\n");
				scanf("%d", &ordernum);
				if (ordernum < 0 || ordernum >= gp->num_v) printf("ͼ��û�иö��㣡\n");
				else {
					printf("����������Ըö��㸳��ֵ��\n");
					getchar();
					scanf("%c", &ch);
					if (PutVex(gp,LocateVex(gp, GetVex(gp, ordernum)) , ch) == OK) printf("��ֵ�ɹ���\n");
					else printf("��ֵʧ�ܣ�\n");
				}
			}
			else printf("ͼ�����ڣ�\n");
			getchar(); getchar();
			break;
		case 6://��õ�һ�ڽӵ�
			if (gp != NULL) {//ͼ����
				char ch;
				printf("��������Ҫ����ڽӵ�Ķ����������Ϣ��\n");
				getchar();
				scanf("%c", &ch);
				if (LocateVex(gp, ch) == -1) printf("ͼ�в����ڸö��㣡\n");
				else {
					if (FirstAdjVex(gp, ch) == NULL) printf("�ö���û���ڽӶ��㣡\n");
					else {
						int i = FirstAdjVex(gp, ch)->adjvex;
						printf("�ö������ڽӶ��㣡�ҵ�һ�ڽӵ�Ϊ%c\n", gp->adjlist[i].data);
					}
				}
			}
			else printf("ͼ�����ڣ�\n");
			getchar(); getchar();
			break;
		case 7://�����һ�ڽӵ�
			if (gp != NULL) {//ͼ����
				char ch;
				char sh;
				printf("��������Ҫ�����һ�ڽӵ�Ķ���������Ϣ");
				printf("(v��ͼ��һ������,w��v���ڽӶ���)��\n");
				printf("�����붥��v��\n");
				getchar();
				scanf("%c", &ch);
				if (LocateVex(gp, ch) == -1) {
					printf("ͼ�в����ڶ���v��\n");
					break;
				}
				if (FirstAdjVex(gp, ch) == NULL) {
					printf("����vû���ڽӶ��㣡\n");
					break;
				}
				printf("�����붥��w��\n");
				getchar();
				scanf("%c", &sh);
				if (NextAdjVex(gp, ch, sh) == NULL) printf("wΪ���һ�����!\n");
				else {
					int i = NextAdjVex(gp, ch, sh)->adjvex;
					printf("����w����v���ڽӱ���һ�ڽӵ�ֵΪ��%c", gp->adjlist[i].data);
					}
			}
			else printf("ͼ�����ڣ�\n");
			getchar(); getchar();
			break;
		case 8://���붥��
			if (gp != NULL) {//ͼ����
				char ch;
				printf("�������������Ķ������Ϣ��\n");
				getchar();
				scanf("%c", &ch);
				if (InsertVex(gp,ch)==OK) printf("����ɹ���\n");
				else printf("����ʧ�ܣ�\n");
			}
			else printf("ͼ�����ڣ�\n");
			getchar(); getchar();
			break;
		case 9://ɾ������
			if (gp != NULL) {//ͼ����
				char ch;
				printf("����������ɾ���Ķ������Ϣ��\n");
				getchar();
				scanf("%c", &ch);
				if (LocateVex(gp,ch)==-1) printf("�ö��㲻���ڣ�\n");
				else {
					if (DeleteVex(gp, ch) == OK) printf("ɾ������ɹ���\n");
					else printf("ɾ��ʧ�ܣ�\n");
				}
			}
			else printf("ͼ�����ڣ�\n");
			getchar(); getchar();
			break;
		case 10://���뻡
			if (gp != NULL) {//ͼ����
				char ch;
				char sh;
				int weight;
				printf("��������(v,w)�������Ϣ������ͼ����\n");
				printf("�����붥��v��\n");
				getchar();
				scanf("%c", &ch);
				if (LocateVex(gp, ch) == -1) {
					printf("ͼ�в����ڶ���v��\n");
					break;
				}
				printf("�����붥��w��\n");
				getchar();
				scanf("%c", &sh);
				if (LocateVex(gp, sh) == -1) {
					printf("ͼ�в����ڶ���w��\n");
					break;
				}
				printf("�������(v,w)��Ȩֵ��\n");
				scanf("%d", &weight);
				if (InsertArc(gp, ch, sh, weight) == OK) printf("����ɹ���\n");
				else printf("����ʧ�ܣ�\n");
			}
			else printf("ͼ�����ڣ�\n");
			getchar(); getchar();
			break;
		case 11://ɾ����
			if (gp != NULL) {//ͼ����
				char ch;
				char sh;
				int weight;
				printf("����ɾ����(v,w)�������Ϣ������ͼ����\n");
				printf("�����붥��v��\n");
				getchar();
				scanf("%c", &ch);
				if (LocateVex(gp, ch) == -1) {
					printf("ͼ�в����ڶ���v��\n");
					break;
				}
				printf("�����붥��w��\n");
				getchar();
				scanf("%c", &sh);
				if (LocateVex(gp, sh) == -1) {
					printf("ͼ�в����ڶ���w��\n");
					break;
				}
				if (DeleteArc(gp, ch, sh) == OK) printf("ɾ���ɹ���\n");
				else printf("ɾ��ʧ�ܣ�\n");
			}
			else printf("ͼ�����ڣ�\n");
			getchar(); getchar();
			break;
		case 12://�����������
			if (gp != NULL) {//ͼ����
				printf("��������������Ϊ��\n");
				DFSTraverse(gp);
			}
			else printf("ͼ�����ڣ�\n");
			getchar(); getchar();
			break;
		case 13://�����������
			if (gp != NULL) {//ͼ����
				printf("��������������Ϊ��\n");
				BFSTraverse(gp);
			}
			else printf("ͼ�����ڣ�\n");
			getchar(); getchar();
			break;
		case 14://���ݱ���
			if (gp != NULL) {//ͼ����
				char filename[30];
				printf("�����ļ�����\n");
				scanf("%s", filename);
				if(SaveData(gp, filename)==OK) printf("���ݱ���ɹ���\n");
				else printf("���ݱ���ʧ�ܣ�\n");
			}
			else printf("ͼ�����ڣ�\n");
			getchar(); getchar();
			break;
		case 15://���ݼ���
			if (gp == NULL) {//ͼΪ��
				char filename[30];
				printf("�����ļ�����\n");
				scanf("%s", filename);
				if (LoadData(gp, filename) == OK) printf("���ݼ��سɹ���\n");
				else printf("���ݼ���ʧ�ܣ�\n");
			}
			else printf("ͼ��Ϊ�գ������ٵ�ǰͼ�ٽ��в�����\n");
			getchar(); getchar();
			break;
		}
	}
}
status CreateCraph(Gra &Gp)
{//����ͼ
	if (!(Gp = (Gra)malloc(sizeof(GraphNode)))) return OVERFLOW;
	int i,j,k,w;
	Edg p;
	printf("\n������ͼ�Ķ������� ");
	scanf("%d", &Gp->num_v);
	printf("������ͼ�ı����� ");
	scanf("%d", &Gp->num_e);
	printf("-------------------------------------------------\n");
	printf("\n���붥����Ϣ��\n");
	for (i = 0; i < Gp->num_v; i++)
	{
		printf("���붥�� v%d ����Ϣ��", i);
		getchar();
		scanf("%c",&Gp->adjlist[i].data);
		Gp->adjlist[i].firstedge = NULL;//���߱���Ϊ��
	}
	for (k = 0; k < Gp->num_e; k++)//�����߱�
	{
		printf("\n�����(vi,vj)�Ķ������i��j:");
		scanf("%d %d", &i, &j);
		printf("������ñߵ�Ȩֵ:");
		scanf("%d", &w);
		/*��������ͼ���ڽӱ�һ��ѭ�����������߱���*/
		if(!(p = (Edg)malloc(sizeof(EdgeNode)))) return OVERFLOW;		
		p->adjvex = j;
		p->weight = w;
		p->next = NULL;
		/*����������β*/
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
	{//�������ÿ���߱�Ľ��
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
			return i;//�����Ƿ��ض������
	}
	return -1;//������ʱ����-1
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
{//v��ͼGp��һ������,w��v���ڽӶ���
	Edg p = FirstAdjVex(Gp, v);//pΪv�߱��һ�ڽӵ�
	while (p&&p->adjvex != LocateVex(Gp, w))
		p = p->next;//�ҵ�w
	if (p->next == NULL)//wΪ���һ�����
		return NULL;
	else return p->next;
}
status InsertVex(Gra &Gp, VElemType v)
{
	Gp->adjlist[Gp->num_v].data = v;
	Gp->adjlist[Gp->num_v].firstedge = NULL;
	Gp->num_v = Gp->num_v + 1;
	printf("�²���Ķ������Ϊv%d", Gp->num_v-1);
	return OK;
}
status DeleteVex(Gra &Gp, VElemType v)
{
	int i, j;
	Edg p=NULL, q=NULL, r=NULL;
	i = LocateVex(Gp, v);//��Ҫɾ���Ķ������
	if (i<0 || i>Gp->num_v-1) return FALSE;
	p = Gp->adjlist[i].firstedge;
	for (j = i + 1; j < Gp->num_v; j++)//����v����Ķ���ǰ��
	{
		Gp->adjlist[j - 1] = Gp->adjlist[j];
		Gp->adjlist[j - 1].firstedge = Gp->adjlist[j].firstedge;
	}
	Gp->num_v--;//��������һ
	while (p != NULL)
	{//ɾ���ڽӱ�����vΪ��ͷ���ı߱�
		q = p->next;
		free(p);
		p = q;
		Gp->num_e = Gp->num_e - 1;//������һ
	}
	for (j = 0; j < Gp->num_v; j++)
	{//ɾ���ڽӱ���v��Ϊ�ı߱���
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
	if (p&&p->adjvex == j)//�ҵ���(v,w)
	{
		if (p == Gp->adjlist[i].firstedge)//w�ǵ�һ�����
		{
			Gp->adjlist[i].firstedge = p->next;
			free(p);
		}
		else {
			q->next = p->next;
			free(p);
		}
	}
	/*����ͼ������һ��*/
	p = Gp->adjlist[j].firstedge;
	while (p&&p->adjvex != i)
	{
		q = p;
		p = p->next;
	}
	if (p&&p->adjvex == i)//�ҵ���(v,w)
	{
		if (p == Gp->adjlist[j].firstedge)//w�ǵ�һ�����
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
	int Q[MAXVEX];//��������
	Edg p;
	for (v = 0; v < gp->num_v; v++) visited[v] = FALSE;
	for (v = 0; v < gp->num_v; v++)
	{
		if (!visited[v])
		{
			visited[v] = TRUE;
			printf(" %c", gp->adjlist[v].data);
			Q[rear++] = v;//�����
		}
		while (head != rear)
		{
			w = Q[head++];//������
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
		gp->adjlist[i].firstedge = NULL;//���߱���Ϊ��
	}
	for (int k = 0; k < 2*gp->num_e; k++)
	{
		fscanf(fp,"%d%d%d", &i, &j, &w);
		if (!(p = (Edg)malloc(sizeof(EdgeNode)))) return OVERFLOW;
		p->adjvex = j;
		p->weight = w;
		p->next = NULL;
		/*����������β*/
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
