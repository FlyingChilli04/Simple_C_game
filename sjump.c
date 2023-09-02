#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>

#define GRAVITY 9.8

// square interface
typedef struct {
    float x, y;
} position;

// textures for graphics
typedef struct {
    SDL_Texture* cookie_texture;
    SDL_Texture* background_texture;
    SDL_Texture* game_over_texture;
} texture;

int square(int a) {
    return a * a;
}

void gameOver(SDL_Window *window, SDL_Renderer *renderer, texture *tex) {
    // load the game over image into memory using SDL_image library function
    SDL_Surface* game_over_surface = IMG_Load("resources/GAMEOVER.png");
    if (!game_over_surface) {
        printf("error creating surface\n");
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(1);
    }

    // load the game over image data into the graphics hardware's memory
    tex->game_over_texture = SDL_CreateTextureFromSurface(renderer, game_over_surface);
    SDL_FreeSurface(game_over_surface);
    if (!tex->game_over_texture) {
        printf("error creating game over texture\n");
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(1);
    }

    // show what has been drawn on screen
    SDL_RenderCopy(renderer, tex->game_over_texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}

// Load all game graphics
void loadGame(SDL_Window *window, SDL_Renderer *renderer, texture *tex) {
    // load the cookie image into memory using SDL_image library function
    SDL_Surface* cookie_surface = IMG_Load("resources/cookie.png");
    if (!cookie_surface) {
        printf("error creating surface\n");
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(1);
    }

    // load the cookie image data into the graphics hardware's memory
    tex->cookie_texture = SDL_CreateTextureFromSurface(renderer, cookie_surface);
    SDL_FreeSurface(cookie_surface);
    if (!tex->cookie_texture) {
        printf("error creating cookie texture\n");
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(1);
    }

    // load the background image into memory using SDL_image library function
    SDL_Surface* background_surface = IMG_Load("resources/background.png");
    if (!background_surface) {
        printf("error creating surface\n");
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(1);
    }

    // load the background image data into the graphics hardware's memory
    tex->background_texture = SDL_CreateTextureFromSurface(renderer, background_surface);
    SDL_FreeSurface(background_surface);
    if (!tex->background_texture) {
        printf("error creating background texture\n");
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(1);
    }
}

// processes events from event poll
int processEvents(SDL_Window *window, position *pos, int *jumping, float *counter) {
    SDL_Event event;
    int isRunning = 1;    
    // check for events
    while (SDL_PollEvent(&event))            
        {
        // switch cases for different type of event types (union)
        switch (event.type) 
            {
            case SDL_QUIT:
                isRunning = 0;
            break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) 
                    {
                    case SDLK_SPACE:
                        // when space bar pressed, jump up
                        pos->y -= 100;
                        *jumping = 1;
                    break;
                }
                break;
            case SDL_KEYUP:
                switch (event.key.keysym.sym) 
                    {
                    case SDLK_SPACE:
                        // when space bar released reset jumping variable
                        *jumping = 0;
                        *counter = 0;
                        break;
                }
                break;
        }
    }

    return isRunning;
}

// renders graphics on screen
void doRender(SDL_Renderer *renderer, position *pos, SDL_Texture *cookie_texture, SDL_Texture *background_texture) {
    // set drawing colours to blue
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

    // set the screen blue
    SDL_RenderClear(renderer);

    // create rectangle using rect structure and render fill rect
    SDL_Rect cookie_rect = {pos->x, pos->y, 200, 200};

    // show what has been drawn on screen
    SDL_RenderCopy(renderer, background_texture, NULL, NULL);
    SDL_RenderCopy(renderer, cookie_texture, NULL, &cookie_rect);
    SDL_RenderPresent(renderer);
}


int main(void) 
{
    // declare position struct
    position pos;
    pos.x = 220;
    pos.y = 140;

    // declare texture struct
    texture tex;

    // intitialise SDL library
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0) {
        printf("Error initialising SDL: %s\n", SDL_GetError());
        return 1;
    }

    printf("initialisation successful\n");

    // declare and initialise window and renderer
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    window = SDL_CreateWindow("Jump Square",
                                    SDL_WINDOWPOS_CENTERED,
                                    SDL_WINDOWPOS_CENTERED,
                                    640, 480, 0);
    
    if (!window) {
        printf("error creating window: %s/n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (!renderer) {
        printf("error creating renderer: %s/n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Load all graphics into screen
    loadGame(window, renderer, &tex);

    int isRunning = 1;
    float counter = 0;
    int game_over_flag = 0;

    // event loop
    while (isRunning == 1) 
        {
        int jumping = 0;
        // apply gravity
        if (jumping == 0) {
            counter += 1 / 60.0;
        }
        float temp_y = (10.0) * (counter) + (0.5) * GRAVITY * square(counter);
        pos.y += temp_y;

        // check for events
        isRunning = processEvents(window, &pos, &jumping, &counter);

        // collision detection
        if (pos.y <= 0) {
            pos.y = 0;
        } 

        if (pos.y >= 480 - 200) {
            // pos.y = 480 - 200;
            gameOver(window, renderer, &tex);
            SDL_DestroyTexture(tex.cookie_texture);
            SDL_DestroyTexture(tex.background_texture);
            game_over_flag = 1;
        }

        // render display
        if (game_over_flag == 0) {
            doRender(renderer, &pos, tex.cookie_texture, tex.background_texture);
        }
    }    

    // clear up resources
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(tex.game_over_texture);
    SDL_Quit();

    return 0;
}