#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;
 
int main()
{
    
    RenderWindow window(VideoMode(800, 600), "Gear Speed");

    
    Texture texture;
    if (!texture.loadFromFile("images/fondoinicial.jpg")){
	     system("echo No se puedo cargar la textura&pause");
        return EXIT_FAILURE;
    }
    Sprite sprite1(texture);
    Vector2u textureSize= texture.getSize();
    Sprite sprite2(texture, IntRect(textureSize.x* .1, 0,textureSize.x, textureSize.y));

    
    Font font;
    if (!font.loadFromFile("fonts/zrnic___.ttf")){
    	     system("echo No se puedo cargar la fuente&pause");
        return EXIT_FAILURE;
    }
	
	Text *txt_intro;
	txt_intro = new Text();
	txt_intro->setFont(font);
	txt_intro->setString("Presiona Espacio");
	txt_intro->setPosition(400,300);
	txt_intro->setOrigin(txt_intro->getGlobalBounds().width/2, txt_intro->getGlobalBounds().height/2);
	
	Text *jugar;
	jugar = new Text();
	jugar->setFont(font);
	jugar->setString("Jugar");
	jugar->setPosition(400,280);
	jugar->setOrigin(jugar->getGlobalBounds().width/2, jugar->getGlobalBounds().height/2);
				
	Text *personalizar;
	personalizar = new Text();  
	personalizar->setFont(font);
	personalizar->setString("Personalizar");
	personalizar->setPosition(400,320);
	personalizar->setOrigin(personalizar->getGlobalBounds().width/2, personalizar->getGlobalBounds().height/2);
		
	
	 
	Music music;
	if(!music.openFromFile("audio/game audio.ogg")){
	   system("echo no se pudo cargar el audio&pause");	
	   return EXIT_FAILURE;
	}
	
	
	music.play();
	

    // Start the game loop
    while (window.isOpen())
    {
        
		
        Event event;
        while (window.pollEvent(event))
        {
            
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed){
            	if(event.key.code == Keyboard::Space){
					music.play(); 
				}
			}    
        }
        
        
        
        
        window.clear();
        

        
        window.draw(sprite1);
        window.draw(sprite2);


        
        window.draw(*txt_intro);
        if (Keyboard::isKeyPressed(Keyboard::Space)){
        	txt_intro->setPosition(801,601);
        	window.draw(*jugar);
        	window.draw(*personalizar);	
		}

        			
					

       
        window.display();
    }

    return EXIT_SUCCESS;
}
