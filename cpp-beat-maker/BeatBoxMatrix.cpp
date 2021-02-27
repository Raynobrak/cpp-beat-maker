#include "BeatBoxMatrix.h"

BeatBoxMatrix::BeatBoxMatrix() {
}

BeatBoxMatrix::BeatBoxMatrix(size_t tracksCount, size_t trackLength) {
	for (size_t trackNumber = 0; trackNumber < tracksCount; ++trackNumber) {
		_matrix.emplace_back();
		for (size_t beatNumber = 0; beatNumber < trackLength; ++beatNumber) {
			_matrix[trackNumber].emplace_back(false);
		}
	}
}

void BeatBoxMatrix::set_at(size_t track, size_t beat, bool val) {
	_matrix[track][beat] = val;
}

bool BeatBoxMatrix::get_at(size_t track, size_t beat) const {
	return _matrix[track][beat];
}

size_t BeatBoxMatrix::tracksCount() const
{
    return _matrix.size();
}

size_t BeatBoxMatrix::beatsCount() const
{
	return _matrix.size() > 0 ? _matrix[0].size() : 0;
}
