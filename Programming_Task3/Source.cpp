#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

const int n = 4;

struct SPunkt
{
    int x, y;
};

void punkty(SPunkt X[][n], int d, int g, char tab, int& dz_a, int& dz_b)
{
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            X[i][j].x = d + rand() % (g + 1 - d);
            X[i][j].y = d + rand() % (g + 1 - d);
        }
    }
    cout << "Drukuje tablice " << tab << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << fixed << setw(6) << "( " << X[i][j].x << " , " << X[i][j].y << " )" << setw(6);
        cout << endl;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= i - 1; j++)
            if (X[i][j].x > 0 && X[i][j].y > 0)
            {
                dz_a++;
            }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j <= n - 1; j++)
            if (X[i][j].x < 0 && X[i][j].y < 0)
            {
                dz_b++;
            }
    }
}

int main()
{
    SPunkt A[n][n], B[n][n];
    int dzial_a = 0, dzial_b = 0;
    cout << endl;
    punkty(A, -15, 15, 'A', dzial_a, dzial_b);
    punkty(B, -20, 20, 'B', dzial_a, dzial_b);
    cout << endl;
    cout << "Laczna ilosc punktow dzialania 'a' w obu tablicach = " << dzial_a << endl;
    cout << "Laczna ilosc punktow dzialania 'b' w obu tablicach = " << dzial_b << endl;
    cout << endl;



    system("PAUSE");
    return 0;
}
