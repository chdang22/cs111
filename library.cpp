#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "library.h"

using namespace std;

bool collect_data(Otome g[], unsigned int& numGames){
  //open
  ifstream input_file("input.dat");
  if (!input_file.is_open()){
   cout << "File not opened" << endl;
   return false;
  }
//collect
  //getline(input_file,g[0].url);//store url into url vari
 //collect loop to get all data
  // Read the url
  string url;
  getline(input_file, url);
  // Read games
  numGames = 10;
  for(int games = 0; games < numGames && !input_file.eof(); games++){
    getline(input_file, g[games].name, ',');
    getline(input_file, g[games].console, ',');
    getline(input_file, g[games].developer, ',');

    string str1, str2;
    getline(input_file, str1, ',');
    getline(input_file, str2);
    g[games].totalSales = stoi(str1);
    g[games].weekSales = stoi(str2);
    // input_file >> g[games].totalSales;
    // char chr;
    // input_file >> chr;
    // input_file >> g[games].weekSales;
    //collect characrer names
    for(int i = 0; i < 6; i++){
      getline(input_file, g[games].characters[i]);
    }    
  }
   
  input_file.close();
  return true; 
}

void display_all(Otome g[], unsigned int numGames){
  //heade3rs
 // cout<< setw(5)<<"Rank"
  cout << left;
  cout << setw(30) << "Name" << setw(10) << "Console";
  cout << setw(15) << "Total Sales" << setw(15) << "Week 1 Sales";
  cout << setw(25) << "Character1" << setw(25) << "Character2"
       << setw(25) << "Character3" << setw(25) << "Character4"
       << setw(25) << "Character5" << setw(25) << "Character6" << endl;
  cout << setw(220) << setfill('=') << "=" << endl;
  //data to table
  for (int i = 0; i < numGames; i++) {
   // int i=0;
   
    cout << setfill(' ');
    cout << setw(30) << g[i].name << setw(10) << g[i].console;
    cout << setw(15) << g[i].totalSales << setw(15) << g[i].weekSales;
    for(int j = 0; j < 6; j++){
      cout << setw(25) << g[i].characters[j];    
    }
    cout << endl;
  }  
}

void sort(Otome g[], unsigned int numGames)
{
  // Sort according to name
  for (int i = 0; i < numGames; i++)
  {
    for (int j = i + 1; j < numGames; j++)
    {
      if (g[i].name.compare(g[j].name) > 0)
      {
        // Swap
        Otome tmp = g[i];
        g[i] = g[j];
        g[j] = tmp;
      }
    }
  }
}

void remove(Otome g[], unsigned int& numGames, string name)
{
  bool found=false;
  // Remove a game with the given name
  int i = 0;
  while (i < numGames)
  {
    if (g[i].name.compare(name) == 0)
    {
      found=true;
      // Found the game, remove it
      for (int j = i + 1; j < numGames; j++)
      {
        g[j - 1] = g[j];
      }
      // Decrease the number of games
      numGames--;
    }
    else
      i++;
  }
  if(found==false){
    cout<<"Game not found. Please enter correctly or ensure the game entered is in the list.\n";
  }
  if(found==true){
    cout << endl << "After removing " << name << endl;
  }
}
/*double percentSales(Otome g[],unsigned gameNum){
  double division,percent;
  division=(double)g[gameNum-1].weekSales/(double)g[gameNum-1].totalSales;
  percent=division*100;
  return percent;
}*/

void displayPercentSales(Otome g[],unsigned numGames){
  
  double division,percent;

  //DISPLAAY heade3rs
  cout<<"This is the percentage of sales that the 1st Week Sales takes up of the total sales"<<endl;
  cout<<left;
  cout << setw(30) << "Name";
  cout << setw(15) << "Total Sales" << setw(15) << "Week 1 Sales"<<setw(25)<<"Wk1 % of Total Sales\n";
  cout  << setfill('=') << setw(85)<< "=" << endl;
  for(int i=0;i<numGames;i++){
    //maths
    division=(double)g[i].weekSales/(double)g[i].totalSales;
    percent=division*100;

    //display
    cout << setfill(' ');
    cout << setw(30) << g[i].name;
    cout<<showpoint<<fixed<<setprecision(2);
    cout << setw(15) << g[i].totalSales << setw(15) << g[i].weekSales<<setw(5)<<percent<< "%"<<endl;
     

  }
}

void displayTopConsole(Otome g[], unsigned numGames){
  int DS=0,PSP=0,PS2=0;
  string topConsole;
  for(int i=0;i<numGames;i++){
   if(g[i].console == "DS"){
    DS++;
    }else if(g[i].console == "PSP"){
      PSP++;
    }else{
      PS2++;
    
    }
  }
  cout<<endl;
  if(DS>PSP && DS>PS2){
    cout<<"The most common console in the list of top-selling otomes is DS\n";
  }else if(PSP>DS && PSP>PS2){
    cout<<"The most common console in the list of top-selling otomes is PSP\n";
  }else if(PS2>DS && PS2>PSP){
    cout<<"The most common console in the list of top-selling otomes is PSP\n";
  }
}

void filterByConsole(Otome g[], unsigned numGames, string consoleChoice){
  cout<< "Please type in the console you would like to filter by (ex. DS, PSP, PS2):\t";
  cin>>consoleChoice;
  cout << left;
  cout << setw(30) << "Name" << setw(10) << "Console";
  cout << setw(15) << "Total Sales" << setw(15) << "Week 1 Sales";
  cout << setw(25) << "Character1" << setw(25) << "Character2"
  << setw(25) << "Character3" << setw(25) << "Character4"
  << setw(25) << "Character5" << setw(25) << "Character6" << endl;
  cout << setw(220) << setfill('=') << "=" << endl;
  for(int i=0;i<numGames;i++){
    if (consoleChoice==g[i].console){
      cout << setfill(' ');
      cout << setw(30) << g[i].name << setw(10) << g[i].console;
      cout << setw(15) << g[i].totalSales << setw(15) << g[i].weekSales;
      for(int j = 0; j < 6; j++){
        cout << setw(25) << g[i].characters[j];    
      }
    cout << endl;
    }  
  }
}
