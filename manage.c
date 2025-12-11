#include <stdio.h>
#include <string.h>

#define FILE_NAME "bookings.txt"

// Structure renamed to ManageReservation to avoid conflict
typedef struct { 
    char name[50]; 
    int seat; 
    char source[50]; 
    char destination[50]; 
} ManageReservation;

// Check if seat is available
int isSeatAvailable(int seat) {
    FILE *fp = fopen(FILE_NAME, "r");
    char line[200];
    
    if(fp == NULL) return 1;
    
    while(fgets(line, sizeof(line), fp)) {
        ManageReservation b;
        sscanf(line, "%[^,],%d,%[^,],%[^\n]", b.name, &b.seat, b.source, b.destination);
        if(b.seat == seat) {
            fclose(fp);
            return 0;
        }
    }
    
    fclose(fp);
    return 1;
}

// Book a seat
void bookSeat() {
    ManageReservation b;
    FILE *fp = fopen(FILE_NAME, "a");
    
    printf("\n--- BOOK A SEAT ---\n");
    printf("Enter name: ");
    scanf(" %[^\n]", b.name);
    printf("Enter seat (1-35): ");
    scanf("%d", &b.seat);
    printf("Enter source: ");
    scanf(" %[^\n]", b.source);
    printf("Enter destination: ");
    scanf(" %[^\n]", b.destination);
    
    if(b.seat < 1 || b.seat > 35) {
        printf("Invalid seat number.\n");
        fclose(fp);
        return;
    }
    
    if(!isSeatAvailable(b.seat)) {
        printf("Seat %d is already booked.\n", b.seat);
        fclose(fp);
        return;
    }
    
    fprintf(fp, "%s,%d,%s,%s\n", b.name, b.seat, b.source, b.destination);
    fclose(fp);
    
    printf("Booking successful!\n");
}

// Booking menu
void bookingMenu() {
    int choice;
    do {
        printf("\n--- BOOKING SYSTEM ---\n");
        printf("1. Book a Seat\n");
        printf("2. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        if(choice == 1) bookSeat();
        else if(choice != 2) printf("Invalid choice.\n");
    } while(choice != 2);
    
    printf("Returning...\n");
}

// Mapped function for main.c case 1 (Book New Ticket)
void bookTicket() {
    bookingMenu();
}

// Mapped function for main.c case 7 (View Available Seats)
void checkSeatAvailability() {
    bookingMenu();
}