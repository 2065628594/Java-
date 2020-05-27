#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<iostream>
using namespace std;
#define P_NUM  5
#define P_TIME  50
enum state
{
    ready,
    execute,
    block,
    finish
};//�������״̬
struct pcb
{
    char name[20];//������
    int priority;         //����Ȩ
    int cputime;       //CPU����ʱ��
    int needtime;    //������������ʱ��
    int count;         //����ִ�д���
    int round;          //ʱ��Ƭ��ת�ִ�
    state process;  //����״̬
    pcb *next;
};//�������PCB
pcb  *get_process()
{
    pcb  *q;
    pcb  *t;
    pcb  *p;
    int  i=0;
    cout<<"input name and time"<<endl;
    while(i<P_NUM)
	{
        pcb *g=(struct pcb *)malloc(sizeof (pcb));
        cin>>q->name;
        cin>>q->needtime;
        q->cputime=0;
        q->priority=g->needtime;
        q->process=ready;
        q->next=NULL;
        if(i==0) 
		{
            p=q;
            t=q;
		}
        else
		{
            t->next=q;//�����������̶���
            t=q;
        }
        i++;
    }
      //while
    return p;
}//����ģ����ԵĽ�������ִ������ʱ�䣬��ʼ���ÿ�ģ��5�����̵ĵ���
void display(pcb  *p)
{
    cout<<"name"<<"   "<<"cputime"<<"    "<<"needtime"<<"  "<<"priority"<<"    "<<"state"<<endl;
    while(p)
	{
        cout<<p->name;
        cout<<"            ";
        cout<<p->cputime;
        cout<<"           "; 
        cout<<p->needtime;
        cout<< "            ";
        cout<<p->priority;
        cout<<"            ";
        switch(p->process)
		{
            case  ready:   cout<<"ready"<<endl; 
			               break;
            case  execute: cout<<"execute"<<endl; 
			               break;
            case  block:   cout<<"block"<<endl; 
			               break;
            case  finish:  cout<<"finish"<<endl; 
			               break;
        }
        p=p->next;
    }
}//��ʾģ������������������CPUʱ�䡢��������ʱ���Լ����ȼ�

int process_finish(pcb *q)
{
    int bl=1;
    while(bl&&q)
	{
        bl=bl&&q->needtime==0;
        q=q->next;
    }
    return bl;
}//�������̣����������и����̵�����ʱ������Ϊ0
void  cpuexe(pcb  *q)
{
    pcb *t=q;
    int tp=0;
    while(q) 
	{
        if (q->process!=finish) 
		{
            q->process=ready;
            if(q->needtime==0) 
			{
                q->process=finish;
            }
        }
        if(tp<q->priority&&q->process!=finish) 
		{
            tp=q->priority;
            t=q;
        }
        q=q->next;
    }
    if(t->needtime!=0)
	{
        t->priority-=3;
        t->needtime--;
        t->process=execute;
        t->cputime++;
    }
}
//ѡ��ĳһ���̣���������CPU
//����������ȼ�
void  priority_cal()
{
    pcb  *p;
    system("cls");
    //clrscr();
    p=get_process();
    int cpu=0;
    system("cls");
    //clrscr();
    while(!process_finish(p))
	{
        cpu++;
        cout<<"cputime:"<<cpu<<endl;
        cpuexe(p);
        display(p);
        Sleep(2);
        //system("cls");
        //clrscr();
    }
    printf("All processes have finished, press any key to exit");
    getch();
}
void display_menu()
{
    cout<<"CHOOSE THE ALGORITHM:"<<endl;
    cout<<"1  PRIORITY"<<endl;
    cout<<"2  ROUNDROBIN"<<endl;
    cout<<"3  EXIT"<< endl;
} //��ʾ�����㷨�˵����ɹ��û�ѡ������Ȩ�����㷨��ʱ��Ƭ��ת�����㷨
pcb  * get_process_round()
{
    pcb  *q;
    pcb *t;
    pcb *p;
    int i=0;
    cout<<"input name and time"<<endl;
    while(i<P_NUM)
	{
        q=(struct pcb *)malloc(sizeof(pcb));
        cin>>q->name;
        cin>>q->needtime;
        q->cputime=0;
        q->round=0;
        q->count=0;
        q->process=ready;
        q->next=NULL;
        if(i==0)
		{
            p=q;
            t=q;
        }
        else
		{
            t->next=q;
            t=q;
        }
        i++;
    } //while
    return p;
}  //ʱ��Ƭ��ת�����㷨�����������̶���
void cpu_round(pcb  *q)
{
    q->cputime+=2;
    q->needtime-=2;
    if(q->needtime<0)
	{
        q->needtime=0;
    }               
    q->count++;
    q->round++;
    q->process= execute;
}   //����ʱ��Ƭ��ת�����㷨ִ��ĳһ����
pcb  *get_next( pcb * k,  pcb * head)
{
    pcb * t;
    t=k;
    do
	{
        t=t->next;
    }while(t&&t->process==finish);
    if(t==NULL)
	{
        t=head;
        while(t->next!=k && t->process== finish)
		{
           t=t->next;
        }
    }
    return t;
}  //��ȡ��һ������
void set_state(pcb  *p)
{
    while(p)
	{
        if(p->needtime==0)
		{
            p-> process= finish;      //�������ִ��ʱ��Ϊ0������������״̬Ϊ��|
        }       
        if (p->process==-execute) 
		{
            p->process=ready;//���Ϊִ��״̬������Ϊ����
        } 
        p=p->next;
    }
}//���ö����н���ִ��״̬
void display_round( pcb * p)
{
    cout<<"NAME"<<"    "<<"CPUTIME"<<"   "<<"NEEDTIME"<<"   "<<"OOUNT"<<"   "<<"ROUTND"<<"    "<<"STATE"<<endl;
    while(p)
	{
        cout<<p->name;
        cout<<"          ";
        cout<<p-> cputime;
        cout<<"          ";
        cout<<p->needtime;
        cout<<"          ";
        cout<<p->count;
        cout<<"          ";
        cout<<p-> round;
        cout<<"          ";
        switch(p->process)
		{
            case ready:    cout<<"ready"<< endl; 
			               break;
            case execute:  cout<<"execute"<<endl; 
			               break;
            case finish:   cout<<"finish"<<endl; 
			               break;
        }
        p=p->next;
    }
}//ʱ��Ƭ��ת�����㷨���������Ϣ
void round_cal()
{
    pcb * p;
    pcb*  r;
    system("cls");
    //clrscr();
    p=get_process_round();
    int cpu=0;
    system("c1s");
    //clrscr;
    r=p; 
    while(!process_finish(p)) 
	{
        cpu+=2;
        cpu_round(r);
        r=get_next(r, p);
        cout<< "cpu "<<cpu<<endl;
        display_round(p);
        set_state(p);
        Sleep(5);
        //system("cls");
        //clrsrc();
    }
} //ʱ��Ƭ��ת�����㷨�����ִμ����������Ϣ
int main()
{
    display_menu();
    int k;
    scanf("%d",&k);
    switch(k)
	{
        case 1: priority_cal(); 
		        break;
        case 2: round_cal(); 
		        break;
        case 3: break;
        display_menu();
        scanf("%d",&k);
    }
    return 0;
} 

