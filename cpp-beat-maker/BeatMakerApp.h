#pragma once

#include "SFMLApplicationBase/SFMLApplicationBase.h"

class BeatMakerApp : public SFMLApplicationBase {
public:
	BeatMakerApp();
private:
	void handleEvent(sf::Event& event) override;
	void update(float dt) override;
	void customRender() override;
};

