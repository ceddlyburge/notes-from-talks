

#include "movie.h"
#include "rental.h"
#include "customer.h"
#include "cuultralight.h"


struct VideoStoreTests
{
  Customer customer;
  
  VideoStoreTests() : customer("Fred") {}
};


TEST(VideoStoreTests,singleNewReleaseStatement)
{
  customer.addRental(new Rental(Movie("The Cell", NEW_RELEASE), 3));
  ASSERT_EQUAL(std::string("Rental Record for Fred\n\tThe Cell\t9.00\nYou owed 9.00\nYou earned 2 frequent renter points\n"), customer.statement());
}

TEST(VideoStoreTests,dualNewReleaseStatement)
{
  customer.addRental(new Rental(Movie("The Cell", NEW_RELEASE), 3));
  customer.addRental(new Rental(Movie("The Tigger Movie", NEW_RELEASE), 3));
  ASSERT_EQUAL(std::string("Rental Record for Fred\n\tThe Cell\t9.00\n\tThe Tigger Movie\t9.00\nYou owed 18.00\nYou earned 4 frequent renter points\n"), customer.statement());
}

TEST(VideoStoreTests,singleChildrensStatement)
{
  customer.addRental(new Rental(Movie("The Tigger Movie", CHILDRENS), 3));
  ASSERT_EQUAL(std::string("Rental Record for Fred\n\tThe Tigger Movie\t1.50\nYou owed 1.50\nYou earned 1 frequent renter points\n"), customer.statement());
}

TEST(VideoStoreTests,testMultipleRegularStatement)
{
  customer.addRental(new Rental(Movie("Plan 9 from Outer Space", REGULAR), 1));
  customer.addRental(new Rental(Movie("8 1/2", REGULAR), 2));
  customer.addRental(new Rental(Movie("Eraserhead", REGULAR), 3));
  ASSERT_EQUAL(std::string("Rental Record for Fred\n\tPlan 9 from Outer Space\t2.00\n\t8 1/2\t2.00\n\tEraserhead\t3.50\nYou owed 7.50\nYou earned 3 frequent renter points\n"), customer.statement());
}



