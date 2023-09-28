#include <iostream>
#include <optional>
#include <vector>

struct ContentRating {

  enum class Scheme { CA_Movie, CA_TV, CA_Movie_FR, CA_TV_FR, US_Movie, US_TV };

  Scheme scheme;
  std::string rating;
  std::vector<std::string> advisories; // optional. empty array means not set
};

int main(int argc, char *argv[]) {

  struct ContentRating cr;
  cr.scheme = ContentRating::Scheme::US_Movie;
  cr.rating = "PG";
  cr.advisories.push_back("AT");
  cr.advisories.push_back("BN");

  std::cout << "scheme - " << static_cast<int>(cr.scheme) << "/nrating - " <<
cr.rating
            << std::endl;
  for (auto ad : cr.advisories) {
    std::cout << ad;
  }
  std::cout << std::endl;

  return 0;
}
