qyaml is a small collection of YAML:: extensions that allow some
Qt types to be used directly with yaml-cpp. Notably QString,
QList, QMap and QVector.

This is by no means complete, it is just a few things that I needed
myself, but you are welcome to use them.

They were initially set up as a library but I just link in the qyaml.pri
file as they are quite small files.

There are nine files at present.

    * qyaml.h         == This just wraps the other header files in one header file.
    * collection.h
    * emitter.h
    * node.h
    * comment.h

    * collection.cpp  == This is actually empty as everything is done in the header file
    * emitter.cpp     == This is actually empty as everything is done in the header file
    * node.cpp
    * comment.cpp     == This is actually empty as everything is done in the header file

These could probably be placed all in one file or a header/source pair but at some
point I might write some more for these so I left all of the files in.

In the example below mRefSquareData is a **QMap<int, QMap<int, QString>>**, ie a two
level QMap system. Only three lines of code are required to save these to the yaml
document.

To create yaml document just:
    YAML::Node root;                    // create root node.
    root["eastings"] = keys;            // add the list
    root["northings"] = mRefSquareData; // add the map

To read just:
    YAML::Node root = YAML::LoadFile( filename );   // load from file
    QList<int> eastings;                            // create empty list.
    root["eastings"] >> eastings;                   // copy list from document
    QMap<int, QMap< int, QString>> northings;       // create empty map
    root["northings"] >> northings;                 // copy map from document

yaml-cpp will handle the multi-level map.

Example YAML file
=================

    eastings:
        - 390000
        - 400000
        - 410000
        - 420000
        - 440000
        - 450000
        - 460000
    northings:
        390000:
            1130000: HT93
            1140000: HT94
        400000:
            1160000: HU06
        410000:
            1140000: HU14
            1150000: HU15
            1160000: HU16
        420000:
            1150000: HU25
            1140000: HU24
        440000:
            1200000: HP40
        450000:
            1200000: HP50
            1210000: HP51
        460000:
            1200000: HP60
            1210000: HP61
            1220000: HP62

Example Source Code
===================
Save file:
==========
    #include <yaml-cpp/yaml.h>
    #include "qyaml.h"

    QList<int> keys = mRefSquareData.keys();
    YAML::Node root;
    root["eastings"] = keys;
    root["northings"] = mRefSquareData;

    YAML::SaveFile("config.yaml", root, QFile::WriteOnly | QFile::Text | QFile::Truncate);


Load File:
==========
    #include <yaml-cpp/yaml.h>
    #include "yaml.h"

    QFile file( Settings::YamlRefSquareFile );

    if ( file.exists() ) {
        YAML::Node baseNode = YAML::LoadFile( Settings::YamlRefSquareFile );

        if ( baseNode.IsNull() )  // file not loaded so when we have data save it.
            bModified =  false;

        QList<int> eastings;
        baseNode["eastings"] >> eastings;
        QMap<int, QMap< int, QString>> northings;
        baseNode["northings"] >> northings;
        mRefSquareData = northings;

    }
