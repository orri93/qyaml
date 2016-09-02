
#include "collection.h"

namespace YAML {

/*!
 * \brief YAML::Emitter operator << extension for QList<T>
 */
template<class T>
Emitter& operator<<( Emitter& emitter, const QList<T> v ) {
    return emitter.Write( v.toStdList() );
}

/*!
 * \brief YAML::Emitter operator << extension for QList<T>
 */
template<class K, class V>
Emitter& operator<<( Emitter& emitter, const QMap<K, V> v ) {
    return emitter.Write( v.toStdMap() );
}

/*!
 * \brief YAML::Emitter operator << extension for QVector<T>
 */
template<class T>
Emitter& operator<<( Emitter& emitter, const QVector<T> v ) {
    return emitter.Write( v.toStdVector() );
}

} // end namespace YAML
