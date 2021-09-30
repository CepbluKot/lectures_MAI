#include <iostream>
#include <exception>
#include <stdexcept>

class Image {
	private:
		
    int * img;
    int mx;
	int my;
    
    public:

        Image(int tmx, int tmy): mx(tmx), my(tmy) 
		{
            img = new int[mx * my]();
        }
        
    virtual ~Image()
    {
    	delete[] img;
	}
    
    int get(int x, int y) 
	{
		try
		{	
        	return img[y * my + x];
    	}
    	catch(int error)
    	{
    		std::cout<<error;
		}
    }
    
    int set(int x, int y, int color) 
	{
        img[y * my + x] = color;
    }
    
    Image operator = (const Image & v);
};



int main() 
{

}
