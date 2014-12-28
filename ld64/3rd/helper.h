#ifndef _HELPER_H
#define _HELPER_H

#include <mach/mach_time.h>
#include <mach/mach_host.h>
#include <mach/host_info.h>
#include <sys/time.h>
#include <dlfcn.h>

struct dyld_unwind_sections
{
    const struct mach_header*       mh;
    const void*                     dwarf_section;
    intptr_t                       dwarf_section_length;
    const void*                     compact_unwind_section;
    intptr_t                       compact_unwind_section_length;
};

typedef Dl_info dl_info;

#ifdef __cplusplus
extern "C" {
#endif
int _NSGetExecutablePath(char *path, unsigned int *size);
#ifdef __cplusplus
}
#endif

int _dyld_find_unwind_sections(void* i, struct dyld_unwind_sections* sec);

mach_port_t mach_host_self(void);

kern_return_t host_statistics ( host_t host_priv, host_flavor_t flavor, host_info_t host_info_out, mach_msg_type_number_t *host_info_outCnt);

uint64_t mach_absolute_time(void);

#endif
