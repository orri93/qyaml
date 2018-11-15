#ifndef COMMENT_H
#define COMMENT_H

#include <QString>
#include <QByteArray>

#include <yaml-cpp/yaml.h>

namespace YAML {

/*!
    \brief YAML::Comment extension for QString
*/
inline _Comment Comment( const QString content ) {
    return _Comment( content.toStdString() );
}

/*!
    \brief YAML::Comment extension for QByteArray
*/
inline _Comment Comment( const QByteArray content ) {
    return _Comment( content.toStdString() );
}

} // end namespace YAML

#endif // COMMENT_H
