#include "node.h"

namespace YAML {

/*!
    \brief Extended YAML operators for Qt.
*/

/*!
    \brief operator >> for QString
*/
void operator >> ( const Node& node, QString& q ) {
    std::string sstr;
    sstr = node.as<std::string>();
    q = QString( sstr.c_str() );
}

void operator << ( Node& node, const QString& q ) {
    std::string sstr = q.toStdString();
    node = sstr;
}

/*!
    \brief YAML::LoadFile extension for QString
*/
Node LoadFile( const QString& filename ) {
    return LoadFile( filename.toStdString() );
}

} // end namespace YAML
