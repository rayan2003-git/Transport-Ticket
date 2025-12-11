#include <stdio.h>
#include <string.h>

#define FILE_NAME "bookings.txt"

// Structure renamed to PaymentInfo to avoid conflict
typedef struct {
    char name[50];
    int seat;
    char source[50];
    char destination[50];
} PaymentInfo;


// View all reservations
void viewAll() {
    FILE *fp = fopen(FILE_NAME, "r");
    char line[200];
    
    printf("\n--- ALL RESERVATIONS ---\n");
    printf("%-4s %-20s %-15s %-15s\n", "Seat", "Name", "From", "To");
    printf("--------------------------------------------------\n");
    
    if(fp == NULL) {
        printf("No bookings yet.\n");
        return;
    }
    
    while(fgets(line, sizeof(line), fp)) {
        PaymentInfo b; // Use the renamed structure
        sscanf(line, "%[^,],%d,%[^,],%[^\n]", b.name, &b.seat, b.source, b.destination);
        printf("%-4d %-20s %-15s %-15s\n", b.seat, b.name, b.source, b.destination);
    }
    
    fclose(fp);
}

// View menu
void viewMenu() {
    int choice;
    do {
        printf("\n--- VIEW RESERVATIONS ---\n");
        printf("1. View All Bookings\n");
        printf("2. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        if(choice == 1) viewAll();
        else if(choice != 2) printf("Invalid choice.\n");
    } while(choice != 2);
    
    printf("Returning...\n");
}

// Mapped function for main.c case 2 (View All Bookings)
void viewAllBookings() {
    viewMenu();
}

// Function to handle payment (bkash/nagad)
void processPayment() {
    int choice;
    float amount = 150.0; // Example fare amount
    
    printf("\n--- PAYMENT PROCESS ---\n");
    printf("Booking Fee: %.2f Taka\n", amount);
    printf("Select Payment Method:\n");
    printf("1. bKash\n");
    printf("2. Nagad\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Processing payment via bKash...\n");
            printf("Enter bKash account number: ");
            char bkashNo[15];
            scanf("%s", bkashNo);
            printf("Payment of %.2f Taka successful via bKash.\n", amount);
            break;
        case 2:
            printf("Processing payment via Nagad...\n");
            printf("Enter Nagad account number: ");
            char nagadNo[15];
            scanf("%s", nagadNo);
            printf("Payment of %.2f Taka successful via Nagad.\n", amount);
            break;
        default:
            printf("Invalid choice. Payment failed.\n");
            break;
    }
}