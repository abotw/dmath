#include <iostream>
#include <set>
using namespace std;

int main() {
    int arr[] = {8, 4, 2, 9};
    int arrSize = sizeof(arr) / sizeof(int);
    set<int> setA, setB(arr, arr+arrSize);
    set<int>::iterator iter;    // set iterator

    cout << setB.size();        // output: 4

    iter = setB.begin();        // iter -> 2 (迭代器指向最小的元素2)

    iter++;                     // 把 iter 移到下一个元素
    cout << *iter;              // output: 4

    iter = setB.end();          // 指向最后一个元素的后面
    iter--;
    cout << *iter;              // output: 9

    setA = setB;                // 使用赋值运算符

    return 0;
}