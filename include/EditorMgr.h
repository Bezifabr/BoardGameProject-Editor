#pragma once
#include "GUIMgr.h"

class EditorMgr
{
public:
	EditorMgr() {};
	~EditorMgr() {};

	/////////////////
	/// Prepares initialization settings
	///
	/// \param fieldMgr - Pointer to FieldMgr class object
	/// \param npcMgr - Pointer to NPCMgr class object
	/// \param data - Pointer to DataMgr class object
	///
	/////////////////
	void Init(FieldMgr* fieldMgr, NPCMgr* npcMgr, DataMgr* data);
	
	////////////////
	/// Loads data from Config.txt file
	///
	/// Includes:
	/// - Editor parameters
	/// - NPC templates
	/// - Field templates
	/// - Texture, sound and font files
	///
	////////////////
	void LoadConfig();

private:

	FieldMgr* fieldMgr_;
	NPCMgr* npcMgr_;
	DataMgr* data_;
};