#include "sortAlgSel-header.hpp"
#include <fstream>
#include <iostream>

SortingStrategy::~SortingStrategy() {}

void BubbleSort::sort(std::vector<int>& vec) const {
    bool flag = true;
    for (int i = 0; i < vec.size(); ++i) {
        flag = true;
        for (int j = 0; j < vec.size() - 1 - i; ++j) {
            if (vec[j] > vec[j + 1]) {
                flag = false;
                std::swap(vec[j], vec[j + 1]);
            }
        }
        if (flag) {
            return;
        }
    }
}

void InsertionSort::sort(std::vector<int>& vec) const {
    for (int i = 1; i < vec.size(); ++i) {
        int tmp = vec[i];
        int j = i - 1;
        while (j >= 0 && tmp < vec[j]) {
            vec[j + 1] = vec[j];
            --j;
        }
        vec[j + 1] = tmp;
    }
}

void SelectionSort::sort(std::vector<int>& vec) const {
    for (int i = 0; i < vec.size() - 1; ++i) {
        int tmp = i;
        for (int j = i + 1; j < vec.size(); j++) {
            if (vec[tmp] > vec[j]) {
                tmp = j;
            }
        }
        if (tmp != i) {
            std::swap(vec[tmp], vec[i]);
        }
    }
}

std::vector<int> FileHandler::readArrayFromFile(const std::string& filename) {
    std::ifstream infile(filename);
    std::vector<int> vec;

    if (infile.is_open()) {
        int num;
        while (infile >> num) {
            vec.push_back(num);
        }
        infile.close();
    } else {
        std::cout << "Error, file doesn't open" << std::endl;
    }

    return vec;
}

void FileHandler::addArrayToFile(const std::string& filename, const std::vector<int>& vec) {
    std::ofstream outfile(filename);
        if (outfile.is_open()) {
        for (int num : vec) {
            outfile << num << " ";
        }
        outfile.close();
    } else {
        std::cout << "Error, file doesn't open" << std::endl;
    }
}

SortingApplication::SortingApplication() : sortingAlgorithm(nullptr) {}

SortingApplication::~SortingApplication() {
    delete sortingAlgorithm;
    sortingAlgorithm = nullptr;
}

void SortingApplication::getUserInput() {
    std::cout << "Enter the name of the input file: ";
    std::string infileName;
    std::cin >> infileName;

    std::cout << "Enter the name of the output file: ";
    std::string outfileName;
    std::cin >> outfileName;

    selectSortingAlgorithm();

    std::vector<int> arr = fileHandler.readArrayFromFile(infileName);

    if (sortingAlgorithm != nullptr) {
        sortingAlgorithm->sort(arr);

        fileHandler.addArrayToFile(outfileName, arr);

        std::cout << "Sorting completed. Sorted array saved to " << outfileName << std::endl;
    } else {
        std::cout << "No sorting algorithm selected." << std::endl;
    }
}

void SortingApplication::selectSortingAlgorithm() {
    std::cout << "Select a sorting algorithm:" << std::endl;
    std::cout << "1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort" << std::endl;
    std::cout << "Enter your choice (1, 2, or 3): ";
    int choice;
    std::cin >> choice;

    delete sortingAlgorithm;

    // if (choice < 1 || choice > 3) {
    //     std::cerr << "Invalid choice. Exiting." << std::endl;
    //     exit(1);
    // }

    if (choice == 1) {
        sortingAlgorithm = new BubbleSort();
    } else if (choice == 2) {
        sortingAlgorithm = new InsertionSort();
    } else if (choice == 3) {
        sortingAlgorithm = new SelectionSort();
    } else {
        std::cout << "Invalid choice. Defaulting to Bubble Sort." << std::endl;
        sortingAlgorithm = new BubbleSort();
    }
}

