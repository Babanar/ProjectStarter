#include <SFML/Graphics.hpp>
#include "effects/light/Light.hpp"
#include "effects/light/LightManager.hpp"
#include "effects/flou/flou.hpp"
#include "core/Ressource.hpp"
#include "core/MusicManager.hpp"

#include "poloniex/API.hpp"
#include "Application.hpp"
#include <iostream>

using namespace sf;
using namespace std;

int main()
{
    //TEST DE L'INTERFACE D'ABSTRACTION, NON EFFECTUABLE DERRIERE UN PROXY
    //C'EST POURQUOI JE N'AI PAS ENCORE PU LE TESTER...
   // cout << plnx::API::getTicker() << endl;


    //Application app;
    //app.launch();
    RenderWindow m_window;
    m_window.create(sf::VideoMode(800, 600), "Trade Inteface");

    while(m_window.isOpen()){

        m_window.clear();
        m_window.display();
        sleep(seconds(1/60.f));
    }

 /*   srand(time(NULL));

    RenderWindow window(VideoMode(800, 600), "Game");
    window.setMouseCursorVisible(false);

    RenderTexture textureWindow;
    textureWindow.create(800,600);

    Sprite spriteWindow;
    spriteWindow.setTexture(textureWindow.getTexture());

    MusicManager musics;
    musics.loadFromDir("res/musics/");
    musics.play();

    Sprite bg=Ressource::getSprite("bgtest.jpg");

    LightManager lights;
    lights.addLight(Vector2f(0,0),Color(255,180,0));

    Flou flou;
    flou.setSize(Vector2f(100,100));

    while (window.isOpen())
    {
        Event event;

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        lights.back().setPosition(Vector2f(Mouse::getPosition(window).x,Mouse::getPosition(window).y));
        flou.setPosition(Vector2f(Mouse::getPosition(window).x,Mouse::getPosition(window).y));


        musics.update();



        window.clear();
        textureWindow.clear();

        lights.applyLight(textureWindow); //Mappage des lumières

        RenderStates states;
        states.blendMode = BlendMultiply;
        textureWindow.draw(bg,states); //Affichage du fonds d'écrands

        flou.applyFlou(textureWindow); //Application de la zone de floutage

        textureWindow.display();

        window.draw(spriteWindow);
        window.display();
    }
*/
    return 0;
}
