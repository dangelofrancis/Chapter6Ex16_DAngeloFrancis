/*
TITLE: Chapter 6 Exercise 16 - D'Angelo Francis
FILE NAME : Chapter6Ex16_DAngeloFrancis.cpp
PROGRAMMER : D'Angelo Francis
DATE : December 2024
REQUIREMENTS : For this programming problem, download the following files from the book’s companion website :
-Teams.txt—This file contains a list of several Major League baseball teams in alphabetical order.
Each team listed in the file has won the World Series at least once.
- WorldSeriesWinners.txt—This file contains a chronological list of the World Series’ winning teams from 1903 to 2012.
(The first line in the file is the name of the team that won in 1903, and the last line is the name of the team that won in 2012. Note the World Series was not played in 1904 or 1994.)
Write a program that displays the contents of the Teams.txt file on the screen and prompts the user to enter the name of one of the teams.The program should then display the number of times that team has won the World Series in the time period from 1903 to 2012.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void readTeams(const string&, string[], int&);
void readWorldSeriesWinners(const string&, string[], int&);
int countWorldSeriesWins(const string&, string[], int);

int main() {
    const int MAX_TEAMS = 30;
    const int MAX_WINS = 1000;

    string teams[MAX_TEAMS];
    string winners[MAX_WINS];
    int numTeams = 0, numWinners = 0;

    readTeams("Teams.txt", teams, numTeams);
    readWorldSeriesWinners("WorldSeriesWinners.txt", winners, numWinners);
  
    cout << "List of Teams:" << endl;
    for (int i = 0; i < numTeams; ++i) {
        cout << teams[i] << endl;
    }

    cout << "Enter the name of a team: ";
    string team;
    cin.ignore(); 

    int wins = countWorldSeriesWins(team, winners, numWinners);

    if (wins > 0) {
        cout << team << " has won the World Series " << wins << " times." << endl;
    }
    else {
        cout << team << " has not won the World Series between 1903 and 2012." << endl;
    }

    return 0;
}
void readTeams(const string& filename, string teams[], int& numTeams) {
    ifstream file(filename);
    string team;
    numTeams = 0;

    if (!file) {
        cout << "Error opening the file " << filename << endl;
        return;
    }

    while (getline(file, team)) {
        teams[numTeams++] = team;
        if (numTeams >= 30) break; 
    }

    file.close();
}
void readWorldSeriesWinners(const string& filename, string winners[], int& numWinners) {
    ifstream file(filename);
    string winner;
    numWinners = 0;

    if (!file) {
        cout << "Error opening the file " << filename << endl;
        return;
    }

    while (getline(file, winner)) {
        if (winner != "World Series Not Played in 1904" && winner != "World Series Not Played in 1994") {
            winners[numWinners++] = winner;
            if (numWinners >= 1000) break; 
        }
    }

    file.close();
}
int countWorldSeriesWins(const string& team, const string winners[], int numWinners) {
    int count = 0;

    for (int i = 0; i < numWinners; ++i) {
        if (winners[i] == team) {
            count++;
        }
    }

    return count;
}
