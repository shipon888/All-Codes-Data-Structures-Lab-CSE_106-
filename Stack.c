#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 101
int a[MAX_SIZE];
int top = -1;

bool isFull()
{
    if (top == MAX_SIZE - 1)
    {
        printf("Error: stack overflow.\n");
        return true;
    }
    else
        return false;
}
bool isEmpty()
{
    if (top == -1)
    {
        printf("Error: stack empty.\n");
        return true;
    }
    else
        return false;
}

void Push(int x)
{
    if (top == MAX_SIZE - 1)
    {
        printf("Error: stack overflow.\n");
        return;
    }
    a[++top] = x;
}
void Pop()
{
    if (top == -1)
    {
        printf("Error: stack empty.\n");
        return;
    }

    top--;
}
int Top()
{
    return a[top];
}

void Print()
{
    printf("Stack: ");
    for (int i = 0; i <= top; i++)
        printf("%d ", a[i]);

    printf("\n");
}
int main()
{
    Pop();
    Push(2);
    Print();
    Push(5);
    Print();
    Push(10);
    Print();
    Pop();
    Print();
    Push(12);
    Print();

    return 0;
}
