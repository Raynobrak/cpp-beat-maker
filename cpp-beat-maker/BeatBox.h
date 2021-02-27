#pragma once

#include <SFML/System/Clock.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <vector>

#include "BeatBoxMatrix.h"

class BeatBox {
public:
	BeatBox(size_t tracksCount, size_t trackLength, size_t bpm);
	void setMatrix(BeatBoxMatrix newMatrix);
	void play();
private:
	void playNextBeat();
	void loadSounds();
private:
	sf::Clock _internalTimer;
	size_t _beatIndex;
	size_t _bpm;
	BeatBoxMatrix _matrix;
	std::vector<sf::Sound> _sounds;
	std::vector<sf::SoundBuffer> _soundBuffers;
};

