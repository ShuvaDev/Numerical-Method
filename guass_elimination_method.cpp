#include<bits/stdc++.h>
using namespace std;

double eqn[10][11];
double result[10][2];

void guass_elimination(int st, int term) {
    for(int i = st + 1; i <= term; i++) {
        double m = eqn[st][st] / eqn[i][st];
        for(int j = st; j <= term + 1; j++) {
            eqn[i][j] = (eqn[i][j] * m);
            eqn[i][j] = eqn[st][j] - eqn[i][j];
        }
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    int term; cin >> term;

    for(int i = 1; i <= term; i++) {
        for(int j = 1; j <= term + 1; j++) {
            cin >> eqn[i][j];
        }
    }

    for(int i = 1; i < term; i++) {
        guass_elimination(i, term);
    }

    for(int i = 1; i <= term; i++) {
        for(int j = 1; j <= term + 1; j++) {
            cout << eqn[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    for(int i = term; i >= 1; i--) {
        double sum = eqn[i][term + 1];
        for(int j = i + 1; j <= term; j++) {
            sum -= eqn[i][j] * result[j][1];
        }
        result[i][1] = sum / eqn[i][i];
    }

    for(int i = 1; i <= term; i++) {
        cout << "x" << i << " = " << result[i][1] << endl;
    }

    return 0;
}
