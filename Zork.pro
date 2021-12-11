TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    attacklistener.cpp \
    character.cpp \
    characterdeathlistener.cpp \
    curseditemlistener.cpp \
    defeatlistener.cpp \
    enemym.cpp \
    enemys.cpp \
    enterroomlistener.cpp \
    eventmanager.cpp \
    exitlistener.cpp \
    game.cpp \
    golistener.cpp \
    infolistener.cpp \
    inputlistener.cpp \
    main.cpp \
    maplistener.cpp \
    restartlistener.cpp \
    restlistener.cpp \
    room.cpp \
    takelistener.cpp \
    teleportlistener.cpp \
    victorylistener.cpp

DISTFILES += \
    main.txt

HEADERS += \
    attacklistener.h \
    character.h \
    characterdeathlistener.h \
    curseditemlistener.h \
    defeatlistener.h \
    enemym.h \
    enemys.h \
    enterroomlistener.h \
    eventlistener.h \
    eventmanager.h \
    exitlistener.h \
    game.h \
    golistener.h \
    health.h \
    infolistener.h \
    inputlistener.h \
    maplistener.h \
    npc.h \
    restartlistener.h \
    restlistener.h \
    room.h \
    shape.h \
    sign.h \
    takelistener.h \
    teleportlistener.h \
    victorylistener.h
