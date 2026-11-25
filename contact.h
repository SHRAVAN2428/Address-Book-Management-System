#ifndef CONTACT_H
#define CONTACT_H
// Maximum number of contacts that can be stored. declared by MACRO

#define MAX_CONTACTS 100
// Structure to store contact details.

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;
// Structure to store all contacts and contact count.

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;
  /// Creates a new contact.
void createContact(AddressBook *addressBook);

// Searches for a contact.
void searchContact(AddressBook *addressBook);

// Edits an existing contact.
void editContact(AddressBook *addressBook, int sortcriteria);

// Deletes a contact.
void deleteContact(AddressBook *addressBook);

// Lists all contacts.
void listContacts(AddressBook *addressBook, int sortCriteria);

// Initializes the address book.
void initialize(AddressBook *addressBook);

// Saves all contacts to the file.
void saveContactsToFile(AddressBook *AddressBook);

#endif
