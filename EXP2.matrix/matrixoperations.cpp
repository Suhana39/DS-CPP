#include <iostream>
using namespace std;

int main() {
    int r1, c1, r2, c2;
    int choice;

    cout << "Enter rows and columns of first matrix: ";
    cin >> r1 >> c1;

    cout << "Enter rows and columns of second matrix: ";
    cin >> r2 >> c2;

    int a[10][10], b[10][10], result[10][10];

    cout << "\nEnter elements of first matrix:\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cin >> a[i][j];
        }
    }

    cout << "\nEnter elements of second matrix:\n";
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            cin >> b[i][j];
        }
    }

    do {
        cout << "\n--- Matrix Operations Menu ---\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                if (r1 != r2 || c1 != c2) {
                    cout << "Addition not possible!\n";
                } else {
                    cout << "Result of addition:\n";
                    for (int i = 0; i < r1; i++) {
                        for (int j = 0; j < c1; j++) {
                            result[i][j] = a[i][j] + b[i][j];
                            cout << result[i][j] << " ";
                        }
                        cout << endl;
                    }
                }
                break;

            case 2:
                if (r1 != r2 || c1 != c2) {
                    cout << "Subtraction not possible!\n";
                } else {
                    cout << "Result of subtraction:\n";
                    for (int i = 0; i < r1; i++) {
                        for (int j = 0; j < c1; j++) {
                            result[i][j] = a[i][j] - b[i][j];
                            cout << result[i][j] << " ";
                        }
                        cout << endl;
                    }
                }
                break;

            case 3:
                if (c1 != r2) {
                    cout << "Multiplication not possible!\n";
                } else {
                    cout << "Result of multiplication:\n";
                    for (int i = 0; i < r1; i++) {
                        for (int j = 0; j < c2; j++) {
                            result[i][j] = 0;
                            for (int k = 0; k < c1; k++) {
                                result[i][j] += a[i][k] * b[k][j];
                            }
                            cout << result[i][j] << " ";
                        }
                        cout << endl;
                    }
                }
                break;

            case 4:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
