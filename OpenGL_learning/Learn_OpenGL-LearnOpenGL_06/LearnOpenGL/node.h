#pragma once
#include "common.h"
#include "render_state.h"
#include "transform.h"

struct Vertex//����һ������ṹ�壬���Դ�Ŷ�������
{
	Vertex(glm::vec3 position = glm::vec3(0.f), glm::vec2 texCoords = glm::vec2(0.0),
		glm::vec3 normal = glm::vec3(0.0), glm::vec3 tangent = glm::vec3(0.0), glm::vec3 bitangent = glm::vec3(0.0)) :
		Position(position), TexCoords(texCoords),
		Normal(normal), Tangent(tangent), Bitangent(bitangent)
	{

	}//����vertex�ṹ�����ڱ���vertex���ݽṹ:v3 ��Position��Normal
//											v2 ���������꣨uv���꣩
	glm::vec3 Position;
	glm::vec2 TexCoords;
	glm::vec3 Normal;
	glm::vec3 Tangent;
	glm::vec3 Bitangent;
};


class Node
{
public:
	Node();
	Node(std::vector<Vertex>& vecVertexs, std::vector<unsigned int>& vecIndexs,
		std::shared_ptr<RenderState> spRenderState, std::shared_ptr<Transform> spTransform);
	~Node();
	void SetRenderState(std::shared_ptr<RenderState> spRenderState);
	void SetTransform(std::shared_ptr<Transform> spTransform);
	void SetInstanceOffset(const std::vector<glm::vec2>& vecOffset);
	void SetInstanceOffset(const std::vector<glm::mat4>& vecOffset);

	virtual void Prender();
	virtual void Draw();
	virtual void PostRender();

private:
	void ApplyTexture();
	void ApplyTransform();

protected:

	void SetVertexs(std::vector<Vertex>& vecVertexs);
	void SetIndexs(std::vector<unsigned int>& vecIndexs);
	void SetVAOVBO();

protected:
	std::shared_ptr<RenderState> m_spRenderState;
	std::shared_ptr<Transform> m_spTransform;
	std::vector<GLuint> m_vecTexture;

private:
	std::vector<Vertex> m_vecVertexs;
	std::vector<unsigned int> m_vecIndexs;

	unsigned int m_uiVAO;
	unsigned int m_uiVBO;
	unsigned int m_uiEBO;
	unsigned int m_uiInstance;
};