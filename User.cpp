#include <cstdlib>
#include <iostream>
#include <string>
#include "Film.h"
#include "Person.h"
using namespace std;


class User{
public:
User( std::string const &uName, std::string const &pw, Film* films, Person* people);
User( std::string const &uName, std::string const &pw);
User();
std::string getUserName();
void setUserName(std::string uName);
std::string getPassword();
void setPassword(std::string pw);
std::vector<Film*> getLikedFilms();
std::vector<Person*> getLikedPeople();
std::vector<std::string> getLikedGenres();
void addLikedFilm(Film*);
int scoreFilm(Film*);

private:
std::string username;
std::string password;//Plaintext...
std::vector<Film*> filmArray;
std::vector<std::string> genreArray;
std::vector<Person*> personArray;//Needs to be populated from the liked films array
int nLikedGenres;
int nLikedFilms;
int nLikedPeople;
};

User::User() : username(""), password(""){
    cout << "DEFAULT USER CONFIGURATION";
};
//Can the constructor check to make sure an object with these same values doesnt already exit?
User::User( std::string const &uName, std::string const &pw) : username(uName), password(pw){
cout << "Username: " << username << "\nPassword: " << password;
filmArray.clear();
personArray.clear();
genreArray.clear();
};
User::User( std::string const &uName,  std::string const &pw, Film* films, Person* people) : username(uName), password(pw), likedFilms(films), likedPeople(people){
};
string User::getUserName(void){
    return username;
};
string User::getPassword(void){
    return password;
};
Film* User::getLikedFilms(void){
    return likedFilms;
};
Person* User::getLikedPeople(void){
    return likedPeople;
};
void User::addLikedPerson(Person p){
    likedPeople[nLikedPeople++];
};
vector<std::string> User::getLikedGenres(void){
return genreArray;
};
//Uses vectors. Automatically adds all important variables to liked arrays for a person
void User::addLikedFilm(Film* f){
//add films
filmArray[nLikedFilms++]=f;
//add people
personArray[nLikedPeople++]=f->actor;
personArray[nLikedPeople++]=f->director;
personArray[nLikedPeople++]=f->actress;
//add genre
genreArray[nLikedGenres++]=f->getGenre();
};
int User::scoreFilm(Film* f){
int total=1;
int counter=0;
while(counter<nLikedFilms){
    if(f->getDirector()->getName()==personArray[counter]->getName()||f->getActress()->getName()==personArray[counter]->getName()||f->getActor()->getName()==personArray[++counter]->getName()){
        total+=5;
    }
}
counter=0;
while(counter<nLikedGenres){
    if(f->getGenre()==(genreArray[++counter])){
        total+=10;
    }
}
total=(total+pow(f->getRating(), 1.5));
total=(pow(total, 1.6*(f->getAwards()+1)));
return total;
};
