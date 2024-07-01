#include "../src/vector_ry.cpp"
#include <iostream>
using namespace ry_stl;
using namespace std;

template <typename T>
void OutputVec(const ry_stl::vector_ry<T>& vec_ry) {
    for (auto i : vec_ry) {
        cout << " " << i;
    }
    cout << endl;
}
int main (){
	vector_ry<int> new_v1(1);
	vector_ry<int> new_v2;
	cout << "is v1 empty? "<<new_v1.empty()<< endl;
	cout << "is v2 empty? "<<new_v2.empty()<< endl;
	new_v1.push_back(1);
	OutputVec(new_v1);
	new_v1.push_back(2);
	OutputVec(new_v1);
	new_v1.push_back(3);
	OutputVec(new_v1);
	return 0;
}