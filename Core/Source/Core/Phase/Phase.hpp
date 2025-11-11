#pragma once
namespace Phase {
	struct PhaseContext {
		sf::RenderWindow& window;
		float dt;
		bool running = true;
	};
	class Phase {
	public:
		void addLayer(std::unique_ptr<Layer> layer);

		void run(PhaseContext& ctx);

	private:
		std::vector<std::unique_ptr<Layer>> layers;
	};
}