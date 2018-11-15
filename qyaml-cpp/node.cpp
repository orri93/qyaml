#include "node.h"

namespace YAML {

/*!
    \brief Extended YAML operators for Qt.
*/

/*= QString
 * ========================================================================*/
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

/*!
    \brief operator << for QString
*/
void
operator<<(Node& node, const QString& q)
{
  std::string sstr = q.toStdString();
  node = sstr;
}

/*= QByteArray
 * =====================================================================*/
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

/*!
    \brief operator << for QByteArray
*/
void
operator<<(Node& node, const QByteArray& q)
{
  std::string sstr = q.toStdString();
  node = sstr;
}

/*= QColor
 * ===============================================================================*/
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
    \brief operator >> for QFont
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
    \brief operator << for QFont
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

/*= QPoint
 * =========================================================================*/
/*!
    \brief operator >> for QPoint
*/
void
operator>>(const Node& node, QPoint& q)
{
  int x = node["x"].as<int>();
  int y = node["y"].as<int>();
  q = QPoint(x, y);
}

/*!
    \brief operator << for QPoint
*/
void
operator<<(Node& node, const QPoint& q)
{
  node["x"] = q.x();
  node["y"] = q.y();
}

/*= QPointF
 * =========================================================================*/
/*!
    \brief operator >> for QPointF
*/
void
operator>>(const Node& node, QPointF& q)
{
  qreal x = node["x"].as<qreal>();
  qreal y = node["y"].as<qreal>();
  q = QPoint(x, y);
}

/*!
    \brief operator << for QPointF
*/
void
operator<<(Node& node, const QPointF& q)
{
  node["x"] = q.x();
  node["y"] = q.y();
}

/*= QRect
 * =========================================================================*/
/*!
    \brief operator >> for QRect
*/
void
operator>>(const Node& node, QRect& q)
{
  int left = node["left"].as<int>();
  int top = node["top"].as<int>();
  int width = node["width"].as<int>();
  int height = node["height"].as<int>();
  q = QRect(left, top, width, height);
}

/*!
    \brief operator << for QRect
*/
void
operator<<(Node& node, const QRect& q)
{
  node["left"] = q.left();
  node["top"] = q.top();
  node["width"] = q.width();
  node["height"] = q.height();
}

/*= QRectF
 * =========================================================================*/
/*!
    \brief operator >> for QRectF
*/
void
operator>>(const Node& node, QRectF& q)
{
  qreal left = node["left"].as<qreal>();
  qreal top = node["top"].as<qreal>();
  qreal width = node["width"].as<qreal>();
  qreal height = node["height"].as<qreal>();
  q = QRect(left, top, width, height);
}

/*!
    \brief operator << for QRectF
*/
void
operator<<(Node& node, const QRectF& q)
{
  node["left"] = q.left();
  node["top"] = q.top();
  node["width"] = q.width();
  node["height"] = q.height();
}

/*= QRect
 * =========================================================================*/
/*!
    \brief operator >> for QSize
*/
void
operator>>(const Node& node, QSize& q)
{
  int width = node["width"].as<int>();
  int height = node["height"].as<int>();
  q = QSize(width, height);
}

/*!
    \brief operator << for QSize
*/
void
operator<<(Node& node, const QSize& q)
{
  node["width"] = q.width();
  node["height"] = q.height();
}

/*= QRectF
 * =========================================================================*/
/*!
    \brief operator >> for QSizeF
*/
void
operator>>(const Node& node, QSizeF& q)
{
  qreal width = node["width"].as<qreal>();
  qreal height = node["height"].as<qreal>();
  q = QSizeF(width, height);
}

/*!
    \brief operator << for QSizeF
*/
void
operator<<(Node& node, const QSizeF& q)
{
  node["width"] = q.width();
  node["height"] = q.height();
}


} // end namespace YAML
