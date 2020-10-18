

#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;



void Swap(int *a,int *b) {
	int c;
	c = *a; *a = *b; *b = c;
}
void Swap(double* a, double* b) {
	double c;
	c = *a; *a = *b; *b = c;
}
void Swap(char* a, char* b) {
	char c;
	c = *a; *a = *b; *b = c;
}
void Swap() {
	string type;
	cout << "Please select the type of data: int/double/char" << endl;
	cin >> type;
	if (type == "int") {
		int a; int b;
		cout << "Please type the value of a" << endl;
		cin >> a;
		cout << "Please type the value of b" << endl;
		cin >> b;
		cout << "a=" << a << "   b=" << b << endl;
		Swap(&a, &b);
		cout << "swap completed." << endl << "a=" << a << "   b=" << b;
	}
	else{
		if (type=="double")
	{
		double a; double b;
		cout << "Please type the value of a" << endl;
		cin >> a;
		cout << "Please type the value of b" << endl;
		cin >> b;
		cout << "a=" << a << "   b=" << b << endl;
		Swap(&a, &b);
		cout << "swap completed!" << endl << "a=" << a << "   b=" << b;
	}
	 
	else
		{
			char a; char b;
			cout << "Please type the value of a" << endl;
			cin >> a;
			cout << "Please type the value of b" << endl;
			cin >> b;
			cout << "a=" << a << "   b=" << b << endl;
			Swap(&a, &b);     //Swap方法重载
			cout << "swap completed!" << endl << "a=" << a << "   b=" << b;
	}
	}


}
double Delta(int a, int b, int c) {
	return (pow(b, 2) - 4 * a * c);
}
void equation() {
	
	int a;
	cout << "Please type the value of a:" << endl;
	cin >> a;
	int b;
	cout << "Please type the value of b:" << endl;
	cin >> b;
	int c;
	cout << "Please type the value of c:" << endl;
	cin >> c;
	double delta = Delta(a, b, c);
	if (delta < 0)
	{
		cout << "This equation has no solution!";
	}
	else {
		if (delta == 0)
		{
			double x1 = (b) / (-2 * a);
			cout << "This equation has two same solution:x1=x2=" << x1;
		}
		else
		{
			double x1 = (b + pow(delta, 0.5)) / (-2 * a);
			double x2 = (b - pow(delta, 0.5)) / (-2 * a);
			cout << "This equation has two solution:" << "x1=" << x1 << " x2=" << x2;
		}
	}
}



void triangle() {
	double a, b, c;
	cout << "Please type first side length:";
	cin >> a;
	cout << endl<<"Please type second side length:";
	cin >> b;
	cout << endl<<"Please type third side length:";
	cin >> c;
	double cosA = (a * a - b * b - c * c) / (-2 * b * c);
	double sinA = pow(1 - cosA * cosA, 0.5);
	double area = 0.5 * b * c * sinA;
	cout << endl << "The value of area is:" << area;
}

void date() {
	int Year, Month, Day;
	cout << "Please type the value of Year:";
	cin >> Year;
	cout <<endl <<"Please type the value of Month:";
	cin >> Month;
	cout <<endl<< "Please type the value of Day:";
	cin >> Day;
	printf("\n%d-%d-%d\n", Year, Month, Day);
	
	int days[] = { 31,28,31,30,31,30,31,31,30,31,30}; //一月到十一月的天数
	if ((Year % 4 == 0) && (Year % 400 == 0))         //若为闰年则将2月设置为29天
	{
		days[2] = 29;
	}
		int daysInYear=0;
		for (int i=0;i<Month-1;i++)
		{
			daysInYear = daysInYear + days[i];
		}
		int weeksInYear = daysInYear/7+1;
        cout << "This day is " << daysInYear + Day << "th day and "
			<<weeksInYear<<"th weeks in the year.";

}
int main()
{
	
	int code;   /*  设定指令菜单：
					1.方程求解
					2.交换数据
					3.计算三角形面积
					4.计算日期        */
	cout << "Please select the number of action to perform: " << endl
		<< " 1 ********* To solve the equation." << endl
		<< " 2 ********* To swap the data." << endl
		<< " 3 ********* To calculate the area of the triangle." << endl
		<< " 4 ********* To calculate the date." << endl;
		
        cin >> code;      //采集指令
		switch (code)     //分辨指令并执行
		{
		case 1:equation();
			break;
		case 2:Swap();
			break;
		case 3:triangle();
			break;
		case 4:date();
			break;
		}

    system("pause");
	
	return 0;
}