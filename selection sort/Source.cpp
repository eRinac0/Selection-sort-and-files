#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;
const  int M = 20, N = 20;
void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    // Проходим по всем элементам массива
    for (i = 0; i < n-1; i++) {
        // Находим минимальный элемент в оставшейся части массива
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Меняем местами текущий элемент с найденным минимальным
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}


void shiftArrayRight(int a[], int n) {
    int last = a[n - 1]; 
        for (int i = n - 1; i > 0; i--) {
            a[i] = a[i - 1]; 
        }
    a[0] = last; 
    cout << endl;
}


void get_mas1(int arr[], int& n, string filename) {
    ifstream file(filename);
    file >> n;
    if (file.is_open()) {
        for (int i = 0; i < n; i++) {
            file >> arr[i];
        }
        file.close();
    }
    else {
        cout << "Unable to open file" << endl;
    }
}

void show_mas1(int arr[], int n, string filename) {
    ofstream out(filename);
    for (int i = 0; i < n; i++) {
        out << arr[i] << " ";
    }
    cout << endl;
}
void show_mas3(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}
void get_mas2(int matrix[M][N], int& n, int& m, string filename) {
    ifstream file(filename);
    file >> m;
    file >> n;
    if (file.is_open()) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
            {
                file >> matrix[i][j];
            }

        }
        file.close();
    }
    else {
        cout << "Unable to open file" << endl;
    }
}


void get_mas3(int arr[], int& n, string filename) {
    ifstream file(filename);
    file >> n;
    if (file.is_open()) {
        for (int i = 0; i < n; i++) {
            file >> arr[i];
        }
        file.close();
    }
    else {
        cout << "Unable to open file" << endl;
    }
}

void task1() {
    int n = 0;
    int* a = new int[n];
    get_mas1(a, n, "array_in_n.txt"); // передаем поток ifstream вместо имени файла
    shiftArrayRight(a, n);
    show_mas1(a, n, "array_out_n.txt"); // передаем поток ofstream вместо имени файла
    delete[] a;
}

void task2() {

    int matrix[M][N]{};
    int s = 0, cols = 0, rows = 0, j=0;

    get_mas2(matrix, cols, rows, "matr_in_n.txt"); // передаем поток ifstream вместо имени файла
    ofstream out("matr_in_n.txt", ios::app);

    for (int i = 0; i < rows; i++) {
        j = 1;
        while ((matrix[i][j - 1] < matrix[i][j]) && (j < cols)) {
            j++;
        }
        if (j == cols) {
            out << matrix[i][0] << endl;
        }
        else {
            j = 1;
            while ((matrix[i][j - 1] > matrix[i][j]) && (j < cols)) {
                j++;
            }
            if (j == cols) {
                out << matrix[i][cols - 1] << endl;
            }
            else {
                out << "0" << endl;
            }
        }
    }
    out.close();
}

void task3() {

    int n = 0;
    int* arr = new int[n];
    get_mas3(arr, n, "3.txt");
    cout << "Масив до сортування:" << endl;
    show_mas3(arr, n);
    selectionSort(arr, n);
    cout << "Масив після сортування:" << endl;
    show_mas3(arr, n);


}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int menu;
    do
    {
        cout << "Task number(0 for exit):";
        cin >> menu;
        switch (menu)
        { // перемикання між завданнями
        case 1:
            task1();
            break; // Завдання 1
        case 2:
            task2();
            break; // Завдання 2
        case 3:
            task3();
            break; // Завдання 3

        }
    } while (menu);



    system("pause");
    return 0;
}
