#ifndef COLOR__H
#define COLOR__H

class Color_
{
private:
	int red_;
	int green_;
	int blue_;
public:
	Color_(int red = 0, int green = 0, int blue = 0) : red_(red), green_(green), blue_(blue) {}
	inline int red(void) const { return red_; }
	inline int green(void) const { return green_; }
	inline int blue(void) const { return blue_; }
	inline void red(const int& red) { red_ = red; }
	inline void green(const int& green) { green_ = green; }
	inline void blue(const int& blue) { blue_ = blue; }
};

#endif // COLOR__H ///