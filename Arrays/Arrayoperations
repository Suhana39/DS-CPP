#include <iostream>
using namespace std;

int main() {
    int arr[100], n = 0, choice, pos, value, key;

    do {
        cout << "\n--- Array Operations Menu ---\n";
        cout << "1. Insert elements\n";
        cout << "2. Display array\n";
        cout << "3. Insert at position\n";
        cout << "4. Delete from position\n";
        cout << "5. Search element\n";
        cout << "6. Sort array (Ascending)\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter number of elements: ";
                cin >> n;
                cout << "Enter elements:\n";
                for (int i = 0; i < n; i++) {
                    cin >> arr[i];
                }
                break;

            case 2:
                if (n == 0) {
                    cout << "Array is empty!\n";
                } else {
                    cout << "Array elements: ";
                    for (int i = 0; i < n; i++) {
                        cout << arr[i] << " ";
                    }
                    cout << endl;
                }
                break;

            case 3:
                if (n == 0) {
                    cout << "Array is empty!\n";
                } else {
                    cout << "Enter position (1 to " << n + 1 << "): ";
                    cin >> pos;
                    cout << "Enter value: ";
                    cin >> value;

                    if (pos < 1 || pos > n + 1) {
                        cout << "Invalid position!\n";
                    } else {
                        for (int i = n; i >= pos; i--) {
                            arr[i] = arr[i - 1];
                        }
                        arr[pos - 1] = value;
                        n++;
                        cout << "Element inserted.\n";
                    }
                }
                break;

            case 4:
                if (n == 0) {
                    cout << "Array is empty!\n";
                } else {
                    cout << "Enter position to delete (1 to " << n << "): ";
                    cin >> pos;

                    if (pos < 1 || pos > n) {
                        cout << "Invalid position!\n";
                    } else {
                        for (int i = pos - 1; i < n - 1; i++) {
                            arr[i] = arr[i + 1];
                        }
                        n--;
                        cout << "Element deleted.\n";
                    }
                }
                break;

            case 5:
                if (n == 0) {
                    cout << "Array is empty!\n";
                } else {
                    cout << "Enter element to search: ";
                    cin >> key;
                    bool found = false;
                    for (int i = 0; i < n; i++) {
                        if (arr[i] == key) {
                            cout << "Element found at position " << i + 1 << endl;
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "Element not found.\n";
                    }
                }
                break;

            case 6:
                if (n == 0) {
                    cout << "Array is empty!\n";
                } else {
                    for (int i = 0; i < n - 1; i++) {
                        for (int j = i + 1; j < n; j++) {
                            if (arr[i] > arr[j]) {
                                int temp = arr[i];
                                arr[i] = arr[j];
                                arr[j] = temp;
                            }
                        }
                    }
                    cout << "Array sorted in ascending order.\n";
                }
                break;

            case 7:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 7);

    return 0;
}
