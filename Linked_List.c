#include<stdio.h>
#include<process.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node*next;
};
struct node*start=NULL;

void addlast (void);
void addaftcons(void);
void delcons(void);
void addaftpos(void);
void delpos(void);
void traversal(void);

int main()

{
    int choice;
    while(1)
    {
        printf("\n1.Add Node Last");
        printf("\n2.Add Node After Constant");
        printf("\n3.Delete Constant");
        printf("\n4.Add Node After Position");
        printf("\n5.Delete Position Node");
        printf("\n6.Traversal");
        printf("\n7.Exit");
    
        printf("\nEnter Your Choice:");
        scanf("%d",&choice);

        switch(choice)
        {
             case 1:  addlast(); break;
             case 2: addaftcons(); break;
             case 3: delcons(); break;
             case 4: addaftpos(); break;
             case 5: delpos(); break;
             case 6: traversal(); break;
             case 7: exit(0);
        }
    }
    return(0);
}

void addlast(void)
{
    struct node*t=start;
    struct node*n=(struct node*)malloc(sizeof(struct node));
    printf("Enter Information");
    scanf("%d",&n->info);
    n->next=NULL;
    if(start==NULL)
    start=n;
    else
    {
         while(t->next!=NULL)
         {
             t=t->next;
         }
            t->next=n;
            printf("Node Added");
    }
}

void addaftcons (void)
{
     int cons;
     struct node*t=start;
     struct node*n=(struct node*)malloc(sizeof(struct node));
     printf("Enter Information");
     scanf("%d",&n->info);
     printf("Enter Constent Value");
     scanf("%d",&cons);
     while(t!=NULL && t->info!=cons)
     {
        t=t->next;     
     }
      if(t==NULL)
      {
        printf("Not Found");
        return;
      }
      n->next=t->next;
      t->next=n;
      printf("\nNode Inserted");
     

}

void delfront(void)
{
	struct node*t=start;
	if(start==NULL)
	printf("\nUnderflow");
	else
	{
		start=start->next;
		free(t);
	}
}
void delcons(void)
{
    int cons;
     struct node*t=start;
     struct node*p=NULL;
     printf("Enter Constant Value:");
     scanf("%d",&cons);
     if(t==NULL)
     printf("\nUnderflow");
     else if(t->info==cons)
     {
     	delfront();
     	printf("\nNode Deleted");
	 }
	 else
	 {
	 
		        while(t!=NULL && t->info!=cons)
		        {
		         p=t;
		        t=t->next;
		       }
		      if(t==NULL)
		      printf("\nNot Found");
		      else
       		{
		      p->next=t->next;
		      free(t);
		      printf("\nNode Deleted");
	    	 }
     }
}

int counting(void)
{
    int count=0;
    struct node*t=start;
    while(t!=NULL)
    {
        count++; 
        t=t->next;
    }
    return(count);

}

void addaftpos (void)
{
     int pos,loc=1;
     struct node*t=start;
     struct node*n=(struct node*)malloc(sizeof(struct node));
     printf("Enter Information");
     scanf("%d",&n->info);
     printf("Enter Position");
     scanf("%d",&pos);
     if(pos>counting())
     printf("\nInvalid Position");
     while(loc<pos)
     {
        loc++;
        t=t->next;
     }
     n->next=t->next;
     t->next=n;
     printf("\nNode Added");
}

void delpos(void)
{
    int pos,loc=1;
    struct node*t=start;
    struct node*f=NULL;
    printf("Enter Position");
    scanf("%d",&pos);    
     if(pos>counting())
    {
    	printf("\nInvalid Position");
	}
    else if(pos==1)
    {
    	delfront();
    	 printf("\nNode Deleted"); 
	}
	else
    {
        while(loc<pos)
        {
            loc++;
            f=t;
            t=t->next;
        }
        
        f->next=t->next;
        free(t);    
        printf("\nNode Deleted");       
    }
}

void traversal (void)
{
    struct node*t=start;
    if(start==NULL)
    {
        printf("\nUnderflow");
    }
    else
    {
       while(t!=NULL)
      {
        printf("%d ",t->info);
        t=t->next;
      }
    }
}
