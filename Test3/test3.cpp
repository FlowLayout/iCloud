#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <vector>
using namespace std;
void Swap(int* x, int* y) {
	int c = 0;
	c = *x; *x = *y; *y = c;
}
void Swap(double* x, double* y) {
	double c = 0;
	c = *x; *x = *y; *y = c;
}

vector<int> Sort(vector<int> vec ) {

	for (int i = 1; i < vec.size(); i++) {
		int o = i;
		while (o!=0&&vec[o - 1] > vec[o]) {
			Swap(&vec[o - 1], &vec[o]);
			o--;
			/*if (o == 0)
				break;*/
		}
	}
	return vec;
}

double getArea(double a, double b, double c) {
	
	double cosA = (a * a - b * b - c * c) / (-2 * b * c);
	double sinA = pow(1 - cosA * cosA, 0.5);
	return 0.5 * b * c * sinA;
	
}

int exam(int x,int y,int z) {
	vector<int>vec = {x,y,z };
	vector<int>newvec=Sort(vec);
	if (newvec[0] + newvec[1] < newvec[2])
	{
		return 0;
	}
	else
		return 1;
}

int findMax(vector<int>a) {
	int o = 0;
	for (int i=0;i<a.size();i++)
	{
		if (o<a[i]){
		  o = a[i];
	     }
	}
	return o;
}
double findMax(vector<double>a) {
	double o = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (o < a[i]) {
			o = a[i];
		}
	}
	return o;
}




int main()
{
	int m;
    cout << "Please type the number of sticks:";
	cin >> m;

	vector<int>side;
	for (int i = 0; i < m; i++) {
		int a;
		cout << "Please type the length of " << i + 1 << "th stick" << endl;
		cin >> a;
		side.push_back(a);
	}
	
		
	vector<int>perimeter;
		for (int i = 0; i < side.size()-2; i++)
		{
			for (int j = i + 1; j < side.size()-1; j++)
			{
				for (int k = j + 1; k < side.size(); k++)
				{
					if (exam(side[i], side[j], side[k]) == 1)
						perimeter.push_back(side[i]+side[j]+side[k]);
				}
			}
		}
		cout << "These are "<<perimeter.size()<<"triangles"<<endl;
		cout << "The max perimeter is "<<findMax(perimeter)<<endl;
		
	
	vector <double>area;
	for (int i=0;i<m;i++)
	{
		for (int j = i+1; j < m; j++)
		{
			for (int k=j+1;k<m;k++)
			{
			    if (exam(side[i], side[j], side[k])==1)
				area.push_back(getArea(side[i] , side[j] , side[k]));
			}
		}
	}
	cout << "The max area is " << findMax(area) << endl;
	
	
	
	
	
	system("pause");

	return 0;
}