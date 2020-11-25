/*
Problem statement:
String processing. (Substring, Indexing, Length, Insert, Delete, Replace, Concatenate).
*/

#include <stdio.h>
#include <string.h>


void rules()
{
    printf ("Rules:\n");
    printf ("-> Press 1 to find a substring.\n");
    printf ("-> Press 2 to find the starting index of a substring.\n");
    printf ("-> Press 3 to find the length of a string.\n");
    printf ("-> Press 4 for inserting.\n");
    printf ("-> Press 5 for deleting.\n");
    printf ("-> Press 6 for replacing.\n");
    printf ("-> Press 7 for concatenating.\n");
    printf ("-> Press -1 to quit.\n\n");
}
void substring (char s[], int start,int len)
{
    int i;
    printf ("The substring is: ");
    for (i=start; i<start+len; i++) printf ("%c",s[i]);
    printf ("\n\n");
}
int indexing (char s[],char p[])
{
    int r=-1;
    int l1=strlen(s),l2=strlen(p);
    for (int i=0; i< l1; i++)
    {
        int count=0,idx=0;
        if (s[i]==p[0])
        {
            for (int j=i; j<i+l2; j++) // checking the rest of the elements
            {
                if (s[j]==p[idx++])
                {
                    count++;
                }
                else break;
            }
            if (count==l2)
            {
                r=i;
                break;
            }
        }
    }
    return r;
}
void length (char s[])
{
    int l;
    l=strlen(s);
    printf("Length of the string is: %d\n\n",l);
}
void insert (char s[],char p[], int idx)
{
    char temp[1000];
    int i,j;
    for (i=0; i<idx; i++) temp[i]=s[i]; 
    for (j=0; j<strlen(p); j++) temp[i++]=p[j]; 
    for (j=idx; j<strlen(s); j++) temp[i++]=s[j];
    strcpy(s,temp);
    printf ("After inserting, the string is : %s\n\n",s);
}
void delete (char s[],int idx, int len)
{
    char temp[500];
    int i,j;
    for (i=0; i<idx; i++) temp[i]=s[i];
    for (j=idx+len; j<strlen(s); j++) temp[i++]=s[j];
    strcpy(s,temp);
    printf ("After deleting, the string is : %s\n\n",s);
}
void replace (char s[], char t1[], char t2[])
{
    char temp[500];
    int i,j,idx;
    idx = indexing(s,t1);
    if (idx==-1)
    {
        printf ("Pattern 1 is not found.\n\n");
    }
    else 
    {
        for (i=0; i<idx; i++) temp[i]=s[i];
        for (j=0; j<strlen(t2); j++) temp[i++]=t2[j];
        for (j=idx+strlen(t1); j<strlen(s); j++) temp[i++]=s[j];
        strcpy(s,temp);
        printf("After replacing, the string is : %s\n\n",s);
    }
}
void concatenate(char s1[],char s2[])
{
    strcat(s1,s2);
    printf ("After concatenating, the string is : %s\n\n",s1);
}
int main()
{
    int n;

    rules();
    while (1)
    {
        printf ("Enter your choice: ");
        scanf("%d",&n);
        getchar();

        if (n==1)
        {
            char s[500];
            int start,len;
            printf ("Enter the string: ");
            gets(s);
            printf ("Enter starting index: ");
            scanf ("%d",&start);
            printf("Enter the length of the substring: ");
            scanf ("%d",&len);

            substring(s,start,len);
        }
        else if (n==2)
        {
            char s[500],p[100];
            printf ("Enter the string: ");
            gets(s);
            printf ("Enter the pattern: ");
            gets(p);

            int r=indexing(s,p);
            if (r!=-1) printf ("Starting index of the pattern is : %d\n\n",r);
            else printf ("Not found.\n\n");
        }
        else if (n==3)
        {
            char s[500];
            printf ("Enter the string: ");
            gets(s);

            length(s);
        }
        else if (n==4)
        {
            char s[500],t[500];
            int idx;
            printf ("Enter the String: ");
            gets(s);
            printf ("Enter the new string: ");
            gets(t);
            printf ("Enter the index (where to add the new string): ");
            scanf ("%d",&idx);

            insert(s,t,idx);
        }
        else if (n==5)
        {
            char s[500];
            int idx,len;
            printf("Enter the string: ");
            gets(s);
            printf ("Enter the starting index: ");
            scanf ("%d",&idx);
            printf ("Enter length: ");
            scanf ("%d",&len);

            delete(s,idx,len);
        }
        else if (n==6)
        {
            char s[500],t1[100],t2[100];
            printf ("Enter the string: ");
            gets (s);
            printf ("Enter the first pattern: ");
            gets(t1);
            printf ("Enter the second pattern: ");
            gets(t2);

            replace (s,t1,t2);
        }
        else if (n==7)
        {
            char s1[500],s2[500];
            printf ("Enter the first string: ");
            gets(s1);
            printf ("Enter the second string: ");
            gets(s2);

            concatenate(s1,s2);
        }
        else if (n==0)
        {
            rules();
        }
        else if (n==-1)
        {
            printf("Thank You.\n\n");
            break;
        }
        else
        {
            printf ("Invalid operation. Press 0 to read the instructions again.\n");
        } 
    }
}
