#!/bin/bash

if [ "$#" -lt 1 ]; then
  echo "Usage: $0 <pid> [fd]"
  exit 1
fi

pid="$1"

fd=""
if [ "$#" -eq 2 ]; then
  fd="$2"
fi

process_info=$(ps -p "$pid" -o comm=,pid=,ppid=)


echo "Name: $(echo "$process_info" | awk '{print $1}')"
echo "Pid: $(echo "$process_info" | awk '{print $2}')"
echo "PPid: $(echo "$process_info" | awk '{print $3}')"

if [ -n "$fd" ]; then
  echo "$fd: " 
  ls /proc/$pid/fd
fi