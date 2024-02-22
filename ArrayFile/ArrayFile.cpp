#include <iostream>
using namespace std;

// Функція для введення масиву цілих чисел
void inputIntArray(int*& arr, int& n) {
    cout << "Введіть розмір масиву: ";
    cin >> n;

    arr = new int[n];
    cout << "Введіть " << n << " елементів масиву:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Елемент " << i + 1 << ": ";
        cin >> arr[i];
    }
}

// Функція для введення масиву дійсних чисел
void inputDoubleArray(double*& arr, int& n) {
    cout << "Введіть розмір масиву: ";
    cin >> n;

    arr = new double[n];
    cout << "Введіть " << n << " елементів масиву:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Елемент " << i + 1 << ": ";
        cin >> arr[i];
    }
}

// Функція для підрахунку нульових елементів у масиві цілих чисел
int countZeroElements(const int* arr, int n) {
    int zeroCount = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == 0) {
            zeroCount++;
        }
    }
    return zeroCount;
}

// Функція для пошуку останнього максимального від'ємного елемента
int findLastMaxNegativeIndex(const int* arr, int n, int T) {
    int maxNegativeIndex = -1;
    for (int i = n - 1; i >= 0; --i) {
        if (arr[i] < 0 && arr[i] > arr[T] && i > T) {
            if (maxNegativeIndex == -1 || arr[i] >= arr[maxNegativeIndex]) {
                maxNegativeIndex = i;
            }
        }
    }
    return maxNegativeIndex;
}

// Функція для побудови масиву B
void buildBArray(const double* arrA, double*& arrB, int n) {
    arrB = new double[n];
    for (int i = 0; i < n; ++i) {
        double sum = 0.0;
        for (int j = 0; j < n; ++j) {
            if (j != i) {
                sum += arrA[j];
            }
        }
        arrB[i] = sum / (n - 1);
    }
}

// Функція для виведення масиву
template<typename T>
void printArray(const T* arr, int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice = -1;
    int* intArray = nullptr;
    double* doubleArrayA = nullptr;
    double* doubleArrayB = nullptr;
    int n = 0;
    int T = 0;

    while (choice != 0) {
        setlocale(LC_CTYPE, "Ukr");
        cout << "Виберіть дію:\n";
        cout << "1. Ввести розмір масиву та елементи цілочисельного масиву\n";
        cout << "2. Знайти кількість нульових елементів цілочисельного масиву\n";
        cout << "3. Знайти номер останнього максимального від'ємного елемента у цілочисельному масиві\n";
        cout << "4. Ввести розмір масиву та елементи дійснозначного масиву A\n";
        cout << "5. Побудувати масив B на основі масиву A\n";
        cout << "0. Вийти\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
        case 1:
            inputIntArray(intArray, n);
            break;
        case 2:
            if (intArray == nullptr) {
                cout << "Масив ще не був введений!\n";
                break;
            }
            cout << "Кількість нульових елементів у масиві: " << countZeroElements(intArray, n) << endl;
            break;
        case 3:
            if (intArray == nullptr) {
                cout << "Масив ще не був введений!\n";
                break;
            }
            cout << "Введіть значення T: ";
            cin >> T;
            cout << "Номер останнього максимального від'ємного елемента, розташованого правіше елемента, рівного T: " << findLastMaxNegativeIndex(intArray, n, T) << endl;
            break;
        case 4:
            inputDoubleArray(doubleArrayA, n);
            break;
        case 5:
            if (doubleArrayA == nullptr) {
                cout << "Масив A ще не був введений!\n";
                break;
            }
            buildBArray(doubleArrayA, doubleArrayB, n);
            cout << "Масив B побудований успішно:\n";
            printArray(doubleArrayB, n);
            break;
        case 0:
            cout << "Дякую за використання програми!\n";
            break;
        default:
            cout << "Невірний вибір!\n";
            break;
        }
    }

    // Звільняємо пам'ять, що була виділена для масивів
    delete[] intArray;
    delete[] doubleArrayA;
    delete[] doubleArrayB;

    return 0;
}
