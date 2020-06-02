#pragma once
// dma.h -- inheritance and dynamic memory allocation
#ifndef DMA_H_
#define DMA_H_
#include <iostream>

class ABC
{
private:
	char* label;
	int rating;
public:
	ABC(const char* l = "null", int r = 0);
	ABC(const ABC& rs);
	virtual ~ABC();
	ABC& operator=(const ABC& rs);
	char* getLabel();
	int getRating();
	virtual void view();
};

// Base Class Using DMA
class baseDMA : public ABC
{
private:
public:
	baseDMA(const char* l = "null", int r = 0) : ABC(l, r) {};
	baseDMA(const baseDMA& rs) : ABC(rs) {};
	//baseDMA& operator=(const baseDMA& rs);
};

class lacksDMA :public ABC
{
private:
	enum { COL_LEN = 40 };
	char color[COL_LEN];
public:
	lacksDMA(const char* c = "blank", const char* l = "null",
		int r = 0);
	lacksDMA(const char* c, const baseDMA& rs);
	virtual void view();
};

class hasDMA :public ABC
{
private:
	char* style;
public:
	hasDMA(const char* s = "none", const char* l = "null",
		int r = 0);
	hasDMA(const char* s, const ABC& rs);
	hasDMA(const hasDMA& hs);
	virtual ~hasDMA();
	hasDMA& operator=(const hasDMA& rs);
	virtual void view();
};
#endif