CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
include(${QT_USE_FILE})

SET(blockBuilder_SRCS main.cc blockBuilderWin.cc colorSelector.cc 
	  blockBuilder.cc property.cc displayWin.cc)

SET(blockBuilder_HDRS blockBuilderWin.hh colorSelector.hh property.hh
    displayWin.hh)

SET(blockBuilder_RCCS ../application.qrc)

QT4_WRAP_CPP(blockBuilder_MOC_SRCS ${blockBuilder_HDRS})
QT4_AUTOMOC(${blockBuilder_SRCS})

INCLUDE_DIRECTORIES(${QT_INCLUDE_DIR})
LINK_LIBRARIES(${QT_LIBRARIES})
ADD_DEFINITIONS(${QT_DEFINITIONS})

IF(BLOCKBUILDER_TESTS)
	ADD_DEFINITIONS(-DBLOCKBUILDER_TESTS)
ENDIF(BLOCKBUILDER_TESTS)

IF(BLOCKBUILDER_DEBUG)
	ADD_DEFINITIONS(-g)
ENDIF(BLOCKBUILDER_DEBUG)

ADD_EXECUTABLE(blockBuilder ${blockBuilder_SRCS} ${blockBuilder_MOC_SRCS})
