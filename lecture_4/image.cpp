#include <iostream>

class Image {
    int * img;
    int mx, int my;
    public:
        Image(int tmx, int tmy): mx(tmx), my(tmy) 
		{
            img = new int[mx * my]();
        }
    vitual~Image();
    int get(int x, int y) 
	{
        return img[y * my + x];
    }
    int set(int x, int y, int color) 
	{
        img[y * my + x] = color;
    }
    Image operator = (const Image & v)
};

int maint() 
{

}
