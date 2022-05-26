#include<stdio.h>
#include<stdlib.h>

typedef struct army
{
    int h;
    struct army *next;
    struct army *prev;
}
*node;


node createNode();


node insertAtEnd(node head);

node selection(node head);

main()
{
int i ,n;
node first=NULL;
scanf("%d",&n);
for(i=0;i<n;i++)
{

first = insertAtEnd(first);
}



selection(first);

}






node insertAtEnd(node head)
{
    node newNode;
    node temp;
    newNode = createNode();
    if(head == NULL)
    {
        head = newNode;
        head->next = NULL;
        head->prev=NULL;
        return head;
    }
    temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev=temp;

    newNode->next = NULL;
    return head;
}



node createNode()
{
    int data;

    scanf("%d",&data);
    node newNode;
    newNode = (node)malloc(sizeof(node));
    if(newNode == NULL)
    {
        printf("Node is Not Created !!\n");
    }
    newNode->h = data;
    newNode->next = NULL;
    newNode->prev=NULL;
    return newNode;
}






node selection(node head)
{
    node cur;
    int i;
    cur=head;
    if(cur==head)
    {
        if((cur->h)<((cur->next)->h)){
                if((cur->h)>=150)
            printf("\n%d",cur->h);
            i=i+1;
        }
    }
    cur=cur->next;
    while((cur->next)!=NULL)
    {
        if((cur->h)>((cur->prev)->h))
            {
            if((cur->h)<((cur->next)->h))
        {
            if((cur->h)>=150){
             printf("\t%d\t",cur->h);
             i=i+1;
            }
        }

        }
        cur=cur->next;

    }

    if((cur->h)>(cur->prev)->h)
    {
        if((cur->h)>=150){
      printf("\t%d\t",cur->h);
      i=i+1;
    }
    }
printf("\n%d",i);

}

