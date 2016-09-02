#include "emitter.h"

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
Emitter& operator<<( Emitter& emitter, QString v ) {
    return emitter.Write( v.toStdString() );
}

} // end namespace YAML
