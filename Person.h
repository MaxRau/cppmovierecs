<<<<<<< HEAD
class Person {
  public:
    Person(Film contrubutedTo, String bio, Gender gender, int activeSince);
    
    Film* getContributedTo();
    String getBio();
    Gender getGender();
    int getActiveSince();
=======


#ifndef FILM_H
#define FILM_H
#include "Film.h"
#endif 
#ifndef PERSON_H
#define	PERSON_H
#include <string>
#include <vector>
class Film;

class Person{

public:
Person();
Person(std::string name,std::vector<Film*>, int activeSince);
void setName(std::string);
std::string getName();
std::vector<Film*> getFilms();
void addFilm(Film *film);
int getActiveSince();
void setActiveSince(int y);
int checkVector(std::vector<Person*> a);
>>>>>>> 144ce250bbfb3564db61e218ea4ab8c48a49c2c1

  private:
    Film contributedTo[];
    String bio;

    enum Gender {Male,Female};
    Gender gender;

    int activeSince;
}
