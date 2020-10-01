#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>
#define new_node (struct stack_ll *)malloc(sizeof(struct stack_ll))

struct stack_ll
{
    int data;
    struct stack_ll *ptr;
};
struct stack_ll *top = NULL, *temp;

void push();
void pop();
void display();

void push()
{
    if (top == NULL)
    {
        top = new_node;
        printf("\nEnter data -");
        scanf("%d", &top->data);
        top->ptr = NULL;
    }
    else
    {
        temp = new_node;
        printf("\nEnter data - ");
        scanf("%d", &temp->data);
        temp->ptr = top;
        top = temp;
    }
}

void pop()
{
    if(top == NULL)
    {
        printf("\nUNDERFLOW");
    }
    else{
        temp = top;
        printf("\n%d is deleted", temp->data);
        top = top->ptr;
        free(temp);
    }
}

void display()
{
    temp = top;
    if (top == NULL)
    {
        printf("\nUNDERFLOW");
    }
    else
    {
        temp = top;
        while (temp != NULL)
        {
            printf("\t%d", temp->data);
            temp = temp->ptr;
        }
    }
}

int main()
{
    int choice;
    while (1)
    {
        system("cls");
        printf("\n=============");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\n=============");
        printf("\nEnter Choice - ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            getch();
            break;
        case 4:
            exit(0);
        default:
            printf("\nWrong choice...");
        }
    }
    return 0;
}