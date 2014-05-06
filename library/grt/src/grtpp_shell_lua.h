/* 
 * Copyright (c) 2007, 2010, Oracle and/or its affiliates. All rights reserved.
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

#ifndef _GRTPP_SHELL_LUA_H_
#define _GRTPP_SHELL_LUA_H_

#include "grtpp_shell.h"
#include "grtpp_module_lua.h"

namespace grt
{
  class MYSQLGRT_PUBLIC LuaShell : public Shell
  {
  public:
    LuaShell(GRT *grt);
    
    virtual std::string shell_type() { return "lua"; }
    
    virtual void init();
    virtual void print_welcome();
    virtual std::string get_prompt();
    virtual int execute_line(const std::string &linebuf);
    virtual int run_file(const std::string &file_name, bool interactive);
    virtual void show_help(const std::string &topic);

    // for GCompletion
    virtual std::vector<std::string> complete_line(const std::string &line, std::string &completed);

    virtual ValueRef get_global_var(const std::string &var_name);
    virtual int set_global_var(const std::string &var_name, const ValueRef &value);

    lua_State *get_lua();

  protected:
    void report_lua_error(int status);

    std::string _current_line;

    LuaModuleLoader *_loader;
  };

};

#endif /* _GRTPP_SHELL_LUA_H_ */
