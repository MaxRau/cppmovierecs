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
int checkVector(vector<User*> a);
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

<<<<<<< HEAD
User::User() : username(""), password(""){
    cout << "DEFAULT USER CONFIGURATION";
=======
User::User() : username(""), password(""), nLikedFilms(0){
cout << "DEFAULT USER CONFIGURATION";
filmArray.clear();
personArray.clear();
genreArray.clear();
nLikedGenres=0;
nLikedPeople=0;
nLikedFilms=0;
>>>>>>> 144ce250bbfb3564db61e218ea4ab8c48a49c2c1
};
//Can the constructor check to make sure an object with these same values doesnt already exit?
User::User( std::string const &uName, std::string const &pw) : username(uName), password(pw){
cout << "Username: " << username << "\nPassword: " << password;
filmArray.clear();
personArray.clear();
genreArray.clear();
nLikedGenres=0;
nLikedPeople=0;
nLikedFilms=0;
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
    int isThere=-1;
    isThere=f->checkVector(filmArray);
        if(isThere==-1){
            cout<<"\nFilm has not yet been liked by user";
            filmArray.push_back(f);
            nLikedFilms++;
        }
        else{
            cout<<"\nFilm already liked by user";
        }
//add people
    isThere=f->actor->checkVector(personArray);
        if(isThere==-1){
            cout<<"\nNot yet liked by user(Person)";
            personArray.push_back(f->actor);
            nLikedPeople++;
        }
        else{
            cout<<"\nPerson already liked by user";
            
        }
    isThere=f->actress->checkVector(personArray);
        if(isThere==-1){
            cout<<"\nNot yet liked by user(Person)";
            personArray.push_back(f->actress);
            nLikedPeople++;
        }
        else{
            cout<<"\nPerson already liked by user";
            
        }
    isThere=f->director->checkVector(personArray);
    if(isThere==-1){
        cout<<"\nNot yet liked by user(Person)";
        personArray.push_back(f->director);
        nLikedPeople++;
    }
    else{
            cout<<"\nPerson already liked by user";
            
        }
personArray.push_back(f->director);
nLikedPeople++;
personArray.push_back(f->actress);
nLikedPeople++;
//add genre
genreArray.push_back(f->getGenre());
nLikedGenres++;
};
//Not working at the moment...
int User::scoreFilm(Film* f){
int total=1;
int counter=0;
while(counter<nLikedFilms){
    if(f->director->getName()==personArray[counter]->getName()||f->actress->getName()==personArray[counter]->getName()||f->actor->getName()==personArray[++counter]->getName()){
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
<<<<<<< HEAD
=======


int User::checkVector(vector<User*> a){
    int i=0;
    while(i<a.size()){
        if(a[i]->getUserName()==this->getUserName()) return i;
        i++;
    }
    return -1;
};
>>>>>>> 144ce250bbfb3564db61e218ea4ab8c48a49c2c1
