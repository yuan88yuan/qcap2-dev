#ifndef QCAP_H
#define QCAP_H

#define QCAP_EXT_API
#define QCAP_EXPORT

#ifdef __cplusplus
#define DEFVAL(x) = x
extern "C"
{
#else
#define DEFVAL(x)
#endif

// Include the top-level modular header, which transitively includes all others.
#include "qcap.helper.h"

#ifdef __cplusplus
}
#endif

#endif // QCAP_H
