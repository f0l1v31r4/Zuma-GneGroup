#ifndef SCRITTAMENU_H
#define SCRITTAMENU_H
#include "HitBox.h"


class ScrittaMenu : public HitBox
{
    public:
    ScrittaMenu(string _immagine, int _x, int _y, int _scale):HitBox(_immagine,_x,_y,_scale){}


    void reazione()
    {
        if(immagine[6]=='0')
            immagine[6]='1';
        else
            immagine[6]='0';
        
    }    
};
#endif