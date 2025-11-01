#include <stdio.h>

void newBook(int isbn[100], char titles[50][100], float prices[100], int quantity[100], int *numBooks)
{
    int num;
    printf("\nHow many books do you want to add: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        int validISBN = 0;
        while (!validISBN)
        {
            printf("\nEnter ISBN number %d: ", *numBooks + i + 1);
            scanf("%d", &isbn[*numBooks + i]);
            validISBN = 1;

            // Check for duplicate ISBNs
            for (int j = 0; j < *numBooks + i; j++)
            {
                if (isbn[*numBooks + i] == isbn[j])
                {
                    printf("Please do not enter duplicate ISBN values.\n");
                    validISBN = 0;
                    break;
                }
            }
        }

        printf("Enter book name: ");
        scanf(" %[^\n]", titles[*numBooks + i]);

        printf("Enter price: ");
        scanf("%f", &prices[*numBooks + i]);

        printf("Enter quantity: ");
        scanf("%d", &quantity[*numBooks + i]);
    }

    *numBooks += num;

    printf("\n%-10s %-30s %-10s %-10s\n", "ISBN", "Book", "Price", "Quantity");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < *numBooks; i++)
    {
        printf("%-10d %-30s %-10.2f %-10d\n", isbn[i], titles[i], prices[i], quantity[i]);
    }
}

void processSale(int isbn[100], char titles[50][100], float prices[100], int quantity[100], int numBooks)
{
    int saleISBN;
    printf("Enter ISBN to sell: ");
    scanf("%d", &saleISBN);

    int found = 0;
    for (int i = 0; i < numBooks; i++)
    {
        if (saleISBN == isbn[i])
        {
            found = 1;
            int qty;
            printf("Enter how many copies you sold: ");
            scanf("%d", &qty);

            if (qty <= quantity[i])
            {
                quantity[i] -= qty;
                printf("Sale processed successfully.\n");
            }
            else
            {
                printf("Invalid quantity. Not enough stock available.\n");
            }
            break;
        }
    }

    if (!found)
    {
        printf("ISBN number not found.\n");
    }
}

void stockReport(int isbn[100], char titles[50][100], float prices[100], int quantity[100], int numBooks)
{
    printf("\nBooks with quantities less than 5:\n");
    int found = 0;

    for (int i = 0; i < numBooks; i++)
    {
        if (quantity[i] < 5)
        {
            printf("ISBN: %d, Title: %s, Quantity: %d\n", isbn[i], titles[i], quantity[i]);
            found = 1;
        }
    }

    if (!found)
    {
        printf("None\n");
    }
}

int main()
{
    int choice;
    int numBooks = 0;
    int isbn[100];
    char titles[50][100];
    float prices[100];
    int quantity[100];

    do
    {
        printf("\n--- Liberty Books Inventory ---\n");
        printf("1. Add New Book\n");
        printf("2. Process Sale\n");
        printf("3. Low-Stock Report\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            newBook(isbn, titles, prices, quantity, &numBooks);
            break;
        case 2:
            processSale(isbn, titles, prices, quantity, numBooks);
            break;
        case 3:
            stockReport(isbn, titles, prices, quantity, numBooks);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
