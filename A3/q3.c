// Create a structure to specify data of customers in a bank. The data to be stored is: Account number, Name,
// Balance in account. Assume there can have more than 100 customers in the bank.
// (1) Write a function to print the account number and name of each customer with balance below Rs. 1000.
// (II) Consider that a customer request for withdrawal or deposit is given in the form: Acct. no, amount,
// code (1 for deposit, 0 for withdrawal)
// and write a program to deposit and withdraw the amount from the specified account and give a message
// "The balance is insufficient for the specified withdrawal" if balance is below the threshold.

#include <stdio.h>

struct customer
{
    int account_number;
    char name[20];
    float balance;
};

typedef struct customer Customer;

void print(Customer c[], int n)
{
    int i;
    printf("%-10s|%-20s|%-15s\n", "Acc No.", "Name", "Balance");
    for (i = 0; i < n; i++)
    {
        if (c[i].balance < 1000)
        {
            printf("%-10d|%-20s|%-10.2f\n", c[i].account_number, c[i].name, c[i].balance);
        }
    }
}

void deposit_withdraw(Customer c[], int n, int account_number, float amount, int code)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (c[i].account_number == account_number)
        {
            if (code == 1)
            {
                c[i].balance += amount;
            }
            else if (code == 0)
            {
                if (c[i].balance < amount)
                {
                    printf("The balance is insufficient for the specified withdrawal");
                }
                else
                {
                    c[i].balance -= amount;
                }
            }
            printf("The balance is %f\n", c[i].balance);
            return;
        }
    }
    printf("Account number not found");
}

int main()
{
    int n, i, account_number, code;
    float amount;
    printf("Enter the number of customers: ");
    scanf("%d", &n);
    Customer c[n];
    for (i = 0; i < n; i++)
    {
        printf("Enter the account number: ");
        scanf("%d", &c[i].account_number);
        printf("Enter the name: ");
        scanf(" %[^\n]", c[i].name);
        printf("Enter the balance: ");
        scanf("%f", &c[i].balance);
    }
    while (1)
    {
        printf("Choose an option:\n");
        printf("1. Print the account number and name of each customer with balance below Rs. 1000.\n");
        printf("2. Deposit and withdraw the amount from the specified account.\n");
        printf("3. Exit.\n");
        int choice;
        scanf("%d", &choice);
        if (choice == 1)
        {
            print(c, n);
        }
        else if (choice == 2)
        {
            printf("Enter the account number: ");
            scanf("%d", &account_number);
            printf("Enter the amount: ");
            scanf("%f", &amount);
            printf("Enter the code:(1 for deposit, 0 for withdrawal) ");
            scanf("%d", &code);
            deposit_withdraw(c, n, account_number, amount, code);
        }
        else if (choice == 3)
        {
            break;
        }
    }

    return 0;
}
