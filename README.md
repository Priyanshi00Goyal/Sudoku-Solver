# 🧩 Sudoku Solver Using C++

A console-based **Sudoku Solver Application** developed in C++ as part of my **CodeAlpha Internship Projects**.

This project uses the **Backtracking Algorithm** to automatically solve Sudoku puzzles while providing an interactive experience with difficulty levels, scoring, player statistics, and file handling.

---

## 📌 Project Overview

Sudoku is a logic-based number puzzle where the objective is to fill a 9×9 grid so that every row, column, and 3×3 sub-grid contains numbers from 1 to 9 without repetition.

This application solves Sudoku puzzles efficiently using recursion and backtracking while demonstrating important concepts of **Data Structures & Algorithms and Object-Oriented Programming**.

---

# ✨ Features

### 🧠 Sudoku Solver

* Solves puzzles automatically using the Backtracking algorithm
* Checks valid moves using:

  * Row validation
  * Column validation
  * 3×3 grid validation

### 🎮 Game Features

* Multiple difficulty levels:

  * Easy
  * Medium
  * Hard
* Random puzzle selection
* Interactive console-based menu

### 👤 Player System

* Player profile management
* Tracks:

  * Games played
  * Games solved
  * Best score

### ⏱ Performance System

* Tracks solving time
* Calculates score based on:

  * Difficulty level
  * Completion time

### 💾 File Handling

* Save current Sudoku game
* Load previous game
* Store player statistics permanently

### 🛡 Validation

* Handles invalid inputs
* Detects invalid Sudoku configurations

---

# 🛠️ Technologies Used

| Technology    | Purpose                   |
| ------------- | ------------------------- |
| C++           | Core programming language |
| OOP           | Modular project design    |
| Recursion     | Sudoku solving logic      |
| Backtracking  | Puzzle solving algorithm  |
| File Handling | Data persistence          |
| STL           | Utility functions         |

---

# 🧠 Algorithm Used

## Backtracking Algorithm

The solver follows these steps:

1. Find an empty cell in the Sudoku board
2. Try numbers from 1 to 9
3. Check whether the number is valid
4. Place the number if it is safe
5. Recursively solve the remaining puzzle
6. Backtrack if the solution is not possible

This approach explores possible solutions efficiently while eliminating invalid choices.

---

# 📂 Project Structure

```
Sudoku-Solver/
│
├── src/
│   ├── main.cpp
│   ├── Sudoku.cpp
│
├── include/
│   ├── Sudoku.h
│
├── data/
│   ├── sudoku.txt
│   └── player.txt
│
├── README.md
├── LICENSE
└── .gitignore
```

---

# ▶️ How to Run

### Clone Repository

```bash
git clone https://github.com/your-username/Sudoku-Solver.git
```

### Compile

```bash
g++ src/*.cpp -I include -o sudoku
```

### Run

Windows:

```bash
sudoku.exe
```

Linux/Mac:

```bash
./sudoku
```

---

# 🎮 Sample Gameplay

```
========================
      SUDOKU SOLVER
========================

1. New Game
2. Solve Sudoku
3. Display Board
4. Save Game
5. Load Game
6. Statistics
7. Exit

Enter choice:
```

---

# 📸 Screenshots

(Add screenshots of:)

* Main menu
* Sudoku puzzle
* Solved puzzle
* Player statistics

---

# 📚 Learning Outcomes

Through this project, I improved my understanding of:

* Recursive problem solving
* Backtracking algorithms
* Object-Oriented Programming
* File handling in C++
* Modular software design
* Building complete console applications

---

# 🚀 Future Improvements

Possible future upgrades:

* Graphical User Interface (GUI)
* Online multiplayer mode
* Sudoku puzzle generator
* Database integration
* Difficulty prediction using AI

---

# 👩‍💻 Author

**Priyanshi Goyal**

B.Tech Computer Science Engineering

---

# ⭐ Acknowledgement

Developed as part of the **CodeAlpha Internship Program** to strengthen programming skills, algorithmic thinking, and software development practices.
