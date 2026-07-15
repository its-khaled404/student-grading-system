# 🎓 Student Grade Management System in C

A console-based **Student Grade Management System** developed in **C**. This project reads student records from a text file, calculates grades and academic performance, and displays detailed individual and overall statistics through an interactive menu-driven interface.

The project demonstrates fundamental C programming concepts, including **file handling, arrays, functions, loops, conditional statements, formatted output, and basic data analysis**.

---

## ✨ Features

- 📂 Reads student information and marks from an external file
- 👨‍🎓 Displays an interactive list of students
- 📊 Shows subject-wise marks and letter grades
- ✅ Determines pass and fail status for each subject
- 🧮 Calculates total and average marks for each student
- 📈 Displays the overall average across all students
- 🏆 Identifies the highest mark and corresponding student and subject
- 📉 Identifies the lowest mark and corresponding student and subject
- 🔁 Supports multiple students sharing the same highest or lowest mark
- 🎯 Displays a complete grading scale
- ⏳ Includes animated text and a loading effect
- 🖥️ Supports screen clearing on Windows and Unix-based systems

---

## 🛠️ Technologies Used

- **Language:** C
- **Compiler:** GCC
- **Data Storage:** Text file (`students.txt`)
- **Interface:** Command-line interface (CLI)

---

## 📚 Concepts Demonstrated

This project applies several core C programming concepts:

- File handling with `FILE`, `fopen()`, `fscanf()`, and `fclose()`
- One-dimensional and two-dimensional arrays
- Functions and modular programming
- Loops and conditional statements
- String handling
- Pointers and string return values
- Preprocessor directives and constants
- Formatted console output
- Basic statistical calculations
- Cross-platform conditional compilation

---

## 📁 Project Structure

```text
student-grading-system/
├── main.c
├── students.txt
├── LICENSE
└── README.md
```

---

## 📝 Input File Format

The program reads student information from a file named `students.txt`.

Each line should contain:

```text
StudentID StudentName Math Physics English CSE
```

Example:

```text
101 Alice 85 78 92 88
102 Bob 65 72 58 80
103 Charlie 45 38 67 55
104 David 30 42 28 35
105 Emma 90 95 89 93
```

> **Note:** The current implementation uses `%s` to read student names, so names should contain only one word.

---

## 🎯 Grading Scale

| Grade | Marks |
|-------|-------|
| A+ | 80–100 |
| A | 70–79 |
| A- | 60–69 |
| B | 50–59 |
| C | 40–49 |
| D | 33–39 |
| F | 0–32 |

The minimum passing mark for each subject is **33**.

---

## 🚀 How to Compile and Run

### Compile the program:

```bash
gcc main.c -o main
```

### Run it:

```bash
./main
```

> Make sure `students.txt` is located in the same directory as the executable.

---

## 💻 How It Works

When the program starts, it:

1. Opens and reads student data from `students.txt`.
2. Displays a loading animation.
3. Calculates overall statistics for all students.
4. Shows an interactive student selection menu.
5. Allows the user to select a student by serial number.
6. Displays the selected student's:
   - Subject-wise marks
   - Letter grades
   - Pass/fail status
   - Total marks
   - Average marks
   - Number of subjects passed and failed
7. Displays overall statistics for all students.
8. Returns to the main menu until the user chooses to exit.

---

## 📊 Example Output

```text
=====================================
   STUDENT GRADE MANAGEMENT SYSTEM
=====================================

====================================
          STUDENT MENU
====================================
+-----+--------+----------------+
| No. | ID     | Name           |
+-----+--------+----------------+
| 1   | 101    | Alice          |
| 2   | 102    | Bob            |
| 3   | 103    | Charlie        |
| 4   | 104    | David          |
| 5   | 105    | Emma           |
+-----+--------+----------------+
|  0  | Exit                     |
+--------------------------------+

Enter the serial number to view grades.
To exit, enter 0:
```

---

## 📈 Statistics

The program calculates:

- Total and average marks
- Pass/fail count
- Subject grades and status
- Highest and lowest marks with student/subject details
- Overall average mark

---

## 🔮 Future Improvements
- Add, edit, and delete records
- Support names with spaces
- Input validation
- Dynamic student count
- Search and sorting
- Class ranking
- Save results to a file
- Subject-wise statistics
- GUI support

---

## 🎯 Purpose

A console-based C programming project designed to practice core programming concepts through a student record and grade management system.

---

## 🤝 Contributions

Contributions, suggestions, and improvements are welcome. Feel free to fork the repository and submit a pull request.

---

## 📄 License

This project is intended for educational and learning purposes.

---

⭐ If you find this project useful, consider giving the repository a star!
