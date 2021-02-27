#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include "BeatBox.h"

class BeatBoxInterface : public sf::Drawable {
public:
	BeatBoxInterface(size_t tracksCount, size_t beatsCount);
	void processClickAt(float normalized_x, float normalized_y, BeatBox& bbox);
	BeatBoxMatrix getMatrix() const;
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	BeatBoxMatrix _matrix;
	sf::Vector2f _wsize;
};

