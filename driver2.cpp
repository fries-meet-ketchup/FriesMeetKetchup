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
  int n = 4;
  Heap pq(n);
  bool flag = false;
  string country, city, type, vegeterian, price, rating, restaurant;
  string line;
  string filename, filename2;
  string answerCountry;
  string answerCity;
  string answerType;
  string answerVeg;
  string answerPrice;
  string name, age, gender, job, face, interset1, interset2, YorN, realAge;
  string answer1, answerAge, answerGender, answerInterest1, answerInterest2;
  vector<Node2> v;
  int count = 0;
  bool right=false;
  filename = argv[1];
  filename2 = argv[2];
  ifstream inStream (filename);
  ifstream inStream2(filename2);
  cout << "# Choose the cuisine of food:"<<endl;
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
  cout<< "Are you planning to go with someone?(Y/N)"<<endl;
  getline(cin, answer1);
  if (answer1 == "N"){
    cout << "Would you like to join someone?(Y/N)"<<endl;
    getline(cin, YorN);
    if (YorN == "Y"){
      cout<<"Choose age range: 1.18-21. 2.22-25. 3.26-30. 4.31-35"<<endl;
      getline(cin, answerAge);
      cout<<"Choose gender: 1.female 2.male "<<endl;
      getline(cin, answerGender);
      cout<<"First interset: "<<endl;
      cout<<"1.Reading\n2.Sports\n3.Hiking\n4.Skiing/Snowboarding\n5.Gaming\n6.Movies\n7.Cooking"<<endl;
      getline(cin, answerInterest1);
      cout<<"Second interset: "<<endl;
      cout<<"1.Reading\n2.Sports\n3.Hiking\n4.Skiing/Snowboardingn\n5.Gaming\n6.Movies\n7.Cooking"<<endl;
      getline(cin, answerInterest2);
      if (inStream2.is_open())
      {
        while (getline(inStream2,line)){
          if(line != "")
          {
            stringstream str(line);
            getline(str, face, ',');
            getline(str, name, ',');
            getline(str, realAge, ',');
            getline(str, gender, ',');
            getline(str, job, ',');
            getline(str, interset1, ',');
            getline(str, interset2,',');
            getline(str, city,',');
            getline(str, age, ',');
            Node2 z;
            z.name=name;
            z.job=job;
            z.face=face;
            z.realAge=realAge;
            z.city=city;
            if(gender == answerGender && age == answerAge && interset1 == answerInterest1 && interset2 == answerInterest2){
              v.push_back(z);
            }
            if (gender == answerGender && age == answerAge && interset2 ==answerInterest1 && interset1 == answerInterest2){
              v.push_back(z);
            }
          }
        }
      }
    }
    else{
      cout<<"Enjoy!!!"<<endl;
    }
  }
  else if(answer1 == "Y"){
    cout<<"Enjoy!!!"<<endl;
  }
  if(inStream.is_open())
  {
    while (getline(inStream,line)){
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
        if(country == answerCountry && type == answerType && city == answerCity && vegeterian == answerVeg && price == answerPrice){
          pq.enqueue(restaurant, stod(rating));
        }
      }
    }
    pq.printArray(n);
    for (int i = 0; i < v.size(); i++){
        cout<<"Profile: "<<v[i].face<<endl;
        cout<<" "<<"Name: "<<v[i].name<<endl;
        cout<<" "<<"Age: "<<v[i].realAge<<endl;
        cout<<" "<<"Job: "<<v[i].job<<endl;
        cout<<" "<<"City: "<<v[i].city<<endl;
    }
    inStream.close();
  }
  return 0;
}
