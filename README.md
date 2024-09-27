Econ-Flight Airline Reservation Program

Overview

The Econ-Flight Airline Reservation Program is a C program that allows users to select and modify seat reservations for an airline. The program supports saving seat arrangements to an external file, enabling users to persist data between sessions.

Features

- View all seat assignments, including empty and occupied seats.
- Display a list of empty seats along with the total count.
- Show only the assigned seats along with the passenger names.
- Assign a passenger to an empty seat.
- Delete a specific seat assignment.
- Reset all seat assignments to empty.
- Load saved seat assignments from a file.

Getting Started

Prerequisites

- A C compiler (e.g., GCC) installed on your machine.
- A terminal or command prompt for compiling and running the program.

Compilation

To compile the program, use the following command in your terminal:

bash
gcc -o airline_reservation airline_reservation.c

Running the Program

To run the program, execute the following command:

bash

./airline_reservation

Usage Instructions

    Upon launching the program, a start menu will display, prompting you to view the main menu.

    Select an option from the menu to manage seat assignments:
        a: Display all seat assignments.
        b: Show a list of empty seats.
        c: Show assigned seats with passenger names.
        d: Assign a customer to an empty seat.
        e: Delete a specific seat assignment.
        f: Reset all seat assignments.
        g: Quit the program.
        h: Load saved seat assignments from a file.

    Follow the prompts to enter or modify seat assignments as needed.

File Handling

    The program saves seat data to airlineSeating.txt.
    On program startup, users can load previously saved data to restore their seat assignments.
