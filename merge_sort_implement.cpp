#include <iostream>
using namespace std;

void merge(int arr[], int lb, int mid, int up) {
    int i, j, k;
    i = 0;
    k = lb;
    j = 0;
    
    int leftSize = mid - lb + 1;
    int rightSize = up - mid;
    int left[leftSize];
    int right[rightSize];

    for (int a = 0; a < leftSize; a++) {
        left[a] = arr[lb + a];
    }
    for (int a = 0; a < rightSize; a++) {
        right[a] = arr[mid + 1 + a];
    }

    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int lb, int up) {
    if (lb >= up) {
        return;
    }

    int mid = (lb + up) / 2;
    mergeSort(arr, lb, mid);
    mergeSort(arr, mid + 1, up);
    merge(arr, lb, mid, up);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}