/*Vance Agte*/
/*CS& 132*/
/*Jean Liu*/
/*Project 2*/

/*This program will input the amount of daily food eaten by monkeys from file,
display it, calculate the average of all, the most by one monkey, and the 
least by any one monkey.*/

#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

void displayFood(double monkDay[][7], int row);
void dataInput(double monkDay[][7], int);
double calcAverage(double monkDay[][7], int row);
double findMost(double monkDay[][7], int row);
double findLeast(double monkDay[][7], int row);

int main()
{
	//const int MONKEY = 3, DAYS = 7;
	//ifstream inputFile;
	double monkeyDay[3][7];
	dataInput(monkeyDay, 3);
	displayFood(monkeyDay, 3);
	cout << endl;
	cout << "Average amount of food eaten by the monkey family is " 
		<< calcAverage(monkeyDay, 3) << " pounds." << endl;
	cout << "The most eaten by any one monkey was " << findMost(monkeyDay, 3) 
		<< " pounds." << endl;
	cout << "The least eaten by any one monkey was " << findLeast(monkeyDay, 3) 
		<< " pounds." << endl;
	
	system("pause");
	return 0;
} //End main


//This function takes a file, collects data from it, closes the file and 
//transfers data to an array
void dataInput(double monkDay [][7], int row) {
	ifstream inputFile;
	inputFile.open("monkeyBus.txt");
	//double monkDay[3][7];
	if (!inputFile)
		cout << "Error opening file.\n";
	else
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < 7; j++) {
				inputFile >> monkDay[i][j];
				if (monkDay[i][j] < 0) {
					cout << "\n Something went wrong. Please check the file." << endl;
				} // end if
			}// end for j
			
		}//end for i
	inputFile.close();

}// end dataInput


void displayFood(double monkDay[][7], int row) {

	cout << fixed << showpoint << setprecision(1);
	cout << setw(12) << " " << setw(8) << "Day 1" 
		<< setw(8) << "Day 2" << setw(8) << "Day 3" 
		<< setw(8) << "Day 4" << setw(8) << "Day 5" << setw(8) 
		<< "Day 6" << setw(8) << "Day 7" << endl;
	for (int i = 0; i < row; i++) {
		cout << setw(10) << "Monkey " << setw(2) << (i + 1);
		for (int j = 0; j < 7; j++) {
			cout << setw(8) << right << monkDay[i][j];
		}// end for j
		cout << endl;
	}//end for i
	   
}//End displayFood

//calculates the average amount of food eaten by the family
double calcAverage(double monkDay[][7], int row) {
	double foodSum = 0, foodAverage;
	int count = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < 7; j++) {
			foodSum += monkDay[i][j];
			count += 1;
		}// end for j

	}//end for i
	foodAverage = foodSum / count;
	return foodAverage;
}// end calcAverage


//Calculates which monkey ate the most
double findMost(double monkDay[][7], int row) {
	double monkFood[3];
	double foodSum = 0;
	double mostEaten = 0;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < 7; j++) {
			foodSum += monkDay[i][j];
		}// end for j
		monkFood[i] = foodSum;
		foodSum = 0;
	}//end for i
	for (int i = 0; i < size(monkFood); i++) {
		if (monkFood[i] > mostEaten)
			mostEaten = monkFood[i];
			}
	return mostEaten;
}//end findMost


//Calculates which monkey ate the least
double findLeast(double monkDay[][7], int row) {
	double monkFood[3];
	double foodSum = 0;
	double leastEaten = 0;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < 7; j++) {
			foodSum += monkDay[i][j];
		}// end for j
		monkFood[i] = foodSum;
		foodSum = 0;
	}//end for i
	for (int i = 0; i < size(monkFood); i++) {
		if (leastEaten == 0)
			leastEaten = monkFood[i];
		else if	(monkFood[i] < leastEaten){
				leastEaten = monkFood[i];
		}// end else if
	} // end for 
	return leastEaten;
}//end findLeast
