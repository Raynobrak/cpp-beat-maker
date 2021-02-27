#include "BeatMakerApp.h"

BeatMakerApp::BeatMakerApp() {
	auto settings = SFMLApplicationSettings();
	settings.applicationName = "Beat Maker !";
	settings.windowWidth = 500;
	settings.windowHeight = 500;
	initApplication(settings);
}

void BeatMakerApp::handleEvent(sf::Event& event) {
}

void BeatMakerApp::update(float dt) {
}

void BeatMakerApp::customRender() {
}
