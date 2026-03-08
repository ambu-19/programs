#include <stdio.h>

int main() {

    int seats[20] = {0}; 
    // 0 = available, 1 = booked

    int bookedSeats[20]; 
    int bookedCount = 0;

    int choice, seatNumber, i, j, temp;

    while (1) {
        printf("\n===== BUS SEAT BOOKING SYSTEM =====\n");
        printf("1. Book a Seat\n");
        printf("2. Search a Seat Status\n");
        printf("3. Display All Booked Seats\n");
        printf("4. Sorting Booked Seats (Bubble Sort)\n");
        printf("5. Statistics (Max Seat, Min Seat, Total Booked)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        // 1. BOOK A SEAT
        case 1:
            printf("Enter seat number to book (1–20): ");
            scanf("%d", &seatNumber);

            if (seatNumber < 1 || seatNumber > 20) {
                printf("Invalid seat number!\n");
                break;
            }

            if (seats[seatNumber - 1] == 0) {
                seats[seatNumber - 1] = 1;
                bookedSeats[bookedCount++] = seatNumber;
                printf("Seat %d booked successfully!\n", seatNumber);
            } else {
                printf("Seat already booked!\n");
            }
            break;

        // 2. SEARCH SEAT STATUS
        case 2:
            printf("Enter seat number to search: ");
            scanf("%d", &seatNumber);

            if (seats[seatNumber - 1] == 1)
                printf("Seat %d is BOOKED.\n", seatNumber);
            else
                printf("Seat %d is AVAILABLE.\n", seatNumber);
            break;

        // 3. DISPLAY BOOKED SEATS
        case 3:
            if (bookedCount == 0) {
                printf("No seats booked yet.\n");
            } else {
                printf("Booked Seats: ");
                for (i = 0; i < bookedCount; i++)
                    printf("%d ", bookedSeats[i]);
                printf("\n");
            }
            break;

        // 4. SORT USING BUBBLE SORT
        case 4:
            for (i = 0; i < bookedCount - 1; i++) {
                for (j = 0; j < bookedCount - i - 1; j++) {
                    if (bookedSeats[j] > bookedSeats[j + 1]) {
                        temp = bookedSeats[j];
                        bookedSeats[j] = bookedSeats[j + 1];
                        bookedSeats[j + 1] = temp;
                    }
                }
            }
            printf("Booked seats sorted successfully!\n");
            break;

        // 5. STATISTICS
        case 5:
            if (bookedCount == 0) {
                printf("No seats booked. No statistics available.\n");
            } else {
                int max = bookedSeats[0];
                int min = bookedSeats[0];

                for (i = 1; i < bookedCount; i++) {
                    if (bookedSeats[i] > max)
                        max = bookedSeats[i];
                    if (bookedSeats[i] < min)
                        min = bookedSeats[i];
                }

                printf("Total Booked Seats: %d\n", bookedCount);
                printf("Highest Seat Number Booked: %d\n", max);
                printf("Lowest Seat Number Booked: %d\n", min);
            }
            break;

        case 6:
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }
}
