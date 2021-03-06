#ifndef SCREEN_H
#define SCREEN_H
#include <SFML/Graphics.hpp>

using namespace sf;

class Screen:public Drawable
{
    public:
        virtual void gainFocus();
        virtual void onEvent(sf::Event & event);
        virtual void update(sf::Time& tps);
        virtual void looseFocus();
    protected:
        sf::Vector2i* _window_size;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const ;
    private:
};

#endif // SCREEN_H
