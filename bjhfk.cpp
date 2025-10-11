#include <iostream>
using namespace std;

class Dist {
protected:
  int m;

public:
  Dist(int v) : m(v) {}
  double get_val() { return m; }
};

class MC : public Dist {
  int cm;

public:
  MC(int m, int cm) : Dist(m + cm / 100), cm(cm % 100) {}

  void display() { cout << m << " m " << cm << " cm\n"; }
  operator double() { return (double)(m) + (double)(cm) / 100; }
};
// Base
class Currency {
protected:
  double rate;

public:
  Currency(double r = 0) : rate(r) {}
};

// Derived class 1
class Dollar : public Currency {
protected:
  double amount;

public:
  Dollar(int amt = 0) : Currency(1.0), amount(amt) {}

  operator double() {
    double usdToBdt = amount * 120.0; // 1 USD = 120 BDT
    return usdToBdt;
  }
  void show() { cout << "Dollar amount: $" << amount << endl; }
};

// Derived class 2
class BDT : public Dollar {
public:
  BDT(int amt = 0) : Dollar(amt) {}
};
int main() {
  int m, cm;
  cin >> m >> cm;

  MC mc1(m, cm);
  mc1.display();
  double val = mc1;
  cout << val << " m\n";

  Dollar d1(10);
  d1.show();
  double valueInBDT = d1;
  cout << "Value in BDT: " << valueInBDT << " Taka" << endl;

  return 0;
}