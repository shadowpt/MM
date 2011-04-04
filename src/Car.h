/*
 * Car.h
 *
 *  Created on: Jul 25, 2010
 *      Author: pinto
 */

#ifndef Car_H_
#define Car_H_

#include <string>
#include <ctime>
#include <math.h>
#include "cg.h"
#include "glm.h"

#define PI 3.14159265

namespace Micromachines {

	class Car : public cg::Entity,
		     public cg::IDrawListener,
		     public cg::IMouseEventListener,
		     public cg::IUpdateListener {

	private:
		double _winHeight;
		cg::Vector2d _position;
		cg::Vector2d _size;
		cg::Vector2d _appForce;
		cg::Vector2d _acceleration;
		cg::Vector2d _arrowKeyPressed;
		double _velocity;
		double _rotationSpeed;
		double _carRotation;
		double _atrittionFactor;
		double _mass;
		double _maxSpeed;
		double _movForce;
		
		
                 
        GLMmodel *model;

	public:
		Car(std::string id);
		~Car();
		void init();
		void draw();
		void onMouse(int button, int state, int x, int y);
		void onMouseMotion(int x, int y);
		void onMousePassiveMotion(int x, int y);
		void update(unsigned long elapsed_millis);
		void applyForce(cg::Vector2d force);
		void setArrowKeyPressed(cg::Vector2d val);
		void keyBreak(int direction);
		double getRotationSpeed();
		double getRotation();
		cg::Vector2d getPosition();
		cg::Vector2d getArrowKeyPressed();
	};

}

#endif /* Car_H_ */
