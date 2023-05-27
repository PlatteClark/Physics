#include "CircleShape.h"
#include "../Engine/Graphics.h"

void CircleShape::Draw(Graphics* graphics, const glm::vec2& position)
{
	int r = graphics->WorldToPixels(radius);

	graphics->DrawCircle(graphics->WorldToScreen(position), r, color);
}
