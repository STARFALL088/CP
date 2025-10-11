class Number {
  int value;

public:

//Arithmatic 
  Number(int v = 0) { value = v; }

  Number operator+(Number &other) { return Number(value + other.value); }

  Number operator-(Number &other) { return Number(value - other.value); }

  Number operator*(Number &other) { return Number(value * other.value); }

  Number operator/(Number &other) { return Number(value / other.value); }

  Number operator%(Number &other) { return Number(value % other.value); }

  //comparison
  bool operator==(Number &other) { return value == other.value; }

  bool operator!=(Number &other) { return value != other.value; }

  bool operator<(Number &other) { return value < other.value; }

  bool operator>(Number &other) { return value > other.value; }

  bool operator<=(Number &other) { return value <= other.value; }

  bool operator>=(Number &other) { return value >= other.value; }


  //assignment 
  Number &operator=(Number &other) {
    if (this != &other) {
      value = other.value;
    }
    return *this;
  }

  Number &operator+=(Number &other) {
    value += other.value;
    return *this;
  }

  Number &operator-=(Number &other) {
    value -= other.value;
    return *this;
  }

  Number &operator*=(Number &other) {
    value *= other.value;
    return *this;
  }

  Number &operator/=(Number &other) {
    value /= other.value;
    return *this;
  }
};
make pdf using these