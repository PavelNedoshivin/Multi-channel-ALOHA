#include "aloha.h"
using namespace std;
int main()
{
	int nrolls = 0;
	cout << "Number of experiments: ";
	cin >> nrolls;
	int nchannels = 0;
	cout << "Number of channels: ";
	cin >> nchannels;
	Aloha* test = new Aloha(nrolls, nchannels);
	test->save();
	/*Aloha* test = new Aloha(nrolls, 1);
	test->saveExperiment();*/
	delete test;
	return 0;
}