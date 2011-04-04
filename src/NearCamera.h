/*
 * NearCamera.h
 *
 *  Created on: Jul 21, 2010
 *      Author: pinto
 */

#ifndef NEARCAMERA_H_
#define NEARCAMERA_H_
#include <vector>

#include "cg.h"
#include "Car.h"
#define PI 3.14159265

namespace Micromachines {

	class NearCamera : public cg::Entity, public cg::IDrawListener {
	
	private:
		double _winWidth, _winHeight;
		double _rotation;
		std::vector <cg::Vector2d> _positionDelayed; //this vector will hold a list of previous car positions
		std::vector <double> _rotationDelayed;
		cg::Vector2d _position;
		Car* _car;

	public:
		NearCamera();
		virtual ~NearCamera();
		void init();
		void draw();
	};

}

#endif /* NearCamera_H_ */
