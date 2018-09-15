#include <iostream> //std
#include <string> //getline

using namespace std;

void arr_out(const char * front,  int *arr, unsigned int r, unsigned int c, const char * back) {
	string  s = "" ;
	for (int i = 0; i < r; i++) {
		s += to_string(arr[i]) + '\t';
	}
	cout << front << endl << s<< back<<endl;
}
void arr_out(const char * front,  int *arr, unsigned int r, unsigned int c) {
	arr_out(front, arr, r,c, "");
}

void arr_out2(const char * front,  int **arr, unsigned int r, unsigned int c, const char * back) {
	
	string  s = "";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			s += to_string(arr[i][j]) + '\t';
		}
		s += '\n';
	}
	cout << front << endl << s<< back<<endl;
}
void arr_out2(const char * front,  int **arr, unsigned int r, unsigned int c) {
	arr_out2(front, arr, r,c, "");
}
