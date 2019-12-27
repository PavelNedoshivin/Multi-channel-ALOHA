#ifndef ALOHA_H
#define ALOHA_H
#include <iostream>
#include <random>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
class Aloha {
private:
	std::vector<double> clients;
	std::vector<double> delay;
	std::vector<double> stream;
	std::vector<double> lambda;
	int nrolls;
	int nchannels;
	void model(double p);
	void modelExperiment();
public:
	Aloha(int mess, int channel);
	void save();
	void saveExperiment();
	~Aloha();
};
#endif