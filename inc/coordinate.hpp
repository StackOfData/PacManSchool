#ifndef COORDINATE_H
#define COORDINATE_H

#include <SDL.h>
#include <vector>

class Coordinate {
	/* Variables et constantes */
	public:
		static const int ALPHABET_TEXTURE_WIDTH{18};
		static const int NUMBER_TEXTURE_WIDTH{18};
		inline static const SDL_Rect NONE_FRUIT{0, 0, 0, 0};

		/**
		 * @brief =============== FOND DE CARTE ======================
		 *
		 */
		inline static const std::vector<SDL_Rect> backMap{{369, 3, 168, 216},
			{540, 3, 168, 216}};


		/**
		 * @brief =============== FRUITS =============================
		 *
		 */
		inline static const std::vector<SDL_Rect> cherry{{289, 257, 14, 14},
			{289, 237, 14, 14}};


		/**
		 * @brief =============== PERSONNAGES ========================
		 * Terminaison des variables :
		 * b -> "base"
		 * r -> "right"
		 * l -> "left"
		 * d -> "down"
		 * u -> "up"
		 */
		// Coordonnées de Pac-Man
		inline static const SDL_Rect pacLives{14, 976, 32, 32};

		inline static const std::vector<SDL_Rect> pacB{{3, 89, 16, 16}};
		inline static const std::vector<SDL_Rect> pacR{{20, 89, 15, 16},
			{35, 89, 11, 16}};
		inline static const std::vector<SDL_Rect> pacL{{47, 89, 15, 16},
			{63, 89, 11, 16}};
		inline static const std::vector<SDL_Rect> pacU{{75, 90, 16, 15},
			{92, 94, 16, 11}};
		inline static const std::vector<SDL_Rect> pacD{{109, 90, 16, 15},
			{126, 94, 16, 11}};
		inline static const SDL_Rect pacDefaultPos{324, 744, 32, 32};

		// Coordonnées du fantôme rouge
		inline static const std::vector<SDL_Rect> ghostRedR{{3, 123, 16, 16},
			{20, 123, 16, 16}};
		inline static const std::vector<SDL_Rect> ghostRedL{{37, 123, 16, 16},
			{54, 123, 16, 16}};
		inline static const std::vector<SDL_Rect> ghostRedU{{71, 123, 16, 16},
			{88, 123, 16, 16}};
		inline static const std::vector<SDL_Rect> ghostRedD{{105, 123, 16, 16},
			{122, 123, 16, 16}};
		inline static const SDL_Rect ghostRedDefaultPos{324, 424, 32, 32};

		// Coordonnées du fantôme bleu
		inline static const std::vector<SDL_Rect> ghostBlueR{{3, 159, 16, 16},
			{20, 159, 16, 16}};
		inline static const std::vector<SDL_Rect> ghostBlueL{{37, 159, 16, 16},
			{54, 159, 16, 16}};
		inline static const std::vector<SDL_Rect> ghostBlueU{{71, 159, 16, 16},
			{88, 159, 16, 16}};
		inline static const std::vector<SDL_Rect> ghostBlueD{{105, 159, 16, 16},
			{122, 159, 16, 16}};
		inline static const SDL_Rect ghostBlueDefaultPos{
			288, 504, 32, 32};

		// Coordonnées du fantôme rose
		inline static const std::vector<SDL_Rect> ghostPinkR{{3, 141, 16, 16},
			{20, 141, 16, 16}};
		inline static const std::vector<SDL_Rect> ghostPinkL{{37, 141, 16, 16},
			{54, 141, 16, 16}};
		inline static const std::vector<SDL_Rect> ghostPinkU{{71, 141, 16, 16},
			{88, 141, 16, 16}};
		inline static const std::vector<SDL_Rect> ghostPinkD{{105, 141, 16, 16},
			{122, 141, 16, 16}};
		inline static const SDL_Rect ghostPinkDefaultPos{
			324, 504, 32, 32};

		// Coordonnées du fantôme orange
		inline static const std::vector<SDL_Rect> ghostOrangeR{{3, 177, 16, 16},
			{20, 177, 16, 16}};
		inline static const std::vector<SDL_Rect> ghostOrangeL{
			{37, 177, 16, 16}, {54, 177, 16, 16}};
		inline static const std::vector<SDL_Rect> ghostOrangeU{
			{71, 177, 16, 16}, {88, 177, 16, 16}};
		inline static const std::vector<SDL_Rect> ghostOrangeD{
			{105, 177, 16, 16}, {122, 177, 16, 16}};
		inline static const SDL_Rect ghostOrangeDefaultPos{
			360, 504, 32, 32};

		// Coordonnées du fantôme apeuré
		inline static const std::vector<SDL_Rect> ghostAfraidBlue{
			{3, 195, 16, 16}, {20, 195, 16, 16}};
		inline static const std::vector<SDL_Rect> ghostAfraidWhite{
			{37, 195, 16, 16}, {54, 195, 16, 16}};


		/**
		 * @brief =============== MURS ===============================
		 *
		 */
		inline static const std::vector<SDL_Rect> walls{
			// ============= Murs de bordure =======
			// Zone haut gauche
			{1, 7, 8, 68},		// Rectangle - Gauche - V

			// Zone haut droite
			{161, 7, 8, 68},	// Rectangle - Droite - V

			// Zone bas gauche
			{1, 143, 8, 68},	// Rectangle - Gauche - V

			// Zone bas droite
			{161, 143, 8, 68},	// Rectangle - Gauche - V

			// Zone haut total
			{1, 1, 168, 8},		// Bordure - Haut - H

			// Zone bas total
			{1, 209, 168, 8},	// Bordure - Bas - H

			// Zone milieu gauche
			{1, 73, 40, 32},	// Bordure sortie - Haut
			{1, 113, 40, 32},	// Bordure sortie - Bas

			// Zone milieu droite
			{129, 73, 40, 32},	// Bordure sortie - Haut
			{129, 113, 40, 32},	// Bordure sortie - Bas

			// ============= Murs internes =========
			// Zone haut gauche
			{17, 17, 24, 24},	// Carré - Haut gauche
			{49, 17, 24, 24},	// Carré - Haut droite
			{17, 49, 24, 16},	// Rectangle - Bas gauche
			{49, 49, 8, 56},	// Rectangle - Double forme - V
			{55, 73, 18, 8},	// Rectangle - Double forme - H

			// Zone haut droite
			{97, 17, 24, 24},	// Carré - Haut gauche
			{129, 17, 24, 24},	// Carré - Haut droite
			{129, 49, 24, 16},	// Rectangle - Bas droite
			{113, 49, 8, 56},	// Rectangle - Double forme - V
			{97, 73, 18, 8},	// Rectangle - Double forme - H

			// Zone bas gauche
			{33, 159, 8, 26},	// Rectangle - Haut gauche - Double forme - V
			{17, 153, 24, 8},	// Rectangle - Haut gauche - Double forme - H
			{7, 169, 18, 16},	// Rectangle - Accolé à gauche
			{49, 169, 8, 26},	// Rectangle - Bas gauche - Double forme - V
			{17, 193, 56, 8},	// Rectangle - Bas gauche - Double forme - H
			{49, 153, 24, 8},	// Rectangle - Haut droite
			{49, 113, 8, 32},	// Rectangle - Haut centre

			// Zone bas droite
			{129, 159, 8, 26},	// Rectangle - Haut droite - Double forme V
			{129, 153, 24, 8},	// Rectangle - Haut droite - Double forme - H
			{145, 169, 18, 16},	// Rectangle - Accolé à droite
			{113, 169, 8, 26},	// Rectangle - Bas droite - Double forme - V
			{97, 193, 56, 8},	// Rectangle - Bas droite - Double forme - H
			{97, 153, 24, 8},	// Rectangle - Haut gauche
			{113, 113, 8, 32},	// Rectangle - Haut centre

			// Zone haut centre
			{81, 7, 8, 34},		// Rectangle - Haut
			{81, 63, 8, 18},	// Rectangle - Haut - Double forme - V
			{65, 49, 40, 16},	// Rectangle - Haut - Double forme - H

			// Zone milieu centre
			{65, 89, 7, 32},	// Rectangle - Cage gauche
			{98, 89, 7, 32},	// Rectangle - Cage droite
			{71, 113, 28, 8},	// Rectangle - Cage bas
			{71, 89, 9, 8},		// Rectangle - Porte gauche
			{88, 89, 9, 8},		// Rectangle - Porte droite

			// Zone bas centre
			{81, 143, 8, 18},	// Rectangle - Haut - Double forme - V
			{65, 129, 40, 16},	// Rectangle - Haut - Double forme - H
			{81, 183, 8, 18},	// Rectangle - Bas - Double forme - V
			{65, 169, 40, 16},	// Rectangle - Bas - Double forme - H
		};


		/**
		 * @brief =============== SORTIE SPAWN =======================
		 *
		 */
		inline static const SDL_Rect door{320, 456, 32, 32};


		/**
		 * @brief =============== TUNNELS ============================
		 *
		 */
		inline static const std::vector<SDL_Rect> tunnels{
			// Droite
			{166, 103, 1, 10},

			// Gauche
			{1, 103, 1, 10}
		};


		/**
		 * @brief =============== PAC-GOMME "dots" ===================
		 *
		 */
		inline static const SDL_Rect dotsTexture{4, 81, 2, 2};
		inline static const std::vector<SDL_Rect> dots{
			// ============= Ligne 1 ===============
			{11, 11, 1, 1},
			{19, 11, 1, 1},
			{27, 11, 1, 1},
			{35, 11, 1, 1},
			{43, 11, 1, 1},
			{51, 11, 1, 1},
			{59, 11, 1, 1},
			{67, 11, 1, 1},
			{75, 11, 1, 1},
			{91, 11, 1, 1},
			{99, 11, 1, 1},
			{107, 11, 1, 1},
			{115, 11, 1, 1},
			{123, 11, 1, 1},
			{131, 11, 1, 1},
			{139, 11, 1, 1},
			{147, 11, 1, 1},
			{155, 11, 1, 1},

			// ============= Ligne 2 ===============
			{11, 43, 1, 1},
			{19, 43, 1, 1},
			{27, 43, 1, 1},
			{35, 43, 1, 1},
			{43, 43, 1, 1},
			{51, 43, 1, 1},
			{59, 43, 1, 1},
			{67, 43, 1, 1},
			{75, 43, 1, 1},
			{83, 43, 1, 1},
			{91, 43, 1, 1},
			{99, 43, 1, 1},
			{107, 43, 1, 1},
			{115, 43, 1, 1},
			{123, 43, 1, 1},
			{131, 43, 1, 1},
			{139, 43, 1, 1},
			{147, 43, 1, 1},
			{155, 43, 1, 1},

			// ============= Ligne 3 ===============
			{11, 67, 1, 1},
			{19, 67, 1, 1},
			{27, 67, 1, 1},
			{35, 67, 1, 1},
			{43, 67, 1, 1},
			{59, 67, 1, 1},
			{67, 67, 1, 1},
			{75, 67, 1, 1},
			{91, 67, 1, 1},
			{99, 67, 1, 1},
			{107, 67, 1, 1},
			{123, 67, 1, 1},
			{131, 67, 1, 1},
			{139, 67, 1, 1},
			{147, 67, 1, 1},
			{155, 67, 1, 1},

			// ============= Ligne 4 ===============
			{11, 147, 1, 1},
			{19, 147, 1, 1},
			{27, 147, 1, 1},
			{35, 147, 1, 1},
			{43, 147, 1, 1},
			{51, 147, 1, 1},
			{59, 147, 1, 1},
			{67, 147, 1, 1},
			{75, 147, 1, 1},
			{91, 147, 1, 1},
			{99, 147, 1, 1},
			{107, 147, 1, 1},
			{115, 147, 1, 1},
			{123, 147, 1, 1},
			{131, 147, 1, 1},
			{139, 147, 1, 1},
			{147, 147, 1, 1},
			{155, 147, 1, 1},

			// ============= Ligne 5 ===============
			{19, 163, 1, 1},
			{27, 163, 1, 1},
			{43, 163, 1, 1},
			{51, 163, 1, 1},
			{59, 163, 1, 1},
			{67, 163, 1, 1},
			{75, 163, 1, 1},
			{91, 163, 1, 1},
			{99, 163, 1, 1},
			{107, 163, 1, 1},
			{115, 163, 1, 1},
			{123, 163, 1, 1},
			{139, 163, 1, 1},
			{147, 163, 1, 1},

			// ============= Ligne 6 ===============
			{11, 187, 1, 1},
			{19, 187, 1, 1},
			{27, 187, 1, 1},
			{35, 187, 1, 1},
			{43, 187, 1, 1},
			{59, 187, 1, 1},
			{67, 187, 1, 1},
			{75, 187, 1, 1},
			{91, 187, 1, 1},
			{99, 187, 1, 1},
			{107, 187, 1, 1},
			{123, 187, 1, 1},
			{131, 187, 1, 1},
			{139, 187, 1, 1},
			{147, 187, 1, 1},
			{155, 187, 1, 1},

			// ============= Ligne 7 ===============
			{11, 203, 1, 1},
			{19, 203, 1, 1},
			{27, 203, 1, 1},
			{35, 203, 1, 1},
			{43, 203, 1, 1},
			{51, 203, 1, 1},
			{59, 203, 1, 1},
			{67, 203, 1, 1},
			{75, 203, 1, 1},
			{83, 203, 1, 1},
			{91, 203, 1, 1},
			{99, 203, 1, 1},
			{107, 203, 1, 1},
			{115, 203, 1, 1},
			{123, 203, 1, 1},
			{131, 203, 1, 1},
			{139, 203, 1, 1},
			{147, 203, 1, 1},
			{155, 203, 1, 1},

			// =========== Colonne 1 ===========
			{11, 19, 1, 1},
			{11, 35, 1, 1},
			{11, 51, 1, 1},
			{11, 59, 1, 1},
			{11, 155, 1, 1},
			{11, 195, 1, 1},

			// ============ Colonne 2 ===========
			{27, 171, 1, 1},
			{27, 179, 1, 1},

			// ============ Colonne 3 ===========
			{43, 19, 1, 1},
			{43, 27, 1, 1},
			{43, 35, 1, 1},
			{43, 51, 1, 1},
			{43, 59, 1, 1},
			{43, 75, 1, 1},
			{43, 83, 1, 1},
			{43, 91, 1, 1},
			{43, 99, 1, 1},
			{43, 107, 1, 1},
			{43, 115, 1, 1},
			{43, 123, 1, 1},
			{43, 131, 1, 1},
			{43, 139, 1, 1},
			{43, 155, 1, 1},
			{43, 171, 1, 1},
			{43, 179, 1, 1},

			// ============= Colonne 4 ============
			{59, 51, 1, 1},
			{59, 59, 1, 1},
			{59, 171, 1, 1},
			{59, 179, 1, 1},

			// ============= Colonnne 5 ============
			{75, 19, 1, 1},
			{75, 27, 1, 1},
			{75, 35, 1, 1},
			{75, 155, 1, 1},
			{75, 195, 1, 1},

			// ============== Colonne 6 ============
			{91, 19, 1, 1},
			{91, 27, 1, 1},
			{91, 35, 1, 1},
			{91, 19, 1, 1},
			{91, 155, 1, 1},
			{91, 195, 1, 1},
			// =============== Colonne 7 ============
			{107, 51, 1, 1},
			{107, 59, 1, 1},
			{107, 171, 1, 1},
			{107, 179, 1, 1},

			// =============== Colonne 8 ==========
			{123, 19, 1, 1},
			{123, 27, 1, 1},
			{123, 35, 1, 1},
			{123, 51, 1, 1},
			{123, 59, 1, 1},
			{123, 75, 1, 1},
			{123, 83, 1, 1},
			{123, 91, 1, 1},
			{123, 99, 1, 1},
			{123, 107, 1, 1},
			{123, 115, 1, 1},
			{123, 123, 1, 1},
			{123, 131, 1, 1},
			{123, 139, 1, 1},
			{123, 155, 1, 1},
			{123, 171, 1, 1},
			{123, 179, 1, 1},

			// ============ Colonne 9 ===========
			{139, 171, 1, 1},
			{139, 179, 1, 1},

			// ============ Colonne 10 ==========
			{155, 19, 1, 1},
			{155, 35, 1, 1},
			{155, 51, 1, 1},
			{155, 59, 1, 1},
			{155, 155, 1, 1},
			{155, 195, 1, 1}
		};

		/**
		 * @brief =============== SUPER PAC-GOMME "energizer" ========
		 *
		 */
		inline static const SDL_Rect energizerTexture{9, 79, 7, 7};
		inline static const std::vector<SDL_Rect> energizers{
			{8, 24, 7, 7},
			{8, 160, 7, 7},
			{152, 24, 7, 7},
			{152, 160, 7, 7}
		};


		/**
		 * @brief =============== ALPHABET ===========================
		 *
		 */
		inline static const SDL_Rect alphabetTexture{25, 25,
			ALPHABET_TEXTURE_WIDTH, 18};
		inline static const std::vector<SDL_Rect> alphabet{
			/****** A - O (première colonne) *****/
			{11, 60, 9, 9},
			{19, 60, 9, 9},
			{27, 60, 9, 9},
			{35, 60, 9, 9},
			{43, 60, 9, 9},
			{51, 60, 9, 9},
			{59, 60, 9, 9},
			{67, 60, 9, 9},
			{75, 60, 9, 9},
			{83, 60, 9, 9},
			{91, 60, 9, 9},
			{99, 60, 9, 9},
			{107, 60, 9, 9},
			{115, 60, 9, 9},
			{123, 60, 9, 9},

			/****** P - Z (seconde colonne) ******/
			{3, 68, 9, 9},
			{11, 68, 9, 9},
			{19, 68, 9, 9},
			{27, 68, 9, 9},
			{35, 68, 9, 9},
			{43, 68, 9, 9},
			{51, 68, 9, 9},
			{59, 68, 9, 9},
			{67, 68, 9, 9},
			{75, 68, 9, 9},
			{83, 68, 9, 9}
		};

		/**
		 * @brief =============== CHIFFRES ===========================
		 *
		 */
		inline static const SDL_Rect numberTexture{25, 50, NUMBER_TEXTURE_WIDTH,
			18};
		inline static const std::vector<SDL_Rect> number{
			{3, 52, 9, 9},
			{11, 52, 9, 9},
			{19, 52, 9, 9},
			{27, 52, 9, 9},
			{35, 52, 9, 9},
			{43, 52, 9, 9},
			{51, 52, 9, 9},
			{59, 52, 9, 9},
			{67, 52, 9, 9},
			{75, 52, 9, 9}
		};


		/** 
		 * @brief =============== SYMBOLE =============================
		*/
		inline static const SDL_Rect hyphen{83, 52, 9, 9};

		/**
		 * @brief =============== MOTS ===============================
		 *
		 */
		inline static const std::vector<int> indexScore{18, 2, 14, 17, 4};
		inline static const std::vector<int> indexHigh{7, 8, 6, 7};
		inline static const std::vector<int> indexRank{17, 0, 13, 10};
		inline static const std::vector<int> indexPressSpace{
			15, 20, 18, 7, -1,
			18, 15, 0, 2, 4, -1,
			10, 4, 24
		};


		/**
		 * @brief =============== MENU ===============================
		 *
		 */
		inline static const SDL_Rect pacmanLogo{3, 3, 182, 48};
		inline static const SDL_Rect posPacmanLogo{67, 100, 546, 144};
		inline static const SDL_Rect namcoLogo{27, 77, 62, 10};
		inline static const SDL_Rect posNamcoLogo{278, 912, 124, 20};
};

#endif