#include "GameWorld.h"
#include "Pyramid.h"

GameWorld::GameWorld (ApplicationMode mode) {
  asset_manager = std::make_shared<GameAssetManager>(mode);
 // asset_manager->AddAsset(std::make_shared<CubeAsset>());
  asset_manager ->AddAsset(std::make_shared<Pyramid>());
}



void GameWorld::Draw() {

  asset_manager->Draw();

}
