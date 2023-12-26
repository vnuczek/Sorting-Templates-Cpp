#ifndef SORTINGTEMPLATES_H
#define SORTINGTEMPLATES_H

/**
 * @file
 * @brief This file contains template functions for various sorting algorithms
 */

/**
 * @brief Template function for Bubble Sort algorithm
 *
 * @tparam Iterator Type of the iterator
 * @tparam Compare Type of the comparison function
 * @param begin Iterator pointing to the beginning of the sequence
 * @param end Iterator pointing to the end of the sequence
 * @param cmp Comparison function for custom ordering
 * @date 2023-12-26
 * @author Vnuczek
 */
template <typename Iterator, typename Compare>
void bubbleSort(Iterator begin, Iterator end, Compare cmp) {
    for (Iterator i = begin; i != end; ++i) {
        for (Iterator j = begin; j != end - 1; ++j) {
            if (cmp(*(j + 1), *j)) {
                std::swap(*j, *(j + 1));
            }
        }
    }
}

/**
 * @brief Template function for Selection Sort algorithm
 *
 * @tparam Iterator Type of the iterator
 * @tparam Compare Type of the comparison function
 * @param begin Iterator pointing to the beginning of the sequence
 * @param end Iterator pointing to the end of the sequence
 * @param cmp Comparison function for custom ordering
 * @date 2023-12-26
 * @author Vnuczek
 */
template <typename Iterator, typename Compare>
void selectionSort(Iterator begin, Iterator end, Compare cmp) {
    for (Iterator i = begin; i != end; ++i) {
        Iterator minElement = i;
        for (Iterator j = i + 1; j != end; ++j) {
            if (cmp(*j, *minElement)) {
                minElement = j;
            }
        }
        std::swap(*i, *minElement);
    }
}

/**
 * @brief Template function for Insertion Sort algorithm
 *
 * @tparam Iterator Type of the iterator
 * @tparam Compare Type of the comparison function
 * @param begin Iterator pointing to the beginning of the sequence
 * @param end Iterator pointing to the end of the sequence
 * @param cmp Comparison function for custom ordering
 * @date 2023-12-26
 * @author Vnuczek
 */
template <typename Iterator, typename Compare>
void insertionSort(Iterator begin, Iterator end, Compare cmp) {
    for (Iterator i = begin + 1; i != end; ++i) {
        auto key = *i;
        Iterator j = i;
        while (j != begin && cmp(key, *(j - 1))) {
            *j = *(j - 1);
            --j;
        }
        *j = key;
    }
}


/**
 * @brief Template function for Quick Sort algorithm
 *
 * @tparam Iterator Type of the iterator
 * @tparam Compare Type of the comparison function
 * @param begin Iterator pointing to the beginning of the sequence
 * @param end Iterator pointing to the end of the sequence
 * @param cmp Comparison function for custom ordering
 * @date 2023-12-26
 * @author Vnuczek
 */
template <typename Iterator, typename Compare>
void quickSort(Iterator begin, Iterator end, Compare cmp) {
    if (std::distance(begin, end) <= 1) {
        return;
    }

    Iterator pivot = begin + std::distance(begin, end) / 2;
    auto pivotValue = *pivot;

    Iterator left = begin;
    Iterator right = end - 1;

    while (left <= right) {
        while (cmp(*left, pivotValue)) {
            ++left;
        }

        while (cmp(pivotValue, *right)) {
            --right;
        }

        if (left <= right) {
            std::swap(*left, *right);
            ++left;
            --right;
        }
    }

    quickSort(begin, right + 1, cmp);
    quickSort(left, end, cmp);
}

/**
 * @brief Template function for Merge Sort algorithm
 *
 * @tparam Iterator Type of the iterator
 * @tparam Compare Type of the comparison function
 * @param begin Iterator pointing to the beginning of the sequence
 * @param end Iterator pointing to the end of the sequence
 * @param cmp Comparison function for custom ordering
 * @date 2023-12-26
 * @author Vnuczek
 */
template <typename Iterator, typename Compare>
void mergeSort(Iterator begin, Iterator end, Compare cmp) {
    if (std::distance(begin, end) <= 1) {
        return;
    }

    Iterator mid = begin + (end - begin) / 2;

    mergeSort(begin, mid, cmp);
    mergeSort(mid, end, cmp);

    std::vector<typename Iterator::value_type> merged;
    Iterator i = begin;
    Iterator j = mid;

    while (i < mid && j < end) {
        if (cmp(*j, *i)) {
            merged.push_back(*j);
            ++j;
        }
        else {
            merged.push_back(*i);
            ++i;
        }
    }

    while (i < mid) {
        merged.push_back(*i);
        ++i;
    }

    while (j < end) {
        merged.push_back(*j);
        ++j;
    }

    std::copy(merged.begin(), merged.end(), begin);
}

#endif
