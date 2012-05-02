#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Release
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Moteur.o \
	${OBJECTDIR}/Signaux.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/HasheurCmd.o \
	${OBJECTDIR}/ObserverObservable.o \
	${OBJECTDIR}/SortieFichier.o \
	${OBJECTDIR}/CleValeur.o \
	${OBJECTDIR}/TestBruteForce.o \
	${OBJECTDIR}/Calculateur.o \
	${OBJECTDIR}/Log.o \
	${OBJECTDIR}/TestDriverRedis.o \
	${OBJECTDIR}/Hasheur.o \
	${OBJECTDIR}/TestHasheurCmd.o \
	${OBJECTDIR}/Md5ManuelUtil.o \
	${OBJECTDIR}/DessinerUtil.o \
	${OBJECTDIR}/BenchmarkUtil.o \
	${OBJECTDIR}/Sortie.o \
	${OBJECTDIR}/Ui.o \
	${OBJECTDIR}/HasheurMd5.o \
	${OBJECTDIR}/TestHasheurMd5.o \
	${OBJECTDIR}/SortieNull.o \
	${OBJECTDIR}/BruteForceUtil.o \
	${OBJECTDIR}/Redis.o \
	${OBJECTDIR}/SortieRedis.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-Wall -W -O2
CXXFLAGS=-Wall -W -O2

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=libs/libhiredis.a -lpthread libs/libcpptest.a

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-Release.mk dist/Release/GNU-Linux-x86/projetunixhashgenerator

dist/Release/GNU-Linux-x86/projetunixhashgenerator: libs/libhiredis.a

dist/Release/GNU-Linux-x86/projetunixhashgenerator: libs/libcpptest.a

dist/Release/GNU-Linux-x86/projetunixhashgenerator: ${OBJECTFILES}
	${MKDIR} -p dist/Release/GNU-Linux-x86
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/projetunixhashgenerator -s ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/Moteur.o: Moteur.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -w -s -MMD -MP -MF $@.d -o ${OBJECTDIR}/Moteur.o Moteur.cpp

${OBJECTDIR}/Signaux.o: Signaux.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -w -s -MMD -MP -MF $@.d -o ${OBJECTDIR}/Signaux.o Signaux.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -w -s -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/HasheurCmd.o: HasheurCmd.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -w -s -MMD -MP -MF $@.d -o ${OBJECTDIR}/HasheurCmd.o HasheurCmd.cpp

${OBJECTDIR}/ObserverObservable.o: ObserverObservable.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -w -s -MMD -MP -MF $@.d -o ${OBJECTDIR}/ObserverObservable.o ObserverObservable.cpp

${OBJECTDIR}/SortieFichier.o: SortieFichier.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -w -s -MMD -MP -MF $@.d -o ${OBJECTDIR}/SortieFichier.o SortieFichier.cpp

${OBJECTDIR}/CleValeur.o: CleValeur.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -w -s -MMD -MP -MF $@.d -o ${OBJECTDIR}/CleValeur.o CleValeur.cpp

${OBJECTDIR}/TestBruteForce.o: TestBruteForce.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -w -s -MMD -MP -MF $@.d -o ${OBJECTDIR}/TestBruteForce.o TestBruteForce.cpp

${OBJECTDIR}/Calculateur.o: Calculateur.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -w -s -MMD -MP -MF $@.d -o ${OBJECTDIR}/Calculateur.o Calculateur.cpp

${OBJECTDIR}/Log.o: Log.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -w -s -MMD -MP -MF $@.d -o ${OBJECTDIR}/Log.o Log.cpp

${OBJECTDIR}/TestDriverRedis.o: TestDriverRedis.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -w -s -MMD -MP -MF $@.d -o ${OBJECTDIR}/TestDriverRedis.o TestDriverRedis.cpp

${OBJECTDIR}/Hasheur.o: Hasheur.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -w -s -MMD -MP -MF $@.d -o ${OBJECTDIR}/Hasheur.o Hasheur.cpp

${OBJECTDIR}/TestHasheurCmd.o: TestHasheurCmd.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -w -s -MMD -MP -MF $@.d -o ${OBJECTDIR}/TestHasheurCmd.o TestHasheurCmd.cpp

${OBJECTDIR}/Md5ManuelUtil.o: Md5ManuelUtil.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -w -s -MMD -MP -MF $@.d -o ${OBJECTDIR}/Md5ManuelUtil.o Md5ManuelUtil.cpp

${OBJECTDIR}/DessinerUtil.o: DessinerUtil.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -w -s -MMD -MP -MF $@.d -o ${OBJECTDIR}/DessinerUtil.o DessinerUtil.cpp

${OBJECTDIR}/BenchmarkUtil.o: BenchmarkUtil.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -w -s -MMD -MP -MF $@.d -o ${OBJECTDIR}/BenchmarkUtil.o BenchmarkUtil.cpp

${OBJECTDIR}/Sortie.o: Sortie.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -w -s -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sortie.o Sortie.cpp

${OBJECTDIR}/Ui.o: Ui.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -w -s -MMD -MP -MF $@.d -o ${OBJECTDIR}/Ui.o Ui.cpp

${OBJECTDIR}/HasheurMd5.o: HasheurMd5.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -w -s -MMD -MP -MF $@.d -o ${OBJECTDIR}/HasheurMd5.o HasheurMd5.cpp

${OBJECTDIR}/TestHasheurMd5.o: TestHasheurMd5.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -w -s -MMD -MP -MF $@.d -o ${OBJECTDIR}/TestHasheurMd5.o TestHasheurMd5.cpp

${OBJECTDIR}/SortieNull.o: SortieNull.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -w -s -MMD -MP -MF $@.d -o ${OBJECTDIR}/SortieNull.o SortieNull.cpp

${OBJECTDIR}/BruteForceUtil.o: BruteForceUtil.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -w -s -MMD -MP -MF $@.d -o ${OBJECTDIR}/BruteForceUtil.o BruteForceUtil.cpp

${OBJECTDIR}/Redis.o: Redis.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -w -s -MMD -MP -MF $@.d -o ${OBJECTDIR}/Redis.o Redis.cpp

${OBJECTDIR}/SortieRedis.o: SortieRedis.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -w -s -MMD -MP -MF $@.d -o ${OBJECTDIR}/SortieRedis.o SortieRedis.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Release
	${RM} dist/Release/GNU-Linux-x86/projetunixhashgenerator

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
