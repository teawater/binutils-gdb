/* This testcase is part of GDB, the GNU debugger.

   Copyright 2012-2014 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

asm (".section	\".text\"");
asm (".balign 8");
asm ("foo_start: .globl foo_start");

int
foo (int i, int j)
{
  return 0;
}

asm ("bar_start: .globl bar_start");

int
bar (int i)
{
  int j = 2;

  return foo (i, j);
}

int global1 = 1;
int global2 = 2;

static void
end (void)
{}

int
main (void)
{
  int ret = 0;

  global1++;
  global2++;
  ret = bar (0);

  end ();
  return ret;
}
