#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct inventory
{
    char name[50];
    float money;
    struct inventory *next;
};
struct inventory *top = NULL;

void push(char pname[], float pmoney)
{
    struct inventory *newNode = (struct inventory*)malloc(sizeof(struct inventory));
    if(newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    strcpy(newNode->name, pname);
    newNode->money = pmoney;
    newNode->next = top;
    top = newNode;
}
void showinventory()
{
    struct inventory *ptr = top;

    printf("List of products:\n");
    while (ptr != NULL)
    {
        printf("Product name: %s . Product Price: %f \n",ptr->name, ptr->money);
        ptr= ptr->next;
    }
    
}

void deadstock()
{
    
}
int main()
{
    int option;
    char pname[50];
    float pmoney;
    while (1)
    {
        printf("Enter your option:\n1 for add your product \n2 for show the list\n");
        scanf("%d",&option);
        
        switch (option)
        {
        case 1:
                printf("Enter product name: ");
                scanf("%s", pname);
                printf("Enter product price: ");
                scanf("%f", &pmoney);
                push(pname, pmoney);
            break;
            
        case 2:
            showinventory();
            break;    
        
        default:
            break;
        }
    }
    return 0;
}