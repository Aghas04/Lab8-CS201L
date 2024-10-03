#pragma once
#include <iostream>
#include <vector>

#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;


void loadTotal(vector<string>& total, string fileName);


void loadVectors(vector<string>& total, vector<double>& DVD, vector<double>& MUSIC, vector<double>& TV);

void SelectionSort(vector<double>& data);


double totalval(vector<double> data);

double mean(vector<double> data, double total);

double median(vector<double> data);

void outputData(vector<double>& DVD, vector<double>& MUSIC, vector<double>& TV);

//pre: none
//Post: asks user for file then reads file into vectors with corresponding type

