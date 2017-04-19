//#include <fstream>
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	ifstream in("input.txt");
//
//	int n;
//	in >> n;
//
//	double matrix[4][5];
//
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//			in >> matrix[i][j];
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = i + 1; j < n; j++)
//			for (int k = i + 1; k < n; k++)
//				matrix[j][k] -= matrix[i][k] * matrix[j][i] / matrix[i][i];
//		for (int j = i + 1; j < n; j++)
//			matrix[j][i] /= (matrix[i][i]); 
//	}
//
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 5; j++)
//			cout << matrix[i][j] << " ";
//		cout << endl;
//	}
//
//
//
//	return 0;
//}
#include <iostream>
#include <fstream>
#include <iomanip>
#include <time.h>
using namespace std;
void main(){
	clock_t start, finish;
	start = clock();
	float **matrix;
	float **E;
	int n;
	int count=1;
	ifstream in;
	in.open("input.txt");
	ofstream out;
	out.open("out.txt");
	in>>n;
	matrix=new float*[n];
	E=new float*[n];
	for (int i=0;i<n;i++){
		matrix[i]=new float[n];
		E[i]=new float[n];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j)
				E[i][i]=1.0;
			else
				E[i][j]=0.0;
		}
	}
	for (int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			in>>matrix[i][j];	
	for(int k=n-1;k>0;k--){ //kolonki
		if(matrix[k-1][k]>matrix[k][k])
		 {count*=-1;
		float*t=matrix[k];
		matrix[k]=matrix[k-1];
		matrix[k-1]=t; 
		t=E[k];
		E[k]=E[k-1];
		E[k-1]=t;
		}
			matrix[k-1][k]/=matrix[k][k];
			for (int j=k-1;j>=0;j--){
				matrix[k-1][j]-=matrix[k-1][k]*matrix[k][j];
			}
			for(int j=0;j<n;j++)
				E[k-1][j]-=matrix[k-1][k]*E[k][j];
	} 

	float det=count;
	for(int i=0;i<n;i++)
		det*=matrix[i][i];
	if (det==0) cout<<"det A=0 => 1/A is absent."<<endl;
	else
	{
		float **res;
		res=new float*[n];
		for(int i=0;i<n;i++)
			res[i]=new float[n];
		for(int k=0;k<n;k++){
			for(int i=0;i<n;i++){ 
				for(int j=0; j<i;j++){ 
					E[i][k]-=matrix[i][j]*res[j][k];
				}
				res[i][k]=E[i][k]/matrix[i][i];

			}
		}
		finish=clock();
		cout<<float(finish - start)/CLOCKS_PER_SEC<<endl; 


		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<setw(7)<<res[i][j]<<" ";
			}
			cout<<endl;
		} 
	}
}
