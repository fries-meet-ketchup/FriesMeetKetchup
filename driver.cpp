#include <iostream>
#include "project.hpp"

using namespace std;

// void menu()
// {
//   cout << "============Main Menu============" << endl;
//   cout << "1. Choose the country of food: American, Japanese, Chinese, Korean, Mediterranean, Italian, Indian, Mexican." << endl;
//   cout << "2. Choose the city: Boulder, Westminster, Denver." << endl;
//   cout << "3. Choose the type of food: Brunch, Coffee, Restaurant." << endl;
//   cout << "4. Are you vegeterian or not: Y or N." << endl;
//   cout << "5. Choose the price: $ or $$, or $$$" << endl;
//   cout << "6. Quit" << endl;
// }

int main(int argc, char* argv[])
{
  Heap pq(stoi(argv[1]));
  string country;
  string city;
  string type;
  string vegeterian;
  string price;
  string rating;
  string restaurant;
  string line;
  string filename;
  string answerCountry;
  string answerCity;
  string answerType;
  string answerVeg;
  string answerPrice;
  int count = 0;
  bool right=false;
  cout << "1. Choose the country of food: American, Japanese, Chinese, Korean, Mediterranean, Italian, Indian, Mexican." << endl;
  getline(cin, answerCountry);
  cout << "2. Choose the city: Boulder, Westminster, Denver." << endl;
  getline(cin, answerCity);
  cout << "3. Choose the type of food: Brunch, Coffee, Restaurant." << endl;
  getline(cin, answerType);
  cout << "4. Are you vegeterian or not: Yes or No." << endl;
  getline(cin, answerVeg);
  cout << "5. Choose the price: $ or $$, or $$$" << endl;
  getline(cin, answerPrice);
  filename = argv[1];
  ifstream inStream (filename);
  if (inStream.is_open())
  {
    while (getline(inStream,line)){
      if(line != "")
      {
        stringstream str;
        string t;
        getline(str, t, ',');
        type = t;
        string r;
        getline(str, r, ',');
        restaurant = r;
        string v;
        getline(str, v, ',');
        vegeterian = v;
        string c;
        getline(str, c, ',');
        country = c;
        string rt;
        getline(str, rt, ',');
        rating = rt;
        string p;
        getline(str, p, ',');
        price = p;
        string ci;
        getline(str, ci, ',');
        city = ci;
        if(country == answerCountry && type == answerType && city == answerCity && Vegeterian == answerVeg && price == answerPrice){
          pq.enqueue(restaurant, rating);
        }
      }
    }
  }
  inStream.close();
  return 0;
}
