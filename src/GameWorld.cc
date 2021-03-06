#include "GameWorld.h"

GameWorld::GameWorld (ApplicationMode mode)
{
  asset_manager = std::make_shared<GameAssetManager>(mode);

  int mapping[4][4][4] = 
    {
      //y=        0         1         2          3
      /*x=0*/ {{1,0,0,0},{1,0,0,0},{1,0,0,0},{0,0,0,0}},
      /*x=1*/ {{0,0,0,0},{1,0,0,0},{0,0,0,0},{0,0,0,0}},
      /*x=2*/ {{2,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},
      /*x=3*/ {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}}
    };
  // x axis
     for(int i = 0; i<4;i++)
     {
    //y axis
     for(int j = 0;j<4;j++)
       {
       //z axis
       for(int k = 0;k<4;k++)
	 {
	   if(mapping[i][j][k]==1)
	     {
	        asset_manager->AddAsset(std::make_shared<CubeAsset>(i,j,k));
	   }else if(mapping[i][j][k]==2)
	     {
	        asset_manager->AddAsset(std::make_shared<PyramidAsset>(i,j,k));
	     }
         }
       }
     }
  
 
 }

void GameWorld::UpdateCameraPosition(Input input_direction, int mouseX, int mouseY){

asset_manager->UpdateCameraPosition(input_direction, mouseX, mouseY);

}


void GameWorld::Draw() {

  asset_manager->Draw();

}

void GameWorld::BindingTest(){
	std::cout << "Binding was successful" << std::endl;
}
