#!/bin/bash

# Pion test
executable=(./install/bin/HGCALTB -t 16 -g TBHGCal181Oct_highcuts.gdml -m HGCALTBrun_pion.mac)
executable2=(./install/bin/HGCALTB -t 16 -g TBHGCal181Oct_original.gdml -m HGCALTBrun_pion.mac)

for i in $(seq 1 10); do
  /usr/bin/time -f "%U" "${executable2[@]}" 2>> binary_stderr_pion.txt 1> /dev/null 2>> cpu_time_original_pion.txt
  /usr/bin/time -f "%U" "${executable[@]}"  2>> binary_stderr_pion.txt 1> /dev/null 2>> cpu_time_highcuts_pion.txt
done

# Electron test
executable=(./install/bin/HGCALTB -t 16 -g TBHGCal181Oct_highcuts.gdml -m HGCALTBrun_electron.mac)
executable2=(./install/bin/HGCALTB -t 16 -g TBHGCal181Oct_original.gdml -m HGCALTBrun_electron.mac)

for i in $(seq 1 10); do
  /usr/bin/time -f "%U" "${executable2[@]}" 2>> binary_stderr_electron.txt 1> /dev/null 2>> cpu_time_original_electron.txt
  /usr/bin/time -f "%U" "${executable[@]}"  2>> binary_stderr_electron.txt 1> /dev/null 2>> cpu_time_highcuts_electron.txt
done

