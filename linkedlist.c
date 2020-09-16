//Name-SRISHTI
//LINKED LIST OPERATION
//1905647
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
    int data;
    struct node* link;
};

struct node* root = NULL;
int len;
void append(void);
void addatbegin(void);
void addatafter(void);
int length(void);
void Display(void);
void Delete(void);
void reverse(void);
void sort(void);

void main()
{
    int ch;
    while(1)
    {
        printf("Single Linked List operation:\n");
        printf("1.Append \n");//add a node at the end 
        printf("2.Add at begin:\n");
        printf("3.Add at after:\n");
        printf("4.Length:\n");
        printf("5.Display:\n");
        printf("6.Delete:\n");
        printf("7.reverse\n");
        printf("8.sort\n");
        printf("9.Quit\n");


        printf("Enter your choice:\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: append();
            break;
            case 2: addatbegin();
            break;
            case 3: addatafter();
            break;
            case 4: len=length();
            printf("Length: %d\n",len);
            break;
            case 5: Display();
            break;
            case 6: Delete();
            break;
            case 7: reverse();
            break;
            case 8: sort();
            break;
            case 9: exit(1);
            default: printf("Invalid choice\n");

        }
    }

}  

void append()
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter node data:\n");//how to read a information 
    scanf("%d",&temp->data);
    temp->link = NULL;

    if(root == NULL)// list is empty
    {
        root=temp;
    }
    else
    {
        //insert an remaining node
        struct node* p;//local variable
        p=root;


        while(p->link!=NULL)
        {
            p=p->link;
        }
        p->link=temp;
    }
    
}

int length()
{
    int count=0;
    struct node* temp;
    temp=root;
    while(temp!=NULL)
    {
        count++;
        temp=temp->link;
    }
    return count;
}



void Display()
{
    struct node*temp;
    temp=root;
    if(temp==NULL)
    {
        printf("List is Empty\n\n");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d-->",temp->data);
            temp=temp->link;
        }
        printf("\n\n");
    }
    
}

void addatbegin()
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter node data:\n");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(root == NULL)
    {
        root = temp;
    }
    else
    {
        temp->link= root;
        root=temp;
    }
    
}



void addatafter(void)
{
    struct node* temp,*p;
    int loc,len;
    int i=1;
    printf("Enter location:\n");
    scanf("%d",&loc);
    len=length();
    if(loc>len)
    {
        printf("Invalid Location\n");  
        printf("Currently list is having %d node",len);
    }
    else
    {
        p=root;
        while(i<loc)
        {
            p=p->link;
            i++;
        }
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data:\n");
        scanf("%d",&temp->data);
        temp->link=NULL;
        temp->link=p->link;
        p->link=temp;
    }
    

}

void Delete(void)
{
    struct node*temp;
    int loc;
    printf("Enter the location to delete\n");
    scanf("%d",&loc);
    if(loc>length())
    {
        printf("Invalid location\n");
    }
    else if (loc==1)
    {
        temp=root;
        root=temp->link;
        temp->link=NULL;
        free(temp);
    }
    else
    {
        struct node*p=root,*q;
        int i=1;
        while(i<loc-1)
        {
            p=p->link;
            i++;

        }
         q=p->link;
         p->link=q->link;
         q->link=NULL;
         free(q);
        
    }
   
    

}

void reverse(void)
{
    struct node*p=NULL;
    struct node*t1=root;
    struct node*t2;
    while(t1!=NULL)
    {
        t2=t1->link;
        t1->link=p;
        p=t1;
        t1=t2;
    }
    root=p;
    Display();

}

void sort(void)
{
    struct node*current=root;
    struct node*p=NULL;
    int temp;

    if(root==NULL)
    {
        return;
    }
    else
    {
        while(current!=NULL)
        {
            p=current->link;

            while(p!=NULL)
          {
            if(current->data>p->data)
            {
                temp=current->data;
                current->data=p->data;
                p->data=temp;
            }
            p=p->link;
          }
           current=current->link;
         
        }
        
    }
    printf("Sorted list:\n");
    Display();

    
}
    

