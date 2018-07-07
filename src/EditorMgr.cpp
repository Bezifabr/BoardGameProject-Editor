#include "EditorMgr.h"

void EditorMgr::Init(FieldMgr* fieldMgr, NPCMgr* npcMgr, DataMgr * data)
{
	fieldMgr_ = fieldMgr;
	npcMgr_ = npcMgr;
	data_ = data;
}

void EditorMgr::LoadConfig()
{
	data_->LoadDataFromFile("Config.txt");
	fieldMgr_->LoadFieldsFromFile("Config.txt");
	npcMgr_->LoadNPCFromFile("Config.txt");

}
