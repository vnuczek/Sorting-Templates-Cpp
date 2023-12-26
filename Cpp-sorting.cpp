#include <iostream>
#include <vector>

#include "utility.h"
#include "sortingTemplates.h"

int main() {
    // Bubble Sort
    std::cout << "Sorting by ascending order using Bubble Sort..." << std::endl;
    //std::cout << "Sorting by descending order using Bubble Sort..." << std::endl;

    std::vector<int> numbersBubbleSort = generateRandomVector(10, 0, 100);
    std::cout << "Original Vector: " << std::endl << numbersBubbleSort << std::endl << std::endl;

    bubbleSort(numbersBubbleSort.begin(), numbersBubbleSort.end(), [](const int& a, const int& b) {
        return a < b;
        }
    );
    std::cout << "Bubble Sort: " << std::endl << numbersBubbleSort << std::endl << std::endl;
    printSeparator(std::cout);

    // Selection Sort
    std::cout << "Sorting by remainder modulo 7 using Selection Sort..." << std::endl;

    std::vector<int> numbersSelectionSort = generateRandomVector(10, 0, 70);
    std::cout << "Original Vector: " << std::endl << numbersSelectionSort << std::endl << std::endl;

    selectionSort(numbersSelectionSort.begin(), numbersSelectionSort.end(), [](const int& a, const int& b) {
        return (a % 7) < (b % 7);
        }
    );
    std::cout << "Selection Sort: " << std::endl << numbersSelectionSort << std::endl << std::endl;
    printSeparator(std::cout);

    // Insertion Sort
    std::cout << "Sorting by count of digits using Insertion Sort..." << std::endl;

    std::vector<int> numbersInsertionSort = generateRandomVector(10, 0, 10000);
    std::cout << "Original Vector: " << std::endl << numbersInsertionSort << std::endl << std::endl;

    insertionSort(numbersInsertionSort.begin(), numbersInsertionSort.end(), [](const int& a, const int& b) {
        auto countDigits = [](int n) {
            n = std::abs(n);
            int count = (n == 0) ? 1 : 0;
            while (n != 0) {
                count++;
                n /= 10;
            }
            return count;
        };

        return countDigits(a) < countDigits(b);
        }
    );
    std::cout << "Insertion Sort: " << std::endl << numbersInsertionSort << std::endl << std::endl;
    printSeparator(std::cout);

    // Quick Sort
    std::cout << "Sorting by remainder modulo 10 using Quick Sort..." << std::endl;

    std::vector<int> numbersQuickSort = generateRandomVector(10, 0, 100);
    std::cout << "Original Vector: " << std::endl << numbersQuickSort << std::endl << std::endl;

    quickSort(numbersQuickSort.begin(), numbersQuickSort.end(), [](const int& a, const int& b) {
        return (a % 10) < (b % 10);
        }
    );
    std::cout << "Quick Sort: " << std::endl << numbersQuickSort << std::endl << std::endl;
    printSeparator(std::cout);

    // Merge Sort
    std::cout << "Sorting by count of digit 7 using Merge Sort..." << std::endl;

    std::vector<int> numbersMergeSort = generateRandomVector(10, 0, 10000);
    std::cout << "Original Vector: " << std::endl << numbersMergeSort << std::endl << std::endl;

    mergeSort(numbersMergeSort.begin(), numbersMergeSort.end(), [](const int& a, const int& b) {
        auto countDigit7 = [](int n) {
            n = std::abs(n);
            int count = 0;
            while (n != 0) {
                if (n % 10 == 7) {
                    count++;
                }
                n /= 10;
            }
            return count;
        };

        return countDigit7(a) < countDigit7(b);
        }
    );
    std::cout << "Merge Sort: " << std::endl << numbersMergeSort << std::endl << std::endl;
    printSeparator(std::cout);

    return 0;
}
