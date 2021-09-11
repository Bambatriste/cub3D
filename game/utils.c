#include "./headers/cub.h"

void    set_pos_v(t_vector *vector, float x, float y)
{
    vector->x = x;
    vector->y = y;
}

int rgb_to_int(int r, int g, int b)
{
	int rgb;

	rgb = r;
	rgb = (rgb << 8) + g;
	rgb = (rgb << 8) + b;
	return (rgb);
}
