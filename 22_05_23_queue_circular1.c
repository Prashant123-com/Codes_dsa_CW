#include <stdio.h>
#include<stdlib.h>
#define SIZE 5
struct queue
{
    int front;
    int rear;
    int items[SIZE];
};
typedef struct queue Queue;
int IsFULL(Queue);
int IsEmpty(Queue);
void Enqueue(Queue *,int);
int Dequeue(Queue *);
void display(Queue );
Queue CreateQueue();
Queue CreateQueue()
{
    Queue Q;
    Q.rear = SIZE-1;
    Q.front = SIZE-1;
    return Q;
}
int IsFULL(Queue Q)
{
    if(((Q.rear + 1)%SIZE==Q.front) )
        return 1;
    else
        return 0;
}

int IsEmpty(Queue Q)
{
    if(Q.rear == Q.front)
        return 1;
    else
        return 0;
}

void Enqueue(Queue *Q,int element)

{

    if(IsFULL(*Q))

        printf("\n Queue is full!! \n");

    else

    {
        Q->rear = (Q->rear + 1) % SIZE;
        Q->items[Q->rear] = element;
    }

}

int Dequeue(Queue *Q)

{
    int element;

    if(IsEmpty(*Q)) {

        printf("\n Queue is empty !! \n");

        return(-1);

    } else {

        Q->front = (Q->front + 1) % SIZE;
        element = Q->items[Q->front];
        return(element);
    }
}
void display(Queue Q)
{
    int i;
    if(IsEmpty(Q))
        printf(" \n Empty Queue\n");
    else
    {
       printf("\n Items -> ");
        for( i = (Q.front+1)%SIZE; i!=Q.rear; i=(i+1)%SIZE) {
            printf("%d ",Q.items[i]);
        }
        printf("%d \n",Q.items[i]);
    }
}

int main()

{
    int i,ch,n,item,x;
    Queue Q;



   Q=CreateQueue();

   while(1)

   {
        printf("1-Insert\n2-Remove Element\n3-Display\n4-Exit\n");
        printf("Enter Choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the element to be inserted\n");
                    scanf("%d",&item);
                    Enqueue(&Q,item);
                    break;

            case 2:x=Dequeue(&Q);
                    if(x!=-1)
                        {
                        printf("Removed Element is = %d\n",x);
                        }
                    break;
            case 3: display(Q);
                    break;
            case 4: exit(0);
                    break;
        }
    }
    return 0;
}
