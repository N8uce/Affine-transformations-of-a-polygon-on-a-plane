#include <iostream>
#include <fstream>
#define _USE_MATH_DEFINES
#include <cmath>
#include "control.h"
#include "task.h"
#include "graphics.h"

using namespace std;

void create_int()
{
   setfillstyle(SOLID_FILL,BLACK);
   bar(0,600,800,800);
   create_control(UP,350,600,"u.bmp");
   create_control(DOWN,350,700,"d.bmp");
   create_control(RIGHT,450,650,"r.bmp");
   create_control(LEFT,250,650,"l.bmp");
   create_control(L_ROT,300,600,"lrot.bmp");
   create_control(R_ROT,450,600,"rrot.bmp");
   create_control(SCALE_UP,450,750,"scale+.bmp");
   create_control(SCALE_D,300,750,"scale-.bmp");
   create_control(SAVE,700,600,"save.bmp");
   create_control(EXIT,750,600,"exit.bmp");
   line(0,600,800,600);
}

int main()
{
   initwindow(800, 800);
   
   Point *xy;
   ifstream input("figure.txt");
   int k = 0;
   double ch;
   while (input >> ch)
            k++;
    input.close();
   
    xy = new Point [k];
    ifstream file("figure.txt");
   
    for(int i=0; i<k/2; i++) 
    file>>xy[i].x;
   
    file.seekg(0,ios_base::cur);
   
    for(int i=0; i<k/2; i++) 
    file>>xy[i].y;
   
    file.close();
 

   Figure hexagon(k/2,125,100,xy);
   
   create_int();

  while (1)
   {
     swapbuffers();
     clearviewport();
     hexagon.draw();
      if(mousebuttons())
      {
         switch(select_control())
         {
            case NONE:break;
            case UP:hexagon.shift(0,-15);break;
            case DOWN: hexagon.shift(0,15); break;
            case RIGHT: hexagon.shift(15,0); break;
            case LEFT:hexagon.shift(-15,0); break;
            case L_ROT: hexagon.rotate(-M_PI/6);break;
            case R_ROT: hexagon.rotate(M_PI/6);break;
            case SCALE_UP:hexagon.ChangeScale(1.5);break;
            case SCALE_D:hexagon.ChangeScale(0.5);break;
            case SAVE:save();break;
            case EXIT:closegraph();return 0;
         }
      }
   delay(1);
   create_int();
   }
  delete[]xy;
  
}