#pragma once
#include <raylib.h>

class Explosion {
public:
    Vector2 position;
    Texture2D image;
    int currentFrame;
    int maxFrames;
    float frameTime;   
    float runningTime;  
    bool active;        
    int directn;
    Explosion(Vector2 pos, Texture2D texture, int direction, int frames);
    void Update();
    void Draw();
};


