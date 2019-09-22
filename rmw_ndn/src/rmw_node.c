/*
    rmw_ndn
    Copyright (C) 2017 INRIA

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "rmw/rmw.h"

#include <stdlib.h>

#include "app.h"

#define ENABLE_DEBUG 0
#include <debug.h>

const char *
rmw_get_implementation_identifier(void)
{
  DEBUG("rmw_get_implementation_identifier" "\n");
  static const char * fake_impl_id = "rmw_ndn";
  return fake_impl_id;
}

rmw_ret_t
rmw_init(const rmw_init_options_t * options, rmw_context_t * context)
{
  DEBUG("rmw_init" "\n");
  return RMW_RET_OK;
}

rmw_node_t *
rmw_create_node(
        rmw_context_t * context,
        const char * name,
        const char * namespace_,
        size_t domain_id,
        const rmw_node_security_options_t * security_options)
{
  (void) domain_id;
  (void) security_options;
  DEBUG("rmw_create_node" "\n");
  rmw_node_t *node = (rmw_node_t *)malloc(sizeof(rmw_node_t));
  node->implementation_identifier = rmw_get_implementation_identifier();
  node->data = NULL;
  node->name = name;
  node->namespace_ = namespace_;

  app_create();

  return node;
}

rmw_ret_t
rmw_destroy_node(rmw_node_t * node)
{
  DEBUG("rmw_destroy_node" "\n");
  free(node);
  app_destroy();
  return RMW_RET_OK;
}
