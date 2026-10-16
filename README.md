Cinema and Event Booking System in C

A university programming project featuring a menu-driven terminal interface for managing seat reservations.

Features

View events and available seats

Book a specific seat

Check event IDs, numeric inputs and seat availability

Prevent duplicate reservations for the same seat

Cancel a reservation using booking details and a numeric password

Display current bookings

Files

main.c — application source code

events.txt — sample event data

Each line in events.txt contains:
Event ID, Event Name, Total Seats, Available Seats

How to run

Download both files into the same folder.

Compile main.c using a C compiler. Run the application with that folder as its working directory so it can find events.txt.

Example using GCC:

gcc main.c -o booking

Run ./booking on Linux/macOS, or .\booking.exe in Windows PowerShell.

Limitations

Bookings are stored in memory and are cleared when the application closes. The application supports up to 10 booking records at a time.
