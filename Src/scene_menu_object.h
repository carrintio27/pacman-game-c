#ifndef MENU_OBJECT_H
#define MENU_OBJECT_H

#include "utility.h"
#include "shared.h"
#include "game.h"

typedef struct Button {
	RecArea body;
	ALLEGRO_BITMAP* default_img;
	ALLEGRO_BITMAP* hovered_img;
	bool hovered;
}Button;

typedef struct CheckBox {
	RecArea body;
	ALLEGRO_BITMAP* default_img;
	ALLEGRO_BITMAP* checked_img;
	bool checked;
	bool hovered;
}CheckBox;

Button button_create(float, float, float, float, const char*, const char*);
void drawButton(Button button);
bool buttonHover(Button, int, int);

CheckBox checked_box(float, float, float, float, const char*, const char*);
void drawCheck(CheckBox checkthebox);
bool checkHover(CheckBox, int, int);
#endif
