#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct list
{ int info;
  struct list *link;
};

int ctr=0;

typedef struct list node;

void create(node*);
void display(node*);
node* insert(node*);
node* del(node*);
main()
{ node *head=NULL;
  int choice;
  char ch;
  do
  { printf("\n1. Creation \n2. Display \n3. Insert \n4. Delete");
    printf("\nEnter your choice.");
    scanf("%d",&choice);
    switch(choice)
    { case 1: head = (node*) malloc(sizeof(node));
	          create(head);
	          break;
	  case 2: if(head!=NULL)
	            display(head);
	          else printf("\nEmpty list");
	          break;
	  case 3: if(head!=NULL)
	            head=insert(head);
	          else printf("\nEmpty list");
	          break;
      case 4: if(head!=NULL)
               head=del(head);
              else printf("\nEmpty list");
              break;
	  default: printf("\nInvalid Input");
	}
	printf("\nDo you want to continue? ans(y/n)");
	fflush(stdin);
	ch=getchar();
  }while(ch=='y');
  return 0;
  
}

void create(node *ptr)
{ char ch;
  printf("\nEnter info.");
  scanf("%d",&ptr->info);
  ctr++;
  printf("\nDo you want another node? Ans(y/n)");
  fflush(stdin);
  ch=getchar();
  if(ch=='y')
  { ptr->link=(node*) malloc(sizeof(node));
    create(ptr->link);
  }
  else
    ptr->link=NULL;
}

void display(node *ptr)
{ while(ptr!=NULL)
  {printf("%d->",ptr->info);
   ptr=ptr->link;
  }
  printf("NULL");
  
}

node* insert(node *ptr)
{ char ch; int p; int c=1; node *temp = ptr;
  node *newnode=NULL;
  newnode = (node*)malloc(sizeof(node));
  printf("\nEnter the info for your new node");
  scanf("%d",&newnode->info);
   printf("\nEnter the position the element has to be inserted in. (Range:1-%d)",ctr+1);
   scanf("%d",&p);
   if(p==1)
   { newnode->link=ptr;
     ptr=newnode;
     ctr++;
   }
   else
   { while(c<p-1)             
     {
	   temp = temp -> link;
	   c++;
     } 
   
   newnode->link=temp->link;
   temp->link=newnode;
   ctr++;
   }
   return ptr;
}

node* del(node*ptr)
{
      char ch; int p; int c=1; node *temp=ptr; node *temp1=ptr;
      printf("\nEnter the position of the element to be deleted. (Range:1-%d)",ctr+1);
      scanf("%d",&p);
      if(p>ctr)
      {
        printf("\ninvalid entry");
      }
      else
      {
      if(ptr!=NULL)
      
      if(p==1)
      {
       ptr=ptr->link;
       free(temp);
      }
      else
      {
        while(c<(p-2))    
        {
          temp1=temp->link;
          c++;
        }
        temp=temp1->link;
        temp1->link=temp->link;
        free(temp1);
        ctr--;
      }
      }
      return ptr;
}
}
        
      


	          
