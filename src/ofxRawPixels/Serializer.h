#pragma once

#include "ofPixels.h"

namespace ofxRawPixels
{
	class Serializer
	{
	public:
		static bool save(const ofPixels & pixels, const std::filesystem::path & path);
		static bool load(ofPixels & pixels, const std::filesystem::path & path);

		static bool save(const ofFloatPixels & pixels, const std::filesystem::path & path);
		static bool load(ofFloatPixels & pixels, const std::filesystem::path & path);

		static bool save(const ofShortPixels & pixels, const std::filesystem::path & path);
		static bool load(ofShortPixels & pixels, const std::filesystem::path & path);

	private:
		template <typename P>
		static std::string getTypeStr(const ofPixels_<P> & pixels)
		{
			const auto& info = typeid(P);
			if (info == typeid(unsigned char))
			{
				return "char";
			}
			else if (info == typeid(float))
			{
				return "float";
			}
			else if (info == typeid(unsigned short))
			{
				return "short";
			}

			return "unknown";
		}

		template <typename P>
		static bool save(const ofPixels_<P> & pixels, const std::filesystem::path & path)
		{
			if (!pixels.isAllocated())
			{
				ofLogError(__FUNCTION__) << "ofPixels is not allocated!";
				return false;
			}

			const size_t width = pixels.getWidth();
			const size_t height = pixels.getHeight();
			const size_t channels = pixels.getNumChannels();

			ofLogNotice(__FUNCTION__) << "Saving '" << Serializer::getTypeStr(pixels) << "' pixels " << width << "x" << height << "x" << channels << " to " << path;

			auto file = ofFile(path, ofFile::WriteOnly, true);
			file.write((char *)(&width), sizeof(size_t));
			file.write((char *)(&height), sizeof(size_t));
			file.write((char *)(&channels), sizeof(size_t));
			file.write((char *)(pixels.getData()), pixels.size() * sizeof(P));
			file.close();

			return true;
		}

		template <typename P>
		static bool load(ofPixels_<P> & pixels, const std::filesystem::path & path)
		{
			ofFile file(path, ofFile::ReadOnly, true);
			if (!file.exists()) {
				ofLogError(__FUNCTION__) << "Cannot open file at " << path;
				return false;
			}

			size_t width;
			size_t height;
			size_t channels;
			file.read((char *)(&width), sizeof(size_t));
			file.read((char *)(&height), sizeof(size_t));
			file.read((char *)(&channels), sizeof(size_t));

			ofLogNotice(__FUNCTION__) << "Loading '" << Serializer::getTypeStr(pixels) << "' pixels " << width << "x" << height << "x" << channels << " from " << path;

			pixels.allocate(width, height, channels);

			file.read((char *)(pixels.getData()), pixels.size() * sizeof(P));

			file.close();

			return true;
		}
	};
}