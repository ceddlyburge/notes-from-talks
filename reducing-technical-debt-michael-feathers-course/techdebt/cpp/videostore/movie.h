
#ifndef MOVIE_H
#define MOVIE_H


#include <string>

#define CHILDRENS      0
#define REGULAR        1
#define NEW_RELEASE    2


class Movie
{
public:

    Movie(const std::string& title, int priceCode)
      : title(title), priceCode(priceCode) 
    {}

    std::string getTitle() const {
      return title;
    }


    int getPriceCode() const {
      return priceCode;
    }

private:
    std::string title;
    int         priceCode;


}; 

#endif

