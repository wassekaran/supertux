//  SuperTux
//  Copyright (C) 2006 Matthias Braun <matze@braunis.de>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef __SPIDERMITE_H__
#define __SPIDERMITE_H__

#include "badguy.hpp"

class SpiderMite : public BadGuy
{
public:
  SpiderMite(const lisp::Lisp& reader);
  SpiderMite(const Vector& pos);

  void initialize();
  void write(lisp::Writer& writer);
  void active_update(float elapsed_time);
  void collision_solid(const CollisionHit& hit);

  virtual SpiderMite* clone() const { return new SpiderMite(*this); }

protected:
  enum SpiderMiteMode {
    FLY_UP,
    FLY_DOWN
  };
  SpiderMiteMode mode;
  bool collision_squished(GameObject& object);
private:
  Timer timer;
};

#endif
