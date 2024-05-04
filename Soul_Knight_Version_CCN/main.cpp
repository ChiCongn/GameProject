
#include"GameObject.h"

int main(int argv, char**argc)
{    
    std::cout << "Chi-Cong <3" << std::endl;
	std::cout << "Hmmm" << std::endl;

    // initialize
	GameObject* game = new GameObject;	    

    // Start    
    game->Running();
   
	std::cout << "OK!\n";
    delete game;
    //waitUntilKeyPressed();
    std::cout << "SUCCESS! <3" << std::endl;

	return 0;
}


