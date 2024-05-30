#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#define FILENAME "inventory.txt"
#include<time.h>

struct inventory
{
    char id[20];
    char name[50];
    int quantity; 
    struct inventory *next;
};
struct inventory *top = NULL;

void push(char pname[], int pquantity)
{
    struct inventory *newNode = (struct inventory *)malloc(sizeof(struct inventory));
    strcpy(newNode->name, pname);
    newNode->quantity = pquantity;

    generateUniqueId(newNode->id);

    newNode->next = top;
    top = newNode;

    // Save inventory data to file after adding the product
    saveInventoryToFile();
}

void showinventory()
{
    struct inventory *ptr = top;

    printf("List of products:\n");
    while (ptr != NULL)
    {
        printf("Product ID: %s, Name: %s, Quantity: %d\n", ptr->id, ptr->name, ptr->quantity);
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
void loadingScreen(int duration, int steps) {
    int i;
    int sleepDuration = duration / steps; 

    printf("         Loading\n [");
    for (i = 0; i < steps; i++) {
        printf("#"); 
        fflush(stdout); 
        Sleep(sleepDuration); 
    }
    printf("]\n"); 
}
void printBoxedText(const char *text) {
    int length = strlen(text);
    int i;
    printf("+");
    for (i = 0; i < length + 2; i++) {
        printf("-");
    }
    printf("+\n");  
    printf("| %s |\n", text);
    printf("+");
    for (i = 0; i < length + 2; i++) {
        printf("-");
    }
    printf("+\n");
}

void start()
{
        const char *text = "Welcome to IMS";
        printBoxedText(text);
        printf("Press Enter to continue...\n");
        getchar();
        loadingScreen(2000, 20);
        printf("proceeding with the rest of the program...\n");
        Sleep(1000);

}

void loadInventoryFromFile()
{
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL)
    {
        printf("No inventory data found.\n");
        return;
    }

    char id[20], name[50];
    int quantity;
    while (fscanf(file, "%s %s %d", id, name, &quantity) != EOF)
    {
        struct inventory *newNode = (struct inventory *)malloc(sizeof(struct inventory));
        strcpy(newNode->id, id);
        strcpy(newNode->name, name);
        newNode->quantity = quantity;
        newNode->next = top;
        top = newNode;
    }

    fclose(file);
}


void saveInventoryToFile()
{
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }

    struct inventory *ptr = top;
    while (ptr != NULL)
    {
        fprintf(file, "ID: %s Name: %s Quantity: %d\n", ptr->id, ptr->name, ptr->quantity);
        ptr = ptr->next;
    }

    fclose(file);
}

void generateUniqueId(char id[])
{
    // Generate a timestamp component based on current time
    long long timestamp = (long long)time(NULL);

    // Generate a random component
    int randomNum = rand() % 10000; // Adjust the range as needed

    // Combine timestamp and random number to create unique ID
    sprintf(id, "%lld-%d", timestamp, randomNum);
}


int main()
{
    int option;
    char pname[50];
    int pquantity;
    int sellQuantity;
    srand((unsigned int)time(NULL));
    loadInventoryFromFile();
    start();
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
            saveInventoryToFile();
            return 0;    
        default:
            break;
        }
    }
    return 0;
}
