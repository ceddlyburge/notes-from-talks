

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <vector>
#include <string>

class Rental;

class Customer
{
public:
       Customer(const std::string& name) : name(name) {}
      ~Customer();
  void addRental(Rental *rental);
  std::string statement();
  std::string getName() const {
    return name;
  }

private:
  std::vector<Rental *> rentals;
  std::string name;
};

#endif
