#include "juego.h"
#include<string>
#include<iostream>
#include<sstream>
#include"enemigo.h"
using namespace sf;
juego::juego(Vector2f resolucion,String titulo)
{
	game_over=false;
	fps=60;
	ventana1=new RenderWindow(VideoMode(resolucion.x,resolucion.y),titulo);
	ventana1->setFramerateLimit(fps);
	
	evento1=new Event;
	carro=new enemigo(25e0,0);
	/*carro =new enemigo;
	carro=new enemigo[4];*/ 
	/*for(int i=0;i<4;i++)
	{
		*(carro+i)=NULL;
	}*/
	cargar_graficos();
	/*reloj1=new Clock;
	tiempo1=new Time;
	tiempo2=0;*/
	gameLoop();
}

void juego::gameLoop()
{
	
	while (!game_over)
	{
		//carro->carro_mov();
		ventana1->clear();
		procesar_evento();
		ventana1->draw(spr_fondo);
		/*for(int i=0;i<4;i++)
		{
			if(carro[i] != NULL)
			{
				ventana1->draw(carro[i]->get_sprite());
			}
		}*/
		
		ventana1->draw(carro->get_sprite());
		ventana1->draw(spr_principal);
	
		ventana1->display();
	}
}

void juego::cargar_graficos()
{
	
	
	txt_fondo.loadFromFile("pista.jpg");
	spr_fondo.setTexture(txt_fondo);
	spr_fondo.setScale((float)ventana1->getSize().x/txt_fondo.getSize().x,(float)ventana1->getSize().y/txt_fondo.getSize().y);
	txt_principal.loadFromFile("coche4.jpg");
	spr_principal.setTexture(txt_principal);
	spr_principal.setPosition(300,500);
	
	spr_principal.setScale(50.f/spr_principal.getTexture()->getSize().x,100.f/spr_principal.getTexture()->getSize().y);
}

void juego::procesar_evento()
{
	while(ventana1->pollEvent(*evento1))
	
	{
		switch(evento1->type)
		{
			case Event::Closed:
			    ventana1->close();
			    exit(1);
			    break;
			case Event::KeyPressed:
				if (Keyboard::isKeyPressed(Keyboard::Up))
				{
					spr_principal.setPosition(spr_principal.getPosition().x,spr_principal.getPosition().y-4);
				}
				
				else if(Keyboard::isKeyPressed(Keyboard::Down))
				{
					spr_principal.setPosition(spr_principal.getPosition().x,spr_principal.getPosition().y+4);
				}
				else if(Keyboard::isKeyPressed(Keyboard::Left))
				{
					spr_principal.setPosition(spr_principal.getPosition().x-4,spr_principal.getPosition().y);
				}
				else if(Keyboard::isKeyPressed(Keyboard::Right))
				{
					spr_principal.setPosition(spr_principal.getPosition().x+4,spr_principal.getPosition().y);
				}
			
				
		}
		
	}
}

bool juego::limite_enemigo(int x, int y)
{
	//if (x>600)
}
