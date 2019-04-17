#include <iostream>
#include "project.hpp"

using namespace std;

void menu()
{
  cout << "============Main Menu============" << endl;
  cout << "1. Choose the country of food: American, Japanese, Chinese, Korean, Mediterranean, Italian, Indian, Mexican." << endl;
  cout << "2. Choose the city: Boulder, Westminster, Denver." << endl;
  cout << "3. Choose the type of food: Brunch, Coffee, Restaurant." << endl;
  cout << "4. Are you vegeterian or not: Y or N." << endl;
  cout << "5. Choose the price: $ or $$, or $$$" << endl;
  cout << "6. Quit" << endl;
}

int main(int argc, char* argv[])
{
  Heap pq(stoi(argv[1]));
  string choice;
  string filename;
  string line;
  string type;
  ifstream inStream (filename);
  if (inStream.is_open())
  {
    while (getline(inStream,line)){
      if(line != ""){
        stringstream str;
        string t;
        getline(str, t, ' ');
        type = t;
        
//         pq.enqueue(type, , );
      }
    }
  }
  while (choice != "7")
  {
    menu();
    getline(cin, choice);
    switch (stoi(choice))
    {
      case 1:
      {
        break;
      }
        
        
        
      case 6:
      {
        cout << "Goodbye!" << endl;
        return 0;
      }
      default:
      {
        cout << "invalid input" << endl<<endl;
        break;
      }
    }
  }
  inStream.close();
  menu();
  return 0;
}
