#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <SFML/Graphics.hpp>
#include <thread>

using namespace sf;
using namespace std;

class Application
{
    public:
        Application();

        void launch();
        void graphicLoop();
        void logicLoop();
        void eventLoop();
    protected:
        RenderWindow m_window;


    private:
};

#endif // APPLICATION_HPP
