#pragma once
#ifndef SDDS_VRVIDEO_H_
#define SDDS_VRVIDEO_H_
#include<iostream>
#include"Video.h"
namespace sdds {
	class VRVideo:public Video {
		char* m_equpiment=nullptr;
	public:
		VRVideo();
		VRVideo(int v_length, const char* equpiment);
		virtual ~VRVideo();
		virtual void load(std::istream& is);
		virtual std::ostream& play(std::ostream& os) const ;
		VRVideo(const VRVideo&) = delete;
		VRVideo& operator=(const VRVideo&) = delete;
	};
}
#endif //!SDDS_VIDEO_H_