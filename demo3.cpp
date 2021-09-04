#include <iostream>

using namespace std;

class Shape{
	public:
		void setwidth(int width){_width = width;};
		void setlength(int length){_length = length;};
		
	protected:
		int _width;
		int _length;
};

class Paincost{
	public:
		int getcost(int area){return area * 70;};
};

class Retangle: public Shape, public Paincost{
	public:
		int getarea(){return _length * _width;};
};

int main(void)
{
	Retangle ret;
	int areas = 0;
	int cost = 0;
	
	ret.setlength(5);
	ret.setwidth(7);
	areas = ret.getarea();
	cost = ret.getcost(areas);
	cout << "area is :" << areas << endl;
	cout << "cost is :" << cost << endl;
	
	return 0;
}
