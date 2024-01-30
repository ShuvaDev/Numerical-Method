#include<bits/stdc++.h>
using namespace std;

int eqn[100][100];

const int EPS = 0.0001;

void jacobi(int var)
{
    double x[var + 1];
    for(int i = 1; i <= var; i++)
        x[i] = 0;

    while(true)
    {
        double t[var + 1];

        for(int i = 1; i <= var; i++)
        {
            double sum = eqn[i][var + 1];
            double div = eqn[i][i];
            for(int j = 1; j <= var; j++)
            {
                if(i != j)
                {
                    sum = sum - (eqn[i][j] * x[j]);
                }
            }
            t[i] = sum / div;
        }

        double res = 0;
        for(int i = 1; i <= var; i++)
        {
            res += eqn[1][i] * t[i];
        }
        if(fabs(res - eqn[1][var + 1]) < 0.001)
        {
            for(int i = 1; i <= var; i++)
            {
                cout << t[i] << " ";
            }
            cout << endl;
            break;
        }
        for(int i = 1; i <= var; i++)
        {
            x[i] = t[i];
        }
    }
}

int main()
{
    freopen("in.txt", "r", stdin);

    int var;
    cin >> var;

    for(int i = 1; i <= var; i++)
    {
        for(int j = 1; j <= var + 1; j++)
        {
            cin >> eqn[i][j];
        }
    }

    jacobi(var);


}
