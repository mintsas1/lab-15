#include <iostream>

using namespace std;


void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}


void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int maxIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            swap(arr[i], arr[maxIndex]);
        }
    }
}

void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int pivot = arr[(left + right) / 2];
        int i = left;
        int j = right;

        while (i <= j) {
            while (arr[i] > pivot) {
                i++;
            }
            while (arr[j] < pivot) {
                j--;
            }
            if (i <= j) {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }

        quickSort(arr, left, j);
        quickSort(arr, i, right);
    }
}

int main() {
    setlocale(LC_CTYPE, "ukr"); 

    int n;
    cout << "Введіть ціле число n: ";
    cin >> n;

    
    int* divisors = new int[n / 2 + 1]; 

    int count = 0;
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            divisors[count++] = i;
        }
    }

    
    cout << "Масив дільників числа " << n << ": ";
    for (int i = 0; i < count; ++i) {
        cout << divisors[i] << " ";
    }
    cout << endl;

    
    selectionSort(divisors, count);

   
    cout << "Відсортований масив (сортування за вибором): ";
    for (int i = 0; i < count; ++i) {
        cout << divisors[i] << " ";
    }
    cout << endl;

    
    quickSort(divisors, 0, count - 1);

    
    cout << "Відсортований масив (швидке сортування): ";
    for (int i = 0; i < count; ++i) {
        cout << divisors[i] << " ";
    }
    cout << endl;

    delete[] divisors;

    return 0;
}
