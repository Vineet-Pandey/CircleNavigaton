#!/bin/bash

if [ "$(basename "$PWD")" == "CircleNavigaton" ]; then
  echo "Current directory is CircleNavigation."

  if [ ! -d "build" ]; then
    mkdir build
  fi

  cd build || exit

  cmake ..
  make VERBOSE=1

  cd bin || exit


  ./UnitTests
  ./CircleNavigation


else
  echo "Please navigate to the CircleNavigation directory before running this script."
fi
