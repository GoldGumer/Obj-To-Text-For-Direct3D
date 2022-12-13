#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

int main()
{
    string fileName = "Bottle2.obj";
	ifstream obj(fileName);
	ofstream outTxt("out.txt");
	string skip;
	vector<string> vertices;
	vector<string> indices;
	getline(obj, skip, 'C');
	while (getline(obj, skip, 'v'))
	{
		string pos;
		for (int i = 0; i < 3; i++)
		{
			getline(obj, skip, ' ');
			obj >> pos;
			vertices.push_back(pos);
		}
	}
	obj.close();
	obj.open(fileName);
	getline(obj, skip, 'C');
	while (getline(obj, skip, 'f'))
	{
		string pos;
		for (int i = 0; i < 3; i++)
		{
			getline(obj, skip, ' ');
			obj >> pos;
			indices.push_back(pos);
		}
	}
	obj.close();
	for (int i = 0; i < 3; i++)
	{
		vertices.pop_back();
		indices.pop_back();
	}
	for (int i = 0; i * 3 < vertices.size(); i++)
	{
		outTxt << '{';
		for (int j = 0; j < 3; j++)
		{
			if (j != 2)
			{
				outTxt << vertices[i * 3 + j] << ',';
			}
			else
			{
				outTxt << vertices[i * 3 + j];
			}
		}
		outTxt << '}' << ',' << endl;
	}
	for (int i = 0; i * 3 < indices.size() / 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			outTxt << indices[i * 3 + j] << ',';
		}
		outTxt << endl;
		for (int j = 0; j < 3; j++)
		{
			outTxt << indices[(indices.size() / 2) + i * 3 + j] << ',';
		}
		outTxt << endl;
	}
	outTxt.close();
	
	return 0;
}