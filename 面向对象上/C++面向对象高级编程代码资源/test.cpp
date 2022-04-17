#include <iostream>
using namespace std;

//static用法
class Account {
public:
    static double m_rate;
    static void set_rate(const double rate) {m_rate = rate;}
};
double Account::m_rate = 8.0;


// //类模版
// template <typename T>
// class complex {
// public:
//     complex(T a = 0, T b = 0):real(a),imag(b) {}

// public:
//     T real, imag;
// };

// complex& operator << (ostream& os, complex& a) 
// {
//     return os << '(' << a.real << ',' << a.imag << ')' << endl;
// }

int main() {
    Account::set_rate(10.0);
    cout << Account::m_rate << endl;
    Account a;
    a.set_rate(7.0);
    cout << a.m_rate << endl;

    cout << "------------------------" << endl;
    // complex<double> ab(3, 4);
    // cout << ab;
    return 0;
}

