/*=============================================================================
Copyright (c) 2010 Broadcom Europe Limited.
All rights reserved.

Project  :  CEC Service
Module   :  Common host interface
File     :  $Id: //software/customers/broadcom/mobcom/vc4/rel/interface/vmcs_host/vc_cec.h#2 $
Revision :  $Revision: #2 $

FILE DESCRIPTION
CEC related constants - shared by both host and vc.

=============================================================================*/
#ifndef _VC_CEC_H_
#define _VC_CEC_H_
//Broadcast address and TV logical address
#define CEC_BROADCAST_ADDR       0x0F
#define CEC_TV_ADDRESS           0x00

//Maximum transmit length excluding the header byte */
#define CEC_MAX_XMIT_LENGTH      15  /* +1 for CEC Header Length */
//Invalid physical address
#define CEC_CLEAR_ADDR           0xFFFF  /* packed 16 bits of F.F.F.F */

/**
 * These are the logical addresses for all possible attached devices
 */
typedef enum CEC_AllDevices {
   CEC_AllDevices_eTV = 0,            /**<TV only */
   CEC_AllDevices_eRecDevice1,        /**<Address for 1st Recording Device */
   CEC_AllDevices_eRecDevice2,        /**<Address for 2nd Recording Device */
   CEC_AllDevices_eSTB1,              /**<Address for 1st SetTop Box Device */
   CEC_AllDevices_eDVD1,              /**<Address for 1st DVD Device */
   CEC_AllDevices_eAudioSystem,       /**<Address for Audio Device */
   CEC_AllDevices_eSTB2,              /**<Address for 2nd SetTop Box Device */
   CEC_AllDevices_eSTB3,              /**<Address for 3rd SetTop Box Device */
   CEC_AllDevices_eDVD2,              /**<Address for 2nd DVD Device */
   CEC_AllDevices_eRecDevice3,        /**<Address for 3rd Recording Device */
   CEC_AllDevices_eSTB4,              /**<10 Address for 4th Tuner Device */
   CEC_AllDevices_eDVD3,              /**<11 Address for 3rd DVD Device */
   CEC_AllDevices_eRsvd3,             /**<Reserved and cannot be used */
   CEC_AllDevices_eRsvd4,             /**<Reserved and cannot be used */
   CEC_AllDevices_eFreeUse,           /**<Free Address, use for any device */
   CEC_AllDevices_eUnRegistered = 15  /**<UnRegistered Devices */
} CEC_AllDevices_T;

/**
 * define device types for <Report Physical Address>
 */
typedef enum CEC_DeviceTypes{
   CEC_DeviceType_TV           = 0, /**<TV only */
   CEC_DeviceType_Rec          = 1, /**<Recoding device */
   CEC_DeviceType_Reserved     = 2, /**<Reserved */
   CEC_DeviceType_Tuner        = 3, /**<STB */
   CEC_DeviceType_Playback     = 4, /**<DVD player */
   CEC_DeviceType_Audio        = 5, /**<AV receiver */

   CEC_DeviceType_Invalid      = 0xF, //RESERVED - DO NOT USE
} CEC_DEVICE_TYPE_T;

/**
 * Generic CEC opcode
 */
typedef enum {
   CEC_Opcode_FeatureAbort 	            = 0x00,
   CEC_Opcode_ImageViewOn 	            = 0x04,
   CEC_Opcode_TunerStepIncrement    	    = 0x05,
   CEC_Opcode_TunerStepDecrement    	    = 0x06,
   CEC_Opcode_TunerDeviceStatus 	    = 0x07,
   CEC_Opcode_GiveTunerDeviceStatus 	    = 0x08,
   CEC_Opcode_RecordOn 	                    = 0x09,
   CEC_Opcode_RecordStatus 	            = 0x0A,
   CEC_Opcode_RecordOff 	            = 0x0B,
   CEC_Opcode_TextViewOn 	            = 0x0D,
   CEC_Opcode_RecordTVScreen                = 0x0F,
   CEC_Opcode_GiveDeckStatus        	    = 0x1A,
   CEC_Opcode_DeckStatus 	            = 0x1B,
   CEC_Opcode_SetMenuLanguage               = 0x32,
   CEC_Opcode_ClearAnalogTimer              = 0x33,
   CEC_Opcode_SetAnalogTimer                = 0x34,
   CEC_Opcode_TimerStatus                   = 0x35,
   CEC_Opcode_Standby 	                    = 0x36,
   CEC_Opcode_Play                  	    = 0x41,
   CEC_Opcode_DeckControl 	            = 0x42,
   CEC_Opcode_TimerClearedStatus            = 0x43,
   CEC_Opcode_UserControlPressed 	    = 0x44,
   CEC_Opcode_UserControlReleased 	    = 0x45,
   CEC_Opcode_GiveOSDName           	    = 0x46,
   CEC_Opcode_SetOSDName 	            = 0x47,
   CEC_Opcode_SetOSDString 	            = 0x64,
   CEC_Opcode_SetTimerProgramTitle          = 0x67,
   CEC_Opcode_SystemAudioModeRequest        = 0x70,
   CEC_Opcode_GiveAudioStatus               = 0x71,
   CEC_Opcode_SetSystemAudioMode            = 0x72,
   CEC_Opcode_ReportAudioStatus             = 0x7A,
   CEC_Opcode_GiveSystemAudioModeStatus     = 0x7D,
   CEC_Opcode_SystemAudioModeStatus         = 0x7E,
   CEC_Opcode_RoutingChange 	            = 0x80,
   CEC_Opcode_RoutingInformation 	    = 0x81,
   CEC_Opcode_ActiveSource 	            = 0x82,
   CEC_Opcode_GivePhysicalAddress           = 0x83,
   CEC_Opcode_ReportPhysicalAddress         = 0x84,
   CEC_Opcode_RequestActiveSource 	    = 0x85,
   CEC_Opcode_SetStreamPath 	            = 0x86,
   CEC_Opcode_DeviceVendorID 	            = 0x87,
   CEC_Opcode_VendorCommand         	    = 0x89,
   CEC_Opcode_VendorRemoteButtonDown 	    = 0x8A,
   CEC_Opcode_VendorRemoteButtonUp    	    = 0x8B,
   CEC_Opcode_GiveDeviceVendorID    	    = 0x8C,
   CEC_Opcode_MenuRequest 	            = 0x8D,
   CEC_Opcode_MenuStatus 	            = 0x8E,
   CEC_Opcode_GiveDevicePowerStatus 	    = 0x8F,
   CEC_Opcode_ReportPowerStatus 	    = 0x90,
   CEC_Opcode_GetMenuLanguage               = 0x91,
   CEC_Opcode_SelectAnalogService           = 0x92,
   CEC_Opcode_SelectDigitalService   	    = 0x93,
   CEC_Opcode_SetDigitalTimer               = 0x97,
   CEC_Opcode_ClearDigitalTimer             = 0x99,
   CEC_Opcode_SetAudioRate                  = 0x9A,
   CEC_Opcode_InactiveSource        	    = 0x9D,
   CEC_Opcode_CECVersion                    = 0x9E,
   CEC_Opcode_GetCECVersion                 = 0x9F,
   CEC_Opcode_VendorCommandWithID           = 0xA0,
   CEC_Opcode_ClearExternalTimer            = 0xA1,
   CEC_Opcode_SetExternalTimer              = 0xA2,
   CEC_Opcode_ReportShortAudioDescriptor    = 0xA3,
   CEC_Opcode_RequestShortAudioDescriptor   = 0xA4,
   CEC_Opcode_Abort        	            = 0xFF
} CEC_OPCODE_T;

/**
 * Reason parameter for <Feature Abort>
 */
typedef enum {
   CEC_Abort_Reason_Unrecognised_Opcode   = 0,
   CEC_Abort_Reason_Wrong_Mode            = 1,
   CEC_Abort_Reason_Cannot_Provide_Source = 2,
   CEC_Abort_Reason_Invalid_Operand       = 3,
   CEC_Abort_Reason_Refused               = 4,
   CEC_Abort_Reason_Undetermined          = 5
} CEC_ABORT_REASON_T;

/**
 * Display control parameter for <Set OSD string>
 */
typedef enum {
   CEC_DISPLAY_CONTROL_DEFAULT_TIME       = 0,
   CEC_DISPLAY_CONTROL_UNTIL_CLEARED      = (1<<6),
   CEC_DISPLAY_CONTROL_CLEAR_PREV_MSG     = (1<<7)
} CEC_DISPLAY_CONTROL_T;

/**
 * Power status parameter for <Report Power Status>
 */
typedef enum {
   CEC_POWER_STATUS_ON                    = 0,
   CEC_POWER_STATUS_STANDBY               = 1,
   CEC_POWER_STATUS_ON_PENDING            = 2,
   CEC_POWER_STATUS_STANDBY_PENDING       = 3
} CEC_POWER_STATUS_T;

/**
 * Menu state parameter for <Menu Status>
 */
typedef enum {
   CEC_MENU_STATE_ACTIVATED               = 0,
   CEC_MENU_STATE_DEACTIVATED             = 1,
   CEC_MENU_STATE_QUERY                   = 2
} CEC_MENU_STATE_T;

/**
 * Button code for <User Control Pressed>
 */
typedef enum {
   CEC_User_Control_Select                      = 0x00,
   CEC_User_Control_Up                          = 0x01,
   CEC_User_Control_Down                        = 0x02,
   CEC_User_Control_Left                        = 0x03,
   CEC_User_Control_Right                       = 0x04,
   CEC_User_Control_RightUp                     = 0x05,
   CEC_User_Control_RightDown                   = 0x06,
   CEC_User_Control_LeftUp                      = 0x07,
   CEC_User_Control_LeftDown                    = 0x08,
   CEC_User_Control_RootMenu                    = 0x09,
   CEC_User_Control_SetupMenu                   = 0x0A,
   CEC_User_Control_ContentsMenu                = 0x0B,
   CEC_User_Control_FavoriteMenu                = 0x0C,
   CEC_User_Control_Exit                        = 0x0D,
   CEC_User_Control_Number0                     = 0x20,
   CEC_User_Control_Number1                     = 0x21,
   CEC_User_Control_Number2                     = 0x22,
   CEC_User_Control_Number3                     = 0x23,
   CEC_User_Control_Number4                     = 0x24,
   CEC_User_Control_Number5                     = 0x25,
   CEC_User_Control_Number6                     = 0x26,
   CEC_User_Control_Number7                     = 0x27,
   CEC_User_Control_Number8                     = 0x28,
   CEC_User_Control_Number9                     = 0x29,
   CEC_User_Control_Dot                         = 0x2A,
   CEC_User_Control_Enter                       = 0x2B,
   CEC_User_Control_Clear                       = 0x2C,
   CEC_User_Control_ChannelUp                   = 0x30,
   CEC_User_Control_ChannelDown                 = 0x31,
   CEC_User_Control_PreviousChannel             = 0x32,
   CEC_User_Control_SoundSelect                 = 0x33,
   CEC_User_Control_InputSelect                 = 0x34,
   CEC_User_Control_DisplayInformation          = 0x35,
   CEC_User_Control_Help                        = 0x36,
   CEC_User_Control_PageUp                      = 0x37,
   CEC_User_Control_PageDown                    = 0x38,
   CEC_User_Control_Power                       = 0x40,
   CEC_User_Control_VolumeUp                    = 0x41,
   CEC_User_Control_VolumeDown                  = 0x42,
   CEC_User_Control_Mute                        = 0x43,
   CEC_User_Control_Play                        = 0x44,
   CEC_User_Control_Stop                        = 0x45,
   CEC_User_Control_Pause                       = 0x46,
   CEC_User_Control_Record                      = 0x47,
   CEC_User_Control_Rewind                      = 0x48,
   CEC_User_Control_FastForward                 = 0x49,
   CEC_User_Control_Eject                       = 0x4A,
   CEC_User_Control_Forward                     = 0x4B,
   CEC_User_Control_Backward                    = 0x4C,
   CEC_User_Control_Angle                       = 0x50,
   CEC_User_Control_Subpicture                  = 0x51,
   CEC_User_Control_VideoOnDemand               = 0x52,
   CEC_User_Control_EPG                         = 0x53,
   CEC_User_Control_TimerProgramming            = 0x54,
   CEC_User_Control_InitialConfig               = 0x55,
   CEC_User_Control_PlayFunction                = 0x60,
   CEC_User_Control_PausePlayFunction           = 0x61,
   CEC_User_Control_RecordFunction              = 0x62,
   CEC_User_Control_PauseRecordFunction         = 0x63,
   CEC_User_Control_StopFunction                = 0x64,
   CEC_User_Control_MuteFunction                = 0x65,
   CEC_User_Control_RestoreVolumeFunction       = 0x66,
   CEC_User_Control_TuneFunction                = 0x67,
   CEC_User_Control_SelectDiskFunction          = 0x68,
   CEC_User_Control_SelectAVInputFunction       = 0x69,
   CEC_User_Control_SelectAudioInputFunction    = 0x6A,
   CEC_User_Control_F1Blue                      = 0x71,
   CEC_User_Control_F2Red                       = 0x72,
   CEC_User_Control_F3Green                     = 0x73,
   CEC_User_Control_F4Yellow                    = 0x74,
   CEC_User_Control_F5                          = 0x75
} CEC_USER_CONTROL_T;

/**
 *CEC topology struct
 *
 * Meaning of device_attr is as follows (one per active logical device)
 * bit 3-0 logical address (see CEC_AllDevices_T above)
 * bit 7-4 device type (see CEC_DEVICE_TYPE_T above)
 * bit 11-8 index to upstream device
 * bit 15-12 number of downstream device
 * bit 31-16 index of first 4 downstream devices
 * 
 * To keep life simple we only show the first 4 connected downstream devices
 *
 */
typedef struct {
   uint16_t active_mask;       /**<bit n is set if logical device n is active */
   uint16_t num_devices;       /**<no. of bits set above, save us from counting */
   uint32_t device_attr[15];   /**<Device attribute, see above for explanation */
} VC_CEC_TOPOLOGY_T;

/**
 * CEC related notification
 */
typedef enum {
   VC_CEC_NOTIFY_NONE     = 0,        //Reserved - NOT TO BE USED
   VC_CEC_TX              = (1 << 0), /**<A message has been transmitted */
   VC_CEC_RX              = (1 << 1), /**<A message has arrived (only for registered commands) */
   VC_CEC_BUTTON_PRESSED  = (1 << 2), /**<<User Control Pressed> */
   VC_CEC_BUTTON_RELEASE  = (1 << 3), /**<<User Control Release> */
   VC_CEC_REMOTE_PRESSED  = (1 << 4), /**<<Vendor Remote Button Down> */
   VC_CEC_REMOTE_RELEASE  = (1 << 5), /**<<Vendor Remote Button Up> */
   VC_CEC_LOGICAL_ADDR    = (1 << 6), /**<New logical address allocated or released */
   VC_CEC_TOPOLOGY        = (1 << 7)  /**<Topology is available */
} VC_CEC_NOTIFY_T;


/**
 * Callback reason and arguments (for sending back to host)
 * Reason                  param1          param2             remark
 * VC_CEC_TX               First 4 bytes   Length |           A message has been transmitted
 *                         of message      success/fail
 * VC_CEC_RX               First 4 bytes   Next 3 bytes |     A message has arrived
 *                         of message      length
 * VC_CEC_BUTTON_PRESSED   User ctrl code     -               User Control pressed
 * VC_CEC_BUTTON_RELEASE   User ctrl code     -               User Control release
 * VC_CEC_REMOTE_PRESSED   Vendor RC code  Vendor ID          Vendor specific button pressed
 * VC_CEC_REMOTE_RELEASE   Vendor RC code  Vendor ID          Vendor specific button release
 * VC_CEC_LOGICAL_ADDR     Logical adress  Physical address   Logical address allocated or failure
 * VC_CEC_TOPOLOGY               -            -               New topology
 */

/**
 * General callback function for notifications from CEC middleware
 *
 * @param client_p is the callback context passed in by user
 *
 * @param reason is the notification nature
 *
 * @param param1 is the first parameter of notification (see above)
 *
 * @param param2 is the second parameter of notification (see above)
 *
 * @return void
 */
typedef void (*CEC_CALLBACK_T)(void *client_p, VC_CEC_NOTIFY_T reason, uint32_t param1, uint32_t param2);

#endif
