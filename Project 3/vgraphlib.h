#ifndef _VGRAPHLIB_H
#define _VGRAPHLIB_H

//
// Global Constants
//

const int CANVAS_HEIGHT = 40;
const int CANVAS_WIDTH = 50;

//
//Functional Prototypes
//

bool cmd_canvas_setup(int & height, int & width);
bool cmd_pen_selection(char & pen);
bool cmd_draw_vertical_line(char pen, int height);
bool cmd_draw_horizontal_line(char pen, int width);
bool cmd_draw_rectangle(char pen, char type, int height, int width);
bool cmd_draw_right_triangle(char pen, char type, int width);

//
//Custom Function
//

void print_main_menu();
int get_picture_height(int canvas_h);
int get_picture_width(int canvas_w);
char get_picture_type();

#endif // _VGRAPHLIB_H