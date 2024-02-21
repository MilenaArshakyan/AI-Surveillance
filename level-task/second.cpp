/*Առաջադրանք 2
Շրջել նկարը հորիզոնական ուղղությամբ
Տրված է n x n չափի մատրից բաղկացած 0 և 1 արժեքներից։
Իրականացնել ֆունկցիա, որը տրված մատրիցը կշրջի հորիզոնական ուղղությամբ, այնուհետև կհակադարձի(invert) մատրիցի էլեմենտների արժեքները և կվերադարձնի այն։
Մատրիցը հորիզոնական շրջել նշանակում է գրել մատրիցի յուրաքանյուր տողի արժեքները հակառակ հերթականությամբ, օրինակ՝
[0, 1, 0, 0] —> [0, 0, 1, 0]
Մատրիցի արժեքները հակադարձել նշանակում է փոխարինել բոլոր 1֊երը 0-ներով և հակառակը, օրինակ՝
[0, 0, 1, 0] —> [1, 1, 0, 1]
Ֆունկցիայի աշխատանքի օրինակ`
Input:
[ [0, 0, 1, 0], 
  [1, 1, 1, 0], 
  [0, 0, 0, 1] ]
Output:
[ [1, 0, 1, 1], 
  [1, 0, 0, 0], 
  [0, 1, 1, 1] ] */


#include <iostream>

void print(int** matrix, size_t n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void horizontalInvert(int** arr, size_t n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n / 2; ++j) {
			std::swap(arr[i][j],arr[i][n - 1 - j]);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			arr[i][j] ^= 1;
		}
	}
}

int main() {
	
	srand(time(0));

	size_t n = 0;
	std::cin >> n;

	int** arr = new int*[n];
	
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			arr[i][j] = 0 + rand() % 2;
		}
	}

    print(arr, n);
	horizontalInvert(arr, n);
	print(arr, n);

	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}

	delete []arr;
    return 0;
}


