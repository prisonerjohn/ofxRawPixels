#include "Serializer.h"

#include "ofFileUtils.h"

namespace ofxRawPixels
{
	bool Serializer::save(const ofPixels & pixels, const std::filesystem::path & path)
	{
		return Serializer::save<unsigned char>(pixels, path);
	}

	bool Serializer::load(ofPixels & pixels, const std::filesystem::path & path)
	{
		return Serializer::load<unsigned char>(pixels, path);
	}

	bool Serializer::save(const ofFloatPixels & pixels, const std::filesystem::path & path)
	{
		return Serializer::save<float>(pixels, path);
	}
		
	bool Serializer::load(ofFloatPixels & pixels, const std::filesystem::path & path)
	{
		return Serializer::load<float>(pixels, path);
	}

	bool Serializer::save(const ofShortPixels & pixels, const std::filesystem::path & path)
	{
		return Serializer::save<unsigned short>(pixels, path);
	}

	bool Serializer::load(ofShortPixels & pixels, const std::filesystem::path & path)
	{
		return Serializer::load<unsigned short>(pixels, path);
	}
}