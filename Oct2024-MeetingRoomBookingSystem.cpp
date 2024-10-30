#include <stdio.h>
#include <stdlib.h>

struct TimeSlot {
    int hour;    
    int isBooked; 
};


struct MeetingRoom{
    int floorNumber;
    int roomNumber;
    struct TimeSlot timeSlots[10]; 
};


void startMenu(){
    printf("\n=== Menu ===\n");
    printf("1. Start\n");
    printf("2. Exit\n");
    printf("Enter the number to proceed: ");
}


void reservationMenu(){
    printf("\n=== Meeting Room Reservation ===\n");
    printf("1. Make a booking\n");
    printf("2. Cancel a booking\n");
    printf("3. Exit\n");
    printf("Enter the number to proceed: ");
}


void NovemberCalendar() {
    printf("\n-- November 2024 --\n");
    printf(" S  M  T  W  T  F  S\n");
    printf("               01 02\n");
    printf("03 04 05 06 07 08 09\n");
    printf("10 11 12 13 14 15 16\n");
    printf("17 18 19 20 21 22 23\n");
    printf("24 25 26 27 28 29 30\n");
}


int dateValidation(int date) {
    if (date >= 1 && date <= 30) {
        return 1;
    }
    return 0;
}


void bookMeetingRoom(struct MeetingRoom rooms[], int numRooms){
    printf("Select Floor (5, 6, 7): ");
    int floorNumber;
    scanf("%d", &floorNumber);

    printf("\nAvailable Rooms:\n");
    for (int i = 0; i < numRooms; i++) {
        if (rooms[i].floorNumber == floorNumber) {
            printf("Room %d\n", rooms[i].roomNumber);
        }
    }

    printf("Enter room number to book: ");
    int roomNumber;
    scanf("%d", &roomNumber);
    
    int roomIndex = -1;

    for (int i = 0; i < numRooms; i++){
    	if (rooms[i].roomNumber == roomNumber && rooms[i].floorNumber == floorNumber){
    		roomIndex = i;
    		break;
		}
	}
	
	if (roomIndex == -1){
		printf("Invalid room selection.\n");
		return;
	}

    NovemberCalendar();
    printf("Select Date to book (e.g., 09 for November 9): ");
    int date;
    scanf("%d", &date);

    if (!dateValidation(date)) {
        printf("Invalid date. Please choose a valid date in November 2024.\n");
        return;
    }

    printf("Available time slots (8am - 5pm):\n");
    for (int i = 0; i < 10; i++) {
        if (!rooms[roomIndex].timeSlots[i].isBooked) {
            printf("%d:00 - Available\n", rooms[roomIndex].timeSlots[i].hour);
        } else {
            printf("%d:00 - Booked\n", rooms[roomIndex].timeSlots[i].hour);
        }
    }

    printf("Enter the hour to book (8 to 17): ");
    int hour;
    scanf("%d", &hour);

    if (hour < 8 || hour > 17 || rooms[roomIndex].timeSlots[hour - 8].isBooked) {
        printf("Invalid or already booked time slot.\n");
    } else {
        rooms[roomIndex].timeSlots[hour - 8].isBooked = 1;
        printf("Meeting room %d on floor %d successfully booked for 2024-11-%02d at %d:00.\n",
               rooms[roomIndex].roomNumber, rooms[roomIndex].floorNumber, date, hour);
    }
}

void cancelBooking(struct MeetingRoom rooms[], int numRooms){
    printf("Select Floor (5, 6, 7): ");
    int floorNumber;
    scanf("%d", &floorNumber);

    printf("Enter room number to cancel booking: ");
    int roomNumber;
    scanf("%d", &roomNumber);

    int roomIndex = -1;

    for (int i = 0; i < numRooms; i++){
    	if (rooms[i].roomNumber == roomNumber && rooms[i].floorNumber == floorNumber){
    		roomIndex = i;
    		break;
		}
	}
	
	if (roomIndex == -1){
		printf("Invalid room selection.\n");
		return;
	}

    printf("Enter the hour to cancel (8 to 17): ");
    int hour;
    scanf("%d", &hour);

    if (hour < 8 || hour > 17 || !rooms[roomIndex].timeSlots[hour - 8].isBooked) {
        printf("Invalid or not booked time slot.\n");
    } else {
        rooms[roomIndex].timeSlots[hour - 8].isBooked = 0;
        printf("Booking for room %d on floor %d at %d:00 has been successfully canceled.\n",
               rooms[roomIndex].roomNumber, rooms[roomIndex].floorNumber, hour);
    }
}

int main(){

    struct MeetingRoom rooms[9] = {
        {5, 501, {{8, 0}, {9, 0}, {10, 0}, {11, 0}, {12, 0}, {13, 0}, {14, 0}, {15, 0}, {16, 0}, {17, 0}}},
        {5, 502, {{8, 0}, {9, 0}, {10, 0}, {11, 0}, {12, 0}, {13, 0}, {14, 0}, {15, 0}, {16, 0}, {17, 0}}},
        {5, 503, {{8, 0}, {9, 0}, {10, 0}, {11, 0}, {12, 0}, {13, 0}, {14, 0}, {15, 0}, {16, 0}, {17, 0}}},
        {6, 601, {{8, 0}, {9, 0}, {10, 0}, {11, 0}, {12, 0}, {13, 0}, {14, 0}, {15, 0}, {16, 0}, {17, 0}}},
        {6, 602, {{8, 0}, {9, 0}, {10, 0}, {11, 0}, {12, 0}, {13, 0}, {14, 0}, {15, 0}, {16, 0}, {17, 0}}},
        {6, 603, {{8, 0}, {9, 0}, {10, 0}, {11, 0}, {12, 0}, {13, 0}, {14, 0}, {15, 0}, {16, 0}, {17, 0}}},
        {7, 701, {{8, 0}, {9, 0}, {10, 0}, {11, 0}, {12, 0}, {13, 0}, {14, 0}, {15, 0}, {16, 0}, {17, 0}}},
        {7, 702, {{8, 0}, {9, 0}, {10, 0}, {11, 0}, {12, 0}, {13, 0}, {14, 0}, {15, 0}, {16, 0}, {17, 0}}},
        {7, 703, {{8, 0}, {9, 0}, {10, 0}, {11, 0}, {12, 0}, {13, 0}, {14, 0}, {15, 0}, {16, 0}, {17, 0}}},
    };
    int numRooms = 9;
    int startChoice;
    
    startMenu();
	scanf("%d", &startChoice);
	
	if (startChoice==1){
	    while(1){
		    reservationMenu();
		    int menuChoice;
		    scanf("%d", &menuChoice);
		    
		    switch (menuChoice){
		    case 1:
		        bookMeetingRoom(rooms, numRooms);
		        break;
		    case 2:
		        cancelBooking(rooms, numRooms);
		        break;
		    case 3:
		        printf("Exiting the program.\n");
		        return 0;
		    default:
		        printf("Invalid choice. Please try again.\n");
		    }
	    }
	}
	else if (startChoice == 2){
	    printf("Exiting the program.\n");
	}
	else{
	    printf("Invalid choice. Please try again.\n");
	}
    return 0;
}

