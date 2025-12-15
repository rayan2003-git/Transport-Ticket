#  Bus Booking System (C – Terminal Based)

A lightweight, file-backed reservation console application written in **plain C**.  
Admins create routes, users book seats, payments are handled via bKash/Nagad, and daily reports can be generated – all without a database.



##  Features

| Role | Feature |
|------|---------|
| **Shared** | Sign-up / Login / Change password |
| **User** | Book seat (1-35), view my bookings, print ticket, check availability |
| **Admin** | View/cancel any booking, add new route, generate daily report |
| **Payment** | bKash & Nagad integration (demo) |
| **I/O** | Human-readable CSV files (`users.txt`, `bookings.txt`) |



##  File Map

| File | Purpose |
|------|---------|
| `main.c` | Entry menu (admin/user/sign-up) |
| `auth.c` | `userSignup`, `secureLogin`, `changePassword` |
| `manage.c` | `bookTicket`, `isSeatAvailable`, `checkSeatAvailability` |
| `booking.c` | `printTicket`, `ticketMenu` |
| `payment.c` | `processPayment`, `viewAll` |
| `report.c` | `generateDailyReport` |
| `testcase_*.c` | Unit-style smoke tests for each module |



##  Build & Run

**Requirements**: GCC (MinGW on Windows) – no extra libraries.

```bash
# 1. Clone or unzip the project
cd bus-booking-c

# 2. Compile everything at once
gcc *.c -o bus.out       # Linux / macOS
gcc *.c -o bus.exe       # Windows (MinGW)

# 3. Run
./bus.out     # or bus.exe
