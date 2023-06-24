#include <stdio.h>
#include <stdlib.h>
#include"splash.h"
#include"login.h"
#include"menu.h"

void rentCar();
void generateBill(int hours);
void returnCar();
void displayAvailableCars();
void clearInputBuffer();
void printSeparatorLine();

// Structure to represent a car
typedef struct {
    int id;
    char name[50];
    int available;
} Car;



int main()
{
    recursiveLoading(0); //use of recursion
    splash();
    system("cls");
    login();
    menu();
    rentCar();
    return 0;
}
void rentCar() {
    int carId;
    printf("\nEnter your choice: ");
    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            displayAvailableCars();
            break;
        case 2:
            printf("\nEnter the car ID you want to rent: ");
            scanf("%d", &carId);
            rentCarById(carId);
            break;
        case 3:
            returnCar();
            break;
        case 4:
            exit_program();
        default:
            printf("\nInvalid choice. Please try again.\n");
            rentCar();
            break;
    }
}

void displayAvailableCars() {
    printf("\nAvailable Cars\n");
    printf("--------------\n");

    // Assuming we have an array of Car structures
    Car cars[] = {
        {1, "Toyota Camry", 1},
        {2, "Honda Civic", 1},
        {3, "Ford Mustang", 0}, // Car 3 is already rented
        {4, "Chevrolet Cruze", 1}
    };

    int numCars = sizeof(cars) / sizeof(Car);
    printf("%-5s %-20s\n", "ID", "Car Name");
    printSeparatorLine();

    for (int i = 0; i < numCars; i++) {
        if (cars[i].available) {
            printf("%-5d %-20s\n", cars[i].id, cars[i].name);
        }
    }
    printf("Enter 2 if you want to rent a car");
    rentCar();
}

void rentCarById(int carId) {
    int rentalDuration;
    // Assuming we have an array of Car structures
    Car cars[] = {
        {1, "Toyota Camry", 1},
        {2, "Honda Civic", 1},
        {3, "Ford Mustang", 0}, // Car 3 is already rented
        {4, "Chevrolet Cruze", 1}
    };

    int numCars = sizeof(cars) / sizeof(Car);
    int carFound = 0;

    for (int i = 0; i < numCars; i++) {
        if (cars[i].id == carId) {
            carFound = 1;
            if (cars[i].available) {
                printf("\nRenting the car '%s'...\n", cars[i].name);
                cars[i].available = 0; // Mark the car as rented
                printf("Enter the rental duration in hours: ");
                scanf("%d", &rentalDuration);
                generateBill(rentalDuration); // Start the bill with 0 hours
            } else {
                printf("\nCar '%s' is already rented.\n", cars[i].name);
            }
            break;
        }
    }

    if (!carFound) {
        printf("\nCar with ID '%d' not found.\n", carId);
    }

    rentCar();
}

void generateBill(int hours) {
    // Assuming the rental rate is $10 per hour
    int rate = 10;

    // Calculate the bill
    int bill = rate * hours;

    printf("Your total bill is $%d.\n", bill);
    menu();
    // Ask for return options
    rentCar();
}

void returnCar() {
    int carId;
    int rentalDuration;

    printf("\nEnter the car ID you want to return: ");
    scanf("%d", &carId);

    // Assuming we have an array of Car structures
    Car cars[] = {
        {1, "Toyota Camry", 1},
        {2, "Honda Civic", 1},
        {3, "Ford Mustang", 0},
        {4, "Chevrolet Cruze", 1}
    };

    int numCars = sizeof(cars) / sizeof(Car);
    int carFound = 0;

    for (int i = 0; i < numCars; i++) {
        if (cars[i].id == carId) {
            carFound = 1;
            if (!cars[i].available) {
                printf("\nReturning the car '%s'...\n", cars[i].name);
                cars[i].available = 1; // Mark the car as available
                printf("Enter the rental duration in hours: ");
                scanf("%d", &rentalDuration);
                generateBill(rentalDuration);
            } else {
                printf("\nCar '%s' is already available.\n", cars[i].name);
            }
            break;
        }
    }

    if (!carFound) {
        printf("\nCar with ID '%d' not found.\n", carId);
    }

    rentCar();
}

void clearInputBuffer() {
    while (getchar() != '\n');
}

void printSeparatorLine() {
    printf("------------------------------------------------------------\n");
}
