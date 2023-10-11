#include <iostream>
#include <vector>
#include "SDL.h"

struct MyRect : SDL_Rect
{
    int mid{0};
    int item_row{0};
    int item_column{0};
    std::string alignment{"centre"};
    std::vector<SDL_Rect> items{};
};

// initialise with what we need
void setMyRect(
MyRect &r, int x, int y, int w, int h)
{
	r.x = x; r.y = y; r.w = w; r.h = h;
	r.mid = r.w/2;
}

int findItems(const MyRect r)
{
    return r.items.size();
}

void makeChildRect(
MyRect parent,
MyRect &child)
{
	child.x = parent.mid;
	child.y = parent.mid;
	child.w = parent.w/2;
	child.h = parent.h/2;
}

int main(int argc, char *argv[])
{
	std::cout << "running...";
	
	SDL_Init(SDL_INIT_VIDEO);
	
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	
	SDL_CreateWindowAndRenderer(
	    640, 480,
	    0,
	    &window,
	    &renderer);
	    
	int screen_width{0};
	int screen_height{0};
	SDL_GetRendererOutputSize(
	    renderer,
	    &screen_width,
	    &screen_height);
	    
	SDL_SetRenderDrawColor(
	    renderer,
	    0,255,0,255);
	SDL_RenderClear(renderer);
	
	MyRect screenRect{};
	setMyRect(
	    screenRect,
	    0,0,screen_width,screen_height);
	
	// parent
	
	SDL_SetRenderDrawColor(
	    renderer,
	    150,50,150,255);
	SDL_RenderFillRect(
	    renderer,
	    &screenRect);

	// child
	MyRect child{};
	makeChildRect(screenRect, child);

	SDL_SetRenderDrawColor(renderer,
		255, 120, 0, 255);
	SDL_RenderFillRect(renderer,
		&child);
	
	SDL_RenderPresent(renderer);
	
	bool running{true};
	while(running)
	{
	    SDL_Event event{};
	    while(SDL_PollEvent(&event))
	    {
	        switch(event.type)
	        {
	            case SDL_FINGERDOWN:
				case SDL_MOUSEBUTTONDOWN:
				case SDL_QUIT:
	            {
	                running = false;
	            }
	        }
	    }
	}
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

    return 0;
}

/*
  *
  * how would i query a MyRect?
  * does it have a vertical layout or horizontal?
  * and where would i set that?
  *
  * somehow i need the left/right limits
  * but at the same time measure the said
  * box's dimensions
  * findLimit("right", rect.w, rect.x)
  *
  * and then find all the details like midpoint
  * and x/y
  *
  * SmallRect needs BossRect to find the mid
  * ONSCREEN
  *
  * initialise - create - get - set - clear - draw
*/

/*
	we could get how many items in a row
	but we wouldnt have the sizes.
	
	how to call and set items?
*/

/*

struct MyRect : SDL_Rect
{
    int mid{0};
    int item_row{0};
    int item_column{0};
    std::string alignment{"centre"};
    std::vector<SDL_Rect> items{};
};

// initialise with what we need
void setMyRect(
MyRect &r, int x, int y, int w, int h)
{
	r.x = x; r.y = y; r.w = w; r.h = h;
	r.mid = r.w/2;
}

int findItems(const MyRect r)
{
    return r.items.size();
}

int main(int argc, char *argv[])
{
	SDL_Init(SDL_INIT_VIDEO);
	
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	
	SDL_CreateWindowAndRenderer(
	    760, 1600,
	    SDL_WINDOW_FULLSCREEN,
	    &window,
	    &renderer);
	    
	int screen_width{0};
	int screen_height{0};
	SDL_GetRendererOutputSize(
	    renderer,
	    &screen_width,
	    &screen_height);
	    
	SDL_SetRenderDrawColor(
	    renderer,
	    0,255,0,255);
	SDL_RenderClear(renderer);
	
	MyRect screenRect{};
	setMyRect(
	    screenRect,
	    0,0,screen_width,screen_height);
	
	SDL_SetRenderDrawColor(
	    renderer,
	    150,50,150,255);
	SDL_RenderFillRect(
	    renderer,
	    &screenRect);
	
	SDL_RenderPresent(renderer);
	
	bool running{true};
	while(running)
	{
	    SDL_Event event{};
	    while(SDL_PollEvent(&event))
	    {
	        switch(event.type)
	        {
	            case SDL_FINGERDOWN:
	            {
	                running = false;
	            }
	        }
	    }
	}
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
*/