/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: IVI_Tbox_v4.5.proto */

#ifndef PROTOBUF_C_IVI_5fTbox_5fv4_2e5_2eproto__INCLUDED
#define PROTOBUF_C_IVI_5fTbox_5fv4_2e5_2eproto__INCLUDED

#include "protobuf.h"


PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1003000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1003001 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif


typedef struct _Tbox__Net__TboxNetworkCtrl Tbox__Net__TboxNetworkCtrl;
typedef struct _Tbox__Net__CallAction Tbox__Net__CallAction;
typedef struct _Tbox__Net__CallActionResult Tbox__Net__CallActionResult;
typedef struct _Tbox__Net__CallStatus Tbox__Net__CallStatus;
typedef struct _Tbox__Net__TboxInfo Tbox__Net__TboxInfo;
typedef struct _Tbox__Net__TboxGPSCmd Tbox__Net__TboxGPSCmd;
typedef struct _Tbox__Net__TboxGPSInfo Tbox__Net__TboxGPSInfo;
typedef struct _Tbox__Net__TboxActiveState Tbox__Net__TboxActiveState;
typedef struct _Tbox__Net__TboxRemoteDiagnose Tbox__Net__TboxRemoteDiagnose;
typedef struct _Tbox__Net__IhuLogfile Tbox__Net__IhuLogfile;
typedef struct _Tbox__Net__IhuChargeAppoointmentSts Tbox__Net__IhuChargeAppoointmentSts;
typedef struct _Tbox__Net__TboxChargeAppoointmentSet Tbox__Net__TboxChargeAppoointmentSet;
typedef struct _Tbox__Net__TboxChargeCtrl Tbox__Net__TboxChargeCtrl;
typedef struct _Tbox__Net__TboxChargeRecord Tbox__Net__TboxChargeRecord;
typedef struct _Tbox__Net__MsgResult Tbox__Net__MsgResult;
typedef struct _Tbox__Net__TopMessage Tbox__Net__TopMessage;


/* --- enums --- */

typedef enum _Tbox__Net__Messagetype {
  /*
   *no use,just for remove 0 in the enum
   */
  TBOX__NET__MESSAGETYPE__REQUEST_RESPONSE_NONE = 0,
  /*
   *heartbeat signal
   */
  TBOX__NET__MESSAGETYPE__REQUEST_HEARTBEAT_SIGNAL = 1,
  /*
   *heartbeat call back
   */
  TBOX__NET__MESSAGETYPE__RESPONSE_HEARTBEAT_RESULT = 2,
  /*
   *ivi request tbox network signal strength; no topmessage's field
   */
  TBOX__NET__MESSAGETYPE__REQUEST_NETWORK_SIGNAL_STRENGTH = 3,
  /*
   *tbox response network signal strength; topmessage's field: signal_type signal_power
   */
  TBOX__NET__MESSAGETYPE__RESPONSE_NETWORK_SIGNAL_STRENGTH = 4,
  /*
   *ivi request tbox a call action; topmessage's field: call_action
   */
  TBOX__NET__MESSAGETYPE__REQUEST_CALL_ACTION = 5,
  /*
   *tbox response ivi a call action result; topmessage's field: call_result
   */
  TBOX__NET__MESSAGETYPE__RESPONSE_CALL_ACTION_RESULT = 6,
  /*
   *tbox report a call action status; topmessage's field: call_status
   */
  TBOX__NET__MESSAGETYPE__RESPONSE_CALL_STATUS = 7,
  /*
   *ivi request tbox info; no topmessage's field
   */
  TBOX__NET__MESSAGETYPE__REQUEST_TBOX_INFO = 8,
  /*
   *tbox response tbox info; topmessage's field: tbox_info
   */
  TBOX__NET__MESSAGETYPE__RESPONSE_TBOX_INFO = 9,
  /*
   *ivi request GPS set
   */
  TBOX__NET__MESSAGETYPE__REQUEST_TBOX_GPS_SET = 10,
  /*
   *ivi response GPS set
   */
  TBOX__NET__MESSAGETYPE__RESPONSE_TBOX_GPS_SET_RESULT = 11,
  /*
   *tbox response mac address		
   */
  TBOX__NET__MESSAGETYPE__RESPONSE_TBOX_GPSINFO_RESULT = 12,
  /*
   *tbox response active state
   */
  TBOX__NET__MESSAGETYPE__RESPONSE_TBOX_ACTIVESTATE_RESULT = 13,
  /*
   *tbox request IVI to capture videos or pictures
   */
  TBOX__NET__MESSAGETYPE__REQUEST_TBOX_REMOTEDIAGNOSE = 14,
  /*
   *ivi response tbox : contrl result
   */
  TBOX__NET__MESSAGETYPE__RESPONSE_TBOX_REMOTEDIAGNOSE_RESULT = 15,
  /*
   *tbox request ihu to report log files
   */
  TBOX__NET__MESSAGETYPE__REQUEST_IHU_LOGFILE = 16,
  /*
   *ihu response tbox result
   */
  TBOX__NET__MESSAGETYPE__RESPONSE_IHU_LOGFILE_RESULT = 17,
  /*
   *tbox request ihu to update charge appointment state
   */
  TBOX__NET__MESSAGETYPE__REQUEST_IHU_CHARGEAPPOINTMENTSTS = 18,
  /*
   *ihu response tbox result
   */
  TBOX__NET__MESSAGETYPE__RESPONSE_IHU_CHARGEAPPOINTMENTSTS_RESULT = 19,
  /*
   *ihu request tbox to set charge appointment 
   */
  TBOX__NET__MESSAGETYPE__REQUEST_TBOX_CHARGEAPPOINTMENTSET = 20,
  /*
   *tbox response ihu result
   */
  TBOX__NET__MESSAGETYPE__RESPONSE_TBOX_CHARGEAPPOINTMENTSET_RESULT = 21,
  /*
   *ihu request tbox to charge
   */
  TBOX__NET__MESSAGETYPE__REQUEST_TBOX_CHARGECTRL = 22,
  /*
   *tbox response ihu result
   */
  TBOX__NET__MESSAGETYPE__RESPONSE_TBOX_CHARGECTRL_RESULT = 23,
  /*
   *ihu response tbox call action status (FOR: RESPONSE_CALL_STATUS)
   */
  TBOX__NET__MESSAGETYPE__IHU_CALL_STATUS_RESULT = 24,
  /*
   *ihu response tbox active status (FOR: RESPONSE_TBOX_ACTIVESTATE_RESULT)
   */
  TBOX__NET__MESSAGETYPE__IHU_ACTIVESTATE_RESULT = 25,
  /*
   *ihu request tbox to get charge record
   */
  TBOX__NET__MESSAGETYPE__REQUEST_QUERY_CHARGE_RECORD = 26,
  /*
   *tbox response ihu charge record
   */
  TBOX__NET__MESSAGETYPE__RESPONSE_CHARGE_RECORD_RESULT = 27,
  /*
   *tbox told ihu have a OTA task
   */
  TBOX__NET__MESSAGETYPE__REQUEST_OTAUPDATE_TASK = 28,
  /*
   *ihu response tbox result
   */
  TBOX__NET__MESSAGETYPE__RESPONSE_OTAUPDATE_TASK_RESULT = 29
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(TBOX__NET__MESSAGETYPE)
} Tbox__Net__Messagetype;
typedef enum _Tbox__Net__NETWORKSENDOnOff {
  /*
   *start network signal send to IVI
   */
  TBOX__NET__NETWORK__SEND__ON_OFF__NETWORK_ON = 0,
  /*
   *stop
   */
  TBOX__NET__NETWORK__SEND__ON_OFF__NETWORK_OFF = 1,
  /*
   *Only send the network signal for one time
   */
  TBOX__NET__NETWORK__SEND__ON_OFF__NETWORK_ONCE = 2
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(TBOX__NET__NETWORK__SEND__ON_OFF)
} Tbox__Net__NETWORKSENDOnOff;
typedef enum _Tbox__Net__SignalType {
  /*
   * no signal
   */
  TBOX__NET__SIGNAL_TYPE__NONE_SIGNAL = 0,
  /*
   *2G
   */
  TBOX__NET__SIGNAL_TYPE__GSM = 1,
  /*
   *3G
   */
  TBOX__NET__SIGNAL_TYPE__UMTS = 2,
  /*
   *4G
   */
  TBOX__NET__SIGNAL_TYPE__LTE = 3
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(TBOX__NET__SIGNAL_TYPE)
} Tbox__Net__SignalType;
typedef enum _Tbox__Net__CallType {
  TBOX__NET__CALL_TYPE__ECALL = 0,
  TBOX__NET__CALL_TYPE__BCALL = 1,
  TBOX__NET__CALL_TYPE__ICALL = 2
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(TBOX__NET__CALL_TYPE)
} Tbox__Net__CallType;
typedef enum _Tbox__Net__CallActionEnum {
  /*
   * start a CALL
   */
  TBOX__NET__CALL_ACTION_ENUM__START_CALL = 0,
  /*
   * end current CALL
   */
  TBOX__NET__CALL_ACTION_ENUM__END_CALL = 1
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(TBOX__NET__CALL_ACTION_ENUM)
} Tbox__Net__CallActionEnum;
typedef enum _Tbox__Net__CallActionResultEnum {
  /*
   *request action success
   */
  TBOX__NET__CALL_ACTION_RESULT_ENUM__CALL_ACTION_SUCCESS = 0,
  /*
   *nonsupport the call
   */
  TBOX__NET__CALL_ACTION_RESULT_ENUM__CALL_ACTION_NONSUPPORT = 1,
  /*
   *start call failed because now a call is processing
   */
  TBOX__NET__CALL_ACTION_RESULT_ENUM__START_FAILED_CALL_PROCESSING = 2,
  /*
   *start call failed because other reasons
   */
  TBOX__NET__CALL_ACTION_RESULT_ENUM__START_FAILED_OTHER_ERROR = 3,
  /*
   *end current call failed because now no call
   */
  TBOX__NET__CALL_ACTION_RESULT_ENUM__END_FAILED_NO_CURRENT_CALL = 4,
  /*
   *end current call failed because other reasons
   */
  TBOX__NET__CALL_ACTION_RESULT_ENUM__END_FAILED_OTHER_ERROR = 5
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(TBOX__NET__CALL_ACTION_RESULT_ENUM)
} Tbox__Net__CallActionResultEnum;
typedef enum _Tbox__Net__CallStatusEnum {
  /*
   *来电
   */
  TBOX__NET__CALL_STATUS_ENUM__CALL_IN = 0,
  /*
   *去电  
   */
  TBOX__NET__CALL_STATUS_ENUM__CALL_OUT = 1,
  /*
   *振铃
   */
  TBOX__NET__CALL_STATUS_ENUM__CALL_RING = 2,
  /*
   *接通
   */
  TBOX__NET__CALL_STATUS_ENUM__CALL_CONNECTED = 3,
  /*
   *挂断
   */
  TBOX__NET__CALL_STATUS_ENUM__CALL_DISCONNECTED = 4
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(TBOX__NET__CALL_STATUS_ENUM)
} Tbox__Net__CallStatusEnum;
typedef enum _Tbox__Net__GPSSENDOnOff {
  /*
   *start GPS info send to IVI
   */
  TBOX__NET__GPS__SEND__ON_OFF__GPS_ON = 0,
  /*
   *stop
   */
  TBOX__NET__GPS__SEND__ON_OFF__GPS_OFF = 1,
  /*
   *Only send the GPS info for one time
   */
  TBOX__NET__GPS__SEND__ON_OFF__GPS_ONCE = 2
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(TBOX__NET__GPS__SEND__ON_OFF)
} Tbox__Net__GPSSENDOnOff;
typedef enum _Tbox__Net__DataTypeEnum {
  TBOX__NET__DATA_TYPE_ENUM__PHOTO_TYPE = 0,
  TBOX__NET__DATA_TYPE_ENUM__VIDEO_TYPE = 1
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(TBOX__NET__DATA_TYPE_ENUM)
} Tbox__Net__DataTypeEnum;
typedef enum _Tbox__Net__CameraNameEnum {
  TBOX__NET__CAMERA_NAME_ENUM__DVR_TYPE = 0,
  TBOX__NET__CAMERA_NAME_ENUM__DMS_TYPE = 1
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(TBOX__NET__CAMERA_NAME_ENUM)
} Tbox__Net__CameraNameEnum;

/* --- messages --- */

struct  _Tbox__Net__TboxNetworkCtrl
{
  ProtobufCMessage base;
  Tbox__Net__NETWORKSENDOnOff onoff;
  uint32_t time_cycle;
};
#define TBOX__NET__TBOX_NETWORK_CTRL__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&tbox__net__tbox_network_ctrl__descriptor) \
    , TBOX__NET__NETWORK__SEND__ON_OFF__NETWORK_ON, 0 }


struct  _Tbox__Net__CallAction
{
  ProtobufCMessage base;
  Tbox__Net__CallType type;
  Tbox__Net__CallActionEnum action;
};
#define TBOX__NET__CALL_ACTION__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&tbox__net__call_action__descriptor) \
    , TBOX__NET__CALL_TYPE__ECALL, TBOX__NET__CALL_ACTION_ENUM__START_CALL }


struct  _Tbox__Net__CallActionResult
{
  ProtobufCMessage base;
  Tbox__Net__CallType type;
  Tbox__Net__CallActionEnum action;
  Tbox__Net__CallActionResultEnum result;
};
#define TBOX__NET__CALL_ACTION_RESULT__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&tbox__net__call_action_result__descriptor) \
    , TBOX__NET__CALL_TYPE__ECALL, TBOX__NET__CALL_ACTION_ENUM__START_CALL, TBOX__NET__CALL_ACTION_RESULT_ENUM__CALL_ACTION_SUCCESS }


struct  _Tbox__Net__CallStatus
{
  ProtobufCMessage base;
  Tbox__Net__CallType type;
  Tbox__Net__CallStatusEnum call_status;
  ProtobufCBinaryData reserve;
};
#define TBOX__NET__CALL_STATUS__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&tbox__net__call_status__descriptor) \
    , TBOX__NET__CALL_TYPE__ECALL, TBOX__NET__CALL_STATUS_ENUM__CALL_IN, {0,NULL} }


struct  _Tbox__Net__TboxInfo
{
  ProtobufCMessage base;
  char *software_version;
  char *hardware_version;
  char *iccid;
  char *pdid;
  char *imei;
  char *vin;
};
#define TBOX__NET__TBOX_INFO__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&tbox__net__tbox_info__descriptor) \
    , (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string }


struct  _Tbox__Net__TboxGPSCmd
{
  ProtobufCMessage base;
  Tbox__Net__GPSSENDOnOff onoff;
  uint32_t time_cycle;
};
#define TBOX__NET__TBOX_GPSCMD__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&tbox__net__tbox_gpscmd__descriptor) \
    , TBOX__NET__GPS__SEND__ON_OFF__GPS_ON, 0 }


struct  _Tbox__Net__TboxGPSInfo
{
  ProtobufCMessage base;
  char *nmea;
};
#define TBOX__NET__TBOX_GPSINFO__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&tbox__net__tbox_gpsinfo__descriptor) \
    , (char *)protobuf_c_empty_string }


struct  _Tbox__Net__TboxActiveState
{
  ProtobufCMessage base;
  /*
   *true:activated   false:not active
   */
  protobuf_c_boolean active_state;
};
#define TBOX__NET__TBOX_ACTIVE_STATE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&tbox__net__tbox_active_state__descriptor) \
    , 0 }


struct  _Tbox__Net__TboxRemoteDiagnose
{
  ProtobufCMessage base;
  char *vin;
  uint32_t eventid;
  uint32_t timestamp;
  Tbox__Net__DataTypeEnum datatype;
  Tbox__Net__CameraNameEnum cameraname;
  uint32_t aid;
  uint32_t mid;
  uint32_t effectivetime;
  uint32_t sizelimit;
};
#define TBOX__NET__TBOX_REMOTE_DIAGNOSE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&tbox__net__tbox_remote_diagnose__descriptor) \
    , (char *)protobuf_c_empty_string, 0, 0, TBOX__NET__DATA_TYPE_ENUM__PHOTO_TYPE, TBOX__NET__CAMERA_NAME_ENUM__DVR_TYPE, 0, 0, 0, 0 }


struct  _Tbox__Net__IhuLogfile
{
  ProtobufCMessage base;
  char *vin;
  uint32_t eventid;
  uint32_t timestamp;
  uint32_t aid;
  uint32_t mid;
  uint32_t starttime;
  uint32_t durationtime;
  /*
   *1:TBOX, 2:IHU
   */
  uint32_t channel;
  /*
   *1:ERROR, 2:WARN, 3:INFO, 4:DEBUG
   */
  uint32_t level;
};
#define TBOX__NET__IHU_LOGFILE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&tbox__net__ihu_logfile__descriptor) \
    , (char *)protobuf_c_empty_string, 0, 0, 0, 0, 0, 0, 0, 0 }


struct  _Tbox__Net__IhuChargeAppoointmentSts
{
  ProtobufCMessage base;
  uint32_t timestamp;
  uint32_t hour;
  uint32_t min;
  uint32_t id;
  uint32_t targetpower;
  /*
   *true:effective, false:Invalid
   */
  protobuf_c_boolean effectivestate;
};
#define TBOX__NET__IHU_CHARGE_APPOOINTMENT_STS__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&tbox__net__ihu_charge_appoointment_sts__descriptor) \
    , 0, 0, 0, 0, 0, 0 }


struct  _Tbox__Net__TboxChargeAppoointmentSet
{
  ProtobufCMessage base;
  uint32_t timestamp;
  uint32_t hour;
  uint32_t min;
  uint32_t id;
  uint32_t targetpower;
  /*
   *true:effective, false:Invalid
   */
  protobuf_c_boolean effectivestate;
};
#define TBOX__NET__TBOX_CHARGE_APPOOINTMENT_SET__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&tbox__net__tbox_charge_appoointment_set__descriptor) \
    , 0, 0, 0, 0, 0, 0 }


struct  _Tbox__Net__TboxChargeCtrl
{
  ProtobufCMessage base;
  uint32_t timestamp;
  /*
   *0: stop, 1:start
   */
  protobuf_c_boolean commend;
  uint32_t targetpower;
};
#define TBOX__NET__TBOX_CHARGE_CTRL__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&tbox__net__tbox_charge_ctrl__descriptor) \
    , 0, 0, 0 }


struct  _Tbox__Net__TboxChargeRecord
{
  ProtobufCMessage base;
  uint32_t timestamp;
  uint32_t hour;
  uint32_t min;
  uint32_t id;
  uint32_t targetpower;
  /*
   *true:effective, false:Invalid
   */
  protobuf_c_boolean effectivestate;
};
#define TBOX__NET__TBOX_CHARGE_RECORD__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&tbox__net__tbox_charge_record__descriptor) \
    , 0, 0, 0, 0, 0, 0 }


struct  _Tbox__Net__MsgResult
{
  ProtobufCMessage base;
  /*
   *true:success    flase:failed
   */
  protobuf_c_boolean result;
  /*
   *none-error, dealing with failures and so on
   */
  ProtobufCBinaryData error_code;
};
#define TBOX__NET__MSG_RESULT__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&tbox__net__msg_result__descriptor) \
    , 0, {0,NULL} }


struct  _Tbox__Net__TopMessage
{
  ProtobufCMessage base;
  /*
   *message type
   */
  Tbox__Net__Messagetype message_type;
  /*
   *current signal type
   */
  Tbox__Net__SignalType signal_type;
  /*
   *current signal strength, 0-5, 0 means no signal, 5 means strong strength
   */
  int32_t signal_power;
  Tbox__Net__TboxNetworkCtrl *tbox_network_ctrl;
  Tbox__Net__CallAction *call_action;
  Tbox__Net__CallStatus *call_status;
  Tbox__Net__CallActionResult *call_result;
  Tbox__Net__TboxInfo *tbox_info;
  Tbox__Net__TboxGPSCmd *tbox_gps_ctrl;
  Tbox__Net__TboxGPSInfo *tbox_gpsinfo;
  Tbox__Net__TboxActiveState *tbox_activestate;
  Tbox__Net__TboxRemoteDiagnose *tbox_remotedaignose;
  Tbox__Net__MsgResult *msg_result;
  Tbox__Net__IhuLogfile *ihu_logfile;
  Tbox__Net__IhuChargeAppoointmentSts *ihu_charge_appoointmentsts;
  Tbox__Net__TboxChargeAppoointmentSet *tbox_charge_appoointmentset;
  Tbox__Net__TboxChargeCtrl *tbox_chargectrl;
  Tbox__Net__TboxChargeRecord *tbox_charge_record;
};
#define TBOX__NET__TOP_MESSAGE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&tbox__net__top_message__descriptor) \
    , TBOX__NET__MESSAGETYPE__REQUEST_RESPONSE_NONE, TBOX__NET__SIGNAL_TYPE__NONE_SIGNAL, 0, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL }


/* Tbox__Net__TboxNetworkCtrl methods */
void   tbox__net__tbox_network_ctrl__init
                     (Tbox__Net__TboxNetworkCtrl         *message);
size_t tbox__net__tbox_network_ctrl__get_packed_size
                     (const Tbox__Net__TboxNetworkCtrl   *message);
size_t tbox__net__tbox_network_ctrl__pack
                     (const Tbox__Net__TboxNetworkCtrl   *message,
                      uint8_t             *out);
size_t tbox__net__tbox_network_ctrl__pack_to_buffer
                     (const Tbox__Net__TboxNetworkCtrl   *message,
                      ProtobufCBuffer     *buffer);
Tbox__Net__TboxNetworkCtrl *
       tbox__net__tbox_network_ctrl__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   tbox__net__tbox_network_ctrl__free_unpacked
                     (Tbox__Net__TboxNetworkCtrl *message,
                      ProtobufCAllocator *allocator);
/* Tbox__Net__CallAction methods */
void   tbox__net__call_action__init
                     (Tbox__Net__CallAction         *message);
size_t tbox__net__call_action__get_packed_size
                     (const Tbox__Net__CallAction   *message);
size_t tbox__net__call_action__pack
                     (const Tbox__Net__CallAction   *message,
                      uint8_t             *out);
size_t tbox__net__call_action__pack_to_buffer
                     (const Tbox__Net__CallAction   *message,
                      ProtobufCBuffer     *buffer);
Tbox__Net__CallAction *
       tbox__net__call_action__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   tbox__net__call_action__free_unpacked
                     (Tbox__Net__CallAction *message,
                      ProtobufCAllocator *allocator);
/* Tbox__Net__CallActionResult methods */
void   tbox__net__call_action_result__init
                     (Tbox__Net__CallActionResult         *message);
size_t tbox__net__call_action_result__get_packed_size
                     (const Tbox__Net__CallActionResult   *message);
size_t tbox__net__call_action_result__pack
                     (const Tbox__Net__CallActionResult   *message,
                      uint8_t             *out);
size_t tbox__net__call_action_result__pack_to_buffer
                     (const Tbox__Net__CallActionResult   *message,
                      ProtobufCBuffer     *buffer);
Tbox__Net__CallActionResult *
       tbox__net__call_action_result__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   tbox__net__call_action_result__free_unpacked
                     (Tbox__Net__CallActionResult *message,
                      ProtobufCAllocator *allocator);
/* Tbox__Net__CallStatus methods */
void   tbox__net__call_status__init
                     (Tbox__Net__CallStatus         *message);
size_t tbox__net__call_status__get_packed_size
                     (const Tbox__Net__CallStatus   *message);
size_t tbox__net__call_status__pack
                     (const Tbox__Net__CallStatus   *message,
                      uint8_t             *out);
size_t tbox__net__call_status__pack_to_buffer
                     (const Tbox__Net__CallStatus   *message,
                      ProtobufCBuffer     *buffer);
Tbox__Net__CallStatus *
       tbox__net__call_status__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   tbox__net__call_status__free_unpacked
                     (Tbox__Net__CallStatus *message,
                      ProtobufCAllocator *allocator);
/* Tbox__Net__TboxInfo methods */
void   tbox__net__tbox_info__init
                     (Tbox__Net__TboxInfo         *message);
size_t tbox__net__tbox_info__get_packed_size
                     (const Tbox__Net__TboxInfo   *message);
size_t tbox__net__tbox_info__pack
                     (const Tbox__Net__TboxInfo   *message,
                      uint8_t             *out);
size_t tbox__net__tbox_info__pack_to_buffer
                     (const Tbox__Net__TboxInfo   *message,
                      ProtobufCBuffer     *buffer);
Tbox__Net__TboxInfo *
       tbox__net__tbox_info__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   tbox__net__tbox_info__free_unpacked
                     (Tbox__Net__TboxInfo *message,
                      ProtobufCAllocator *allocator);
/* Tbox__Net__TboxGPSCmd methods */
void   tbox__net__tbox_gpscmd__init
                     (Tbox__Net__TboxGPSCmd         *message);
size_t tbox__net__tbox_gpscmd__get_packed_size
                     (const Tbox__Net__TboxGPSCmd   *message);
size_t tbox__net__tbox_gpscmd__pack
                     (const Tbox__Net__TboxGPSCmd   *message,
                      uint8_t             *out);
size_t tbox__net__tbox_gpscmd__pack_to_buffer
                     (const Tbox__Net__TboxGPSCmd   *message,
                      ProtobufCBuffer     *buffer);
Tbox__Net__TboxGPSCmd *
       tbox__net__tbox_gpscmd__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   tbox__net__tbox_gpscmd__free_unpacked
                     (Tbox__Net__TboxGPSCmd *message,
                      ProtobufCAllocator *allocator);
/* Tbox__Net__TboxGPSInfo methods */
void   tbox__net__tbox_gpsinfo__init
                     (Tbox__Net__TboxGPSInfo         *message);
size_t tbox__net__tbox_gpsinfo__get_packed_size
                     (const Tbox__Net__TboxGPSInfo   *message);
size_t tbox__net__tbox_gpsinfo__pack
                     (const Tbox__Net__TboxGPSInfo   *message,
                      uint8_t             *out);
size_t tbox__net__tbox_gpsinfo__pack_to_buffer
                     (const Tbox__Net__TboxGPSInfo   *message,
                      ProtobufCBuffer     *buffer);
Tbox__Net__TboxGPSInfo *
       tbox__net__tbox_gpsinfo__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   tbox__net__tbox_gpsinfo__free_unpacked
                     (Tbox__Net__TboxGPSInfo *message,
                      ProtobufCAllocator *allocator);
/* Tbox__Net__TboxActiveState methods */
void   tbox__net__tbox_active_state__init
                     (Tbox__Net__TboxActiveState         *message);
size_t tbox__net__tbox_active_state__get_packed_size
                     (const Tbox__Net__TboxActiveState   *message);
size_t tbox__net__tbox_active_state__pack
                     (const Tbox__Net__TboxActiveState   *message,
                      uint8_t             *out);
size_t tbox__net__tbox_active_state__pack_to_buffer
                     (const Tbox__Net__TboxActiveState   *message,
                      ProtobufCBuffer     *buffer);
Tbox__Net__TboxActiveState *
       tbox__net__tbox_active_state__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   tbox__net__tbox_active_state__free_unpacked
                     (Tbox__Net__TboxActiveState *message,
                      ProtobufCAllocator *allocator);
/* Tbox__Net__TboxRemoteDiagnose methods */
void   tbox__net__tbox_remote_diagnose__init
                     (Tbox__Net__TboxRemoteDiagnose         *message);
size_t tbox__net__tbox_remote_diagnose__get_packed_size
                     (const Tbox__Net__TboxRemoteDiagnose   *message);
size_t tbox__net__tbox_remote_diagnose__pack
                     (const Tbox__Net__TboxRemoteDiagnose   *message,
                      uint8_t             *out);
size_t tbox__net__tbox_remote_diagnose__pack_to_buffer
                     (const Tbox__Net__TboxRemoteDiagnose   *message,
                      ProtobufCBuffer     *buffer);
Tbox__Net__TboxRemoteDiagnose *
       tbox__net__tbox_remote_diagnose__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   tbox__net__tbox_remote_diagnose__free_unpacked
                     (Tbox__Net__TboxRemoteDiagnose *message,
                      ProtobufCAllocator *allocator);
/* Tbox__Net__IhuLogfile methods */
void   tbox__net__ihu_logfile__init
                     (Tbox__Net__IhuLogfile         *message);
size_t tbox__net__ihu_logfile__get_packed_size
                     (const Tbox__Net__IhuLogfile   *message);
size_t tbox__net__ihu_logfile__pack
                     (const Tbox__Net__IhuLogfile   *message,
                      uint8_t             *out);
size_t tbox__net__ihu_logfile__pack_to_buffer
                     (const Tbox__Net__IhuLogfile   *message,
                      ProtobufCBuffer     *buffer);
Tbox__Net__IhuLogfile *
       tbox__net__ihu_logfile__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   tbox__net__ihu_logfile__free_unpacked
                     (Tbox__Net__IhuLogfile *message,
                      ProtobufCAllocator *allocator);
/* Tbox__Net__IhuChargeAppoointmentSts methods */
void   tbox__net__ihu_charge_appoointment_sts__init
                     (Tbox__Net__IhuChargeAppoointmentSts         *message);
size_t tbox__net__ihu_charge_appoointment_sts__get_packed_size
                     (const Tbox__Net__IhuChargeAppoointmentSts   *message);
size_t tbox__net__ihu_charge_appoointment_sts__pack
                     (const Tbox__Net__IhuChargeAppoointmentSts   *message,
                      uint8_t             *out);
size_t tbox__net__ihu_charge_appoointment_sts__pack_to_buffer
                     (const Tbox__Net__IhuChargeAppoointmentSts   *message,
                      ProtobufCBuffer     *buffer);
Tbox__Net__IhuChargeAppoointmentSts *
       tbox__net__ihu_charge_appoointment_sts__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   tbox__net__ihu_charge_appoointment_sts__free_unpacked
                     (Tbox__Net__IhuChargeAppoointmentSts *message,
                      ProtobufCAllocator *allocator);
/* Tbox__Net__TboxChargeAppoointmentSet methods */
void   tbox__net__tbox_charge_appoointment_set__init
                     (Tbox__Net__TboxChargeAppoointmentSet         *message);
size_t tbox__net__tbox_charge_appoointment_set__get_packed_size
                     (const Tbox__Net__TboxChargeAppoointmentSet   *message);
size_t tbox__net__tbox_charge_appoointment_set__pack
                     (const Tbox__Net__TboxChargeAppoointmentSet   *message,
                      uint8_t             *out);
size_t tbox__net__tbox_charge_appoointment_set__pack_to_buffer
                     (const Tbox__Net__TboxChargeAppoointmentSet   *message,
                      ProtobufCBuffer     *buffer);
Tbox__Net__TboxChargeAppoointmentSet *
       tbox__net__tbox_charge_appoointment_set__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   tbox__net__tbox_charge_appoointment_set__free_unpacked
                     (Tbox__Net__TboxChargeAppoointmentSet *message,
                      ProtobufCAllocator *allocator);
/* Tbox__Net__TboxChargeCtrl methods */
void   tbox__net__tbox_charge_ctrl__init
                     (Tbox__Net__TboxChargeCtrl         *message);
size_t tbox__net__tbox_charge_ctrl__get_packed_size
                     (const Tbox__Net__TboxChargeCtrl   *message);
size_t tbox__net__tbox_charge_ctrl__pack
                     (const Tbox__Net__TboxChargeCtrl   *message,
                      uint8_t             *out);
size_t tbox__net__tbox_charge_ctrl__pack_to_buffer
                     (const Tbox__Net__TboxChargeCtrl   *message,
                      ProtobufCBuffer     *buffer);
Tbox__Net__TboxChargeCtrl *
       tbox__net__tbox_charge_ctrl__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   tbox__net__tbox_charge_ctrl__free_unpacked
                     (Tbox__Net__TboxChargeCtrl *message,
                      ProtobufCAllocator *allocator);
/* Tbox__Net__TboxChargeRecord methods */
void   tbox__net__tbox_charge_record__init
                     (Tbox__Net__TboxChargeRecord         *message);
size_t tbox__net__tbox_charge_record__get_packed_size
                     (const Tbox__Net__TboxChargeRecord   *message);
size_t tbox__net__tbox_charge_record__pack
                     (const Tbox__Net__TboxChargeRecord   *message,
                      uint8_t             *out);
size_t tbox__net__tbox_charge_record__pack_to_buffer
                     (const Tbox__Net__TboxChargeRecord   *message,
                      ProtobufCBuffer     *buffer);
Tbox__Net__TboxChargeRecord *
       tbox__net__tbox_charge_record__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   tbox__net__tbox_charge_record__free_unpacked
                     (Tbox__Net__TboxChargeRecord *message,
                      ProtobufCAllocator *allocator);
/* Tbox__Net__MsgResult methods */
void   tbox__net__msg_result__init
                     (Tbox__Net__MsgResult         *message);
size_t tbox__net__msg_result__get_packed_size
                     (const Tbox__Net__MsgResult   *message);
size_t tbox__net__msg_result__pack
                     (const Tbox__Net__MsgResult   *message,
                      uint8_t             *out);
size_t tbox__net__msg_result__pack_to_buffer
                     (const Tbox__Net__MsgResult   *message,
                      ProtobufCBuffer     *buffer);
Tbox__Net__MsgResult *
       tbox__net__msg_result__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   tbox__net__msg_result__free_unpacked
                     (Tbox__Net__MsgResult *message,
                      ProtobufCAllocator *allocator);
/* Tbox__Net__TopMessage methods */
void   tbox__net__top_message__init
                     (Tbox__Net__TopMessage         *message);
size_t tbox__net__top_message__get_packed_size
                     (const Tbox__Net__TopMessage   *message);
size_t tbox__net__top_message__pack
                     (const Tbox__Net__TopMessage   *message,
                      uint8_t             *out);
size_t tbox__net__top_message__pack_to_buffer
                     (const Tbox__Net__TopMessage   *message,
                      ProtobufCBuffer     *buffer);
Tbox__Net__TopMessage *
       tbox__net__top_message__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   tbox__net__top_message__free_unpacked
                     (Tbox__Net__TopMessage *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*Tbox__Net__TboxNetworkCtrl_Closure)
                 (const Tbox__Net__TboxNetworkCtrl *message,
                  void *closure_data);
typedef void (*Tbox__Net__CallAction_Closure)
                 (const Tbox__Net__CallAction *message,
                  void *closure_data);
typedef void (*Tbox__Net__CallActionResult_Closure)
                 (const Tbox__Net__CallActionResult *message,
                  void *closure_data);
typedef void (*Tbox__Net__CallStatus_Closure)
                 (const Tbox__Net__CallStatus *message,
                  void *closure_data);
typedef void (*Tbox__Net__TboxInfo_Closure)
                 (const Tbox__Net__TboxInfo *message,
                  void *closure_data);
typedef void (*Tbox__Net__TboxGPSCmd_Closure)
                 (const Tbox__Net__TboxGPSCmd *message,
                  void *closure_data);
typedef void (*Tbox__Net__TboxGPSInfo_Closure)
                 (const Tbox__Net__TboxGPSInfo *message,
                  void *closure_data);
typedef void (*Tbox__Net__TboxActiveState_Closure)
                 (const Tbox__Net__TboxActiveState *message,
                  void *closure_data);
typedef void (*Tbox__Net__TboxRemoteDiagnose_Closure)
                 (const Tbox__Net__TboxRemoteDiagnose *message,
                  void *closure_data);
typedef void (*Tbox__Net__IhuLogfile_Closure)
                 (const Tbox__Net__IhuLogfile *message,
                  void *closure_data);
typedef void (*Tbox__Net__IhuChargeAppoointmentSts_Closure)
                 (const Tbox__Net__IhuChargeAppoointmentSts *message,
                  void *closure_data);
typedef void (*Tbox__Net__TboxChargeAppoointmentSet_Closure)
                 (const Tbox__Net__TboxChargeAppoointmentSet *message,
                  void *closure_data);
typedef void (*Tbox__Net__TboxChargeCtrl_Closure)
                 (const Tbox__Net__TboxChargeCtrl *message,
                  void *closure_data);
typedef void (*Tbox__Net__TboxChargeRecord_Closure)
                 (const Tbox__Net__TboxChargeRecord *message,
                  void *closure_data);
typedef void (*Tbox__Net__MsgResult_Closure)
                 (const Tbox__Net__MsgResult *message,
                  void *closure_data);
typedef void (*Tbox__Net__TopMessage_Closure)
                 (const Tbox__Net__TopMessage *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCEnumDescriptor    tbox__net__messagetype__descriptor;
extern const ProtobufCEnumDescriptor    tbox__net__network__send__on_off__descriptor;
extern const ProtobufCEnumDescriptor    tbox__net__signal_type__descriptor;
extern const ProtobufCEnumDescriptor    tbox__net__call_type__descriptor;
extern const ProtobufCEnumDescriptor    tbox__net__call_action_enum__descriptor;
extern const ProtobufCEnumDescriptor    tbox__net__call_action_result_enum__descriptor;
extern const ProtobufCEnumDescriptor    tbox__net__call_status_enum__descriptor;
extern const ProtobufCEnumDescriptor    tbox__net__gps__send__on_off__descriptor;
extern const ProtobufCEnumDescriptor    tbox__net__data_type_enum__descriptor;
extern const ProtobufCEnumDescriptor    tbox__net__camera_name_enum__descriptor;
extern const ProtobufCMessageDescriptor tbox__net__tbox_network_ctrl__descriptor;
extern const ProtobufCMessageDescriptor tbox__net__call_action__descriptor;
extern const ProtobufCMessageDescriptor tbox__net__call_action_result__descriptor;
extern const ProtobufCMessageDescriptor tbox__net__call_status__descriptor;
extern const ProtobufCMessageDescriptor tbox__net__tbox_info__descriptor;
extern const ProtobufCMessageDescriptor tbox__net__tbox_gpscmd__descriptor;
extern const ProtobufCMessageDescriptor tbox__net__tbox_gpsinfo__descriptor;
extern const ProtobufCMessageDescriptor tbox__net__tbox_active_state__descriptor;
extern const ProtobufCMessageDescriptor tbox__net__tbox_remote_diagnose__descriptor;
extern const ProtobufCMessageDescriptor tbox__net__ihu_logfile__descriptor;
extern const ProtobufCMessageDescriptor tbox__net__ihu_charge_appoointment_sts__descriptor;
extern const ProtobufCMessageDescriptor tbox__net__tbox_charge_appoointment_set__descriptor;
extern const ProtobufCMessageDescriptor tbox__net__tbox_charge_ctrl__descriptor;
extern const ProtobufCMessageDescriptor tbox__net__tbox_charge_record__descriptor;
extern const ProtobufCMessageDescriptor tbox__net__msg_result__descriptor;
extern const ProtobufCMessageDescriptor tbox__net__top_message__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_IVI_5fTbox_5fv4_2e5_2eproto__INCLUDED */
