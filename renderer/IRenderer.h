#pragma once


class IRenderer
{

public:
	IRenderer();
	virtual ~IRenderer();

	void virtual init() = 0;
	void virtual drawScene() = 0;

	void virtual _drawObject() = 0;
	void virtual _drawMesh() = 0;
};

