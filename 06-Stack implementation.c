/*
Problem statement:
Push and pop operation of stack.
*/

#include <stdio.h>

void push_op (int stac_k[],int *top,int max,int item)
{
    if (*top==max)
    {
        printf ("Overflow.\n\n");
        return;
    }

    *top+=1;
    stac_k[*top]=item;
    printf("Push operation successful.\n\n");

    return;
}
void pop_op (int stac_k[], int *top)
{
    if (*top==0)
    {
        printf ("Underflow.\n\n");
        return;
    }

    printf("Successfully popped %d from the stack.\n\n",stac_k[*top]);
    *top-=1;

    return;
}
int main()
{

    int top=0,max,item,i,j,c;

    printf ("Enter the max size of stack : ");
    scanf ("%d",&max);
    int stac_k[max];
    
    printf ("\nRules :\n-> Type 1 for push operation.\n-> Type 2 for pop operation.\n-> Type 0 to exit.\n\n");

    while (1)
    {
        printf ("Your choice : ");
        scanf ("%d",&c);

        if (c==0)
        {
            printf ("\nThank you.\n\n");
            break;
        }
        else if (c==1)
        {
            printf ("Enter item : ");
            scanf ("%d",&item);

            push_op(stac_k,&top,max,item);
        }
        else
        {
            pop_op(stac_k,&top);
        }
        
    }
}
