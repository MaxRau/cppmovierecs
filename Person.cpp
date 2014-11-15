#include "Person.h"
class Person {
  Person::Person(Film c, String b, Gender g, int a)
  {
    contributedTo = c;
    bio = b;
    gender = g;
    activeSince = a;
  }

  Film* getContributedTo() {return *contributedTo}
  String getBio() {return bio}
  Gender getGender() {return gender}
  int getActiveSince() {return activeSince}
}
