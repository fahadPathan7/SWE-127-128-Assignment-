/*
Problem statement :
Input a data set. sort the data. insert some data. delete some data.
*/

#include <stdio.h>

int ar[10000];

void sort_data(int n)
{
    int i, j, item;

    for (i = 1; i < n; i++)
    {
        item = ar[i];
        j = i - 1;

        while (j >= 0 && ar[j] > item)
        {
            ar[j + 1] = ar[j];
            j--;
        }
        ar[j + 1] = item;
    }
}

void insert_data(int v, int n)
{
    int i, j, item;

    for (i = 1; i < n; i++)
    {
        item = ar[i];
        j = i - 1;

        while (j >= 0 && ar[j] > item)
        {
            ar[j + 1] = ar[j];
            j--;
        }
        ar[j + 1] = item;
    }
}

int search_data(int v, int n)
{
    int sidx = 0, fidx = n - 1, midx;

    while (sidx <= fidx)
    {
        midx = sidx + (fidx - sidx) / 2;

        if (ar[midx] > v)
        {
            fidx = midx - 1;
        }
        else if (ar[midx] < v)
        {
            sidx = midx + 1;
        }
        else
        {
            return midx;
        }
    }
    return -1;
}

void delete_data(int v, int n, int idx)
{
    int i;
    for (i = idx + 1; i < n; i++)
    {
        ar[i - 1] = ar[i];
    }
}

int main()
{
    int i, j, n, v, o, f;

    printf("Enter the size of the array : ");
    scanf("%d", &n);

    printf("Enter the array : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &ar[i]);
    }
    sort_data(n);

    printf("\nRules :\n-> If you want to insert a value type 1.\n-> If you want to delete a value type 2.\n-> When you are finished type -1.\n\n");
    while (1)
    {
        printf("Type your choice : ");
        scanf("%d", &o);

        if (o == 1)
        {
            printf("Enter the value : ");
            scanf("%d", &v);
            ar[n] = v;
            insert_data(v, n + 1);
            n+=1;
            printf("Value inserted successfully.\n\n");
        }
        else if (o == 2)
        {
            printf("Enter the value : ");
            scanf("%d", &v);
            f = search_data(v, n);
            if (f == -1)
            {
                printf("The data is not found in the array.\n\n");
            }
            else
            {
                delete_data(v, n, f);
                n -= 1;
                printf("Value deleted successfully.\n\n");
            }
        }
        else
        {
            break;
        }
    }

    printf("The modified array is : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", ar[i]);
    }
}
