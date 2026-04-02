#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>
using namespace std;

int v[100005];

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
        for(int i = 0; i < n - 1; i++) {#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>
using namespace std;

int v[100005];

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

void mergeSort(int v[], int st, int dr) {
	int tmp[100005];
	if(st < dr) {
		int m = (st + dr) / 2;
		mergeSort(v, st, m);
		mergeSort(v, m + 1, dr);

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

	if(n <= 0 || n > 100005) {
		n = 10000;
	}

	genereazaRandom(v, n);

	int copia1[100005], copia2[100005], copia3[100005], copia4[100005], copia5[100005];
	long long timp[5];

	// Bubble Sort
	for(int i = 0; i < n; i++) copia1[i] = v[i];
	auto t1 = chrono::high_resolution_clock::now();
	bubbleSort(copia1, n);
	auto t2 = chrono::high_resolution_clock::now();
	timp[0] = chrono::duration_cast<chrono::milliseconds>(t2 - t1).count();

	// Selection Sort
	for(int i = 0; i < n; i++) copia2[i] = v[i];
	t1 = chrono::high_resolution_clock::now();
	selectionSort(copia2, n);
	t2 = chrono::high_resolution_clock::now();
	timp[1] = chrono::duration_cast<chrono::milliseconds>(t2 - t1).count();

	// Insertion Sort
	for(int i = 0; i < n; i++) copia3[i] = v[i];
	t1 = chrono::high_resolution_clock::now();
	insertionSort(copia3, n);
	t2 = chrono::high_resolution_clock::now();
	timp[2] = chrono::duration_cast<chrono::milliseconds>(t2 - t1).count();

	// Merge Sort
	for(int i = 0; i < n; i++) copia4[i] = v[i];
	t1 = chrono::high_resolution_clock::now();
	mergeSort(copia4, 0, n - 1);
	t2 = chrono::high_resolution_clock::now();
	timp[3] = chrono::duration_cast<chrono::milliseconds>(t2 - t1).count();

	// Quick Sort
	for(int i = 0; i < n; i++) copia5[i] = v[i];
	t1 = chrono::high_resolution_clock::now();
	quickSort(copia5, 0, n - 1);
	t2 = chrono::high_resolution_clock::now();
	timp[4] = chrono::duration_cast<chrono::milliseconds>(t2 - t1).count();

	long long minim = timp[0];
	int poz = 0;
	for(int i = 1; i < 5; i++) {
		if(timp[i] < minim) {
			minim = timp[i];
			poz = i;
		}
	}

	cout << "1. Bubble Sort - " << timp[0] << " ms\n";
	cout << "2. Selection Sort - " << timp[1] << " ms\n";
	cout << "3. Insertion Sort - " << timp[2] << " ms\n";
	cout << "4. Merge Sort - " << timp[3] << " ms\n";
	cout << "5. Quick Sort - " << timp[4] << " ms\n";

	return 0;
}
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

void mergeSort(int v[], int st, int dr) {
    int tmp[100005];
    if(st < dr) {
        int m = (st + dr) / 2;
        mergeSort(v, st, m);
        mergeSort(v, m + 1, dr);
        
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
    
    cout << "Introduceti numarul de elemente: ";
    cin >> n;
    
    if(n <= 0 || n > 100005) {
        n = 10000;
    }
    
    genereazaRandom(v, n);
    
    int copia1[100005], copia2[100005], copia3[100005], copia4[100005], copia5[100005];
    long long timp[5];
    
    // Bubble Sort
    for(int i = 0; i < n; i++) copia1[i] = v[i];
    auto t1 = chrono::high_resolution_clock::now();
    bubbleSort(copia1, n);
    auto t2 = chrono::high_resolution_clock::now();
    timp[0] = chrono::duration_cast<chrono::milliseconds>(t2 - t1).count();
    
    // Selection Sort
    for(int i = 0; i < n; i++) copia2[i] = v[i];
    t1 = chrono::high_resolution_clock::now();
    selectionSort(copia2, n);
    t2 = chrono::high_resolution_clock::now();
    timp[1] = chrono::duration_cast<chrono::milliseconds>(t2 - t1).count();
    
    // Insertion Sort
    for(int i = 0; i < n; i++) copia3[i] = v[i];
    t1 = chrono::high_resolution_clock::now();
    insertionSort(copia3, n);
    t2 = chrono::high_resolution_clock::now();
    timp[2] = chrono::duration_cast<chrono::milliseconds>(t2 - t1).count();
    
    // Merge Sort
    for(int i = 0; i < n; i++) copia4[i] = v[i];
    t1 = chrono::high_resolution_clock::now();
    mergeSort(copia4, 0, n - 1);
    t2 = chrono::high_resolution_clock::now();
    timp[3] = chrono::duration_cast<chrono::milliseconds>(t2 - t1).count();
    
    // Quick Sort
    for(int i = 0; i < n; i++) copia5[i] = v[i];
    t1 = chrono::high_resolution_clock::now();
    quickSort(copia5, 0, n - 1);
    t2 = chrono::high_resolution_clock::now();
    timp[4] = chrono::duration_cast<chrono::milliseconds>(t2 - t1).count();
    
    long long minim = timp[0];
    int poz = 0;
    for(int i = 1; i < 5; i++) {
        if(timp[i] < minim) {
            minim = timp[i];
            poz = i;
        }
    }
    
    cout << "\nn=" << n << "\n";
    cout << "1. Bubble Sort - " << timp[0] << " ms\n";
    cout << "2. Selection Sort - " << timp[1] << " ms\n";
    cout << "3. Insertion Sort - " << timp[2] << " ms\n";
    cout << "4. Merge Sort - " << timp[3] << " ms\n";
    cout << "5. Quick Sort - " << timp[4] << " ms\n";
    
    return 0;
}