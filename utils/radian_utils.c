#include "cub3d.h"

float convert_to_radian(float angle)
{
    return (angle * M_PI / 180.0);
}

float convert_to_degree(float radian)
{
    return (radian * 180.0 / M_PI);
}