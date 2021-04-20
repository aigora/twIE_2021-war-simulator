#include <stdio.h>

//Estructuras:

//Estructura bots:
struct bots{
	char nombre[100]; //Nombre y apellido
	int kills; //Las bajas que lleva. Inicialmente son 0.
};

int menu();

int main()
{
	menu();
}

//EL MENÚ
//la funcion menu imprime el menu y le al jugador opciones a elegir
int menu()
{
	//Aqui iria un logo
	printf("Eliga 1 entre las siguentes opciones(Introduzca el numero): \n");
	int opcion;
	printf("1.Manual simple(Se introducen manualmente los nombre)(todas las rondas se llevan acabo de manera aleatoria) \n");
	printf("2.Automatica simple(Solo introduces un nombre y el resto son puestos por el pc)(todas las rondas se llevan acabo de manera aleatoria)  \n");
	printf("3.Manual complex(Se introducen manualmente los nombre)(El usuario elige en cada ronda que 2 bots se enfrentan) \n");
	printf("4.Automatica complex(Solo introduces un nombre y el resto son puestos por el pc)(El usuario elige en cada ronda que 2 bots se enfrentan)  \n");
	while (true)
	{
		scanf("%i", &opcion);
		switch (opcion)
		{
		//De momento solo imprime el número introducido.
		case 1:
			printf("Has elegido %i \n", opcion);
			return false;
			break;
		case 2:
			printf("Has elegido %i \n", opcion);
			return false;
			break;
		case 3:
			printf("Has elegido %i \n", opcion);
			return false;
			break;
		case 4:
			printf("Has elegido %i \n", opcion);
			return false;
			break;
		default:
			printf("%i", opcion);
			printf(" no es una opcion valida. Recuerda que debes introducir 1,2,3 o 4. \n");
		}
	}
	//devuelve la opcion elegida
	return opcion;
}


