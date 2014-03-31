#include "PlumeImage.h"

using namespace Plume;


PlumeImage::PlumeImage(ConstStr addr)
{
	pImage = Gdiplus::Image::FromFile(addr);
}


PlumeImage::~PlumeImage(void)
{
	delete pImage;
}
