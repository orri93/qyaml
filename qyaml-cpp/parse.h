#ifndef Q_YAML_PARSE_H
#define Q_YAML_PARSE_H

#include <QString>
#include <QFile>
#include <QTextStream>

#include "node.h"

namespace YAML {

YAML_CPP_API Node Load(const QString& input);

YAML_CPP_API Node Load(const QByteArray& input);

YAML_CPP_API Node
LoadFile(const QString& filename);

YAML_CPP_API Node
LoadFile(QFile &file);



}

#endif // Q_YAML_PARSE_H
