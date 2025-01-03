//Rwilhelm2024
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>
#include <algorithm>

// Function to read floating-point numbers from a file
std::vector<float> readInputFile(const std::string& filename) {
    std::vector<float> numbers;
    std::ifstream infile(filename);
    if (!infile) {
        std::cerr << "Error: Could not open input file." << std::endl;
        return numbers;
    }
    float num;
    while (infile >> num) {
        numbers.push_back(num);
    }
    return numbers;
}

// Function to write sorted numbers to a file
void writeOutputFile(const std::string& filename, const std::vector<float>& numbers) {
    std::ofstream outfile(filename);
    if (!outfile) {
        std::cerr << "Error: Could not open output file." << std::endl;
        return;
    }
    for (size_t i = 0; i < numbers.size(); ++i) {
        outfile << numbers[i];
        if (i < numbers.size() - 1) {
            outfile << " ";
        }
    }
}

// Function to write execution time to a file
void writeExecutionTime(const std::string& filename, long long duration) {
    std::ofstream outfile(filename);
    if (!outfile) {
        std::cerr << "Error: Could not open time file." << std::endl;
        return;
    }
    outfile << duration << " microseconds";
}

// Median-of-Three method for pivot selection
int medianOfThree(std::vector<float>& arr, int left, int right) {
    int mid = left + (right - left) / 2;

    // Sort left, mid, right
    if (arr[left] > arr[mid]) std::swap(arr[left], arr[mid]);
    if (arr[left] > arr[right]) std::swap(arr[left], arr[right]);
    if (arr[mid] > arr[right]) std::swap(arr[mid], arr[right]);

    // Place pivot at left
    std::swap(arr[left], arr[mid]);
    return left;
}

// Partition function for QuickSort
int partition(std::vector<float>& arr, int left, int right) {
    int pivotIndex = medianOfThree(arr, left, right);
    float pivot = arr[pivotIndex];
    int i = left + 1;

    for (int j = left + 1; j <= right; ++j) {
        if (arr[j] < pivot) {
            std::swap(arr[i], arr[j]);
            ++i;
        }
    }
    std::swap(arr[left], arr[i - 1]); // Place pivot in correct position
    return i - 1;
}

// QuickSort algorithm
void quickSort(std::vector<float>& arr, int left, int right) {
    if (left < right) {
        int pivotIndex = partition(arr, left, right);
        quickSort(arr, left, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, right);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: ./Wilhelm_Ryan_QuickSort input.txt output.txt" << std::endl;
        return 1;
    }

    std::string inputFile = argv[1];
    std::string outputFile = argv[2];
    std::string timeFile = "execution_time.txt";

    // Read input file
    std::vector<float> numbers = readInputFile(inputFile);
    if (numbers.empty()) return 1;

    // Measure execution time
    auto start = std::chrono::high_resolution_clock::now();
    quickSort(numbers, 0, numbers.size() - 1);
    auto end = std::chrono::high_resolution_clock::now();

    long long duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    // Write sorted numbers to output file
    writeOutputFile(outputFile, numbers);

    // Write execution time to time file
    writeExecutionTime(timeFile, duration);

    return 0;
}

