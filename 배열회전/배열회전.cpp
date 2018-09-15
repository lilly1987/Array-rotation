#include <iostream> //std
#include <string> //getline
#include "배열출력.h"

using namespace std;

void rotation270(int **a, int **b, unsigned int  c, unsigned int  r) {
	//cout << "rotation270"<< ", c:"<<c<<", r:"<<r<<endl<<endl;
	for (unsigned int i = 0; i < c; i++)
	{
		for (unsigned int j = 0; j < r; j++)
		{
			//cout << "rotation270"<< " , "<< c - i-1 <<" ,"<< j <<" ,"<< j <<" ,"<< i <<endl;
			b[c - i-1][j] = a[j][i];
		}
	}
}

void rotation180(int **a, int **b, unsigned int  c, unsigned int  r) {
	//cout << "rotation180"<< ", c:"<<c<<", r:"<<r<<endl<<endl;
	for (unsigned int i = 0; i < c; i++)
	{
		for (unsigned int j = 0; j < r; j++)
		{
			//cout << "rotation180"<< " , "<< r - j-1 <<" ,"<< c - i-1 <<" ,"<< j <<" ,"<< i <<endl;
			b[r - j -1][c - i-1] = a[j][i];
		}
	}
}

void rotation90(int **a, int **b, unsigned int  c, unsigned int  r) {
	//cout << "rotation90"<< ", c:"<<c<<", r:"<<r<<endl<<endl;
	for (unsigned int i = 0; i < c; i++)
	{
		for (unsigned int j = 0; j < r; j++)
		{
			//cout << "rotation90"<< " , "<<  i <<" ,"<< r - j -1<<" ,"<< j <<" ,"<< i <<endl;
			b[i][r-j-1] = a[j][i];
		}
	}
}

int main(int argc, char* argv[]) {

	unsigned int r, c;//r:행,c:열

	do
	{
		// 단순히 모양 출력용으로 cout 반복으로 쓰는건 성능상 좋지 않음
		// 수학적으로 쓸일이 있다면 모를까
		// 변수에 미리 처리후 한번만 출력하는게 젤 좋음
		// 배열 회전이 목적이므로 출력할때 회전시키지 않을것

		// 입력 받기
		cout << "숫자만 입력." << endl;
		cout << "0 입력시 종료" << endl;
		cout << "행 갯수:";
		//getline(cin, v);
		cin >> r;
		if (r <= 0)
		{
			break;
		}
		cout << "열 갯수:";
		cin >> c;
		if (c <= 0)
		{
			break;
		}
		//cin.clear();
		//fflush(stdin);//리눅스에선 작동 안됨.

		// 배열 초기화
		int **a;// 방향↗
		int **b;// 방향↙
		int **a90;// 방향↗ 90
		int **b90;// 방향↙ 90
		int **a180;// 방향↗ 180
		int **b180;// 방향↙ 180
		int **a270;// 방향↗ 270
		int **b270;// 방향↙ 270

		a = new int *[r];
		b = new int *[r];
		// 회전용
		a90 = new int *[c];
		b90 = new int *[c];
		a180 = new int *[r];
		b180 = new int *[r];
		a270 = new int *[c];
		b270 = new int *[c];

		for (int i = 0; i < r; i++) {
			//cout << "new int :" << i <<  endl;
			a[i] = new int[c];
			b[i] = new int[c];
			a180[i] = new int[c];
			b180[i] = new int[c];
		}

		// 회전용
		for (int i = 0; i < c; i++) {
			//cout << "new int :" << i <<  endl;
			a90[i] = new int[r];
			b90[i] = new int[r];
			a270[i] = new int[r];
			b270[i] = new int[r];
		}

		int t, n = 0, m = 0;

		//== 초기 배열 입력

		// Y>X 일때 효율적
		if (r < c)
		{

			// 입력↗
			for (int i = 0; i < r + c - 1; i++) { //3:0 -> 5
				for (int j = 0; j < c; j++) {
					t = i - j;				// Y 좌표값
					if (0 <= t && t < r)
					{
						a[t][j] = ++n;
					}
					//cout << "i:" << i << " , j:" << j << " , t:" << t << " , n:"<<n << endl;
				}
				//cout << endl;
			}

			// 입력↙
			for (int i = 0; i < r + c - 1; i++) { //3:0 -> 5
				for (int j = c - 1; j >= 0; j--) {
					t = i - j;				// Y 좌표값
					if (0 <= t && t < r)
					{
						b[t][j] = ++m;
					}
					//cout << "i:" << i << " , j:" << j << " , t:" << t << " , m:"<<m << endl;
				}
				//cout << endl;
			}

		}
		// Y<X 일때 효율적
		else {

			// 입력↙
			for (int i = 0; i < r + c - 1; i++) { //3:0 -> 5
				for (int j = 0; j < r; j++) {
					t = i - j;				// X 좌표값
					if (0 <= t && t < c)
					{
						b[j][t] = ++m;
					}
					//cout << "i:" << i << " , j:" << j << " , t:" << t << " , m:"<<m << endl;

				}
				//cout << endl;
			}

			// 입력↗
			for (int i = 0; i < r + c - 1; i++) { //3:0 -> 5
				for (int j = r - 1; j >= 0; j--) {
					t = i - j;				// X 좌표값
					if (0 <= t && t < c)
					{
						a[j][t] = ++n;
					}
					//cout << "i:" << i << " , j:" << j << " , t:" << t << " , n:"<<n << endl;				
				}
				//cout << endl;
			}
		}

		// === 배열 회전 ===

		rotation90(a, a90, c, r);
		rotation90(b, b90, c, r);

		rotation180(a, a180, c, r);
		rotation180(b, b180, c, r);

		rotation270(a, a270, c, r);
		rotation270(b, b270, c, r);

		// === 내용 출력 ===

		arr_out2("원본↗", a, r, c);
		arr_out2("원본↙", b, r, c);

		arr_out2("90↗", a90, c, r);
		arr_out2("90↙", b90, c, r);

		arr_out2("180↗", a180, r, c);
		arr_out2("180↙", b180, r, c);

		arr_out2("270↗", a270, c, r);
		arr_out2("270↙", b270, c, r);

		/*
		string s0 = "", s1 = "", s2 = "", s3 = "", s4 = "", s5 = "", s6 = "", s7 = "";

		s0 += "원본↗\n";
		s1 += "원본↙\n";
		s2 += "90↗\n";
		s3 += "90↙\n";
		s4 += "180↗\n";
		s5 += "180↙\n";
		s6 += "270↗\n";
		s7 += "270↙\n";

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				s0 += to_string(a[i][j]) + '\t';
				s1 += to_string(b[i][j]) + '\t';
				s4 += to_string(a180[i][j]) + '\t';
				s5 += to_string(b180[i][j]) + '\t';
			}
			s0 += '\n';
			s1 += '\n';
			s4 += '\n';
			s5 += '\n';
		}
		for (int i = 0; i < c; i++) {
			for (int j = 0; j < r; j++) {
				s2 += to_string(a90[i][j]) + '\t';
				s3 += to_string(b90[i][j]) + '\t';
				s6 += to_string(a270[i][j]) + '\t';
				s7 += to_string(b270[i][j]) + '\t';
			}
			s2 += '\n';
			s3 += '\n';
			s6 += '\n';
			s7 += '\n';
		}

		s0 += '\n';
		s1 += '\n';
		s2 += '\n';
		s3 += '\n';
		s4 += '\n';
		s5 += '\n';
		s6 += '\n';
		s7 += '\n';

		cout << s0;
		cout << s1;
		cout << s2;
		cout << s3;
		cout << s4;
		cout << s5;
		cout << s6;
		cout << s7;
		*/

		// 메모리 해제

		for (int i = 0; i < r; i++) {
			delete[] a[i], b[i], a90[i], b90[i], a180[i], b180[i], a270[i], b270[i];
		}
		delete[] a, b, a90, b90, a180, b180, a270, b270;

	} while (true); // 0 입력시 종료
}