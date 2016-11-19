#pragma once
#include <iostream>
using namespace std;
#ifndef COLOR_H
#define COLOR_H

class ColorH {
	
private:
	int red;
	int green;
	int blue; 
	
public:
	
	ColorH(int red = 0, int green = 0, int blue = 0) {
		this->red = red;
		this->green = green;
		this->blue = blue;

	}

	
	~ColorH() { 

	}

	
	void setRed(int colorComponent) { this->red = colorComponent; }
	void setGreen(int colorComponent) { this->green = colorComponent; }
	void setBlue(int colorComponent) { this->blue = colorComponent; }
	
	
	int getRed() const { return this->red; }
	int getGreen() const { return this->green; }
	int getBlue() const { return this->blue; }
	
	ColorH operator+(const ColorH& rhs) const { return ColorH(this->getRed() + rhs.getRed(), this->getGreen() + rhs.getGreen(), this->getBlue() + rhs.getBlue());}
	ColorH operator-(const ColorH& rhs) const { return ColorH(this->getRed() - rhs.getRed(), this->getGreen() - rhs.getGreen(), this->getBlue() - rhs.getBlue()); }
	bool operator==(const ColorH& rhs) { return (ColorH(this->getRed(), this->getGreen(), this->getBlue()) == ColorH(rhs.getRed(), rhs.getGreen(), rhs.getBlue()) ); }
	//ColorH& ColorH::operator-(const ColorH& rhs) const { return ColorH(this->getRed() - rhs.getRed(), this->getGreen() - rhs.getGreen(), this->getBlue() - rhs.getBlue()); }
	
	ColorH& ColorH::operator++() {
		++red;
		++green;
		++blue;
		return *this;
	}
	
	ColorH& ColorH::operator--() {
		--red;
		--green;
		--blue;
		return *this;
	}
	
	friend ostream& operator<<(ostream& os, ColorH const& color) {
		return os << color.getRed() << ":" << color.getGreen() << ":" << color.getBlue();
	}

};



#endif