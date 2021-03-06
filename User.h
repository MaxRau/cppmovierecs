class User {
public:
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
int checkVector(std::vector<User*> a);
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
#endif	/* USER_H */
