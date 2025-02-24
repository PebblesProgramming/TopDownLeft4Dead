#include "raylib.h"
#include <math.h>

struct Player{
    Vector2 position;
    float speed;
    float rotation;
    float scale;
    Texture2D animation;
};


void InitPlayer(Player& player, const char* texturePath, Vector2 startPos, float scale, float speed);
void UpdatePlayer(Player& player);
void DrawPlayer(const Player& player);
void UnloadPlayer(Player& player);
