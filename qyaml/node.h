#ifndef NODE_H
#define NODE_H

#include <QString>
#include <QTextStream>

#include <string>

#include "yaml-cpp/yaml.h"

namespace YAML {

template<>
struct convert<QString> {
    static Node encode( const QString& rhs ) {
        Node node;
        node = rhs.toStdString();
        return node;
    }

    static bool decode( const Node& node, QString& rhs ) {
        if ( !node.IsScalar() ) {
            return false;
        }

        std::string sstr = node.as<std::string>();
        rhs = QString( sstr.c_str() );

        return true;
    }
};

void operator >> ( const Node node, QString q ) ;
void operator << ( Node node, const QString q );
void operator >> ( QTextStream stream, const Node& node );
void operator << ( QTextStream stream, const Node& node );

Node LoadFile( const QString& filename );

} // end of namespace YAML

#endif // NODE_H
