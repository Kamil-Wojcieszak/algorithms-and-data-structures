# Sorting Algorithms

This repository contains implementations of various sorting algorithms in C++.

---

## Array

**Description**: The `Array` class provides definitions and implementations related to arrays, offering functionalities for array manipulation, such as creating arrays, accessing elements, and modifying array contents.

**Code**:
- Header file: [Array.h](src/Array/Array.h)
- Implementation file: [Array.cpp](src/Array/Array.cpp)

---

## Menu

**Description**: The `Menu` class facilitates user interaction by presenting an interactive menu that allows users to choose sorting algorithms and input data.

**Code**:
- Header file: [Menu.h](src/Menu/Menu.h)
- Implementation file: [Menu.cpp](src/Menu/Menu.cpp)

---

## Test

**Description**: The `Test` class contains functions for testing the sorting algorithms, verifying their correctness and efficiency under various scenarios.

**Code**:
- Header file: [Test.h](src/Test/Test.h)
- Implementation file: [Test.cpp](src/Test/Test.cpp)

---

## Time

**Description**: The `Time` class includes functions for measuring the execution time of sorting algorithms, providing insights into their efficiency and performance.

**Code**:
- Header file: [Time.h](src/Time/Time.h)
- Implementation file: [Time.cpp](src/Time/Time.cpp)

---

## Cheap Sort

**Code**:
- Header file: [HeapSort.h](src/Sorts/HeapSort/HeapSort.h)
- Implementation file: [HeapSort.cpp](src/Sorts/HeapSort/HeapSort.cpp)

**Description**: Cheap Sort is a simple sorting algorithm that repeatedly iterates through the list, compares adjacent elements, and swaps them if they are in the wrong order.

**Conclusion**: While Cheap Sort is straightforward to implement, it is not efficient for large datasets due to its O(n^2) time complexity.

---

## Insert Sort

**Code**:
- Header file: [InsertionSort.h](src/Sorts/InsertionSort/InsertionSort.h)
- Implementation file: [InsertionSort.cpp](src/Sorts/InsertionSort/InsertionSort.cpp)

**Description**: Insertion Sort works by building a sorted array one element at a time, iterating through the list and shifting elements as necessary to find the correct position for each element.

**Conclusion**: Insertion Sort performs well for small datasets or nearly sorted arrays but becomes inefficient for larger datasets due to its O(n^2) time complexity.

---

## Quick Sort

**Code**:
- Header file: [QuickSort.h](src/Sorts/QuickSort/QuickSort.h)
- Implementation file: [QuickSort.cpp](src/Sorts/QuickSort/QuickSort.cpp)

**Description**: Quick Sort is a divide-and-conquer algorithm that partitions the array into smaller subarrays, then recursively sorts each subarray.

**Conclusion**: Quick Sort offers excellent performance with an average time complexity of O(n log n), making it suitable for most practical sorting tasks.

---

## Shell Sort

**Code**:
- Header file: [shell_sort.h](src/Sorts/ShellSort/ShellSort.h)
- Implementation file: [shell_sort.cpp](src/Sorts/ShellSort/ShellSort.cpp)

**Description**: Shell Sort is an extension of Insert Sort that compares elements that are distant from each other and gradually reduces the gap between elements to be compared.

**Conclusion**: Shell Sort improves upon Insert Sort by reducing the number of comparisons, providing better performance for medium-sized datasets.

---

## Results

### Performance Comparison

- **Cheap Sort**: While easy to implement, it performs poorly on large datasets due to its quadratic time complexity.
- **Insert Sort**: Efficient for small datasets or nearly sorted arrays but becomes slow for larger datasets.
- **Quick Sort**: Offers excellent average-case performance and is suitable for most practical sorting tasks.
- **Shell Sort**: Improves upon Insert Sort by reducing the number of comparisons, providing better performance for medium-sized datasets.

Overall, the choice of sorting algorithm depends on the size and nature of the dataset. Quick Sort is often a good default choice due to its balanced performance. However, for specific use cases, other algorithms might be more appropriate.

---
