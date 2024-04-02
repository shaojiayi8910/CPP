#pragma once
#include <string>
#include <unordered_map>

#include "glm/glm.hpp"

struct ShaderPrograSoure
{
	std::string VertexSource;
	std::string FragmentSource;
};
class Shader
{
private:
	std::string m_FilePath;
	unsigned int m_RendererID;
	std::unordered_map<std::string, int> m_UniformLocationCache;
	//cashing for uniform
	 int GetUniformLocation(const std::string& name);
	unsigned int CompileShader(unsigned type, const std::string& soure);
	unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	ShaderPrograSoure PareShader(const std::string& filepath);

public:
	
	Shader(const std::string& filepath);
	~Shader();

	void Bind() const;
	void Unbind() const;
	//set uniform
	void SetUniform1i(const std::string& name, int value);
	void SetUniform1f(const std::string& name, float value);
	void SetUniform4f(const std::string& name, float v0, float v1, float f2, float f3);
	void SetUniformMat4f(const std::string& name, const glm::mat4& matrix);

	
};
