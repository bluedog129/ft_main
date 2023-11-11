#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& arr) {
    int i, key, j;
    int n = arr.size();
    for (i = 1; i < n; i++) {
        key = arr[i]; // 현재 삽입될 숫자
        j = i - 1;

        /* 배열의 정렬된 부분에 대해,
           현재 숫자보다 큰 숫자들을 한 칸씩 뒤로 옮깁니다. */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // 적절한 위치에 숫자를 삽입합니다.
    }
}

// 배열을 출력하는 함수
void printArray(const std::vector<int>& array) {
    for (int i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

// 메인 함수
int main() {
    std::vector<int> arr = {3, 1, 2, 4, 6, 5, 9, 7, 8, 0};
    std::cout << "Original array:\n";
    printArray(arr);

    insertionSort(arr);
    std::cout << "Sorted array:\n";
    printArray(arr);
    
    return 0;
}
