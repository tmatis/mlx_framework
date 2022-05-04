#include "framework/graphic.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct square_s
{
	int x;
	int y;
	struct square_s *next;
} square_t;

typedef struct line_s
{
	int x1;
	int y1;
	int x2;
	int y2;
	struct line_s *next;	
} line_t;

int info_keycode = 0;
int info_mouse_button = 0;
int info_mouse_x = 0;
int info_mouse_y = 0;

square_t *squares = NULL;

line_t *lines = NULL;

int first_point_line_x = -1;
int first_point_line_y = -1;


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
	draw_rectangle(frame, 20, 20, 100, 120, rgb_to_color(30, 30, 30));

	square_t *square = squares;
	while (square)
	{
		draw_rectangle(frame, square->x - 25, square->y - 25, 50, 50, 0xFFFFFF);
		square = square->next;
	}

	line_t *line = lines;
	while (line)
	{
		draw_line(frame, line->x1, line->y1, line->x2, line->y2, 0xFFFFFF);
		line = line->next;
	}
}

/*
** Post frame render est executé apres frame_render et apres que la frame soit affichée
** on peut afficher du texte ici 
*/
void post_frame_render(t_mlx *mlx)
{
	char buffer[300];
	put_string(mlx, 50, 40, 0xFFFFFF, "Infos :");
	sprintf(buffer, "Keycode: %d", info_keycode);
	put_string(mlx, 30, 60, 0xFFFFFF, buffer);
	sprintf(buffer, "Mouse btn: %d", info_mouse_button);
	put_string(mlx, 30, 80, 0xFFFFFF, buffer);
	sprintf(buffer, "Mouse x: %d", info_mouse_x);
	put_string(mlx, 30, 100, 0xFFFFFF, buffer);
	sprintf(buffer, "Mouse y: %d", info_mouse_y);
	put_string(mlx, 30, 120, 0xFFFFFF, buffer);
}

/*
** Key press event est executé lorsque l'on appuie sur une touche
** keycode est le code de la touche
*/
void key_press_event(int keycode)
{
	info_keycode = keycode;

	if (keycode == 99)
	{
		// clear squares
		square_t *square = squares;
		while (square)
		{
			square_t *next = square->next;
			free(square);
			square = next;
		}
		squares = NULL;

		// clear lines
		line_t *line = lines;
		while (line)
		{
			line_t *next = line->next;
			free(line);
			line = next;
		}
		lines = NULL;
	}
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
	info_mouse_button = button;
	info_mouse_x = x;
	info_mouse_y = y;

	if (button == 1)
	{
		square_t *square = malloc(sizeof(square_t));
		if (square == NULL)
			return;
		square->x = x;
		square->y = y;
		square->next = NULL;
		if (squares == NULL)
			squares = square;
		else
		{
			square_t *tmp = squares;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = square;
		}
	}
	else if (button == 3)
	{
		if (first_point_line_x != -1)
		{
			line_t *line = malloc(sizeof(line_t));
			if (line == NULL)
				return;
			line->x1 = first_point_line_x;
			line->y1 = first_point_line_y;
			line->x2 = x;
			line->y2 = y;
			line->next = NULL;
			if (lines == NULL)
				lines = line;
			else
			{
				line_t *tmp = lines;
				while (tmp->next != NULL)
					tmp = tmp->next;
				tmp->next = line;
			}
			first_point_line_x = -1;
		}
		else
		{
			first_point_line_x = x;
			first_point_line_y = y;
		}
	}
}