#include <iostream>
#include <fstream>
#include <vector>

void bubbleSort(std::vector<int>& vec);
void insertionSort(std::vector<int>& vec);
void selectionSort(std::vector<int>& vec);

enum SortingStrategy {
    BubbleSort,
    InsertionSort,
    SelectionSort
};

struct SortingOption {
    SortingStrategy strategy;
    void (*sortFptr)(std::vector<int>&);

    SortingOption() : strategy(BubbleSort), sortFptr(bubbleSort) {}
    SortingOption(SortingStrategy newStrategy, void (*fptr)(std::vector<int>&)) : strategy(newStrategy), sortFptr(fptr) {}
    ~SortingOption() {}
};

SortingOption getSortingOption() {
    SortingOption sortOpt[] = {
        SortingOption(BubbleSort, bubbleSort),
        SortingOption(SelectionSort, selectionSort),
        SortingOption(InsertionSort, insertionSort)
    };

    std::cout << "Select a sorting algorithm:" << std::endl;
    std::cout << "1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort" << std::endl;

    int choice;
    std::cin >> choice;
    if (choice < 1 || choice > 3) {
        std::cerr << "Invalid choice. Exiting." << std::endl;
        exit(1);
    }

    return sortOpt[choice - 1];
}

int main() {
    std::string fileName;
    std::cout << "Enter the name of the input file: ";
    std::cin >> fileName;

    std::ifstream infile(fileName);

    if (!infile.is_open()) {
        std::cout << "Error, file doesn't open" << fileName << std::endl;
        return 1;
    }

    std::vector<int> array;
    int number;
    while (infile >> number) {
        array.push_back(number);
    }

    SortingOption sortOpt = getSortingOption();
    sortOpt.sortFptr(array);

    std::cout << "Sorted array:" << std::endl;
    for (int num : array) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

void bubbleSort(std::vector<int>& vec) {
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

void insertionSort(std::vector<int>& vec) {
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

void selectionSort(std::vector<int>& vec) {
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


