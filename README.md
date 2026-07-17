Student Record Management System

A robust, modular command-line application built in C to manage student academic records, utilizing dynamic data structures to ensure memory efficiency and operational safety.



📋 Project OverviewThis system acts as an administrative portal designed to replace static, fixed-size data storage with dynamic memory allocation. By implementing custom data structures, the software ensures scalable performance, fair processing of admissions, and reliable data recovery.  



🚀 FeaturesAdmissions Queue: Implements a FIFO (First-In, First-Out) structure to process registration applications in the exact order they arrive.  Active Master Database: Utilizes a Singly Linked List to store active student records, allowing for dynamic growth without memory fragmentation.  Zero-Overhead Undo Engine: Features a LIFO (Last-In, First-Out) Stack to intercept deleted nodes, allowing for instant, non-destructive data restoration.  Data Persistence: Automatically serializes and deserializes records to a flat file (students.txt), ensuring data durability across program sessions. 

&#x20;

📁 Project StructureThe project follows a modular file architecture to decouple logic and improve maintainability:student.h: Defines the unified struct Student and function interfaces.  linked\_list.c: Manages active database traversal and record manipulation.  queue.c: Controls the FIFO incoming registration pipeline.  stack.c: Implements the LIFO history stack for the Undo function.  file\_handler.c: Handles disk serialization and data persistence.  main.c: Drives the interactive dashboard menu and user input validation.  



🛠️ Compilation \& Setup

Clone the repository

git clone https://github.com/YOUR\_USERNAME/YOUR\_REPOSITORY\_NAME.git



Compile using GCC:Ensure you have MinGW or a standard GCC compiler installed. Run the following command in your terminal

gcc main.c linked\_list.c queue.c stack.c stack.c file\_handler.c -o student\_system



Execute the program

./student\_system



📖 Usage GuideUpon launching the system, navigate the administrative dashboard using the following menu options:

Add Student: Enqueue a new applicant.

Process Registration: Move a student from the queue to the master database.

Search Records: Find student details via ID.

Display Active Students: View the current database.

Display Queue: View pending applications.

Delete Record: Remove a student and push them to the history stack.

Undo Last Deletion: Restore a deleted record instantly.

Save \& Exit: Terminate the session and save data to students.txt.



Developed as a practical assignment for the Department of ICT, Uva Wellassa University of Sri Lanka.  

