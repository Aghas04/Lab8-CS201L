#include <iostream>
#include <vector>
#include "Lab08Utility.h"
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;


/*void loadTotal(vector<string>& total, string fileName) {
	string line, test = "";
	int index;
	double temp;
	ifstream inFile(fileName);

	while (getline(inFile, line)) {
		total.push_back(line);
	}
	inFile.close();
}
void loadVectors(vector<string>& total, vector<double>& DVD, vector<double>& MUSIC, vector<double>& TV) {
	string line, test = "";
	int index;
	double temp;

	
	for (int j = 0; j < total.size(); j++) {
		test = "";
		for (int i = 0; i < total[j].length(); i++) {
			if (isalpha(total[j][i])) {
				test += total[j][i];
			}
			else {
				index = i;
				break;
			}

		}
		if (test == "DVD") {
			string strnum = total[j].substr(index, total[j].length() - 1);
			temp = stod(strnum);
			DVD.push_back(temp);
		}
		else if (test == "MUSIC") {
			string strnum = total[j].substr(index, total[j].length() - 1);
			temp = stod(strnum);
			MUSIC.push_back(temp);
		}
		else if (test == "TV") {
			string strnum = total[j].substr(index, total[j].length() - 1);
			temp = stod(strnum);
			TV.push_back(temp);
		}
	}

}

void SelectionSort(vector<double>& data) {
	int i;
	int j;
	int indexSmallest;
	double temp;      // Temporary variable for swap

	for (i = 0; i < data.size(); ++i) {

		// Find index of smallest remaining element
		indexSmallest = i;
		for (j = i + 1; j < data.size(); ++j) {

			if (data[j] < data[indexSmallest]) {
				indexSmallest = j;
			}
		}

		// Swap numbers[i] and numbers[indexSmallest]
		temp = data[i];
		data[i] = data[indexSmallest];
		data[indexSmallest] = temp;
	}
}


double totalval(vector<double> data) {
	if (data.size() == 0) {
		
		return 0;
	}
	double totalval = 0;
	for (int i = 0; i < data.size(); i++) {
		totalval += data[i];

	}
	return totalval;
}

double mean(vector<double> data,double total) {
	if (data.size() == 0) {
		cout << "nan";
		return 0;
	}
	return total / data.size();
}

double median(vector<double> data) {
	if (data.size() == 0) {
		cout << "nan";
		return 0;
	}
	int size = data.size(),index;
	double middle;
	if (size % 2 == 0) {
		middle = size / 2;
		return (data[middle] + data[middle - 1]) / 2;
	}
	else {
		middle = (size + 1) / 2;
		return data[middle - 1];
	}
	
}
*/
int main() {
	vector<double> TV;
	vector<double> DVD;
	vector<double> MUSIC;

	vector<string> total;
	//comment out the one you do not want to use
	//loadTotal(total, "input.txt");
	loadTotal(total, "input1.txt");
	loadVectors(total, DVD, MUSIC, TV);


	SelectionSort(DVD);
	SelectionSort(TV);
	SelectionSort(MUSIC);
	
	outputData(DVD, MUSIC, TV);

	
	return 0;
}