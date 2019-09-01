/*
    g++ *.cpp -lallegro -lallegro_image -lallegro_font -lallegro_ttf -lallegro_audio -lallegro_acodec -o Zuma && ./Zuma
*/
#define IMMAGINE_SFONDO "image/Sfondo.jpg"
#include "../header/Sfondo.h"
#include "../header/Livello.h"
#include "../header/Suono.h"
#include <string>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro5.h>

int wGlobal=1024;
int hGlobal=768;

void game()
{
    
    SFONDO sfondo;
    Menu* menu = new Menu();
    Livello* liv = new Livello();
    Suono *music = new Suono();
    int numero = 0;
    int modalita = 0;
    int sceltaLivello = 0;
    music->playMenu();
    
    while(true)
    {
       
        if(modalita == 0)
        {
           
            modalita = menu->menuPricipale(music);
        }   
        else
        {
             
           
            numero = menu->menuLivelli( );
            if(numero == liv->NUM_LIVELLI)
            { 
                modalita = 0;
            }
            else
             { 
                 
                   sceltaLivello = liv->livello_base( music,modalita,numero);
                //liv->nuovoLivello(modalita,numero);
             }
        }

        if(sceltaLivello == 2)
        {
            ((!music->getMenu()&&music->getLivello())?cout<<"ok": cout<<"no");
            if(music->getMenu())
            al_rest(0.5);
            music->playMenu();
            modalita = 0;
            sceltaLivello = 0;
        }
    }
    
    delete menu;
    delete liv;
    delete music;
     
}

int main(int argc, char **argv)
{   
    /* ::wGlobal=100;
    ::hGlobal=100;  */  
    
    if(!al_init())
    {
        cerr << "Failed to initialite allegro - 1";
        return -1;
    }
    
    if(!al_init_image_addon())
    {
        cerr << "Failed to initialite image addon - 2 ";
        return -1;
    }
    if(!al_install_audio()){
      cerr << "failed to initialize audio!\n";
      return -1;
   }

   if(!al_init_acodec_addon()){
      cerr << "failed to initialize audio codecs!\n";
      return -1;
   }
	
   if (!al_reserve_samples(1)){
      cerr << "failed to reserve samples!\n";
      return -1;
   }
    game();
    return 0;
}

