#include <stdio.h>
#include <stdlib.h>

struct Account {
    int accNo;
    char name[50];
    float balance;
};

void createAccount() {
    FILE *fp;
    struct Account acc;

    fp = fopen("bank.dat", "ab");

    printf("\nEnter Account Number: ");
    scanf("%d", &acc.accNo);

    printf("Enter Account Holder Name: ");
    scanf("%s", acc.name);

    acc.balance = 0;

    fwrite(&acc, sizeof(acc), 1, fp);

    fclose(fp);

    printf("\nAccount Created Successfully!\n");
}

void depositMoney() {
    FILE *fp;
    struct Account acc;
    int accNo;
    float amount;
    int found = 0;

    fp = fopen("bank.dat", "rb+");

    printf("\nEnter Account Number: ");
    scanf("%d", &accNo);

    printf("Enter Amount to Deposit: ");
    scanf("%f", &amount);

    while (fread(&acc, sizeof(acc), 1, fp)) {

        if (acc.accNo == accNo) {

            acc.balance += amount;

            fseek(fp, -sizeof(acc), SEEK_CUR);
            fwrite(&acc, sizeof(acc), 1, fp);

            printf("\nDeposit Successful!");
            printf("\nCurrent Balance: %.2f\n", acc.balance);

            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found)
        printf("\nAccount Not Found!\n");
}

void withdrawMoney() {
    FILE *fp;
    struct Account acc;
    int accNo;
    float amount;
    int found = 0;

    fp = fopen("bank.dat", "rb+");

    printf("\nEnter Account Number: ");
    scanf("%d", &accNo);

    printf("Enter Amount to Withdraw: ");
    scanf("%f", &amount);

    while (fread(&acc, sizeof(acc), 1, fp)) {

        if (acc.accNo == accNo) {

            if (amount > acc.balance) {
                printf("\nInsufficient Balance!\n");
                fclose(fp);
                return;
            }

            acc.balance -= amount;

            fseek(fp, -sizeof(acc), SEEK_CUR);
            fwrite(&acc, sizeof(acc), 1, fp);

            printf("\nWithdrawal Successful!");
            printf("\nRemaining Balance: %.2f\n", acc.balance);

            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found)
        printf("\nAccount Not Found!\n");
}

void balanceEnquiry() {
    FILE *fp;
    struct Account acc;
    int accNo;
    int found = 0;

    fp = fopen("bank.dat", "rb");

    printf("\nEnter Account Number: ");
    scanf("%d", &accNo);

    while (fread(&acc, sizeof(acc), 1, fp)) {

        if (acc.accNo == accNo) {

            printf("\n===== ACCOUNT DETAILS =====");
            printf("\nAccount Number : %d", acc.accNo);
            printf("\nName           : %s", acc.name);
            printf("\nBalance        : %.2f\n", acc.balance);

            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found)
        printf("\nAccount Not Found!\n");
}

int main() {

    int choice;

    do {

        printf("\n\n===== BANK ACCOUNT MANAGEMENT SYSTEM =====");
        printf("\n1. Create Account");
        printf("\n2. Deposit Money");
        printf("\n3. Withdraw Money");
        printf("\n4. Balance Enquiry");
        printf("\n5. Exit");

        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                createAccount();
                break;

            case 2:
                depositMoney();
                break;

            case 3:
                withdrawMoney();
                break;

            case 4:
                balanceEnquiry();
                break;

            case 5:
                printf("\nThank You!\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while(choice != 5);

    return 0;
}