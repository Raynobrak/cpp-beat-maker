#pragma once

#include "BeatBox.h"
#include "SFMLApplicationBase/SFMLApplicationBase.h"
#include "BeatBoxInterface.h"

class BeatMakerApp : public SFMLApplicationBase {
public:
	BeatMakerApp();
private:
	void handleEvent(sf::Event& event) override;
	void update(float dt) override;
	void customRender() override;
private:
	BeatBox _bbox;
	BeatBoxInterface _interface;
};

