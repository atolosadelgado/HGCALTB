#!/bin/bash

# Pion test
executable2=(./install/bin/HGCALTB -p "FTFP_BERT_EMZ" -t 16 -g TBHGCal181Oct_subregionSilicon.gdml -m HGCALTBrun_electron.mac -f "electron10GeV_EEsensregion.root")
executable=(./install/bin/HGCALTB  -p "FTFP_BERT_EMZ" -t 16 -g TBHGCal181Oct_original.gdml         -m HGCALTBrun_electron.mac -f "electron10GeV_original.root")

/usr/bin/time -f "%U" "${executable[@]}" 2>> binary_stderr_electron.txt 1> /dev/null 2>> cpu_time_original_electron.txt
/usr/bin/time -f "%U" "${executable2[@]}" 2>> binary_stderr_electron.txt 1> /dev/null 2>> cpu_time_subregionSilicon_electron.txt


