#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
typedef int typ; 
struct goods
{
	char name[10];//货物名
	int num;//编号
	int sum;//数量 
};
typedef struct SL
{ 
  int size;//表示数据个数
  int capacity=50;//容量
  char c[10];
  struct goods gs[50];//货物 
}sl;
int c=1;
sl g;
int size1=3;//在外初始化货物数量，便于其他函数调用 
void menu();
void end();
void check();
void checkname(sl *ps);
void checknum(sl *ps);
void init(sl *ps);
void browse(sl *ps);
void put(sl *ps);
void out(sl *ps);

void end()
{		system("cls");
c=0;
printf("已退出\n");	
}

void menu()
{		system("cls");
		printf("  ******************************************************\n\n");
		printf("  *               仓库货物管理系统                     *\n \n");
		printf("  ******************************************************\n\n");
		printf("     ----------------------   ----------------------   \n");
		printf("     *********************************************     \n");
		printf("     * 0.查看所有货物信息        *\n");
		printf("     *********************************************     \n");
		printf("     * 1.查询货物                *\n");
		printf("     *********************************************     \n");		
		printf("     * 2.货物入库管理               *\n");
		printf("     *********************************************     \n");
		printf("     * 3.货物出库管理              *\n");
		printf("     *********************************************     \n");
		printf("     * 4.退出系统                *\n");
		printf("     *********************************************     \n");
		printf("     ----------------------   ----------------------                  \n");
	while(c) //菜单实现 
	{int opt;
	scanf("%d",&opt);
	 switch(opt)
	 {case 0:browse(&g);break;
      case 1:check();break;
      case 2:put(&g);break;
      case 3:out(&g);break;
      case 4:end();break;
     default:printf("请输入正确的选项\n");	
	}}	
}

void init(sl *ps)//初始化 
{  ps->size=3;
strcpy(ps->gs[0].name, "shupian");
ps->gs[0].num=1;
ps->gs[0].sum=10;
strcpy(ps->gs[1].name, "kele");
ps->gs[1].num=2;
ps->gs[1].sum=15;
strcpy(ps->gs[2].name, "binggan");
ps->gs[2].num=3;
ps->gs[2].sum=17;
}

void browse(sl *ps)
{	system("cls");
printf("货物名     编号    数量\n");
for(int i=0;i<size1;i++)	
{printf("%-10s %-5d   %-5d\n",ps->gs[i].name,ps->gs[i].num,ps->gs[i].sum);
}
			printf("  ******************************************************\n\n");
			printf("     * 选择您接下来行进行的操作      *\n");
			printf("     *********************************************     \n");
			printf("     * 0.返回菜单   *\n");
			printf("     *********************************************     \n");
			printf("     * 1.退出系统   *\n");
			printf("     *********************************************     \n");
			printf("     ----------------------   ----------------------                  \n");
while(c) 
{int opt;
scanf("%d",&opt);
switch(opt)
{case 0:menu();break;
 case 1:end();break;
default:printf("请输入正确的选项\n");
}}
}

void check()
{system("cls");
		printf("  ******************************************************\n\n");
				printf("     * 选择您接下来行进行的操作      *\n");
				printf("     *********************************************     \n");
				printf("     * 0.返回菜单   *\n");
				printf("     *********************************************     \n");
				printf("     * 1.按名称查询   *\n");
				printf("     *********************************************     \n");
				printf("     * 2.按编号查询   *\n");
				printf("     *********************************************     \n");
				printf("     ----------------------   ----------------------                  \n");
	while(c) 
	{int opt;
	scanf("%d",&opt);
	switch(opt)
	{case 0:menu();break;
	 case 1:checkname(&g);break;
	 case 2:checknum(&g);break;
	default:printf("请输入正确的选项\n");
	}}	
}

void checkname(sl *ps)
{char a[10];
printf("输入你要查询货物的名称");
scanf("%s",a);
for(int i=0;i<size1;i++)
{if(strcmp(a,ps->gs[i].name)==0)
{printf("货物名     编号    数量\n");
printf("%-10s %-5d   %-5d\n",ps->gs[i].name,ps->gs[i].num,ps->gs[i].sum);
printf("货物已查询到\n");
break;
}
if(i==size1-1)
printf("货物未查询到\n");
}
printf("输入0返回菜单\n");
	while(c) 
	{int opt;
	scanf("%d",&opt);
	switch(opt)
	{case 0:menu();break;
	default:printf("请输入正确的选项\n");
	}}	
}

void checknum(sl *ps)
{int a; 
	printf("输入你要查询货物的编号");
	scanf("%d",&a);
for(int i=0;i<size1;i++)
{if(a==ps->gs[i].num)
{printf("货物名     编号    数量\n");
printf("%-10s %-5d   %-5d\n",ps->gs[i].name,ps->gs[i].num,ps->gs[i].sum);
printf("货物已查询到\n");
break;
}
if(i==size1-1)
printf("货物未查询到\n");
}	
printf("输入0返回菜单\n");
	while(c) 
	{int opt;
	scanf("%d",&opt);
	switch(opt)
	{case 0:menu();break;
	default:printf("请输入正确的选项\n");
	}}		
}

void put(sl *ps)
{system("cls");
char a[10];
int b; 
printf("请输入库货物的名称\n");
scanf("%s",a);	
for(int i=0;i<size1;i++)
{if(strcmp(a,ps->gs[i].name)==0)
{
printf("请输入你入库货物的数量(此货物已入库)\n");
scanf("%d",&b);	
ps->gs[i].sum=ps->gs[i].sum+b;
break;
}
if(i==size1-1)
{printf("请输入你入库货物数量(此货物未入库，将作为新货物入库，其编号为%d)\n",size1+1);
scanf("%d",&b);	
size1++;	
break;
}}
printf("输入0返回菜单\n");
	while(c) 
	{int opt;
	scanf("%d",&opt);
	switch(opt)
	{case 0:menu();break;
	default:printf("请输入正确的选项\n");
	}}	
}

void out(sl *ps)
{system("cls");
char a[10];
int b; 
printf("输入你要出库货物的名称");
scanf("%s",a);
for(int i=0;i<size1;i++)
{if(strcmp(a,ps->gs[i].name)==0)
{printf("货物名     编号    数量\n");
printf("%-10s %-5d   %-5d\n",ps->gs[i].name,ps->gs[i].num,ps->gs[i].sum);
printf("请输入需要出库货物的数量\n");
scanf("%d",&b);	
ps->gs[i].sum=ps->gs[i].sum-b;
break;}
if(i==size1-1)
{printf("未查寻到该货物\n");
}
}
printf("输入0返回菜单\n");

	while(c) 
	{int opt;
	scanf("%d",&opt);
	switch(opt)
	{case 0:menu();break;
	default:printf("请输入正确的选项\n");
	}}}	

int main()
{   
    init(&g);
	menu();
	return 0;
}
