// BookingSystem.h
#ifndef BOOKINGSYSTEM_H
#define BOOKINGSYSTEM_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

struct Event {
    int id;
    std::string name;
    int totalSeats;
    int bookedSeats;

    Event(int id_, const std::string& name_, int total)
        : id(id_), name(name_), totalSeats(total), bookedSeats(0) {}

    int getAvailableSeats() const {
        return totalSeats - bookedSeats;
    }
};

struct Booking {
    int bookingId;
    int eventId;
    std::string userName;
    int seatCount;
};

class BookingSystem {
    std::vector<Event> events;
    std::vector<Booking> bookings;
    int nextBookingId;

public:
    BookingSystem();
    void loadEvents();
    void showEvents();
    void bookTicket();
    void cancelTicket();
    void viewBookings();
    void saveBookingsToFile();
};

#endif


BookingSystem::BookingSystem() {
    nextBookingId = 1;
    loadEvents();
}

void BookingSystem::loadEvents() {
    events.push_back(Event(1, "Movie: Inception", 50));
    events.push_back(Event(2, "Movie: Interstellar", 40));
    events.push_back(Event(3, "Concert: Arijit Singh", 100));
}

void BookingSystem::showEvents() {
    std::cout << "\nAvailable Events:\n";
    for (const auto& e : events) {
        std::cout << e.id << ". " << e.name << " (Available Seats: " << e.getAvailableSeats() << ")\n";
    }
}

void BookingSystem::bookTicket() {
    int eventId, seats;
    std::string name;

    showEvents();
    std::cout << "\nEnter Event ID to book: ";
    std::cin >> eventId;
    std::cin.ignore();
    std::cout << "Enter your name: ";
    getline(std::cin, name);
    std::cout << "Enter number of seats: ";
    std::cin >> seats;

    for (auto& e : events) {
        if (e.id == eventId) {
            if (e.getAvailableSeats() >= seats) {
                e.bookedSeats += seats;
                Booking b = { nextBookingId++, eventId, name, seats };
                bookings.push_back(b);
                std::cout << "\nBooking Confirmed! Booking ID: " << b.bookingId << "\n";
                return;
            } else {
                std::cout << "\nNot enough seats available!\n";
                return;
            }
        }
    }
    std::cout << "\nInvalid Event ID.\n";
}

void BookingSystem::cancelTicket() {
    int bookingId;
    std::cout << "\nEnter Booking ID to cancel: ";
    std::cin >> bookingId;

    for (size_t i = 0; i < bookings.size(); ++i) {
        if (bookings[i].bookingId == bookingId) {
            for (auto& e : events) {
                if (e.id == bookings[i].eventId) {
                    e.bookedSeats -= bookings[i].seatCount;
                    break;
                }
            }
            bookings.erase(bookings.begin() + i);
            std::cout << "Booking Cancelled.\n";
            return;
        }
    }
    std::cout << "\nBooking ID not found.\n";
}

void BookingSystem::viewBookings() {
    std::cout << "\nAll Bookings:\n";
    for (const auto& b : bookings) {
        std::cout << "Booking ID: " << b.bookingId << ", User: " << b.userName
                  << ", Event ID: " << b.eventId << ", Seats: " << b.seatCount << "\n";
    }
    if (bookings.empty()) {
        std::cout << "No bookings found.\n";
    }
}

void BookingSystem::saveBookingsToFile() {
    std::ofstream fout("bookings.txt");
    for (const auto& b : bookings) {
        fout << b.bookingId << " " << b.userName << " " << b.eventId << " " << b.seatCount << "\n";
    }
    fout.close();
}

int main() {
    BookingSystem system;
    int choice;
    do {
        std::cout << "\n----- Ticket Booking System -----\n";
        std::cout << "1. Show Events\n2. Book Ticket\n3. Cancel Ticket\n4. View Bookings\n5. Exit\nEnter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: system.showEvents(); break;
            case 2: system.bookTicket(); break;
            case 3: system.cancelTicket(); break;
            case 4: system.viewBookings(); break;
            case 5: system.saveBookingsToFile(); std::cout << "Exiting...\n"; break;
            default: std::cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}
