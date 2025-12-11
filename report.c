#include <stdio.h>
#include <string.h>
#include <time.h>

#define BOOKING_FILE "bookings.txt"


typedef struct {
    char bookingId[20];
    char passengerName[50];
    char phone[15];
    char routeNo[10];
    char busType[20];
    char seatNo[10];
    char date[15];
    char time[10];
    float fare;
    char status[20];
    char payment[20];
} Booking;

void generateDailyReport() {
    FILE *fp = fopen(BOOKING_FILE, "r");
    Booking b;
    char reportDate[15];
    int totalBookings = 0;
    int confirmed = 0;
    int cancelled = 0;
    float totalRevenue = 0;
    float collected = 0;
    
    printf("Enter date for report (DD-MM-YYYY): ");
    scanf("%s", reportDate);
    
    printf("\n=== DAILY REPORT FOR %s ===\n", reportDate);

    if(fp == NULL) {
        printf("Booking file not found.\n");
        return;
    }
    
    while(fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%f,%[^,],%s\n",
                b.bookingId, b.passengerName, b.phone, b.routeNo,
                b.busType, b.seatNo, b.date, b.time,
                &b.fare, b.status, b.payment) != EOF) {
        if(strcmp(b.date, reportDate) == 0) {
            totalBookings++;
            if(strcmp(b.status, "confirmed") == 0) {
                confirmed++;
                totalRevenue += b.fare;
                if(strcmp(b.payment, "paid") == 0) {
                    collected += b.fare;
                }
            } else if(strcmp(b.status, "cancelled") == 0) {
                cancelled++;
            }
        }
    }
    
    printf("Total Bookings: %d\n", totalBookings);
    printf("Confirmed: %d\n", confirmed);
    printf("Cancelled: %d\n", cancelled);
    printf("Total Revenue: %.2f\n", totalRevenue);
    printf("Collected: %.2f\n", collected);
    printf("Pending Collection: %.2f\n", totalRevenue - collected);
    
    fclose(fp);
}