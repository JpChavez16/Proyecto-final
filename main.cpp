#include"juego.h"

int main()
{
	srand(time(NULL));
	Vector2f resol;
	resol.x=800;
	resol.y=600;
	juego partida1(resol,"Juego_carrera");
	return 0;
}
