# Word Ladder Solver

## Introduction

This program, developed in collaboration with Peter Chu, is a Word Ladder solver that finds the shortest sequence of words that transforms one word into another by changing one letter at a time while ensuring that each intermediate word is also a valid word. The program takes input for the dictionary file, input and output file names, and the start and end words of the ladder. This README provides an overview of the program's structure and its main functions.

## Program Structure

The program consists of multiple files, including the main source file (`main.cpp`) and a separate header and implementation file (`WordLadder.h` and `WordLadder.cpp`). The key components of the program include:

- **Main Function**: `main()`: The program's entry point, where user input is obtained for the dictionary file, input and output file names, and the start and end words of the Word Ladder. It initializes the `WordLadder` class and calls the `outputLadder()` function to find and display the ladder.

- **`WordLadder` Class**: Defined in the `WordLadder.h` and `WordLadder.cpp` files, this class is responsible for loading the dictionary, finding the ladder, and outputting the results.

## Program Execution

The program executes the following steps:

1. **User Input**: The program prompts the user to input the following information:
   - Dictionary file name
   - Output file name
   - Start word
   - End word

2. **Input Validation**: The program validates that both the start and end words have exactly 5 characters. If not, it prompts the user to reenter them.

3. **Word Ladder Solver**: The program creates an instance of the `WordLadder` class and uses it to find the shortest word ladder between the start and end words.

4. **Output**: The program outputs the Word Ladder to the specified output file, or it displays an error message if no ladder can be found.

## Usage

To use this program and find a Word Ladder between two words, follow these steps:

1. **Compile the program**: Use a C++ compiler to compile the program, including `WordLadder.cpp`, `main.cpp`, and any other necessary files. The provided compilation command can be used as a reference.

2. **Run the compiled program**: Execute the compiled program. It will prompt you to enter the dictionary file name, output file name, start word, and end word.

3. **Observe the results**: The program will attempt to find the shortest Word Ladder between the start and end words. If successful, it will output the ladder to the specified output file. If no ladder can be found, it will display an error message.

Compile with:

```bash
g++ main.cpp WordLadder.cpp -o a.exe
```

## Sample Output

**Terminal**:
```bash
$ ./a
Enter the name of the dictionary file: dictionary.txt

Enter the name of the output file: outputFile.txt

Enter the first word: abaca

Enter the last word: abate
```

**`outputFile.txt`**:
```
abaca aback alack black blank flank flask flash slash swash awash abash abase abate
```

## Comments and Notes

- The program includes commented-out code blocks that may be used for additional functionality or input validation. You can uncomment and extend these as needed.

- Collaborator information is provided at the beginning of the file to indicate collaboration on the project.

## Conclusion

This program serves as a Word Ladder solver, allowing you to find the shortest sequence of words that transforms one word into another while considering the validity of each intermediate word. You can use it to explore word ladders and study their structures. Additionally, you can modify the program to suit specific requirements or expand its functionality.
