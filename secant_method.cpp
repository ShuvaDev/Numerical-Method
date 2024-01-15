#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int arr[100];
const double EPS = 0.00001;

double f(double x, int term) {
    double result = 0;
    for(int i = term - 1; i >= 0; i--) {
        result += arr[i] * pow(x, i);
    }
    return result;
}

double fprime(double x, int term) {
    double result = 0;
    for(int i = term - 1; i > 0; i--) {
        result += arr[i] * i * pow(x, i - 1);
    }
    return result;
}

double find_root(double x1, double x2, int term) {
    double x3 = (f(x2, term)*x1 - f(x1, term)*x2) / (f(x2, term) - f(x1, term));
    while(fabs(f(x3, term)) > EPS)  {
        x1 = x2;
        x2 = x3;
        x3 = (f(x2, term)*x1 - f(x1, term)*x2) / (f(x2, term) - f(x1, term));
    }
    return x3;
}

int main() {
    int term;
    cout << "No. of term : ";
    cin >> term;

    for(int i = 1; i <= term; i++) {
        int degree, term;
        cin >> degree >> term;
        arr[degree] = term;
    }

    double x1, x2;
    cout << "Enter the guess value : ";
    cin >> x1 >> x2;

    cout << "Root : " << find_root(x1, x2, term);

    return 0;
}