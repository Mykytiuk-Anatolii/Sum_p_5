#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

template<typename ForwardIterator, typename OutputIterator>
void duplicateAndReverse(ForwardIterator first, ForwardIterator last, OutputIterator result) {
    advance(first, distance(first, last) / 2);
    reverse_copy(first, last, result);
    copy(first, last, result);
}

int main() {
    list<int> L1;
    list<int> L2;

    int count;
    cout << "Enter the count of elements for L1 (even count): ";
    cin >> count;

    cout << "Enter elements for L1: ";
    for (int i = 0; i < count; ++i) {
        int num;
        cin >> num;
        L1.push_back(num);
    }

    cout << "Enter the count of elements for L2 (even count): ";
    cin >> count;

    cout << "Enter elements for L2: ";
    for (int i = 0; i < count; ++i) {
        int num;
        cin >> num;
        L2.push_back(num);
    }

    list<int> result1;
    duplicateAndReverse(L1.begin(), L1.end(), inserter(result1, result1.end()));

    list<int> result2;
    duplicateAndReverse(L2.rbegin(), L2.rend(), inserter(result2, result2.begin()));

    cout << "Result 1: ";
    for (const auto& num : result1) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Result 2: ";
    for (const auto& num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}