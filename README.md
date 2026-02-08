# INET3101 Module 3 Assignment 3

Airline Seat Reservation System

# Problem Statement

The purpose of this assignment is to create a C program that manages seat reservations for an airline with one airplane and 24 seats. The airplane operates two flights per day: outbound and inbound. The program must use an array of structures to store seat information and provide a menu-driven system for managing seat assignments.

# Describe the Solution

The solution uses a structure to represent each seat, storing the seat number, assignment status, and passenger name. Two arrays of this structure are used to manage seats for the outbound and inbound flights separately. The program provides a main menu to select a flight and a secondary menu to view seat availability, assign seats, and delete seat assignments. Each task is handled using separate functions for clarity.

# Pros and Cons of the Solution

### Pros
- The program follows the assignment requirements by using structures and arrays.
- The menu-driven design is easy to understand and use.
- The code is organized and modular.

### Cons
- Seat data is not saved after the program ends.
- The program supports only a fixed number of seats and flights.
