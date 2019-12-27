#include "aloha.h"
using namespace std;
Aloha::Aloha(int mess, int channel)
{
	nrolls = mess;
	nchannels = channel;
}
void Aloha::model(double p)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dis(0.0, 1.0);
	random_device rdP;
	mt19937 genP(rdP());
	uniform_real_distribution<> disP(0.0, 1.0);
	random_device rdC;
	mt19937 genC(rdC());
	uniform_int_distribution<> disC(0, nchannels - 1);
	vector<int> windows;
	vector<int> input;
	vector<int> channels;
	for (double i = 0.1; i < 0.91; i += 0.01)
	{
		lambda.push_back(i);
	}
	delay.resize(lambda.size());
	clients.resize(lambda.size());
	stream.resize(lambda.size());
	for (int i = 0; i < lambda.size(); i++)
	{
		vector<double> T;
		T.resize(nrolls);
		windows.clear();
		input.clear();
		channels.clear();
		channels.resize(nchannels);
		double time = 0;
		for (int j = 0; j < nrolls; j++)
		{
			T[j] = (-1 / lambda[i]) * log(dis(gen));
			time += T[j];
		}
		windows.resize(ceil(time));
		input.resize(ceil(time));
		double ct = 0;
		for (int j = 0; j < nrolls; j++)
		{
			ct += T[j];
			int number = floor(ct);
			input.resize(number + 1);
			input[number]++;
		}
		int counter = 0;
		int M = 0;
		time = 0;
		double abonents = 0;
		int lim = (int)(round(nrolls * 0.8));
		for (int j = 0; counter < lim; j++)
		{
			if (time > 20000)
			{
				break;
			}
			if (j == windows.size())
			{
				windows.resize(windows.size() * 2);
				input.resize(input.size() * 2);
			}
			if (input[j] > 0)
			{
				M += input[j];
			}
			abonents += M;
			for (int k = 0; k < nchannels; k++)
			{
				if (channels[k] == 1)
				{
					M--;
					counter++;
				}
				channels[k] = 0;
			}
			for (int k = 0; k < M; k++)
			{
				double decision = disP(genP);
				if (decision < p)
				{
					windows.resize(max((int)time + 2, (int)windows.size()));
					input.resize(max((int)time + 2, (int)input.size()));
					int channel = disC(genC);
					channels[channel]++;
				}
			}
			time++;
		}
		clients[i] = abonents / time;
		delay[i] = clients[i] / lambda[i] + 0.5;
		stream[i] = (double)counter / time;
	}
}
void Aloha::save()
{
	ofstream foutN("alohaN.txt", ios_base::out);
	foutN.exceptions(ios_base::badbit | ios_base::failbit);
	foutN.seekp(ios_base::beg);
	ofstream foutD("alohaD.txt", ios_base::out);
	foutD.exceptions(ios_base::badbit | ios_base::failbit);
	foutD.seekp(ios_base::beg);
	ofstream foutS("alohaS.txt", ios_base::out);
	foutS.exceptions(ios_base::badbit | ios_base::failbit);
	foutS.seekp(ios_base::beg);
	for (double p = 0.1; p <= 0.9; p += 0.1)
	{
		model(p);
		for (int i = 0; i < clients.size(); i++)
		{
			foutN << clients[i] << " ";
			foutD << delay[i] << " ";
			foutS << stream[i] << " ";
		}
		foutN << "\n";
		foutD << "\n";
		foutS << "\n";
	}
	foutN.close();
	foutD.close();
	foutS.close();
}
void Aloha::saveExperiment()
{
	ofstream foutN("experimentN.txt", ios_base::out);
	foutN.exceptions(ios_base::badbit | ios_base::failbit);
	foutN.seekp(ios_base::beg);
	ofstream foutD("experimentD.txt", ios_base::out);
	foutD.exceptions(ios_base::badbit | ios_base::failbit);
	foutD.seekp(ios_base::beg);
	ofstream foutS("experimentS.txt", ios_base::out);
	foutS.exceptions(ios_base::badbit | ios_base::failbit);
	foutS.seekp(ios_base::beg);
	for (int i = 1; i < 3; i++)
	{
		nchannels = i;
		modelExperiment();
		for (int i = 0; i < clients.size(); i++)
		{
			foutN << clients[i] << " ";
			foutD << delay[i] << " ";
			foutS << stream[i] << " ";
		}
		foutN << "\n";
		foutD << "\n";
		foutS << "\n";
	}
	foutN.close();
	foutD.close();
	foutS.close();
}
void Aloha::modelExperiment()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dis(0.0, 1.0);
	random_device rdP;
	mt19937 genP(rdP());
	uniform_real_distribution<> disP(0.0, 1.0);
	random_device rdC;
	mt19937 genC(rdC());
	uniform_int_distribution<> disC(0, nchannels - 1);
	vector<int> windows;
	vector<int> input;
	vector<int> channels;
	for (double i = 0.1; i < 1; i += 0.01)
	{
		lambda.push_back(i);
	}
	delay.resize(lambda.size());
	clients.resize(lambda.size());
	stream.resize(lambda.size());
	for (int i = 0; i < lambda.size(); i++)
	{
		/*if (lambda[i] > exp(-1))
		{
			clients[i] = clients[i - 1];
			delay[i] = delay[i - 1];
			stream[i] = stream[i - 1];
		}
		else
		{*/
		vector<double> T;
		T.resize(nrolls);
		windows.clear();
		input.clear();
		channels.clear();
		channels.resize(nchannels);
		double time = 0;
		for (int j = 0; j < nrolls; j++)
		{
			T[j] = (-1 / lambda[i]) * log(dis(gen));
			time += T[j];
		}
		windows.resize(ceil(time));
		input.resize(ceil(time));
		double ct = 0;
		for (int j = 0; j < nrolls; j++)
		{
			ct += T[j];
			int number = floor(ct);
			input.resize(number + 1);
			input[number]++;
		}
		int counter = 0;
		int M = 0;
		time = 0;
		double abonents = 0;
		int lim = (int)(round(nrolls * 0.8));
		for (int j = 0; counter < lim; j++)
		{
			/*if (windows.size() >= INT_MAX)
			{
				break;
			}*/
			if (j == windows.size())
			{
				windows.resize(windows.size() * 2);
				input.resize(input.size() * 2);
			}
			if (input[j] > 0)
			{
				M += input[j];
			}
			abonents += M;
			for (int k = 0; k < nchannels; k++)
			{
				if (channels[k] == 1)
				{
					M--;
					counter++;
				}
				channels[k] = 0;
			}
			for (int k = 0; k < M; k++)
			{
				double decision = disP(genP);
				double p = (double)nchannels / (double)M;
				if (decision < p)
				{
					windows.resize(max((int)time + 2, (int)windows.size()));
					input.resize(max((int)time + 2, (int)input.size()));
					int channel = disC(genC);
					channels[channel]++;
				}
			}
			time++;
		}
		clients[i] = abonents / time;
		delay[i] = clients[i] / lambda[i] + 0.5;
		stream[i] = (double)counter / time;
		//}
	}
}

Aloha::~Aloha()
{

}