
#include<stdio.h>
#include<stdlib.h>
typedef struct opt
{

	int data;
	struct opt *next;

}
*opt;

opt getopt()
{
    opt c;
    c=(opt)malloc(sizeof(struct opt));
    if(c==NULL)
    {
        printf("\nLIST NOT CREATED\n");
        return;
    }
    c->next=NULL;
        return c;
}


opt read()
{
    opt temp;
    temp= getopt();
    printf("ENTER\nData\n");
    scanf("%d",&temp->data);
    return temp;
}




opt insert_end(opt head)
{
    opt h,c;



	h=read();
		h ->next = NULL;
	if(head==NULL)
	  return h;
	c=head;
	while(c->next !=NULL)
	{
		c=c->next;
	}
	c->next = h;
	return head;


}


void display(opt head)
{
    int i=1;
    opt c;
     if(head==NULL)
    {
        printf("\nTHE LIST IS EMPTY!\n");
        return;
    }
    c=head;
    printf("List is\n");
    while(c!=NULL)
	{
		printf("%d\t",c->data);
		c= c->next;
		i++;
	}
	printf("\n");


}




opt swap(opt head)
{
    opt t;
    t=head;
    int d;

    while(t->next!=NULL)
    {

        d=t->data;
        t->data=(t->next)->data;
        (t->next)->data=d;


        t=(t->next)->next;
        if(t==NULL)
        {
            return head;
        }


    }


return head;


}






















main()
{

    int n,i;
    opt head=NULL;
while(1)
    {
        printf("Enter your choice : \n1.Insert\n2.Display\n3.Swap\n");
        scanf("%d",&n);

        switch(n)
        {
            case 1:

                head=insert_end(head);
                break;
            case 2:
                display(head);
                break;
                case 3:
                head=swap(head);


                break;


            case 8:
                    exit(1);
                    break;

        }
    }
}
