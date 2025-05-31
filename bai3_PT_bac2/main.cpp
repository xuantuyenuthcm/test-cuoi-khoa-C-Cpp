#include <iostream>
#include <cmath>
using namespace std;

class QuadraticEquation {
private:
    double a, b, c;

public:
    // Constructor
    QuadraticEquation(double a_, double b_, double c_) {
        a = a_;
        b = b_;
        c = c_;
    }

    void solve() {
        if (a == 0) {
            if (b == 0) {
                if (c == 0)
                    cout << "Phuong trinh vo so nghiem." << endl;
                else
                    cout << "Phuong trinh vo nghiem." << endl;
            }
            else {
                double x = -c / b;
                cout << "Phuong trinh bac nhat, nghiem: x = " << x << endl;
            }
            return;
        }

        double delta = b * b - 4 * a * c;

        if (delta > 0) {
            double x1 = (-b + sqrt(delta)) / (2 * a);
            double x2 = (-b - sqrt(delta)) / (2 * a);
            cout << "Phuong trinh co 2 nghiem phan biet:\n";
            cout << "x1 = " << x1 << ", x2 = " << x2 << endl;
        }
        else if (delta == 0) {
            double x = -b / (2 * a);
            cout << "Phuong trinh co nghiem kep: x = " << x << endl;
        }
        else {
            cout << "Phuong trinh vo nghiem (delta < 0)." << endl;
        }
    }
};

// Ví dụ sử dụng
int main() {
    double a, b, c;
    cout << "Nhap he so a, b, c: ";
    cin >> a >> b >> c;

    QuadraticEquation eq(a, b, c);
    eq.solve();

    return 0;
}
