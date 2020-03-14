#include <iostream>

struct Date
{
    short day;
    short month;
    short  year;
    bool isCorrect();
};

bool Date::isCorrect()
{
    bool result = false;
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
    {
        if ((day <= 31) && (day > 0))
        {
            result = true;
            break;
        }
    }
    case 4:
    case 6:
    case 9:
    case 11:
    {
        if ((day <= 30) && (day > 0))
        {
            result = true;
            break;
        }
    }
    case 2:
    {
        if (year % 4 != 0)
        {
            if ((day <= 28) && (day > 0))
                result = true;
        }
        else
            if (year % 400 == 0)
            {
                if ((day <= 29) && (day > 0))
                    result = true;
            }
            else
                if ((year % 100 == 0) && (year % 400 != 0))
                {
                    if ((day == 28) && (day > 0))
                        result = true;
                }
                else
                    if ((year % 4 == 0) && (year % 100 != 0))
                        if ((day <= 29) && (day > 0))
                            result = true;
        break;
    }
    default:
        result = false;
    }
    return result;
}

struct Base
{
    char F[56];
    char I[32];
    char O[48];
    char Name[256];
    unsigned int Quantity;
    double Price;
    Date Sale;
};

using namespace std;

int main()
{
    const int N = 2;
    Base Product[N];
    char F[] = "Ivanov";
    for (int i = 0; i < N; i++)
    {
        cout << "\nInput F: ";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin.getline(Product[i].F, 56);

        cout << "\nInput I: ";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin.getline(Product[i].I, 32);

        cout << "\nInput O: ";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin.getline(Product[i].O, 48);

        cout << "\nInput Name:";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin.getline(Product[i].Name, 256);

        do
        {
            cout << "\nInput date of sale: ";
            cin.ignore(std::cin.rdbuf()->in_avail());
            cin >> Product[i].Sale.day >> Product[i].Sale.month >> Product[i].Sale.year;
        } while (!Product[i].Sale.isCorrect());

        cout << "\nInput price:";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin >> Product[i].Price;

        cout << "\nInput quantity:";
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin >> Product[i].Quantity;

        cin.clear();

    }
    cout << endl << endl << endl << endl;

    for (int i = 0; i < N; i++)
    {
        if (!(strcmp(F, Product[i].F)))
        {
            cout << "\nFIO: " << Product[i].F << " " << Product[i].I << " " << Product[i].O;
            cout << "\nDate of sale: " << Product[i].Sale.day << "." << Product[i].Sale.month << "." << Product[i].Sale.year;
            cout << "\nName: " << Product[i].Name;
            cout << "\nPrice: " << Product[i].Price;
            cout << "\nQuantity: " << Product[i].Quantity;
        }
    }
    int max = 0;
    for (int i = 0; i < N; i++)
    {
        if (Product[i].Price > Product[max].Price)
            max = i;
    }
    cout << "\nProdact: " << " " << Product[max].Name << " " << Product[max].Price << " is the most expensive!";
    return 0;
}