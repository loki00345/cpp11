#include <iostream>
using namespace std;
template<typename T, size_t N>
T findMax(const T(&arr)[N]) {
    if (N == 0) {
        throw invalid_argument("Array is empty");
    }
    T maxVal = arr[0];
    for (size_t i = 1; i < N; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

template<typename T, size_t N>
T findMin(const T(&arr)[N]) {
    if (N == 0) {
        throw invalid_argument("Array is empty");
    }
    T minVal = arr[0];
    for (size_t i = 1; i < N; ++i) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

template<typename T, size_t N>
void selectionSort(T(&arr)[N]) {
    for (size_t i = 0; i < N - 1; ++i) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < N; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            T temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

template<typename T, size_t N>
int binarySearch(const T(&arr)[N], const T& key) {
    int left = 0;
    int right = N - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

template<typename T, size_t N>
void replaceElement(T(&arr)[N], const T& oldValue, const T& newValue) {
    for (size_t i = 0; i < N; ++i) {
        if (arr[i] == oldValue) {
            arr[i] = newValue;
        }
    }
}

int main() {
    int nums[] = { 4, 2, 7, 1, 5, 9, 3 };
    constexpr size_t size = sizeof(nums) / sizeof(nums[0]);

    cout << "Original Array: ";
    for (size_t i = 0; i < size; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    cout << "Max Element: " << findMax(nums) << endl;
    cout << "Min Element: " << findMin(nums) << endl;

    selectionSort(nums);
    cout << "Sorted Array: ";
    for (size_t i = 0; i < size; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    int searchKey = 5;
    int index = binarySearch(nums, searchKey);
    if (index != -1) {
        cout << searchKey << " found at index " << index << endl;
    }
    else {
        cout << searchKey << " not found in the array" << endl;
    }

    int oldValue = 7;
    int newValue = 10;
    replaceElement(nums, oldValue, newValue);
    cout << "Array after replacing " << oldValue << " with " << newValue << ": ";
    for (size_t i = 0; i < size; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

}