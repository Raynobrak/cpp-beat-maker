#include "BeatBoxInterface.h"
#include <cmath>

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

BeatBoxInterface::BeatBoxInterface(size_t tracksCount, size_t beatsCount) : _matrix(tracksCount, beatsCount) {

}

void BeatBoxInterface::processClickAt(float normalized_x, float normalized_y, BeatBox& bbox) {
	size_t row = static_cast<size_t>(std::floorf(normalized_y * static_cast<float>(_matrix.tracksCount())));
	size_t col = static_cast<size_t>(std::floorf(normalized_x * static_cast<float>(_matrix.beatsCount())));

	_matrix.set_at(row, col, !_matrix.get_at(row, col));
}

BeatBoxMatrix BeatBoxInterface::getMatrix() const {
	return _matrix;
}

void BeatBoxInterface::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	//std::vector<sf::RectangleShape> rectangles;
	auto winSize = sf::Vector2f(target.getSize());

	auto rectSize = sf::Vector2f(winSize.x / _matrix.beatsCount(), winSize.y / _matrix.tracksCount());

	for (size_t trackNumber = 0; trackNumber < _matrix.tracksCount(); ++trackNumber) {
		for (size_t beatNumber = 0; beatNumber < _matrix.beatsCount(); ++beatNumber) {
			auto rectPos = sf::Vector2f(beatNumber * rectSize.x, trackNumber * rectSize.y);
			sf::RectangleShape rect;
			rect.setPosition(rectPos);
			rect.setSize(rectSize);
			rect.setOutlineThickness(-5.f);
			rect.setOutlineColor(sf::Color::Black);
			rect.setFillColor(sf::Color::White);

			if (_matrix.get_at(trackNumber, beatNumber)) {
				rect.setFillColor(sf::Color::Red);
				
			}

			target.draw(rect);
		}
	}
}
