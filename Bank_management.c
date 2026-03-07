#include <stdio.h>
#include <string.h>

#define MAX 30

struct Account {
    int acc_no;
    char name[50];
    char type[10];   // savings / current
    float balance;
    int transaction_count;
};

struct Account acc[MAX];
int count = 0;

/* Function declarations */
void createAccount();
void deposit();
void withdraw();
void transfer();
void display();
float compoundInterest(float p, float r, int t);
void saveAccounts();
int findAccount(int acc_no);

/* MAIN */
int main() {
    int choice;

    do {
        printf("\n--- Bank Account Management ---\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Transfer\n");
        printf("5. Display Account\n");
        printf("6. Compound Interest\n");
        printf("7. Save & Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: transfer(); break;
            case 5: display(); break;
            case 6: {
                int acc_no, years;
                float rate;
                printf("Enter account number: ");
                scanf("%d", &acc_no);
                int i = findAccount(acc_no);
                if(i != -1 && strcmp(acc[i].type,"savings")==0) {
                    printf("Enter rate & years: ");
                    scanf("%f %d",&rate,&years);
                    acc[i].balance =
                        compoundInterest(acc[i].balance, rate, years);
                    printf("Updated balance: %.2f\n", acc[i].balance);
                } else {
                    printf("Savings account not found\n");
                }
                break;
            }
            case 7: saveAccounts(); break;
            default: printf("Invalid choice\n");
        }
    } while(choice != 7);

    return 0;
}

/* CREATE ACCOUNT */
void createAccount() {
    if(count >= MAX) {
        printf("Account limit reached\n");
        return;
    }

    printf("Enter account number: ");
    scanf("%d",&acc[count].acc_no);
    printf("Enter name: ");
    scanf(" %[^\n]",acc[count].name);
    printf("Enter type (savings/current): ");
    scanf("%s",acc[count].type);

    acc[count].balance = 0;
    acc[count].transaction_count = 0;
    count++;

    printf("Account created successfully\n");
}

/* DEPOSIT */
void deposit() {
    int acc_no;
    float amt;
    printf("Enter account number & amount: ");
    scanf("%d %f",&acc_no,&amt);

    int i = findAccount(acc_no);
    if(i != -1) {
        acc[i].balance += amt;
        acc[i].transaction_count++;
        printf("Deposit successful\n");
    } else {
        printf("Account not found\n");
    }
}

/* WITHDRAW */
void withdraw() {
    int acc_no;
    float amt;
    printf("Enter account number & amount: ");
    scanf("%d %f",&acc_no,&amt);

    int i = findAccount(acc_no);
    if(i != -1) {
        if(acc[i].balance >= amt) {
            acc[i].balance -= amt;
            acc[i].transaction_count++;
            printf("Withdraw successful\n");
        } else {
            printf("Insufficient balance\n");
        }
    } else {
        printf("Account not found\n");
    }
}

/* TRANSFER */
void transfer() {
    int from, to;
    float amt;
    printf("From acc, To acc, Amount: ");
    scanf("%d %d %f",&from,&to,&amt);

    int i = findAccount(from);
    int j = findAccount(to);

    if(i!=-1 && j!=-1 && acc[i].balance>=amt) {
        acc[i].balance -= amt;
        acc[j].balance += amt;
        acc[i].transaction_count++;
        acc[j].transaction_count++;
        printf("Transfer successful\n");
    } else {
        printf("Transfer failed\n");
    }
}

/* DISPLAY */
void display() {
    int acc_no;
    printf("Enter account number: ");
    scanf("%d",&acc_no);

    int i = findAccount(acc_no);
    if(i != -1) {
        printf("\nAccount No: ****%d\n", acc[i].acc_no % 1000);
        printf("Name: %s\n", acc[i].name);
        printf("Type: %s\n", acc[i].type);
        printf("Balance: %.2f\n", acc[i].balance);
        printf("Transactions: %d\n", acc[i].transaction_count);
    } else {
        printf("Account not found\n");
    }
}

/* COMPOUND INTEREST (RECURSION) */
float compoundInterest(float p, float r, int t) {
    if(t == 0)
        return p;
    return compoundInterest(p * (1 + r/100), r, t-1);
}

/* SAVE FILE */
void saveAccounts() {
    FILE *fp = fopen("accounts.dat","wb");
    fwrite(acc, sizeof(struct Account), count, fp);
    fclose(fp);
    printf("Accounts saved. Exiting...\n");
}

/* FIND ACCOUNT */
int findAccount(int acc_no) {
    for(int i=0;i<count;i++) {
        if(acc[i].acc_no == acc_no)
            return i;
    }
    return -1;
}
