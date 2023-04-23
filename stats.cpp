#include "stats.h"

Stats::Stats(
	int dots,
	int energizers,
	int ghosts,
	int score
):
	dots_{dots},
	energizers_{energizers},
	ghosts_{ghosts},
	score_{score}
{};

Stats::~Stats() {};

/**
 * @brief Update the score according to the type of what have been eaten
 * 
 * @param earnedPoints number of points earned
 */
void Stats::updateScore(int earnedPoints) {
	switch (earnedPoints) {
		case DOT:
			this->addDot();
			break;

		case ENERGIZER:
			this->addEnergizer();
			break;

		default:
			break;
	}
};

/**
 * @brief Update the score according to the type of what have been eaten, but
 * take in account the number of ghosts eaten in the span of the "power pellet
 * mode"
 * 
 * @param earnedPoints number of points earned
 * @param eatenGhosts number of ghosts eaten in the span of the "power pellet
 * 					  mode"
 */
void Stats::updateScore(int earnedPoints, int eatenGhosts) {
	switch (earnedPoints) {
		case GHOST:
			this->addGhost(eatenGhosts);
			break;

		default:
			std::cerr << "This function is specific to ghosts" << std::endl;
			break;
	}
};

/**
 * @brief Check if the player has won the game
 */
void Stats::checkWon(void) {
	if (this->getDots() == 189) {
		std::cout << "You win!" << std::endl;
		writeScore();
	}
};

/**
 * @brief Write the score in the scores file
 */
void Stats::writeScore(void) {
	std::ofstream scoresFile(Stats::SCORES_FILE, std::ios_base::app);
	if (scoresFile.is_open()) {
			scoresFile << this->getScore() << std::endl;
		scoresFile.close();
	}
};

/**
 * @brief Uncompose a number into its digits
 * 
 * @param number number to uncompose
 * @return std::vector<int> vector of digits
 */
std::vector<int> Stats::uncomposeNumber(int number) {
	std::vector<int> digits;
	while (number > 0) {
		digits.push_back(number % 10);
		number /= 10;
	}
	return digits;
};