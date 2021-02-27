#include "BeatBox.h"

BeatBox::BeatBox(size_t tracksCount, size_t trackLength, size_t bpm) : _matrix(tracksCount, trackLength), _bpm(bpm) {
	loadSounds();
}

void BeatBox::setMatrix(BeatBoxMatrix newMatrix) {
	_matrix = newMatrix;
}

void BeatBox::play() {
	float timePerBeat = 60.f / static_cast<float>(_bpm);
	if (_internalTimer.getElapsedTime().asSeconds() > timePerBeat) {
		_internalTimer.restart();

		playNextBeat();
	}
}

void BeatBox::playNextBeat() {
	_beatIndex++;

	if (_beatIndex >= _matrix.beatsCount()) {
		_beatIndex = 0;
	}

	for (size_t track = 0; track < _matrix.tracksCount(); ++track) {
		if (_matrix.get_at(track, _beatIndex)) {
			_sounds[track].play();
		}
	}
}

void BeatBox::loadSounds() {
	std::vector<std::string> filenames = { "metronome.wav", "drum_hit_snare.wav", "brutal_snare2.wav", "thugly_snare.wav" };

	_soundBuffers.reserve(filenames.size());

	for (const auto& filename : filenames) {
		sf::SoundBuffer buff;
		if (buff.loadFromFile("sounds/" + filename)) {
			_soundBuffers.push_back(buff);
			sf::Sound sound;
			sound.setBuffer(_soundBuffers[_soundBuffers.size() - 1]);
			_sounds.push_back(sound);
		}
		else {
			throw std::exception("well shit");
		}
	}	
}
