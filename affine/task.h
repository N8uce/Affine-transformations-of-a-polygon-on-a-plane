#ifndef TASK_H
#define TASK_H

struct Point
{
double x,y;
};

class Figure
{
   int n;
   Point *xy;
   double x0,y0;
   public:
   Figure(int,double,double,Point *xy);
   ~Figure();
   void draw();
   void shift(int,int);
   void ChangeScale(double);
   void rotate(double);
};

void save();
#endif