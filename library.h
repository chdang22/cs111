#include <string>
using namespace std;

struct Otome{
  string name, console, developer;
  string characters[6];
  unsigned int totalSales, weekSales;
};

//collect data from input file into struct members
bool collect_data(Otome g[], unsigned int& numGames);
//display all data in tabular format
void display_all(Otome g[], unsigned int numGames);
//sort by alpha order
void sort(Otome g[], unsigned int numGames);
//remove chosen game by comparing user input string
void remove(Otome g[], unsigned int& numGames, string name);
//calc and display Wk1 % of Total Sales
void displayPercentSales(Otome g[],unsigned numGames);
//determine and display most common console
void displayTopConsole(Otome g[],unsigned numGames);
//filter by console
void filterByConsole(Otome g[], unsigned numGames, string consoleChoice);