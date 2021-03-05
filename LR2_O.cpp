#include <iostream>
#include <fstream>
#include "Vector.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    ifstream fin("input.txt");
    if (!fin) {
        cerr << "Error!\n";
        return 1;
    }
    ofstream fou("output.txt");
    int n, m;

    fin >> n; //размерность первого вектора
    int* Data = new int[n];
    for (int i = 0; i < n; ++i) {
        fin >> Data[i];
    }

    fin >> m; //размерность второго вектора
    int* Data1 = new int[m];
    for (int i = 0; i < m; ++i) {
        fin >> Data1[i];
    }

    Vector a(n, Data); //Вызывается конструктор с 2 аргументами
    Vector b(a); //Вызывается конструктор копирования
    cout << "A: " << a << "B: " << b; //Вызывается перегруженный оператор вставки в потоки cout
    fou << "A: " << a << "B: " << b; //Вызывается перегруженный оператор вывода в файл

    Vector c = move(b); //Вызывается перегруженный оператор присвоения с перемещением
    cout << "C: " << c;
    fou << "C: " << c;

    cout << "После побитового ИЛИ: " << (Data1 ^ c) << endl;
    fou << "После побитового ИЛИ: " << (Data1 ^ c) << endl;
}