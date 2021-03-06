// RASCAL: Realtime Asynchronous Connection Abstraction Layer.
// Copyright (c) 2003-2004 hex@faerion.oss
// Distributed under the terms of GNU LGPL, read 'LICENSE'.
//
// $Id$

#include <errno.h>
#include "connection.h"
#include "../common/debug.h"

rrid_t rascal_connect_ex(const sock_t *target, rascal_dispatcher disp, void *context, int mode)
{
	rrid_t rc;
	connection *tmp;

	if (mode == proto_tcp)
		tmp = new connection(disp, context);
	else if (mode == proto_udp)
		tmp = new connection_dg(disp, context);
	else
		return REC_INVALID_ARGUMENT;

	if (tmp == NULL)
		return errno | REC_SYSERROR_MASK;

	if (!rascal_isok(rc = tmp->connect(*target))) {
		delete tmp;
		return rc;
	}

	debug((flog, rl_conn, "%X: connection to %s:%u initialized", tmp->get_id(), rascal::ntoa(*target).c_str(), target->port));
	return tmp->get_id();
}
