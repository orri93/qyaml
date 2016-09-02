#ifndef EMITTER_H
#define EMITTER_H

#include <QString>

#include "yaml-cpp/yaml.h"

namespace YAML {

/*!
 * \brief Emitter::Write overload for QString
 */
//Emitter& Emitter::Write(const QString& str) {
//    Emitter::Write(str.toStdString());)
//}

/*!
 * \brief Emitter operator << overload for QString
 */
Emitter& operator<<( Emitter& emitter, QString v );

} // end namespace YAML

#endif // EMITTER_H
