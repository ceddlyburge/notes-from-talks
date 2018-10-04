using System;
using System.Collections.Generic;
using System.Text;

namespace VideoCs
{
    public class Rental
    {
        public Rental(Movie movie, int daysRented)
        {
            this.daysRented = daysRented;
            this.movie = movie;
        }

        public int DaysRented 
        {
            get { return daysRented; }
        }

        public Movie Movie
        {
            get { return movie; }
        }

        private Movie movie;
        private int daysRented;
    }
}
