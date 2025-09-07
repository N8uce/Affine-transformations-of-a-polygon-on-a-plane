#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include "task.h"
#include "graphics.h"

Figure::Figure(int n1,double X0,double Y0, Point *xy1)
{
   xy = xy1;
   x0=X0;
   y0=Y0;
   n=n1;
}

Figure::~Figure()
{
   delete [] xy;
}

void Figure::draw()
{
   setfillstyle(SOLID_FILL,COLOR(0,162,232));
   int *p;
   p=new int[2*n];
   for(int j=0,i=0;j<n;i+=2,j++)
   {
      p[i]=xy[j].x;
      p[i+1]=xy[j].y;
   }
   fillpoly(n,p);
   delete [] p;
}

void Figure::shift(int nx,int ny)
{
   
   x0+=nx;
   y0+=ny;
   
   for(int i=0;i<n;i++)
   {
      xy[i].x+=nx;
      xy[i].y+=ny;
   }
   
}

void Figure::ChangeScale(double S)
{
   for(int i=0;i<n;i++)
   {
      xy[i].x=(xy[i].x-x0)*S+x0;
      xy[i].y=(xy[i].y-y0)*S+y0;
   }
}

void Figure::rotate(double phi)
{
   double x1y;
   for(int i=0;i<n;i++)
   {
      x1y=xy[i].x;
      xy[i].x=x0+cos(phi)*(xy[i].x-x0) - (xy[i].y-y0)*sin(phi);
      xy[i].y=y0+sin(phi)*(x1y-x0) + (xy[i].y-y0)*cos(phi);
   }
}

void save()
{
   int width, height;
   IMAGE *output;

   width  = getmaxx()+1 ;
   height = getmaxy()+1 ;
   output = createimage(width, height);

   getimage(0, 0, width - 1, height - 1, output);
   saveBMP("output.bmp", output);
   freeimage(output);
}
