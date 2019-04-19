#include <vector>
#include <queue>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "project.hpp"

using namespace std;

int main(int argc, char* argv[])
{
  int n = 6;
  Heap pq(n);
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
  cout << "4. Are you vegeterian or not: Y or N." << endl;
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
        // cout << line << endl;
        stringstream str(line);
        string t;
        getline(str, t, ',');
        type = t;
        cout<<"Testing: "<<type<<" rest. "<<endl;
        string r;
        getline(str, r, ',');
        restaurant = r;
        cout<<"Testing: "<<restaurant<<" type. "<<endl;

        string v;
        getline(str, v, ',');
        vegeterian = v;
        cout<<"Testing: "<<vegeterian<<" veg. "<<endl;

        string c;
        getline(str, c, ',');
        country = c;
        cout<<"Testing: "<<country<<" country "<<endl;
        getline(str, rating, ',');
        cout<<"Testing: "<<rating<<" rating "<<endl;

        string p;
        getline(str, p, ',');
        price = p;
        cout<<"Testing: "<<price<<" price "<<endl;

        getline(str, city,',');

        cout<<"Testing: "<<city<<" city "<<endl;

        // cout<<"Testing: "<<type;
        // cout << country << "&" <<  answerCountry << endl;
        // cout<<  type << "&" << answerType << endl;
        // cout << city <<"&" << answerCity <<endl;
        // cout << vegeterian << "&" << answerVeg << endl;
        // cout <<price << "&" <<answerPrice << endl;
        if(country == answerCountry && type == answerType && city == answerCity && vegeterian == answerVeg && price == answerPrice){
          pq.enqueue(restaurant, stod(rating));
        }
      }
    }
    pq.printArray(n);
  }
  inStream.close();
  return 0;
}

