/* 
 * Copyright (c) 2007, 2012, Oracle and/or its affiliates. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; version 2 of the
 * License.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301  USA
 */

#ifndef _MDC_LINE_SEGMENT_HANDLE_H_
#define _MDC_LINE_SEGMENT_HANDLE_H_

#include "mdc_item_handle.h"

BEGIN_MDC_DECLS

class MYSQLCANVAS_PUBLIC_FUNC LineSegmentHandle : public ItemHandle {
public:
  LineSegmentHandle(InteractionLayer *ilayer, CanvasItem *item, const base::Point &pos,
    bool vertical);
  virtual ~LineSegmentHandle();

  virtual base::Rect get_bounds() const;

  void set_vertical(bool flag);
  bool is_vertical() { return _vertical; }

private:
  bool _vertical;
};

END_MDC_DECLS

#endif
