#ifndef EMITTER_H
#define EMITTER_H

#include <QColor>
#include <QString>
#include <QByteArray>
#include <QFont>
#include <QPoint>
#include <QPointF>
#include <QRect>
#include <QRectF>
#include <QSize>
#include <QSizeF>

#include <yaml-cpp/yaml.h>
#include "node.h"

namespace YAML {

/*!
    \brief Emitter operator << overload for QList<T>
*/
template<class T>
inline Emitter& operator<<( Emitter& emitter, const QList<T> v ) {
    Node node;
    node = v;
    return emitter << node;
}

/*!
    \brief Emitter operator << overload for QMap(K, V).
*/
template<class K, class V>
inline Emitter& operator<<( Emitter& emitter, const QMap<K, V> v ) {
    Node node;
    node = v;
    return emitter << node;
}

/*!
    \brief Emitter operator << overload for QVector<T>
*/
template<class T>
inline Emitter& operator<<( Emitter& emitter, const QVector<T> v ) {
    Node node;
    node = v;
    return emitter << node;
}


/*!
    \brief Emitter operator << overload for QString
*/
inline Emitter&
operator<<(Emitter& emitter, QString& v)
{
  return emitter.Write(v.toStdString());
}

/*!
    \brief Emitter operator << overload for QByteArray
*/
inline Emitter&
operator<<(Emitter& emitter, QByteArray& v)
{
  return emitter.Write(v.toStdString());
}

/*!
    \brief Emitter operator << overload for QColor
*/
inline Emitter&
operator<<(Emitter& emitter, QColor& v)
{
  emitter << YAML::BeginMap;
  emitter << YAML::Key << "red";
  emitter << YAML::Value << v.red();
  emitter << YAML::Key << "green";
  emitter << YAML::Value << v.green();
  emitter << YAML::Key << "blue";
  emitter << YAML::Value << v.blue();
  emitter << YAML::Key << "alpha";
  emitter << YAML::Value << v.alpha();
  emitter << YAML::EndMap;
  return emitter;
}

/*!
    \brief Emitter operator << overload for QFont
*/
inline Emitter&
operator<<(Emitter& emitter, QFont& v)
{
  emitter << YAML::BeginMap;
  emitter << YAML::Key << "family";
  emitter << YAML::Value << v.family().toStdString();
  emitter << YAML::Key << "bold";
  emitter << YAML::Value << v.bold();
  emitter << YAML::Key << "capitalization";
  emitter << YAML::Value << v.capitalization();
  emitter << YAML::Key << "fixedpitch";
  emitter << YAML::Value << v.fixedPitch();
  emitter << YAML::Key << "hinting preference";
  emitter << YAML::Value << v.hintingPreference();
  emitter << YAML::Key << "italic";
  emitter << YAML::Value << v.italic();
  emitter << YAML::Key << "kerning";
  emitter << YAML::Value << v.kerning();
  emitter << YAML::Key << "letter spacing";
  emitter << YAML::Value << v.letterSpacing();
  emitter << YAML::Key << "letter spacing type";
  emitter << YAML::Value << v.letterSpacingType();
  emitter << YAML::Key << "overline";
  emitter << YAML::Value << v.overline();
  // not recommended to use pixelSize()
  emitter << YAML::Key << "point size";
  emitter << YAML::Value << v.pointSize();
  emitter << YAML::Key << "stretch";
  emitter << YAML::Value << v.stretch();
  emitter << YAML::Key << "strikeout";
  emitter << YAML::Value << v.strikeOut();
  emitter << YAML::Key << "style";
  emitter << YAML::Value << v.style();
  emitter << YAML::Key << "style hint";
  emitter << YAML::Value << v.styleHint();
  emitter << YAML::Key << "style name";
  emitter << YAML::Value << v.styleName().toStdString();
  emitter << YAML::Key << "style strategy";
  emitter << YAML::Value << v.styleStrategy();
  emitter << YAML::Key << "underline";
  emitter << YAML::Value << v.underline();
  emitter << YAML::Key << "weight";
  emitter << YAML::Value << v.weight();
  emitter << YAML::Key << "word spacing";
  emitter << YAML::Value << v.wordSpacing();
  emitter << YAML::EndMap;
  return emitter;
}

/*!
    \brief Emitter operator << overload for QPoint
*/
inline Emitter&
operator<<(Emitter& emitter, QPoint& v)
{
  emitter << YAML::BeginMap;
  emitter << YAML::Key << "x";
  emitter << YAML::Value << v.x();
  emitter << YAML::Key << "y";
  emitter << YAML::Value << v.y();
  emitter << YAML::EndMap;
  return emitter;
}

/*!
    \brief Emitter operator << overload for QPointF
*/
inline Emitter&
operator<<(Emitter& emitter, QPointF& v)
{
  emitter << YAML::BeginMap;
  emitter << YAML::Key << "x";
  emitter << YAML::Value << v.x();
  emitter << YAML::Key << "y";
  emitter << YAML::Value << v.y();
  emitter << YAML::EndMap;
  return emitter;
  }

/*!
    \brief Emitter operator << overload for QRect
*/
inline Emitter&
operator<<(Emitter& emitter, QRect& v)
{
  emitter << YAML::BeginMap;
  emitter << YAML::Key << "left";
  emitter << YAML::Value << v.left();
  emitter << YAML::Key << "top";
  emitter << YAML::Value << v.top();
  emitter << YAML::Key << "width";
  emitter << YAML::Value << v.width();
  emitter << YAML::Key << "height";
  emitter << YAML::Value << v.height();
  emitter << YAML::EndMap;
  return emitter;
}

/*!
    \brief Emitter operator << overload for QRectF
*/
inline Emitter&
operator<<(Emitter& emitter, QRectF& v)
{
  emitter << YAML::BeginMap;
  emitter << YAML::Key << "left";
  emitter << YAML::Value << v.left();
  emitter << YAML::Key << "top";
  emitter << YAML::Value << v.top();
  emitter << YAML::Key << "width";
  emitter << YAML::Value << v.width();
  emitter << YAML::Key << "height";
  emitter << YAML::Value << v.height();
  emitter << YAML::EndMap;
  return emitter;
  }

/*!
    \brief Emitter operator << overload for QSize
*/
inline Emitter&
operator<<(Emitter& emitter, QSize& v)
{
  emitter << YAML::BeginMap;
  emitter << YAML::Key << "width";
  emitter << YAML::Value << v.width();
  emitter << YAML::Key << "height";
  emitter << YAML::Value << v.height();
  emitter << YAML::EndMap;
  return emitter;
}

/*!
    \brief Emitter operator << overload for QSizeF
*/
inline Emitter&
operator<<(Emitter& emitter, QSizeF& v)
{
  emitter << YAML::BeginMap;
  emitter << YAML::Key << "width";
  emitter << YAML::Value << v.width();
  emitter << YAML::Key << "height";
  emitter << YAML::Value << v.height();
  emitter << YAML::EndMap;
  return emitter;
  }


} // end namespace YAML

#endif // EMITTER_H
