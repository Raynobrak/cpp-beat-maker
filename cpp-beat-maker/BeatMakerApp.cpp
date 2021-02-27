#include "BeatMakerApp.h"

constexpr size_t TRACKS = 4;
constexpr size_t BEATS = 8;

BeatMakerApp::BeatMakerApp() : _bbox(TRACKS, BEATS, 300), _interface(TRACKS, BEATS) {
	auto settings = SFMLApplicationSettings();
	settings.applicationName = "Beat Maker !";
	settings.windowWidth = 800;
	settings.windowHeight = 500;
	initApplication(settings);
}

void BeatMakerApp::handleEvent(sf::Event& event) {
	switch (event.type) {
	case sf::Event::Closed:
		exitApplication();
		break;
	case sf::Event::MouseButtonPressed:
		auto winSize = sf::Vector2f(window_.getSize());
		auto coords = getMousePosOnWindow();
		coords.x /= winSize.x;
		coords.y /= winSize.y;
		_interface.processClickAt(coords.x, coords.y, _bbox);
		break;
	}
}

void BeatMakerApp::update(float dt) {
	_bbox.setMatrix(_interface.getMatrix());
	_bbox.play();
}

void BeatMakerApp::customRender() {
	drawOnWindow(_interface);
}
