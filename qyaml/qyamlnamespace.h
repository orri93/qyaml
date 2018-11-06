#ifndef YAMLNAMESPACE_H
#define YAMLNAMESPACE_H

//  Disables the namespace
//  The problem with declaring namespaces like hjis is that the
//  QTCreator method list (Symbols) do not work for some reason,
//  probably in the qtcreator parser.
#if defined(QYAML_DISABLE_NAMESPACE)

#   define QYAML_BEGIN_NAMESPACE
#   define QYAML_END_NAMESPACE
#   define QYAML_USE_NAMESPACE

#else

#   define QYAML_BEGIN_NAMESPACE namespace QYaml {
#   define QYAML_END_NAMESPACE }
#   define QYAML_USE_NAMESPACE using namespace QYaml;

#endif


#endif // YAMLNAMESPACE_H
