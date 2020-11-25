/*
Problem statement:
convert a infix expression to postfix expression.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void push_op(char stack[], int *top, char ch)
{
    *top += 1;
    stack[*top] = ch;
}
char pop_op(char stack[], int *top)
{
    char ch;
    ch = stack[*top];
    *top -= 1;

    return ch;
}
int operator(char ch)
{
    if (ch == '^' || ch == '*' || ch == '/' || ch == '+' || ch == '-')
    {
        return 1;
    }
    return 0;
}
int operator_val(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;

    return 0;
}
int main()
{
    char stack[500], q[500], p[500];
    int i, j, top = 0, p_idx = 0;

    push_op(stack, &top, '(');
    printf("Enter the infix expression (no space): ");
    gets(q);

    strcat(q, ")");

    for (i = 0; i < strlen(q); i++)
    {
        char ch = q[i];
        if (isdigit(ch))
        {
            p[p_idx++] = ch;
        }
        else if (ch == '(')
        {
            push_op(stack, &top, ch);
        }
        else if (operator(ch) == 1)
        {
            char temp;
            temp = pop_op(stack, &top);
            while (operator(temp) == 1 && operator_val(temp) >= operator_val(ch) && top > 0)
            {
                p[p_idx++] = temp;
                temp = pop_op(stack, &top);
            }
            push_op(stack, &top, temp);
            push_op(stack, &top, ch);
        }
        else if (ch == ')')
        {
            char temp;
            temp = pop_op(stack, &top);
            while (temp != '(')
            {
                p[p_idx++] = temp;
                temp = pop_op(stack, &top);
            }
        }
    }
    printf ("The postfix expression is: ");
    for (i = 0; i < p_idx; i++)
    {
        printf("%c", p[i]);
    }
}
