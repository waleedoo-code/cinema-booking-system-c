#include <stdio.h>
#include <stdlib.h>

//database for storing event details with the event ID, event name, total number of seats and the number of seats available.
struct event {
    int eventID;
    char eventName[50];
    int totalSeats;
    int availableSeats;
};
struct event events[100];// Array to hold up to 100 events
int eventCount = 0;// Counter for number of events

//record information of user such as event ID, user ID, seat ID and password
struct user{
    int eventID;
    int userID;
    int seatID;
    int pasword;
};
struct user users[10];// declare and instance a struct user to hold date for 10 users only
int userCount= 0;// Counter of the number of users

// functions
void toStructure(); // Reads event data from a file into the structure
void eventlist();   // list the events available
void booking();     // books the events and
void report();      // generate a report for the all available bookings
void cancelling();  // cancel the booking for an event
int eventcheck(int ID);  // Checks if an event ID exists
int getValidInteger(const char* prompt); // Gets and check integer input from the user


int main()
{
    toStructure();// Load event data into memory
    int book =0;
    // Continuous loop to display the menu and process user input
    while(1){
    int choice;


    // Display menu options
    printf("type 1 to view available events\n");
    printf("type 2 to Book a seat \n");
    printf("type 3 to Cancel a booking \n");
    printf("type 4 to Generate a report of current bookings \n");
    printf("type 5 to Exit\n\n");

    // get the user choice
    choice = getValidInteger("Enter your choice: ");
    printf("\n");


   printf("\n");


    //handles user choice
    switch (choice)
    {
        case 1:
            eventlist();// View event list
            book++;
            break;

        case 2:
            // the user has to see the list before choice.
            if(book ==0){
                    printf("press 1 to see the list first.\n\n");
                break;
                }
            else
            {
                booking();// Book a seat
                break;
            }

        case 3:
            cancelling();// Cancel a booking
            break;
        case 4:
            report();// Generate booking report
            break;

        case 5:
            printf("Exiting the system. Goodbye!");
            return 0;// Exit program

        default:
            printf("error enter a number from the list provided\n\n");// handling user invalid input
            break;


    }

    }

}

// a function that receive a valid input from the user
int getValidInteger(const char* prompt) {
    int value;
    char term;
    while (1) {
        printf("%s", prompt); // display the message
        //to make sure the imput is a integer
        if (scanf("%d%c", &value, &term) == 2 && term == '\n') {
            return value; //integer input
        }
        printf("Invalid input. Please enter a valid number.\n");
        while (getchar() != '\n'); // Clear the input buffer
    }
}

// Function to cancel a booking
void cancelling()
{
     // check if there are events that are booked to be cancelled
    if (userCount == 0) {
         printf("No bookings have been done to be cancelled.\n\n");
        return;
    }

    int userID, eventID,password;
    userID = getValidInteger("Enter your user ID: ");// Get user ID
    printf("\n");


    eventID = getValidInteger("Enter the event ID for the booking you want to cancel: ");// Get event ID
    printf("\n");

    password = getValidInteger("enter the password for this id: ");// Get user password
    printf("\n");


    //Initialisation of the booking and the event index
    int bookingIndex = -1;
    int eventIndex = -1;

   // Find the current booking in the list of users
    for (int i = 0; i < userCount; i++) {
        if (users[i].userID == userID && users[i].eventID == eventID) {
            bookingIndex = i;
            break;
        }
    }

     // Search for the event in the events array
    for (int i = 0; i < eventCount; i++) {
        if (events[i].eventID == eventID) {
            eventIndex = i;
            break;
        }
    }

    // if no booking is available from the particular User ID for the particular Event ID, then the following message should be printed
    if (bookingIndex == -1) {
        printf("Error: No booking found for User ID %d and Event ID %d.\n\n", userID, eventID);
        return;
    }

    // If there is no booking with the specific User ID and Event ID, these lines will be printed
    if (eventIndex == -1) {
        printf("Error: Invalid Event ID.\n\n");
        return;
    }

    // Compare the user entered password with the password for this booking
    // If the password does not match print message of incorrect Password
    if (users[bookingIndex].pasword != password) {
        printf("Error: Incorrect password. Booking not cancelled.\n\n");
        return;

    }

    // Update available seats and shift bookings to maintain order
    events[eventIndex].availableSeats++;

    // Shift the bookings array to remove the cancelled booking
    for (int i = bookingIndex; i < userCount - 1; i++) {
        users[i] = users[i + 1];
    }

    // Decrease the overall the total user bookings number after cancelling a certain booking
    userCount--;

    // Let the user know that their booking was cancelled
    printf("Booking successfully cancelled.\n\n");

}



// Function to handle the booking of seats for an event
void booking()
{
    int eventid;
    int userid;
    int userpasword;

    // Prompt the user to enter the Event ID they want to book
    eventid = getValidInteger("Enter the event ID to book a seat: ");
    printf("\n");
    int eventIndex = -1;

     // Search for the event with the entered Event ID in the events array
    for (int i = 0; i < eventCount; i++) {
        if (events[i].eventID == eventid) {
            eventIndex = i; // Save the index of the event if found
            break; // Exit the loop once the event is found
        }
    }

    // If the entered Event ID is invalid (not found in the list of events)
    if (eventIndex == -1) {
        printf("Unavailable event ID. Please try again.\n\n");
        booking(); // start booking from the start
        return;
    }

    // Check if there are any available seats for the selected event
    if (events[eventIndex].availableSeats <= 0) {
        printf("Error: No seats available for this event.\n\n");
        return; // Exit the function
    }

    // check if the maximum amount of users has been reached
    if (userCount >= 10) {
        printf("Too many users, cannot book more seats.\n\n");
        return;//exist the function
    }


   int tr = 1;

while (tr) {
    // Prompt the user to enter a valid User ID
    userid = getValidInteger("Enter user ID (only numbers no more than 6 digits and not less than 4 digits): ");
    printf("\n");

    if (userid >= 1000 && userid <= 999999) {
        // Store the User ID and Event ID if valid
        users[userCount].userID = userid;
        users[userCount].eventID = eventid;

        int passwordValid = 0; // Flag to ensure valid password input
        while (!passwordValid) {
            // Prompt the user to enter a valid password
            userpasword = getValidInteger("Enter password (only numbers no more than 6 digits and not less than 4 digits): ");
            printf("\n");

            if (userpasword >= 1000 && userpasword <= 999999) {
                // Store the password if valid and exit the loop
                users[userCount].pasword = userpasword;
                passwordValid = 1;
            } else {
                printf("Error: Password must be between 1000 and 999999. Please try again.\n\n");
            }
        }

        int seatAssigned = 0; // Flag to ensure a valid seat is assigned
        while (!seatAssigned) {
            // Prompt the user to enter a valid seat number
            int seat = getValidInteger("Enter seat number: ");
            printf("\n");

            if (seat >= 1 && seat <= events[eventIndex].totalSeats) {
                // Check if the seat is already booked for the event
                int seatTaken = 0;
                for (int i = 0; i < userCount; i++) {
                    if (users[i].eventID == eventid && users[i].seatID == seat) {
                        seatTaken = 1;
                        break;
                    }
                }

                if (seatTaken) {
                    // Notify the user if the seat is already taken
                    printf("Error: Seat is already booked. Please try a different seat.\n\n");
                } else {
                    // Assign the seat and finalize the booking
                    users[userCount].seatID = seat;
                    events[eventIndex].availableSeats--;
                    printf("Booking successful!\n\n");
                    userCount++;
                    seatAssigned = 1; // Exit the seat assignment loop
                    tr = 0; // Exit the main booking loop
                }
            } else {
                printf("Error: Seat number out of range. Please try again.\n\n");
            }
        }
    } else {
        printf("Error: User ID must be between 1000 and 999999. Please try again.\n\n");
    }
}
}

// Function to list out the events Currently Available
void eventlist() {

    // header for event list
    printf("%-10s %-30s %-15s %-15s\n", "EventID", "Event Name", "Total Seats", "Available Seats");
    printf("-----------------------------------------------------------------------------\n");

    // To show all details of each event
    for(int i = 0; i<eventCount;i++)
    {
       printf("%-10d %-35s %-15d %-15d\n", events[i].eventID,
                                            events[i].eventName,
                                            events[i].totalSeats,
                                            events[i].availableSeats);
    }
        printf("\n");
}

// The following function  search an event by its ID.
int  eventcheck(int ID)
{
    int found = 0;
    // There is a for loop  that iterates through all the events in the events array
    for (int i =  0; i<eventCount;i++)
    {
        // If the given ID is equal with the  event ID of the element at the current index
        if (ID == events[i].eventID)
        {
            found = 1; // There is an event and therefore 1 (true)
            break;
        }
    }
    return found; // Event not found
}

// The  following function is used to read event data from a file to the structure.
void toStructure()
{
    FILE *file = fopen("events.txt", "r"); // To open the file  in read mode

    // check if there is a file
    if (file == NULL)
    {
        printf("Error: Could not open 'events.txt'.\n");
        return;
    }

    // To read event details from the file and then copy the information to event structure
    while(fscanf(file, "%d,%49[^,],%d,%d",  &events[eventCount].eventID, events[eventCount].eventName,
        &events[eventCount].totalSeats,  &events[eventCount].availableSeats) == 4)
    {
        eventCount++;
    }

    fclose(file); // Close file
    printf("\n");
}
// The following function is  used to generate a booking report
void report()
{
    if (userCount ==  0) // If there are no bookings
    {
        printf("No bookings have been made  yet.\n\n");
        return;
    }

    // display header for report
    printf("\n%-5s %-15s %-15s %-15s\n", "No.", "Event  ID", "User ID", "Seat ID");
    printf("--------------------------------------------------------------\n");

    // To  Print each booking which had been made
    for (int i = 0; i <  userCount; i++)
    {
        printf("%-5d %-15d %-15d  %-15d\n", i + 1, users[i].eventID, users[i].userID,  users[i].seatID);
    }

    printf("\n");
}

