// SRV_L4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <intrin.h>
#include <cstdlib>
#include <ctime>

#define RN(x)(double)((double)x.u.LowPart+(double)x.u.HighPart*(double)0xffffffff)

using namespace std;

int VOID_B(){

int N = 1336337; 
int div=2;
while (N>1){
	while(N%div==0)
		N/=div;
	div++;		
}
return N;
}

void VOID_C(int *mas){
	int temp = 0;
	for (int i = 0; i < 1000 - 1; i++) {
		for (int j = 0; j < 1000; j++) {
			if (mas[i] < mas[j]) {
				temp = mas[i];
				mas[i] = mas[j];
				mas[j] = temp;
			}
		}
	}
	
}

int VOID_D(){
int N = 909091; 
int div=2;
while (N>1){
	while(N%div==0)
		N/=div;
	div++;		
}
return N;
}

double getTimeFromVoid_B(){
	LARGE_INTEGER f,t0,t1;
	double t;

	QueryPerformanceFrequency(&f);
	QueryPerformanceCounter(&t0);
	VOID_B();
	QueryPerformanceCounter(&t1);
	t=(RN(t1)-RN(t0))/RN(f);

	//printf("\nTime is %f",t);
	return t;
}

double getTimeFromVoid_C(){	
	int mas[1000];
	for(int i =0; i < 1000;i++)
		mas[i]=rand();

	LARGE_INTEGER f,t0,t1;
	double t;

	QueryPerformanceFrequency(&f);
	QueryPerformanceCounter(&t0);
	VOID_C(mas);
	QueryPerformanceCounter(&t1);
	t=(RN(t1)-RN(t0))/RN(f);

	//printf("\nTime is %f",t);
	return t;
}

double getTimeFromVoid_D(){
	LARGE_INTEGER f,t0,t1;
	double t;

	QueryPerformanceFrequency(&f);
	QueryPerformanceCounter(&t0);
	VOID_D();
	QueryPerformanceCounter(&t1);
	t=(RN(t1)-RN(t0))/RN(f);

	//printf("\nTime is %f",t);
	return t;
}

double getTimeFromVoid_ALL(){		
	int mas2[1000];
	for(int i =0; i < 1000;i++)
		mas2[i]=rand();

	LARGE_INTEGER f,t0,t1;
	double t;

	QueryPerformanceFrequency(&f);
	QueryPerformanceCounter(&t0);
	VOID_B();
	VOID_C(mas2);
	VOID_D();
	QueryPerformanceCounter(&t1);
	t=(RN(t1)-RN(t0))/RN(f);

	//printf("\nTime is %f",t);
	return t;
}

double getMax(double arr[]) {
	double max=0;
	for(int i =0; i<100;i++)
	{
	if(arr[i]>max)
		max=arr[i];
	}
	return max;
}

double getMin(double arr[]) {
	double min=1;
	for(int i =0; i<100;i++)
	{
	if(arr[i]<min)
		min=arr[i];
	}
	return min;
}

void print(double min,double max,double delta,double mas[]){
	for (int i =0; i<10;i++){
		printf("%1.7f |",min);
		
		for (int j = 0;j<100;j++){
			if ((mas[j]<max)&&(mas[j]>min))
				cout<<"*";
		}
		min+=delta;
		max+=delta;
		cout<<endl;	
	}
	}

int _tmain(int argc, _TCHAR* argv[]){

	double masTimeB[100];
	double masTimeC[100];
	double masTimeD[100];
	double masTimeALL[100];

	double sumB=0;;
	double sumC=0;
	double sumD=0;
	double sumALL=0;

	double mxB=0;
	double mxC=0;
	double mxD=0;
	double mxALL=0;

	double dxB=0;
	double dxC=0;
	double dxD=0;
	double dxALL=0;


	for (int i=0; i<100;i++)
	{
	

	masTimeB[i]= getTimeFromVoid_B();
	masTimeC[i]= getTimeFromVoid_C();
	masTimeD[i]= getTimeFromVoid_D();
	masTimeALL[i]= getTimeFromVoid_ALL();

	sumB += masTimeB[i];
	sumC += masTimeC[i];
	sumD += masTimeD[i];
	sumALL += masTimeALL[i];

	mxB = sumB/100;
	mxC = sumC/100;
	mxD = sumD/100;
	mxALL = sumALL/100;
	
	dxB = (masTimeB[i] - mxB)*(masTimeB[i] - mxB);
	dxC = (masTimeC[i] - mxC)*(masTimeC[i] - mxC);
	dxD = (masTimeD[i] - mxD)*(masTimeD[i] - mxD);
	dxALL = (masTimeALL[i] - mxALL)*(masTimeALL[i] - mxALL);

	}

	double mxALLsum =mxB+mxC+mxD;
	double dxALLsum =dxB+dxC+dxD;



	cout <<"Start"<< endl;
	cout << "\nVOID B :" << endl ;
	printf(" Time(min) = %1.7f\n",getMin(masTimeB));
	printf(" Time(max) = %1.7f\n",getMax(masTimeB));
	printf(" mx = %1.10f\n", mxB);
	printf(" dx = %1.10f\n", dxB);
	
	double max,min,delta;
	max = getMax(masTimeB);
	min = getMin(masTimeB);
	delta = (max-min)/10;
	print(min,max,delta,masTimeB);

	
	cout << "\nVOID C :" << endl ;
	printf(" Time(min) = %1.7f\n",getMin(masTimeC));
	printf(" Time(max) = %1.10f\n",getMax(masTimeC));
	printf(" mx = %1.10f\n", mxC);
	printf(" dx = %1.10f\n", dxC);


	max = getMax(masTimeC);
	min = getMin(masTimeC);
	delta = (max-min)/10;
	print(min,max,delta,masTimeC);

	cout << "\nVOID D :" << endl ;
	printf(" Time(min) = %1.7f\n",getMin(masTimeD));
	printf(" Time(max) = %1.7f\n",getMax(masTimeD));
	printf(" mx = %1.10f\n", mxD);
	printf(" dx = %1.10f\n", dxD);
	
	max = getMax(masTimeD);
	min = getMin(masTimeD);
	delta = (max-min)/10;
	print(min,max,delta,masTimeD);

	cout << "\nVOID ALL :" << endl ;

	cout << "\nAnaliticheesk. : " << endl;
	printf(" mx = %1.10f\n", mxALLsum);
	printf(" dx = %1.10f\n", dxALLsum);

	cout << "\nNatural : " << endl ;
	printf(" Time(min) = %1.7f\n",getMin(masTimeALL));
	printf(" Time(max) = %1.7f\n",getMax(masTimeALL));
	printf(" mx = %1.10f\n", mxALL);
	printf(" dx = %1.10f\n", dxALL);
	
	max = getMax(masTimeALL);
	min = getMin(masTimeALL);
	delta = (max-min)/10;
	print(min,max,delta,masTimeALL);

	system("pause");
	return 0;
}

