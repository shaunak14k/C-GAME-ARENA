#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct head
{	
	struct head *next;
	char *line;
}*top=NULL,*curr,*prev,*last;

struct head *loadfile(char[]);

void print(); 
void insert();
void save();
void move();
void copy();
void delete();
void find();
void help();
struct head *gettxt();
struct head *duplicate(struct head *n1l,struct head *n2l);
char cmd[30];
int i;
void main(int argc,char *argv[])
{	
	if(argc>=2)
		top=loadfile(argv[1]);
	else
		top=NULL;
	printf("\np:Print \ni:Insert \ns:Save \nm:Move \nc:Copy \nd:Delete \nf:Find \nh:Help \nq:Quit");
	while(1)
	{
		printf("\n$");
		fgets(cmd,6,stdin);
		switch(cmd[0])
		{
			case 'p':print();
				break;
			case 'i':insert();
				break;
			case 's':save();
				break;
			case 'm':move();
				break;
			case 'c':copy();
				break;
			case 'd':delete();
				break;
			case 'f':find();
				break;
			case 'h':help();
				break;
			case 'q':exit(0);
		}//switch
	}//while
}//main

struct head *loadfile(char fname[])
{
	FILE *fp;
	char str[80];
	fp=fopen(fname,"r");
	if(fp==NULL)
	{
		printf("\nUnable to open file");
		exit(0);
	}
	top==NULL;
	while(!feof(fp))
	{
		fgets(str,80,fp);
		if(feof(fp))
			break;
		curr=(struct head*)malloc(sizeof(struct head));
		curr->line=(char*)malloc(strlen(str));
		strcpy(curr->line,str);
		if(top==NULL)
		{
			top=curr;
			prev=curr;
		}
		else
		{
			prev->next=curr;
			prev=curr;
		}
	}//while
	
	last=curr;
	printf("File loaded successfully"); 
	return top;
	
}//loadfile

void print()
{
	char t;
	int m,n;
	int ntoken=sscanf(cmd,"%c%d%d",&t,&m,&n);
	if(ntoken==1)
	{
	//print all lines
		curr=top;
		while(curr!=NULL)
		{
			printf("%s",curr->line);
			curr=curr->next;
		}
        }
	else
	{
		if(ntoken==2)
			n=m;
			//set current on mth line
			curr=top;
		for(i=1;i<=m-1;i++)
		{
			curr=curr->next;
			if(curr==NULL)
			{
				printf("Invalid line number....");
				return;
			}
		}//for
      
		//printf n lines
		for(i=m;i<=n;i++)
		{
			printf("%s",curr->line);
			curr=curr->next;
			if(curr==NULL)
				break;
		}
	}//else

}//print

void insert()
{
	struct head *atop,*nl;
	char t;
	int n;
	int ntoken=sscanf(cmd,"%c %d",&t,&n);
	if(ntoken==1)
	{
		printf("\n Please Specify line number...");
		return;
	}
//set nl on nth line
	nl=top;
	for(i=1;i<=n-1;i++)
	{
		nl=nl->next;
		if(nl==NULL)
		{
			printf("Invalid line number");
			return;
		}
	}
	atop=gettxt();
	if(n==1)//insert at top
	{
		curr->next=top;
		top=atop;
	}
	else//insert other than top
	{
		curr->next=nl->next;
		nl->next=atop;
	}
}//insert

struct head *gettxt()
{
	struct head *atop=NULL;
	char str[80];
	do
	{
		gets(str);
		if(strlen(str)==0)
			break;
		strcat(str,"\n");
		curr=(struct head*)malloc(sizeof(struct head));
		curr->line=(char *)malloc(strlen(str));
		strcpy(curr->line,str);
		if(atop==NULL)
		{
			atop=curr;
			prev=curr;
		}
		else
		{
			prev->next=curr;
			prev=curr;
		}
	}
	while(1);
	curr->next=NULL;
	return(atop);
}
void save()
{
	char fname[20];
	FILE *fp;
	printf("\nEnter the file name:");
	gets(fname);
	fp=fopen(fname,"w");
	if(fp==NULL)
	{
		printf("\n Unable to open file");
		exit(0);
	}
	else
	{
		curr=top;
		while(curr!=NULL)
		{
			fputs(curr->line,fp);
			curr=curr->next;
		}
		fclose(fp);
	}
}

void copy()
{
	struct head *n1l,*n2l,*atop,*pn3l,*n3l;
	char t;
	int n1,n2,n3;
	int ntoken=sscanf(cmd,"%c %d %d %d",&t,&n1,&n2,&n3);
	if(ntoken<3)
	{
		printf("Specify line number....");
		return;
	}
	if(ntoken==3)
	{
		n3=n2;
		n2=n1;
	}
	n1l=top;
	for(i=1;i<n1;i++)
		n1l=n1l->next;
	n2l=top;
	for(i=1;i<n2;i++)
		n2l=n2l->next;
	n3l=top;
	for(i=1;i<n3;i++)
	{
		pn3l=n3l;
		n3l=n3l->next;
	}
	atop=duplicate(n1l,n2l);
	if(n3l==top)
	{
		curr->next=top;
		top=atop;
	}
	else
	{
		pn3l->next=atop;
		curr->next=n3l;
	}
}
struct head *duplicate(struct head *n1l,struct head *n2l)
{
	struct head *atop=NULL,*temp;
	temp=n1l;
	while(temp!=n2l->next)
	{
		curr=(struct head*)malloc(sizeof(struct head));
		curr->line=(char *)malloc(strlen(temp->line));
		strcpy(curr->line,temp->line);
		if(atop==NULL)
		{
			atop=curr;
			prev=curr;
		}
		else
		{
			prev->next=curr;
			prev=curr;
		}
	temp=temp->next;
	}
	curr->next=NULL;
	return(atop);
}

void move()
{
	struct head *pn1l,*n1l,*n2l,*pn3l,*n3l;
	char t;
	int n1,n2,n3;
	int ntoken=sscanf(cmd,"%c%d%d%d",&t,&n1,&n2,&n3);
	if(ntoken<3)
	{
		printf("Specify the line number....");
		return;
	}
	if(ntoken==3)
	{
		n3=n2;
		n2=n1;
	}
	n1l=top;
	for(i=1;i<n1;i++)
	{
		pn1l=n1l;
		n1l=n1l->next;
	}
	n2l=top; 
	for(i=1;i<n2;i++)
		n2l=n2l->next;
		n3l=top;
	
	for(i=1;i<n3;i++)
	{
		pn3l=n3l;
		n3l=n3l->next;
	}
	if(n1l==top)
		top=n2l->next;
	else
		if(n3l==top)
		top=n1l;
		pn1l->next=n2l->next;
		n2l->next=n3l;
		pn3l->next=n2l;
}

void find()
{
	char t,pat[20],*ptr1;
	int ntoken;
	ntoken=sscanf(cmd,"%c%s",&t,&pat);
	if(ntoken==1)
	{
		printf("\nPattern not specified");
		return;
	}
	curr=top;
	i=1;
	while(curr!=NULL)
	{
		ptr1=strstr(curr->line,pat);
		if(ptr1!=NULL)
		printf("%d%s",i,curr->line);
		curr=curr->next;
		i++;
	}
}

void delete()
{
	char t;
	int m,n,ntoken;
	struct head *pml,*ml,*nl;
	ntoken=sscanf(cmd,"%c %d %d",&t,&m,&n);
	if(ntoken==1)
	{
		printf("\n erroe:no line number...");
		return;
	}
	else
	{
		if(ntoken==2)
		n=m;
		else
		if(m>n)
		{
			printf("\n form line should be less than to line");
			return;
		}
		pml=NULL;
		ml=top;
		for(i=5;i<=m-1;i++)
		{
			pml=ml;
			ml=ml->next;
		}
	nl=top;
	for(i=1;i<=n-1;i++)
		nl=nl->next;
	if(ml==top)
		top=nl->next;
	else
		pml->next=nl->next;
	}
}




void help()
{
	printf("\n h:help \t\tp:print");
	printf("\n f:find pattern \t\ts:save");
	printf("\n d:delete \t\tc:copy");
	printf("\n m:move \t\ti:insert");
}

