#include<stdio.h>
#include<stdlib.h>
typedef struct tree{
int data;
struct tree *right;
struct tree *left;

}*node;



node DLLgetNewNode()
 {
	node newNode = (node)malloc(sizeof(struct tree));
	if(newNode==NULL)
	{
		printf("Song not created\n");
		exit(0);
	}
	printf("\nEnter details:\n");


	scanf("%d", &newNode->data);


	newNode->right = NULL;
	newNode->left = NULL;
	return newNode;
}








node ins(node head)
{

	if(head == NULL)
	{
node newNode = DLLgetNewNode();
 	head = newNode;
 	return head;
	}



	else
	{ 	NODE cur = head;
	int a;
	printf("Enter data\n");
	scanf("%d",&a);

       if((cur->data)>a);
       {

       }
		while(cur -> next != NULL)
			{
			cur = cur -> next;
			}
	cur -> next = newNode;
	newNode -> previous = cur;
	return head;
	}
}








main()
{
    node head;
    head=NULL;

    int a;
    scanf("%d",&a);
    switch(a){
case 1:
    head=ins(head);


    }

}
