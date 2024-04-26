
#include <iostream>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int a[], int m, int p) {
    int v = a[m];
    int i = m;
    int j = p;

    do {
        do {
            i++;
        } while(a[i] < v);

        do {
            j--;
        } while(a[j] > v);

        if (i < j) {
            swap(a[i], a[j]);
        }
    } while (i < j);

    a[m] = a[j];
    a[j] = v;

    return j;
}

void quickSort(int a[], int p, int q) {
    if (p < q) {
        int j = partition(a, p, q + 1);
        quickSort(a, p, j - 1);
        quickSort(a, j + 1, q);
    }
}

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    int a[n];
    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    quickSort(a, 0, n - 1);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }

    return 0;
}
