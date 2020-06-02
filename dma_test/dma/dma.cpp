// dma.cpp --dma class methods
#include "dma.h"
#include <cstring>
#pragma warning(disable : 4996)

// ABC methods
ABC::ABC(const char* l, int r)
{
	label = new char[std::strlen(l) + 1];
	std::strcpy(label, l);
	rating = r;
}
ABC::ABC(const ABC& rs)
{
	label = new char[std::strlen(rs.label) + 1];
	std::strcpy(label, rs.label);
	rating = rs.rating;
}
ABC::~ABC()
{
	delete[] label;
}
ABC& ABC::operator=(const ABC& rs)
{
	if (this == &rs)
		return *this;
	delete[] label;
	label = new char[std::strlen(rs.label) + 1];
	std::strcpy(label, rs.label);
	rating = rs.rating;
	return *this;
}
char* ABC::getLabel()
{
	return label;
}
int ABC::getRating()
{
	return rating;
}
void ABC::view()
{
	std::cout << "Label: " << getLabel() << std::endl;
	std::cout << "Rating: " << getRating() << std::endl;
}

// baseDMA methods


// lacksDMA methods
lacksDMA::lacksDMA(const char* c, const char* l, int r)
	: ABC(l, r)
{
	std::strncpy(color, c, 39);
	color[39] = '\0';
}
lacksDMA::lacksDMA(const char* c, const baseDMA& rs)
	: ABC(rs)
{
	std::strncpy(color, c, COL_LEN - 1);
	color[COL_LEN - 1] = '\0';
}
void lacksDMA::view()
{
	ABC::view();
	std::cout << "Color: " << color << std::endl;
}

// hasDMA methods
hasDMA::hasDMA(const char* s, const char* l, int r)
	: ABC(l, r)
{
	style = new char[std::strlen(s) + 1];
	std::strcpy(style, s);
}
hasDMA::hasDMA(const char* s, const ABC& rs)
	: ABC(rs)
{
	style = new char[std::strlen(s) + 1];
	std::strcpy(style, s);
}
hasDMA::hasDMA(const hasDMA& hs)
	: ABC(hs) // invoke base class copy constructor
{
	style = new char[std::strlen(hs.style) + 1];
	std::strcpy(style, hs.style);
}
hasDMA::~hasDMA()
{
	delete[] style;
}
hasDMA& hasDMA::operator=(const hasDMA& hs)
{
	if (this == &hs)
		return *this;
	ABC::operator=(hs); // copy base portion
	delete[] style; // prepare for new style
	style = new char[std::strlen(hs.style) + 1];
	std::strcpy(style, hs.style);
	return *this;
}
void hasDMA::view()
{
	ABC::view();
	std::cout << "Style: " << style << std::endl;
}
