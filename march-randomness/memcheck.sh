#!/bin/bash

exec > >(tee -a log/leaks)

binpathname="bin"

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

progressBar() {
  local w=40 p=$1; shift
  printf -v dots "%*s" "$(( $p*$w/100 ))" "" 1>&2
  dots=${dots// /.}
  printf "\r\e[K|%-*s| %3d %% %s" "$w" "$dots" "$p" "$*" 1>&2
}

mkdir -p log
echo "memcheck log" > log/leaks

echo "bin path: $(pwd)/$binpathname"; echo
echo "using $toolName on $unameOut"; echo
for file in "$binpathname"/*; do
  echo "$file"
  toolCmd "$file"
  for x in {1..100}; do
    progressBar "$x" waiting before continuing...
    sleep 0.05
  done; echo; echo 1>&2
done
