#pragma once
#include "Phase.h"
namespace Service {
	class Service
	{
	public:
		 virtual void update(Phase::PhaseContext& ctx) = 0;
	};
}