o/*
Առաջադրանք 3
Հաշվել նկարում օբյեկտների քանակը

Տրված է նկար, որը ներկայացված է m x n չափանի մատրիցի տեսքով։ Նկարը ունի միայն սև և սպիտակ գույներ, որոնք մատրիցում արտահայտվում են համապատասխանաբար 0 և 1 թվերի միջոցով։ Նկարում օբյեկտները ներկայացված են կապակցված 1-երից (հարևան են՝ հորիզոնական և ուղղահայաց ուղղություններով, անկյունագծով կից տարրերը հարևան չեն համարվում)։ Անհրաժեշտ է այդ մատրիցում գտնել օբյեկտների քանակը։ 
Օրինակ հետևյալ մատրիցում կան 3 օբյեկտներ։
Input: [ [1, 1, 1, 0, 0, 0], 
[0, 1, 1, 0, 0, 0], 
[0, 0, 0, 1, 1, 0], 
[0, 1, 1, 0, 1, 0] ]

Output: 3
*/

#include <iostream>

void foo(int** matrix, int i, int j, int m, int n) {
    if (i < 0 || i >= m || j < 0 || j >= n || matrix[i][j] == 0) {
        return;
    }
    matrix[i][j] = 0;

    foo(matrix, i + 1, j, m, n);
    foo(matrix, i - 1, j, m, n);
    foo(matrix, i, j + 1, m, n);
    foo(matrix, i, j - 1, m, n);
}

int objectsCount(int** matrix, size_t m, size_t n) {
    int count = 0;
    for (size_t i = 0; i < m; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (matrix[i][j] == 1) {
                ++count;
                foo(matrix, i, j, m, n);
            }
        }
    }
    return count;
}

int main() {
    size_t m = 0;
    size_t n = 0;
    std::cout << "enter m: ";
    std::cin >> m;
    std::cout << "enter n: ";
    std::cin >> n;

    int** matrix = new int*[m];
    for (size_t i = 0; i < m; ++i) {
        matrix[i] = new int[n];
    }

    std::cout << "Enter matrix values (0 or 1):" << std::endl;
    for (size_t i = 0; i < m; ++i) {
        for (size_t j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    std::cout << "Number of objects: " << objectsCount(matrix, m, n) << std::endl;

    for (size_t i = 0; i < m; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

