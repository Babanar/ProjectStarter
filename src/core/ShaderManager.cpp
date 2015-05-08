
#include "core/ShaderManager.hpp"
#include <iostream>

using namespace std;
using namespace sf;

ShadersManager::ShadersMap ShadersManager::myShaders;
Shader* ShadersManager::getShader(const string& path)
{
	ShadersMap::iterator it = myShaders.find(path);
    if(it != myShaders.end())
		return it->second.getShader();
    cout << "Chargement du shader : "  << path << endl;
	if(!myShaders[path].loadShaderFromFile(path))
		cerr << "Impossible de charger le shader." << endl;

	return myShaders[path].getShader();
}


ShadersManager::ShaderHolder::ShaderHolder()

{ myShader = nullptr; }


ShadersManager::ShaderHolder::~ShaderHolder()

{
	if(myShader)
		delete myShader;
}


sf::Shader* ShadersManager::ShaderHolder::getShader() const
{
    return myShader;
}


bool ShadersManager::ShaderHolder::loadShaderFromFile(const std::string& path)
{
	if(!myShader)
		myShader=new sf::Shader;

	return myShader->loadFromFile(path, sf::Shader::Fragment);
}
