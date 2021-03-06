#include "Vector.h"

Vector::Vector()
{
    n = 0;
    data = nullptr;
}

Vector::Vector(int n, int* data)
{
    this->n = n;
    this->data = new int[n];
    for (int i = 0; i < n; ++i) {
        this->data[i] = data[i];
    }
}

Vector::Vector(const Vector& other) //Êîíñòðóêòîð êîïèðîâàíèÿ
{
    this->n = other.n;
    delete[] this->data;
    this->data = new int[other.n];
    for (int i = 0; i < other.n; ++i) {
        this->data[i] = other.data[i];
    }
}

Vector::Vector(Vector&& other)  //Êîíñòðóêòîð ïåðåìåùåíèÿ
{
    this->n = other.n;
    this->data = other.data;
    other.data = nullptr;
    other.n = 0;
}

Vector& Vector::operator=(const Vector& other)  //Ïðèñâàèâàíèå ñ êîïèðîâàíèåì
{
    if (&other == this) return *this;
    if (other.n != this->n) {
        if (this->data != nullptr) {
            delete[] this->data;
        }
        this->n = other.n;
    }
    this->n = other.n;
    this->data = new int[n];
    for (int i = 0; i < n; i++)
    {
        this->data[i] = other.data[i];
    }
    return *this;
}

Vector& Vector::operator=(Vector&& other) //Ïðèñâàèâàíèå ñ ïåðåìåùåíèåì
{
    if (&other == this) return *this;
    delete[] this->data;
    this->n = other.n;
    this->data = other.data;
    other.data = nullptr;
    other.n = 0;
    return *this;
}

int& Vector::operator[](int index)
{
    return data[index];
}

int Vector::getN()
{
    return n;
}

int* Vector::getData()
{
    return data;
}

void Vector::setVector(int n, int* data)
{
    if (this->data != nullptr) delete[] this->data;
    this->n = n;
    this->data = data;
}

Vector::~Vector()
{
    if (data != nullptr) {
        delete[] data;
    }
}

ostream& operator<<(ostream& out, Vector& vec)
{
    int n = vec.getN();
    int* data = vec.getData();
    for (int i = 0; i < n; i++)
    {
        out << data[i] << " ";
    }
    out << endl << endl;
    return out;
}

istream& operator>>(istream& in, Vector& vec)
{
    delete[] vec.data;
    in >> vec.n;
    vec.data = new int[vec.n];
    for (int i = 0; i < vec.n; i++) {
        in >> vec.data[i];
    }
    return in;
}

Vector& operator^(int* array, Vector& vec)
{
    int n = vec.getN();
    int* V_data = new int[n];
    for (int j = 0; j < n; j++)
    {
        V_data[j] = (array[j] ^ vec[j]);
    }
    Vector *V = new Vector(n, V_data);
    delete[] V_data;
    return *V;
}
