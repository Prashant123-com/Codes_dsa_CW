#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct option
{
	char m_name[20];

	int year;
	struct option *next;

}
*opt;


opt getnode()
{
    opt temp;
    temp=(opt)malloc(sizeof(struct option));
temp->next=NULL;
return temp;
}
opt read()
{
    opt temp;
    temp=getnode();
    printf("\nenter info\n1.Movie_name\n2.Year\n");
    scanf("%s%d",temp->m_name,&temp->year);
    return temp;


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
    printf("s.No\tm_name\tYear\n");
    while(c!=NULL)
	{
		printf("%d\t%s\t\t%d\n",i,c->m_name,c->year);
		c= c->next;
		i++;
	}
	printf("\n");


}

opt ins_end(opt head)
{
    opt h,c;
    h=read();
    h->next=NULL;
    if(head==NULL)
    {
        head=h;
        return head;
    }
    else {
        c=head;
            while(c->next!=NULL)
            {
                c=c->next;
            }
    c->next=h;
    return head;

}



}





void search(opt head)

{



    int flag = 0,h,c=0;

    printf("Enter year\n");


    scanf("%d",&h);

    opt cur = head;


    if(head == NULL)

    {

        printf("List is empty\n");

    }

    else

    {

        while(cur!= NULL)

        {

            if(cur->year==h)

            {

                flag = 1;
                printf("%s\t\t%d\n",cur->m_name,cur->year);
                c++;



            }

            cur = cur-> next;


        }

        if(flag==0)

          {

           printf("No details found");
            exit(0);
          }
          printf("Total number of movies in that year=%d\n",c);

    }

}





opt del_a(opt head)
{
    opt c,h,prev;
    c=head;
    int n,i=1;
    printf("Enter where u want to delete\n");
    scanf("%d",&n);

        if(i==n)
        {

            head=head->next;
            c->next=NULL;
            free(c);
            return head;
        }
        for(i=1;i<n;i++)
    {
        prev=c;
        c=c->next;
    }

    h=c->next;
    prev->next=h;
    free(c);
    return head;
}













int main()
{
    opt ne=NULL;



    int n;
    while(1)
    {
        printf("enter choice\n1.Insert\n2.Dispaly\n3.Search \n4.Delete at a particular position\n");
        scanf("%d",&n);

    switch(n)
    {
    case 1:ne=ins_end(ne);
break;
case 2:display(ne);
break;
case 3:
search(ne);
    break;
case 4:ne=del_a(ne);
break;


    }
    }
}

