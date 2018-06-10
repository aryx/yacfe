/*******************************************************************************
 *
 * Copyright (C) 1999-2000 by Y. Padioleau, G. Cottenceau, P. Garcia,
 *   G. LeGuelvouit, Y. Zemali, S. Crunchant, X. Michard.
 *
 * Please check out README.
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation under the terms of the GNU General Public License is hereby 
 * granted. No representations are made about the suitability of this software 
 * for any purpose. It is provided "as is" without express or implied warranty.
 * See the GNU General Public License for more details.
 *
 ******************************************************************************/

#ifndef _COMMONINTERFACE_H
#define _COMMONINTERFACE_H

#include <config.h>

#include <libintl.h>
#include <locale.h>

#include <gtkmm.h>
#include <string>

#include "InterfaceUtils.h"

#define _(x) InterfaceUtils::gettext_(x)
#define __(x) string("  ")+_(x)+string("  ")
#define gettext_noop(x) (x)

#define GRANULARITY 10

#endif
