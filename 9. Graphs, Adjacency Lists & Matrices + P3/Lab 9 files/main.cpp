// Collaborated with demo partner Peter Chu
#include <iostream>
#include <ctime>
#include <array>
#include <algorithm>
#include <vector>
// Compile with: g++ main.cpp -Wall -Werror -o ./a.exe

using namespace std;

// DECLARATIONS:
    void Quicksort_midpoint(int numbers[], int i, int k);
    void Quicksort_medianOfThree(int a[], int start, int end); 
    void InsertionSort(int numbers[], int numbersSize);
// Utility functions:
    int Partition_midpoint(int numbers[], int i, int k);
    int genRandInt(int low, int high);
    void fillArrays(int arr1[], int arr2[],int arr3[]);
// Global variable(s):
    const int NUMBERS_SIZE = 50000;

int main() {
    int arr1[NUMBERS_SIZE];
    int arr2[NUMBERS_SIZE];
    int arr3[NUMBERS_SIZE];
    const int CLOCKS_PER_MS = CLOCKS_PER_SEC / 1000; // clock per milliseconds...

    // Randomize the arrays
    fillArrays(arr1, arr2, arr3);
    
    cout << "Beginning tests...\n";
    {
        cout << "\nTesting quicksort midpoint on arr1" << endl;
        clock_t Start = clock();
        Quicksort_midpoint(arr1, 0, NUMBERS_SIZE - 1);
        clock_t End = clock();
        int elapsedTime = (End - Start) / CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
        cout << "Time elapsed: " << elapsedTime << " milliseconds" << endl;
    }

    {
        cout << "\nTesting quicksort median on arr2" << endl;
        clock_t Start = clock();
        Quicksort_medianOfThree(arr2, 0, NUMBERS_SIZE - 1);
        clock_t End = clock();
        int elapsedTime = (End - Start) / CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
        cout << "Time elapsed: " << elapsedTime << " milliseconds" << endl; 
    }

    {
        cout << "\nTesting insertion sort on arr3" << endl;
        clock_t Start = clock();
        InsertionSort(arr3, NUMBERS_SIZE - 1);
        clock_t End = clock();
        int elapsedTime = (End - Start) / CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
        cout << "Time elapsed: " << elapsedTime << " milliseconds" << endl; 
    }

    cout << endl;
    cout << "Testing completed...\n";

    return 0;
}

// DEFINITIONS:

    /*  this function sorts the given array in the range from i to k using quicksort method. In this function, 
        pivot is the midpoint element (numbers[(i+k)/2]). (implementation of this function is given in section 21.5) */
    void Quicksort_midpoint(int numbers[], int i, int k) {
        // Base case: If the partition size is 1 or zero 
        // elements, then the partition is already sorted
        if (i >= k) {
            return;
        }
        
        // Partition the data within the array. Value lowEndIndex 
        // returned from partitioning is the index of the low 
        // partition's last element.
        int lowEndIndex = Partition_midpoint(numbers, i, k);
        
        // Recursively sort low partition (lowIndex to lowEndIndex) 
        // and high partition (lowEndIndex + 1 to highIndex)
        Quicksort_midpoint(numbers, i, lowEndIndex);
        Quicksort_midpoint(numbers, lowEndIndex + 1, k);
    }

    /*  this function utilizes different pivot selection technique in quicksort algorithm. The pivot is the median 
        of the following three values: leftmost (numbers[i]), midpoint (numbers[(i+k)/2]) and rightmost (numbers[k]). 
        You should modify the partition function given in section 21.5 to select the pivot using median-of-three technique. */
    void Quicksort_medianOfThree(int numbers[], int i, int k) {

        // Base case: If the partition size is 1 or zero 
        // elements, then the partition is already sorted
        if (i >= k) {
            return;
        }

        int mid = numbers[i + (k - i) / 2];
        int pivot;

        if (numbers[i] < numbers[mid] && numbers[mid] < numbers[k]) {
            pivot = mid;
        }
        else if (numbers[i] < numbers[mid] && numbers[i] > numbers[k]) {
            pivot = i;
        }
        else {
            pivot = k;
        }

        int l = i - 1;
        int r = k + 1;

        while (l <= r) {
            do {
                l++;
            }
            while (numbers[l] < pivot && l <= r );

            do {
                r--;
            }
            while (numbers[r] > pivot && l <= r);

            if (l <= r) {
                int temp;
                temp = numbers[l];
                numbers[l] = numbers[r];
                numbers[r] = temp;
            }
        }
        Quicksort_midpoint(numbers, i, r);
        Quicksort_midpoint(numbers, r + 1, k);
    }

    /* Utility function for quicksort midpoint */
    int Partition_midpoint(int numbers[], int i, int k) {
        // Pick middle element as pivot
        int midpoint = i + (k - i) / 2;
        int pivot = numbers[midpoint];
        
        bool done = false;
        while (!done) {
            // Increment lowIndex while numbers[lowIndex] < pivot
            while (numbers[i] < pivot) {
                i += 1;
            }
            
            // Decrement highIndex while pivot < numbers[highIndex]
            while (pivot < numbers[k]) {
                k -= 1;
            }
            
            // If zero or one elements remain, then all numbers are 
            // partitioned. Return highIndex.
            if (i >= k) {
                done = true;
            }
            else {
                // Swap numbers[lowIndex] and numbers[highIndex]
                int temp = numbers[i];
                numbers[i] = numbers[k];
                numbers[k] = temp;
                
                // Update lowIndex and highIndex
                i += 1;
                k -= 1;
            }
        }
        
        return k;
    }

    /* this function sorts the given array using InsertionSort method. (implementation of this method is provided in section 21.3). */
    void InsertionSort(int numbers[], int numbersSize) {
        int i;
        int j;
        int temp;      // Temporary variable for swap
        
        for (i = 1; i < numbersSize; ++i) {
            j = i;
            // Insert numbers[i] into sorted part
            // stopping once numbers[i] in correct position
            while (j > 0 && numbers[j] < numbers[j - 1]) {
                
                // Swap numbers[j] and numbers[j - 1]
                temp = numbers[j];
                numbers[j] = numbers[j - 1];
                numbers[j - 1] = temp;
                --j;
            }
        }
    }

    /* You can use the following function to generate three similar array of random integers. */
    int genRandInt(int low, int high) {
        return low + rand() % (high - low + 1);
    }
    void fillArrays(int arr1[], int arr2[],int arr3[]){
        for(int i = 0; i < NUMBERS_SIZE; ++i){
            arr1[i] = genRandInt(0,NUMBERS_SIZE);
            arr2[i] = arr1[i];
            arr3[i] = arr1[i];
        }
    }