#include "../src/vector_ry.cpp"
#include <iostream>
using namespace ry_stl;
using namespace std;
int main (){
	vector_ry<int> new_v1(1);
	vector_ry<int> new_v2;
	cout << "is v1 empty? "<<new_v1.empty()<< endl;
	cout << "is v2 empty? "<<new_v2.empty()<< endl;
	return 0;
}