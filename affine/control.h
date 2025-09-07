#ifndef CONTROL_H
#define CONTROL_H

enum control_values { NONE = -1,UP,DOWN,RIGHT,LEFT,
   L_ROT,R_ROT,SCALE_UP,SCALE_D,SAVE,EXIT,N_CONTROLS };

struct Control
{
   int left;
   int top;
   int right;
   int bottom;
};
void create_control(int, int, int, const char *);
int select_control();

#endif