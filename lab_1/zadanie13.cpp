#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <functional>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Sorting {
public:
    // Funkcja pomiaru czasu sortowania
    static double measurement(float* Data, int Size, void(*sort)(float[], int)) {
        auto start = high_resolution_clock::now(); // Rozpoczęcie pomiaru czasu
        sort(Data, Size); // Wywołanie algorytmu sortowania
        auto stop = high_resolution_clock::now(); // Zakończenie pomiaru czasu
        duration<double> elapsed = stop - start;
        return elapsed.count();
    }
};

// Algorytm bąbelkowy
void bubbleSort(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Algorytm stogowy (kopcowy)
void heapify(float arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(float arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Algorytm quicksort
int partition(float arr[], int low, int high) {
    float pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(float arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void quickSortWrapper(float arr[], int n) {
    quickSort(arr, 0, n - 1);
}

int main() {
    const int numTests = 1000;
    const int dataSize = 300;
    const int maxValue = 1000;

    srand(time(nullptr)); // Inicjalizacja generatora liczb losowych

    double totalTimeBubble = 0;
    double totalTimeHeap = 0;
    double totalTimeQuick = 0;

    for (int test = 0; test < numTests; test++) {
        float data[dataSize];
        float dataCopy[dataSize];

        // Generowanie losowego ciągu
        for (int i = 0; i < dataSize; i++) {
            data[i] = rand() % (maxValue + 1);
        }

        // Kopiowanie danych do użycia w różnych algorytmach
        copy(data, data + dataSize, dataCopy);
        totalTimeBubble += Sorting::measurement(dataCopy, dataSize, bubbleSort);

        copy(data, data + dataSize, dataCopy);
        totalTimeHeap += Sorting::measurement(dataCopy, dataSize, heapSort);

        copy(data, data + dataSize, dataCopy);
        totalTimeQuick += Sorting::measurement(dataCopy, dataSize, quickSortWrapper);
    }

    // Wyświetlanie wyników
    cout << "BS " << totalTimeBubble / numTests << endl;
    cout << "HS " << totalTimeHeap / numTests << endl;
    cout << "QS " << totalTimeQuick / numTests << endl;

    return 0;
}
