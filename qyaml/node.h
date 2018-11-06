#ifndef NODE_H
#define NODE_H

#include <QByteArray>
#include <QColor>
#include <QFile>
#include <QFont>
#include <QString>
#include <QTextStream>

#include <string>

#include "yaml-cpp/yaml.h"

namespace YAML {

template<>
struct convert<QString>
{
  static Node encode(const QString& rhs)
  {
    Node node;
    node = rhs.toStdString();
    return node;
  }

  static bool decode(const Node& node, QString& rhs)
  {
    if (!node.IsScalar()) {
      return false;
    }

    std::string sstr = node.as<std::string>();
    rhs = QString(sstr.c_str());

    return true;
  }
};

void
operator>>(const Node node, QString q);
void
operator<<(Node node, const QString q);

Node
LoadFile(const QString& filename);
void
SaveFile(const QString& filename,
         const Node& node,
         QIODevice::OpenMode flags = QIODevice::ReadWrite);

/*
 * Converts QByteArray to Node and back. Enables QByteArray to be sent/received
 * from a YAML file via yaml-cpp.
 */
template<>
struct convert<QByteArray>
{
  static Node encode(const QByteArray& rhs)
  {
    Node node;
    node = rhs.toStdString();
    return node;
  }

  static bool decode(const Node& node, QByteArray& rhs)
  {
    if (!node.IsScalar()) {
      return false;
    }

    std::string sstr = node.as<std::string>();
    rhs = QByteArray(sstr.c_str());

    return true;
  }
};

void
operator>>(const Node node, QByteArray q);
void
operator<<(Node node, const QByteArray q);

/*
 * Converts QColor to Node and back. Enables QColor to be sent/received from a
 * YAML file via yaml-cpp.
 */
template<>
struct convert<QColor>
{
  static Node encode(const QColor& rhs)
  {
    Node node;
    node["red"] = rhs.red();
    node["green"] = rhs.green();
    node["blue"] = rhs.blue();
    node["alpha"] = rhs.alpha();
    return node;
  }

  static bool decode(const Node& node, QColor& rhs)
  {
    if (!node.IsMap()) {
      return false;
    }

    int red = node["red"].as<int>();
    int green = node["green"].as<int>();
    int blue = node["blue"].as<int>();
    int alpha = node["alpha"].as<int>();
    rhs = QColor(red, green, blue, alpha);

    return true;
  }
};

void
operator>>(const Node node, QColor q);
void
operator<<(Node node, const QColor q);

/*
 * Converts QFont to Node and back. Enables QFont to be sent/received from a
 * YAML file via yaml-cpp.
 */
template<>
struct convert<QFont>
{
  static Node encode(const QFont& rhs)
  {
    Node node;
    node["family"] = rhs.family();
    node["bold"] = rhs.bold();
    node["capitalization"] = int(rhs.capitalization());
    node["fixedpitch"] = rhs.fixedPitch();
    node["hinting preference"] = int(rhs.hintingPreference());
    node["italic"] = rhs.italic();
    node["kerning"] = rhs.kerning();
    node["letter spacing"] = rhs.letterSpacing();
    node["letter spacing type"] = int(rhs.letterSpacingType());
    node["overline"] = rhs.overline();
    // not recommended to use pixelSize()
    node["point size"] = rhs.pointSize();
    node["stretch"] = rhs.stretch();
    node["strikeout"] = rhs.strikeOut();
    node["style"] = int(rhs.style());
    node["style hint"] = int(rhs.styleHint());
    node["style name"] = rhs.styleName();
    node["style strategy"] = int(rhs.styleStrategy());
    node["underline"] = rhs.underline();
    node["weight"] = int(rhs.weight());
    node["word spacing"] = rhs.wordSpacing();

    return node;
  }

  static bool decode(const Node& node, QFont& rhs)
  {
    if (!node.IsMap()) {
      return false;
    }

    QFont font;
    rhs.setFamily(node["family"].as<QString>());
    rhs.setBold(node["bold"].as<bool>());
    rhs.setCapitalization(
      QFont::Capitalization(node["capitalization"].as<int>()));
    rhs.setFixedPitch(node["fixedpitch"].as<bool>());
    rhs.setHintingPreference(
      QFont::HintingPreference(node["hinting preference"].as<int>()));
    rhs.setItalic(node["italic"].as<bool>());
    rhs.setKerning(node["kerning"].as<bool>());
    rhs.setLetterSpacing(
      QFont::SpacingType(node["letter spacing type"].as<int>()),
      node["letter spacing"].as<double>());
    rhs.setOverline(node["overline"].as<bool>());
    // not recommended to use pixelSize()
    rhs.setPointSize(node["point size"].as<int>());
    rhs.setStretch(node["stretch"].as<int>());
    rhs.setStrikeOut(node["strikeout"].as<bool>());
    rhs.setStyle(QFont::Style(node["style"].as<int>()));
    rhs.setStyleHint(QFont::StyleHint(node["style hint"].as<int>()));
    rhs.setStyleName(node["style name"].as<QString>());
    rhs.setStyleStrategy(
      QFont::StyleStrategy(node["style strategy"].as<int>()));
    rhs.setUnderline(node["underline"].as<bool>());
    rhs.setWeight(QFont::Weight(node["weight"].as<int>()));
    rhs.setWordSpacing(node["word spacing"].as<int>());

    return true;
  }
};

void
operator>>(const Node node, QFont q);
void
operator<<(Node node, const QFont q);

} // end of namespace YAML

#endif // NODE_H
