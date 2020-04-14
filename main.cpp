#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
// #include <SDL2/SDL_ttf.h>
#include <SDL2/SDL2_gfxPrimitives.h>
//#include <SDL2/SDL_mixer.h>
#include "Bird.h"
using namespace std;

int cn=0;//use for random canals
int cn2=0;//use for random day and night

const int SCREEN_WIDTH = 760;
const int SCREEN_HEIGHT = 800;
//renderer
SDL_Renderer *gRenderer = NULL;


//textures
SDL_Texture* gTexture1 = NULL;
SDL_Texture* gbackgroundT = NULL;
SDL_Texture* canal1= NULL;
SDL_Texture* canal2= NULL;
SDL_Texture* canal3= NULL;
SDL_Texture* canal4= NULL;
SDL_Texture* canal5= NULL;

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* canalserface = NULL;

//rects
SDL_Rect grect1;//bird1
SDL_Rect backrect={0,0,2280,800};
SDL_Rect canal1r={760,0,152,655};
SDL_Rect canal2r={760,0,152,655};
SDL_Rect canal3r={760,0,152,655};
SDL_Rect canal4r={760,0,152,655};
SDL_Rect canal5r={760,0,152,655};




//Surface for loading png images (except map)
SDL_Surface* gSurface1 = NULL; //bird1
SDL_Surface* canalsurface= NULL;
SDL_Surface* background=NULL;

//keyboard states
const Uint8 *state = SDL_GetKeyboardState(NULL);

bool init()
{

    //Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow( "Flapy-Bird", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);

		//Initialise SDL_mixer and Music
	
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Get window surface
		    //gScreenSurface = SDL_GetWindowSurface( gWindow );
			if(cn2==1)
			{
				gSurface1 = SDL_LoadBMP("bird1.bmp");
			}
			if(cn2==2)
			{
				gSurface1 = SDL_LoadBMP("soul.bmp");
			}
			
   			gTexture1 = SDL_CreateTextureFromSurface(gRenderer, gSurface1);

			   canalserface = SDL_LoadBMP("canal1.bmp");
   			  canal1 = SDL_CreateTextureFromSurface(gRenderer, canalserface);

			   canalserface = SDL_LoadBMP("canal2.bmp");
   			  canal2 = SDL_CreateTextureFromSurface(gRenderer, canalserface);

			   canalserface = SDL_LoadBMP("canal3.bmp");
   			  canal3 = SDL_CreateTextureFromSurface(gRenderer, canalserface);

			   canalserface = SDL_LoadBMP("canal4.bmp");
   			  canal4 = SDL_CreateTextureFromSurface(gRenderer, canalserface);

			   canalserface = SDL_LoadBMP("canal5.bmp");
   			  canal5 = SDL_CreateTextureFromSurface(gRenderer, canalserface);
    	
	  		bird1.x = 340;
    		bird1.y = 360;
			grect1.x = bird1.x;
			grect1.y = bird1.y;
		}
	}

	return success;
}



void loadMedia(int cn)
{
	//Load random image
	if(cn2==1)
	{
		background = SDL_LoadBMP("daybackground.bmp");
	}
	if(cn2==2)
	{
		background = SDL_LoadBMP("nightbackground.bmp");
	}
  			
   			gbackgroundT = SDL_CreateTextureFromSurface(gRenderer, background);
			// background=SDL_LoadBMP("xborder.bmp");
			// gborderx1 = SDL_CreateTextureFromSurface(gRenderer, background);
			// gborderx2 = SDL_CreateTextureFromSurface(gRenderer, background);
			// background=SDL_LoadBMP("yborder.bmp");
			// gbordery1 = SDL_CreateTextureFromSurface(gRenderer, background);
			// gbordery2 = SDL_CreateTextureFromSurface(gRenderer, background);
 	// if (cn == 1)
    // {

    //     map.wallrecty1.h = 200;
    //     map.wallrecty2.h = 200;

    //     map.wallrecty4.h = 200;
    //     map.wallrecty5.h = 200;
    //     map.wallrecty3.h = 210;

    //     Wallsurface = SDL_LoadBMP("wallx.bmp");
    //     walltexture_x1 = SDL_CreateTextureFromSurface(gRenderer, Wallsurface);
    //     Wallsurface = SDL_LoadBMP("wallx.bmp");
    //     walltexture_x2 = SDL_CreateTextureFromSurface(gRenderer, Wallsurface);

    //     Wallsurface = SDL_LoadBMP("wally.bmp");
    //     walltexture_y1 = SDL_CreateTextureFromSurface(gRenderer, Wallsurface);
    //     Wallsurface = SDL_LoadBMP("wally.bmp");
    //     walltexture_y2 = SDL_CreateTextureFromSurface(gRenderer, Wallsurface);
    //     Wallsurface = SDL_LoadBMP("wally.bmp");
    //     walltexture_y3 = SDL_CreateTextureFromSurface(gRenderer, Wallsurface);
    //     Wallsurface = SDL_LoadBMP("wally.bmp");
    //     walltexture_y4 = SDL_CreateTextureFromSurface(gRenderer, Wallsurface);
    //     Wallsurface = SDL_LoadBMP("wally.bmp");
    //     walltexture_y5 = SDL_CreateTextureFromSurface(gRenderer, Wallsurface);

    //     map.wallrectx1.x = 500;
    //     map.wallrectx1.y = 75;

    //     map.wallrectx2.x = 500;
    //     map.wallrectx2.y = 575;

    //     map.wallrecty1.x = 215;
    //     map.wallrecty1.y = 106.7;

    //     map.wallrecty2.x = 215;
    //     map.wallrecty2.y = 413.4;

    //     map.wallrecty3.x = 605;
    //     map.wallrecty3.y = 255;

    //     map.wallrecty4.x = 995;
    //     map.wallrecty4.y = 106.7;
    //     ;

    //     map.wallrecty5.x = 995;
    //     map.wallrecty5.y = 413.4;
    // }

    // if (cn == 2)
    // {
    //     map.wallrecty1.h = 200;
    //     map.wallrecty2.h = 200;

    //     map.wallrecty4.h = 200;
    //     map.wallrecty5.h = 200;

    //     Wallsurface = SDL_LoadBMP("wally.bmp");
    //     walltexture_y1 = SDL_CreateTextureFromSurface(gRenderer, Wallsurface);
    //     Wallsurface = SDL_LoadBMP("wally.bmp");
    //     walltexture_y2 = SDL_CreateTextureFromSurface(gRenderer, Wallsurface);
    //     Wallsurface = SDL_LoadBMP("wally.bmp");
    //     walltexture_y3 = SDL_CreateTextureFromSurface(gRenderer, Wallsurface);
    //     Wallsurface = SDL_LoadBMP("wally.bmp");
    //     walltexture_y4 = SDL_CreateTextureFromSurface(gRenderer, Wallsurface);
    //     Wallsurface = SDL_LoadBMP("wally.bmp");
    //     walltexture_y5 = SDL_CreateTextureFromSurface(gRenderer, Wallsurface);

    //     map.wallrecty1.x = 267.5;
    //     map.wallrecty1.y = 106.7;

    //     map.wallrecty2.x = 380;
    //     map.wallrecty2.y = 413.4;

    //     map.wallrecty3.x = 605;
    //     map.wallrecty3.y = 106.6;

    //     map.wallrecty4.x = 942.5;
    //     map.wallrecty4.y = 106.7;
    //     ;

    //     map.wallrecty5.x = 830;
    //     map.wallrecty5.y = 413.4;
    // }

    // if (cn == 3)
    // {
    //     Wallsurface = SDL_LoadBMP("wallx.bmp");
    //     walltexture_x1 = SDL_CreateTextureFromSurface(gRenderer, Wallsurface);
    //     Wallsurface = SDL_LoadBMP("wallx.bmp");
    //     walltexture_x2 = SDL_CreateTextureFromSurface(gRenderer, Wallsurface);
    //     Wallsurface = SDL_LoadBMP("wallx.bmp");
    //     walltexture_x3 = SDL_CreateTextureFromSurface(gRenderer, Wallsurface);
    //     Wallsurface = SDL_LoadBMP("wallx.bmp");
    //     walltexture_x4 = SDL_CreateTextureFromSurface(gRenderer, Wallsurface);

    //     Wallsurface = SDL_LoadBMP("wally.bmp");
    //     walltexture_y1 = SDL_CreateTextureFromSurface(gRenderer, Wallsurface);
    //     Wallsurface = SDL_LoadBMP("wally.bmp");
    //     walltexture_y2 = SDL_CreateTextureFromSurface(gRenderer, Wallsurface);

    //     map.wallrectx1.x = 116;
    //     map.wallrectx1.y = 150;

    //     map.wallrectx2.x = 884;
    //     map.wallrectx2.y = 150;

    //     map.wallrectx3.x = 884;
    //     map.wallrectx3.y = 500;

    //     map.wallrectx4.x = 116;
    //     map.wallrectx4.y = 500;

    //     map.wallrecty1.x = 512;
    //     map.wallrecty1.y = 220;

    //     map.wallrecty2.x = 698;
    //     map.wallrecty2.y = 220;
    // }
}


bool start=false;
bool movebird(SDL_Event e, bool *quit)
{
if(start)
{

	if(bird1.speed>-0.4)
	{
		bird1.speed-=bird1.acc;
	}

	
	SDL_PollEvent(&e);
    if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE)
	{
		bird1.speed += 1.3;
	}
        

	

	bird1.y-=bird1.speed;

	

	if (e.type == SDL_QUIT)
    {
        *quit = true;
    }
	
}
else
{
	SDL_PollEvent(&e);
    if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE)
	{
		start=true;
		bird1.speed += 0.9;
	}
}


grect1={bird1.x,bird1.y,60,60};
	return true;
}



// void movecanal(int num,int canal)
// {
// 	float speed=0.001;
// 	switch(num)
// 	{
// 		case 1:
// 		{
// 			int c=canal;
// 			while(canal1r.x>-152)
// 			{
// 				canal1r.x-=speed;
// 			}
// 			canal1r.x=760;
// 			if(c==1)
// 			{
// 				endcanal1=false;
// 			}
// 			else
// 			{
// 				endcanal2=false;
// 			}
			
// 			break;
// 		}
// 		case 2:
// 		{
// 			int c=canal;
// 			while(canal2r.x>-152)
// 			{
// 				canal2r.x-=speed;
// 			}
// 			canal2r.x=760;
// 			if(c==1)
// 			{
// 				endcanal1=false;
// 			}
// 			else
// 			{
// 				endcanal2=false;
// 			}
// 			break;
// 		}
// 		case 3:
// 		{
// 				int c=canal;
// 			while(canal3r.x>-152)
// 			{
// 				canal3r.x-=speed;
// 			}
// 			canal3r.x=760;
// 			if(c==1)
// 			{
// 				endcanal1=false;
// 			}
// 			else
// 			{
// 				endcanal2=false;
// 			}
// 			break;
// 		}
// 		case 4:
// 		{
// 			int c=canal;
// 			while(canal4r.x>-152)
// 			{
// 				canal4r.x-=speed;
// 			}
// 			canal4r.x=760;
// 			if(c==1)
// 			{
// 				endcanal1=false;
// 			}
// 			else
// 			{
// 				endcanal2=false;
// 			}
// 			break;
// 		}
// 		case 5:
// 		{
// 			int c=canal;
// 			while(canal5r.x>-152)
// 			{
// 				canal5r.x-=speed;
// 			}
// 			canal5r.x=760;
// 			if(c==1)
// 			{
// 				endcanal1=false;
// 			}
// 			else
// 			{
// 				endcanal2=false;
// 			}
// 			break;
// 		}

// 	}
// }

bool endcanal1=false;
bool endcanal2=false;
int canalnum=0;

void canal_move()
{
	float speed=1;
	if(cn==1&&!endcanal1)
	{
		
			endcanal1=true;
			canalnum=1;

	}
	if(cn==2&&!endcanal1)
	{
		
			endcanal1=true;
			canalnum=2;
		
	}
	if(cn==3&&!endcanal1)
	{
	
			endcanal1=true;
			canalnum=3;
		
	
	}
	if(cn==4&&!endcanal1)
	{
		
			endcanal1=true;
			canalnum=4;
		
	}
	if(cn==5&&!endcanal1)
	{
		
			endcanal1=true;
			canalnum=5;
		
	}
	if(endcanal1)
	{
		switch (canalnum)
		{
			case 1:
			{
				canal1r.x-=speed;
				if(canal1r.x<-152)
				{
					canal1r.x=760;
					endcanal1=false;
				}

				break;
			}

			case 2:
			{
				canal2r.x-=speed;
				if(canal2r.x<-152)
				{
					canal2r.x=760;
					endcanal1=false;
				}

				break;
			}

			case 3:
			{
				canal3r.x-=speed;
				if(canal3r.x<-152)
				{
					canal3r.x=760;
					endcanal1=false;
				}

				break;
			}


			case 4:
			{
				canal4r.x-=speed;
				if(canal4r.x<-152)
				{
					canal4r.x=760;
					endcanal1=false;
				}

				break;
			}


			case 5:
			{
				canal5r.x-=speed;
				if(canal5r.x<-152)
				{
					canal5r.x=760;
					endcanal1=false;
				}

				break;
			}
			
		}
	}








}





void setcn()
	{
	cn=rand()%5+1;
	}
void setcn2()
	{
	cn2=rand()%2+1;
	}


int main()
{

	 srand(time(0));
    setcn2();
	//Start up SDL and create window   
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//For closing the program
		 
		    bool *quit = new bool;
   			*quit = false;
			SDL_Event e;

			//Load media
			while (!*quit)
			{
				while (SDL_PollEvent(&e) != 0)
				{
					if (e.type == SDL_QUIT)
					{
						*quit = true;
					}
				}
				loadMedia(5);//map.cn);
				//Mix_PlayMusic(gMusic, -1);
				int b=0;//for move ment of back ground
				do
				{
					//grect1 = {bird1.x , bird1.y , 60, 60};
					SDL_RenderCopy(gRenderer, gbackgroundT, NULL, &backrect);
					SDL_RenderCopy(gRenderer, canal1, NULL, &canal1r);
					SDL_RenderCopy(gRenderer, canal2, NULL, &canal2r);
					SDL_RenderCopy(gRenderer, canal3, NULL, &canal3r);
					SDL_RenderCopy(gRenderer, canal4, NULL, &canal4r);
					SDL_RenderCopy(gRenderer, canal5, NULL, &canal5r);


					//movement of back ground
					b++;
					if(b==10)
					{
						backrect.x-=1;
						canal_move();
						setcn();
						
						b=0;
					}
					
					if(backrect.x<-1520)
					{
						backrect.x=0;
					}
					//end of movement of back ground
					

					// SDL_RenderCopy(gRenderer, gborderx1, NULL, &map.borderrectx1);
					// SDL_RenderCopy(gRenderer, gborderx2, NULL, &map.borderrectx2);
					// SDL_RenderCopy(gRenderer, gbordery1, NULL, &map.borderrecty1);
					// SDL_RenderCopy(gRenderer, gbordery2, NULL, &map.borderrecty2);
					// if(map.cn==1)
					// {
					// 	SDL_RenderCopy(gRenderer, walltexture_x1, NULL, &map.wallrectx1);
					// 	SDL_RenderCopy(gRenderer, walltexture_x2, NULL, &map.wallrectx2);
					// 	SDL_RenderCopy(gRenderer, walltexture_y1, NULL, &map.wallrecty1);
					// 	SDL_RenderCopy(gRenderer, walltexture_y2, NULL, &map.wallrecty2);
					// 	SDL_RenderCopy(gRenderer, walltexture_y3, NULL, &map.wallrecty3);
					// 	SDL_RenderCopy(gRenderer, walltexture_y4, NULL, &map.wallrecty4);
					// 	SDL_RenderCopy(gRenderer, walltexture_y5, NULL, &map.wallrecty5);
					// }
					// if(map.cn==2)
					// {
					// 	SDL_RenderCopy(gRenderer, walltexture_x1, NULL, &map.wallrectx1);
					// 	SDL_RenderCopy(gRenderer, walltexture_y1, NULL, &map.wallrecty1);
					// 	SDL_RenderCopy(gRenderer, walltexture_y2, NULL, &map.wallrecty2);
					// 	SDL_RenderCopy(gRenderer, walltexture_y3, NULL, &map.wallrecty3);
					// 	SDL_RenderCopy(gRenderer, walltexture_y4, NULL, &map.wallrecty4);
					// 	SDL_RenderCopy(gRenderer, walltexture_y5, NULL, &map.wallrecty5);
					// }
					// if(map.cn==3)
					// {
					// 	SDL_RenderCopy(gRenderer, walltexture_x1, NULL, &map.wallrectx1);
					// 	SDL_RenderCopy(gRenderer, walltexture_x2, NULL, &map.wallrectx2);
					// 	SDL_RenderCopy(gRenderer, walltexture_x3, NULL, &map.wallrectx3);
					// 	SDL_RenderCopy(gRenderer, walltexture_x4, NULL, &map.wallrectx4);
					// 	SDL_RenderCopy(gRenderer, walltexture_x5, NULL, &map.wallrectx5);
					// 	SDL_RenderCopy(gRenderer, walltexture_x6, NULL, &map.wallrectx6);
					// 	SDL_RenderCopy(gRenderer, walltexture_y1, NULL, &map.wallrecty1);
					// 	SDL_RenderCopy(gRenderer, walltexture_y2, NULL, &map.wallrecty2);
					// }
					
					
					// if (gtank1.lose == false)
					 	//SDL_RenderCopyEx(gRenderer, gTexture1, NULL, &grect1, degree1, NULL, SDL_FLIP_NONE);
						SDL_RenderCopy(gRenderer, gTexture1, NULL, &grect1);
					// if (gtank2.lose == false)
					// 	SDL_RenderCopyEx(gRenderer, gTexture2, NULL, &grect2, degree2, NULL, SDL_FLIP_NONE);
					// if (laserflag == true)
					// 	SDL_RenderCopy(gRenderer, glaser, NULL, &LaserRect);
					// if (EBFlag == true)
					// 	SDL_RenderCopy(gRenderer, ammotexture, NULL, &BulletRect);
					// BulletIcon(lastTimebullet);
					// BICollision();
					// Score();
					// for (int i = 0; i < 6; i++)
					// {
					// 	if (gbullet1[i].value == 1)
					// 		gbullet1[i].move();
					// 	if (gbullet2[i].value == 1)
					// 		gbullet2[i].move();
					// }
					//lose();
					SDL_RenderPresent(gRenderer);
				} while (movebird(e, quit)&& !*quit);//Tank(e, quit) && !*quit);
			}
	}


}