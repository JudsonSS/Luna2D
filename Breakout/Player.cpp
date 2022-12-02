/**********************************************************************************
// Player (Arquivo de Cabe�alho)
// 
// Cria��o:     22 Dez 2012
// Atualiza��o: 01 Dez 2022
// Compilador:  Visual C++ 2022
//
// Descri��o:   Player do jogo Breakout
//
**********************************************************************************/

#include "Breakout.h"
#include "Player.h"
#include "Ball.h"

// ---------------------------------------------------------------------------------

Player::Player()
{
    // tamanho do player � 100x20
    BBox(new Rect(-50, -10, 49, 9));

    // bounding box alternativa: experimente usar 
    // uma combina��o de ret�ngulos e c�rculos
    
    //Mixed * mixed = new Mixed();
    //
    //Circle * cLeft = new Circle(10.0f);
    //cLeft->MoveTo(-40.0f, 0.0f);
    //Circle * cRight = new Circle(10.0f);
    //cRight->MoveTo(40.0f, 0.0f);
    //Rect* rect = new Rect(-40.0f, -10.0f, 40.0f, 10.0f);
    //
    //mixed->Insert(cLeft);
    //mixed->Insert(cRight);
    //mixed->Insert(rect);
    //
    //BBox(mixed);

    // sprite do jogador
    sprite = new Sprite("Resources/Player.png");

    // centraliza o jogador
    MoveTo(window->CenterX(), window->Height() - 20.0f, Layer::FRONT);

    // velocidade do jogador
    vel = 500; 

    // estado inicial do jogo
    state = STOPED;

    // tipo do objeto
    type = PLAYER;

}

// ---------------------------------------------------------------------------------

Player::~Player()
{
    delete sprite;
}

// ---------------------------------------------------------------------------------

void Player::OnCollision(Object * obj)
{
    // bola colidiu com o player
    if (obj->Type() == BALL)
    {
        Ball * ball = (Ball*) obj;
        ball->velY = -ball->velY;
    }    
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
    // inicia o jogo com barra de espa�o
    if (state == STOPED && window->KeyDown(VK_SPACE))
        state = PLAYING;

    // desloca jogador horizontalmente
    if (window->KeyDown(VK_RIGHT))
        Translate(vel * gameTime, 0);
    if (window->KeyDown(VK_LEFT))
        Translate(-vel * gameTime, 0);

    // mant�m jogador dentro da janela (tam. da barra: 100x20)
    if (x < sprite->Width() / 2.0f)
        MoveTo(sprite->Width() / 2.0f, y);
    if (x + sprite->Width() / 2.0f > window->Width())
        MoveTo(float(window->Width() - sprite->Width() / 2.0f), y);
}

// ---------------------------------------------------------------------------------
