#include "main.h"


int main()
{
    bool run =1;
    if(SDL_Init(SDL_INIT_EVERYTHING)) cout<<"Error with init SDL, Error: " << SDL_GetError()<< endl;
    if(TTF_Init()) cout<<"Error with font init" << SDL_GetError()<<endl;
   
    Window* window = new Window("Pong", SIZEX, SIZEY);

    Player* left = new Player(Vec2(50, (SIZEY /2 - PLAYER_HEIGHT /2)));
    Player* right = new Player(Vec2(SIZEX - 50, (SIZEY /2 - PLAYER_HEIGHT /2)));

    Ball* ball = new Ball(Vec2((SIZEX /2 - WIDTH /2), (SIZEY /2 - HEIGHT /2)), Vec2(SPEED, 0.0f));


    PlayerScore* left_text = new PlayerScore(Vec2(SIZEX /4, 20), window->GetRenderer(), window->GetFont());
    PlayerScore* right_text = new PlayerScore(Vec2(3 * SIZEX /4, 20), window->GetRenderer(), window->GetFont());

    enum Buttons
    {
        PlayerLeftDown=0,
        PlayerLeftUp,
        PlayerRightDown,
        PlayerRightUp
    };

    float dt_ball= 0.4;
    bool buttons[4] = {};
    float dt =15;
    SDL_Event event;
    int ticks =10;

    while (run)
    {
        auto startTime = chrono::high_resolution_clock::now();

        while(SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT) run =0;

            //holdkey
             if(event.type == SDL_KEYDOWN)
            {
                if(event.key.keysym.sym ==SDLK_w) buttons[Buttons::PlayerLeftUp] = true;
                if(event.key.keysym.sym ==SDLK_s) buttons[Buttons::PlayerLeftDown] = true;
                if(event.key.keysym.sym ==SDLK_UP) buttons[Buttons::PlayerRightUp] = true;
                 if(event.key.keysym.sym ==SDLK_DOWN) buttons[Buttons::PlayerRightDown] = true;
            }

          //realesed key
             if(event.type == SDL_KEYUP)
            {
                if(event.key.keysym.sym ==SDLK_w) buttons[Buttons::PlayerLeftUp] = false;
                if(event.key.keysym.sym ==SDLK_s) buttons[Buttons::PlayerLeftDown] = false;
                if(event.key.keysym.sym ==SDLK_UP) buttons[Buttons::PlayerRightUp] = false;
                 if(event.key.keysym.sym ==SDLK_DOWN) buttons[Buttons::PlayerRightDown] = false;
            }

            //movement
            if (buttons[Buttons::PlayerLeftDown])
            {
                left->velocity.y = PADDLE_SPEED;
                
            }
            else if (buttons[Buttons::PlayerLeftUp])
            {
                left->velocity.y = -PADDLE_SPEED;
                
            }
            
            else left->velocity.y = 0;

            if (buttons[Buttons::PlayerRightDown])
            {
                right->velocity.y = PADDLE_SPEED;
                
            }
            
            else if (buttons[Buttons::PlayerRightUp])
            {
                right->velocity.y = -PADDLE_SPEED;
                
            }
            else right->velocity.y =0;
        }
        
        right->Update(dt);
        left->Update(dt);
        ball->Update(0.5);

        if (Contact contact = ball->CheckPaddleCollision(left);
            contact.type != CollisionType::None)
        {
            ball->CollideWithPaddle(contact);
        }
        else if (contact = ball->CheckPaddleCollision( right);
            contact.type != CollisionType::None)
        {
            ball->CollideWithPaddle(contact);
        }

        else if (contact = ball->CheckCollisionWithWall();
	    contact.type != CollisionType::None)
        {
	        ball->CollideWithWall();
        }
        
        if (ball->position.x <= 0 || ball->position.x >= SIZEX)
        {
            if(ball->position.x <= 0 ) right_text->Add();
            if(ball->position.x >= SIZEX) left_text->Add();

            for (int i = 0; i < ticks; i++)
            {
                SDL_Delay(100);
            }
            
            ball->position.x = SIZEX /2 - WIDTH /2;
            ball->position.y = SIZEY /2 - HEIGHT /2;
            left->position.y = SIZEY /2 - PLAYER_HEIGHT /2;
            right->position.y = SIZEY /2 - PLAYER_HEIGHT /2;
        }
        
        SDL_SetRenderDrawColor(window->GetRenderer(), 0x0, 0x0, 0x0, 0xFF);
		SDL_RenderClear(window->GetRenderer());

        SDL_SetRenderDrawColor(window->GetRenderer(), 255, 255, 255, 0);
        SDL_RenderDrawLine(window->GetRenderer(),SIZEX /2, SIZEY, SIZEX /2,0 );
        ball->Draw(window->GetRenderer());
        left->Draw(window->GetRenderer());
        right->Draw(window->GetRenderer());
        left_text->Draw();
        right_text->Draw();
        
        window->Display();  //backbuffer
         
        auto stopTime = chrono::high_resolution_clock::now();
	    dt = chrono::duration<float, chrono::milliseconds::period>(stopTime - startTime).count();

    }

    delete ball;
    delete left;
    delete right;
    delete left_text;
    delete right_text;
    delete window;
    
    SDL_Quit();
    TTF_Quit();
    return 0;
}
