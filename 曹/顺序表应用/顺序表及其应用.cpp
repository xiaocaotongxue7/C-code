#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
typedef int typ; 
struct goods
{
	char name[10];//������
	int num;//���
	int sum;//���� 
};
typedef struct SL
{ 
  int size;//��ʾ���ݸ���
  int capacity=50;//����
  char c[10];
  struct goods gs[50];//���� 
}sl;
int c=1;
sl g;
int size1=3;//�����ʼ���������������������������� 
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
printf("���˳�\n");	
}

void menu()
{		system("cls");
		printf("  ******************************************************\n\n");
		printf("  *               �ֿ�������ϵͳ                     *\n \n");
		printf("  ******************************************************\n\n");
		printf("     ----------------------   ----------------------   \n");
		printf("     *********************************************     \n");
		printf("     * 0.�鿴���л�����Ϣ        *\n");
		printf("     *********************************************     \n");
		printf("     * 1.��ѯ����                *\n");
		printf("     *********************************************     \n");		
		printf("     * 2.����������               *\n");
		printf("     *********************************************     \n");
		printf("     * 3.����������              *\n");
		printf("     *********************************************     \n");
		printf("     * 4.�˳�ϵͳ                *\n");
		printf("     *********************************************     \n");
		printf("     ----------------------   ----------------------                  \n");
	while(c) //�˵�ʵ�� 
	{int opt;
	scanf("%d",&opt);
	 switch(opt)
	 {case 0:browse(&g);break;
      case 1:check();break;
      case 2:put(&g);break;
      case 3:out(&g);break;
      case 4:end();break;
     default:printf("��������ȷ��ѡ��\n");	
	}}	
}

void init(sl *ps)//��ʼ�� 
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
printf("������     ���    ����\n");
for(int i=0;i<size1;i++)	
{printf("%-10s %-5d   %-5d\n",ps->gs[i].name,ps->gs[i].num,ps->gs[i].sum);
}
			printf("  ******************************************************\n\n");
			printf("     * ѡ�����������н��еĲ���      *\n");
			printf("     *********************************************     \n");
			printf("     * 0.���ز˵�   *\n");
			printf("     *********************************************     \n");
			printf("     * 1.�˳�ϵͳ   *\n");
			printf("     *********************************************     \n");
			printf("     ----------------------   ----------------------                  \n");
while(c) 
{int opt;
scanf("%d",&opt);
switch(opt)
{case 0:menu();break;
 case 1:end();break;
default:printf("��������ȷ��ѡ��\n");
}}
}

void check()
{system("cls");
		printf("  ******************************************************\n\n");
				printf("     * ѡ�����������н��еĲ���      *\n");
				printf("     *********************************************     \n");
				printf("     * 0.���ز˵�   *\n");
				printf("     *********************************************     \n");
				printf("     * 1.�����Ʋ�ѯ   *\n");
				printf("     *********************************************     \n");
				printf("     * 2.����Ų�ѯ   *\n");
				printf("     *********************************************     \n");
				printf("     ----------------------   ----------------------                  \n");
	while(c) 
	{int opt;
	scanf("%d",&opt);
	switch(opt)
	{case 0:menu();break;
	 case 1:checkname(&g);break;
	 case 2:checknum(&g);break;
	default:printf("��������ȷ��ѡ��\n");
	}}	
}

void checkname(sl *ps)
{char a[10];
printf("������Ҫ��ѯ���������");
scanf("%s",a);
for(int i=0;i<size1;i++)
{if(strcmp(a,ps->gs[i].name)==0)
{printf("������     ���    ����\n");
printf("%-10s %-5d   %-5d\n",ps->gs[i].name,ps->gs[i].num,ps->gs[i].sum);
printf("�����Ѳ�ѯ��\n");
break;
}
if(i==size1-1)
printf("����δ��ѯ��\n");
}
printf("����0���ز˵�\n");
	while(c) 
	{int opt;
	scanf("%d",&opt);
	switch(opt)
	{case 0:menu();break;
	default:printf("��������ȷ��ѡ��\n");
	}}	
}

void checknum(sl *ps)
{int a; 
	printf("������Ҫ��ѯ����ı��");
	scanf("%d",&a);
for(int i=0;i<size1;i++)
{if(a==ps->gs[i].num)
{printf("������     ���    ����\n");
printf("%-10s %-5d   %-5d\n",ps->gs[i].name,ps->gs[i].num,ps->gs[i].sum);
printf("�����Ѳ�ѯ��\n");
break;
}
if(i==size1-1)
printf("����δ��ѯ��\n");
}	
printf("����0���ز˵�\n");
	while(c) 
	{int opt;
	scanf("%d",&opt);
	switch(opt)
	{case 0:menu();break;
	default:printf("��������ȷ��ѡ��\n");
	}}		
}

void put(sl *ps)
{system("cls");
char a[10];
int b; 
printf("���������������\n");
scanf("%s",a);	
for(int i=0;i<size1;i++)
{if(strcmp(a,ps->gs[i].name)==0)
{
printf("�������������������(�˻��������)\n");
scanf("%d",&b);	
ps->gs[i].sum=ps->gs[i].sum+b;
break;
}
if(i==size1-1)
{printf("������������������(�˻���δ��⣬����Ϊ�»�����⣬����Ϊ%d)\n",size1+1);
scanf("%d",&b);	
size1++;	
break;
}}
printf("����0���ز˵�\n");
	while(c) 
	{int opt;
	scanf("%d",&opt);
	switch(opt)
	{case 0:menu();break;
	default:printf("��������ȷ��ѡ��\n");
	}}	
}

void out(sl *ps)
{system("cls");
char a[10];
int b; 
printf("������Ҫ������������");
scanf("%s",a);
for(int i=0;i<size1;i++)
{if(strcmp(a,ps->gs[i].name)==0)
{printf("������     ���    ����\n");
printf("%-10s %-5d   %-5d\n",ps->gs[i].name,ps->gs[i].num,ps->gs[i].sum);
printf("��������Ҫ������������\n");
scanf("%d",&b);	
ps->gs[i].sum=ps->gs[i].sum-b;
break;}
if(i==size1-1)
{printf("δ��Ѱ���û���\n");
}
}
printf("����0���ز˵�\n");

	while(c) 
	{int opt;
	scanf("%d",&opt);
	switch(opt)
	{case 0:menu();break;
	default:printf("��������ȷ��ѡ��\n");
	}}}	

int main()
{   
    init(&g);
	menu();
	return 0;
}
