# Cinema and Event Booking System in C

A university programming project demonstrating **C programming**, **file handling** and **input validation** through a terminal-based booking application.

## Features

- View available events and seat counts
- Reserve a specific seat
- Prevent duplicate reservations for the same seat
- Validate event IDs, numeric inputs and seat numbers
- Cancel reservations using booking details and a numeric password
- Display a report of current bookings

## Project Files

| File | Purpose |
|---|---|
| `main.c` | Application source code |
| `events.txt` | Sample event names and seat information |

## Event Data Format

Each line in `events.txt` contains:

```text
Event ID,Event Name,Total Seats,Available Seats
```

Example data — do not include a header row in the file:

```text
101,Example Movie A,50,50
102,Example Movie B,40,40
103,Example Movie C,30,30
```

## How to Run

Download both files into the same folder. Open a terminal in that folder.

### Compile with GCC

```bash
gcc main.c -o booking
```

### Run on Windows PowerShell

```powershell
.\booking.exe
```

### Run on Linux or macOS

```bash
./booking
```

The program reads `events.txt` from its working directory.

## Programming Concepts

- Structures and arrays
- Functions and modular programming
- Loops and conditional logic
- Text-file input
- Input validation
- Booking and seat-availability management

## Current Limitations

- Reservations are stored in memory and cleared when the application closes.
- A maximum of 10 booking records can be stored at one time.
