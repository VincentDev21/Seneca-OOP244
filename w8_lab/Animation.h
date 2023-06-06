#pragma once
#ifndef SDDS_ANIMATION_H_
#define SDDS_ANIMATION_H_
#include<iostream>
#include"Video.h"
namespace sdds {
	class Animation:public Video {
		int m_dimension=0;
	public:
		Animation();
		Animation(int length, int dimension);
		virtual void load(std::istream& is) ;
		virtual std::ostream& play(std::ostream& os) const ;
	};
}
#endif  //!SDDS_ANIMATION_H_