#pragma once
#include "../../class/entity.h"

class IClientEntityList
{
public:
	// Get IClientNetworkable interface for specified entity
	virtual void * GetClientNetworkable(int entnum) = 0;
	virtual void* GetClientNetworkableFromHandle(unsigned hEnt) = 0;
	virtual void* GetClientUnknownFromHandle(unsigned hEnt) = 0;

	// NOTE: This function is only a convenience wrapper.
	// It returns GetClientNetworkable( entnum )->GetIClientEntity().
	virtual CEntity* GetClientEntity(int entnum) = 0;
	virtual CEntity* GetClientEntityFromHandle(unsigned hEnt) = 0;

	// Returns number of entities currently in use
	virtual int					NumberOfEntities(bool bIncludeNonNetworkable) = 0;

	// Returns highest index actually used
	virtual int					GetHighestEntityIndex(void) = 0;

	// Sizes entity list to specified size
	virtual void				SetMaxEntities(int maxents) = 0;
	virtual int					GetMaxEntities() = 0;
};
