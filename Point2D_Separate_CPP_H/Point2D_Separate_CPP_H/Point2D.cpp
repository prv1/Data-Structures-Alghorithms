#include "Point2D.h"

int Point2D::numberOfPoints2D = 0;

Point2D::Point2D(int x, int y) {
	numberOfPoints2D++;
	this->x = x;
	this->y = y;
}

Point2D::Point2D(const Point2D& point) {
	this->setX(point.getX());
	this->setY(point.getY());

}

Point2D::~Point2D() {
	//numberOfPoints2D--;
}

int Point2D::getX() const { return this->x; }

int Point2D::getY() const { return this->y; }

void Point2D::setX(int x) { this->x = x; }

void Point2D::setY(int y) { this->y = y; }

Point2D& Point2D::operator+(const Point2D& rhs) const {
	return Point2D(this->getX() + rhs.getX(), this->getY() + rhs.getY());
}

ostream& operator<<(ostream& os, const Point2D& p) {
	return os << "(" << p.getX() << ", " << p.getY() << ")";
}