#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <cstring>
using namespace std;

int v[1000005];
int original[1000005];

void genereazaRandom(int v[], int n) {
    srand(time(NULL));
    for(int i = 0; i < n; i++) {
        v[i] = rand() % 100000 + 1;
    }
}

void bubbleSort(int v[], int n) {
    bool ok = 0;
    while(!ok) {
        ok = 1;
        for(int i = 0; i < n - 1; i++) {
            if(v[i] > v[i+1]) {
                int aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                ok = 0;
            }
        }
    }
}

void selectionSort(int v[], int n) {
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++)
            if(v[i] > v[j]) {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
}

void insertionSort(int v[], int n) {
    for(int i = 1; i < n; i++) {
        int j = i;
        while(j > 0 && v[j] < v[j-1]) {
            int aux = v[j];
            v[j] = v[j-1];
            v[j-1] = aux;
            j--;
        }
    }
}

void mergeSort(int v[], int st, int dr, int tmp[]) {
    if(st < dr) {
        int m = (st + dr) / 2;
        mergeSort(v, st, m, tmp);
        mergeSort(v, m + 1, dr, tmp);

        int i = st, j = m + 1, k = 0;
        while(i <= m && j <= dr) {
            if(v[i] < v[j])
                tmp[++k] = v[i++];
            else
                tmp[++k] = v[j++];
        }
        while(i <= m)
            tmp[++k] = v[i++];
        while(j <= dr)
            tmp[++k] = v[j++];

        for(int i = st, j = 1; i <= dr; i++, j++)
            v[i] = tmp[j];
    }
}

void quickSort(int v[], int st, int dr) {
    if(st < dr) {
        int m = (st + dr) / 2;
        int aux = v[st];
        v[st] = v[m];
        v[m] = aux;
        int i = st, j = dr, d = 0;

        while(i < j) {
            if(v[i] > v[j]) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
                d = 1 - d;
            }
            i += d;
            j -= 1 - d;
        }
        quickSort(v, st, i - 1);
        quickSort(v, i + 1, dr);
    }
}

int main() {
    int n;

    cout << "n= ";
    cin >> n;

    if(n <= 0 || n > 1000005) {
        n = 100000;
    }

    genereazaRandom(original, n);

    int tmp[1000005];
    long long timp[5];


    // 1. BUBBLE SORT
    cout.flush();
    memcpy(v, original, n * sizeof(int));
    auto t1 = chrono::high_resolution_clock::now();
    bubbleSort(v, n);
    auto t2 = chrono::high_resolution_clock::now();
    timp[0] = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();

    // 2. SELECTION SORT
    cout.flush();
    memcpy(v, original, n * sizeof(int));
    t1 = chrono::high_resolution_clock::now();
    selectionSort(v, n);
    t2 = chrono::high_resolution_clock::now();
    timp[1] = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();

    // 3. INSERTION SORT
    cout.flush();
    memcpy(v, original, n * sizeof(int));
    t1 = chrono::high_resolution_clock::now();
    insertionSort(v, n);
    t2 = chrono::high_resolution_clock::now();
    timp[2] = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();

    // 4. MERGE SORT
    cout.flush();
    memcpy(v, original, n * sizeof(int));
    t1 = chrono::high_resolution_clock::now();
    mergeSort(v, 0, n - 1, tmp);
    t2 = chrono::high_resolution_clock::now();
    timp[3] = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();

    // 5. QUICK SORT
    cout.flush();
    memcpy(v, original, n * sizeof(int));
    t1 = chrono::high_resolution_clock::now();
    quickSort(v, 0, n - 1);
    t2 = chrono::high_resolution_clock::now();
    timp[4] = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();

    cout << "\n1. Bubble Sort       : " << timp[0] << " µs\n";
    cout << "2. Selection Sort    : " << timp[1] << " µs\n";
    cout << "3. Insertion Sort    : " << timp[2] << " µs\n";
    cout << "4. Merge Sort        : " << timp[3] << " µs\n";
    cout << "5. Quick Sort        : " << timp[4] << " µs\n";

    return 0;
}