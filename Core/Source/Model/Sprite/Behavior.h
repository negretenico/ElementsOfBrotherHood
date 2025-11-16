#pragma once
namespace Sprite {
	class Behavior {
		//Virtual keyword here implies we have to allocate some bytes for the Vlookup table
	public:
		virtual ~Behavior() = default;
		virtual void update(float dt) = 0;
	};
}