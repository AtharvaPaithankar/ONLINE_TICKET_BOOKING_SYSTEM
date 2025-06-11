# ONLINE_TICKET_BOOKING_SYSTEM
Overview
This is a simple console-based Online Ticket Booking System implemented in C++. It allows users to view available events, book tickets, cancel bookings, and view all bookings. The system uses basic concepts of object-oriented programming and standard library containers for data management.

Features
View Events
Users can view all the available events along with the number of seats left for each.

Book Tickets
Allows a user to book tickets for a specific event by entering the event ID, their name, and the number of seats.

Cancel Tickets
Users can cancel a booking by providing their booking ID. The seats are restored upon cancellation.

View Bookings
Displays all the bookings made during the session, including user name, event ID, and number of seats booked.

Save to File
Before exiting, the system writes all booking data to a file named bookings.txt.

Concepts Used
Object-Oriented Programming (OOP)
The system uses classes (Event, Booking, BookingSystem) to encapsulate data and related functions.

Data Structures
std::vector is used to store the list of events and bookings dynamically.
std::string handles user inputs and event names.

Control Structures
for loops and if conditions manage flow control and selection logic.

A do-while loop is used for the main menu to keep the system interactive until the user chooses to exit.
