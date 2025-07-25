# 3rd Semester Practical Programs

This repository contains all the practical programs from the **3rd semester of Computer Engineering**, covering three core subjects:

- **Computer Graphics (CG)**
- **Fundamentals of Data Structures (FDS)**
- **Object-Oriented Programming (OOP)**

Each folder is organized by subject and experiment number, with both original and DEV versions (if applicable).

---

## 📁 Project Structure

3rd sem practical final/
│
├── CG/
│ ├── Exp-01/ → DDA Line Drawing
│ ├── Exp-02/ → Circle Drawing
│ ├── Exp-03/ → Patterns
│ ├── Exp-04/ → Chess Board Drawing
│ ├── Exp-05/ → Seed Fill Algorithm
│ ├── Exp-07/ → OpenGL Program
│ ├── Exp-08/ → Bezier Curves
│ └── Extra/ → Hilbert Curve, etc.
│
├── FDS/
│ └── Exp-07/ to Exp-13/ → Various Data Structures in C++
│
├── OOP/
│ └── 01_OOP.cpp to 07_OOP.cpp → C++ Object-Oriented Programs
│
├── README.md
├── NOTICE
├── LICENSE
└── .vscode/ → Configuration for VS Code


---

## 🛠 Requirements

- C++ Compiler (e.g., g++, clang++)
- (For CG programs) OpenGL + GLUT Libraries
- Visual Studio Code (Recommended)

---

## 🚀 How to Run

### Compile a Program (Linux/macOS/WSL):

```bash
g++ filename.cpp -o output
./output
```
Compile a Computer Graphics Program (with OpenGL):
g++ filename.cpp -lGL -lGLU -lglut -o output
./output

📌 Notes
*_DEV.cpp files are alternative or developer versions.

Code is written with academic structure in mind (clearly segmented experiments).

Some programs may require graphical libraries to be installed.

🙌 Contributing
Feel free to fork and contribute by:

Fixing bugs

Adding comments

Including output screenshots or sample input

📚 License
This project is intended for educational use. If you use this for submissions, please understand the code and give proper credit.
