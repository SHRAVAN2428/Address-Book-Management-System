#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
#include <ctype.h>
#define RESET "\033[0m"
#define R "\033[1;32m"

// Displays all contacts after sorting by name, phone, or email.
void listContacts(AddressBook *addressBook, int sortCriteria) 
{
    // Sort contacts based on the chosen criteria
    switch(sortCriteria){
        case 1:
                printf("Sorting of name:\n");

         for(int i=0;i<addressBook->contactCount - 1;i++){
            for(int j=0;j<addressBook->contactCount - i -1;j++){
                if(strcasecmp(addressBook->contacts[j].name,addressBook->contacts[j+1].name) > 0){
                Contact temp = addressBook->contacts[j];
                addressBook->contacts[j] = addressBook->contacts[j+1];
                addressBook->contacts[j+1] = temp;
            }
         }
        }
             break;

        case 2:
                printf("Sorting of phone:\n");

        for(int i=0;i<addressBook->contactCount - 1;i++){
            for(int j=0;j<addressBook->contactCount - i -1;j++){
                if(strcmp(addressBook->contacts[j].phone,addressBook->contacts[j+1].phone) > 0){
                Contact temp = addressBook->contacts[j];
                addressBook->contacts[j] = addressBook->contacts[j+1];
                addressBook->contacts[j+1] = temp;
            }
         }
        }
             break;

        case 3:
        printf("Sorting of Email :\n");
        for(int i=0;i<addressBook->contactCount - 1;i++){
            for(int j=0;j<addressBook->contactCount - i -1;j++){
                if(strcmp(addressBook->contacts[j].email,addressBook->contacts[j+1].email) > 0){
                Contact temp = addressBook->contacts[j];
                addressBook->contacts[j] = addressBook->contacts[j+1];
                addressBook->contacts[j+1] = temp;
            }
         }
        }
             break;
            default : 
              printf("Invalid sortCriteria");
    }
   printf("-------------------------------------------------------------------------------\n");
    printf(R "%-6s %-20s %-15s %-30s\n" RESET, "S.No", "Name", "Phone", "Email");
printf("-------------------------------------------------------------------------------\n");

for (int i = 0; i < addressBook->contactCount; i++)
{
    printf("%-6d %-20s %-15s %-30s\n",
           i + 1,
           addressBook->contacts[i].name,
           addressBook->contacts[i].phone,
           addressBook->contacts[i].email);
}

printf("-------------------------------------------------------------------------------\n");

}
// Initializes the address book and loads contacts from the file.
void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
   // populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
   loadContactsFromFile(addressBook);
}
  // Saves all contacts to the file and exits the program.
void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}
// Validates the entered contact name.

int validatename(char *name, AddressBook *addressBook){
    int len = strlen(name);
    int i=0;
    if(len<4){
        printf("Error : Invalid input lenght should be atleast 4 \n");
        return 0;
    }
    for(i=0;i<len;i++){
        if(!(isalpha(name[i]) || name[i] == ' ' || name[i]=='.')){
            printf("Error : the name should contain alphabets , space and dot only\n");
            return 0;
        }
    }
    for(int j=0;j<addressBook->contactCount;j++)
    {
        if(strcmp(addressBook->contacts[j].name,name)==0){
            printf("Error : entered name is already present in the database,give another name\n");
            return 0;
        }
    }
    return 1;
}
// Validates the entered phone number.

  int validatephone(char *phone,AddressBook *addressBook){
    int len = strlen(phone);
    if(len!= 10){
        printf("Error : Invaild input atleat 10 digits should there in phone number\n");
        return 0;
    }
   int i = 0;
while(phone[i] != '\0')
{
    if(!(isdigit(phone[i])))
    {
    printf("Error: phone numbers should only contain digits...\n");
    return 0;
    }
    i++;
}
       if(phone[0]< '6'){
        printf("eroor : phone number only start with 6 or 9");
        return 0;
       }
    for(int j=0;j<addressBook->contactCount;j++)
    {
        if(strcmp(addressBook->contacts[j].phone,phone)==0)
        {
            printf("ERROR : This phone number already there in the list Give me another number\n");
            return 0;
        }
    }
          return 1;
  }
  // Validates the entered Email id address.

  int validateemail(char *email,AddressBook *addressBook){
    int i=0,count=0,dot=0;
    int len = strlen(email);
    while(email[i] !='\0'){
         if(!(isalnum(email[i]) || email[i]==' ' || email[i]=='@' || email[i]=='.')){
            printf("Error : invalid email type....\n");
            return 0;
         } 
         if(email[i] == '@'){
            count++;
         }
         if(email[i]=='.' && count == 1){
            dot++;
         }
         i++;
        }
         if(count>1){
            printf("Error : only one @ should be there in email.\n");
            return 0;
         }
         if(!count){
            printf("Error : minimum one @ should there,please enter @ \n");
            return 0;
         }
         if((email[len-1]!='m' || email[len-2]!= 'o' && email[len-3]!='c')){
            printf("Error : last 3 characters should be com\n");
            return 0;
         }
         if(email[len-4]!='.'){
            printf("Error : dot should be placed before com\n");
            return 0;
         }
         if(!dot){
            printf("Error : there should be one dot in email\n");
            return 0;
         }
         for(int j=0;j<addressBook->contactCount;j++)
    {
        if(strcmp(addressBook->contacts[j].email,email)==0)
        {
            printf("ERROR : This name already there in the list Give me another email\n");
            return 0;
        }
    }
    return 1;
}
// Creates a new contact after validating all details.

void createContact(AddressBook *addressBook)
{
    int ret;
	/* Define the logic to create a Contacts */
      char name[50];
      char phone[11];
      char email[50];
      do{
         printf("Enter the Name : ");
          scanf(" %[^\n]",name);
      ret = validatename(name,addressBook);
    }while(!ret);

     do{
         printf("Enter the phone Number : ");
          scanf(" %[^\n]",phone);
       ret = validatephone(phone,addressBook);
    }while(!ret);

    do{
         printf("Enter the Email : ");
          scanf(" %[^\n]",email);
      ret = validateemail(email,addressBook);
    }while(!ret);

    strcpy(addressBook->contacts[addressBook->contactCount].name, name);
    strcpy(addressBook->contacts[addressBook->contactCount].phone, phone);
    strcpy(addressBook->contacts[addressBook->contactCount].email, email);

      addressBook->contactCount++;
     printf("Contact added successfully!\n");

}
// Searches contacts by name.

   int searchname(char *name,AddressBook *addressBook,int match[]){
    int flag = 0;
    int count = 0;
    //printf("\tINDEX\t\tNAME\t\tPHONE\t\tEMAIL\n");
    printf("-------------------------------------------------------------------------------\n");
printf("%-8s %-20s %-15s %-30s\n",
       "INDEX", "NAME", "PHONE", "EMAIL");
printf("-------------------------------------------------------------------------------\n");
    for(int i=0;i<addressBook->contactCount;i++)
{
    if(strcasestr(addressBook->contacts[i].name,name))
    {
        printf("%-8d %-20s %-15s %-30s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        flag++;
        match[count] = i;
        count++;
    }
}
printf("-------------------------------------------------------------------------------\n");

if(flag == 0)
{
    printf("Contact not found\n");
    return -1;
}
  if(count ==0){
    printf("contact not found");
    return 0;
  }
  if(flag > 1)
    {
    printf("Multiple contacts found. Search by email.\n");
    }

return count;
   }
   // Searches contacts by phone number.

 int searchphone(char *phone,AddressBook *addressBook,int match[]){
    int flag =0;
    int count = 0;

        //printf("\tINDEX\t\tNAME\t\tPHONE\t\tEMAIL\n");
        printf("-------------------------------------------------------------------------------\n");
printf("%-8s %-20s %-15s %-30s\n",
       "INDEX", "NAME", "PHONE", "EMAIL");
printf("-------------------------------------------------------------------------------\n");
    for(int i=0;i<addressBook->contactCount;i++){
        if((strstr(addressBook->contacts[i].phone,phone)!= NULL))
        {
            printf("%-8d %-20s %-15s %-30s\n", i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
           // printf("|------------------|----------------------|-----------------------------|\n");
            flag++;
            match[count] =i;
            count++;
        }
    }
    if(flag == 0){
        printf("Error : contact not found\n");
        return 0;
    }
    if(count == 0){
        printf("no contact found");
        return 0;
    }
    if(flag > 1)
    {
    printf("Multiple contacts found. Search by email.\n");
    return 0;
    }

        return count;
    
 }
 // Searches contacts by Email id.

 int searchemail(char *email,AddressBook *addressBook,int match[]){
    int flag =0;
    int index;
    int count =0;
        
        printf("-------------------------------------------------------------------------------\n");
printf("%-8s %-20s %-15s %-30s\n",
       "INDEX", "NAME", "PHONE", "EMAIL");
printf("-------------------------------------------------------------------------------\n");
    for(int i=0;i<addressBook->contactCount;i++){
        if((strcasestr(addressBook->contacts[i].email,email)!= NULL))
        {
            printf("%-8d %-20s %-15s %-30s\n", i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
           // printf("|------------------|----------------------|-----------------------------|\n");
            flag++;
            match[count] = i;
            count++;
        }
    }
    if(count == 0){
        printf("Error : contact not found\n");
        return 0;
    }
    if(flag > 1)
    {
    printf("Multiple contacts found.\n");
    return 0;
    }
    return count;
    
 }
   // Provides search options and displays matching contacts.

void searchContact(AddressBook *addressBook) 
{
     int ret;
     int match[100];
    int searchchoice;
    /* Define the logic for search */
    char name[20];
    char phone[20];
    char email[50];
    printf("\nSearch Contact By\n");
    printf("1. Name\n");
    printf("2. Phone\n");
    printf("3. Email\n");
    printf("Enter the search_choice : ");
    scanf("%d",&searchchoice);
    switch(searchchoice){
        case 1: 
        printf("Enter the name : ");
        scanf(" %[^\n]",name);
        ret = searchname(name,addressBook,match);
    
    break;
    case 2 :
        printf("ENterthe phone : ");
        scanf(" %[^\n]",phone);
        ret = searchphone(phone,addressBook,match);
    break;
    case 3 :
        printf("ENterthe email : ");
        scanf(" %[^\n]",email);
        ret = searchemail(email,addressBook,match);
    break;
    case 4 :
    printf("exit......");
    break;
    default :
      printf("invalid no case is found");
}
}
// Edits an existing contact based on the selected search criteria.

    void editContact(AddressBook *addressBook, int sortchoice)
{
    int ret;
    char name[20];
    char phone[20];
    char email[50];
    int count = 0;
    int match[MAX_CONTACTS];  // Stores matching contact indexs
    switch(sortchoice)
    {
        case 1:
        do{
        printf("Enter the name: ");
        scanf(" %[^\n]",name);
        count = searchname(name,addressBook,match);
    }while(!count);
    break;
        case 2:
        do{
        printf("Enter the phone: ");
        scanf(" %[^\n]",phone);
        count = searchphone(phone,addressBook,match);
    }while(!count);
    break;
        case 3:
        do{
        printf("Enter the email: ");
        scanf(" %[^\n]",email);
        count = searchemail(email,addressBook,match);
    }while(!count);
    break;
        case 4:
        printf("Exiting...Thank you\n");
        exit(0);
        break;
    default:
    printf("Invalid input");    
}
int index;
int valid;
do
{
    valid = 0;
    printf("Enter the index to edit: ");
    scanf("%d", &index);
    index--;
    for(int i=0; i<count; i++)
    {
        if(match[i] == index)
        {
            valid = 1;
            break;
        }
    }
    if(!valid)
        printf("Invalid index. Enter one of the displayed indices.\n");
}while(!valid);

    printf("Select the edit criteria\n");
    printf("1. Edit_name\n");
    printf("2. Edit_phone\n");
    printf("3. Edit_email\n");
    printf("4. Edit_Whole_contact\n");
    printf("5. Exit\n");
    printf("Enter your choice:\n ");
    int select;
    scanf("%d",&select);
    switch(select)
    {
        case 1:
        do
        {
        printf("Enter new name: ");
        scanf(" %[^\n]", name);
        if(strcmp(name, addressBook->contacts[index].name) == 0)
        break;
        }while(!validatename(name, addressBook));
        strcpy(addressBook->contacts[index].name, name);
        printf("Name updated successfully.\n");
        break;
        case 2:
        do
        {
        printf("Enter new phone: ");
        scanf("%s", phone);
        if(strcmp(phone, addressBook->contacts[index].phone) == 0)
        break;
        }while(!validatephone(phone, addressBook));
        strcpy(addressBook->contacts[index].phone, phone);
        printf("Phone updated successfully.\n");
        break;
        break;
        case 3:
        do
        {
        printf("Enter new email: ");
        scanf("%s", email);
        if(strcmp(email, addressBook->contacts[index].email) == 0)
            break;
        }while(!validateemail(email, addressBook));
        strcpy(addressBook->contacts[index].email, email);
        printf("Email updated successfully.\n");
        break;
        case 4:
        do
        {
        printf("Enter new name: ");
        scanf(" %[^\n]", name);
        if(strcmp(name, addressBook->contacts[index].name) == 0)
        break;
        }while(!validatename(name, addressBook));
        strcpy(addressBook->contacts[index].name, name);

        do
        {
        printf("Enter new phone: ");
        scanf("%s", phone);
        if(strcmp(phone, addressBook->contacts[index].phone) == 0)
        break;
        }while(!validatephone(phone, addressBook));
        strcpy(addressBook->contacts[index].phone, phone);

        do
        {
        printf("Enter new email: ");
        scanf("%s", email);
        if(strcmp(email, addressBook->contacts[index].email) == 0)
        break;
        }while(!validateemail(email, addressBook));
        strcpy(addressBook->contacts[index].email, email);

        printf("Whole contact updated successfully.\n");
        break;
        case 5:
        printf("Exiting...Thank you\n");
        exit(0);
        break;
        default :
        printf("Invalid input\n");
    }
}
   // Deletes a contact using the contact name.

void delete_contact_name(AddressBook *addressBook, char *name) {
    int index = -1;
    for (int i = 0; i < addressBook->contactCount; i++) {
        if (strcmp(addressBook->contacts[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("ERROR : Contact not found to delete\n");
        return;
    }
    for (int i = index; i < addressBook->contactCount - 1; i++) {
        addressBook->contacts[i] = addressBook->contacts[i + 1];
    }
    addressBook->contactCount--;
    printf("Contact '%s' deleted successfully.\n", name);
}
  // Deletes a contact using the phone number.

void delete_contact_phone(AddressBook *addressBook, char *phone) {
    int index = -1;
    for (int i = 0; i < addressBook->contactCount; i++) {
        if (strcmp(addressBook->contacts[i].phone,phone) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("ERROR : Contact not found to delete\n");
        return;
    }
    for (int i = index; i < addressBook->contactCount - 1; i++) {
        addressBook->contacts[i] = addressBook->contacts[i + 1];
    }
    addressBook->contactCount--;
    printf("Contact '%s' deleted successfully.\n",phone);
}
// Deletes a contact using the email address.

void delete_contact_mail(AddressBook *addressBook, char *email) {
    int index = -1;
    for (int i = 0; i < addressBook->contactCount; i++) {
        if (strcmp(addressBook->contacts[i].email,email) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("ERROR : Contact not found to delete\n");
        return;
    }
    for (int i = index; i < addressBook->contactCount - 1; i++) {
        addressBook->contacts[i] = addressBook->contacts[i + 1];
    }
    addressBook->contactCount--;
    printf("Contact '%s' deleted successfully.\n",email);
}
// Provides delete options and removes the selected contact.

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
     int choice;
    while (1)
    {
        printf("\nEnter the choice to delete:\n");
        printf("1. Name\n2. Phone No\n3. Mail ID\n4. Exit\n");
        printf("Enter the choice: ");
        
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }
        while (getchar() != '\n'); 

        switch (choice)
        {
            case 1:
            {
                char delete_name[50];
                printf("Enter the name to delete: ");
                scanf(" %[^\n]", delete_name);
                delete_contact_name(addressBook, delete_name);
                break;
            }
            case 2:
            {
                char delete_phone[50];
                printf("Enter the phone no to delete: ");
                scanf(" %[^\n]", delete_phone);
                delete_contact_phone(addressBook, delete_phone);
                break;
            }
            case 3:
            {
                char delete_mail[50];
                printf("Enter the mail id to delete: ");
                scanf(" %[^\n]", delete_mail);
                delete_contact_mail(addressBook, delete_mail);
                break;
            }
            case 4:
                printf("Exiting delete menu...\n");
                return; 
            default:
                printf("Enter a valid number (1-4)\n");
        }
    }
}
  
