/*
Problem statement :
Binary search code.
*/
#include <stdio.h>

int Binary_search(int ar[],int n, int v)
{
    int i,j,start=0,end=n-1,mid=(start+end)/2;

    while (start<=end)
    {
        if (ar[mid]<v)
        {
            start=mid+1;
        }
        else if (ar[mid]>v)
        {
            end=mid-1;
        }
        else
        {
            return mid;
        }
        mid=(start+end)/2;
    }
    return -1;
}
int main()
{
    int n,i,val;

    printf ("Enter the size of the array : ");
    scanf ("%d",&n);
    int ar[n];

    printf ("Enter the elements (ascending order) : ");
    for (i=0; i<n; i++)
    {
        scanf ("%d",&ar[i]);
    }
    printf ("Enter the value which you want to search : ");
    scanf ("%d",&val);

    int index = Binary_search(ar,n,val);
    if (index==-1)
    {
        printf ("\nThe value is not found\n");
    }
    else
    {
        printf("\nIndex of %d is %d\n",val,index);
    }

}
