/*
 * Copyright (c) 2016 GitHub, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef LIBBCC_PROC_H
#define LIBBCC_PROC_H

#include "bcc_syms.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef int (*bcc_procutils_modulecb)(const char *, uint64_t, uint64_t, void *);
typedef void (*bcc_procutils_ksymcb)(const char *, uint64_t, void *);

char *bcc_procutils_which_so(const char *libname, int pid);
char *bcc_procutils_which(const char *binpath);
int bcc_procutils_each_module(int pid, bcc_procutils_modulecb callback,
                              void *payload);
int bcc_procutils_each_ksym(bcc_procutils_ksymcb callback, void *payload);
void bcc_procutils_free(const char *ptr);

#ifdef __cplusplus
}
#endif
#endif
