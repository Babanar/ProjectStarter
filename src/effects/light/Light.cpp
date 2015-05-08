#include "effects/light/Light.hpp"
#include "core/ShaderManager.hpp"
using namespace sf;
using namespace std;

Light::Light()
{
    position = Vector2f(100,100);
    color = Color::Red;
    range = 150.f;
}



void Light::applyLight(RenderTexture& target) const
{
    sf::Shader* shader = ShadersManager::getShader("shader/shader.frag");
	shader->setParameter("frag_LightOrigin", Vector2f(position.x,target.getSize().y-position.y));
	shader->setParameter("frag_LightColor", color);


    RenderStates states;
    states.shader = shader;
    states.blendMode = BlendAdd;

    Sprite sprite;
    sprite.setTexture(target.getTexture());

    target.draw(sprite,states);
}


void Light::setPosition(Vector2f newPosition)
{
    position = newPosition;
}

void Light::setColor(Color newColor)
{
    color = newColor;
}
