#include <iostream>
#include <vector>
using namespace std;

//转换函数实例
class Fraction 
{
public:
    Fraction(int num, int den = 1):m_numerator(num), m_denominator(den)
    { }
    operator double() const 
    {
        return (double)(m_numerator) / m_denominator;
    }
    // Fraction operator +(const Fraction&) 
    // {
    //     return Fraction(...);
    // }
private:
    int m_numerator;    //分子
    int m_denominator; //分母
};


template <class T>
class shared_ptr
{
public:
    T& operator*() const
    {return *px;}

    T* operator->() const
    {return px;}

    shared_ptr(T* p) : px(p) {}
private:
    T* px;
    long* pn;
};

template <typename T>
class complex {
public:
    complex(T a = 0, T b = 0):real(a),imag(b) {
        cout << "模版类构造函数" << endl;
    }

public:
    T real, imag;
};

void print() {

}

template <typename T, typename... Types>
void print(const T& firstArg, const Types&...args)
{
    cout << firstArg << endl;
    print(args...);
}

class base {
public:
    virtual void draw() {
        cout << "this is base" << endl;
    }
};

class yuan : public base{
    void draw() {
        cout << "this is yuan" << endl;
    } 
};

class sanjiao : public base{
    void draw() {
        cout << "this is sanjiao" << endl;
    } 
};

class tixing : public base{
    void draw() {
        cout << "this is tixing" << endl;
    } 
};

class wubianxing : public base{
    void draw() {
        cout << "this is wubianxing" << endl;
    } 
};

int main() {
    cout << "-------------------------" << endl;
    vector<base*> test; 
    //sanjiao* t = new base; //wrong
    base* a = new sanjiao;
    base* b = new tixing;
    base* c = new wubianxing;
    test.push_back(a);
    test.push_back(b);
    test.push_back(c);
    for (auto& it : test) {
        it->draw();
    }
    return 0;
    cout << "-------------------------" << endl;
    print(7.5, "hello", 42, "world");
    cout << "-------------------------" << endl;
    cout << __cplusplus << endl;
    Fraction f(3, 5);
    double d = 4 + f;
    //调用operator double()将f转为0.6
    cout << d << endl;

    // Fraction d2 = f + 4;
    // //调用 non-explicit ctor 将4转为Fraction,然后调用operator+
    complex<int> c2(2, 6);
    cout << "-------------------------" << endl;
    return 0;
}