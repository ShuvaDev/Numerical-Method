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

double find_root(double x, int term) {
    while(fabs(f(x, term)) > EPS)  {
        x = x - (f(x, term) / fprime(x, term));
    }
    return x;
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

    double x;
    cout << "Enter the guess value : ";
    cin >> x;

    cout << "Root : " << find_root(x, term);


    
    
    
    return 0;
}