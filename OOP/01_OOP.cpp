#include <iostream>
using namespace std;

class Complex
{
public:
    int real, img;

    Complex()
    {
        real = 0;
        img = 0;
    }

    Complex operator+(Complex b)
    {
        Complex r;
        r.real = real + b.real;
        r.img = img + b.img;
        return r;
    }

    Complex operator-(Complex b)
    {
        Complex r;
        r.real = real - b.real;
        r.img = img - b.img;
        return r;
    }

    // Overloading the * operator to multiply two complex numbers
    Complex operator*(Complex b)
    {
        Complex r;
        r.real = (real * b.real) - (img * b.img);
        r.img = (real * b.img) + (img * b.real);
        return r;
    }

    friend ostream &operator<<(ostream &os, const Complex &z);
    friend istream &operator>>(istream &is, Complex &z);
};

// Overloading the << operator for output
ostream &operator<<(ostream &os, const Complex &z)
{
    os << "(" << z.real << ")" << "+i" << "(" << z.img << ")";
    return os;
}

istream &operator>>(istream &is, Complex &z)
{
    is >> z.real >> z.img;
    return is;
}

int main()
{
    int option;
    char cont;
    Complex z1, z2;

    cout << "Welcome to SuperZ Complex Calculator!";

    while (true)
    {
        cout << "\nOptions Menu Card :"
             << "\n1 - Addition"
             << "\n2 - Multiplication"
             << "\n3 - Subtraction"
             << "\n\nEnter your option :";
        cin >> option;

        switch (option)
        {
        case 1: // Addition
            cout << "\nEnter real and imaginary part of complex number z1 :\n";
            cin >> z1;
            cout << "\nEnter real and imaginary part of complex number z2 :\n";
            cin >> z2;
            cout << "Addition of complex numbers = ";
            cout << z1 + z2;
            break;

        case 2: // Multiplication
            cout << "\nEnter real and imaginary part of complex number z1 :\n";
            cin >> z1;
            cout << "\nEnter real and imaginary part of complex number z2 :\n";
            cin >> z2;
            cout << "Product of complex numbers = ";
            cout << z1 * z2;
            break;

        case 3: // Subtraction
            cout << "\nEnter real and imaginary part of complex number z1 :\n";
            cin >> z1;
            cout << "\nEnter real and imaginary part of complex number z2 :\n";
            cin >> z2;
            cout << "Subtraction of complex numbers = ";
            cout << z1 - z2;
            break;

        default:
            cout << "\nInvalid choice!" << endl;
            break;
        }

        cout << "\nDo you wish to continue? (y/n)\n";
        cin >> cont;

        if (cont == 'n' || cont == 'N')
        {
            break;
        }
    }

    return 0;
}
