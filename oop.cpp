#include <iostream>
#include <istream>
#include <ostream>
using namespace std;

class Vector {
public:
  int *arr;
  int n;

  Vector(int size) : n(size) {
    arr = new int[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
  }
  Vector(int val, int size) : n(size) {
    arr = new int[n];
    for (int i = 0; i < n; i++)
      arr[i] = val;
  }
  ~Vector() { delete[] arr; }
  // copy constractor
  Vector(Vector &other) : n(other.n) {
    arr = new int[n];
    for (int i = 0; i < n; i++)
      arr[i] = other.arr[i];
  }
  Vector operator+(Vector &other) {
    Vector Sum(0);
    for (int i = 0; i < n; i++)
      Sum.arr[i] = arr[i] + other.arr[i];
    return Sum;
  }
};

class ResultVector : public Vector {
public:
  int sum;
  ResultVector(Vector &a) : Vector(0, a.n), sum(0) {
    for (int i = 0; i < n; i++) {
      arr[i] = a.arr[i];
      sum += a.arr[i];
    }
  }
  friend ResultVector compareSum(ResultVector a, ResultVector b);
};

ResultVector cmp(ResultVector a, ResultVector b) {

  if (a.sum > b.sum)
    return a;
  else
    return b;
}

class Matrix {
public:
  int **arr;
  int row, col;
  Matrix(int n, int m) : row(n), col(m) {
    arr = new int *[row];
    for (int i = 0; i < row; i++)
      arr[i] = new int[col];
  }
  ~Matrix(){
    for (int i=0; i<row; i++) {
        delete [] arr[i];
    }
    delete[] arr;
  }
};
int main() {
  int n1, n2;
  cin >> n1 >> n2;
  Vector a(n1), b(n2);
  ResultVector p(a), q(b);
  ResultVector ans = cmp(p, q);
  //   Vector sum = a + b;
  for (int i = 0; i < ans.n; i++)
    cout << ans.arr[i] << " ";
  cout << endl;
  ;
}