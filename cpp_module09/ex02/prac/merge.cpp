#include <iostream>
#include <vector>

// Function to merge two subvectors
void merge(std::vector<int>& array, int left, int mid, int right) {
    int subArrayOne = mid - left + 1;
    int subArrayTwo = right - mid;

    // Create temp arrays
    std::vector<int> leftArray(subArrayOne), rightArray(subArrayTwo);

    // Copy data to temp arrays leftArray and rightArray
    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    int indexOfSubArrayOne = 0;    // Initial index of first sub-array
    int indexOfSubArrayTwo = 0;    // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        } else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    // Copy the remaining elements of leftArray, if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    // Copy the remaining elements of rightArray, if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

// Recursive function to sort the vector using merge sort
void mergeSort(std::vector<int>& array, int left, int right) {
    if (left >= right) {
        return; // Returns recursively
    }

    int mid = left + (right - left) / 2;
    mergeSort(array, left, mid);
    mergeSort(array, mid + 1, right);
    merge(array, left, mid, right);
}

// Function to print an array
void printArray(const std::vector<int>& A, int size) {
    for (int i = 0; i < size; i++)
        std::cout << A[i] << " ";
    std::cout << "\n";
}

// Driver code
int main() {
    int rawArray[] = {3, 1, 2, 4, 6, 5, 9, 7, 8, 0};
    std::vector<int> arr(rawArray, rawArray + sizeof(rawArray) / sizeof(rawArray[0]));
    int arr_size = static_cast<int>(arr.size());

    std::cout << "Given array is \n";
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    std::cout << "Sorted array is \n";
    printArray(arr, arr_size);
    return 0;
}