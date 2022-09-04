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
（6）用尾插法建立一个存储学生信息的带头结点的双向链表，任意指定一个位置后，输出该结点之前的第2个学生信息和它之后的第2个学生信息。
（7）基于上述双向链表，将其拆分成两个链表，一个是男生链表，一个是女生链表。
*/
typedef struct studen1tinformation{//单链表数据定义 
	int num;
	char name[10];	
}si;
typedef si sldatatype;
typedef struct slist{
	sldatatype val;
	struct slist *next;
}sl;

typedef struct student2information{//双向链表数据定义 
	int num;
	int gender; //1是男生，0是女生 
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
ll *phead1=&head1;//男表，未拆分前为总表 
ll *phead2=&head2;//女表 

void llprintf2(struct llist *head,int n)//用于输出老师的特定功能
{ll *cur=head;
	while(n)
{cur=cur->next;
	n--;
} 
	if(cur->prev!=head&&cur->prev->prev!=head)
	{	printf("在您选择输出的学生之前的第2个学生信息为\n"); 
	if(cur->prev->prev->val.gender==1)
			printf("%d     %s   男\n",cur->prev->prev->val.num,cur->prev->prev->val.name);
		else 
		    printf("%d     %s   女\n",cur->prev->prev->val.num,cur->prev->prev->val.name);	
	}
	else
	{printf("您选择输出的学生之前的第2个学生信息不存在\n");}
	if(cur->next!=head&&cur->next->next!=head)
		{	printf("在您选择输出的学生之后的第2个学生信息为\n"); 
		if(cur->next->next->val.gender==1)
				printf("%d     %s   男\n",cur->next->next->val.num,cur->next->next->val.name);
			else 
			    printf("%d     %s   女\n",cur->next->next->val.num,cur->next->next->val.name);	
		}
		else
		{printf("您选择输出的学生之后的第2个学生信息不存在\n");}
			printf("输入0返回双链表系统\n");
 while(c) 
	  	{int opt;
	 	scanf("%d",&opt);
	  	switch(opt)
	 	{case 0:llmenu();break;
	 	default:printf("请输入正确的选项\n");
	 	}}		
	
} 
void llprintf(struct llist *head)//输出双链表 
{	
ll *cur=head->next;
printf("学号	姓名   性别\n"); 

	while(cur!=head) 
	{if(cur->val.gender==1)
		printf("%d     %s   男\n",cur->val.num,cur->val.name);
	else 
	    printf("%d     %s   女\n",cur->val.num,cur->val.name);
		cur=cur->next;
	}
}
struct llist *Breakup(struct llist *head)//拆表，原表为男表，返回表为女表
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
struct llist *llinit()//双向链表初始化 
{ll *p2head,*cur,*newnode;
p2head=(struct llist *)malloc(sizeof(struct llist));
cur=p2head;
newnode=(struct llist *)malloc(sizeof(struct llist));
newnode->val.num=100;
newnode->val.gender=1;
strcpy(newnode->val.name,"张三"); 
cur->next=newnode;
newnode->prev=cur;
cur=cur->next;
newnode=(struct llist *)malloc(sizeof(struct llist));
newnode->val.num=101;
newnode->val.gender=1;
strcpy(newnode->val.name,"李四"); 
cur->next=newnode;
newnode->prev=cur;
cur=cur->next;
newnode=(struct llist *)malloc(sizeof(struct llist));
newnode->val.num=102;
newnode->val.gender=0;
strcpy(newnode->val.name,"赵六"); 
cur->next=newnode;
newnode->prev=cur;
cur=cur->next;
newnode=(struct llist *)malloc(sizeof(struct llist));
newnode->val.num=103;
newnode->val.gender=0;
strcpy(newnode->val.name,"王五"); 
cur->next=newnode;
newnode->prev=cur;
cur=cur->next;
newnode=(struct llist *)malloc(sizeof(struct llist));
newnode->val.num=104;
newnode->val.gender=1;
strcpy(newnode->val.name,"张六"); 
cur->next=newnode;
newnode->prev=cur;
cur=cur->next;
newnode=(struct llist *)malloc(sizeof(struct llist));
newnode->val.num=105;
newnode->val.gender=0;
strcpy(newnode->val.name,"张七"); 
cur->next=newnode;
newnode->prev=cur;
cur=cur->next;
newnode=(struct llist *)malloc(sizeof(struct llist));
newnode->val.num=106;
newnode->val.gender=1;
strcpy(newnode->val.name,"张八"); 
cur->next=newnode;
newnode->prev=cur;
cur=cur->next;
newnode=(struct llist *)malloc(sizeof(struct llist));
newnode->val.num=107;
newnode->val.gender=0;
strcpy(newnode->val.name,"张九"); 
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
printf("已退出\n");	
}
void re()//返回系统 
{printf("输入0返回单链表系统\n");
	while(c) 
	{int opt;
	scanf("%d",&opt);
	switch(opt)
	{case 0:slmenu();break;
	default:printf("请输入正确的选项\n");
	}}	
}
void llmenu()//双链表菜单 
{system("cls");
		printf("  ******************************************************\n\n");
		printf("  *               双链表信息管理系统                     *\n \n");
		printf("  ******************************************************\n\n");
		printf("     ----------------------   ----------------------   \n");
		printf("     *********************************************     \n");
		printf("     * 0.查看学生信息   *\n");
		printf("     *********************************************     \n");
		printf("     * 1.拆表         *\n");
		printf("     *********************************************     \n");		
		printf("     * 2.返回主系统             *\n");
		printf("     *********************************************     \n");
		printf("     * 3.退出系统             *\n");
		printf("     *********************************************     \n");
		printf("     ----------------------   ----------------------                  \n");
	while(c) //菜单实现 
	{int opt;
	scanf("%d",&opt);
	 switch(opt)
	{case 0:llprintf(phead1);
	printf("请输入您选择输出第几个学生前的第2个学生信息和它之后的第2个学生信息\n");
	int a;
	scanf("%d",&a);
	llprintf2(phead1,a);
	break;
	 case 1:phead2=Breakup(phead1);
	 	    printf("男表为:\n"); 
	 	 	llprintf(phead1);
	     	printf("女表为:\n"); 
	 	 	llprintf(phead2);
	 	 	printf("输入0返回单链表系统\n");
	      while(c) 
	  	{int opt;
	 	scanf("%d",&opt);
	  	switch(opt)
	 	{case 0:llmenu();break;
	 	default:printf("请输入正确的选项\n");
	 	}}	
	 	 	break;
	 case 2:menu();break;
	 case 3:end();break;
     default:printf("请输入正确的选项\n");	
	}}	
}
void slmenu()//单链表菜单 
{system("cls");
		printf("  ******************************************************\n\n");
		printf("  *               单链表信息管理系统                     *\n \n");
		printf("  ******************************************************\n\n");
		printf("     ----------------------   ----------------------   \n");
		printf("     *********************************************     \n");
		printf("     * 0.查看学生信息    *\n");
		printf("     *********************************************     \n");
		printf("     * 1.增加学生           *\n");
		printf("     *********************************************     \n");		
		printf("     * 2.删除学生              *\n");
		printf("     *********************************************     \n");
		printf("     * 3.查找学生              *\n");
		printf("     *********************************************     \n");
		printf("     * 4.统计学生个数              *\n");
		printf("     *********************************************     \n");
		printf("     * 5.返回主系统             *\n");
		printf("     *********************************************     \n");
		printf("     * 6.退出系统             *\n");
		printf("     *********************************************     \n");
		printf("     ----------------------   ----------------------                  \n");
	while(c) //菜单实现 
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
     default:printf("请输入正确的选项\n");	
	}}	
}
void slsum(struct slist *head)//统计表长 
{system("cls");
sl *cur=head->next;
int sum=0;
while(cur)
{sum++;
cur=cur->next;
}
printf("共有%d个学生\n",sum);	
re();
}
void slFind(struct slist *head)//查找 
{system("cls");
sl *cur=head->next;
int i;
printf("请输入你要查找学生的学号"); 
scanf("%d",&i);
while(cur) 
{if(cur->val.num==i)
{   printf("学号	姓名\n"); 
	printf("%d     %s\n",cur->val.num,cur->val.name);
	re();
	break;}
	cur=cur->next;
}
if(!cur)
{printf("查无此人\n");
re();}
}

void slErase(struct slist *head)//删除 
{system("cls");
sl *cur=head,*del;
int sum=0,i;
printf("请输入你需要删除第几个学生"); 
scanf("%d",&i);
while(cur) 
{  sum++;
cur=cur->next;
}
if(i>=sum)
{printf("您选择删除的数字大于学生数\n");
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
void slInsertbefore(struct slist *head)//插入 
{system("cls");
sl *cur=head,*newnode;
int i;
printf("请输入你要在第几个学生之前增加一名学生:\n");
scanf("%d",&i);
int n,sum=0;
char m[10];
while(cur) 
{  sum++;
cur=cur->next;
}
if(i>=sum)
{printf("您选择插入的数字大于学生数\n");
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
printf("请输入新学生的学号与姓名\n"); 
scanf("%d %s",&n,&m);
newnode->val.num=n;
strcpy(newnode->val.name,m);
slprintf(head);
re();
}
void slprintf(struct slist *head)//输出单链表 
{
sl *cur=head->next;
printf("学号	姓名\n"); 
	if(!cur)
	printf("当前名单并无学生\n");
	while(cur) 
	{
		printf("%d     %s\n",cur->val.num,cur->val.name);
		cur=cur->next;
	}
}
void slheadinit(struct slist *head)//初始化哨兵头 
{
head->next=NULL;
}
void slinit(struct slist *head) 
{sl *newnode,*cur=head;
newnode=(struct slist *)malloc(sizeof(struct slist));
newnode->val.num=100;
strcpy(newnode->val.name,"张三"); 
cur->next=newnode;
cur=cur->next;
newnode=(struct slist *)malloc(sizeof(struct slist));
newnode->val.num=101;
strcpy(newnode->val.name,"李四"); 
cur->next=newnode;
cur=cur->next;
newnode=(struct slist *)malloc(sizeof(struct slist));
newnode->val.num=102;
strcpy(newnode->val.name,"王五"); 
cur->next=newnode;
cur=cur->next;
newnode->next=NULL;//空指针 
}
void menu()
{		system("cls");
		printf("  ******************************************************\n\n");
		printf("  *               学生信息管理系统                     *\n \n");
		printf("  ******************************************************\n\n");
		printf("     ----------------------   ----------------------   \n");
		printf("     *********************************************     \n");
		printf("     * 0.单链表系统     *\n");
		printf("     *********************************************     \n");
		printf("     * 1.双链表系统            *\n");
		printf("     *********************************************     \n");		
		printf("     * 2.退出系统                *\n");
		printf("     *********************************************     \n");
		printf("     ----------------------   ----------------------                  \n");
	while(c) //菜单实现 
	{int opt;
	scanf("%d",&opt);
	 switch(opt)
	 {case 0:slmenu();break;
	  case 1:llmenu();break; 
	  case 2:end();break; 
     default:printf("请输入正确的选项\n");	
	}}	
}
int main()
{ 
slheadinit(phead);//初始化哨兵头 
slinit(phead);//初始化单链表   
phead1=llinit();//初始化双向链表表头 
menu();
	return 0;
}
