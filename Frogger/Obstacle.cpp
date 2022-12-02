/**********************************************************************************
// Obstacle (C�digo Fonte)
// 
// Cria��o:     19 Dez 2012
// Atualiza��o: 01 Dez 2022
// Compilador:  Visual C++ 2022
//
// Descri��o:   Obst�culos do jogo Frogger
//
**********************************************************************************/

#include "Obstacle.h"

// ---------------------------------------------------------------------------------

Obstacle::Obstacle(Image * img, float speed)
{
    sprite = new Sprite(img);
    vel    = speed;
}

// ---------------------------------------------------------------------------------

Obstacle::~Obstacle()
{
    delete sprite;
}

// ---------------------------------------------------------------------------------

void Obstacle::Update()
{
    // objeto caminha no eixo x
    Translate(-vel * gameTime, 0.0f);
    
    // passa objeto de um lado da tela para o outro
    if (x + sprite->Width() / 2.0f < 0)
        MoveTo(window->Width() + sprite->Width() / 2.0f , y);
}

// ---------------------------------------------------------------------------------
