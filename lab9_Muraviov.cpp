#include <iostream>
using namespace std;

int main() {
    setlocale(LC_CTYPE, "ukr");
    int a, b;
    cout << "Введіть кількість рядків і стовпців: ";
    cin >> a >> b;

    if (a <= 0 || b <= 0) {
        cout << "Невірний розмір масиву\n";
        return 1;
    }

    if (a * b < 2) {
        cout << "Недостатньо елементів\n";
        return 1;
    }

    double** arr = new double* [a];
    for (int i = 0; i < a; i++) {
        arr[i] = new double[b];
    }

    cout << "Введіть елементи масиву:\n";
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin >> arr[i][j];
        }
    }

    double max1 = arr[0][0], max2 = arr[0][0];
    double min1 = arr[0][0], min2 = arr[0][0];

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            double x = arr[i][j];

            if (x > max1) {
                max2 = max1;
                max1 = x;
            }
            else if (x > max2) {
                max2 = x;
            }

            if (x < min1) {
                min2 = min1;
                min1 = x;
            }
            else if (x < min2) {
                min2 = x;
            }
        }
    }

    double product = max1 * max2;
    double difference = min1 - min2;

    double* rowSum = new double[a];

    for (int i = 0; i < a; i++) {
        rowSum[i] = 0;
        for (int j = 0; j < b; j++) {
            rowSum[i] += arr[i][j];
        }
    }

    cout << "\nДобуток двох максимальних: " << product << endl;
    cout << "Різниця двох мінімальних: " << difference << endl;

    cout << "Суми рядків:\n";
    for (int i = 0; i < a; i++) {
        cout << rowSum[i] << " ";
    }
    cout << endl;
   
    for (int i = 0; i < a; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    delete[] rowSum;

    return 0;
}