#include <stdio.h>
#include <string.h>   // ← Required for strlen()

#define MAX_LENGTH 500

void reverseString(char str[])
{
    int length = strlen(str), start = 0, end = length - 1;
    char temp;

    while (start < end)
    {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

char toggleBits(char ch)
{
    ch = ch ^ (1 << 1);  // toggle 2nd bit
    ch = ch ^ (1 << 4);  // toggle 5th bit
    return ch;
}

void encodeMessage(char message[])
{
    printf("\nEncoding Process\n\n");
    printf("Original Message: %s\n", message);

    reverseString(message);
    printf("After Reversal: %s\n", message);

    printf("Toggling Bits (2nd and 5th) of each character...\n");
    for (int i = 0; i < strlen(message); i++)
    {
        message[i] = toggleBits(message[i]);
    }

    printf("Encoded Message:\n%s\n", message);
    printf("Message Encoded Successfully!\n\n");
}

void decodeMessage(char message[])
{
    printf("\nDecoding Process\n\n");
    printf("Original Message: %s\n", message);

    printf("Untoggling Bits (2nd and 5th) of each character...\n");
    for (int i = 0; i < strlen(message); i++)
    {
        message[i] = toggleBits(message[i]);
    }

    printf("After Untoggling Bits:\n%s\n", message);
    reverseString(message);
    printf("Decoded Message:\n%s\n", message);
    printf("Message Decoded Successfully!\n\n");
}

int main()
{
    int choice;
    char message[MAX_LENGTH];

    printf("--------TRANZUM COURIER SERVICE (TCS)--------\n----SECURITY TOOL----\n\n");

    do
    {
        printf("1. Encode Message\n2. Decode Message\n3. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nMessage Encoder\nEnter Normal Text Message:\n");
            scanf(" %[^\n]", message);
            encodeMessage(message);
            break;

        case 2:
            printf("\nMessage Decoder\nEnter Encoded Text Message:\n");
            scanf(" %[^\n]", message);
            decodeMessage(message);
            break;

        case 3:
            printf("\nExiting The System.\nThank you for using our service.\n");
            break;

        default:
            printf("Invalid Choice! Please re-enter (1-3)\n");
            break;
        }
    } while (choice != 3);

    return 0;
}
