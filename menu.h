#include<stdio.h>
void menu (void)
{
    printf("\nCar Rental Menu\n");
    printf("-----------------\n");
    printf("1. Display available cars\n");
    printf("2. Rent a car\n");
    printf("3. Return a car\n");
    printf("4. Exit\n");
}



void exit_program(void)
 {
     system("cls");
    printf("                ...Thank you for using the Car Rental Management System. Goodbye!...\n");
    sleep(1);
    exit(0); // Terminate the program with a status code of 0
 }

