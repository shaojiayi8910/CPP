#pragma once
#include "common.h"

enum TextureType
{
	DIFFUSE = 0,
	SPECULAR,
	NORMAL,
	HEIGHT,
	CUBEMAP
};

struct TextureStruct//定义一个纹理结构体来包含纹理的数据结构，包含ID type path
{
	unsigned int uiID;
	TextureType eType;
	std::string sPath;
};

class Texture
{
public:
	Texture();
	~Texture();
	void AddTexture(std::shared_ptr<TextureStruct> spTexture);
	GLuint AddTexture(const std::string& sPath, TextureType eType, bool bflip = false, bool gamma = false);
	GLuint AddTexture(std::vector<std::string>& vecCubeMap);
	const std::map<GLuint, std::shared_ptr<TextureStruct>>& GetTexures()const;
private:
	unsigned int TextureFromFile(const std::string& sPath, bool bflip, bool gamma);
	unsigned int TextureFromCube(std::vector<std::string>& vecCubeMap);
private:
	std::map<GLuint, std::shared_ptr<TextureStruct>> m_mapTextures;
};
