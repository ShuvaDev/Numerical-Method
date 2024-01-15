#include<bits/stdc++.h>
using namespace std;

// Finding roots for quadratic equation using bisection method
int arr[3];

double f(double x) {
    int a = arr[2], b = arr[1], c = arr[0];
    return (a * x * x) + (b * x) + c;
}

double bisection(double x1, double x2) {
    while(true) {
        double x0 = x1 - (f(x1) * ((x2 - x1) / (f(x2) - f(x1))));

        if(fabs(f(x0)) < 0.00001) return x0;

        if(f(x1) * f(x0) > 0) {
            x1 = x0;
        } else {
            x2 = x0;
        }
    }
}

int main() {
    int term;
    cout << "Number of term : ";
    cin >> term;

    if(term > 3) {
        cout << "Invalid input!";
    } else {
        for(int i = 1; i <= term; i++) {
            int degree, coefficient;

            cout << "Term - " << i << endl;
            cout << "Degree : ";
            cin >> degree;
            cout << "Coefficient : ";
            cin >> coefficient;
            arr[degree] = coefficient;
        }
        double x1, x2, xmax, xmin;

        do {
            int a = arr[2], b = arr[1], c = arr[0];

            xmax = sqrt((((b * 1.0) / a) * ((b * 1.0) / a)) - (2 * (c * 1.0) / a));
            xmin = -1 * xmax;

            cout << "Please input between (" << xmin << ", " << xmax << ") interval!\n";
            cout << "x1 : "; cin >> x1;
            cout << "x2 : "; cin >> x2;


            if(f(x1) * f(x2) > 0) {
                cout << "Invalid x1 and x2!\n";
            } else {
                cout << "Approximate root is : " << bisection(x1, x2);
                break;
            }
        } while(true);
    }
}