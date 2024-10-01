

# Lexicraft

**Lexicraft** is a C++ console-based text editor that allows users to write, edit, and navigate text in real-time. The application is built with a custom doubly linked list for efficient text manipulation and supports advanced editing and file management features.

## Features

- **Cursor**: The cursor is represented by the " | " character, showing the current position in the text.
- **Text Input**: Type any character, which is added to the left of the cursor.
- **Deletion**: 
  - **Backspace**: Deletes the character immediately to the left of the cursor.
  - **Delete Key**: Deletes the character immediately to the right of the cursor.
  - **Ctrl + Backspace**: Deletes the entire word to the left of the cursor.
  - **Ctrl + Delete**: Deletes the entire word to the right of the cursor.
- **Cursor Movement**: 
  - Use the **left** and **right arrow keys** to move the cursor horizontally across the text.
  - **Up** and **down arrow keys** allow vertical movement between lines.
- **Footer Display**: Shows the current cursor index in the text.
- **File Operations**:
  - **Ctrl + S**: Save your notes to a `.txt` file.
  - **Ctrl + Load**: Load a saved file and continue editing from where you left off.

## Requirements

- Implemented in **C++** using a **doubly linked list** for efficient insertion and deletion.
- Works entirely in the console.
- Uses `getch()` (or equivalent) for capturing arrow key inputs and special key combinations.

## Installation and Usage

1. Clone the repository:
    ```bash
    git clone https://github.com/Rebelhere/lexicraft.git
    ```
2. Compile and run the program:
    ```bash
    g++ -o lexicraft lexicraft.cpp
    ./lexicraft
    ```

## Keybindings

- **Left Arrow**: Move cursor left.
- **Right Arrow**: Move cursor right.
- **Up Arrow**: Move cursor up.
- **Down Arrow**: Move cursor down.
- **Backspace**: Delete the character to the left of the cursor.
- **Delete**: Delete the character to the right of the cursor.
- **Ctrl + Backspace**: Delete the entire word to the left.
- **Ctrl + Delete**: Delete the entire word to the right.
- **Ctrl + S**: Save the current file.
- **Ctrl + Load**: Load a saved file.

## Future Improvements

- Add support for more text formatting options.
- Implement undo/redo functionality.

## Contributing

Feel free to open issues or submit pull requests for improvements or bug fixes.

## Collaboration Guidelines

We welcome contributions from the open-source community. If you'd like to collaborate on this project, please adhere to the following guidelines:
1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Implement your changes and commit them with descriptive messages.
4. Push your branch to your fork and submit a pull request.

### Feel free to reach out if you have any questions or suggestions !
