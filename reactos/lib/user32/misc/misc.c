/*
 *  ReactOS kernel
 *  Copyright (C) 1998, 1999, 2000, 2001 ReactOS Team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */
/* $Id: misc.c,v 1.5.8.1 2004/07/08 22:58:11 weiden Exp $
 *
 * PROJECT:         ReactOS user32.dll
 * FILE:            lib/user32/misc/misc.c
 * PURPOSE:         Misc
 * PROGRAMMER:      Thomas Weidenmueller (w3seek@users.sourceforge.net)
 * UPDATE HISTORY:
 *      19-11-2003  Created
 */

/* INCLUDES ******************************************************************/

#include <windows.h>
#include <user32.h>
#include <debug.h>

/* FUNCTIONS *****************************************************************/

/*
 * @implemented
 */
DWORD
STDCALL
GetGuiResources(
  HANDLE hProcess,
  DWORD uiFlags)
{
  return NtUserGetGuiResources(hProcess, uiFlags);
}


/*
 * Private calls for CSRSS
 */
VOID
STDCALL
PrivateCsrssManualGuiCheck(LONG Check)
{
  NtUserManualGuiCheck(Check);
}

VOID
STDCALL
PrivateCsrssInitialized(VOID)
{
  NtUserCallNoParam(NOPARAM_ROUTINE_CSRSS_INITIALIZED);
}


/*
 * @implemented
 */
BOOL
STDCALL
RegisterLogonProcess(DWORD dwProcessId, BOOL bRegister)
{
  return NtUserCallTwoParam(dwProcessId,
			    (DWORD)bRegister,
			    TWOPARAM_ROUTINE_REGISTERLOGONPROC);
}
