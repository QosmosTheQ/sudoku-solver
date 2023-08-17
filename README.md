# Sudoku Solver

This program contains a C++ application that solves a given Sudoku puzzle by taking input from the user. The Sudoku-solving algorithm uses the backtracking method.

## Features

- Solves a Sudoku-solving problem provided by the user.
- Provides a visual representation of the Sudoku board.
- Notifies the user if a solution doesn't exist.

## How to Use

1. **Requirements**

    - C++ compiler (e.g., g++)

2. **Downloading the Code**

    ```bash
    git clone https://github.com/QosmosTheQ/Sudoku-Solver.git
    cd Sudoku-Solver
    ```

3. **Compiling and Running the Code**

    ```bash
    g++ -o sudoku_solver main.cpp
    ./sudoku_solver
    ```

4. **Entering the Sudoku Board**

    - The program will prompt you to enter a 9x9 Sudoku board. Use 0 for empty cells.
    - Example input:
      ```
      5 3 0 0 7 0 0 0 0
      6 0 0 1 9 5 0 0 0
      0 9 8 0 0 0 0 6 0
      8 0 0 0 6 0 0 0 3
      4 0 0 8 0 3 0 0 1
      7 0 0 0 2 0 0 0 6
      0 6 0 0 0 0 2 8 0
      0 0 0 4 1 9 0 0 5
      0 0 0 0 8 0 0 7 9
      ```

5. **Viewing the Solution or Status**

    - If a solution exists, the program will display the solved Sudoku board.
    - If no solution exists, the program will show a "No solution exists." message.

## License

This project is open-source and licensed under the MIT license. For more information, please see the `LICENSE` file.
