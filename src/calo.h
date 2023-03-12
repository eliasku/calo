#ifndef CALO_H
#define CALO_H

#include "calo_file.h"
#include "calo_stream.h"
#include "calo_table.h"

#endif // CALO_H

#ifdef CALO_IMPLEMENTATION
#ifndef CALO_IMPLEMENTED
#define CALO_IMPLEMENTED
#else
#error you should implement only once
#endif

#include "calo_stream.c.h"
#include "calo_table.c.h"
#include "calo_file.c.h"

#undef CALO_IMPLEMENTATION
#endif // CALO_IMPLEMENTATION
