#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    int arrElements[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> arr(arrElements, arrElements + sizeof(arrElements) / sizeof(arrElements[0]));
    int target = 5;

    int result = binarySearch(arr, target);

    if (result != -1) {
        std::cout << "Element found at index: " << result << std::endl;
    } else {
        std::cout << "Element not found in the array" << std::endl;
    }

    return 0;
}