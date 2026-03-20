// TODO-HACKATHON 3-9: Create scene_settings.h and scene_settings.c.
// No need to do anything for this part. We've already done it for
// you, so this 2 files is like the default scene template.
#include "scene_settings.h"
#include "scene_menu_object.h"
#include "scene_game.h"

// Variables and functions with 'static' prefix at the top level of a
// source file is only accessible in that file ("file scope", also
// known as "internal linkage"). If other files has the same variable
// name, they'll be different variables.

/* Define your static vars / function prototypes below. */

// TODO-IF: More variables and functions that will only be accessed
// inside this scene. They should all have the 'static' prefix.

static Button yellow_icon;
static Button red_icon;
static Button blue_icon;
static Button green_icon;

static Button up_icon;
static Button down_icon;
static Button left_icon;
static Button right_icon;

static CheckBox check_box1;
static CheckBox check_box2;
static CheckBox check_box3;
static CheckBox check_box4;
static Button mapone;
static Button maptwo;
static Button mapthree;
static Button mapfour;

static Button drop_menu;
static Button back_ground1;
static Button back_ground2;
static Button back_ground3;

bool changeCtrlup = false;
bool changeCtrldown = false;
bool changeCtrlright = false;
bool changeCtrlleft = false;

bool click = false; 
int pickbg;

static void draw(void ){
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 255),
		SCREEN_W/2,
		SCREEN_H - 150,
		ALLEGRO_ALIGN_CENTER,
		"<ENTER> Back to menu"
	);
	drawButton(yellow_icon);
	drawButton(blue_icon);
	drawButton(red_icon);
	drawButton(green_icon);

	drawButton(up_icon);
	drawButton(down_icon);
	drawButton(left_icon);
	drawButton(right_icon);

	drawCheck(check_box1);
	drawCheck(check_box2);
	drawCheck(check_box3);
	drawCheck(check_box4);
	drawButton(mapone);
	drawButton(maptwo);
	drawButton(mapthree);
	drawButton(mapfour);

	drawButton(drop_menu);
	if (click == true) {
		drawButton(back_ground1);
		drawButton(back_ground2);
		drawButton(back_ground3);
	}
}

static void on_key_down(int keycode) {
	switch (keycode) {
		case ALLEGRO_KEY_ENTER:
			game_change_scene(scene_menu_create());
			break;
		default:
			if (changeCtrlup) {
				change_controls(0, keycode);
				changeCtrlup = false;
			}
			else if (changeCtrldown) {
				change_controls(1, keycode);
				changeCtrldown = false;
			}
			else if (changeCtrlleft) {
				change_controls(2, keycode);
				changeCtrlleft = false;
			}
			else if (changeCtrlright) {
				change_controls(3, keycode);
				changeCtrlright = false;
			}
			break;
	}
}

static void on_mouse_move(int a, int mouse_x, int mouse_y, int f) 
{
	yellow_icon.hovered = buttonHover(yellow_icon, mouse_x, mouse_y);
	blue_icon.hovered = buttonHover(blue_icon, mouse_x, mouse_y);
	red_icon.hovered = buttonHover(red_icon, mouse_x, mouse_y);
	green_icon.hovered = buttonHover(green_icon, mouse_x, mouse_y);

	up_icon.hovered = buttonHover(up_icon, mouse_x, mouse_y);
	down_icon.hovered = buttonHover(down_icon, mouse_x, mouse_y);
	left_icon.hovered = buttonHover(left_icon, mouse_x, mouse_y);
	right_icon.hovered = buttonHover(right_icon, mouse_x, mouse_y);

	check_box1.hovered = checkHover(check_box1, mouse_x, mouse_y);
	check_box2.hovered = checkHover(check_box2, mouse_x, mouse_y);
	check_box3.hovered = checkHover(check_box3, mouse_x, mouse_y);
	check_box4.hovered = checkHover(check_box4, mouse_x, mouse_y);
	
	drop_menu.hovered = buttonHover(drop_menu, mouse_x, mouse_y);
	back_ground1.hovered = buttonHover(back_ground1, mouse_x, mouse_y);
	back_ground2.hovered = buttonHover(back_ground2, mouse_x, mouse_y);
	back_ground3.hovered = buttonHover(back_ground3, mouse_x, mouse_y);
}

static void on_mouse_down() {
	if (yellow_icon.hovered)
		change_color("Assets/pacman_move.png", "Assets/pacman_die.png");
	else if (blue_icon.hovered)
		change_color("Assets/pacman_move_blue.png", "Assets/pacman_die.png");
	else if (red_icon.hovered)
		change_color("Assets/pacman_move_red.png", "Assets/pacman_die.png");
	else if (green_icon.hovered)
		change_color("Assets/pacman_move_green.png", "Assets/pacman_die.png");

	else if (up_icon.hovered) {
		changeCtrlup = true;
		changeCtrldown = false;
		changeCtrlright = false;
		changeCtrlleft = false;
		change_map("Assets/map_nthu.txt");
	}
	else if (down_icon.hovered) {
		changeCtrlup = false;
		changeCtrldown = true;
		changeCtrlright = false;
		changeCtrlleft = false;
		change_map("Assets/map_nthu.txt");
	}
	else if (left_icon.hovered) {
		changeCtrlup = false;
		changeCtrldown = false;
		changeCtrlright = false;
		changeCtrlleft = true;
	}
	else if (right_icon.hovered) {
		changeCtrlup = false;
		changeCtrldown = false;
		changeCtrlright = true;
		changeCtrlleft = false;
	}

	else if (check_box1.hovered && !check_box1.checked) {
		check_box1.checked = true;
		check_box2.checked = false;
		check_box3.checked = false;
		check_box4.checked = false;
	}
	else if (check_box2.hovered && !check_box2.checked) {
		check_box2.checked = true;
		check_box1.checked = false;
		check_box3.checked = false;
		check_box4.checked = false;
		change_map("Assets/map_1.txt");
	}
	else if (check_box3.hovered && !check_box3.checked) {
		check_box3.checked = true;
		check_box2.checked = false;
		check_box1.checked = false;
		check_box4.checked = false;
		change_map("Assets/map_2.txt");
	}
	else if (check_box4.hovered && !check_box4.checked) {
		check_box4.checked = true;
		check_box3.checked = false;
		check_box2.checked = false;
		check_box1.checked = false;
		change_map("Assets/map_3.txt");
	}

	else if (drop_menu.hovered) {
		click = true;
	} 

	else if (back_ground1.hovered) {
		pickbg = 1;
	}
	else if (back_ground2.hovered) {
		pickbg = 2;
	}

	else if (back_ground3.hovered) {
		pickbg = 3;
	}
}

// The only function that is shared across files.
Scene scene_settings_create(void) {
	Scene scene;
	memset(&scene, 0, sizeof(Scene));
	scene.name = "Settings";
	scene.draw = &draw;
	scene.on_key_down = &on_key_down;
	// TODO-IF: Register more event callback functions such as keyboard, mouse, ...
	scene.on_mouse_move = &on_mouse_move;
	scene.on_mouse_down = &on_mouse_down;

	game_log("Settings scene created");
	yellow_icon = button_create(30, 20, 100, 100, "Assets/button_yellow.png", "Assets/button_yellow_select.png");
	blue_icon = button_create(30, 120, 100, 100, "Assets/button_blue.png", "Assets/button_blue_select.png");
	red_icon = button_create(30, 220, 100, 100, "Assets/button_red.png", "Assets/button_red_select.png");
	green_icon = button_create(30, 320, 100, 100, "Assets/button_green.png", "Assets/button_green_select.png");

	up_icon = button_create(200, 440, 100, 100, "Assets/upkey.png", "Assets/upkeyselect.png");
	down_icon = button_create(201, 540, 100, 100, "Assets/downkey.png", "Assets/downkeyselect.png");
	left_icon = button_create(102, 490, 100, 100, "Assets/leftkey.png", "Assets/leftkeyselect.png");
	right_icon = button_create(298, 490, 100, 100, "Assets/rightkey.png", "Assets/rightkeyselect.png");

	check_box1 = checked_box(150, 20, 100, 100, "Assets/checkbox.png", "Assets/check.png");
	check_box2 = checked_box(150, 120, 100, 100, "Assets/checkbox.png", "Assets/check.png");
	check_box3 = checked_box(150, 220, 100, 100, "Assets/checkbox.png", "Assets/check.png");
	check_box4 = checked_box(150, 320, 100, 100, "Assets/checkbox.png", "Assets/check.png");
	mapone = button_create(250, 20, 100, 100, "Assets/map1.png", "Assets/map1.png");
	maptwo = button_create(250, 120, 100, 100, "Assets/map2.png", "Assets/map2.png");
	mapthree = button_create(250, 220, 100, 100, "Assets/map3.png", "Assets/map3.png");
	mapfour = button_create(250, 320, 100, 100, "Assets/map4.png", "Assets/map4.png");

	drop_menu = button_create(400, 20, 300, 51, "Assets/dropmenu.png", "Assets/dropmenu_select.png");
	back_ground1 = button_create(400, 60, 300, 50, "Assets/volcano.png", "Assets/volcano_select.png");
	back_ground2 = button_create(400, 110, 300, 50, "Assets/forest.png", "Assets/forest_select.png");
	back_ground3 = button_create(400, 161, 300, 50, "Assets/winter.png", "Assets/winter_select.png");

	return scene;
}

// TODO-Graphical_Widget:
// Just suggestions, you can create your own usage.
	// Selecting BGM:
	// 1. Declare global variables for storing the BGM. (see `shared.h`, `shared.c`)
	// 2. Load the BGM in `shared.c`.
	// 3. Create dropdown menu for selecting BGM in setting scene, involving `scene_settings.c` and `scene_setting.h.
	// 4. Switch and play the BGM if the corresponding option is selected.

	// Adjusting Volume:
	// 1. Declare global variables for storing the volume. (see `shared.h`, `shared.c`)
	// 2. Create a slider for adjusting volume in setting scene, involving `scene_settings.c` and `scene_setting.h.
		// 2.1. You may use checkbox to switch between mute and unmute.
	// 3. Adjust the volume and play when the button is pressed.

	// Selecting Map:
	// 1. Preload the map to `shared.c`.
	// 2. Create buttons(or dropdown menu) for selecting map in setting scene, involving `scene_settings.c` and `scene_setting.h.
		// 2.1. For player experience, you may also create another scene between menu scene and game scene for selecting map.
	// 3. Create buttons(or dropdown menu) for selecting map in setting scene, involving `scene_settings.c` and `scene_setting.h.
	// 4. Switch and draw the map if the corresponding option is selected.
		// 4.1. Suggestions: You may use `al_draw_bitmap` to draw the map for previewing. 
							// But the map is too large to be drawn in original size. 
							// You might want to modify the function to allow scaling.