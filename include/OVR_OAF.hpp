#pragma once
#include "OVR.hpp"

// OVRService function IDs
#define OAF_OVRSERVICE_CHANGEFOCUS_FUNC_ID 3
#define OAF_OVRSERVICE_CHANGEINPUTFOCUS_FUNC_ID 5
#define OAF_OVRSERVICE_SETMODALSYSTEMOVERLAY_FUNC_ID 7
#define OAF_OVRSERVICE_SETDEPTHBUFFERSREQUESTSTATUS_FUNC_ID 9
#define OAF_OVRSERVICE_ACTIVATEHEADSET_FUNC_ID 24
#define OAF_OVRSERVICE_SETTRACKINGMODE_FUNC_ID 46

// OAF callback IDs
#define OAFSERVER_TESTCONNECTION_CALLBACK_ID 0
#define OAFSERVER_UPLOADCRASHREPORTS_CALLBACK_ID 1
#define OAFSERVER_RUN_CALLBACK_ID 2
#define OAFSERVER_TEARDOWN_CALLBACK_ID 3
#define OAF_NEWPROCESS_CALLBACK_ID 7
#define OAF_HMDEVENT_CALLBACK_ID 18
#define OAF_TRACKEREVENT_CALLBACK_ID 19

// OVRService functions
// TODO(Kaitlyn): Determine return values, if at all, also figure out unknown parameters as well.
static int32_t (*Oaf_OVRService_ChangeFocus)(uint32_t processId) = nullptr;
static int32_t (*Oaf_OVRService_ChangeInputFocus)(uint32_t processId, uint64_t a2) = nullptr;
static int32_t (*Oaf_OVRService_SetModalSystemOverlay)(ovrBool value) = nullptr;
static int32_t (*Oaf_OVRService_SetDepthBuffersRequestStatus)(ovrBool value) = nullptr;
static int32_t (*Oaf_OVRService_ActivateHeadset)(const char serialNumber[16], int32_t a2) = nullptr;
static uint8_t (*Oaf_OVRService_SetTrackingMode)(ovrBool value) = nullptr;

static void Oaf_Init(void* funcTable) {
  void** funcs = reinterpret_cast<void**>(static_cast<char*>(funcTable) + sizeof(uint64_t));
  Oaf_OVRService_ChangeFocus = decltype(Oaf_OVRService_ChangeFocus)(funcs[OAF_OVRSERVICE_CHANGEFOCUS_FUNC_ID]);
  Oaf_OVRService_ChangeInputFocus = decltype(Oaf_OVRService_ChangeInputFocus)(funcs[OAF_OVRSERVICE_CHANGEINPUTFOCUS_FUNC_ID]);
  Oaf_OVRService_SetModalSystemOverlay = decltype(Oaf_OVRService_SetModalSystemOverlay)(funcs[OAF_OVRSERVICE_SETMODALSYSTEMOVERLAY_FUNC_ID]);
  Oaf_OVRService_SetDepthBuffersRequestStatus = decltype(Oaf_OVRService_SetDepthBuffersRequestStatus)(funcs[OAF_OVRSERVICE_SETDEPTHBUFFERSREQUESTSTATUS_FUNC_ID]);
  Oaf_OVRService_ActivateHeadset = decltype(Oaf_OVRService_ActivateHeadset)(funcs[OAF_OVRSERVICE_ACTIVATEHEADSET_FUNC_ID]);
  Oaf_OVRService_SetTrackingMode = decltype(Oaf_OVRService_SetTrackingMode)(funcs[OAF_OVRSERVICE_SETTRACKINGMODE_FUNC_ID]);
}
