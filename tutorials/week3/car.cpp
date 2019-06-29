#include "tutorials/week3/car.h"

// TODO(tutorial): fill me in


class Car {
  public:
  Car(std::string man, int seats) :
    manufacturer_{man}, num_seats_{seats} {
      ++object_count_;
    }

  ~Car() {
    --object_count_;
  }

  // Copy constructor
  Car(const Car& c) : Car(c.manufacturer_, c.seats) {}

  // Move constructor. Take in an rvalue reference
  Car(const Car&& c) : Car(c.manufacturer_, c.seats) {}

  // Copy assignment
  operator=(const Car& c) {
    manufacturer_ = c.manufacturer_;
    num_seats_ = c.num_seats;
  }

  // Move assignment
  // object_count shouldn't change when we use this
  operator=(const Car& c) {
    manufacturer_ = std::move(c.manufacturer_);
    num_seats_ = std::move(c.num_seats);
  }

  static int getObjectCount() {
    return object_count_;
  }

  private:
    std::string manufacturer_;
    int num_seats_;
};


int main(){
  Car c{4}; // constructor
  Car d{c}; // Copy constructor
  Car e = c; // Copy constructor
  Car f;
  f = c; // Copy assignment

  f = std::move(c); // Move assignment
}
