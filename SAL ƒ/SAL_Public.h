#ifndef SAL_PUBLIC_H#define SAL_PUBLIC_H/***************************************************************************\|***************************************************************************||																			|| 	SimpleApp Framework: A Simple Application Framework						||		by Apple Macintosh Developer Technical Support						||																			||	File Name:	SAL_Public.h												||																			||	Contains:	SimpleAppLib public interface								||																			||	DRI: George Warner, Apple Developer Technical Support (dts@apple.com)	||																			||	Copyright:	� 1999 by Apple Computer,Inc., all rights reserved.			||																			||	You may incorporate this sample code into your applications without		||	restriction, though the sample code has been provided "AS IS" and the	||	responsibility for its operation is 100% yours.  However, what you are	||	not permitted to do is redistribute the source as "Apple Sample Code"	||	after having made changes. If you're going to re-distribute the source,	||	we require that you make it clear in the source that the code was		||	descended from Apple Sample Code, but that you've made changes.			||																			|| **************************************************************************||			C h a n g e		H i s t o r y (most recent first):				|| **************************************************************************||		Vers	  Date		Author		Description							||		----	--------	------	----------------------------------------||		2.0		 8/10/99	 gaw	Converted to C							||		1.0		 4/ 1/94	 mxm	Initial version							||***************************************************************************|\***************************************************************************//************************************************************\|*	NOTICE: This is an minimun header file for SAL;			*||*			It's just enough to build the sample apps.		*||*			SAL is a work in progress; we'll release more	*||*			as we write it.									*|\************************************************************/#if PRAGMA_ONCE#pragma once#endif#ifdef __cplusplusextern "C"{#endif#if PRAGMA_IMPORT#pragma import on#endif#if PRAGMA_STRUCT_ALIGN#pragma options align=mac68k#elif PRAGMA_STRUCT_PACKPUSH#pragma pack(push, 2)#elif PRAGMA_STRUCT_PACK#pragma pack(2)#endif#include <Controls.h>#include <Lists.h>/**\|**|	Typedefs, defines, enums, structs, etc.\**/enum{	kSAL_ErrorBase = 0,						//  Base value for ErrorNumbers	kSAL_StandardDebugAlert = 9999,	kSAL_NonFatalError = 0,	kSAL_FatalError = kSAL_ErrorBase - 1,	kSAL_BadSelectorErr = kSAL_ErrorBase - 2,	kSAL_BadProcPtr = kSAL_ErrorBase - 3,	kSAL_NotOurWindowError = kSAL_ErrorBase - 4,	kSAL_NotValidObject = kSAL_ErrorBase - 5};enum{	kSAL_UseStandardMenu = true,	kSAL_MenuStartID = 127,	kSAL_AppleNum = 128,	kSAL_FileNum = 129,	kSAL_EditNum = 130,	kSAL_EditMenu = 3,	kSAL_UndoItem = 1,	//kSAL_Undefined = 2,	kSAL_CutItem = 3,	kSAL_CopyItem = 4,	kSAL_PasteItem = 5,	kSAL_ClearItem = 6};//key navigationenum{	kSAL_NoKey = 0,	kSAL_NoCommandKey = 0,	kSAL_UpArrow = 30,	kSAL_DownArrow = 31,	kSAL_EnterKey = 3,	kSAL_ReturnKey = 13,	kSAL_TabKey = 9};//List Flagsenum{	kSAL_ListDrawFrame = 1,	kSAL_ListVScroll = 2,	kSAL_ListHScroll = 4,	kSAL_ListCustomLDEF = 8,	kSAL_ListDrawingOn = 16,	kSAL_ListHasGrow = 32,	kSAL_ListWantsDrag = 64,	kSAL_StandardList = kSAL_ListDrawFrame + kSAL_ListVScroll + kSAL_ListDrawingOn};enum{	kSAL_MagicSig = 0x4D584D21,				// 'MXM!' our magic signature	kSAL_MaxMenus = 20,	kSAL_MaxMenuItems = 128,	kSAL_MaxButtons = 128,	kSAL_MaxEventProc = 10,	kSAL_AppleEventLoadingErr = 129,	kSAL_EventPassThru = true,// This lets the event pass thru to the default handler	kSAL_EventOverRide = false,				// This overides the event and doesn't call to the default handler	kSAL_ResultNoErr = noErr,	kSAL_ResultPassThru = 1,	kSAL_ResultOverride = 0,	kSAL_DefaultStackSize = (SInt32)(24 * 1024),	kSAL_Margin = 5};typedef Str255				StringArray[];typedef StringArray*		StringArray_Ptr;typedef StringArray_Ptr*	StringArray_Hdl;typedef ControlHandle		ControlArray[];typedef ControlArray*		ControlArray_Ptr;typedef ControlArray_Ptr*	ControlArray_Hdl;// Opaque referencestypedef struct ButtonItem_Struct**	ButtonItemRef;typedef struct Group_Struct**		GroupRecRef;typedef struct ListItem_Struct**	ListItemRef;typedef struct ObjectItem_Struct**	ObjectRef;typedef struct WindowItem_Struct**	WindowItemRef;// ProcPtr'stypedef pascal void		(*SalAction_ProcPtr)(const ControlHandle pCtrlHdl,										 const SInt16 pPart);typedef pascal OSErr	(*SalButtonHit_ProcPtr)(const ButtonItemRef pButtonItemRef,											 const SInt32 pModifiers);typedef pascal OSErr	(*SalButtonUpdate_ProcPtr)(const SInt32 pModifiers);typedef pascal OSErr	(*SalEvent_ProcPtr)(const EventRecord* pEventPtr);typedef pascal Boolean	(*SalAbout_ProcPtr)(const SInt32 pData);typedef pascal OSErr	(*SalListHit_ProcPtr)(const Boolean pIsDoubleClick,										   const Point pCell,										   const Rect* pBounds,										   const ListItemRef pListItemRef);typedef pascal OSErr	(*SalListTrack_ProcPtr)(const EventRecord* pEventPtr,											 const ListItemRef pListItemRef);typedef pascal OSErr	(*SalListUpdate_ProcPtr)(const RgnHandle pUpdateRgn_Hdl,											  const ListItemRef pListItemRef);typedef pascal void		(*SalListDrawCell_ProcPtr)(const Point pCell,											   const Rect* pBounds,											   const ListItemRef pListItemRef);typedef pascal OSErr	(*SalListIdle_ProcPtr)(const EventRecord* pEventPtr,											const ListItemRef pListItemRef);typedef pascal OSErr	(*SalListKey_ProcPtr)(EventRecord* pEventPtr,										   ListItemRef pListItemRef);typedef pascal OSErr	(*SalMenuEvent_ProcPtr)(const SInt32 pMenuResult);typedef pascal OSErr	(*SalMenuHit_ProcPtr)(const SInt32 pModifiers);typedef pascal OSErr	(*SalMenuUpdate_ProcPtr)(const SInt32 pModifiers);typedef pascal OSErr	(*SalWindowHit_ProcPtr)(const WindowItemRef pWIR,											 const EventRecord* pEventPtr);typedef pascal OSErr	(*SalWindowUpdate_ProcPtr)(const SInt32 pModifiers);typedef pascal OSErr	(*SalWindowResize_ProcPtr)(const WindowPtr pWindowPtr);typedef pascal Boolean	(*SalGroupPreHit_ProcPtr)(const SInt32 pModifiers,												 const Point pPoint,												 const ControlArray_Ptr pCAP,												 const SInt16 pCount);typedef pascal OSErr	(*SalGroupPostHit_ProcPtr)(const SInt32 pModifiers,												const ControlHandle pCtrl_Hdl,												const ButtonItemRef pBIR,												const SInt16 pItem);typedef pascal OSErr	(*SalGroupUpdate_ProcPtr)(const WindowPtr pWindowPtr,											   const GroupRecRef pGroupRecRef);/**\|**|	external globals\**/extern SInt16			gSAL_NumberOfWindows;extern WindowPtr		gSAL_CurrentWindow;extern WindowItemRef	gSAL_CurrentWindowItemRef;extern ControlHandle	gSAL_CurrentControl;extern ListHandle		gSAL_CurrentList;extern TextStyle		gSAL_DefaultStyle;extern TextStyle		gSAL_TextStyle;extern SysEnvRec		gSAL_Mac;/**\|**|	external function prototypes\**///-----------------------------------------------------------------------------//	Application//-----------------------------------------------------------------------------// Initialize SimpleAppextern pascal void SAL_InitSimpleApp(const SInt16 pMasters,									 const Boolean pWantsStandardMenu);// Runextern pascal void SAL_Run(void);extern pascal OSErr SAL_AddStringToList(const ListHandle pListID,										const Str255 pStr255);// Get & Set the print areaextern pascal void SAL_GetPrintArea(const WindowPtr pWindowPtr,									Rect* pBounds);extern pascal void SAL_SetPrintArea(const WindowPtr pWindowPtr,									const Rect* pBounds);// Print no CRextern pascal void SAL_Print(const StringPtr pStringPtr);// Print with CRextern pascal void SAL_PrintLine(const StringPtr pStringPtr);// Print a buffer full of text with CRextern pascal void SAL_PrintTextHandle(const Handle pText_Hdl);extern pascal void SAL_SetCursorBusy(void);extern pascal void SAL_DefaultCursor(void);//-----------------------------------------------------------------------------//	Controls//-----------------------------------------------------------------------------extern pascal Rect SAL_GetGroupBounds(GroupRecRef pGroupRecRef);extern pascal OSErr SAL_InstallCheckBox(const SInt32 pButtonID,										const WindowPtr pWindowPtr,										const Str255 pName,										const Rect* pRect,										const UInt8 pCmdKey,										const SInt16 pInitialValue,										const SalButtonHit_ProcPtr pBHP,										const SalButtonUpdate_ProcPtr pBUP);extern pascal OSErr SAL_InstallPushButton(const SInt32 pButtonID,										  const WindowPtr pWindowPtr,										  const Str255 pName,										  const Rect* pRect,										  const UInt8 pCmdKey,										  const SalButtonHit_ProcPtr pBHP,										  const SalButtonUpdate_ProcPtr pBUP);extern pascal OSErr SAL_InstallRadioGroup(const SInt32 pGroupID,										  const WindowPtr pWindowPtr,										  const SInt16 pCount,										  const Str255 pTitle,										  const StringArray_Ptr pNames,										  const Rect* pRect,										  const SInt16 pDefaultItem,										  const SInt16 pSpacingH,										  const SInt16 pSpacingV,										  const SInt16 pButtonHeight,										  const SInt16 pButtonWidth,										  const SalGroupPreHit_ProcPtr pPreGHP,										  const SalGroupPostHit_ProcPtr pPostGHP,										  const SalGroupUpdate_ProcPtr pGUP);extern pascal void SAL_DisableMe(void);extern pascal void SAL_EnableMe(void);extern pascal void SAL_SetTitle(const StringPtr pTitle);//-----------------------------------------------------------------------------//	Error Unit//-----------------------------------------------------------------------------extern pascal void SAL_ErrorMessage(const StringPtr pMessage,									const OSStatus pOSStatus,									const SInt16 pFlags);//-----------------------------------------------------------------------------//	Lists//-----------------------------------------------------------------------------extern pascal OSErr SAL_InstallList(const SInt32 pListID,									const WindowPtr pWindowPtr,									const Point pCellSize,									const Rect* pRect,									const SalListHit_ProcPtr pLHP,									const SalListTrack_ProcPtr pLTP,									const SalListUpdate_ProcPtr pLUP,									const SalListDrawCell_ProcPtr pLDCP,									const ListDefUPP pLDefUPP,									const SInt32 pFlags);//-----------------------------------------------------------------------------//	Menus//-----------------------------------------------------------------------------extern pascal OSErr SAL_AttachMenuToMenuItem(const SInt16 pMenuIDToAdd,											 const SInt16 pAttachMenuID,											 const SInt16 pAttachMenuItem);extern pascal OSErr SAL_InstallFontMenu(const SInt16 pMenuID,										const Str255 pName,										const Boolean pIsHeirarchical,										const SalMenuHit_ProcPtr pMHP,										const SalMenuUpdate_ProcPtr pMUP);extern pascal OSErr SAL_InstallMenu(const SInt16 pMenuID,									const Str255 pMenuTitle,									const Boolean pIsHierarchical,									const SalMenuHit_ProcPtr pMHP,									const SalMenuUpdate_ProcPtr pMUP);extern pascal OSErr SAL_InstallMenuItem(const SInt16 pMenuID,										const SInt16 pMenuItem,										const Str255 pMenuTitle,										const char pMarkChar,										const char pCmdChar,										const SalMenuHit_ProcPtr pMHP,										const SalMenuUpdate_ProcPtr pMUP);extern pascal OSErr SAL_InstallResourceMenu(const SInt16 pMenuID,											const Str255 pMenuTitle,											const OSType pResType,											const Boolean pIsHiearchical,											const SalMenuHit_ProcPtr pMHP,											const SalMenuUpdate_ProcPtr pMUP);//-----------------------------------------------------------------------------//	Objects//-----------------------------------------------------------------------------extern pascal void SAL_DisableObject(const SInt32 pThing);extern pascal void SAL_EnableObject(const SInt32 pThing);extern pascal SInt32 SAL_GetObjectRefCon(const SInt32 pThing);extern pascal void SAL_SetObjectRefCon(const SInt32 pThing,									   SInt32 pRefCon);extern pascal Handle SAL_GetObjectHandle(const SInt32 pThing);//-----------------------------------------------------------------------------//	ProcUnit//-----------------------------------------------------------------------------extern pascal void SAL_InstallIdleProc(const SalEvent_ProcPtr pEventProc);extern pascal void SAL_InstallAboutProc(const SalAbout_ProcPtr pAboutProc);//-----------------------------------------------------------------------------//	ScrollBars//-----------------------------------------------------------------------------extern pascal OSErr SAL_InstallScrollBar(const SInt32 pButtonID,										 const WindowPtr pWindowPtr,										 const Str255 pName,										 const Rect* pRect,										 const UInt8 pCmdKey,										 const SalAction_ProcPtr pSHP,										 const SalAction_ProcPtr pSBP,										 const SalAction_ProcPtr pSIP);//-----------------------------------------------------------------------------//	Utils//-----------------------------------------------------------------------------extern pascal SInt8 SAL_LockHandle(Handle pHandle);extern pascal void SAL_UnlockHandle(Handle pHandle,									const SInt8 pState);// This Sets a rects anchor pointextern pascal void SAL_SetRectLocation(Rect* pRect,									   const SInt16 pH,									   const SInt16 pV);// This Sets its size without changing its positionextern pascal void SAL_SetRectDimensions(Rect* pRect,										 const SInt16 pH,										 const SInt16 pV);//-----------------------------------------------------------------------------//	Windows//-----------------------------------------------------------------------------// Deprecated funtion do not useextern pascal SInt16 SAL_GetDocWindow(SInt16 pResID);extern pascal SInt16 SAL_GetDocumentWindow(const SInt16 pResID,										   WindowPtr* pWindowPtr);extern pascal void SAL_SetWindowUpdateProc(const WindowPtr pWindowPtr,										   const SalWindowUpdate_ProcPtr pWindowUpdateProc);extern pascal void SAL_SetWindowResizeProc(const WindowPtr pWindowPtr,										   const SalWindowResize_ProcPtr pWRP);extern pascal OSErr SAL_DoWindowClose(const WindowPtr pWindowPtr);//-----------------------------------------------------------------------------#if PRAGMA_STRUCT_ALIGN#pragma options align=reset#elif PRAGMA_STRUCT_PACKPUSH#pragma pack(pop)#elif PRAGMA_STRUCT_PACK#pragma pack()#endif#ifdef PRAGMA_IMPORT_OFF#pragma import off#elif PRAGMA_IMPORT#pragma import reset#endif#ifdef __cplusplus}#endif#endif SAL_PUBLIC_H