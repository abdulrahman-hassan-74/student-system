# Student Management System (C with Linked List)

## 📌 Overview
This project is a **console-based student management system** implemented in **C** using a **singly linked list**.  
It allows adding, searching, updating, deleting, and displaying student information dynamically.  

Each student record contains:
- Name  
- ID (unique identifier)  
- GPA  
- Age  

---

## ⚙️ Features
1. **Add Student**  
   - Insert a new student into the system.  
   - Prevents duplicate IDs.  

2. **Display All Students**  
   - Prints all stored student information.  

3. **Search by ID**  
   - Finds and displays student information by ID.  

4. **Update Student by ID**  
   - Edits an existing student's information.  

5. **Delete Student by ID**  
   - Removes a student record from the system.  

6. **Calculate Average GPA**  
   - Computes and displays the average GPA of all students.  

7. **Find Student with Highest GPA**  
   - Finds and displays the student who has the maximum GPA.  

---

## 📜 Menu Options
When you run the program, the following menu appears:

```
enter 1 to add student
enter 2 to display all
enter 3 to search by id
enter 4 to edit student info by id
enter 5 to delete student by id
enter 6 to calculate the average GPA
enter 7 to get the highest GPA
enter 0 to terminate
```

---

## 🛠️ Implementation Details
- **Data Structures:**  
  - `struct student` → stores individual student info.  
  - `struct node` → linked list node that wraps a student.  

- **Linked List:**  
  - Dynamic allocation with `malloc`.  
  - Insertion at the end of the list.  
  - Traversal for display, search, update, and delete operations.  

- **Error Handling:**  
  - Prevents duplicate student IDs.  
  - Handles empty list cases gracefully.  

---

## 👨‍💻 Author
- **Name:** Abdelrahman Hassan  
- **Language:** C  
- **Style:** ANSI C (console-based, linked list implementation)  
