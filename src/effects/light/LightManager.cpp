#include "effects/light/LightManager.hpp"

using namespace std;
using namespace sf;

void LightManager::applyLight(RenderTexture& texture)
{
    for(Light & l:lights)
        l.applyLight(texture);
}

Light & LightManager::getLight(int id)
{
    list<Light>::iterator it=lights.begin();
    for(int i=0;i<id;i++)
        it++;
    return *it;

}

Light & LightManager::back()
{
    return lights.back();
}

void LightManager::addLight(Vector2f position, Color color)
{
    lights.push_back(Light());
    lights.back().setPosition(position);
    lights.back().setColor(color);
}
