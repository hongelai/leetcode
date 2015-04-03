#include <iostream>
using namespace std;
 
enum genre_e{ROCK,POP, REGGAE, INVALID};
 
/*Base Class*/
class Music {
public:
 virtual void song() = 0;
};
 
/*Derived class Rock from Music*/
class Rock: public Music
{
public:
 void song()
 {
  cout<<"Nirvana: Smells like a teen spirit\n";
 }
};
 
/*Derived class Pop from Music*/
class Pop: public Music
{
public:
 void song()
 {
  cout<<"Michael Jackson: Billie Jean\n";
 }
};
 
/*Derived class Reggae from Music*/
class Reggae: public Music
{
public:
 void song()
 {
  cout<<"Bob Marley: No woman, No cry\n";
 }
};
 
/*Factory Class*/
class MusicFactory
{
public:
 /*Factory Method*/
 Music *getMusic(genre_e genre)
 {
  Music *music = NULL;
 
  /*Logic based on Genre*/
  switch(genre)
  {
  case ROCK:
   music = new Rock();
   break;
  case POP:
   music = new Pop();
   break;
  case REGGAE:
   music = new Reggae();
   break;
  default:
   music = NULL;
   break;
  }
  return music;
 }
};
 
int main()
{
 /*Create factory*/
 MusicFactory *musicFactory = new MusicFactory();
 
 /*Factory instantiating an object of type ROCK*/
 Music *music = musicFactory->getMusic(ROCK);
 
 cout<<"Song: ";
 if(music)
  music->song();
 else
  cout<<"Wrong selection dude/dudette !!";
}