# OcuKnow

### *OcuKnow* is an interactive educational application built with Qt and C++. It allows medical students to explore a virtual model of the human eye, including a study guide and interactive quiz mode. Designed for clarity and accessibility, OcuKnow is ideal for students studying anatomy or preparing for exams.

---

## Table of Contents

- [Environment](#environment)
- [Installation](#installation)
- [File Descriptions](#file-descriptions)
- [Usage](#usage)
- [Study Guide](#study-guide)
- [Quiz Mode](#quiz-mode)
- [Key Features](#key-features)
- [Known Issues](#known-issues)
- [Authors](#authors)
- [License](#license)

---

## Environment

This project was developed and tested in:

- **Operating System**: Ubuntu 22.04 (also tested in Dockerized environments)
- **Qt Version**: Qt 6.4+
- **C++ Version**: C++17+
- **CMake**: 3.26+
- **IDE**: Visual Studio Code and Qt Creator

---

## Installation

Clone the repository and install dependencies:

```bash
git clone https://github.com/NecroKnightMare/OcuKnow.git
cd OcuKnow/src
mkdir build && cd build
cmake ..
cmake --build .
```

You will also need Qt 6 installed. You can download it via:

[Qt Installer](https://www.qt.io/download-qt-installer)

Optional: Use **Qt Creator** or **VS Code with Qt extensions** for better GUI support.

---

## File Descriptions

- `main.cpp`: Entry point of the application. Handles navigation between splash screen, quiz, and study guide.
- `UI/intro/introwidget.cpp/.h`: Main splash screen with animated background and navigation buttons.
- `UI/quiz/quiz.cpp/.h`: Logic and UI for the quiz feature.
- `UI/credits/creditswidget.cpp/.h`: Displays credits with a return option.
- `UI/eyemodel.ui`: Qt Designer file for the anatomical eye interface.
- `graphics/ocuknow_intro.gif`: Splash animation GIF.
- `graphics/half_image_eye.jpg`: Background image for the study guide.
- `resources.qrc`: Qt resource file linking embedded assets.
- `questions.txt`: Source file for quiz content.

---

## Usage

From the `build` folder, launch the program:

```bash
./OcuKnow
```

Upon launch, you'll see the animated splash screen with three options:

- **Enter Study Guide**
- **Take Quiz**
- **Credits**

---

## Study Guide

The Study Guide is a visual UI created using Qt Designer and provides an interactive model of the eye. Users can explore different anatomical parts of the eye using mouse-over or buttons. A labeled diagram helps users visualize the information.

---

## Quiz Mode

Clicking "Take Quiz" starts a multiple-choice quiz based on `questions.txt`. It includes:

- A splash screen with a Start button
- Multiple-choice questions with navigation
- A score screen and retry option

---

## Key Features

- Animated splash screen using GIF
- Translucent and styled UI buttons
- Responsive layouts and custom fonts
- Study Guide with anatomical eye model
- Quiz feature with question parsing and scoring
- Themed styling consistent across views

---

## Authors

- **Ariel Lopez**  
  [GitHub](https://github.com/NKN_Neko)  
  [LinkedIn](https://www.linkedin.com/in/arielnkm369)  
  [Email](alexandrea.ariel@gmail.com)

- **Stephen Newby**  
  [GitHub](https://github.com/TheSnewby/)  
  [LinkedIn](https://www.linkedin.com/in/stephenjnewby/)  
  [Email](stephen.j.newby@gmail.com)

- **Nash Thames**  
  [GitHub](https://github.com/internashionalist)  
  [LinkedIn](https://www.linkedin.com/in/nashthames/)  
  [Email](taylor.thames@atlasschool.com)

---

## License

This project is released under the Public Domain. Free to use, modify, and distribute.
