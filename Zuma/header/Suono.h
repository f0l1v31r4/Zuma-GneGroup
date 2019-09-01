#ifndef SUONO_H
#define SUONO_H

#include <iostream>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

using namespace std;

class Suono
{
    private:
        ALLEGRO_SAMPLE *exit;
        ALLEGRO_SAMPLE *pause;

        ALLEGRO_SAMPLE *menuSound;
        ALLEGRO_SAMPLE_ID IDMenuSound;

        ALLEGRO_SAMPLE *level1Sound;
        ALLEGRO_SAMPLE_ID IDLevel1Sound;

        ALLEGRO_SAMPLE *gameover;
        ALLEGRO_SAMPLE *win;
        ALLEGRO_SAMPLE *coin;
        ALLEGRO_SAMPLE *time;

    protected:
        bool startL1 = true;
        bool isMenu = false;

    public:
        Suono();
        ~Suono();

        bool getLivello();
        bool getMenu();

        void playExit();
        void playPause();
        void playMenu();
        void playLevel1();
        void playGameOver();
        void playWin();
        void playCoin();
        void playTime();
        
        void stopMenu();
        void stopLevel1();
        void stopWin();
        void stopTime();
};
#endif