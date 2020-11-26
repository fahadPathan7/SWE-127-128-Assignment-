/*
problem statement :
print the steps of binary search.
*/

#include <stdio.h>

int Binary_search(int ar[],int n, int v)
{
    int i,j,start=0,end=n-1,mid=(start+end)/2,count = 1;

    printf("\n");
    while (start<=end)
    {
        printf ("step %d : start = %d. end = %d. mid = %d.\n",count,ar[start],ar[end],ar[mid]);
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
        count++;
    }
    return -1;
}
int main()
{
    int n,i,v;

    printf ("Enter the size of the array : ");
    scanf ("%d",&n);
    int ar[n];

    printf ("Enter the elements (ascending order) : ");
    for (i=0; i<n; i++)
    {
        scanf ("%d",&ar[i]);
    }
    printf ("Enter the value which you want to search : ");
    scanf ("%d",&v);

    int index = Binary_search(ar,n,v);
    if (index==-1)
    {
        printf ("\nThe value is not found\n");
    }
    else
    {
        printf("\nIndex of %d is %d\n\n",v,index);
    }
    
}
