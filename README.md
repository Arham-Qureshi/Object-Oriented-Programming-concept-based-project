# 🎓 Student Report Management System (C++)

![Language](https://img.shields.io/badge/language-C%2B%2B-blue.svg)
![Status](https://img.shields.io/badge/project-OOP%20PBL%20Assignment-green)

This is a **C++ Object-Oriented Programming (OOP)** based project designed for college-level PBL (Project-Based Learning). It manages and maintains student academic records using core C++ features and standard file handling.

---

## 🚀 Features

- 📌 Add, update, delete student records  
- 📊 Calculate average marks and assign grades  
- 📁 Save student data to a CSV file  
- 🔄 Load student data automatically on startup  
- 🔍 Search students by roll number or name  
- 🧾 View full student reports  
- 📊 Count total number of students  
- 🔢 Sort students by roll number  

---

## 🧠 Concepts Used

- ✅ Object-Oriented Programming  
- ✅ Classes and Objects  
- ✅ Encapsulation  
- ✅ File Handling (CSV format)  
- ✅ Vectors and STL  
- ✅ Lambda Functions  
- ✅ Basic Data Validation  

---

## 💾 How It Works

1. On starting the program, student records are **automatically loaded** from `students.csv`.
2. You can perform operations like add, update, delete, and search using a **menu-driven interface**.
3. After making changes, you can choose to **save** the data, which will export it to the same `students.csv` file.

---

## 📁 Project Structure

```bash
📂 Student-Report-System/
│
├── 📄 main.cpp         # Complete source code
├── 📄 students.csv     # Auto-generated student data file (after save)
└── 📄 README.md        # This project documentation
```

---

## 🛠️ Requirements

- C++11 or later
- g++ compiler or any C++ IDE (e.g., Code::Blocks, Dev C++, VS Code)

---

## 🧪 Sample CSV Output

```
RollNo,Name,Math,Science,English,Average,Grade
101,Arjun,88,76,92,85.33,B
102,Kriti,94,89,96,93.00,A
```

---

## 📌 How to Run

```bash
g++ main.cpp -o student_report
./student_report
```

---

## 📄 License
Feel free to use or modify it for academic or educational purposes.

---

## 🙋‍♀️ Contribution

This project was developed as part of a college **OOP PBL assignment**. Contributions for additional features (e.g., GUI, PDF export, marks graph) are welcome!
