# Econ-Flight Airline Reservation Program

## Overview

The Econ-Flight Airline Reservation Program is a C program that allows users to select and modify seat reservations for an airline. The program supports saving seat arrangements to an external file, enabling users to persist data between sessions.

## Features

- View all seat assignments, including empty and occupied seats.
- Display a list of empty seats along with the total count.
- Show only the assigned seats along with the passenger names.
- Assign a passenger to an empty seat.
- Delete a specific seat assignment.
- Reset all seat assignments to empty.
- Load saved seat assignments from a file.

## Getting Started

### Prerequisites

- A C compiler (e.g., GCC) installed on your machine.
- A terminal or command prompt for compiling and running the program.

### Compilation

To compile the program, use the following command in your terminal:

```
gcc -o airline_reservation airline_reservation.c
