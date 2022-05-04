#include "framework/graphic.h"
#include <stdio.h>
#include <stdlib.h>

/*
** desciption des fonctions du framework
** int rgb_to_color(int r, int g, int b);
**     description: convertit rgb en couleur
**     paramètre: r, g, b: valeur de 0 à 255, correspondant à la couleur
**     retour: la couleur en int
**     exemple: rgb_to_color(255, 0, 0) retourne 0xFF0000
**
** void frame_put_pixel(t_frame *f, int x, int y, int color)
**     description: place un pixel dans la frame
**     paramètre: f: la frame, x, y: coordonnées du pixel, color: la couleur
**     retour: rien
**     exemple: frame_put_pixel(frame, 10, 10, 0xFF0000) place un pixel rouge à la position (10;10)
**
** void draw_rectangle(t_frame *f, int x, int y, int w, int h, int color)
**     description: dessine un rectangle
**     paramètre: f: la frame, x, y: coordonnées du coin supérieur gauche,
**					w, h: largeur et hauteur, color: la couleur
**     retour: rien
**     exemple: draw_rectangle(frame, 10, 10, 10, 10, 0xFF0000) dessine un rectangle rouge à la position (10;10)
**
** void draw_line(t_frame *f, int x0, int y0, int x1, int y1, int color)
**     description: dessine une ligne
**     paramètre: f: la frame, x0, y0: coordonnées du premier point,
**					x1, y1: coordonnées du deuxième point,
**					color: la couleur
**     retour: rien
**     exemple: draw_line(frame, 10, 10, 20, 20, 0xFF0000) dessine une ligne de couleur rouge entre les points (10;10) et (20;20)
**
** void put_string(t_mlx *mlx, int x, int y, int color, char *string)
**     description: place une chaine de caractère, s'utilise dans post_frame_render
**     paramètre: mlx: la structure mlx, x, y: coordonnées du premier caractère,
**					color: la couleur, string: la chaine de caractère
**     retour: rien
**     exemple: put_string(mlx, 10, 10, 0xFF0000, "Hello world") place la chaine "Hello world" à la position (10;10)
*/

/*
** Frame render est executé à chaque frame
** c'est là que l'on peut faire tout ce qui est nécessaire à la frame
*/
void frame_render(t_frame *frame)
{
	draw_rectangle(frame, 0, 0, frame->x, frame->y, 0x000000);
	draw_rectangle(frame, 30, 30, 70, 70, rgb_to_color(255, 0, 255));
	draw_line(frame, 0, 0, frame->x, frame->y, rgb_to_color(255, 255, 0));
	draw_line(frame, 0, frame->y, frame->x, 0, rgb_to_color(0, 255, 255));
}

/*
** Post frame render est executé apres frame_render et apres que la frame soit affichée
** on peut afficher du texte ici 
*/
void post_frame_render(t_mlx *mlx)
{
	put_string(mlx, 50, 40, 0xFFFFFF, "Hello world");
}

/*
** Key press event est executé lorsque l'on appuie sur une touche
** keycode est le code de la touche
*/
void key_press_event(int keycode)
{
	(void)keycode;
}

/*
** Key release event est executé lorsque l'on relache une touche
** keycode est le code de la touche
*/
void key_release_event(int keycode)
{
	(void)keycode;
}

/*
** Mouse click event est executé lorsque l'on clique sur la souris
** int button : 1 = gauche, 2 = milieu, 3 = droit, 4 = scroll up, 5 = scroll down
** int x : position x de la souris
*/
void mouse_click_event(int button, int x, int y)
{
	(void)button;
	(void)x;
	(void)y;
}