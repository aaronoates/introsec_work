#!/usr/bin/env node

'use strict';

function f(x, y, z)
{
  return {
    x: () => x,
    y: y,
    z: z
  };
}


var something = f(1, 2, 3);

console.log(something);
console.log(something.x());
console.log(something.y);
console.log(something.z);