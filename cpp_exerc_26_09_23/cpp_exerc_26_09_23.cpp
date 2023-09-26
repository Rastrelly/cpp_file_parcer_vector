#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::ifstream;
using std::getline;
using std::vector;

struct dataPoint
{
	int x, y;
};

vector<dataPoint> pts = {};

void printPoint(string prefix,dataPoint pt)
{
	printf("%s%d; %d\n",prefix.c_str(),pt.x,pt.y);
}

int main()
{
	ifstream dataRead("data.txt");
	string cLine = "";
	//get data from file and put into a vector
	while (getline(dataRead, cLine))
	{
		int l = cLine.length();
		int nSymbol = 0;
		string sym1 = "", sym2 = "";
		for (int i = 0; i < l; i++)
		{
			if (cLine[i] != ' ')
			{
				if (nSymbol == 0)
				{
					sym1 += cLine[i];
				}
				if (nSymbol == 1)
				{
					sym2 += cLine[i];
				}
			}
			else
			{
				nSymbol++;
			}
		}
		int cX = atoi(sym1.c_str());
		int cY = atoi(sym2.c_str());
		pts.push_back({cX, cY});
	}

	//analyze data from vector and get coords pf max Y
	dataPoint max = pts[0];
	for (int i = 1; i < pts.size(); i++)
	{
		if (pts[i].y > max.y)
		{
			max = pts[i];
		}
	}

	//print out our results:
	cout << "++ Resulting data ++\n";
	for (int i = 1; i < pts.size(); i++)
	{
		printPoint(std::to_string(i)+") ", pts[i]);
	}
	printPoint("Found maximum: ", max);

	system("pause");
}
