#include <iostream>
#include "library.h"
#include <iomanip>

int main() {

  const int CAPACITY = 10;
  unsigned int sizeArr = 0;
  Otome gameArr[CAPACITY];
  bool open = false; 
  char choice; 
  string removeGame, filter;
  unsigned gameChoice;
  

  if (!collect_data(gameArr, sizeArr)) {
    return 1;
  }

//welcome message
cout<<"Welcome. This program deals with data about top otome games.\nThe source is: https://w.atwiki.jp/ggirluriage/sp/pages/14.html#ldA-1\n";
  do{

    cout<<"\nChoose an option: \na. display all\nb. sort\nc. remove\nd. analysis\ne. filter by console\nany other key to exit:\t";
    cin>> choice;
    if(choice=='a'){
      display_all(gameArr, sizeArr);
    }else if(choice=='b'){
      cout << endl << "After sorting by game title in alphabetical order" << endl;
      sort(gameArr, sizeArr);
      display_all(gameArr, sizeArr);
    }else if(choice=='c'){
      cout << "Enter name of game you want to remove. Please type the title exactly as you see it.\t";
      cin.ignore();
      getline(cin,removeGame);
      remove(gameArr, sizeArr, removeGame);//will update to allow user choice of removal
      display_all(gameArr, sizeArr);
    }else if(choice=='d'){
      displayPercentSales(gameArr,sizeArr);
      displayTopConsole(gameArr,sizeArr);
    }else if(choice=='e'){
     filterByConsole(gameArr, sizeArr, filter);
    }


  }while(choice>='a'&choice<='e');
  cout<<endl<<"Thank you for using my program!";


  return 0;
}