//RWILHELM2024
#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <filesystem>

void generateInputFiles(int size, int numFiles) {
    // Ensure the "Input Files" directory exists
    std::filesystem::create_directory("Input Files");

    // Random number generator setup
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-100, 100);

    for (int i = 0; i < numFiles; ++i) {
        // File name inside the "Input Files" directory
        std::string filename = "Input Files/Wilhelm_Ryan_input_" + std::to_string(size) + "_" + std::to_string(i + 1) + ".txt";
        std::ofstream outfile(filename);

        if (!outfile) {
            std::cerr << "Error: Could not create file " << filename << std::endl;
            continue;
        }

        for (int j = 0; j < size; ++j) {
            outfile << dis(gen);  // Generate random number
            if (j < size - 1) {
                outfile << " ";  // Add space between numbers
            }
        }

        outfile.close();
        std::cout << "File generated: " << filename << std::endl;
    }
}

int main() {
    generateInputFiles(10, 25);    // Generate 25 files with 10 numbers each
    generateInputFiles(100, 25);  // Generate 25 files with 100 numbers each
    generateInputFiles(1000, 25); // Generate 25 files with 1000 numbers each
    return 0;
}

