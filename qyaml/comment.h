#ifndef COMMENT_H
#define COMMENT_H

#include <QString>

#include <yaml-cpp/yaml.h>

namespace YAML {

/*!
    \brief YAML::Comment extension for QString
*/
inline _Comment Comment( const QString content ) {
    return _Comment( content.toStdString() );
}

inline Node NodeComment(const std::string content ) {
    std::string c;
    if (content.find("\n") != std::string::npos) {
        c.append("/*\\n");
        c.append(content);
        c.append("\\n*/");
    } else {
        c.append("# ");
        c.append(content);
    }
    Node node;
    node = c;
    return node;
}

inline Node NodeComment(const QString content ) {
    return NodeComment(content.toStdString());
}

} // end namespace YAML

#endif // COMMENT_H
