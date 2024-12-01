#include <iostream>
using namespace std;
class OBST
{
public:
    void input(double *w, double *c, double *r, int n, int m, double *p, double *k)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Enter K[" << (i + 1) << "] : " << endl;
            cin >> (k[i]);
            cout << "Enter P[" << (i + 1) << "] : " << endl;
            cin >> (p[i]);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                *(c + i * n + j) = -1;
            }
        }
    }
    void calculate(double *w, double *c, double *r, int n, int m, double *p, double *k)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i; j++)
            {
                if (j == j + i)
                {
                    *(r + j * n + (j + i)) = 0;
                    *(w + j * n + (j + i)) = p[j + i];
                    *(c + j * n + (j + i)) = 0;
                }
                else
                {
                    *(w + j * n + (j + i)) = *(w + (j)*n +
                                               (j + i - 1)) +
                                             p[j + i];
                    int flag = 0, min, kk;
                    for (int k = j + 1; k <= j + i; k++)
                    {
                        if (*(c + j * n + (k - 1)) == -1)
                        {
                            if (*(c + j * n + (k - 1 - 1)) != -1 && *(c + k * n + (j + i)) != -1)
                                *(c + j * n + (k - 1)) =
                                    *(c + j * n + (k - 1 - 1)) + *(c + k * n + (j + i));
                        }
                        if (*(c + k * n + (j + i)) == -1)
                        {
                            if (*(c + k * n + (j + i - 1)) != -1 && *(c + j + 1 * n + (j + 1)) != -1)
                                *(c + k * n + (j + i)) =
                                    *(c + k * n + (j + i - 1)) + *(c + (j + i) * n + (j + i));
                        }
                        int cost = *(c + j * n + (k - 1)) +
                                   *(c + k * n + (j + i));
                        if (flag == 0)
                        {
                            flag = 1;
                            min = cost;
                            kk = k;
                        }
                        if (min > cost)
                        {
                            min = cost;
                            kk = k;
                        }
                    }
                    *(c + j * n + (j + i)) = min + *(w +
                                                     j * n + (j + i));
                    *(r + j * n + (j + i)) = kk;
                }
            }
        }
    }
    void displayCalc(double *w, double *c, double *r, int n, int m, double *p, double *k)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i; j++)
            {
                cout << "W" << j << j + i << ":" << *(w + j * n + (j + i)) << ",C" << j << j + i << ":" << *(c + j * n + (j + i)) << ",R" << j << j + i << ":" << *(r + j * n + (j + i)) << " | ";
            }
            cout << endl;
        }
    }
};
int main()
{
    OBST obst;
    int n;
    cout << "Enter the no. of columns for the OBST table : " << endl;
    cin >> n;
    int m = n;
    double *r = new double[m * n];
    double *c = new double[m * n];
    double *w = new double[m * n];
    double *k = new double[n];
    double *p = new double[n];
    obst.input(w, c, r, n, m, p, k);
    obst.calculate(w, c, r, n, m, p, k);
    obst.displayCalc(w, c, r, n, m, p, k);
    return 0;
}
