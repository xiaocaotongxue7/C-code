#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
void slheadinit(struct slist *head);
void slinit(struct slist *head);
struct llist *llinit();
void slprintf(struct slist *head);
void slInsertbefore(struct slist *head);
void slErase(struct slist *head);
void slFind(struct slist *head);
void slsum(struct slist *head);
void menu();
void slmenu();
void re();
void end();
void llmenu();
struct llist *Breakup(struct slist *head);
void llprintf(struct llist *head);
void llprintf2(struct llist *head,int n);
/*
��6����β�巨����һ���洢ѧ����Ϣ�Ĵ�ͷ����˫����������ָ��һ��λ�ú�����ý��֮ǰ�ĵ�2��ѧ����Ϣ����֮��ĵ�2��ѧ����Ϣ��
��7����������˫�����������ֳ���������һ������������һ����Ů������
*/
typedef struct studen1tinformation{//���������ݶ��� 
	int num;
	char name[10];	
}si;
typedef si sldatatype;
typedef struct slist{
	sldatatype val;
	struct slist *next;
}sl;

typedef struct student2information{//˫���������ݶ��� 
	int num;
	int gender; //1��������0��Ů�� 
	char name[10];	
}s2i;
typedef s2i lldatatype;
typedef struct llist{
	lldatatype val;
	struct llist *next;
	struct llist *prev;
}ll;
int c=1;
sl head;
sl*phead=&head;
ll head1;
ll head2;
ll *phead1=&head1;//�б�δ���ǰΪ�ܱ� 
ll *phead2=&head2;//Ů�� 

void llprintf2(struct llist *head,int n)//���������ʦ���ض�����
{ll *cur=head;
	while(n)
{cur=cur->next;
	n--;
} 
	if(cur->prev!=head&&cur->prev->prev!=head)
	{	printf("����ѡ�������ѧ��֮ǰ�ĵ�2��ѧ����ϢΪ\n"); 
	if(cur->prev->prev->val.gender==1)
			printf("%d     %s   ��\n",cur->prev->prev->val.num,cur->prev->prev->val.name);
		else 
		    printf("%d     %s   Ů\n",cur->prev->prev->val.num,cur->prev->prev->val.name);	
	}
	else
	{printf("��ѡ�������ѧ��֮ǰ�ĵ�2��ѧ����Ϣ������\n");}
	if(cur->next!=head&&cur->next->next!=head)
		{	printf("����ѡ�������ѧ��֮��ĵ�2��ѧ����ϢΪ\n"); 
		if(cur->next->next->val.gender==1)
				printf("%d     %s   ��\n",cur->next->next->val.num,cur->next->next->val.name);
			else 
			    printf("%d     %s   Ů\n",cur->next->next->val.num,cur->next->next->val.name);	
		}
		else
		{printf("��ѡ�������ѧ��֮��ĵ�2��ѧ����Ϣ������\n");}
			printf("����0����˫����ϵͳ\n");
 while(c) 
	  	{int opt;
	 	scanf("%d",&opt);
	  	switch(opt)
	 	{case 0:llmenu();break;
	 	default:printf("��������ȷ��ѡ��\n");
	 	}}		
	
} 
void llprintf(struct llist *head)//���˫���� 
{	
ll *cur=head->next;
printf("ѧ��	����   �Ա�\n"); 

	while(cur!=head) 
	{if(cur->val.gender==1)
		printf("%d     %s   ��\n",cur->val.num,cur->val.name);
	else 
	    printf("%d     %s   Ů\n",cur->val.num,cur->val.name);
		cur=cur->next;
	}
}
struct llist *Breakup(struct llist *head)//���ԭ��Ϊ�б����ر�ΪŮ��
{ ll* cur=head->next,*heads,*newnode,*cur2;
heads=(struct llist *)malloc(sizeof(struct llist));
heads->next=heads;
heads->prev=heads;
cur2=heads;
	while(cur!=head)
	{if(cur->val.gender==0)
	{newnode=cur;
	cur=cur->next;
	newnode->prev->next=newnode->next;
	newnode->next->prev=newnode->prev;	
	cur2->next=newnode;
	newnode->prev=cur2;
	cur2=cur2->next;	
	}
	else
	cur=cur->next;		
	}
	cur2->next=heads;
	heads->prev=cur2;
	return heads;
}
struct llist *llinit()//˫�������ʼ�� 
{ll *p2head,*cur,*newnode;
p2head=(struct llist *)malloc(sizeof(struct llist));
cur=p2head;
newnode=(struct llist *)malloc(sizeof(struct llist));
newnode->val.num=100;
newnode->val.gender=1;
strcpy(newnode->val.name,"����"); 
cur->next=newnode;
newnode->prev=cur;
cur=cur->next;
newnode=(struct llist *)malloc(sizeof(struct llist));
newnode->val.num=101;
newnode->val.gender=1;
strcpy(newnode->val.name,"����"); 
cur->next=newnode;
newnode->prev=cur;
cur=cur->next;
newnode=(struct llist *)malloc(sizeof(struct llist));
newnode->val.num=102;
newnode->val.gender=0;
strcpy(newnode->val.name,"����"); 
cur->next=newnode;
newnode->prev=cur;
cur=cur->next;
newnode=(struct llist *)malloc(sizeof(struct llist));
newnode->val.num=103;
newnode->val.gender=0;
strcpy(newnode->val.name,"����"); 
cur->next=newnode;
newnode->prev=cur;
cur=cur->next;
newnode=(struct llist *)malloc(sizeof(struct llist));
newnode->val.num=104;
newnode->val.gender=1;
strcpy(newnode->val.name,"����"); 
cur->next=newnode;
newnode->prev=cur;
cur=cur->next;
newnode=(struct llist *)malloc(sizeof(struct llist));
newnode->val.num=105;
newnode->val.gender=0;
strcpy(newnode->val.name,"����"); 
cur->next=newnode;
newnode->prev=cur;
cur=cur->next;
newnode=(struct llist *)malloc(sizeof(struct llist));
newnode->val.num=106;
newnode->val.gender=1;
strcpy(newnode->val.name,"�Ű�"); 
cur->next=newnode;
newnode->prev=cur;
cur=cur->next;
newnode=(struct llist *)malloc(sizeof(struct llist));
newnode->val.num=107;
newnode->val.gender=0;
strcpy(newnode->val.name,"�ž�"); 
cur->next=newnode;
newnode->prev=cur;
cur=cur->next;

cur->next=p2head;
p2head->prev=cur; 
return p2head; 
}
void end()
{		system("cls");
c=0;
printf("���˳�\n");	
}
void re()//����ϵͳ 
{printf("����0���ص�����ϵͳ\n");
	while(c) 
	{int opt;
	scanf("%d",&opt);
	switch(opt)
	{case 0:slmenu();break;
	default:printf("��������ȷ��ѡ��\n");
	}}	
}
void llmenu()//˫����˵� 
{system("cls");
		printf("  ******************************************************\n\n");
		printf("  *               ˫������Ϣ����ϵͳ                     *\n \n");
		printf("  ******************************************************\n\n");
		printf("     ----------------------   ----------------------   \n");
		printf("     *********************************************     \n");
		printf("     * 0.�鿴ѧ����Ϣ   *\n");
		printf("     *********************************************     \n");
		printf("     * 1.���         *\n");
		printf("     *********************************************     \n");		
		printf("     * 2.������ϵͳ             *\n");
		printf("     *********************************************     \n");
		printf("     * 3.�˳�ϵͳ             *\n");
		printf("     *********************************************     \n");
		printf("     ----------------------   ----------------------                  \n");
	while(c) //�˵�ʵ�� 
	{int opt;
	scanf("%d",&opt);
	 switch(opt)
	{case 0:llprintf(phead1);
	printf("��������ѡ������ڼ���ѧ��ǰ�ĵ�2��ѧ����Ϣ����֮��ĵ�2��ѧ����Ϣ\n");
	int a;
	scanf("%d",&a);
	llprintf2(phead1,a);
	break;
	 case 1:phead2=Breakup(phead1);
	 	    printf("�б�Ϊ:\n"); 
	 	 	llprintf(phead1);
	     	printf("Ů��Ϊ:\n"); 
	 	 	llprintf(phead2);
	 	 	printf("����0���ص�����ϵͳ\n");
	      while(c) 
	  	{int opt;
	 	scanf("%d",&opt);
	  	switch(opt)
	 	{case 0:llmenu();break;
	 	default:printf("��������ȷ��ѡ��\n");
	 	}}	
	 	 	break;
	 case 2:menu();break;
	 case 3:end();break;
     default:printf("��������ȷ��ѡ��\n");	
	}}	
}
void slmenu()//������˵� 
{system("cls");
		printf("  ******************************************************\n\n");
		printf("  *               ��������Ϣ����ϵͳ                     *\n \n");
		printf("  ******************************************************\n\n");
		printf("     ----------------------   ----------------------   \n");
		printf("     *********************************************     \n");
		printf("     * 0.�鿴ѧ����Ϣ    *\n");
		printf("     *********************************************     \n");
		printf("     * 1.����ѧ��           *\n");
		printf("     *********************************************     \n");		
		printf("     * 2.ɾ��ѧ��              *\n");
		printf("     *********************************************     \n");
		printf("     * 3.����ѧ��              *\n");
		printf("     *********************************************     \n");
		printf("     * 4.ͳ��ѧ������              *\n");
		printf("     *********************************************     \n");
		printf("     * 5.������ϵͳ             *\n");
		printf("     *********************************************     \n");
		printf("     * 6.�˳�ϵͳ             *\n");
		printf("     *********************************************     \n");
		printf("     ----------------------   ----------------------                  \n");
	while(c) //�˵�ʵ�� 
	{int opt;
	scanf("%d",&opt);
	 switch(opt)
	{case 0:slprintf(phead);break;
	 case 1:slInsertbefore(phead);break;
	 case 2:slErase(phead);break;
	 case 3:slFind(phead);break;
	 case 4:slsum(phead);break;
	 case 5:menu();break;
	 case 6:end();break;
     default:printf("��������ȷ��ѡ��\n");	
	}}	
}
void slsum(struct slist *head)//ͳ�Ʊ� 
{system("cls");
sl *cur=head->next;
int sum=0;
while(cur)
{sum++;
cur=cur->next;
}
printf("����%d��ѧ��\n",sum);	
re();
}
void slFind(struct slist *head)//���� 
{system("cls");
sl *cur=head->next;
int i;
printf("��������Ҫ����ѧ����ѧ��"); 
scanf("%d",&i);
while(cur) 
{if(cur->val.num==i)
{   printf("ѧ��	����\n"); 
	printf("%d     %s\n",cur->val.num,cur->val.name);
	re();
	break;}
	cur=cur->next;
}
if(!cur)
{printf("���޴���\n");
re();}
}

void slErase(struct slist *head)//ɾ�� 
{system("cls");
sl *cur=head,*del;
int sum=0,i;
printf("����������Ҫɾ���ڼ���ѧ��"); 
scanf("%d",&i);
while(cur) 
{  sum++;
cur=cur->next;
}
if(i>=sum)
{printf("��ѡ��ɾ�������ִ���ѧ����\n");
re();
}
cur=head;
while(i-1)
{i--;
cur=cur->next;
}
del=cur->next;
cur->next=cur->next->next;
free(del);
slprintf(head);	
re();
}
void slInsertbefore(struct slist *head)//���� 
{system("cls");
sl *cur=head,*newnode;
int i;
printf("��������Ҫ�ڵڼ���ѧ��֮ǰ����һ��ѧ��:\n");
scanf("%d",&i);
int n,sum=0;
char m[10];
while(cur) 
{  sum++;
cur=cur->next;
}
if(i>=sum)
{printf("��ѡ���������ִ���ѧ����\n");
re();
}
newnode=(struct slist *)malloc(sizeof(struct slist));
cur=head;
while(i-1)
{i--;
cur=cur->next;
}
newnode->next=cur->next;
cur->next=newnode;	
printf("��������ѧ����ѧ��������\n"); 
scanf("%d %s",&n,&m);
newnode->val.num=n;
strcpy(newnode->val.name,m);
slprintf(head);
re();
}
void slprintf(struct slist *head)//��������� 
{
sl *cur=head->next;
printf("ѧ��	����\n"); 
	if(!cur)
	printf("��ǰ��������ѧ��\n");
	while(cur) 
	{
		printf("%d     %s\n",cur->val.num,cur->val.name);
		cur=cur->next;
	}
}
void slheadinit(struct slist *head)//��ʼ���ڱ�ͷ 
{
head->next=NULL;
}
void slinit(struct slist *head) 
{sl *newnode,*cur=head;
newnode=(struct slist *)malloc(sizeof(struct slist));
newnode->val.num=100;
strcpy(newnode->val.name,"����"); 
cur->next=newnode;
cur=cur->next;
newnode=(struct slist *)malloc(sizeof(struct slist));
newnode->val.num=101;
strcpy(newnode->val.name,"����"); 
cur->next=newnode;
cur=cur->next;
newnode=(struct slist *)malloc(sizeof(struct slist));
newnode->val.num=102;
strcpy(newnode->val.name,"����"); 
cur->next=newnode;
cur=cur->next;
newnode->next=NULL;//��ָ�� 
}
void menu()
{		system("cls");
		printf("  ******************************************************\n\n");
		printf("  *               ѧ����Ϣ����ϵͳ                     *\n \n");
		printf("  ******************************************************\n\n");
		printf("     ----------------------   ----------------------   \n");
		printf("     *********************************************     \n");
		printf("     * 0.������ϵͳ     *\n");
		printf("     *********************************************     \n");
		printf("     * 1.˫����ϵͳ            *\n");
		printf("     *********************************************     \n");		
		printf("     * 2.�˳�ϵͳ                *\n");
		printf("     *********************************************     \n");
		printf("     ----------------------   ----------------------                  \n");
	while(c) //�˵�ʵ�� 
	{int opt;
	scanf("%d",&opt);
	 switch(opt)
	 {case 0:slmenu();break;
	  case 1:llmenu();break; 
	  case 2:end();break; 
     default:printf("��������ȷ��ѡ��\n");	
	}}	
}
int main()
{ 
slheadinit(phead);//��ʼ���ڱ�ͷ 
slinit(phead);//��ʼ��������   
phead1=llinit();//��ʼ��˫�������ͷ 
menu();
	return 0;
}
