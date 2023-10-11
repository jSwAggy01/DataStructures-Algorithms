# Movie Review Sentiment Analyzer

## Introduction

This program is a movie review sentiment analyzer that reads movie reviews from a file, computes the average sentiment score for user-provided reviews, and categorizes them as positive, somewhat positive, somewhat negative, or negative.

## Program Structure

The program consists of multiple C++ source files, including `main.cpp`, `HashTable.cpp`, and `WordEntry.cpp`, along with other necessary source files. The key components of the program include:

- **Main Function**: `main()`: The program's entry point, where users can provide movie reviews for sentiment analysis.

- **HashTable Class**: The `HashTable.cpp` file contains the implementation of the `HashTable` class, which represents a hash table data structure. It includes functions for inserting words with sentiment scores, computing the average score for words, and retrieving scores.

- **WordEntry Class**: The `WordEntry.cpp` file contains the implementation of the `WordEntry` class, which represents individual word entries with associated sentiment scores.

## Program Execution

The program executes the following steps:

1. **Data Input**: The program reads movie reviews and their associated sentiment scores from the "movieReviews.txt" file.

2. **Hash Table**: It constructs a hash table to store individual words from the reviews along with their sentiment scores.

3. **User Input**: Users can input their own movie reviews for sentiment analysis. The program calculates the average sentiment score for each review.

4. **Sentiment Analysis**: Based on the average sentiment score, the program categorizes the review as "Positive Sentiment," "Somewhat Positive Sentiment," "Somewhat Negative Sentiment," or "Negative Sentiment."

5. **Output**: The program displays the average sentiment score and sentiment category for each review.

6. **Repeat or Exit**: Users can provide multiple reviews or exit the program.

## Usage

To use this program for movie review sentiment analysis, follow these steps:

1. **Compile the Program**: Use a C++ compiler to compile the source files, including `main.cpp`, `HashTable.cpp`, and `WordEntry.cpp`, along with any other necessary source files. For example:

```bash
g++ WordEntry.cpp HashTable.cpp main.cpp -Wall -Wuninitialized -o a.exe
```

2. **Run the Compiled Program**: Execute the compiled program (`./a.exe` on Windows).

3. **Data Input**: The program will read movie reviews and their associated sentiment scores from the "movieReviews.txt" file. Ensure that this file exists in the same directory as the program executable.

4. **User Input**: The program will prompt you to enter a movie review. Press "Return" to exit the program. You can provide multiple reviews.

5. **Sentiment Analysis**: For each review you provide, the program will calculate the average sentiment score and categorize it as positive, somewhat positive, somewhat negative, or negative.

6. **Output**: The program will display the average sentiment score and sentiment category for each review.

7. **Exit the Program**: To exit the program, press "Return" when prompted to enter a review.

## Sample Output

```bash
$ ./a
enter a review -- Press return to exit: 
Blue Crush
The review has an average value of 2.125
Somewhat Positive Sentiment

enter a review -- Press return to exit: 
Men in Black II
The review has an average value of 1.95881
Somewhat Negative Sentiment

enter a review -- Press return to exit:   
Mr. Deeds
The review has an average value of 2.77
Somewhat Positive Sentiment

enter a review -- Press return to exit:
Spy Kids 2 : The Island of Lost Dreams
The review has an average value of 2.64501
Somewhat Positive Sentiment

enter a review -- Press return to exit:

```

## Comments and Notes

- The program uses a hash table to efficiently store and retrieve sentiment scores for individual words.

- It calculates the average sentiment score for user-provided reviews by analyzing the scores of individual words in the reviews.

- Collaborator information is provided at the beginning of the file to indicate collaboration on the project.

## Conclusion

This program serves as a tool for analyzing the sentiment of movie reviews. It demonstrates the use of hash tables and sentiment analysis techniques to categorize reviews based on their content and sentiment scores.
