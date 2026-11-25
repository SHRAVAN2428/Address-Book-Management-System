📌 Project Overview

The Address Book Management System is a menu-driven application developed using C programming. It helps users efficiently manage contact information by allowing them to add, search, edit, delete, and display contacts.

The project uses structures, pointers, file handling, and modular programming concepts. Contact information is stored in a CSV file to maintain data even after the application is closed.

🚀 Features

Add Contact: Add new contact details to the address book.

Search Contact: Search for contacts using their name, phone number, or email.

Edit Contact: Modify existing contact information.

Delete Contact: Remove unwanted contacts.

List Contacts: Display all saved contacts.

Data Persistence: Store and retrieve contact details using CSV file handling.

Input Validation: Validate names, phone numbers, and email addresses.

🛠️ Technologies Used

C Programming

Structures and Pointers

File Handling

String Manipulation

Modular Programming

GCC Compiler

📂 Project Structure

Address-Book/
│
├── main.c
├── contact.c
├── contact.h
├── file.c
├── file.h
├── populate.c
├── contacts.csv
└── README.md

Note: The file structure shown above is an example. Actual filenames may vary.

⚙️ Validation Rules

Name: Minimum 4 characters.

Phone Number: Must start with 6 or 9.

Email: Must contain a valid email format and .com domain.

💻 Compilation and Execution

Compile

gcc *.c -o addressbook

Run

On Linux:

./addressbook

On Windows:

addressbook.exe

If your project uses multiple source files or special compilation requirements, adjust the compilation command accordingly.

🧠 Concepts Implemented

Structures

Pointers

Functions

Arrays and Strings

File Operations

Input Validation

Modular Programming

🎯 Learning Outcomes

Improved understanding of C programming fundamentals.

Practical implementation of file handling.

Experience with structures and pointers.

Understanding modular programming.

Development of a real-time contact management application.