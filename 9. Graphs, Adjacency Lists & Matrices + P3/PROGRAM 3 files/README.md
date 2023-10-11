# Word Frequency and Hash Code Generation

## Introduction

This program reads words from a text file, calculates word frequency, and generates hash codes for the words based on a custom hash function. It also assigns a unique code to each word based on its frequency and hash value.

## Program Structure

The program consists of a C++ source file named `main.cpp` and includes several standard libraries. The key components of the program include:

- **Main Function**: `main()`: The program's entry point, where word frequency, hash codes, and unique codes are calculated.

- **Struct Definition**: `Node`: Defines a custom struct to store word-related information, including word data, frequency, hash number, and code.

- **Hash Function**: `sHash(const string& word)`: Implements a custom hash function to calculate hash numbers for words.

- **Code Generation**: `code(vector<Node> &name)`: Generates unique codes for words based on their frequency and hash number.

- **Input/Output**: The program reads words from an input text file and writes the generated codes and word data to an output text file.

## Program Execution

The program executes the following steps:

1. **Read Input File**: It reads words from an input text file specified by `fileName`. The program handles words with single characters and accounts for capitalization (e.g., "WORD" and "word" are treated as separate words).

2. **Word Frequency Calculation**: The program calculates the frequency of each word and stores it in the `freq` field of the corresponding `Node` structure.

3. **Word Preprocessing**: For words containing special characters like "-", "&", "*", etc., the program splits them into separate words and increments their frequencies accordingly. For example, "apple-pie" becomes "apple" and "pie."

4. **Hash Code Generation**: The program calculates hash numbers for each word using the custom `sHash` function.

5. **Code Generation**: The program generates unique codes for each word based on its frequency and hash number. The codes are stored in the `code` field of the corresponding `Node` structure.

6. **Output**: The program writes the generated codes and word data to an output text file named "test2.txt."

## Usage

To use this program for word frequency analysis and code generation, follow these steps:

1. **Compile the Program**: Use a C++ compiler to compile the source file `main.cpp`. For example:

```bash
g++ main.cpp -Wall -o ./a.exe
```

2. **Run the Compiled Program**: Execute the compiled program (`./a.exe` on Windows).

3. **Word Analysis**: The program will read the input text file specified by `fileName`, analyze word frequencies, and generate hash codes and unique codes for each word.

4. **Output**: The program will create an output text file named "test2.txt," containing the generated codes and word data.

5. **Analysis**: You can analyze the generated codes and word frequencies for further processing or understanding of the input text.

6. **Note**: Make sure to adjust the `fileName` variable in the code to specify the input text file you want to analyze.

## Sample Output

**`inputFile.txt`**:
```bash
...
..apple  
app--le   
apple--  
app-l-e   
,
,
,
,apple
apple,
```

**`outputFile.txt`**:
```bash
1 2 3 4 5 6 7 8 
- . , apple app le l e 
```

## Comments and Notes

- The program accounts for word frequencies and special characters within words.

- Collaborator information is provided at the beginning of the file to indicate collaboration on the project.

## Conclusion

This program serves as a tool for analyzing word frequencies, calculating hash codes, and generating unique codes for words found in a text file. It can be used for various applications, including text analysis and data processing.
