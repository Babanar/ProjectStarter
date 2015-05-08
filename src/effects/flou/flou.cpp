#include "effects/flou/flou.hpp"
#include "core/ShaderManager.hpp"
void Flou::setPosition(Vector2f newPosition)
{
    position = newPosition;

}

void Flou::setSize(Vector2f newSize){
    size=newSize;
}

void Flou::applyFlou(RenderTexture & texture)
{
    sf::Shader* shader = ShadersManager::getShader("shader/flou.frag");
	shader->setParameter("frag_Texture", texture.getTexture());
	shader->setParameter("frag_rectLT", Vector2f(position.x-size.x/2,600-position.y-size.y/2));
	shader->setParameter("frag_rectRB",Vector2f(position.x+size.x/2,600-position.y+size.y/2));

    RenderStates states;
    states.shader = shader;
    states.blendMode = BlendNone;

    Sprite sprite;
    sprite.setTexture(texture.getTexture());

    texture.draw(sprite,states);
}
