/* 
 * File:   KWPMsgHandler_Types.h
 * Author: Benjamin
 *
 * Created on 2019. március 20., 20:12
 */

#ifndef KWPMSGHANDLER_TYPES_H
#define	KWPMSGHANDLER_TYPES_H

#include "types.h"

typedef enum EnumSmKwp
{
    KWP_Init,
    KWP_WaitForInitResponse,
    KWP_InitDone,
}dtEnumSmKwp;

typedef struct sMsg
{
    uint8 FormatByte;
    uint8 DstAddr;
    uint8 SrcAddr;
    uint8 ServiceID;
    uint8 PID;
    uint8 CRC;
} dtMsg;


typedef struct sKWPMsgHandler
{
    dtEnumSmKwp SM;
    uint16      Timeout;
    uint8       ECUAddr;
    uint8       QuerriedService;
    uint8       QuerriedPID;
    uint8       ReceivedMsgs;
    
    uint8       WaitForAnswer;
    uint8       Msg[64];
} dtKWPMsgHandler;

typedef struct sService_0
{
    uint8   PID_00   :1;
    uint8   PID_01   :1;
    uint8   PID_02   :1;
    uint8   PID_03   :1;
    uint8   PID_04   :1;
    uint8   PID_05   :1;
    uint8   PID_06   :1;
    uint8   PID_07   :1;
    uint8   PID_08   :1;
    uint8   PID_09   :1;
    uint8   PID_0A   :1;
    uint8   PID_0B   :1;
    uint8   PID_0C   :1;
    uint8   PID_0D   :1;
    uint8   PID_0E   :1;
    uint8   PID_0F   :1;
    uint8   PID_10   :1;
    uint8   PID_11   :1;
    uint8   PID_12   :1;
    uint8   PID_13   :1;
    uint8   PID_14   :1;
    uint8   PID_15   :1;
    uint8   PID_16   :1;
    uint8   PID_17   :1;
    uint8   PID_18   :1;
    uint8   PID_19   :1;
    uint8   PID_1A   :1;
    uint8   PID_1B   :1;
    uint8   PID_1C   :1;
    uint8   PID_1D   :1;
    uint8   PID_1E   :1;
    uint8   PID_1F   :1;
    uint8   PID_20   :1;
    uint8   PID_21   :1;
    uint8   PID_22   :1;
    uint8   PID_23   :1;
    uint8   PID_24   :1;
    uint8   PID_25   :1;
    uint8   PID_26   :1;
    uint8   PID_27   :1;
    uint8   PID_28   :1;
    uint8   PID_29   :1;
    uint8   PID_2A   :1;
    uint8   PID_2B   :1;
    uint8   PID_2C   :1;
    uint8   PID_2D   :1;
    uint8   PID_2E   :1;
    uint8   PID_2F   :1;
    uint8   PID_30   :1;
    uint8   PID_31   :1;
    uint8   PID_32   :1;
    uint8   PID_33   :1;
    uint8   PID_34   :1;
    uint8   PID_35   :1;
    uint8   PID_36   :1;
    uint8   PID_37   :1;
    uint8   PID_38   :1;
    uint8   PID_39   :1;
    uint8   PID_3A   :1;
    uint8   PID_3B   :1;
    uint8   PID_3C   :1;
    uint8   PID_3D   :1;
    uint8   PID_3E   :1;
    uint8   PID_3F   :1;
    uint8   PID_40   :1;
    uint8   PID_41   :1;
    uint8   PID_42   :1;
    uint8   PID_43   :1;
    uint8   PID_44   :1;
    uint8   PID_45   :1;
    uint8   PID_46   :1;
    uint8   PID_47   :1;
    uint8   PID_48   :1;
    uint8   PID_49   :1;
    uint8   PID_4A   :1;
    uint8   PID_4B   :1;
    uint8   PID_4C   :1;
    uint8   PID_4D   :1;
    uint8   PID_4E   :1;
    uint8   PID_4F   :1;
    uint8   PID_50   :1;
    uint8   PID_51   :1;
    uint8   PID_52   :1;
    uint8   PID_53   :1;
    uint8   PID_54   :1;
    uint8   PID_55   :1;
    uint8   PID_56   :1;
    uint8   PID_57   :1;
    uint8   PID_58   :1;
    uint8   PID_59   :1;
    uint8   PID_5A   :1;
    uint8   PID_5B   :1;
    uint8   PID_5C   :1;
    uint8   PID_5D   :1;
    uint8   PID_5E   :1;
    uint8   PID_5F   :1;
    uint8   PID_60   :1;
    uint8   PID_61   :1;
    uint8   PID_62   :1;
    uint8   PID_63   :1;
    uint8   PID_64   :1;
    uint8   PID_65   :1;
    uint8   PID_66   :1;
    uint8   PID_67   :1;
    uint8   PID_68   :1;
    uint8   PID_69   :1;
    uint8   PID_6A   :1;
    uint8   PID_6B   :1;
    uint8   PID_6C   :1;
    uint8   PID_6D   :1;
    uint8   PID_6E   :1;
    uint8   PID_6F   :1;
    uint8   PID_70   :1;
    uint8   PID_71   :1;
    uint8   PID_72   :1;
    uint8   PID_73   :1;
    uint8   PID_74   :1;
    uint8   PID_75   :1;
    uint8   PID_76   :1;
    uint8   PID_77   :1;
    uint8   PID_78   :1;
    uint8   PID_79   :1;
    uint8   PID_7A   :1;
    uint8   PID_7B   :1;
    uint8   PID_7C   :1;
    uint8   PID_7D   :1;
    uint8   PID_7E   :1;
    uint8   PID_7F   :1;
    uint8   PID_80   :1;
    uint8   PID_81   :1;
    uint8   PID_82   :1;
    uint8   PID_83   :1;
    uint8   PID_84   :1;
    uint8   PID_85   :1;
    uint8   PID_86   :1;
    uint8   PID_87   :1;
    uint8   PID_88   :1;
    uint8   PID_89   :1;
    uint8   PID_8A   :1;
    uint8   PID_8B   :1;
    uint8   PID_8C   :1;
    uint8   PID_8D   :1;
    uint8   PID_8E   :1;
    uint8   PID_8F   :1;
    uint8   PID_90   :1;
    uint8   PID_91   :1;
    uint8   PID_92   :1;
    uint8   PID_93   :1;
    uint8   PID_94   :1;
    uint8   PID_95   :1;
    uint8   PID_96   :1;
    uint8   PID_97   :1;
    uint8   PID_98   :1;
    uint8   PID_99   :1;
    uint8   PID_9A   :1;
    uint8   PID_9B   :1;
    uint8   PID_9C   :1;
    uint8   PID_9D   :1;
    uint8   PID_9E   :1;
    uint8   PID_9F   :1;
    uint8   PID_A0   :1;
    uint8   PID_A1   :1;
    uint8   PID_A2   :1;
    uint8   PID_A3   :1;
} dtService_0;

#endif	/* KWPMSGHANDLER_TYPES_H */

