// #include <bits/stdc++.h>
// #define F first
// #define S second
// #define PB push_back
// #define MP make_pair
// #define REP(i, a, b) for (int = a; i <= b; i++)
//
// using namespace std;
//
// typedef vector<int> vi;
// typedef vector<pair<int, int>> vp;
// typedef tuple<int, int, int> ti;
//
// int m2_binary_search(const vi& array, const int right, const int target) {
//     int start = 0;
//     int end = right - 1;
//
//     for (int middle = end / 2; middle >= 1; middle /= 2) {
//         while (start + middle < right && array[start + middle] <= target) {
//             start += middle;
//         }
//     }
//
//     if (array[start] == target) {
//         return start;
//     }
//
//     return -1;
// }
//
//
// int m1_binary_search(const vi& array, const int left, const int right, const int target) {
//     int start = left, end = right;
//
//     while (start < end) {
//         int middle = (start + end) / 2;
//
//         if (array[middle] == target) {
//             return middle;
//         }
//
//         if (array[middle] > target) {
//             end = middle - 1;
//         } else if (array[middle] < target) {
//             start = middle + 1;
//         }
//     }
//
//     return -1;
// }
//
// struct Pair {
//     int x, y;
//
//     bool operator<(const Pair & p) const {
//         if (x != p.x) {
//             return x < p.x;
//         }
//
//         return y < p.y;
//     }
// };
//
// bool comp(string a, string b) {
//     if (a.size() != b.size()) {
//         return a.size() < b.size();
//     }
//
//     return a < b;
// }
//
// vector<int> sortAnArray() {
//     vi v;
//
//     v.push_back(2);
//     v.push_back(1);
//     v.push_back(0);
//
//     sort(v.begin(), v.end());
//
//     return v;
// }
//
//
// vector<int> bubbleSort() {
//     vector<int> vi;
//     const int SIZE = 5;
//
//     for (int i = 0; i < SIZE; i++) {
//         int num; cout << "Insert a number:  "; cin >> num;;
//         vi.push_back(num);
//     }
//
//     for (int i = 0; i < vi.size(); i++) {
//         for (int j = 0; j < vi.size() - 1; j++) {
//             if (vi[j] > vi[j + 1]) {
//                 swap(vi[j], vi[j + 1]);
//             }
//         }
//     }
//
//     return vi;
// }
// // int main() {
//     // freopen("input.txt", "r", stdin);
//     // freopen("output.txt", "w", stdout);
//     // double a, b;
//     //
//     // // Read the input values into the variables a and b
//     // scanf("%lf %lf", &a, &b);
//     //
//     // // Compare the values with a precision threshold and print the results
//     // if (abs(a - b) < 1e-9) {
//     //     printf("%.9f is equal to %.9f\n", a, b);
//     // } else {
//     //     printf("%.9f is not equal to %.9f\n", a, b);
//     // }
//
//     vi my_vector = sortAnArray();
//     string a = "hatti";
//     a += a;
//     string c = a.substr(3, 4);
//     c[5] = 'v';
//     cout << a << "\n" << c << "\n";
//
//
//     int target = 3;
//     int size = my_vector.size();
//
//     vi v(10, 5);
//
//
//
//     cout << v[0];
//
//     return 0;
// }
//
// int useMacros() {
//     vp v;
//     int x1 = 1;
//     int x2 = 2;
//     int y1 = 3;
//     int y2 = 5;
//
//     int counter = 0;
//
//     v.PB(MP(y1, x1));
//     v.PB(MP(y2, x2));
//
//     int d = v[0].F + v[0].S;
//
//
//     return 0;
// }
//
//
