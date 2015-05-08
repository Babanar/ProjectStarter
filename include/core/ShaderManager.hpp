#ifndef _SHADER_MANAGER_HPP_
#define _SHADER_MANAGER_HPP_

#include <SFML/Graphics.hpp>
#include <map>


class ShadersManager
{

	public:
		static sf::Shader* getShader(const std::string& path);


	private:
		class ShaderHolder
		{
			public:
				ShaderHolder();
				~ShaderHolder();
				sf::Shader* getShader() const;
				bool loadShaderFromFile(const std::string& path);
			private:
				sf::Shader* myShader;
		};

		typedef std::map<std::string, ShaderHolder> ShadersMap;
		static ShadersMap myShaders;

};

#endif // _SHADER_MANAGER_HPP_
