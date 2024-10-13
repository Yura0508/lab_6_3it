// lab_6_3_it.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

// Функція для генерації масиву
void Create(int* a, const int size, const int Low, const int High) {
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

// Функція для виведення масиву
void Print(const int* a, const int size) {
    for (int i = 0; i < size; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

// Функція для мінімального значення
int Min(int* a, const int size)
{
    int min; 
    int imin = -1; 
    for (int i = 0; i < size; i++)
        if (a[i] % 2 != 0)
        {
            min = a[i]; 
            imin = i;  
            break;
        }
    if (imin == -1)
    {
        cerr << "there are no elements that satisfy the condition" << endl;
        return 0; 
    } 
    
    for (int i = imin + 1; i < size; i++)
        if (a[i] < min && a[i] % 2 != 0)
            min = a[i];
    return min;
}



int* SeparateOdds(int* a, const int size, int& newSize) {
    newSize = 0; 
    for (int i = 0; i < size; i++) {
        if (a[i] % 2 != 0) {
            newSize++;
        }
    }
    int* newArray = new int[newSize];
    int index = 0;

    for (int i = 0; i < size; i++) {
        if (a[i] % 2 != 0) {
            newArray[index] = a[i];
            index++;
        }
    }
    return newArray; 
}
int Min2(int* newArray, const int size) {
    int min;
    bool found = false; 

    for (int i = 0; i < size; i++) {
        if (newArray[i] % 2 != 0) {
            if (!found || newArray[i] < min) {
                min = newArray[i];
                found = true; // Знайдено хоча б одне непарне число
            }
        }
    }

    if (!found) {
        cerr << "there are no odd elements in the newArray" << endl;
        return 0;
    }

    return min;
}


int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    const int size = 10;
    int a[size];
    const int Low = -10;
    const int High = 20;

    Create(a, size, Low, High);
    cout << "massif a:" << endl;
    Print(a, size);

    cout << "min = " << Min(a, size) << endl;

    int newSize; 
    int* separatedArray = SeparateOdds(a, size, newSize);
    cout << "now massif:" << endl;
    Print(separatedArray, newSize);
    cout << "min = " << Min2(separatedArray, newSize) << endl;

    delete[] separatedArray;
    cin.get();
    return 0;
}