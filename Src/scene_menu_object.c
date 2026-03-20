#define _CRT_SECURE_NO_WARNINGS

#include "scene_menu_object.h"
#include "utility.h"
#include <allegro5/allegro_primitives.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Button button_create(float x, float y, float w, float h, const char* default_image_path, const char* hovered_image_path) {

	Button button;
	memset(&button, 0, sizeof(Button));

	button.default_img = load_bitmap(default_image_path);
	if (hovered_image_path) {
		button.hovered_img = load_bitmap(hovered_image_path);
	}

	if (!button.default_img) {
		game_log("failed loading button image!");
	}

	button.body.x = x;
	button.body.y = y;
	button.body.w = w;
	button.body.h = h;

	return button;
}

void drawButton(Button button) {
	ALLEGRO_BITMAP* _img = button.hovered_img ? 
												button.hovered ? 
													button.hovered_img : 
													button.default_img : 
												button.default_img;
	al_draw_scaled_bitmap(
		_img,
		0, 0,
		al_get_bitmap_width(_img), al_get_bitmap_height(_img),
		button.body.x, button.body.y,
		button.body.w, button.body.h, 0
	);
}

bool buttonHover(Button button, int mouse_x, int mouse_y) {
	// TODO-HACKATHON 3-6: Check if mouse is hovering on the button
	//	Uncomment and fill the code below
	
	return pnt_in_rect(mouse_x, mouse_y, button.body);
	return false;
}

CheckBox checked_box(float x, float y, float w, float h, const char* default_image_path, const char* checked_image_path) {

	CheckBox checkthebox;
	memset(&checkthebox, 0, sizeof(CheckBox));

	checkthebox.default_img = load_bitmap(default_image_path);
	if (checked_image_path) {
		checkthebox.checked_img = load_bitmap(checked_image_path);
	}

	if (!checkthebox.default_img) {
		game_log("failed loading button image!");
	}

	checkthebox.body.x = x;
	checkthebox.body.y = y;
	checkthebox.body.w = w;
	checkthebox.body.h = h;

	checkthebox.checked = false;

	return checkthebox;
}

void drawCheck(CheckBox checkthebox) {
	ALLEGRO_BITMAP* _img = checkthebox.checked_img ?
		checkthebox.checked ?
		checkthebox.checked_img :
		checkthebox.default_img :
		checkthebox.default_img;
	al_draw_scaled_bitmap(
		_img,
		0, 0,
		al_get_bitmap_width(_img), al_get_bitmap_height(_img),
		checkthebox.body.x, checkthebox.body.y,
		checkthebox.body.w, checkthebox.body.h, 0
	);
}

bool checkHover(CheckBox checkthebox, int mouse_x, int mouse_y) {
	return pnt_in_rect(mouse_x, mouse_y,checkthebox.body);
}