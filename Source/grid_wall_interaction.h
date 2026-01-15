#pragma once
#include "CoreMinimal.h"

class LogCommands;
class BaseGridCalculator;
class WallGenerator;
class AFloorGrid;
class GridClick;
class AWall;
class GlobalBuildManager;
class StorageGridData;

/**
 * GridWallInteractions - Handles wall placement and manipulation logic.
 *
 * Manages the complete wall interaction flow:
 * 1. Input processing (clicks, drags)
 * 2. Grid validation (can wall be placed here?)
 * 3. Preview visualization (real-time feedback)
 * 4. Wall instantiation (final placement)
 *
 * Works in tandem with GridTileData for spatial validation
 * and WallGenerator for mesh creation.
 */
class GAMEBUILDMODE_API GridWallInteractions
{

public:

  bool debug;

  GridWallInteractions(
    BaseGridCalculator* calculator,
    AFloorGrid* grid,
    GridClick* click,
    StorageGridData* tiles_data
  );

  /**
  * Processes wall placement interaction.
  * @param world_point - Click location in world space
  * @param is_pressed - True on mouse down, false on mouse up
  */
  void HandlePlaceWall(const FVector& world_point, bool is_pressed);


private:

  void PlaceWallBetweenCorners();
  void PlaceDiagonalWallLine();


  // ====================
  // PREVIEW MANAGEMENT
  // ====================

  void UpdatePreviewWall();
  void UpdateDiagonalPreview();
  void PlaceWallBetweenCornersPreview();

  void SpawnWallPreviewActor(
    const FVector& position,
    const FRotator& rotation,
    bool isDiagonal
  );

  void CancelWallPlacement();
  void ClearAllWallPreviews();



private:

  TUniquePtr<WallGenerator> wall_generator_;

  bool is_placing_wall_;

  // --- SINGLETONS ---
  LogCommands* log_;
  GlobalBuildManager* build_mode_manager_;

  // --- DEPENDENCIES (injected) ---
  StorageGridData* grid_data_;
  AFloorGrid* floor_grid_;
  GridClick* click_;
  BaseGridCalculator* calculator_;


  // --- VISUAL FEEDBACK ---
  TArray<AActor*> wall_preview_actors_;
  TArray<AActor*> diagonal_preview_actors_;
};
