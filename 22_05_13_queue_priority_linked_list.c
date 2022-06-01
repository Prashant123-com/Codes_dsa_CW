
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int priority;
    int data;
    struct node *next;
};
typedef struct node *NODE;
NODE GetNode();
NODE Enqueue(NODE,int,int);
void display(NODE);
NODE Dequeue(NODE);
int main()
{

    int ele,ch,pr;
    NODE first=NULL;
    while(1)
    {
        printf("Enter your choice\n");
        printf("1:Enqueue \n2:Dequeue \n3:Display \n4:exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the Element\n");
                    scanf("%d",&ele);
                    printf("Enter the Priority\n");
                    scanf("%d",&pr);
                    first=Enqueue(first,ele,pr);
                    break;
            case 2: first=Dequeue(first);
                    break;
            case 3: display(first);
                    printf("\n");
                    break;
            case 4: exit(0);
                    break;
        }
}
}

NODE GetNode()
{

    NODE temp=malloc(sizeof(*temp));
    if(temp==NULL)
    {
        printf("memory not allocated\n");
        exit(0);

    }
    return temp;

}
NODE Enqueue(NODE first,int ele,int pr)
{
    NODE temp,q=NULL,p=first;
    temp=GetNode();
    temp->priority=pr;
    temp->data=ele;
    temp->next=NULL;

    if(first==NULL)
    {
        first=temp;
        return first;
    }
    else if(temp->priority<first->priority)
    {
        temp->next=first;
        first=temp;
        return first;
    }
    else
        {
        while(p!=NULL && temp->priority>p->priority)
        {

            q=p;
            p=p->next;
        }
            q->next=temp;
            temp->next=p;
            return first;

         }
}

void display(NODE first)
{
    NODE p=first;
    if(p==NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        while(p!=NULL)
        {
            printf("[%d - %d]\t",p->priority,p->data);
            p=p->next;
        }
}
}

NODE Dequeue(NODE first)
{
    if(first==NULL)
    {
        printf("Queue is empty\n");
        return first;

    }
    else
    {
        NODE t=first;
        first=first->next;
        printf("Deleted Element = %d & priority = %d\n",t->data,t->priority);
        free(t);
        return first;
    }
}
