
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "grid_tool_enums.h" 
#include "grid_calculator_enum.h" 
#include "instance.generated.h" 

// ================================================================
// 	               SYSTEM COORDINATOR: FloorGrid
// 	Central hub for grid-based editing operations in Build Mode.
// 	Delegates specialized tasks to focused subsystem managers.
// ================================================================

// --- SINGLETONS ---
class LogCommands;
class BuildModeManager;

// --- INTERFACE ---
class BaseGridCalculator;

// --- UNREAL COMPONENT ---
class UProceduralMeshComponent;

// --- GRID MEMBERS ---
class GridTileData;
class GridClick;
class GridWallInteractions;
class GridObjectInteractions;
class GridPathFinder;
class RoomsManager;

// UnrealEngine has its own naming conventions.
UCLASS()
class GAMEBUILDMODE_API AFloorGrid : public AActor {
	GENERATED_BODY()

public:

	int32 current_floor_index;
	AFloorGrid* floor_above;
	AFloorGrid* floor_below;
	
	/** Template with optimized operations, accessed via this interface. */
	BaseGridCalculator* calculator;
	
	TUniquePtr<DataFloor> data; // Holds tiles, tile edges, tile corners, and operations.
	TUniquePtr<GridClick> click;
	TUniquePtr<DataObjects> objects;
	
	// Member classes
	TUniquePtr<GridWallInteractions> wall_interactions;
	TUniquePtr<GridObjectInteractions> object_interactions;
	TUniquePtr<GridPathFinder> pathfinder;
	TUniquePtr<RoomsManager> rooms_manager;


	/** Enables debug logging and visualization. */
	bool debug = false;

	// Unreal Engine classes don't allow passing variables through the constructor.
	AFloorGrid();

	//It needs to be initialized manually.
	void Initialize(grid_calculator_enum::Lot lot_key, float floor_height);

	void HandleClick(EditTool tool, const FVector& world_point, bool is_pressed) const;

	UProceduralMeshComponent* CreateAndAttachProceduralMesh();

protected:
	virtual void BeginPlay() override {
		Super::BeginPlay();

		// This is just for test purposes; it will actually be called by the GlobalMap class.
		Initialize(grid_calculator_enum::Lot::kNeighbor1Lot1, 100.f);
	}

private:

	template<typename... Types>
	void Info(
		const FString& category, 
		const FString& format, 
		Types... args
		){
		
		if (!debug) return;
		Log::Infof(category, format, args...);
	}

	// Core systems
	LogCommands* log_;
	BuildModeManager* build_mode_manager_;
};

