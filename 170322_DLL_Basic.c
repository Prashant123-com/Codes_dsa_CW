#include<stdio.h>
#include<stdlib.h>
#include<string.h>




struct playlist
{
	int data;

	struct playlist *next;
	struct playlist *prev;
};
typedef struct playlist *NODE;






NODE DLLgetNewNode()
 {
	NODE newNode = (NODE)malloc(sizeof(struct playlist));
	if(newNode==NULL)
	{
		printf("Song not created\n");
		exit(0);
	}
	printf("\nEnter data\n");


	scanf("%d",&newNode->data);

	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}


NODE DLLinsertAtFront(NODE head)
{
	NODE newNode = DLLgetNewNode();

	if(head == NULL)
	{
		head = newNode ;
  		return head ;
	}
head->prev = newNode ;
	newNode ->next = head;

	head = newNode ;
	return head;
}




NODE DLLinsertAtEnd(NODE head)
{
	NODE newNode = DLLgetNewNode();
	if(head == NULL)
	{

 	head = newNode;
 	return head;
	}
	else
	{ 	NODE cur = head;
		while(cur -> next != NULL)
			{
			cur = cur -> next;
			}
	cur -> next = newNode;
	newNode -> prev = cur;
	return head;
	}
}

NODE DLLinsertat(NODE head, int n)
{

	NODE newNode = DLLgetNewNode();
	NODE temp;
	temp=head;
	int i;
	for(i=1;i<n-1;i++)
    {

        temp=temp->next;
    }
	newNode->next=temp->next;
	newNode->prev=temp;
	(temp->next)->prev=newNode;
	temp->next=newNode;

		return head;



}


void DLLdisplayPlaylist(NODE head)
{
	NODE temp = head;
	if(head == NULL)
		printf("\nList is Empty!!!");
	else
	{
		printf("\nList elements are: \n");
		while(temp != NULL)
		{
		  printf("%d\t", temp->data);
		temp = temp->next;
		}
	}
}


NODE DLLdeletefront(NODE head)
{

    if(head==NULL)
    {
        printf("List is empty\n");
        return 0;
    }

    (head->next)->prev=NULL;
    head=head->next;


}


NODE DLLdeleteend(NODE head)
{
NODE t;
t=head;
    if(head==NULL)
    {
        printf("List is empty\n");
        return 0;
    }

while(t->next!=NULL)
{
    t=t->next;
}
(t->prev)->next=NULL;
return head;


}



NODE DLLinsertAfter(NODE head, int n)
{

	NODE newNode = DLLgetNewNode();
	NODE temp;
	temp=head;
	int i;
	for(i=1;i<n-1;i++)
    {

        temp=temp->next;
    }
	newNode->next=temp->next;
	newNode->prev=temp;
	(temp->next)->prev=newNode;
	temp->next=newNode;

		return head;



}




NODE DLLdeletespec(NODE head,int n)
{


	NODE temp;
	temp=head;
	int i;
	for(i=1;i<n-1;i++)
    {

        temp=temp->next;
    }
    temp=temp->next;
    if(temp->next!=NULL)
    {
    (temp->next)->prev=temp->prev;
    (temp->prev)->next=temp->next;
    }
    else{

        (temp->prev)->next=NULL;
    }
return head;

}


























int main()
{
    int choice=0,n;

    NODE head=NULL;
    while(1)
    {

	printf("\nMenu:\n====================\n");
	printf("\n1.Insert data at the beginning\n");
	printf("\n2.Insert dats at the end\n");
	printf("\n3.Insert at specific\n");
	printf("\n4.Display list\n");
	printf("\n5.Delete data at the beginning\n");
	printf("\n6.Delete data at the end\n");

    	scanf("%d",&choice);


switch(choice)
        {
            case 1: head=DLLinsertAtFront(head);
                    break;
            case 2: head=DLLinsertAtEnd(head);
                    break;
           case 3: printf("Enter place at which new data has to inserted\n ");
                    scanf("%d",&n);
                    head=DLLinsertat(head,n);
                    break;
            case 4: DLLdisplayPlaylist(head);
                    break;
            case 5: head=DLLdeletefront(head);
                    break;
            case 6: head=DLLdeleteend(head);
                    break;

                case 7:    printf("Enter place at which data has to deleted\n ");
                    scanf("%d",&n);
                     head=DLLdeletespec(head,n);
                    break;



        }
    }

    return 0;
}




















