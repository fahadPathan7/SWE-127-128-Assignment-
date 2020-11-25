/*
Problem statement :
counting the number of changes and comparisons in a bubble sort.
*/

#include <stdio.h>

void bubble_sort(int a[],int n)
{
    int i,j,cnt1=0,cnt2=0,temp;

    for (i=0; i<n; i++)
    {
        for (j=0; j<n-i-1; j++)
        {
            cnt2++;
            if (a[j+1]<a[j])
            {
                temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
                cnt1++;
            }
        }
    }
    printf ("\nNumber of interchanges : %d\n",cnt1);
    printf ("Number of comparisons : %d\n",cnt2);
    printf ("The sorted array is : ");
    for (i=0; i<n; i++) printf ("%d ",a[i]);
}
int main()
{
    int n;

    printf ("Enter the size of the array : ");
    scanf ("%d",&n);
    int ar[n];

    printf ("Enter the elements : ");
    for (int i=0; i<n; i++)
    {
        scanf ("%d",&ar[i]);
    }
    bubble_sort(ar,n);
}
