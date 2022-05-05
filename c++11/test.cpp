#include <iostream>
using namespace std;


//----------------------------------------
namespace lz2{
    void print() {}

    template<typename T, typename ... Types>
    void print(const T& firstArg, const Types& ... args) {
        cout << firstArg << ", " << sizeof...(args) << endl;
        print(args...);
    }

    // template<typename ... Types>
    // void print(const Types& ... args) {
    //     cout << firstArg << ", " << sizeof...(args) << endl;
    //     print(args...);
    // }


} //namespace lz2
//----------------------------------------
#include <cstring>
//clang不支持初始化列表

// namespace lz4{
//     void test() {
//         vector<string> str{"sh", "hi", "ta", "ui", "na"};
//         for (auto& it : str) {
//             cout << it << ", ";
//         }
//     }
// }
//----------------------------------------
namespace lz7{
    struct Complex{
        int real,imag;
        //explicit 加上此关键字不会自动出现转换，加上Complex c2 = c1 + 5;编译出错
        Complex(int re, int im = 0) : real(re), imag(im) {

        }
        Complex operator+(const Complex& x) {
            return Complex(real + x.real, imag + x.imag);
        }
    };

    void test() {
        Complex c1(12, 5);
        Complex c2 = c1 + 5;
    }
} //namespace lz7
//----------------------------------------
namespace lz10 {

}


int main() {
    cout << __cplusplus << endl;
    //lz2::print(12,"hello","test", 89);
    //lz7::test();
    return 0;
}