#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct inventory
{
    char name[50];
    int quantity; 
    struct inventory *next;
};
struct inventory *top = NULL;

void push(char pname[], int pquantity)
{
    struct inventory *newNode = (struct inventory*)malloc(sizeof(struct inventory));
    strcpy(newNode->name, pname);
    newNode->quantity = pquantity;
    newNode->next = top;
    top = newNode;
}

void showinventory()
{
    struct inventory *ptr = top;

    printf("List of products:\n");
    while (ptr != NULL)
    {
        printf("Product name: %s . Quantity: %d\n", ptr->name, ptr->quantity);
        ptr = ptr->next;
    }
}

void deadstock()
{
    struct inventory *ptr = top;
    int deadStockFound = 0;

    printf("Dead Stock:\n");
    while (ptr != NULL)
    {
        if (ptr->quantity == 0)
        {
            printf("Product name: %s\n", ptr->name);
            deadStockFound = 1;
        }
        ptr = ptr->next;
    }

    if (!deadStockFound)
    {
        printf("No dead stock found.\n");
    }
}

void sell(char pname[], int sellQuantity)
{
    struct inventory *ptr = top;

    while (ptr != NULL)
    {
        if (strcmp(ptr->name, pname) == 0)
        {
            if (ptr->quantity >= sellQuantity)
            {
                ptr->quantity -= sellQuantity;
                printf("Sold %d units of %s\n", sellQuantity, pname);
                return;
            }
            else
            {
                printf("Not enough quantity of %s in stock.\n", pname);
                return;
            }
        }
        ptr = ptr->next;
    }
    printf("Product not found in inventory.\n");
}

void deleteProduct(char pname[])
{
    struct inventory *prev = NULL;
    struct inventory *curr = top;

    while (curr != NULL)
    {
        if (strcmp(curr->name, pname) == 0)
        {
            if (prev != NULL)
            {
                prev->next = curr->next;
            }
            else
            {
                top = curr->next;
            }
            free(curr);
            printf("Product %s deleted from inventory.\n", pname);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Product not found in inventory.\n");
}

int main()
{
    int option;
    char pname[50];
    int pquantity;
    int sellQuantity;

    while (1)
    {
        printf("  |**Enter your option**|\n1: Add your product\n2: Show the list\n3: Dead stock\n4: Sell\n5: Delete product\n6: Exit\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Enter product name: ");
            scanf("%s", pname);
            printf("Enter product quantity: ");
            scanf("%d", &pquantity);
            push(pname, pquantity);
            break;
        case 2:
            showinventory();
            break;

        case 3:
            deadstock();
            break;
        case 4:
            printf("Enter product name to sell: ");
            scanf("%s", pname);
            printf("Enter quantity to sell: ");
            scanf("%d", &sellQuantity);
            sell(pname, sellQuantity);
            break;
        case 5:
            printf("Enter product name to delete: ");
            scanf("%s", pname);
            deleteProduct(pname);
            break;
        case 6:
            printf("|**Exiting**|");
            return 0;    
        default:
            break;
        }
    }
    return 0;
}
