#!/bin/sh

unameOut="$(uname -s)"
if [ "$unameOut" = "Darwin" ]; then
  toolName="$(which leaks)"
  toolCmd(){
    leaks --atExit -- "$1"
  }
elif [ "$(uname -s)" = Linux ]; then
  toolName="$(which valgrind)"
  toolCmd(){
    valgrind "$1"
  }
fi

echo "using $toolName on $unameOut"
for file in bin/*; do
  echo "$file"
  toolCmd $file
  sleep 10
done
