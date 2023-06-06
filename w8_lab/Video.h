#pragma once
#ifndef SDDS_VIDEO_H_
#define SDDS_VIDEO_H_
#include <iostream>
#include"Media.h"
namespace sdds {
	class Video :public Media{
		int m_length=0;
	protected:
		int get() const;
	public:
		Video(); 
		Video(int length);
		Video(const Video& data)=delete;
		Video& operator=(const Video& data)=delete;
		virtual void load(std::istream& is) ;
	};

}
#endif //!SDDS_VIDEO_H_