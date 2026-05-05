#include <iostream>
using namespace std;

//////////////////// DISPLAY ////////////////////
void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

//////////////////// INSERTION SORT ////////////////////
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

//////////////////// MERGE SORT ////////////////////
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[100], R[100];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

//////////////////// QUICK SORT ////////////////////
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

//////////////////// MAIN ////////////////////
int main() {
    int arr[100], n, ch;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    do {
        cout << "\n--- SORTING MENU ---\n";
        cout << "1. Insertion Sort\n";
        cout << "2. Merge Sort\n";
        cout << "3. Quick Sort\n";
        cout << "4. Display\n";
        cout << "0. Exit\n";
        cin >> ch;

        switch (ch) {
            case 1:
                insertionSort(arr, n);
                cout << "After Insertion Sort:\n";
                display(arr, n);
                break;

            case 2:
                mergeSort(arr, 0, n - 1);
                cout << "After Merge Sort:\n";
                display(arr, n);
                break;

            case 3:
                quickSort(arr, 0, n - 1);
                cout << "After Quick Sort:\n";
                display(arr, n);
                break;

            case 4:
                display(arr, n);
                break;
        }

    } while (ch != 0);

    return 0;
}
