#include <stdio.h>
#include "file.h"
  // Saves all contacts from the address book to the CSV file.

void saveContactsToFile(AddressBook *addressBook) {
    FILE *fp = fopen("contacts.csv", "w");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    //fprintf(fp, "Name,Phone,Email\n");

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        fprintf(fp, "%s,%s,%s\n",
                addressBook->contacts[i].name,
                addressBook->contacts[i].phone,
                addressBook->contacts[i].email);
    }

    fclose(fp);

    printf("%d contacts saved successfully.\n",
           addressBook->contactCount);
}

  // Loads all contacts from the CSV file into the address book.

void loadContactsFromFile(AddressBook *addressBook) {

    FILE *fp = fopen("contacts.csv", "r");

    if (fp == NULL)
    {
        printf("contacts.csv not found. Starting with empty address book.\n");
        addressBook->contactCount = 0;
        return;
    }

    addressBook->contactCount = 0;
    while (addressBook->contactCount < MAX_CONTACTS)
    {
        Contact *c = &addressBook->contacts[addressBook->contactCount];

        if (fscanf(fp,"%49[^,],%10[^,],%49[^\n]\n",c->name,c->phone,c->email) == 3)
        {
            addressBook->contactCount++;
        }
        else
        {
            break;
        }
    }

    fclose(fp);

    printf("Loaded %d contacts successfully.\n",
       addressBook->contactCount);
}
