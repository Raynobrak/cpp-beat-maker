#pragma once

#include <vector>

struct BeatBoxMatrix {
	BeatBoxMatrix();
	BeatBoxMatrix(size_t tracksCount, size_t trackLength);

	void set_at(size_t track, size_t beat, bool val);
	bool get_at(size_t track, size_t beat) const;

	size_t tracksCount() const;
	size_t beatsCount() const;
private:
	std::vector<std::vector<bool>> _matrix;
};

