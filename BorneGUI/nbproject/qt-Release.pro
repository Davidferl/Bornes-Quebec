# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Release/GNU-Linux
TARGET = BorneGUI
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += release 
PKGCONFIG +=
QT = core gui widgets
SOURCES += AjoutBorneFontaineInterface.cpp AjoutBorneStatInterface.cpp MWborneGUI.cpp SupprimeBorneInterface.cpp main.cpp
HEADERS += AjoutBorneFontaineInterface.h AjoutBorneStatInterface.h MWborneGUI.h SupprimeBorneInterface.h
FORMS += AjoutBorneFontaineInterface.ui AjoutBorneStatInterface.ui MWborneGUI.ui SupprimeBorneInterface.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Release/GNU-Linux
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += 
LIBS += 
