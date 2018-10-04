
#ifndef RENTAL_H
#define RENTAL_H

#include "movie.h"

class Rental
{
public:
  Rental(const Movie& movie, int daysRented)
    : movie(movie), daysRented(daysRented)
  {}

  const Movie& getMovie() const {
    return movie;
  }

  int getDaysRented() const {
    return daysRented;
  }

private:
  Movie movie;
  int   daysRented;
};

#endif


