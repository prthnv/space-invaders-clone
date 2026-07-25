#include "Explosion.hpp"

Explosion::Explosion(Vector2 pos, Texture2D texture,int direction, int frames) {
    position = pos;
    image = texture;
    maxFrames = frames;
    directn = direction;
    currentFrame = 0;
    frameTime = 0.05f; 
    runningTime = 0.0f;
    active = true;
}

void Explosion::Update() {
    if (!active) return;

    runningTime += GetFrameTime(); 
    
    if (runningTime >= frameTime) {
        currentFrame++; 
        runningTime = 0.0f; 
        
        if (currentFrame >= maxFrames) {
            active = false; 
        }
    }
}

void Explosion::Draw() {
    if (active) {
        DrawTexture(image, position.x + directn*4, position.y , WHITE);   
    }
}
                           
