
#include "customer.h"
#include "rental.h"


void Customer::addRental(Rental *rental) 
{
  rentals.push_back(rental);
}

Customer::~Customer() 
{
  for(std::vector<Rental *>::iterator it = rentals.begin(); it != rentals.end(); ++it)
    delete *it;
}

std::string Customer::statement() 
{
  double         totalAmount             = 0.0;
  int            frequentRenterPoints    = 0;
  std::string    result                  = "Rental Record for " + getName() + "\n";
  char           buffer [120]            = { 0 };

  for(std::vector<Rental *>::iterator it = rentals.begin(); it != rentals.end(); ++it) {
    double thisAmount = 0;
    Rental& each = **it;

    switch(each.getMovie().getPriceCode()) {
      case REGULAR:
        thisAmount += 2;
        if (each.getDaysRented() > 2)
          thisAmount += (each.getDaysRented() - 2) * 1.5;
        break;
     
      case NEW_RELEASE:
        thisAmount += each.getDaysRented() * 3;
        break;
   
      case CHILDRENS:
        thisAmount += 1.5;
        if (each.getDaysRented() > 3)
          thisAmount += (each.getDaysRented() - 3) * 1.5;
        break;
    }

    frequentRenterPoints++;

    if (each.getMovie().getPriceCode() == NEW_RELEASE
          && each.getDaysRented() > 1)
      frequentRenterPoints++;

    sprintf(buffer,"%3.2f", thisAmount);
    result += "\t" + each.getMovie().getTitle() + "\t" + std::string(buffer) + "\n";
 
    totalAmount += thisAmount;
  }

  sprintf(buffer,"%3.2f", totalAmount);
  result += "You owed " + std::string(buffer) + "\n";
    
  sprintf(buffer, "%d", frequentRenterPoints);
  result += "You earned " + std::string(buffer) + " frequent renter points\n";
  
  return result;
}


