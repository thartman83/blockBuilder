##########################################
# Top level cmake file from blockBuilder #
##########################################
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
MESSAGE(STATUS "##################")
MESSAGE(STATUS "Starting configure")
MESSAGE(STATUS "##################")
PROJECT(BlockBuilder)
OPTION(BLOCKBUILDER_TESTS "Build unit, framework and functional tests." ON)
OPTION(BLOCKBUILDER_DEBUG "Build with debugging support. (-g flag)" ON)
SET(CMAKE_COLOR_MAKEFILE ON)

include(CheckCXXCompilerFlag)

MESSAGE(STATUS "Checking for X11...")
INCLUDE(FindX11)
IF(NOT X11_FOUND)
	MESSAGE(FATAL_ERROR "Could not find X11!")
ENDIF(NOT X11_FOUND)
MESSAGE(STATUS "     Found!")

# Check for Qt and relate modules
MESSAGE(STATUS "Checking for QT4...")
INCLUDE(FindQt4)
IF(NOT QT4_FOUND)
	MESSAGE(FATAL_ERROR "Could not find Qt4!")
ENDIF(NOT QT4_FOUND)

IF("${QT_VERSION_MINOR}" LESS 5)
	MESSAGE(FATAL_ERROR "blockBuilder requires atleast Qt4.5 .  Found Qt4.${QT_VERSION_MINOR}")
ELSE("${QT_VERSION_MINOR}" LESS 5)
	MESSAGE(STATUS "     Found Qt4.${QT_VERSION_MINOR}")
ENDIF("${QT_VERSION_MINOR}" LESS 5)

IF(NOT QT_QTGUI_FOUND)
	MESSAGE(FATAL_ERROR "blockBuilder requires qtgui support.")
ELSE(NOT QT_QTGUI_FOUND)
	MESSAGE(STATUS "     Found Qt-GUI support.")
ENDIF(NOT QT_QTGUI_FOUND)

ADD_SUBDIRECTORY(src)