# Library-Management-System
A simple yet efficient C++ console-based Library Management System designed for students and librarians. It allows book inventory management, issuing and returning of books, and fine calculation for overdue returns — all with a clean menu-driven interface.

## 📝 Table of Contents

1. [Overview](#overview)
2. [Features](#features)
3. [Tech Stack](#tech-stack)
4. [Data Structures Used](#data-structures-used)
5. [Login Credentials](#login-credentials)
6. [How to Run](#how-to-run)
7. [Program Flow](#program-flow)
8. [Sample Output](#sample-output)
9. [Future Improvements](#future-improvements)
10. [Contributing](#contributing)
11. [Author](#author)

---

## 📖 Overview

This Library Management System offers two modes:

1. **Librarian Mode** — Manage the library's book collection.
2. **Student Mode** — Borrow and return books, view fines, and check issued books.

The system is **menu-driven** and relies entirely on the **console** for interaction.  
It uses a **Binary Search Tree (BST)** to store books in alphabetical order, a **map** to track quantities, and **vectors** to store student records.

---

## ✨ Features

### 👩‍🏫 Librarian Functions
- Add new books to the library's inventory.
- Update quantities of existing books.
- View available books with stock count.
- Display book list in alphabetical order using **inorder traversal** of BST.

### 👨‍🎓 Student Functions
- Borrow up to **2 books** at a time.
- Return books and check for late return **fines**.
- View currently borrowed books with issue dates.
- Check total fines accumulated over time.

### ⚙️ Additional Features
- **Fine Calculation**: ₹2 per day after 15 days of issue.
- **Date Tracking**: Automatically records the issue date for each book.
- **Multiple Students**: Preloaded student database with individual records.

---

## 🛠 Tech Stack

- **Language**: C++17
- **Compiler**: GCC / G++
- **Libraries**:
  - `<iostream>` — input/output handling
  - `<map>` — book quantity management
  - `<vector>` — student database
  - `<ctime>` — date handling
  - `<iomanip>` — formatted output
  - `<string>` — text handling

---

## 🗂 Data Structures Used

| Data Structure  | Purpose |
|-----------------|---------|
| **Binary Search Tree (BST)** | Store books in sorted alphabetical order. |
| **Map**         | Store book quantities with book title as the key. |
| **Vector**      | Store list of student records. |
| **Struct**      | Represent student details and book issue records. |

---

## 🔐 Login Credentials

### Librarian
- **User ID**: `19876`
- **Password**: `abc123`

### Students (Preloaded)
| Name  | ID        | Stream       |
|-------|----------|--------------|
| Aby   | 12318757 | B.Tech-CSE   |
| Lia   | 12325062 | B.Tech-CSE   |
| Noor  | 12322598 | B.Tech-CSE   |

---

## 🖥 How to Run

1. **Clone the repository**
   ```bash
   git clone https://github.com/your-username/LibraryManagementSystem.git
   cd LibraryManagementSystem
   ```

2. **Compile the program**
   ```bash
   g++ main.cpp -o library
   ```

3. **Run the executable**
   ```bash
   ./library
   ```

---

## 📊 Program Flow

```plaintext
Main Menu
│
├── Librarian Login
│     ├── Add Book
│     ├── Show Books
│     ├── Display in Alphabetical Order
│     └── Exit to Main Menu
│
└── User Login
      ├── Issue Book
      ├── Return Book
      ├── View Issued Books
      ├── View Total Fine
      └── Exit to Main Menu
```

---

## 🖼 Sample Output

```plaintext
1. Librarian Login
2. User Login
3. Exit
Enter choice: 1
Enter UserId: 19876
Enter Password: abc123
Login Successful!

1. Add Book
2. Show Books
3. Display Book in Alphabetical Order
4. Exit
Enter choice: 1
Enter book name: C++ Primer
Enter quantity: 5
Book added successfully!
```

---

## 🚀 Future Improvements

- Add **persistent storage** using file handling or databases.
- Implement **search by author or genre**.
- Add **book return reminders**.
- Support **multiple copies** of the same book with unique IDs.
- Create a **graphical user interface (GUI)** version.

---

## 🤝 Contributing

1. Fork this repository.
2. Create your feature branch:
   ```bash
   git checkout -b feature/YourFeature
   ```
3. Commit your changes:
   ```bash
   git commit -m "Add new feature"
   ```
4. Push to the branch:
   ```bash
   git push origin feature/YourFeature
   ```
5. Open a pull request.

---

## 👤 Author

**Nadeem Saba**  
📧 Email: nadeemsaba.work@gmail.com <br>
🔗 GitHub: [Nadeemsaba](https://github.com/Nadeemsaba)

---
