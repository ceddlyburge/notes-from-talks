using System;
using System.Collections.Generic;
using System.Text;

namespace VideoCs
{
    class Customer
    {
        public Customer(string name)
        {
            this.name = name;
        }

        public void AddRental(Rental rental)
        {
            rentals.Add(rental);
        }

        public string Name 
        {
            get { return name; }
        }

        public string Statement()
        {
            double totalAmount = 0;
            int frequentRenterPoints = 0;

            string result = "Rental Record for " + Name + "\n";

            foreach (Rental each in rentals)
            {
                double thisAmount = 0;
         
                // determines the amount for each line
                switch (each.Movie.PriceCode)
                {
                    case Movie.REGULAR:
                        thisAmount += 2;
                        if (each.DaysRented > 2)
                            thisAmount += (each.DaysRented - 2) * 1.5;
                        break;

                    case Movie.NEW_RELEASE:
                        thisAmount += each.DaysRented * 3;
                        break;

                    case Movie.CHILDRENS:
                        thisAmount += 1.5;
                        if (each.DaysRented > 3)
                            thisAmount += (each.DaysRented - 3) * 1.5;
                        break;
                }

                frequentRenterPoints++;
                if (each.Movie.PriceCode == Movie.NEW_RELEASE
                        && each.DaysRented > 1)
                    frequentRenterPoints++;

                result += "\t" + each.Movie.Title + "\t"
                                    + thisAmount + "\n";
                totalAmount += thisAmount;
            }

            result += "You owed " + totalAmount + "\n";
            result += "You earned " + frequentRenterPoints + " frequent renter points\n";

            return result;

        }

        private string name;
        private List<Rental> rentals = new List<Rental>();
    }
}
