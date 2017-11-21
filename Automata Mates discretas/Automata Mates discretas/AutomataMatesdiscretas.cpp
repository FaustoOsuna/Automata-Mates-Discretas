// Tamagotchi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

enum State { FELIZ, HAMBRIENTO, ABURRIDO, TRISTE, MUERTO };
enum Sigma { JUGAR, ALIMENTAR, ACARICIAR, TIEMPO };

int Vitalidad = 100;
int Stamina = 100;
int Felicidad = 100;
int Minimo(int a, int b)
{
	return a < b ? a : b;
}


State Delta(State s, Sigma a)
{
	State Siguiente = s;
	switch (s)
	{
	case FELIZ:
		switch (a)
		{
		case JUGAR:
			Vitalidad -= 5;
			Stamina -= 10;
			Felicidad += 2;
			if (Stamina == 0) Felicidad -= 10;
			if (Vitalidad < 20) Siguiente = HAMBRIENTO;
			if (Felicidad > 150) Siguiente = MUERTO;
			break;
		case ALIMENTAR:
			Vitalidad -= 2;
			Felicidad += 2;
			Stamina -= 2;
			if (Felicidad > 150) Siguiente = MUERTO;
			if (Vitalidad > 150) Siguiente = MUERTO;
			if (Stamina == 0) Siguiente = MUERTO;
			break;
		case ACARICIAR:
			Stamina += 2;
			Felicidad += 5;

		case TIEMPO:
			Vitalidad -= 1;
			Stamina = Minimo(100, Stamina + 1);
			Felicidad -= 1;
			if (Felicidad < 50) Siguiente = ABURRIDO;
			if (Vitalidad == 0)Siguiente = MUERTO;
			break;
		}
		break;
	case HAMBRIENTO:
		switch (a)
		{
		case JUGAR:
		case ALIMENTAR:
		case ACARICIAR:
		case TIEMPO:
		}
		break;
	case TRISTE:
		switch (a)
		{
		case JUGAR:
		case ALIMENTAR:
		case ACARICIAR:
		case TIEMPO:
		}
		break;
	case MUERTO:
		switch (a)
		{
		case JUGAR:
		case ALIMENTAR:
		case ACARICIAR:
		case TIEMPO:
		}
		break;


	}

	return Siguiente;

}



void PrintState(State s)
{

	switch (s)
	{
	case FELIZ:
		printf(":)");
		break;
	case TRISTE:
		printf(":(");
		break;
	case ABURRIDO:
		printf(":/");
		break;
	case MUERTO:
		printf("X.X   ded");
		break;
	case HAMBRIENTO:
		printf("Hammmbrreee");
		break;



	}
	printf("    Vitalidad:%d,Stamina:%d,Felicidad:%d",
		Vitalidad, Stamina, Felicidad);

}

#include <conio.h>}
#include <Windows.h>


int main()
{
	State s = FELIZ;
	int nCounter = 10;
	while (1)
	{
		PrintState(s);
		if (!_kbhit())
		{
			Sleep(100);
			if (!nCounter--)
			{
				s = Delta(s, TIEMPO);
				nCounter = 10;
			}
		}
		else
		{
			int c = _getch();
			switch (c)
			{
			case 'J':
				s = Delta(s, JUGAR);
			}

		}
	}



	return 0;
}

