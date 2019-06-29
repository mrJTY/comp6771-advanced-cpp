#include <string>
#include <tuple>
#include <algorithm>

class Book {
  public:
    Book(
       std::string name,
       std::string author,
       int isbn,
       double price
    ) : name_{name}, author_{author}, isbn_{isbn}, price_{price} {}

    int GetIsbn() const { return isbn_; }
    double GetPrice() const  { return price_; }

  friend bool operator==(const Book &lhs, const Book &rhs){
    return std::tie(lhs.name_, lhs.author_, lhs.isbn_, lhs.price_)
      == std::tie(rhs.name_, rhs.author_, rhs.isbn_, rhs.price_);
  }

  friend bool operator!=(const Book &lhs, const Book &rhs){
    return std::tie(lhs.name_, lhs.author_, lhs.isbn_, lhs.price_)
      != std::tie(rhs.name_, rhs.author_, rhs.isbn_, rhs.price_);
  }

  friend bool operator<(const Book &lhs, const Book &rhs){
    return std::tie(lhs.name_, lhs.author_, lhs.isbn_, lhs.price_)
      != std::tie(rhs.name_, rhs.author_, rhs.isbn_, rhs.price_);
  }

  friend std::ostream& operator<<(std::ostream& os, const Book &b){
    os << b.name_;
    return os;
  }

  private:
    std::string name_;
    std::string author_;
    int isbn_;
    double price_;
};

int main(){
  std::cout << "";

  // Once we overload the < operator, we can use std algorithms
  std::vector<Book> vec;
  vec.push_back({"a", "a", 100, 50});
  vec.push_back({"b", "b", 200, 60});

  std::sort(vec.begin(), vec.end());

  // We can also sort by price
  auto lamb = [] (const Book& lhs, const Book& rhs) {
      return lhs.GetPrice < rhs.GetPrice();
  };

  std::sort(vec.begin(), vec.end(), lamb);
  for(const auto& v: vec){
    std::cout << v << std::endl;
  }

}
