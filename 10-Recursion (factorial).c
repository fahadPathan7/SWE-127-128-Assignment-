/*
Problem statement:
factorial calculation (using recursion)
*/

#include <stdio.h>

int factorial(long long int fact,long long int n)
{
    if (n==0)
    {
        fact=1;
        return fact;
    }
    fact = factorial(fact,n-1);
    fact=n*fact;
    return fact;
}
int main()
{
    long long int n,r,i,j;

    printf ("Enter the value of n: ");
    scanf ("%lld",&n);

    r = factorial(1,n);
    printf ("\nValue of %lld! is: %lld\n\n",n,r);
}
