//Name-SRISHTI
//ADD TO POLYNOMIAL
//1905647
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
    int coeff;
    int exp;
    struct node *next;
} *start1=NULL,*start2=NULL,*start3=NULL;

void createlist(struct node **st,int c,int ex)
{
    struct node *temp;
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->coeff=c;
    new->exp=ex;
    new->next = NULL;
    if (*st==NULL)
    {
        *st=new;
    }
    else
    {
        temp=*st;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=new;
    }
    
}

void traverse(struct node **st)
{
    struct node*t;
    t=*st;
    while(t!=NULL)
    {
        printf("Exponents=%d,coefficient=%d\n",t->exp,t->coeff);
        t=t->next;
    }
    
}

void addpoly(struct node** start1,struct node **start2,struct node **start3)
{
    struct node *t1,*t2;
    struct node *new=(struct node *)malloc(sizeof(struct node));
    t1=*start1;
    t2=*start2;

    while(t1!=NULL  &&  t2!=NULL)
    {
        if(t1->exp>t2->exp)
        {
            createlist(start3,t1->coeff,t1->exp);
            t1=t1->next;
        }
        else if (t1->exp<t2->exp)
        {
            createlist(start3,t2->exp,t2->coeff);
            t2=t2->next;
        }
        else
        {
            if((t1->coeff + t2->coeff)!=0)
            {
                createlist(start3,t1->exp,t1->coeff + t2->coeff);
                t1=t1->next;
                t2=t2->next;
           }
        }
         
    }    
        
    while(t1!=NULL)
    {
        createlist(start3,t1->exp,t1->coeff);
        t1=t1->next;
    }
    while(t2!=NULL)
    {
        createlist(start3,t2->exp,t2->coeff);
        t2=t2->next;
    }
        
}

int main()
{
    while(1)
    {
        printf("Menu Driven\n");
        printf("Option 1: Creating a new node for linked list 1\n");
	    printf("Option 2: Display the first linked list\n");
	    printf("Option 3: Creating a new node for linked list 2\n");
	    printf("Option 4: Display the second linked list\n");
        printf("Option 5: AddPoly\n");
        printf("Option 6: Display the polyadd linked list\n");
        printf("Option 7: Exist\n");

        
        int ch,c1,c2,ex1,ex2;
        printf("Enter your choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: 
                printf("Enter the coefficient and exponents for the new node of the linked list\n");
                scanf("%d%d",&c1,&ex1);
                createlist(&start1,c1,ex1);
                break;
            case 2: 
                traverse(&start1);
                break;
            case 3:
                printf("Enter the coefficient and exponents for the new node of the linked list\n");
                scanf("%d%d",&c2,&ex2);
                createlist(&start2,c2,ex2);
                break;
            case 4: 
                traverse(&start2);
                break;
            case 5:
                addpoly(&start1,&start2,&start3);
                break;
            case 6:
                traverse(&start3);
                break;
            case 7:exit(1);
		    default:printf("Invalid choice\n");
            }
           
    }
    return 0;
}
