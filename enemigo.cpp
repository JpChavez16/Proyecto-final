#include "enemigo.h"
#include<stdlib.h>
#include<string>
#include<iostream>
#include<sstream>
#include<SFML\Graphics.hpp>
enemigo::enemigo(int x,int y)
{
	this->posicion_x = x;
	this->posicion_y= y;
	//int num_enemigo,coches;
	//carro_mov();
	/*std::string path,result;
	std::stringstream convert;
	num_enemigo=rand()%4+1;
	coches=num_enemigo;
	convert<<coches;
	result=convert.str();
	path="coche"+ result+".jpg";*/
	
	/*
	txt_carro.loadFromFile("coche4.jpg");
	spr_carro.setTexture(txt_carro);
	spr_carro.setPosition(400,100);
	spr_carro.setScale(50.f/spr_carro.getTexture()->getSize().x,100.f/spr_carro.getTexture()->getSize().y);
*/
    carro_mov();
    
}


Sprite enemigo::get_sprite()
{
	this->carro_mov();
	return spr_carro;
}

void enemigo::carro_mov()
{
	txt_carro.loadFromFile("coche1.jpg");
	spr_carro.setTexture(txt_carro);
	spr_carro.setPosition(this->posicion_x,this->posicion_y);
	spr_carro.setScale(50.f/spr_carro.getTexture()->getSize().x,100.f/spr_carro.getTexture()->getSize().y);
    carro_abajo();
	
}
void enemigo::carro_abajo()
{
	this->posicion_y=this->posicion_y+1;
	if(this->posicion_y==500)
	{
		this->posicion_y=0;
	}
}

void enemigo::actualizar_pos(int x, int y)
{
	this->posicion_x = x;
	this->posicion_y= y;
}


