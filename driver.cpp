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
  int print = 6; //how many we want to print
  int maxsize = 5; //max size for heap
  Heap pq1(maxsize); 
  Heap pq2(maxsize);
  bool flag = false;
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
  cout << "# Choose the country of food:"<<endl;
  cout<< "1.American\n2.Japanese\n3.Chinese\n4.Korean\n5.Mediterranean\n6.Italian\n7.Indian\n8.Mexican" << endl;
  getline(cin, answerCountry);
  cout << "# Choose the city:" <<endl;
  cout<< "1.Boulder\n2.Westminster\n3.Denver" << endl;
  getline(cin, answerCity);
  cout << "# Choose the type of food: "<<endl;
  cout<<"1.Brunch\n2.Coffee\n3.Restaurant" << endl;
  getline(cin, answerType);
  cout << "# Are you vegeterian or not: Y or N." << endl;
  getline(cin, answerVeg);
  cout << "# Choose the price: $ or $$, or $$$" << endl;
  getline(cin, answerPrice);
  filename = argv[1];
  ifstream inStream (filename);
  if (inStream.is_open())
  {
     while (getline(inStream,line))
    {
      if(line != "")
      {
        stringstream str(line);
        getline(str, type, ',');
        getline(str, restaurant, ',');
        getline(str, vegeterian, ',');
        getline(str, country, ',');
        getline(str, rating, ',');
        getline(str, price, ',');
        getline(str, city,',');
        if(country == answerCountry &&
          type == answerType &&
          city == answerCity &&
          vegeterian == answerVeg &&
          price == answerPrice)
        {
          pq1.enqueue(restaurant, stod(rating));
          flag = true;
        }
  
        else
        {
          if (city == answerCity)
          pq2.enqueue(restaurant,stod(rating));
        }
        }
      }
      if (flag == false)
      {
        pq2.printArray(print);
      }
      else
      {
        pq1.printArray(print);
      }
    }
  inStream.close();
  return 0;
}
