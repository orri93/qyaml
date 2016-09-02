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

/*!
    \brief Saves a YAML::Node to a file.
    \fn YAML::SaveFile(const QString& filename, const Node& node, QIODevice::OpenMode flags)

    Takes two parameters, a QString holding the required filename and the node to
    write, plus one optional QIODevice::OpenMode flags parameter.

    \see QIODevice::OpenMode
*/
void SaveFile( const QString& filename, const Node& node, QIODevice::OpenMode flags ) {
    Emitter out;
    out << node;
    QFile file( filename );

    if ( file.open( flags ) ) {
        QTextStream os( &file );
        os << out.c_str();
    }
}

} // end namespace YAML
