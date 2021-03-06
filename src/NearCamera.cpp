/*
 * NearCamera.cpp
 *
 *  Created on: Jul 21, 2010
 *      Author: pinto
 */

#include "NearCamera.h"
#include "Car.h"
#include "PlayerManager.h"

namespace Micromachines {

	NearCamera::NearCamera() : Entity("NearCamera")
	{
	}

	NearCamera::~NearCamera()
	{
	}

	void NearCamera::init() {
		cg::tWindow win = cg::Manager::instance()->getApp()->getWindow();
		_pm = (PlayerManager*) cg::Registry::instance()->get("PlayerManager");
		_winWidth = win.width;
		_winHeight = win.height;
	}

	void NearCamera::draw()
	{	
		if (_car == NULL) {
			std::vector<Car*> players = _pm->getPlayers();
			_car = players[0];
		} else {
			_positionDelayed.push_back(_car->getPosition());
		
			if (_positionDelayed.size() > 20) {
				_rotationDelayed.push_back(_car->getRotation());
				if (_rotationDelayed.size() > 5) {
					_position = (-_positionDelayed.front());
					_rotation = (_rotationDelayed.front());
					glMatrixMode(GL_PROJECTION);
					glLoadIdentity();
					gluPerspective(60, _winWidth/_winHeight, 1, 3000);
					gluLookAt(-_position[0]-50*cos(_rotation*PI/180 + PI/2), 
						  -_position[1] - 50*sin(_rotation*PI/180 + PI/2), 
						  -385, 
						  -_position[0], -_position[1], -396, 0, 0 , 1);
					glMatrixMode(GL_MODELVIEW);
					glLoadIdentity();
					_positionDelayed.erase(_positionDelayed.begin());
					_rotationDelayed.erase(_rotationDelayed.begin());
				}
			}
		}
	}

}
