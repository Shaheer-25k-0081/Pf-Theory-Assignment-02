#include <stdio.h>
#include <string.h>
void customerInfo(char customerName[20], char cnic[15])
{
    printf("Enter your Name: ");
    scanf(" %[^\n]", customerName);
    printf("Enter your CNIC number: ");
    scanf("%s", cnic);
}

void display(int prodCode[4], int quantity[4], int price[4])
{

    printf("%-20s %10s %10s\n\n", "Product Code", "quantity", "Price");
    for (int i = 0; i < 4; i++)
    {
        printf("%-20d %10d %10d\n", prodCode[i], quantity[i], price[i]);
    }
}
void addItem(int prodCode[], int quantity[], int selectedCode[], int selectedQty[], int *totalItem)
{
    int num;
    int newQty;
    printf("How many items do you want to add: ");
    scanf("%d", &num);
    int newarr[num];
    for (int i = 0; i < num; i++)
    {
        printf("\nEnter the product code of your item  %d: ", i + 1);
        scanf("%d", &newarr[i]);
        int found = 0;
        for (int j = 0; j < 4; j++)
        {
            if (newarr[i] == prodCode[j])
            {
                found = 1;
                selectedCode[*totalItem] = prodCode[j];

                printf("Enter quantity: ");
                scanf("%d", &newQty);
                selectedQty[*totalItem] = newQty;
                (*totalItem)++;
                if (newQty <= quantity[j])
                {
                    quantity[j] -= newQty;
                }
                else
                {
                    printf("Required quantity not available\n");
                    i--;

                    break;
                }
            }
        }
        if (!found)
        {
            printf("Invalid Item");
            i--;
        }
    }
}
float calculateBill(int prodCode[], int price[], int selectedCode[], int selectedQty[], int num, int *hasDiscount, float *orignalBill)
{
    float totalBill = 0.0;
    *hasDiscount = 0;
    char code[7];

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (selectedCode[i] == prodCode[j])
            {
                totalBill += price[j] * selectedQty[i];
            }
        }
    }
    *orignalBill = totalBill;
    char isPromoCode;
    printf("\n Do you have any vocher for promo code? (Y for yes, N for no): ");
    scanf(" %c", &isPromoCode);
    if (isPromoCode == 'Y' || isPromoCode == 'y')
    {
        printf("Enter the promocode: ");
        scanf(" %s", code);
        if (strcmp(code, "Eid2025") == 0 || strcmp(code, "eid2025") == 0 || strcmp(code, "EID2025") == 0)
        {
            *hasDiscount = 1;
            totalBill -= (totalBill * .25);
            printf("\nPromo Code applied");
            return totalBill;
        }
        else
        {
            printf("\nInvalid Promocode");
            return totalBill;
        }
    }
    else
    {
        return totalBill;
    }
}
void invoice(int prodCode[], int selectedCode[], int selectedQty[], int price[], char customerName[], char cnic[], float totalbill, int totalItem, int hasDiscount, float orignalBill)
{
    float discountedAmount = 0.0;
    printf("===========INVOICE=========\n\n");
    printf("Customer Name: %s\n", customerName);
    printf("Customer CNIC: %s\n\n", cnic);
    printf("----------------------------\n");
    printf("%-20s %10s %10s\n\n", "Product Code", "Quantity", "Price Per product");
    printf("----------------------------\n");
    for (int i = 0; i < totalItem; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (selectedCode[i] == prodCode[j])
            {
                printf("%-20d %10d %10d\n", selectedCode[i], selectedQty[i], price[j]);
            }
        }
    }
    printf("\nOrignal Bill: %.2f ", orignalBill);
    if (hasDiscount)
    {

        printf("\nDiscount Applied (25%%)");
        printf("\nFinal Bill : %.2f", totalbill);
    }
    else
    {
        printf("\nDiscount = 0%%");
        printf("\nFinal Bill : %.2f", orignalBill);
    }
    printf("\n\n----------Thanks For Shopping!------------");
}
int main()
{

    char customerName[20], cnic[15];
    int hasDiscount = 0;
    float originalBill = 0.0;
    int selectedCode[50];
    int selectedQty[50];
    int prodCode[4] = {1, 2, 3, 4};
    int quantity[4] = {50, 10, 20, 8};
    int price[4] = {100, 200, 300, 150};
    int totalItem = 0;
    int choice;
    float bill = 0.0;
    do
    {
        printf("\n---------Welcome to ABC Shopping Center-----------------\n");
        printf("1. Customer Info\n");
        printf("2. Display items\n");
        printf("3. Add item to the cart\n");
        printf("4. See updated items\n");
        printf("5. Calculate bill\n");
        printf("6. Show invoice\n");
        printf("7. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            customerInfo(customerName, cnic);
            break;
        case 2:
            display(prodCode, quantity, price);
            break;
        case 3:
            addItem(prodCode, quantity, selectedCode, selectedQty, &totalItem);
            break;
        case 4:

            printf("\n");
            display(prodCode, quantity, price);
            break;
        case 5:
            printf("\n");
            bill = calculateBill(prodCode, price, selectedCode, selectedQty, totalItem, &hasDiscount, &originalBill);
            break;
        case 6:
            invoice(prodCode, selectedCode, selectedQty, price, customerName, cnic, bill, totalItem, hasDiscount, originalBill);
            break;
            case 7:
            printf("\nExit");
        default:
            printf("Invalid Choice");
            break;
        }
    } while (choice != 7);
}