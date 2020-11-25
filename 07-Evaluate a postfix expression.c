/*
Problem statement: 
Evaluate a postfix expression.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void push_op(int Stack[], int *top, int item)  // for puhing any element in the stack
{
    *top += 1;
    Stack[*top] = item;

    return;
}
int pop_op(int Stack[], int *top) // for popping top element from the stack
{
    int a;
    a = Stack[*top];
    *top -= 1;

    return a; // returning the top element of the stack
}

int main()
{
    int a, b, i, size, top = 0, item, j = 0;
    int Stack[500];
    char ch, temp[100];

    printf("Enter the arithmetic expression (postfix) : ");
    while (1)
    {
        scanf("%c", &ch); // inserting the elements from the user

        if (ch == ')') // checking the end of the expression.
        {
            break;
        }
        else if (ch == '*' || ch == '/' || ch == '+' || ch == '-') // checking for operator
        {
            a = pop_op(Stack, &top); // popping the last element of the stack
            b = pop_op(Stack, &top); // popping the second last element of the stack

            if (ch == '*')  // doing operation according to the operator
            {
                item = b * a;
            }
            else if (ch == '/')
            {
                item = b / a;
            }
            else if (ch == '+')
            {
                item = b + a;
            }
            else
            {
                item = b - a;
            }

            push_op(Stack, &top, item); // pushing the new value after the operation
        }
        else if (ch != ',') // inserting the digits of an operand to a temporary array
        {
            temp[j++] = ch;
        }
        else // after inserting all the digits of an operand , I converted it to an integer
        {
            if (j != 0)
            {
                char temp1[j];
                for (int k = 0; k < j; k++)
                {
                    temp1[k] = temp[k]; // inserting the elements of the temporary array to another array for integer conversion
                }
                item = atoi(temp1); // converting the temporary array to integer format
                push_op(Stack, &top, item); // pushing the integer value to the stack
            }
            j = 0;
        }
    }

    int value = Stack[top];
    printf("\nThe result is : %d\n\n", value); // printing the result of the arithmetic expression
}
