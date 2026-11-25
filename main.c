
// ******************************************************************************
// --------------------------DOCUMENTATION---------------------------------------
//  * Project Name   : Address Book Management System
//  * File Name      : main.c /Shravan_Gopal_AddressBook_zip
//  * Author         : Shravan Gopal
//  * Batch no       : 26005D_188
//  * Course         : Embedded Systems
//  * Organization   : Emertxe Information Technologies
//  * Language       : C
//  * Compiler       : GCC
//  * Operating System : Linux
//  *
//  * Description:
//  * ---------------
//  * This project implements an Address Book Management System that allows
//  * users to manage contact information efficiently. The application supports
//  * operations such as adding, searching, editing, deleting, listing, saving,
//  * and loading contacts using file handling techniques.
//  *
//  * Features:
//  * ---------
//  * - Add new contacts
//  * - Search contacts
//  * - Edit existing contacts
//  * - Delete contacts
//  * - Display all contacts
//  * - Save contacts to a file
//  * - Load contacts from a file
//  *
//  * Date Created   : 25/06/2026
//  * Last Modified  : 09/07/2026
//  * Version        : 1.0
//  ******************************************************************************

#include <stdio.h>
#include "contact.h"
  // Main function of the Address Book Management System.

int main() {
    int choice;
    AddressBook addressBook;
    initialize(&addressBook); // Initialize the address book

    do {
        printf("\nAddress Book Menu:\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
                // Perform the selected operation.

        switch (choice) {
            case 1:
                createContact(&addressBook);
                break;
            case 2:
                searchContact(&addressBook);
                break;
            case 3:
              printf("Select sort criteria:\n");
                printf("1. Sort by name\n");
                printf("2. Sort by phone\n");
                printf("3. Sort by email\n");
                printf("Enter your choice: ");
                int sortchoice1;
                scanf("%d", &sortchoice1);
                editContact(&addressBook,sortchoice1);
                break;
            case 4:
                deleteContact(&addressBook);
                break;
            case 5:
                printf("Select sort criteria:\n");
                printf("1. Sort by name\n");
                printf("2. Sort by phone\n");
                printf("3. Sort by email\n");
                printf("Enter your choice: ");
                int sortChoice;
                scanf("%d", &sortChoice);
                listContacts(&addressBook, sortChoice);
                break;
            case 6:
                printf("Saving and Exiting...\n");
                                // Save all contacts before exiting.

                saveContactsToFile(&addressBook);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
        // End of the program.

       return 0;
}
