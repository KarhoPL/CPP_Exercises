#include <iostream>
#include <iomanip>


# define n 8

using namespace std;

void show(double tab[n][n])
{
    for(int i=0; i<n; i++)
        {
        for(int j=0; j<n; j++)
            {
            cout << setw(10) << setprecision (3)<< tab[i][j];
            }
        cout << endl;
    }
    cout << endl;
}


double srednia(double tab[n])
{
    double suma = 0;
    for(int i=0; i<n; i++)
        {
        suma += tab[i];
        }
    return suma/n;
}


int main()
{

    double A[n][n]; double pomocnicza[n];
    float licznik, mianownik;
//tworzenie tablicy n x n
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            {
            licznik = rand()%21-10;
            mianownik = rand()%10+1;
            A[i][j] = licznik/mianownik;
            }
    }
    show(A);

//sortowanie wyrazów w wierszach
    for(int i=0;i<n;i++)
    {
        for(int k=0; k<n; k++)
        {
            for(int j=1; j<n; j++)
            {
                if (A[i][j-1]>A[i][j]) swap(A[i][j-1], A[i][j]);
            }
        }
    }
    show(A);
// sortowanie wierszy po średniej
        for(int k=0; k<n; k++)
        {
            for(int i=1; i<n; i++)
            {
            if(srednia(A[i-1])>srednia(A[i])) swap (A[i-1], A[i]);
            }
        }
    show(A);
    for(int k=0; k<n; k++)
        {
        cout << "srednia wiersza " << k <<" = " << srednia(A[k]) <<endl;
        }
    return 0;
}
