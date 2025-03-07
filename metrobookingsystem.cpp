#include <iostream> 
#include <limits> 
#include <ctime> 
#include <iomanip> 
#include <fstream> 
#include <cctype> 
#include <cstring> 
#include <sstream> 
using namespace std; 
class Metro { 
private: 
int from[100], to[100], no[100], type[100]; 
float fare[100]; 
char ans[10]; 
int bookingCount; 
char adminPassword[20]; 
int nextTicketId; // To generate unique ticket IDs 
// Structure to hold booking details with tm for date and time 
struct Booking { 
int id; // Unique ticket ID 
int from; 
int to; 
int no; 
int type; 
float fare; 
tm dateTime; // Use tm structure to hold date and time 
} bookings[100]; 

public: 
Metro() : bookingCount(0), nextTicketId(1) { 
strcpy(adminPassword, "admin123"); 
loadBookings(); 
} 
void booking(); 
void timetable(); 
void station(); 
void contact_us(); 
void menu(); 
void show_bookings(); // Method to show booking details 
void adminLogin(); // Admin login method 
void displayAllBookings(); // Method to display all bookings 
void saveBookings(); // Save bookings to file 
void loadBookings(); // Load bookings from file 
void cancelBooking(); // Method to cancel a booking 
}; 
// Function to display the menu and handle user choices 
void Metro::menu() { 
int x; 
cout << "\n\n\n\t\t\t___HOME___"; 
cout << "\n\t\t\t1. Booking\n\t\t\t2. Timetable\n\t\t\t3. Stations\n\t\t\t4. Contact 
us\n\t\t\t5. Show Bookings\n\t\t\t6. Cancel Booking\n\t\t\t7. Admin Login\n\t\t\t8. 
Exit\n"; 
cout << "Choose the Operation: "; 
cin >> x; 
// Validate input 
while (cin.fail() || x < 1 || x > 8) { 
cin.clear(); // Clear the error flag 
  
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input 
        cout << "Invalid choice. Please enter a number between 1 and 8: "; 
        cin >> x; 
    } 
 
    switch (x) { 
        case 1: 
            booking(); 
            break; 
        case 2: 
            timetable(); 
            break; 
        case 3: 
            station(); 
            break; 
        case 4: 
            contact_us(); 
            break; 
        case 5: 
            show_bookings(); // Show bookings 
            break; 
        case 6: 
            cancelBooking(); // Cancel booking 
            break; 
        case 7: 
            adminLogin(); // Admin login 
            break; 
        case 8: 
            saveBookings(); // Save bookings to file before exiting 
            cout << "Your feedback is valuable for us!\n\n"; 
            cout << "Please let us know what you think.\n\n"; 
            cout << "Thanks for visiting!!!!\n\n"; 
            break; 
default: 
cout << "Enter the correct operation.\n"; 
} 
} 
// Function to display available stations 
void Metro::station() { 
cout << "\t\t\t___Available Stations: ___\n"; 
cout << "\n\t\t\t1. Kashmere Gate\n\t\t\t2. Rohini East\n\t\t\t3. Karol Bagh\n\t\t\t4. 
Noida\n\t\t\t5. Rithala\n"; 
cout << "\t\t\t___We are coming soon to other areas__\n"; 
cout << "Do you want to go home (YES/yes): "; 
cin >> ans; 
if (strcmp(ans, "YES") == 0 || strcmp(ans, "yes") == 0 || strcmp(ans, "Yes") == 0) 
menu(); 
else 
cout << "\t\t\t\t\t\t\t\tThanks for visiting-_-\n"; 
} 
// Function to display the timetable 
void Metro::timetable() { 
cout << "Operational Section: Kashmere Gate to Rithala\n"; 
cout << "Frequency of Trains: 10 mins\n"; 
cout << "Off Peak Frequency: 15 mins\n"; 
cout << "Service Time: 7 am to 10 pm (15 hrs)\n"; 
cout << "Station Stopping Time: 30 Sec\n"; 
cout << "Travel Time from Kashmere Gate to Rithala: 25 mins\n"; 
cout << "Do you want to go home (YES/yes): "; 
cin >> ans; 
if (strcmp(ans, "YES") == 0 || strcmp(ans, "yes") == 0 || strcmp(ans, "Yes") == 0) 
menu(); 

else 
cout << "\t\t\t\t\t\t\t\t\t\t\nThanks for visiting\n"; 
} 
// Function to handle booking and fare calculation 
void Metro::booking() { 
float fare; 
cout << "__WELCOME TO METRO TICKET BOOKING_" << endl; 
cout << "\n1. Kashmere Gate\n2. Rohini East\n3. Karol Bagh\n4. Noida\n5. Rithala\n"; 
cout << "SOURCE STATION (1-5): "; 
cin >> from[bookingCount]; 
cout << "DESTINATION STATION (1-5): "; 
cin >> to[bookingCount]; 
cout << "Number of Tickets : "; 
cin >> no[bookingCount]; 
cout << "Journey type:\n1. One Way\n2. Return\n"; 
cin >> type[bookingCount]; 
// Validate input 
while (cin.fail() || no[bookingCount] <= 0 || (type[bookingCount] != 1 && 
type[bookingCount] != 2) || from[bookingCount] < 1 || from[bookingCount] > 5 || 
to[bookingCount] < 1 || to[bookingCount] > 5) { 
cin.clear(); // Clear the error flag 
cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input 
cout << "Invalid input. Please enter valid values.\n"; 
cout << "SOURCE STATION (1-5): "; 
cin >> from[bookingCount]; 
cout << "DESTINATION STATION (1-5): "; 
cin >> to[bookingCount]; 
cout << "Number of Tickets: "; 
cin >> no[bookingCount]; 
cout << "Journey type:\n1. One Way\n2. Return\n"; 
cin >> type[bookingCount]; 
  
} 
// Fare calculation 
if ((from[bookingCount] == 1 && to[bookingCount] == 2) || (from[bookingCount] == 
2 && to[bookingCount] == 1)) { 
fare = (10.50 * no[bookingCount]) * type[bookingCount]; 
} 
else 
if 
((from[bookingCount] == 2 && to[bookingCount] == 3) || 
(from[bookingCount] == 3 && to[bookingCount] == 2)) { 
fare = (17.50 * no[bookingCount]) * type[bookingCount]; 
} 
else 
if 
((from[bookingCount] == 2 && to[bookingCount] == 4) || 
(from[bookingCount] == 4 && to[bookingCount] == 2)) { 
fare = (17.50 * no[bookingCount]) * type[bookingCount]; 
} 
else 
if 
((from[bookingCount] == 3 && to[bookingCount] == 4) || 
(from[bookingCount] == 4 && to[bookingCount] == 3)) { 
fare = (7.00 * no[bookingCount]) * type[bookingCount]; 
} 
else 
if 
((from[bookingCount] == 1 && to[bookingCount] == 3) || 
(from[bookingCount] == 3 && to[bookingCount] == 1)) { 
fare = (21.00 * no[bookingCount]) * type[bookingCount]; 
} 
else 
if 
((from[bookingCount] == 1 && to[bookingCount] == 4) || 
(from[bookingCount] == 4 && to[bookingCount] == 1)) { 
fare = (21.00 * no[bookingCount]) * type[bookingCount]; 
} 
else 
if 
((from[bookingCount] == 1 && to[bookingCount] == 5) || 
(from[bookingCount] == 5 && to[bookingCount] == 1)) { 
fare = (31.00 * no[bookingCount]) * type[bookingCount]; 
} 
else 
if 
((from[bookingCount] == 2 && to[bookingCount] == 5) || 
(from[bookingCount] == 5 && to[bookingCount] == 2)) { 
fare = (31.00 * no[bookingCount]) * type[bookingCount]; 
} 
else 
if 
((from[bookingCount] == 3 && to[bookingCount] == 5) || 
(from[bookingCount] == 5 && to[bookingCount] == 3)) { 
fare = (31.00 * no[bookingCount]) * type[bookingCount]; 
} else if ((from[bookingCount] == 4 && to[bookingCount] == 5) || 
(from[bookingCount] == 5 && to[bookingCount] == 4)) { 
fare = (21.00 * no[bookingCount]) * type[bookingCount]; 
} else { 
  
fare = 0; 
cout << "Invalid route. Please try again.\n"; 
return; 
} 
bookings[bookingCount].id = nextTicketId++; // Assign ticket ID and increment 
counter 
bookings[bookingCount].from = from[bookingCount]; 
bookings[bookingCount].to = to[bookingCount]; 
bookings[bookingCount].no = no[bookingCount]; 
bookings[bookingCount].type = type[bookingCount]; 
bookings[bookingCount].fare = fare; 
time_t now = time(0); 
bookings[bookingCount].dateTime = *localtime(&now); 
bookingCount++; 
cout << "Booking Successful! Your Ticket ID is " << bookings[bookingCount - 1].id 
<< " and fare is Rs " << fare << endl; 
cout << "Do you want to go home (YES/yes): "; 
cin >> ans; 
if (strcmp(ans, "YES") == 0 || strcmp(ans, "yes") == 0 || strcmp(ans, "Yes") == 0) 
menu(); 
else 
cout << "\t\t\t\t\t\t\t\t\t\tThanks for visiting\n"; 
} 
// Function to format date and time using strftime 
void formatDateTime(const tm& dateTime, char* buffer, size_t bufferSize) { 
strftime(buffer, bufferSize, "%Y-%m-%d %H:%M:%S", &dateTime); 
} 
  
// Function to display booking details 
void Metro::show_bookings() { 
cout << "__CURRENT BOOKINGS__\n"; 
for (int i = 0; i < bookingCount; ++i) { 
cout << "Ticket ID: " << bookings[i].id << "\n"; 
cout << "From Station: " << bookings[i].from << "\n"; 
cout << "To Station: " << bookings[i].to << "\n"; 
cout << "Number of Tickets: " << bookings[i].no << "\n"; 
cout << "Journey Type: " << (bookings[i].type == 1 ? "One Way" : "Return") << 
"\n"; 
} 
cout << "Fare: " << bookings[i].fare << "\n"; 
char dateTimeBuffer[20]; 
formatDateTime(bookings[i].dateTime, dateTimeBuffer, sizeof(dateTimeBuffer)); 
cout << "Date & Time: " << dateTimeBuffer << "\n\n"; 
cout << "Do you want to go home (YES/yes): "; 
cin >> ans; 
if (strcmp(ans, "YES") == 0 || strcmp(ans, "yes") == 0 || strcmp(ans, "Yes") == 0) 
menu(); 
else 
cout << "\t\t\t\t\t\t\t\t\t\tThanks for visiting\n"; 
} 
// Function to display all bookings (admin functionality) 
void Metro::displayAllBookings() { 
cout << "__ALL BOOKINGS__\n"; 
for (int i = 0; i < bookingCount; ++i) { 
cout << "Ticket ID: " << bookings[i].id << "\n"; 
cout << "From Station: " << bookings[i].from << "\n"; 
  
cout << "To Station: " << bookings[i].to << "\n"; 
cout << "Number of Tickets: " << bookings[i].no << "\n"; 
cout << "Journey Type: " << (bookings[i].type == 1 ? "One Way" : "Return") << 
"\n"; 
} 
cout << "Fare: " << bookings[i].fare << "\n"; 
char dateTimeBuffer[20]; 
formatDateTime(bookings[i].dateTime, dateTimeBuffer, sizeof(dateTimeBuffer)); 
cout << "Date & Time: " << dateTimeBuffer << "\n\n"; 
cout << "Do you want to go home (YES/yes): "; 
cin >> ans; 
if (strcmp(ans, "YES") == 0 || strcmp(ans, "yes") == 0 || strcmp(ans, "Yes") == 0) 
menu(); 
else 
cout << "\t\t\t\t\t\t\t\t\t\tThanks for visiting\n"; 
} 
// Function to handle ticket cancellation 
void Metro::cancelBooking() { 
int ticketId; 
cout << "Enter Ticket ID to Cancel: "; 
cin >> ticketId; 
for (int i = 0; i < bookingCount; ++i) { 
if (bookings[i].id == ticketId) { 
for (int j = i; j < bookingCount - 1; ++j) { 
bookings[j] = bookings[j + 1]; 
} --bookingCount; 
cout << "Booking with Ticket ID " << ticketId << " has been cancelled.\n"; 
  
saveBookings(); // Save changes to file 
return; 
} 
} 
cout << "Ticket ID not found.\n"; 
} 
// Function to handle admin login 
void Metro::adminLogin() { 
char password[20]; 
cout << "Enter Admin Password: "; 
cin >> password; 
if (strcmp(password, adminPassword) == 0) { 
displayAllBookings(); 
} else { 
cout << "Invalid password.\n"; 
} 
} 
// Function to save bookings to a file 
void Metro::saveBookings() { 
ofstream file("bookings.dat", ios::binary); 
if (file.is_open()) { 
file.write(reinterpret_cast<char*>(&bookingCount), sizeof(bookingCount)); 
file.write(reinterpret_cast<char*>(&nextTicketId), sizeof(nextTicketId)); 
file.write(reinterpret_cast<char*>(bookings), sizeof(bookings)); 
file.close(); 
} else { 
cout << "Unable to open file for saving bookings.\n"; 
} 
} 
  
// Function to load bookings from a file 
void Metro::loadBookings() { 
ifstream file("bookings.dat", ios::binary); 
if (file.is_open()) { 
file.read(reinterpret_cast<char*>(&bookingCount), sizeof(bookingCount)); 
file.read(reinterpret_cast<char*>(&nextTicketId), sizeof(nextTicketId)); 
file.read(reinterpret_cast<char*>(bookings), sizeof(bookings)); 
file.close(); 
} else { 
cout << "No previous booking data found.\n"; 
} 
} 
// Function to display contact information 
void Metro::contact_us() { 
cout << "For any queries, please contact:\n"; 
cout << "Metro Customer Service: 123-456-7890\n"; 
cout << "Email: support@metro.com\n"; 
cout << "Address: 123 Metro Street, City, Country\n"; 
cout << "Do you want to go home (YES/yes): "; 
cin >> ans; 
if (strcmp(ans, "YES") == 0 || strcmp(ans, "yes") == 0 || strcmp(ans, "Yes") == 0) 
menu(); 
else 
cout << "\t\t\t\t\t\t\t\t\t\tThanks for visiting\n"; 
} 
// Main function 
int main() { 
Metro m; 
m.menu(); 
  
  
    return 0; 
}