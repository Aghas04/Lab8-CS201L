#include <iostream>
#include <vector>
#include "Lab08Utility.h"
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

void loadTotal(vector<string>& total, string fileName) {
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

double mean(vector<double> data, double total) {
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
	int size = data.size(), index;
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
void outputData(vector<double>& DVD, vector<double>& MUSIC, vector<double>& TV) {
	ofstream outFile("output.txt");
	if (!outFile.is_open()) {
		cout << "not open" << endl;
	}

	if (!(DVD.size() == 0)) {
		outFile << setw(7) << left << "DVD: " << setw(7) << left << totalval(DVD) << " " << setw(7) << left << median(DVD) << " " << mean(DVD, totalval(DVD)) << endl;
	}
	else if (DVD.size() == 0) {
		outFile << setw(7) << left << "DVD: " << setw(7) << left << 0 << " " << setw(7) << left << "nan" << " " << "nan" << endl;
	}
	if (!(TV.size() == 0)) {
		outFile << setw(7) << left << "TV: " << setw(7) << left << totalval(TV) << " " << setw(7) << left << median(TV) << " " << mean(TV, totalval(TV)) << endl;
	}
	else if (TV.size() == 0) {
		outFile << setw(7) << left << "TV: " << setw(7) << left << 0 << " " << setw(7) << left << "nan" << " " << "nan" << endl;
	}
	if (!(MUSIC.size() == 0)) {
		outFile << setw(7) << left << "MUSIC: " << setw(7) << left << totalval(MUSIC) << " " << setw(7) << left << median(MUSIC) << " " << mean(MUSIC, totalval(MUSIC)) << endl;
	}
	else if (MUSIC.size() == 0) {
		outFile << setw(7) << left << "MUSIC: " << setw(7) << left << 0 << " " << setw(7) << left << "nan" << " " << "nan" << endl;
	}



	outFile.close();
}