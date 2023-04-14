#include <iostream>
#include <memory>
#include <vector>

struct Pixel;
struct Point3;
class PoseSE3;
template<typename T> class Image;
template<typename T> class ImagePyramid;
class Landmark;
class Frame;

using PixelVec = std::vector<Pixel>;
using Point3Vec = std::vector<Point3>;

using FramePtr = std::shared_ptr<Frame>;
using FramePtrVec = std::vector<FramePtr>;

using LandmarkPtr = std::shared_ptr<Landmark>;
using LandmarkPtrVec = std::vector<LandmarkPtr>;

struct Pixel
{
	float x;
	float y;
};
struct Point3
{
	float x;
	float y;
	float z;
};
class PoseSE3 
{ /// @breif SE(3) class
	
};
template<typename T>
class Image
{
private:
	T* data_;
	size_t cols_;
	size_t rows_;
};
template<typename T>
class ImagePyramid
{
private:
	std::vector<Image<T>> image_pyramid_;
	std::vector<int> cols_pyramid_;
	std::vector<int> rows_pyramid_;
};
class Landmark
{
private:
	Point3 Xw; // world coordinate
	FramePtr frame_reference_;
	FramePtrVec frames_observed_;
};
class Frame
{
private:
	// Identifier
	uint32_t id_; // unique ID of this frame.
	double timestamp_; // timestamp of this frame in second.
	bool is_stereo_pair_;

	// Image
	Image<uint8_t> image_;
	ImagePyramid<uint8_t> image_pyramid_;

	// related landmarks
	LandmarkPtrVec landmarks_observed_;
	PixelVec pts_observed_;
};

class MapLandmarks
{
	// It contains all the landmarks registered to the map
public:
	const LandmarkPtrVec& getRelatedMapLandmarks(const FramePtr& frame);

private:
	LandmarkPtrVec all_landmarks_; //all_landmarks_[i]->getRelatedFramePtrVec()[j]->getPose();
};

class FrameMap
{
private:
	FramePtrVec keyframe_window_;
};



int main()
{
    std::cout << "Hello World!\n";
}
