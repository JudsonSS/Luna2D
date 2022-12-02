/**********************************************************************************
// Frog (C�digo Fonte)
// 
// Cria��o:     19 Dez 2012
// Atualiza��o: 14 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define o objeto Sapo no jogo Frogger
//
**********************************************************************************/

#include "Frog.h"

// ---------------------------------------------------------------------------------

Frog::Frog()
{
    sprite = new Sprite("Resources/frog.png");
    MoveTo(window->CenterX(), 560.0f, Layer::FRONT);
}

// ---------------------------------------------------------------------------------

Frog::~Frog()
{
    delete sprite;
}

// ---------------------------------------------------------------------------------

void Frog::Update()
{
    // desloca sapo para cima
    if (window->KeyPress(VK_UP))
    {
        Translate(0.0f, -40.0f);
    }
    
    // desloca sapo para baixo
    if (window->KeyPress(VK_DOWN))
    {
        Translate(0.0f, 40.0f);
    }
    
    // mant�m sapo dentro da tela
    if (y < 80)
        MoveTo(x, 80);

    if (y > 560)
        MoveTo(x, 560);
}

// ---------------------------------------------------------------------------------
