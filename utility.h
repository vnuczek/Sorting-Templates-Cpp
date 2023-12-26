#ifndef UTILITY_H
#define UTILITY_H

/**
 * @file
 * @brief This file contains utility functions useful for testing this project
 */

#include <iostream>
#include <vector>
#include <random>

/**
 * @brief Print a separator line with a specified symbol and length
 *
 * This function prints a separator line consisting of a specified symbol and a specified length to visually distinguish different sections of output
 *
 * @param os The output stream to which the separator is printed
 * @param symbol The symbol to use for the separator line (default is '-')
 * @param length The length of the separator line (default is 50)
 * @date 2023-12-26
 * @author Vnuczek
 */
inline void printSeparator(std::ostream& os, const char symbol = '-', const std::size_t& length = 50) {
    os << std::endl << std::string(length, symbol) << std::endl << std::endl;
}


/**
 * @brief Generate a vector of random integers
 *
 * @param size The size of the vector
 * @param minVal The minimum value for the generated integers
 * @param maxVal The maximum value for the generated integers
 * @return A vector of random integers
 * @date 2023-12-26
 * @author Vnuczek
 */
inline std::vector<int> generateRandomVector(size_t size, int minVal, int maxVal) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(minVal, maxVal);

    std::vector<int> randomVector(size);
    for (size_t i = 0; i < size; ++i) {
        randomVector[i] = distribution(gen);
    }

    return randomVector;
}

/**
 * @brief Generate a vector of random double-precision floating-point numbers
 *
 * @param size The size of the vector
 * @param minVal The minimum value for the generated doubles
 * @param maxVal The maximum value for the generated doubles
 * @return A vector of random double-precision floating-point numbers
 * @date 2023-12-26
 * @author Vnuczek
 */
inline std::vector<double> generateRandomVector(size_t size, double minVal, double maxVal) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> distribution(minVal, maxVal);

    std::vector<double> randomVector(size);
    for (size_t i = 0; i < size; ++i) {
        randomVector[i] = distribution(gen);
    }

    return randomVector;
}

/**
 * @brief Print the elements of a vector
 *
 * @tparam T Type of elements in the vector
 * @param os Output stream
 * @param vec Vector to be printed
 * @date 2023-12-26
 * @author Vnuczek
 */
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << "[ ";
    if (!vec.empty()) {
        os << vec[0];
        for (size_t i = 1; i < vec.size(); ++i) {
            os << ", " << vec[i];
        }
    }
    os << " ]";
    return os;
}

#endif
