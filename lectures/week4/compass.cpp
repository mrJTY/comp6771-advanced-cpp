#include <ostream>
#include <iostream>

// Point.h:
class Point {
  public:
    Point(int x, int y) : x_{x}, y_{y} {};

    Point& operator+=(const Point& p);
    Point& operator-=(const Point& p);
    Point& operator*=(const Point& p);
    Point& operator/=(const Point& p);
    Point& operator*=(const int& i);
    const int& x() const { return this->x_; };
    const int& y() const { return this->y_; };

  private:
    int x_;
    int y_;
};

// Point.cpp:
Point& Point::operator+=(const Point& p) {
  this->x_ += p.x_;
  this->y_ += p.y_;
  return *this; // this is a pointer. Return the actual object with *this
}

Point& Point::operator-=(const Point& p) {
  this->x_ -= p.x_;
  this->y_ -= p.y_;
  return *this;
}
//Point& Point::operator-=(const Point& p) { /* Should we do this one? */ }
//Point& Point::operator*=(const Point& p) { /* Should we do this one? */ }
//Point& Point::operator/=(const Point& p) { /* Should we do this one? */ }
//Point& Point::operator*=(const int& p) { /* Should we do this one? */ }

int main(){
  Point p1 {1,2};
  Point p2 {3,4};

  p1 += p2;
  std::cout << p1.x() << " " << p1.y() << std::endl;

}
