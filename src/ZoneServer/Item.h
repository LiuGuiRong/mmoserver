/*
---------------------------------------------------------------------------------------
This source file is part of swgANH (Star Wars Galaxies - A New Hope - Server Emulator)
For more information, see http://www.swganh.org


Copyright (c) 2006 - 2009 The swgANH Team

---------------------------------------------------------------------------------------
*/

#ifndef ANH_ZONESERVER_ITEM_H
#define ANH_ZONESERVER_ITEM_H

#include "TangibleObject.h"
#include "Item_Enums.h"

//=============================================================================


class Item : public TangibleObject
{
	friend class ItemFactory;
	friend class NonPersistantObjectFactory;

	public:

		Item();
		virtual ~Item();

		uint32	getItemFamily(){ return mItemFamily; }
		void	setItemFamily(uint32 family){ mItemFamily = family; }

		uint32	getItemType(){ return mItemType; }
		void	setItemType(uint32 type){ mItemType = type; }

		uint32	getDynamicInt32(){ return mDynamicInt32; }
		void	setDynamicInt32(uint32 value){ mDynamicInt32 = value; }

		virtual void	handleObjectMenuSelect(uint8 messageType,Object* srcObject);
		virtual string	getBazaarName(){int8 name[128];
									sprintf(name,"@%s:%s",getNameFile().getAnsi(),getName().getAnsi()); 
									return name;  }

		virtual void	prepareCustomRadialMenu(CreatureObject* creatureObject, uint8 itemCount);

		//temporary Instruments
		bool	getPlaced(){ return mPlaced; }
		void	setPlaced(bool placed){ mPlaced = placed; }

		uint64	getNonPersistantCopy(){ return mNonPersistantCopy; }
		void	setNonPersistantCopy(uint64 copy){ mNonPersistantCopy = copy; }

		//gets the id of the persistant copy
		uint64	getPersistantCopy(){ return mPersistantCopy; }
		void	setPersistantCopy(uint64 copy){ mPersistantCopy = copy; }

		uint64	getOwner(){ return mOwner; }
		void	setOwner(uint64 owner){ mOwner = owner; }

		
	protected:

		uint32	mItemFamily;
		uint32	mItemType;
		uint32	mDynamicInt32;
		
		//temporary Instruments
		uint64  mNonPersistantCopy;
		uint64	mPersistantCopy;
		uint64	mOwner;
		bool	mPlaced;

		//sitable objects flag 1 = sit. 0 = no sit
		bool	mIsSitable;
};

//=============================================================================

#endif

