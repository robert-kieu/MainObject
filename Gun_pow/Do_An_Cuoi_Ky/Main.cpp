#include"Header.h"
#include"MainObject.h"
#include"ThreatObject.h"

#include<conio.h>

using namespace std;
using namespace SDLcommon;

int main() {
	cout << " Loading...";
	_getch();
	int bgr_X = 0;
	bool isQuit = false;
	if (!inIt()) return 0;

	// transparent background
	g_background = loadImage("bkgr.png");
	if (g_background == NULL) return 0;

	//create main
	MainObject mainObject;
	mainObject.setRect(100, SCREEN_HEIGHT / 2);
	bool ret = mainObject.loadImg("main.png");
	if (!ret) return 0;

	// create threat
	ThreatObject* pThreats = new ThreatObject[NUM_THREATS];
	for (int i = 0; i < NUM_THREATS; i++) {
		ThreatObject* pThreat = (pThreats + i);
		if (pThreat) {
			ret = pThreat->loadImg("threat.png");
			if (!ret) return 0;

			int randY = rand() % SCREEN_HEIGHT;
			if (randY > SCREEN_HEIGHT - UNDER_LIMIT) randY = SCREEN_HEIGHT * 0.8;

			pThreat->setRect(SCREEN_WIDTH + i * UNDER_LIMIT * 2, randY);
			pThreat->setX_Val(4);

			AmoObject* p_Amo = new AmoObject();
			pThreat->inItAmo(p_Amo);
		}
	}

	//process image
	while (!isQuit) {
		while (SDL_PollEvent(&g_even)) {
			if (g_even.type == SDL_QUIT) {
				isQuit = true;
				break;
			} mainObject.handleInput(g_even);
		} 
		bgr_X -= 3;
		applySurface(g_background, g_screen, bgr_X, 0);
		applySurface(g_background, g_screen, bgr_X + SCREEN_WIDTH, 0);
		if (bgr_X <= -SCREEN_WIDTH) bgr_X = 0;
		
		// load main
		mainObject.handleMove();

		mainObject.show(g_screen);

		// load amo 
		mainObject.makeAmo(g_screen);

		for (int j = 0; j < NUM_THREATS; j++) {
			ThreatObject* pThreat = (pThreats + j);
			if (pThreat) {
				// run threat
				pThreat->handleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
				pThreat->show(g_screen);

				//amo of threat
				pThreat->makeAmo(g_screen, SCREEN_WIDTH, SCREEN_HEIGHT);

				//update screen soon(Maybe do not need)
				/*if (SDL_Flip(g_screen) == -1) return 0;*/

				//check collision
				bool isColi = SDLcommon::checkCollision(mainObject.getRect(), pThreat->getRect());
				if (isColi)
					if (MessageBox(NULL, L"GAME OVER", L"INFO", MB_OK) == IDOK) {
						//free memory
						delete[] pThreats;
						cleanUp();
						SDL_Quit();
						return 1;
					}
				vector<AmoObject*> amoList = mainObject.getAmoList();
				for (int k = 0; k < amoList.size(); k++) {
					AmoObject* p_amo = amoList.at(k);
					if (p_amo) {
						bool ret_col = SDLcommon::checkCollision(p_amo->getRect(), pThreat->getRect());
						if (ret_col) {
							pThreat->reset(SCREEN_WIDTH + j * UNDER_LIMIT * 2);
							mainObject.removeAmo(k);
						}
					}
				}
			}
		}

		if (SDL_Flip(g_screen) == -1) return 0;
	}

	//free memory
	delete[] pThreats;
	cleanUp();
	SDL_Quit();
	return 1;
}