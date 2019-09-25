#include "../header/GestoreSpari.h"

PallinaRana* GestoreSpari::getPallinaRana(int i)
{ 
    return spari[i];
}

void GestoreSpari::inserisciSparo(PallinaRana* sparo)
{
    if(sparo!=nullptr)
        spari.push_back(sparo);
}

Pallina* GestoreSpari::rimuoviPallina(int i) 
{
    if(!(i>0 && i<spari.size()))
        return nullptr;

    Pallina* p = spari[i];
    spari.erase(spari.begin()+i);
    return p;
}

// se la pallina ha lo spazio per essere inserita viene rimossa dagli spari
bool GestoreSpari::collisioneSparo(Serpente& serpy)
{
    bool b = false;
    for(int j=spari.size()-1; j>=0; j--)
        if(serpy.toccaSparo(spari[j], j))
        {    
            spari.erase(spari.begin()+j);
            j=0;
            b = true;
        }
    return b;
}

void GestoreSpari::stampa()
{
    for(auto i:spari)
    {
        i->movimento();
        i->stampa(1);
    }
}

// se uno sparo esce dallo schermo viene eliminato
void GestoreSpari::nelloSchermo(BUFFER& b)
{ 
   for(vector<PallinaRana*>::iterator it = spari.begin(); it!=spari.end(); ++it)
    {
        if(!b.collisione(*it) )
        {
            delete *it;
            it=spari.erase(it);
            break;
        }
    }
}  
    

GestoreSpari::~GestoreSpari()
{
    for(int i=0; i<spari.size(); i++)
        delete spari[i];  
}