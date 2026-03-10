#include <stdio.h>

// Function declarations
int login();
void showMenu();
void balanceEnquiry(int balance);
int deposit(int balance, int amount);
int withdraw(int balance, int amount);
int fastCash(int balance);

int main() {
    int balance = 5000;  // Initial balance
    int choice, amount;

    printf("=====================================\n");
    printf("             ATM SYSTEM\n");
    printf("=====================================\n");

    // Login
    if (!login()) {
        printf("\nToo many incorrect attempts! Try again later.\n");
        return 0;
    }

    do {
        showMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                balanceEnquiry(balance);
                break;

            case 2:
                printf("Enter deposit amount: ");
                scanf("%d", &amount);
                balance = deposit(balance, amount);
                break;

            case 3:
                printf("Enter withdrawal amount: ");
                scanf("%d", &amount);
                balance = withdraw(balance, amount);
                break;

            case 4:
                balance = fastCash(balance);
                break;

            case 5:
                printf("\nThank you! Visit Again.\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 5);

    return 0;
}

// Function to verify PIN
int login() {
    int pin, attempts = 0;

    while (attempts < 3) {
        printf("\nEnter your 4-digit PIN: ");
        scanf("%d", &pin);

        if (pin == 1234) {
            printf("\nLogin Successful!\n");
            return 1;
        } else {
            printf("Incorrect PIN!\n");
        }
        attempts++;
    }
    return 0;
}

// Display ATM menu
void showMenu() {
    printf("\n===== ATM MENU =====\n");
    printf("1. Balance Enquiry\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Fast Cash (₹500 / ₹1000 / ₹2000)\n");
    printf("5. Exit\n");
}

// Print balance
void balanceEnquiry(int balance) {
    printf("\nCurrent Balance: ₹%d\n", balance);
}

// Deposit function
int deposit(int balance, int amount) {
    if (amount <= 0) {
        printf("Invalid deposit amount!\n");
        return balance;
    }
    balance += amount;
    printf("Amount Deposited Successfully!\n");
    printf("Updated Balance: ₹%d\n", balance);
    return balance;
}

// Withdraw function
int withdraw(int balance, int amount) {
    if (amount <= 0) {
        printf("Invalid withdrawal amount!\n");
        return balance;
    }
    if (amount > balance) {
        printf("Insufficient Balance!\n");
        return balance;
    }
    balance -= amount;
    printf("Please collect your cash.\n");
    printf("Updated Balance: ₹%d\n", balance);
    return balance;
}

// Fast cash options
int fastCash(int balance) {
    int choice;
    printf("\nSelect Fast Cash Option:\n");
    printf("1. ₹500\n2. ₹1000\n3. ₹2000\n");
    printf("Enter option: ");
    scanf("%d", &choice);

    int amount = 0;

    if (choice == 1) amount = 500;
    else if (choice == 2) amount = 1000;
    else if (choice == 3) amount = 2000;
    else {
        printf("Invalid option!\n");
        return balance;
    }

    if (amount > balance) {
        printf("Insufficient Balance for Fast Cash!\n");
        return balance;
    }

    balance -= amount;
    printf("Please collect ₹%d\n", amount);
    printf("Updated Balance: ₹%d\n", balance);
    return balance;
}
