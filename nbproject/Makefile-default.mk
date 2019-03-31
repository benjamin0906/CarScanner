#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/CarScanner.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/CarScanner.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=src/DisplayHandler/DisplayHandler.c src/KWPMsgHandler/KWPMsgHandler.c src/Tasking/Tasking.c src/UartHal/UartHal.c Utilities.c src/main.c GettingTroubleCodes.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/src/DisplayHandler/DisplayHandler.p1 ${OBJECTDIR}/src/KWPMsgHandler/KWPMsgHandler.p1 ${OBJECTDIR}/src/Tasking/Tasking.p1 ${OBJECTDIR}/src/UartHal/UartHal.p1 ${OBJECTDIR}/Utilities.p1 ${OBJECTDIR}/src/main.p1 ${OBJECTDIR}/GettingTroubleCodes.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/src/DisplayHandler/DisplayHandler.p1.d ${OBJECTDIR}/src/KWPMsgHandler/KWPMsgHandler.p1.d ${OBJECTDIR}/src/Tasking/Tasking.p1.d ${OBJECTDIR}/src/UartHal/UartHal.p1.d ${OBJECTDIR}/Utilities.p1.d ${OBJECTDIR}/src/main.p1.d ${OBJECTDIR}/GettingTroubleCodes.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/src/DisplayHandler/DisplayHandler.p1 ${OBJECTDIR}/src/KWPMsgHandler/KWPMsgHandler.p1 ${OBJECTDIR}/src/Tasking/Tasking.p1 ${OBJECTDIR}/src/UartHal/UartHal.p1 ${OBJECTDIR}/Utilities.p1 ${OBJECTDIR}/src/main.p1 ${OBJECTDIR}/GettingTroubleCodes.p1

# Source Files
SOURCEFILES=src/DisplayHandler/DisplayHandler.c src/KWPMsgHandler/KWPMsgHandler.c src/Tasking/Tasking.c src/UartHal/UartHal.c Utilities.c src/main.c GettingTroubleCodes.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/CarScanner.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F2480
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/src/DisplayHandler/DisplayHandler.p1: src/DisplayHandler/DisplayHandler.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/DisplayHandler" 
	@${RM} ${OBJECTDIR}/src/DisplayHandler/DisplayHandler.p1.d 
	@${RM} ${OBJECTDIR}/src/DisplayHandler/DisplayHandler.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"src" -I"src/Tasking" -I"src/UartHal" -I"src/KWPMsgHandler" -I"src/DisplayHandler" -I"src/Functionalities" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/DisplayHandler/DisplayHandler.p1 src/DisplayHandler/DisplayHandler.c 
	@-${MV} ${OBJECTDIR}/src/DisplayHandler/DisplayHandler.d ${OBJECTDIR}/src/DisplayHandler/DisplayHandler.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/DisplayHandler/DisplayHandler.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/KWPMsgHandler/KWPMsgHandler.p1: src/KWPMsgHandler/KWPMsgHandler.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/KWPMsgHandler" 
	@${RM} ${OBJECTDIR}/src/KWPMsgHandler/KWPMsgHandler.p1.d 
	@${RM} ${OBJECTDIR}/src/KWPMsgHandler/KWPMsgHandler.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"src" -I"src/Tasking" -I"src/UartHal" -I"src/KWPMsgHandler" -I"src/DisplayHandler" -I"src/Functionalities" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/KWPMsgHandler/KWPMsgHandler.p1 src/KWPMsgHandler/KWPMsgHandler.c 
	@-${MV} ${OBJECTDIR}/src/KWPMsgHandler/KWPMsgHandler.d ${OBJECTDIR}/src/KWPMsgHandler/KWPMsgHandler.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/KWPMsgHandler/KWPMsgHandler.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/Tasking/Tasking.p1: src/Tasking/Tasking.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/Tasking" 
	@${RM} ${OBJECTDIR}/src/Tasking/Tasking.p1.d 
	@${RM} ${OBJECTDIR}/src/Tasking/Tasking.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"src" -I"src/Tasking" -I"src/UartHal" -I"src/KWPMsgHandler" -I"src/DisplayHandler" -I"src/Functionalities" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/Tasking/Tasking.p1 src/Tasking/Tasking.c 
	@-${MV} ${OBJECTDIR}/src/Tasking/Tasking.d ${OBJECTDIR}/src/Tasking/Tasking.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/Tasking/Tasking.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/UartHal/UartHal.p1: src/UartHal/UartHal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/UartHal" 
	@${RM} ${OBJECTDIR}/src/UartHal/UartHal.p1.d 
	@${RM} ${OBJECTDIR}/src/UartHal/UartHal.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"src" -I"src/Tasking" -I"src/UartHal" -I"src/KWPMsgHandler" -I"src/DisplayHandler" -I"src/Functionalities" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/UartHal/UartHal.p1 src/UartHal/UartHal.c 
	@-${MV} ${OBJECTDIR}/src/UartHal/UartHal.d ${OBJECTDIR}/src/UartHal/UartHal.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/UartHal/UartHal.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Utilities.p1: Utilities.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Utilities.p1.d 
	@${RM} ${OBJECTDIR}/Utilities.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"src" -I"src/Tasking" -I"src/UartHal" -I"src/KWPMsgHandler" -I"src/DisplayHandler" -I"src/Functionalities" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Utilities.p1 Utilities.c 
	@-${MV} ${OBJECTDIR}/Utilities.d ${OBJECTDIR}/Utilities.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Utilities.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/main.p1: src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/main.p1.d 
	@${RM} ${OBJECTDIR}/src/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"src" -I"src/Tasking" -I"src/UartHal" -I"src/KWPMsgHandler" -I"src/DisplayHandler" -I"src/Functionalities" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/main.p1 src/main.c 
	@-${MV} ${OBJECTDIR}/src/main.d ${OBJECTDIR}/src/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/GettingTroubleCodes.p1: GettingTroubleCodes.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/GettingTroubleCodes.p1.d 
	@${RM} ${OBJECTDIR}/GettingTroubleCodes.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"src" -I"src/Tasking" -I"src/UartHal" -I"src/KWPMsgHandler" -I"src/DisplayHandler" -I"src/Functionalities" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/GettingTroubleCodes.p1 GettingTroubleCodes.c 
	@-${MV} ${OBJECTDIR}/GettingTroubleCodes.d ${OBJECTDIR}/GettingTroubleCodes.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/GettingTroubleCodes.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/src/DisplayHandler/DisplayHandler.p1: src/DisplayHandler/DisplayHandler.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/DisplayHandler" 
	@${RM} ${OBJECTDIR}/src/DisplayHandler/DisplayHandler.p1.d 
	@${RM} ${OBJECTDIR}/src/DisplayHandler/DisplayHandler.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"src" -I"src/Tasking" -I"src/UartHal" -I"src/KWPMsgHandler" -I"src/DisplayHandler" -I"src/Functionalities" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/DisplayHandler/DisplayHandler.p1 src/DisplayHandler/DisplayHandler.c 
	@-${MV} ${OBJECTDIR}/src/DisplayHandler/DisplayHandler.d ${OBJECTDIR}/src/DisplayHandler/DisplayHandler.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/DisplayHandler/DisplayHandler.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/KWPMsgHandler/KWPMsgHandler.p1: src/KWPMsgHandler/KWPMsgHandler.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/KWPMsgHandler" 
	@${RM} ${OBJECTDIR}/src/KWPMsgHandler/KWPMsgHandler.p1.d 
	@${RM} ${OBJECTDIR}/src/KWPMsgHandler/KWPMsgHandler.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"src" -I"src/Tasking" -I"src/UartHal" -I"src/KWPMsgHandler" -I"src/DisplayHandler" -I"src/Functionalities" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/KWPMsgHandler/KWPMsgHandler.p1 src/KWPMsgHandler/KWPMsgHandler.c 
	@-${MV} ${OBJECTDIR}/src/KWPMsgHandler/KWPMsgHandler.d ${OBJECTDIR}/src/KWPMsgHandler/KWPMsgHandler.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/KWPMsgHandler/KWPMsgHandler.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/Tasking/Tasking.p1: src/Tasking/Tasking.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/Tasking" 
	@${RM} ${OBJECTDIR}/src/Tasking/Tasking.p1.d 
	@${RM} ${OBJECTDIR}/src/Tasking/Tasking.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"src" -I"src/Tasking" -I"src/UartHal" -I"src/KWPMsgHandler" -I"src/DisplayHandler" -I"src/Functionalities" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/Tasking/Tasking.p1 src/Tasking/Tasking.c 
	@-${MV} ${OBJECTDIR}/src/Tasking/Tasking.d ${OBJECTDIR}/src/Tasking/Tasking.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/Tasking/Tasking.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/UartHal/UartHal.p1: src/UartHal/UartHal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/UartHal" 
	@${RM} ${OBJECTDIR}/src/UartHal/UartHal.p1.d 
	@${RM} ${OBJECTDIR}/src/UartHal/UartHal.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"src" -I"src/Tasking" -I"src/UartHal" -I"src/KWPMsgHandler" -I"src/DisplayHandler" -I"src/Functionalities" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/UartHal/UartHal.p1 src/UartHal/UartHal.c 
	@-${MV} ${OBJECTDIR}/src/UartHal/UartHal.d ${OBJECTDIR}/src/UartHal/UartHal.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/UartHal/UartHal.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Utilities.p1: Utilities.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Utilities.p1.d 
	@${RM} ${OBJECTDIR}/Utilities.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"src" -I"src/Tasking" -I"src/UartHal" -I"src/KWPMsgHandler" -I"src/DisplayHandler" -I"src/Functionalities" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Utilities.p1 Utilities.c 
	@-${MV} ${OBJECTDIR}/Utilities.d ${OBJECTDIR}/Utilities.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Utilities.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/main.p1: src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/main.p1.d 
	@${RM} ${OBJECTDIR}/src/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"src" -I"src/Tasking" -I"src/UartHal" -I"src/KWPMsgHandler" -I"src/DisplayHandler" -I"src/Functionalities" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/main.p1 src/main.c 
	@-${MV} ${OBJECTDIR}/src/main.d ${OBJECTDIR}/src/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/GettingTroubleCodes.p1: GettingTroubleCodes.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/GettingTroubleCodes.p1.d 
	@${RM} ${OBJECTDIR}/GettingTroubleCodes.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"src" -I"src/Tasking" -I"src/UartHal" -I"src/KWPMsgHandler" -I"src/DisplayHandler" -I"src/Functionalities" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/GettingTroubleCodes.p1 GettingTroubleCodes.c 
	@-${MV} ${OBJECTDIR}/GettingTroubleCodes.d ${OBJECTDIR}/GettingTroubleCodes.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/GettingTroubleCodes.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/CarScanner.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/CarScanner.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"src" -I"src/Tasking" -I"src/UartHal" -I"src/KWPMsgHandler" -I"src/DisplayHandler" -I"src/Functionalities" -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     --rom=default,-3dc0-3fff --ram=default,-2f4-2ff,-fdb-fdf,-fe3-fe7,-feb-fef,-fd4-fd4,-ffd-fff  $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/CarScanner.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/CarScanner.X.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/CarScanner.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/CarScanner.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"src" -I"src/Tasking" -I"src/UartHal" -I"src/KWPMsgHandler" -I"src/DisplayHandler" -I"src/Functionalities" -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/CarScanner.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
