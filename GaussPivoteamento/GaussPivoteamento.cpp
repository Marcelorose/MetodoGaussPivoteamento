// GaussPivoteamento.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>
#define COL 11
#define LIN 10

using namespace std;

void arrumarMatriz(double vetor[COL], double matriz[LIN][COL], int valor) {
	double temp = matriz[valor][valor];
	int pos = valor;
	for (int i = valor; i < LIN; i++)
	{
		if (fabs(matriz[i][valor]) > temp)
		{
			temp = fabs(matriz[i][valor]);
			pos = i;
		}
	}
	for (int i = 0; i < COL; i++)
	{
		vetor[i] = matriz[pos][i];
	}
	
	for (int i = 0; i < COL; i++)
	{
		matriz[pos][i] = matriz[valor][i];
	}
	for (int i = 0; i < COL; i++)
	{
		matriz[valor][i] = vetor[i];
	}
	
}

void mostrarMatriz(double matriz[LIN][COL]) {
	for (int i = 0; i < LIN; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			cout << matriz[i][j] << " | ";
		}
		cout << endl;
	}
}

void zerarBaixo(double matriz[LIN][COL], int valor) {
	double mult;
	double desvio;
	for (int i = valor; i < LIN - 1; i++)
	{
		mult = matriz[i + 1][valor] / matriz[valor][valor];

		for (int j = 0; j < COL; j++)
		{
			desvio = matriz[i + 1][j] - mult * matriz[valor][j];
			if (desvio > -0.0001 && desvio < 0 || desvio < 0.0001 && desvio > 0)
			{
				matriz[i + 1][j] = 0;
			}
			else
			{
				matriz[i + 1][j] = desvio;
			}
		}
		//mostrarMatriz(matriz);
		//cout << endl << endl;
	}
}

void zerarCima(double matriz[LIN][COL], int valor, int diag) {
	double mult;
	double desvio;
	for (int i = valor; i > 0; i--)
	{
		mult = matriz[i - 1][diag] / matriz[diag][diag];
		for (int j = 0; j < COL; j++)
		{
			desvio = matriz[i - 1][j] - mult * matriz[valor][j];
			if (desvio > -0.0001 && desvio < 0 || desvio < 0.0001 && desvio > 0)
			{
				matriz[i - 1][j] = 0;
			}
			else
			{
				matriz[i - 1][j] = desvio;
			}
		}
	}
}


int main()
{
	double matriz[LIN][COL] = { 2,1,7,4,-3,-1,4,4,7,0,86,4,2,2,3,-2,0,3,3,4,1,45,3,4,4,2,1,-2,2,1,9,-3,52.5,9,3,5,1,0,5,6,-5,-3,4,108,2,0,7,0,-5,7,1,0,1,6,66.5,1,9,8,0,3,9,9,0,0,5,90.5,4,1,9,0,4,3,7,-4,1,3,139,6,3,1,1,6,8,3,3,0,2,61,6,5,0,-7,7,-7,6,2,-6,1,-43.5,1,6,3,4,8,3,-5,0,-6,0,31 };
	double mult;
	double vetor[COL];
	double vetorRes[LIN];
	int diag = COL - 2;

	mostrarMatriz(matriz);
	cout << endl << endl;

	for (int i = 0; i < LIN - 1; i++)
	{
		arrumarMatriz(vetor, matriz, i);
		zerarBaixo(matriz,i);
	}
	for (int i = LIN - 1; i > 0; i--)
	{
		zerarCima(matriz, i, diag);
		diag--;
	}
	for (int i = 0; i < LIN; i++)
	{
		vetorRes[i] = matriz[i][COL - 1] / matriz[i][i];
	}

	mostrarMatriz(matriz);
	cout << endl << endl;

	for (int i = 0; i < LIN; i++)
	{
		cout << "x" << i + 1 << " = " << vetorRes[i]  << "\n";
	}

    return 0;
}

