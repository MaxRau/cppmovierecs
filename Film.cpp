#include "Film.h"
class Film {
  Film::Film(String d, Person* w, Person* d, Person* a, String* c, float r, float e)
  {
    description = d;
    writer = w;
    director = d;
    actor = a;
    character = c;
    rating = r;
    earnings = e;
  }

  Person* getWriter() {return *writer}
  Person* getDirector() {return *director}
  Person* getProducer() {return *producer}
  Person* getActors() {return *actors}
  float getRating() {return rating}
  float getEarnings() {return earnings}
}
