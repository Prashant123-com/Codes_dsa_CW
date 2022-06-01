#include<stdio.h>
#include<stdlib.h>

struct books
{
	int num_exe[25];
	char book_name[25];

};
typedef struct books STK;

int full(STK );
int empty(STK );
void PUSH(STK *,int );
int POP(STK *);

void main()
{
	STK s[100000];
	int ch,n,i;

		scanf("%d",&ch);
for(i=0;i<ch;i++)
{


                    scanf("%d",&n);

                    if(n!=-1){
                    PUSH(s,n);
                    }
                    else {
                            s.top=POP(&s);
                    }
}

}
int full(STK s)
{
	if(s.top==25-1)
		return 1;
	else
		return 0;
}

int empty(STK s)
{
	if(s.top==-1)
		return 1;
	else
		return 0;
}

void PUSH(STK *s,int num)
{
    char k[15];
	if(full(*s))
	{
		//printf("\nStack Overflow!!");

	}
	else
    {
        s->top++;
        scanf("%s",k);
        strcpy(s->book_name[s->top],k);
        s->num_exe[s->top]=num;
    }
}

int POP(STK *s)
{
	int min,i;

	if(empty(*s))
	{
		//printf("\nStack Underflow");

	}
	else
        min=s->num_exe[s->top];


        while(s->top!=-1){

    if(min>s->num_exe[s->top])
    {
        min=s->num_exe[s->top];

    }
     s->top--;
    }

            printf("%d %s",s->num_exe[min],s->book_name[min]);
    s->top=min;
        return s->top;


}




