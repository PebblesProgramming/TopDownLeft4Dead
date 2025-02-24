#include "player.h"
#include <cmath>

void InitPlayer(Player& player, const char* texturePath, Vector2 startPos, float scale, float speed) {
    player.position = startPos;
    player.speed = speed;
    player.rotation = 0.0f;
    player.scale = scale;
    player.animation = LoadTexture(texturePath);
}

void UpdatePlayer(Player& player) {
    float deltaTime = GetFrameTime();

        if (IsKeyDown(KEY_W)) player.position.y -= player.speed * deltaTime;
        if (IsKeyDown(KEY_S)) player.position.y += player.speed * deltaTime;
        if (IsKeyDown(KEY_A)) player.position.x -= player.speed * deltaTime;
        if (IsKeyDown(KEY_D)) player.position.x += player.speed * deltaTime;

        Vector2 mousePos = GetMousePosition();
        float dx = mousePos.x - player.position.x;
        float dy = mousePos.y - player.position.y;
        player.rotation = atan2(dy, dx) * (180.0f / PI);
}

void DrawPlayer(const Player& player) {
  
        Rectangle source = {0, 0, (float)player.animation.width, (float)player.animation.height};
        Rectangle dest = {player.position.x, player.position.y, (float)player.animation.width * player.scale, (float)player.animation.height * player.scale};
        Vector2 origin = {(float)player.animation.width * player.scale / 2, (float)player.animation.height * player.scale / 2};

        DrawTexturePro(player.animation, source, dest, origin, player.rotation, WHITE);
    
}

void UnloadPlayer(Player& player) {
        UnloadTexture(player.animation);
}
