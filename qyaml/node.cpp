#include "node.h"

namespace YAML {

/*!
    \brief Extended YAML operators for Qt.
*/

/*!
    \brief operator >> for QString
*/
void
operator>>(const Node& node, QString& q)
{
  std::string sstr;
  sstr = node.as<std::string>();
  q = QString(sstr.c_str());
}

void
operator<<(Node& node, const QString& q)
{
  std::string sstr = q.toStdString();
  node = sstr;
}

/*!
    \brief operator >> for QByteArray
*/
void
operator>>(const Node& node, QByteArray& q)
{
  std::string sstr;
  sstr = node.as<std::string>();
  q = QByteArray(sstr.c_str());
}

void
operator<<(Node& node, const QByteArray& q)
{
  std::string sstr = q.toStdString();
  node = sstr;
}

/*!
    \brief operator >> for QColor
*/
void
operator>>(const Node& node, QColor& q)
{
  int red = node["red"].as<int>();
  int green = node["green"].as<int>();
  int blue = node["blue"].as<int>();
  int alpha = node["alpha"].as<int>();
  q = QColor(red, green, blue, alpha);
}

/*!
    \brief operator << for QColor
*/
void
operator<<(Node& node, const QColor& q)
{
  node["red"] = q.red();
  node["green"] = q.green();
  node["blue"] = q.blue();
  node["alpha"] = q.alpha();
}

/*!
    \brief operator >> for QColor
*/
void
operator>>(const Node& node, QFont& q)
{
  q.setFamily(node["family"].as<QString>());
  q.setBold(node["bold"].as<bool>());
  q.setCapitalization(QFont::Capitalization(node["capitalization"].as<int>()));
  q.setFixedPitch(node["fixedpitch"].as<bool>());
  q.setHintingPreference(
    QFont::HintingPreference(node["hinting preference"].as<int>()));
  q.setItalic(node["italic"].as<bool>());
  q.setKerning(node["kerning"].as<bool>());
  q.setLetterSpacing(QFont::SpacingType(node["letter spacing type"].as<int>()),
                     node["letter spacing"].as<double>());
  q.setOverline(node["overline"].as<bool>());
  // not recommended to use pixelSize()
  q.setPointSize(node["point size"].as<int>());
  q.setStretch(node["stretch"].as<int>());
  q.setStrikeOut(node["strikeout"].as<bool>());
  q.setStyle(QFont::Style(node["style"].as<int>()));
  q.setStyleHint(QFont::StyleHint(node["style hint"].as<int>()));
  q.setStyleName(node["style name"].as<QString>());
  q.setStyleStrategy(QFont::StyleStrategy(node["style strategy"].as<int>()));
  q.setUnderline(node["underline"].as<bool>());
  q.setWeight(QFont::Weight(node["weight"].as<int>()));
  q.setWordSpacing(node["word spacing"].as<int>());
}

/*!
    \brief operator << for QColor
*/
void
operator<<(Node& node, const QFont& q)
{
  node["family"] = q.family();
  node["bold"] = q.bold();
  node["capitalization"] = int(q.capitalization());
  node["fixedpitch"] = q.fixedPitch();
  node["hinting preference"] = int(q.hintingPreference());
  node["italic"] = q.italic();
  node["kerning"] = q.kerning();
  node["letter spacing"] = q.letterSpacing();
  node["letter spacing type"] = int(q.letterSpacingType());
  node["overline"] = q.overline();
  // not recommended to use pixelSize()
  node["point size"] = q.pointSize();
  node["stretch"] = q.stretch();
  node["strikeout"] = q.strikeOut();
  node["style"] = int(q.style());
  node["style hint"] = int(q.styleHint());
  node["style name"] = q.styleName();
  node["style strategy"] = int(q.styleStrategy());
  node["underline"] = q.underline();
  node["weight"] = int(q.weight());
  node["word spacing"] = q.wordSpacing();
}

/*!
    \brief YAML::LoadFile extension for QString
*/
Node
LoadFile(const QString& filename)
{
  return LoadFile(filename.toStdString());
}

/*!
    \brief Saves a YAML::Node to a file.
    \fn YAML::SaveFile(const QString& filename, const Node& node,
   QIODevice::OpenMode flags)

    Takes two parameters, a QString holding the required filename and the node
   to write, plus one optional QIODevice::OpenMode flags parameter.

    \see QIODevice::OpenMode
*/
void
SaveFile(const QString& filename, const Node& node, QIODevice::OpenMode flags)
{
  Emitter out;
  out << node;
  QFile file(filename);

  if (file.open(flags)) {
    QTextStream os(&file);
    os << out.c_str();
  }
}

} // end namespace YAML
