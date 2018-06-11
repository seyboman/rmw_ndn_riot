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

#ifndef APP_HPP
#define APP_HPP

#include <clist.h>

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct raw_msg_data {
  clist_node_t clist_node;
  unsigned int _seq;
  const char* data;
  size_t size;
} raw_msg_data_t;

typedef struct sub {
  char* _topic_name;
  unsigned int _seq;
  uint32_t _timeout_us;
  clist_node_t _data;
  uint32_t _last_interest_date_us;
  size_t (*_deserialize)(void*, const char*, size_t);
  list_node_t clist_node;
} sub_t;

typedef struct pub {
  char* _topic_name;
  unsigned int _cur_seq;
  unsigned int _req_seq;
  unsigned int _snd_seq;
  clist_node_t _data;
  size_t (*_serialize)(const void*, char*, size_t);
  list_node_t clist_node;
} pub_t;

void app_add_sub(sub_t* sub);
void app_rm_sub(sub_t* sub);

void app_add_pub(pub_t* pub);
void app_rm_pub(pub_t* pub);

void app_create(void);
void app_destroy(void);

void app_update(void);

#ifdef __cplusplus
}
#endif

#endif//APP_HPP
